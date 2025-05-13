#pragma once
using namespace std;
#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#ifndef CUSTOMERS_H
#define CUSTOMERS_H


class AllCustomers
{
private:
	string firstName, lastName, streetAddress, city, state, zipCode;
	string accountNumber, phoneNumber;
	//double totalSpent;
public:
	vector<AllCustomers> customerList;

	AllCustomers(string fName = "N/A", string lName = "N/A", string accNum = "0", string stA = "N/A", string c = "N/A", string s = "N/A", string zc = "N/A", string pn = "0");

	void printCustomerList(vector<AllCustomers>& customers); //done
	void sortCustomerListAscending(); //done
	void sortCustomerListDescending(); //done

	AllCustomers addNewCustomer();

	void addMultipleCustomers(vector<AllCustomers>& customerList); //done
	void updateCustomerInfo(vector<AllCustomers>& customerList); //done
	void deleteCustomer(vector<AllCustomers>& customerList);


	//getters
	string getFirstName();
	string getLastName();
	string getStreetAddress();
	string getCity();
	string getState();
	string getZipCode();
	string getAccountNumber();
	string getPhoneNumber();

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
