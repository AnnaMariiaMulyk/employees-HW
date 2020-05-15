#pragma once
#include <iostream>
#include <string>
using namespace std;

struct employee
{
	string firstName;
	string lastName;
	int age;
	string email;
};

void init();
void rewriteFile();
void rewriteFile1();
void addEmployee();
void editEmployee();
void searEmployee();
