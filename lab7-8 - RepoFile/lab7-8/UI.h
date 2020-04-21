#pragma once
#include "pch.h"
#include "Controller.h"

#ifndef UI_H
#define UI_H

class UI
{
private:
	Controller* C;
public:
	UI();
	UI(Controller* crt);
	~UI();

	///--------------------------------------------------------
	void steps();
	void run();

	///--------------------------------------------------------
	void printListP();
	void printListB();

	///--------------------------------------------------------
	void DeCumparat(int v[1000], int &l);
	int inputBani(int sum, int ap[11]);
};
#endif
