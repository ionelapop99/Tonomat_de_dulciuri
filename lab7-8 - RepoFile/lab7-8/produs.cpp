#include "pch.h"
#include "produs.h"
#include <cstring>
#include <iostream>

using namespace std;

Produs::Produs()
{
	this->nume = NULL;
	this->cod = -1;
	this->pret = 0;
	
}
Produs::Produs(int cod, char* nume, int pret)
{
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->cod = cod;
	this->pret = pret;
}
Produs::Produs(const Produs& p)
{
	this->nume = new char[strlen(p.nume) + 1];
	strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
	this->pret = p.pret;
	this->cod = p.cod;
}

Produs::~Produs()
{
	if (this->nume != NULL)
	{
		//cout << "[Produs]destructor "<<type << endl;
		delete[]this->nume;
		this->nume = NULL;
	}
}
//---------------------------------------------------------------------------------
//Getters
int Produs::getCod()
{
	return this->cod;
}
char* Produs::getNume()
{
	return this->nume;
}
int Produs::getPret()
{
	return this->pret;
}


//-----------------------------------------------------------------------------------
//setters
void Produs::setNume(char* n)
{
	if (this->nume)
	{
		delete[] this->nume;
	}
	this->nume = new char[strlen(n) + 1];
	strcpy_s(this->nume, strlen(n) + 1, n);
}

void Produs::setCod(int c)
{
	this->cod = c;
}

void Produs::setPret(int p)
{
	this->pret = p;
}

//---------------------------------------------------------------
//Operator = overloading
Produs& Produs::operator=(const Produs &c)
{
	if (this != &c)
	{
		this->setNume(c.nume);
		this->setCod(c.cod);
		this->setPret(c.pret);
	}
	return *this;
}

//Operator == overloading
bool Produs::operator==(const Produs &c)const
{
	return (strcmp(this->nume, c.nume) == 0) && (this->pret == c.pret && this->cod == c.cod);
}

//-------------------------------------------------------------------------
//cout operator overloading
ostream& operator<<(ostream &os, const Produs &obj) {
	os << obj.cod<< "\t |" << obj.pret << "\t |" << obj.nume;
	return os;
}




