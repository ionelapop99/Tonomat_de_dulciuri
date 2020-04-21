#pragma once
#include "pch.h"
#include <iostream>

using namespace std;

#ifndef BANI_H
#define BANI_H
class Bani
{
private:
	int valoare, numar;
public:
	Bani();
	Bani(int valoare,int numar);
	~Bani();

	//--------------------------------------------------------------
	//Getters
	int getValoare();
	int getNumar();

	//--------------------------------------------------------------
	//Setters
	void setValoare(int);
	void setNumar(int);

	//--------------------------------------------------------------
	Bani& operator=(const Bani &c);
	bool operator==(const Bani &c)const;
	friend ostream& operator<<(ostream &os, const Bani &obj);
};
#endif
