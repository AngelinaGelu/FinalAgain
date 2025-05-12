//#pragma once
//using namespace std;
//#include <iomanip>
//#include <fstream>
//#include <iostream>
//#include <vector>
//#include <string>
#ifndef FILESTUFF_H
#define FILESTUFF_H
#include "Customers.h"
#include "Purchases.h"

//reads in file info to the program
bool readInCustomersFromFile(string& filename, vector<AllCustomers>& customers)
{
	ifstream infile(filename);
	if (!infile)
	{
		cout << "There was an error opening " << filename << endl;
		return false;
	}

	string fName ="NA", lName, street, city, state, zipCode;
	
	string accNum, phoneNum;
	
	while (infile >> fName >> lName >> accNum >> street >> city >> state >> zipCode >> phoneNum) {
		//cout << fName << " " << lName << " " << accNum << " " << street << " " << city << " " << state << " " << zipCode << " " << phoneNum << endl;
		customers.push_back(AllCustomers(fName, lName, accNum, street, city, state, zipCode, phoneNum));


	}
	
	

	infile.close();
	return true;
}

//reads purchases from a file
bool readInPurchasesFromFile(string& filename, vector<AllPurchases>& purchases)
{
	ifstream file(filename);
	if (!file)
	{
		cout << "There was an error opening " << filename << endl;
		return false;
	}
	
	string accNum;
	string item, date;
	string amount;

	while (file >> accNum >> item >> date >> amount)
	{
		purchases.push_back(AllPurchases(accNum, item, date, amount));
	}

	file.close();
	return true;
}

#endif