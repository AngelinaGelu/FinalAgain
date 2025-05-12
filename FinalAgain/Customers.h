#pragma once
using namespace std;
#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#ifdef CUSTOMERS_H
#define CUSTOMERS_H


class AllCustomers
{
private:
	string firstName, lastName, streetAddress, city, state, zipCode;
	int accountNumber, phoneNumber;
	//double totalSpent;
public:
	AllCustomers(string fName = "N/A", string lName = "N/A", int accNum = 0, string stA = "N/A", string c = "N/A", string s = "N/A", string zc = "N/A", int pn = 0);

	void printCustomerList(); //done
	void sortCustomerListAscending(); //done
	void sortCustomerListDescending(); //done
	void addNewCustomer(); 
	void addMultipleCustomers(vector<AllCustomers>& customerList);

	//getters
	string getFirstName();
	string getLastName();
	string getStreetAddress();
	string getCity();
	string getState();
	string getZipCode();
	int getAccountNumber();
	int getPhoneNumber();

	//setters
	void setFirstName(string fn);
	void setLastName(string ln);
	void setStreetAddress(string stA);
	void setCity(string c);
	void setState(string s);
	void setZipCode(string zc);
	void setAccountNumber(int accN);
	void setPhoneNumber(int pn);


};

#endif
