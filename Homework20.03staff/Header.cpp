#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <list>
using namespace std;

const string fileNameEmployee = "employee.txt";
const string fileNameSearch = "search.txt";
list <employee> employees;
list <employee> search;
void init()
{
	employee tempEmp;
	ifstream fin;
	fin.open(fileNameEmployee);
	bool isOpen = fin.is_open();
	if (isOpen == true)
	{
		while (!fin.eof())
		{
			fin >> tempEmp.firstName;
			if (tempEmp.firstName != "")
			{
				fin >> tempEmp.lastName;
				fin >> tempEmp.age;
				fin >> tempEmp.email;
				employees.push_back(tempEmp);
				tempEmp = employee();
			}
		}
	}
	else
	{
		cout << "Error in file system" << endl;
	}
	fin.close();
	fin.open(fileNameSearch);
	isOpen = fin.is_open();
	if (isOpen == true)
	{
		while (!fin.eof())
		{
			fin >> tempEmp.firstName;
			if (tempEmp.firstName != "")
			{
				fin >> tempEmp.lastName;
				fin >> tempEmp.age;
				fin >> tempEmp.email;
				search.push_back(tempEmp);
				tempEmp = employee();
			}
		}
	}
	else
	{
		cout << "Error in file system" << endl;
	}
	fin.close();

	fin.open(fileNameSearch);
	isOpen = fin.is_open();
	if (isOpen == true)
	{
		while (!fin.eof())
		{
			fin >> tempEmp.firstName;
			if (tempEmp.firstName != "")
			{
				fin >> tempEmp.lastName;
				fin >> tempEmp.age;
				fin >> tempEmp.email;
				search.push_back(tempEmp);
				tempEmp = employee();
			}
		}
	}
	else
	{
		cout << "Error in file system" << endl;
	}
	fin.close();
}

void rewriteFile()
{
	ofstream fout;
	fout.open(fileNameEmployee);
	bool isOpen = fout.is_open();
	if (isOpen == true)
	{
		for (employee item : employees)
		{
			fout << item.firstName << endl;
			fout << item.lastName << endl;
			fout << item.age << endl;
			fout << item.email << endl;
		}
	}
	else
	{
		cout << "Error in file system" << endl;
	}
	fout.close();
}

void rewriteFile1()
{
	ofstream fout;
	fout.open(fileNameSearch);
	bool isOpen = fout.is_open();
	if (isOpen == true)
	{
		for (employee item : search)
		{
			fout << item.firstName << endl;
			fout << item.lastName << endl;
			fout << item.age << endl;
			fout << item.email << endl;
		}
	}
	else
	{
		cout << "Error in file system" << endl;
	}
	fout.close();
}

void addEmployee()
{
	employee temp;
	bool exist = false;
	cout << "\t\tADD EMPLOYEE" << endl;
	cout << endl;
	cout << "\tEnter employee first name: ";
	cin >> temp.firstName;
	cout << "\tEnter employee last name: ";
	cin >> temp.lastName;
	for (employee item : employees)
	{
		if (temp.lastName == item.lastName && item.firstName == temp.firstName)
		{
			exist = true;
		}
	}
	if (exist == false)
	{
		cout << "\tEnter employee age: ";
		cin >> temp.age;
		cout << "Enter employee email: ";
		cin >> temp.email;
		employees.push_back(temp);
		temp = employee();
		rewriteFile();
	}
	else
	{
		cout << endl;
		cout << "\tEmployee with this first and last name is already exists" << endl;
	}
}

void editEmployee()
{
	employee temp;
	int choise = 0;
	cout << "\t\tEDIT EMPLOYEE" << endl;
	cout << "\tEnter emloyee`s first name to edit: ";
	cin >> temp.firstName;
	cout << "\tEnter employee`s last name to edit: ";
	cin >> temp.lastName;
	for (employee item : employees)
	{
		if (item.firstName == temp.firstName && item.lastName == temp.lastName)
		{
			cout << "\tWhat do you want to change?" << endl;
			cout << "\t\t1. First name\n\t\t2. Last name\n\t\t3. Age\n\t\t4. EMAIL" << endl;
			cout << "Enter what do you want to change: ";
			cin >> choise;
			cout << endl;

			if (choise == 1)
			{
				string firstName;
				cout << "\tEnter new first name: ";
				cin >> firstName;
				item.firstName = firstName;
				rewriteFile();
			}
			else if (choise == 2)
			{
				string lastName; 
				cout << "\tEnter new last name: ";
				cin >> lastName;
				item.lastName = lastName;
				rewriteFile();
			}
			else if (choise == 3)
			{
				int age;
				cout << "\tEnter new age: ";
				cin >> age;
				item.age = age;
				rewriteFile();
			}
			else if (choise == 4)
			{
				string email;
				cout << "\tEnter new email: ";
				cin >> email;
				item.email = email;
				rewriteFile();
			}
		}
	}
}

void searEmployee()
{
	int choise = 0;
	string temp;
	int age;
	cout << "\t\tSEARCH EMPLOYEE" << endl;
	cout << "\tSearch by: " << endl;
	cout << "\t\t1. First name" << endl;
	cout << "\t\t2. Last name" << endl;
	cout << "\t\t3. Age" << endl;
	cout << "\t\t4. Email" << endl;
	cout << endl;
	switch (choise)
	{
	case 1:
	{
		cout << "\tEnter first name: ";
		cin >> temp;
		for (employee item : employees)
		{
			if (item.firstName == temp)
			{
				cout << item.firstName << endl;
				cout << item.lastName << endl;
				cout << item.age << endl;
				cout << item.email << endl;
				search.push_back(item);
			}
		}
		break;
	}
	case 2:
	{
		cout << "\tEnter last name: ";
		cin >> temp;
		for (employee item : employees)
		{
			if (item.lastName == temp)
			{
				cout << item.firstName << endl;
				cout << item.lastName << endl;
				cout << item.age << endl;
				cout << item.email << endl;
				search.push_back(item);
			}
		}
		break;
	}
	case 3:
	{
		cout << "\tEnter age: ";
		cin >> age;
		for (employee item : employees)
		{
			if (item.age == age)
			{
				cout << item.firstName << endl;
				cout << item.lastName << endl;
				cout << item.age << endl;
				cout << item.email << endl;
				search.push_back(item);
			}
		}
		break;
	}
	case 4:
	{
		cout << "\tEnter email: ";
		cin >> temp;
		for (employee item : employees)
		{
			if (item.email == temp)
			{
				cout << item.firstName << endl;
				cout << item.lastName << endl;
				cout << item.age << endl;
				cout << item.email << endl;
				search.push_back(item);
			}
		}
		break;
	}
	default:
		break;
	}
	int choise1;
	cout << "\tDo you want to renew file with searches?" << endl;
	cout << "\tEnter 1-yes/2-no: ";
	cin >> choise1;
	if (choise == 1)
	{
		rewriteFile1();
	}
}
