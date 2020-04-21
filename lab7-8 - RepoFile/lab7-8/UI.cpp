#include"pch.h"
#include "UI.h"
#include<iostream>

using namespace std;

//default constructor
UI::UI()
{
	//cout << "[UI] default constructor" << endl;
	this->C = new Controller();
}

//constructor with param
UI::UI(Controller* crt)
{
	//cout << "[UI] constructor with parameters" << endl;
	this->C = crt;
}

//destructor
UI::~UI()
{
	//cout << "[UI] destructor" << endl;
	this->C = NULL;
}

///----------------------------------------------------------
///steps
void Steps()
{
	cout << "Steps" << endl;
	cout << "1.Vezi produse\n";
	cout << "2.Alege produs\n";
	cout << "3.Plateste\n";
	cout << "4.Ridica produsele & restul\n";
	cout << endl;
}

/// Run/Meniu
void UI::run()
{
	cout << "Tonomat de dulciuri" << endl;
	Steps();
	char stare[30] = "continua";

	while (strcmp(stare, "continua") == 0)
	{
		//step0
		cout << "Lista bani:" << endl;
		printListB();
		cout << endl;

		//step1
		cout << "Aceasta e lista de produse" << endl;
		printListP();

		//step2
		cout << "Alege produsul/le dorite:" << endl;
		int v[1000], l = 0;
		DeCumparat(v, l);

		//step3
		int s = C->SumP(v, l);
		cout << "Introdu " << s << " lei\n";
		cout << "Tonomatul accepta bacnote de 1, 5 sau 10 lei" << endl;
		int ap[11];
		for (int i = 0; i <= 10; i++)
		{
			ap[i] = 0;
		}
		int input = inputBani(s, ap);

		//step4
		int r;
		r = C->getRest(input, s);

		int cate10, cate5, cate1;
		bool ok;
		bool rest = true;
		if (r != 0)
		{
			ok = C->cautare(r, cate10, cate5, cate1);

			if (ok == true)
			{
				cout << "Restul dumneavoastra este:" << cate10 << "x 10 lei," << cate5 << "x 5 lei," << cate1 << "x 1 lei\n";
				this->C->scoateBani(cate1, cate5, cate10);///stergem banii ce i-am dat rest din lista de bani

				cout << "Lista bani-scoate bani:" << endl;
				printListB();
				cout << endl;
				rest = true;
			}
			else
			{
				cout << "Tonomatul nu poate oferi rest momentan. Va returnam banii.\n";
				cout << "Ridicati " << input << " lei" << endl;
				rest = false;
			}
		}
		if (rest == true)
		{
			/*for (int i = 0; i < l; i++)
			{
				this->C->stergeProduse(v[i]-1);
			}*/
			cate10 = ap[10];
			cate5 = ap[5];
			cate1 = ap[1];
			this->C->updateBani(cate1, cate5, cate10);///adaugam banii introdusi de client in lista de bani

			cout << "Lista bani-update bani:" << endl;
			printListB();
			this->C->write_toFile_Bani();
			cout << "Multumim ca ati cumparat de la noi.\n";
		}

		cout << "Pentru a opri aplicatia introdu cuvantul <<stop>> pentru a continua, introdu <<continua>>.\n";
		cin >> stare;
	}
	cout << "Bye bye!\n";
}
///------------------------------------------------------------------
///Print functions
void UI::printListP()
{
	cout << "Cod" << "\t |" << "Pret" << "\t |" << "Nume" << endl;
	for (unsigned i = 0; i < C->getSizeP(); i++)
	{
		cout << this->C->getAllP()->getAll()[i] << endl;
	}
}
void UI::printListB()
{
	cout << "Valoare" << "\t |" << "Numar" << endl;
	for (unsigned i = 0; i < C->getSizeB(); i++)
	{
		cout << this->C->getAllB()->getAll()[i];
	}
}

///----------------------------------------------------------------
void UI::DeCumparat(int v[1000], int &l)
{
	int nr;
	cout << "Cate produse doresti sa achizitionezi?"; cin >> nr;
	cout << "Introdu codul produsului:";
	int cod;
	while (l < nr)
	{
		cin >> cod;
		v[l] = cod;
		l++;
	}
}

int UI::inputBani(int sum, int ap[11])
{
	int val = 0;
	cout << "Introdu bacnotele:\n";
	while (val < sum)
	{
		int b;
		cin >> b;
		while (!((b == 1 || b == 5) || b == 10))
		{
			cout << "Tonomatul accepta doar bancnote de 1,5 si 10 lei";
			cin >> b;
		}
		val += b;
		ap[b]++;

	}
	return val;
}