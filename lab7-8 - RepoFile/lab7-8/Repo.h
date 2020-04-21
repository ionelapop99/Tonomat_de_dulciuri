#include "pch.h"
#include<iostream>
#include<vector>

using namespace std;

#ifndef REPO_H
#define REPO_H

template<class T>

class Repo
{
protected:
	vector<T> List;
public:
	Repo();
	Repo(const vector<T>&v);
	~Repo();

	//-------------------------------------------------------
	//Getterss
	virtual T* getAll() { return &this->List[0]; }
	virtual int getSize()
	{
		return this->List.size();
	}

	//--------------------------------------------------------
	//add
	virtual void add(const T &e)
	{
		this->List.push_back(e);
	}
	//-----------------------------------------------------------
	//update
	void update(const T &c,int pos)
	{
		this->List[pos]=c;
	}

	//----------------------------------------------------------
	//delete
	void deleteE(int pos)
	{
		this->List.erase(this->List.begin() + pos);
	}

};

///default constructor
template <class T>Repo<T>::Repo()
{
	this->List.reserve(10);
}

///copy constructor
template <class T>Repo<T>::Repo(const vector<T> &v)
{
	for (unsigned i = 0; i < v.size(); i++) {
		this->List.push_back(v[i]);
	}
}

///destructor
template <class T>Repo<T>::~Repo()
{
	this->List.~vector();
}
#endif