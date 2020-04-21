#include "pch.h"
#include <iostream>

using namespace std;

#ifndef PRODUS_H
#define PRODUS_H
class Produs
{
private:
	int cod, pret;
	char* nume;
public:
	Produs();
	Produs(int cod, char *nume, int pret);
	Produs(const Produs &p);
	~Produs();

	//--------------------------------------------------------------
	//Getters
	char* getNume();
	int getCod();
	int getPret();

	//--------------------------------------------------------------
	//Setters
	void setNume(char*);
	void setCod(int);
	void setPret(int);

	//--------------------------------------------------------------
	Produs& operator=(const Produs &c);
	bool operator==(const Produs &c)const;
	friend ostream& operator<<(ostream &os, const Produs &obj);
};
#endif
