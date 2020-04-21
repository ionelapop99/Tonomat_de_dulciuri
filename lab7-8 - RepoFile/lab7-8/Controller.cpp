#include "pch.h"
#include "Controller.h"
#include "RepoFile.h"

//controller default constructor
Controller::Controller()
{
	///cout << "[Controller] default constructor" << endl;
	RepoFile<Produs>*lp = new RepoFile<Produs>;
	RepoFile<Bani> *lb = new RepoFile<Bani>;
	(*lp).load_DataFromFile_Produs();
	(*lb).load_DataFromFile_Bani();
	this->ListP = lp;
	this->ListB = lb;
}

//constructor with param
Controller::Controller(Repo<Produs>* lp, Repo<Bani>*lb)
{
	//cout << "[Controller]Constructor with param" << endl;
	this->ListP = lp;
	this->ListB = lb;
}

//controller destructor
Controller::~Controller()
{
	//cout << "[Controller] Destructor" << endl;
	this->ListP = NULL;
	this->ListB = NULL;
}
///---------------------------------------------------------------

int Controller::SumP(int v[1000], int l)
{
	int s = 0;
	for (int i = 0; i < l; i++)
	{
		s += this->ListP->getAll()[v[i]-1].getPret();
	}
	return s;
}

void Controller::scoateBani(int cate1, int cate5, int cate10)
{
	this->ListB->getAll()[0].setNumar(this->ListB->getAll()[0].getNumar() - cate1);
	this->ListB->getAll()[1].setNumar(this->ListB->getAll()[1].getNumar() - cate5);
	this->ListB->getAll()[2].setNumar(this->ListB->getAll()[2].getNumar() - cate10);
}

void Controller::updateBani(int cate1, int cate5, int cate10)
{
	this->ListB->getAll()[0].setNumar(this->ListB->getAll()[0].getNumar() + cate1);
	this->ListB->getAll()[1].setNumar(this->ListB->getAll()[1].getNumar() + cate5);
	this->ListB->getAll()[2].setNumar(this->ListB->getAll()[2].getNumar() + cate10);
}

bool Controller::cautare(int val, int &cate10, int &cate5, int &cate1)
{
	cate10 = 0; cate5 = 0; cate1 = 0;
	while (this->ListB->getAll()[2].getNumar() - cate10 != 0 && val >= 10)
	{
		cate10++;
		val -= 10;
	}
	while (this->ListB->getAll()[1].getNumar() - cate5 != 0 && val >= 5)
	{
		cate5++;
		val -= 5;
	}
	while (this->ListB->getAll()[0].getNumar() - cate1 != 0 && val >= 1)
	{
		cate1++;
		val -= 1;
	}
	if (val != 0)
	{
		return false;
	}
	return true;
}
void Controller::write_toFile_Bani()
{
	RepoFile<Bani>*lb=new RepoFile<Bani>();
	for(int i=0;i<this->ListB->getSize();i++)
	{
		lb->add(this->ListB->getAll()[i]);
	}
	lb->write_DataToFile_Bani();
	
}
