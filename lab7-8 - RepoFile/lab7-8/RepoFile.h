#pragma once
#include "pch.h"
#include<fstream>
#include "Controller.h"

using namespace std;

#ifndef REPOFILE_H
#define REPOFILE_H

template<class T>

class RepoFile :public Repo<T>
{
public:

	RepoFile();
	//~RepoFile();
	//---------------------------------------------------
	void load_DataFromFile_Produs();
	void write_DataToFile_Produs();

	void load_DataFromFile_Bani();
	void write_DataToFile_Bani();
};
template <class T> RepoFile<T>::RepoFile()
{
	Repo<T>();
}
/*template <class T> RepoFile<T>::~RepoFile()
{
	~Repo<T>();
}*/

///----------------------------------------------------------------------
template <class T> void RepoFile<T>::load_DataFromFile_Produs()
{
	fstream f;
	f.open("C:\\Users\\Ionela\\source\\repos\\lab7-8 - RepoFile\\lab7-8\\dateIn.txt",ios::in);
	int cod, pret;
	char n[100];
	while (f >> cod >> pret >> n)
	{
		Produs p = Produs(cod, n, pret);
		this->add(p);
		//cout << p << endl;
	}
	//cout << endl;

	f.close();
}
template <class T>void RepoFile<T>::write_DataToFile_Produs()
{
	fstream f;
	f.open("C:\\Users\\Ionela\\source\\repos\\lab7-8\\lab7-8\\dateOut.txt",ios::out);
	for(int i=0;i<this->getSize();i++)
	{
		f <<this->getAll()[i].getCod() << " " << this->getAll()[i].getPret()<< endl;
		f <<this->getAll()[i].getNume() << endl;
	}
	f.close();
}

template <class T> void RepoFile<T>::load_DataFromFile_Bani()
{
	fstream f;
	f.open("C:\\Users\\Ionela\\source\\repos\\lab7-8 - RepoFile\\lab7-8\\baniIn.txt", ios::in);
	int val, nr;
	while (f >> val >> nr)
	{
		Bani b = Bani(val, nr);
		this->add(b);
	}

	f.close();
}
template <class T>void RepoFile<T>::write_DataToFile_Bani()
{
	fstream f;
	f.open("C:\\Users\\Ionela\\source\\repos\\lab7-8 - RepoFile\\lab7-8\\baniOut.txt", ios::out);
	for (int i = 0; i < this->getSize(); i++)
	{
		f << this->getAll()[i].getValoare() << " " << this->getAll()[i].getNumar() << endl;
	}
	f.close();
}
#endif;