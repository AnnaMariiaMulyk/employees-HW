#include<iostream>
#include <string>
#include <Windows.h>
#include "Header.h"
using namespace std;
#define CLEAR system("CLS");

int main()
{

	int choise;
	do
	{
		CLEAR;
		cout << "\t\tMENU" << endl;
		cout << "\t1. Add employee" << endl;
		cout << "\t2. Edit employee" << endl;
		cout << "\t3. Search employee" << endl;
		cout << "\t4. Exit " << endl;
		cout << endl;
		cout << "\t\tEnter action: ";
		cin >> choise;
		CLEAR;
		switch (choise)
		{
		case 1:
		{
			addEmployee();
			break;
		}
		case 2:
		{
			editEmployee();
			break;
		}
		case 3:
		{
			searEmployee();
			break;
		}
		case 4:
		{
			cout << "\t\tGOOD BYE" << endl;
			break;
		}
		default:
			break;
		}



	} while (choise != 4);


	return 0;
}