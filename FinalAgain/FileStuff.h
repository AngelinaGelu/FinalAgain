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
bool readInPurchasesFromFile(string& filename, vector <AllPurchases>& purchases)
{
	ifstream file(filename);
	if (!file)
	{
		cout << "There was an error opening " << filename << endl;
		return false;
	}
	
	string accNum;
	string item, date;
	double amount;
	
	
	while (file >> accNum >> item >> date >> amount)
	{

		purchases.push_back(AllPurchases(accNum, item, date, amount));
	}

	file.close();
	return true;

}

void savePurchasesToFile(vector<AllPurchases>& purchases)
{
	ofstream outFile("AllPurchasesData.txt");
	if (!outFile)
	{
		cout << "Could not create file for saving purchase data." << endl;
		return;
	}

	for (int i = 0; i < purchases.size(); ++i)
	{
		outFile << purchases[i].getAccNumber() << " "
			<< purchases[i].getItem() << " "
			<< purchases[i].getDate() << " "
			<< purchases[i].getItem() << endl;
	}

	outFile.close();
	cout << "Purchase data saved to PurchasesInfo.txt successfully!" << endl;
}

void saveCustomersToFile(vector<AllCustomers>& customers)
{
	ofstream outFile("AllCustomersData.txt");
	if (!outFile)
	{
		cout << "Could not create file for saving customer data." << endl;
		return;
	}
	for (int i = 0; i < customers.size(); ++i)
	{
		outFile << customers[i].getFirstName() << " "
			<< customers[i].getLastName() << " "
			<< customers[i].getAccountNumber() << " "
			<< customers[i].getStreetAddress() << " "
			<< customers[i].getCity() << " "
			<< customers[i].getState() << " "
			<< customers[i].getZipCode() << " "
			<< customers[i].getPhoneNumber() << endl;
	}
	outFile.close();
	cout << "Customer data saved to CustomersInfo.txt successfully!" << endl;
}

#endif