#include "pch.h"
#include "Bani.h"
#include <cstring>
#include <iostream>

using namespace std;

Bani::Bani()
{
	this->valoare = 0;
	this->numar = 0;
}
Bani::Bani(int Val,int nr)
{
	this->valoare = Val;
	this->numar = nr;
}

Bani::~Bani()
{

}
//---------------------------------------------------------------------------------
//Getters
int Bani::getValoare()
{
	return this->valoare;
}
int Bani::getNumar()
{
	return this->numar;
}


//-----------------------------------------------------------------------------------
//setters
void Bani::setValoare(int val)
{
	this->valoare = val;
}

void Bani::setNumar(int nr)
{
	this->numar = nr;
}
//---------------------------------------------------------------
//Operator = overloading
Bani& Bani::operator=(const Bani &c)
{
	if (this != &c)
	{
		this->setValoare(c.valoare);
		this->setNumar(c.numar);
	}
	return *this;
}

//Operator == overloading
bool Bani::operator==(const Bani &c)const
{
	return (this->valoare == c.valoare);
}

//-------------------------------------------------------------------------
//cout operator overloading
ostream& operator<<(ostream &os, const Bani &obj) {
	os << obj.valoare << "\t |" << obj.numar <<endl;
	return os;
}
