// lab7-8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Tests.h"
#include "UI.h"
#include "RepoFile.h"

using namespace std;

int main()
{
	//Call tests
	Test_Produs();
	cout << "A"<<endl;
	Test_Repo_Produs();
	cout << "B" << endl;
	Test_Repo_Bani();
	cout << "C" << endl;
	Test_RepoFile_Produse();
	cout << "D" << endl;
	Test_Controller();
	cout << "E" << endl;
	cout << endl;

	//-------------------------------------------------------
	UI* ui = new UI();
	ui->run();

	return 0;
}

