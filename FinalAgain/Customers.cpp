using namespace std;
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Customers.h"

//prints customer list
void AllCustomers::printCustomerList()
{
	for (int i = 0; i < customerList.size(); i++)
	{
		cout << "--------------------" << endl;
		cout << "Customer #" << (i + 1) << endl;
		cout << "Account No.: " << customerList[i].accountNumber << endl;
		cout << "Name: " << customerList[i].firstName << ' ' << customerList[i].lastName << endl;
		cout << "Address: " << customerList[i].streetAddress << ", " << customerList[i].city << ", " << customerList[i].state << customerList[i].zipCode << endl;
		cout << "Phone No.: " << customerList[i].phoneNumber << endl;
		cout << "--------------------" << endl;

	}
}

//sorts customer list in ascending order
void AllCustomers::sortCustomerListAscending()
{
	int x = customerList.size();
	for (int i = 0; i < x - 1; i++)
	{
		for (int j = 0; j < x - i - 1; j++)
		{
			if (customerList[j].firstName > customerList[j + 1].firstName)
			{
				swap(customerList[j], customerList[j + 1]);
			}
		}
	}
}

//sorts customer list in descending order
void AllCustomers::sortCustomerListDescending()
{
	int x = customerList.size();
	for (int i = 0; i < x - 1; i++)
	{
		for (int j = 0; j < x - i - 1; j++)
		{
			if (customerList[j].firstName < customerList[j + 1].firstName)
			{
				swap(customerList[j], customerList[j + 1]);
			}
		}
	}
}

//prints total amount a customer spent
/*void AllCustomers::printCustomerTotalSpent()
{
	for (int i = 0; i < customerList.size(); i++)
	{
		cout << "--------------------" << endl;
		cout << "Customer #" << (i + 1) << endl;
		cout << "Account No.: " << customerList[i].accountNumber << endl;
		cout << "Name: " << customerList[i].firstName << ' ' << customerList[i].lastName << endl;
		cout << "Total Amount Spent: $" << fixed << setprecision(2) << customerList[i].totalSpent << endl;
		cout << "--------------------" << endl;
	}
}*/

//adds a new customer 
void AllCustomers::addNewCustomer()
{
	string fName, lName, stA, city, state, zipCode;
	int accNum, phoneNum;

	cout << "Enter the first name: ";
	cin >> fName;
	cout << "Enter the last name: ";
	cin >> lName;
	cout << "Enter the account number: ";
	cin >> accNum;
	cout << "Enter the street address (no spaces): ";
	cin >> stA;
	cout << "Enter the city name: ";
	cin >> city;
	cout << "Enter the state: ";
	cin >> state;
	cout << "Enter the zipcode: ";
	cin >> zipCode;
	cout << "Enter the phone number (numbers only): ";
	cin >> phoneNum;

	return AllCustomers(fName, lName, accNum, stA, city, state, zipCode, phoneNum);
}

//adds multiple customers to the vector (recursive)
void AllCustomers::addMultipleCustomers(vector<AllCustomers>& customerList)
{
	customerList.push_back(addNewCustomer());

	char choice;
	cout << "Add another customer? (y/n): ";
	cin >> choice;

	if (choice == 'y' || 'Y')
	{
		addMultipleCustomers(customerList);
	}
	else
	{
		cout << "Done adding customers." << endl;
	}
}

//getters
string AllCustomers::getFirstName() { return firstName; }
string AllCustomers::getLastName() { return lastName; }
string AllCustomers::getStreetAddress() { return streetAddress; }
string AllCustomers::getCity() { return city; }
string AllCustomers::getState() { return state; }
string AllCustomers::getZipCode() { return zipCode; }
int AllCustomers::getAccountNumber() { return accountNumber; }
int AllCustomers::getPhoneNumber() { return phoneNumber; }

//setters
void AllCustomers::setFirstName(string fn) { fn = firstName; }
void AllCustomers::setLastName(string ln) { ln = lastName; }
void AllCustomers::setStreetAddress(string stA) { stA = streetAddress; }
void AllCustomers::setCity(string c) { c = city; }
void AllCustomers::setState(string s){ s = state; }
void AllCustomers::setZipCode(string zc) { zc = zipCode; }
void AllCustomers::setAccountNumber(int accN) {	accN = accountNumber; }
void AllCustomers::setPhoneNumber(int pn) {	pn = phoneNumber; }



