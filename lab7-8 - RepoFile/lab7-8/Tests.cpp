#include "pch.h"
#include<iostream>
#include<cassert>
#include "produs.h"
#include "Repo.h"
#include "Bani.h"
#include "Controller.h"
#include "RepoFile.h"

using namespace std;

void Test_Produs()
{
	char n1[30] = "Coca-cola";
	char n2[30] = "Fanta";
	char n3[30] = "Milka";
	char n4[30] = "Biscuiti-Oreo";
	Produs p1 = Produs(1,n1,4);
	Produs p2 = Produs(2, n2, 4);
	Produs p3 = Produs(3, n3, 4);
	//Produs p4 = Produs(4, n4, 5);

	p1.setPret(2);
	p1.setCod(4);
	p1.setNume(n4);
	assert(p1.getPret() == 2);
	assert(p1.getCod() == 4);
	assert(strcmp(p1.getNume(),n4)==0);

	cout << "all test from Produs run ok" << endl;
}
void Test_Repo_Produs()
{
	Repo<Produs> r = Repo<Produs>();
	char n1[30] = "Coca-cola";
	char n2[30] = "Fanta";
	char n3[30] = "Milka";
	char n4[30] = "Biscuiti-Oreo";
	Produs p1 = Produs(1, n1, 4);
	Produs p2 = Produs(2, n2, 4);
	Produs p3 = Produs(3, n3, 4);
	Produs p4 = Produs(4, n4, 5);

	r.add(p1);
	r.add(p2);
	r.add(p3);
	r.add(p4);

	assert(r.getSize() == 4);
	assert(r.getAll()[0] == p1);
	assert(r.getAll()[1] == p2);
	assert(r.getAll()[2] == p3);
	assert(r.getAll()[3] == p4);

	r.update(p4, 0);
	assert(r.getAll()[0] == p4);

	r.deleteE(0);
	assert(r.getSize() == 3);
	assert(r.getAll()[0] == p2);
	assert(r.getAll()[1] == p3);
	assert(r.getAll()[2] == p4);

	cout << "all test from Test_Repo run ok" << endl;
}
void Test_Repo_Bani()
{
	Repo<Bani>B = Repo<Bani>();

	Bani b1 = Bani(1, 10);
	Bani b2 = Bani(5, 20);
	Bani b3 = Bani(10, 10);
	Bani b4 = Bani(2, 10);

	B.add(b1);
	B.add(b2);
	B.add(b3);


	assert(B.getSize() == 3);
	assert(B.getAll()[0].getValoare() == 1);
	assert(B.getAll()[1].getValoare() == 5);
	assert(B.getAll()[2].getValoare() == 10);

	assert(B.getAll()[0].getNumar() == 10);
	assert(B.getAll()[1].getNumar() == 20);
	assert(B.getAll()[2].getNumar() == 10);

	B.add(b4);
	assert(B.getAll()[3].getValoare() == 2);
	assert(B.getAll()[3].getNumar() == 10);
	B.update(b3, 3);
	assert(B.getAll()[3].getValoare() == 10);
	assert(B.getAll()[3].getNumar() == 10);

	B.deleteE(3);
	assert(B.getSize() == 3);

	cout << "all test from Repo_Bani run ok" << endl;

}
void Test_RepoFile_Produse()
{

	RepoFile<Produs> r;
	r.load_DataFromFile_Produs();
	assert(r.getSize() ==10 );
	char n[10] = "Rafaelo";
	assert(r.getAll()[4] == Produs(5, n, 20));
	cout << "all test from RepoFile_Produse run ok"<<endl;

}
void Test_RepoFile_Bani()
{

	RepoFile<Bani> r;
	r.load_DataFromFile_Bani();
	assert(r.getSize() == 3);
	assert(r.getAll()[0] == Bani(1,300));
	cout << "all test from RepoFile_Bani run ok" << endl;

}
void Test_Controller()
{
	Controller C = Controller();

	char n1[30] = "Coca-cola";
	char n2[30] = "Fanta";
	char n3[30] = "Milka";
	char n4[30] = "Biscuiti-Oreo";
	Produs p1 = Produs(11, n1, 4);
	Produs p2 = Produs(12, n2, 4);
	Produs p3 = Produs(13, n3, 4);
	Produs p4 = Produs(14, n4, 5);

	C.addProduse(p1);
	C.addProduse(p2);
	C.addProduse(p3);
	C.addProduse(p4);
	int v[10] = { 1,2,3 };

	assert(C.SumP(v, 3) == 16);

	assert(C.getSizeP() == 14);
	char n[10] = "Rafaelo";
	 
	assert(C.getAllP()->getAll()[4] == Produs(5, n, 20));
	assert(C.getAllP()->getAll()[10] == p1);
	assert(C.getAllP()->getAll()[11] == p2); 
	assert(C.getAllP()->getAll()[12] == p3);
	assert(C.getAllP()->getAll()[13] == p4);


	Bani b1 = Bani(1, 300);
	Bani b2 = Bani(5, 50);
	Bani b3 = Bani(10, 80);

	assert(C.getSizeB() == 3);
	assert(C.getAllB()->getAll()[0] == b1);
	assert(C.getAllB()->getAll()[1] == b2);
	assert(C.getAllB()->getAll()[2] == b3);

	C.updateBani(10,10,10);

	assert(C.getAllB()->getAll()[0].getNumar() == 310);
	assert(C.getAllB()->getAll()[1].getNumar()== 60);
	assert(C.getAllB()->getAll()[2].getNumar() == 90);

	C.scoateBani(10, 10, 10);
	assert(C.getAllB()->getAll()[0].getNumar() == 300);
	assert(C.getAllB()->getAll()[1].getNumar() == 50);
	assert(C.getAllB()->getAll()[2].getNumar() == 80);
	cout << "all test from Contorller run ok" << endl;
}