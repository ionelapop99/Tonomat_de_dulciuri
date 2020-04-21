#include "pch.h"
#include "Repo.h"
#include "Bani.h"
#include "produs.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
protected:
	Repo<Produs>* ListP;
	Repo<Bani>* ListB;
public:
	Controller();
	Controller(Repo<Produs> *lp,Repo<Bani>*lb);
	~Controller();

	//--------------------------------------------------------
	Repo<Produs>* getAllP() { return &this->ListP[0]; }
	Repo<Bani>* getAllB() { return &this->ListB[0]; }
	
	int getRest(int input, int val) { return input - val; };
	int getSizeP() { return this->ListP->getSize(); };
	int getSizeB() { return this->ListB->getSize(); };

	int SumP(int v[1000], int l);

	void addBani(const Bani &b) { this->ListB->add(b); };
	void scoateBani(int cate10, int cate5, int cate1);
	void updateBani(int cate10, int cate5, int cate1);

	void stergeProduse(int pos) { this->ListP->deleteE(pos); };
	void addProduse(const Produs &p) { this->ListP->add(p); };

	void write_toFile_Bani();
	
	bool cautare(int val, int &cate10, int &cate5, int &cate1);
};
#endif
