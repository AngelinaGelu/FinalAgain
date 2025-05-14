using namespace std;
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
//#include "FileStuff.h"
#include "Customers.h"
#include "Purchases.h"

//AllCustomers::AllCustomers() {}

//default constructor
AllCustomers::AllCustomers(string fName, string lName, string accNum, string stA, string c, string s, string zc, string pn)
{
	firstName = fName;
	lastName = lName;
	accountNumber = accNum;
	streetAddress = stA;
	city = c;
	state = s;
	zipCode = zc;
	phoneNumber = pn;
}

//print customer information
void AllCustomers::printCustomerInfo()
{
	cout << "\n--------------------" << endl;
	cout << "Account No.: " << getAccountNumber() << endl;
	cout << "Name: " << getFirstName() << ' ' << getLastName() << endl;
	cout << "Address: " << getStreetAddress() << ", " << getCity() << ", " << getState() << ", " << getZipCode() << endl;
	cout << "Phone No.: " << getPhoneNumber() << endl;
	cout << "--------------------" << endl;
}


//prints customer list
void printCustomerList(vector<AllCustomers>& customerList)
{

	for (int i = 0; i < customerList.size(); i++)
	{
		cout << "\n--------------------" << endl;
		cout << "Customer #" << (i + 1) << endl;
		cout << "Account No.: " << customerList[i].accountNumber << endl;
		cout << "Name: " << customerList[i].firstName << ' ' << customerList[i].lastName << endl;
		cout << "Address: " << customerList[i].streetAddress << ", " << customerList[i].city << ", " << customerList[i].state << ", " << customerList[i].zipCode << endl;
		cout << "Phone No.: " << customerList[i].phoneNumber << endl;
		cout << "--------------------" << endl;

	}
}

//sorts customer list in ascending order
void sortCustomerListAscending(vector<AllCustomers>& customerList)
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
void sortCustomerListDescending(vector<AllCustomers>& customerList)
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
AllCustomers AllCustomers::addNewCustomer()
{
	string fName, lName, stA, city, state, zipCode;
	string accNum, phoneNum;

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

	while (true) 
	{
		cout << "Add another customer? (y/n): ";
		cin >> choice;

		if (choice == 'y' || choice == 'Y')
		{
			addMultipleCustomers(customerList);
			break;
		}
		else if (choice == 'n' || choice == 'N')
		{
			cout << "Done adding customers." << endl;
			break;
		}
		else
		{
			cout << "Invalid input. Please enter 'y' or 'n':" << endl;
		}
	}
}

//updates the info of a preexisting customer
void AllCustomers::updateCustomerInfo(vector<AllCustomers>& customerList)
{
	if (customerList.empty())
	{
		cout << "There are no customers to update." << endl;
		return;
	}

	cout << "Which customer would you like to update? " << endl;
	for (int i = 0; i < customerList.size(); ++i)
	{
		cout << i + 1 << ". " << customerList[i].getFirstName() << ' ' << customerList[i].getLastName() << endl;
		cout << "Account No. " << customerList[i].getAccountNumber() << endl;
	}

	int choice;
	cout << "Enter here: ";
	cin >> choice;

	if (choice < 1 || choice > customerList.size())
	{
		cout << "Invalid Selection. Would you like to select another customer to update ? :" << endl;

		char again;
		//cout << "Would you like to select another customer to update?: ";
		cin >> again;

		if (again == 'y' || again == 'Y')
		{
			updateCustomerInfo(customerList);
		}
		else
		{
			cout << "Exiting the update menu. . ." << endl;
		}
		return;
	}

	AllCustomers& customer = customerList[choice - 1];

	cout << customer.getFirstName() << ' ' << customer.getLastName() << " selected." << endl;

	cout << "What would you like to update?" << endl;
	cout << "1. First Name\n2. Last Name\n3. Street Address\n4. City\n5. State\n6. Zip Code\n7. Phone Number" << endl;
	cout << "Enter here: ";

	int c;
	cin >> c;

	string newThing;
	int newNumber;

	if (c == 1)
	{
		cout << "Enter the new first name: ";
		cin >> newThing;
		customer.setFirstName(newThing);
	}
	else if (c == 2)
	{
		cout << "Enter the new last name: ";
		cin >> newThing;
		customer.setLastName(newThing);
	}
	else if (c == 3)
	{
		cout << "Enter the new street address (no spaces): ";
		cin >> newThing;
		customer.setStreetAddress(newThing);
	}
	else if (c == 4)
	{
		cout << "Enter the new city: ";
		cin >> newThing;
		customer.setCity(newThing);
	}
	else if (c == 5)
	{
		cout << "Enter the new state: ";
		cin >> newThing;
		customer.setState(newThing);
	}
	else if (c == 6)
	{
		cout << "Enter the new zip code: ";
		cin >> newThing;
		customer.setZipCode(newThing);
	}
	else if (c == 7)
	{
		cout << "Enter the new phone number: ";
		cin >> newNumber;
		customer.setPhoneNumber(newNumber);
	}
	else
	{
		cout << "Invalid choice. Would you like to reenter? (y/n): ";

		char reenter;
		cin >> reenter;

		if (reenter == 'y' || reenter == 'Y')
		{
			updateCustomerInfo(customerList);
		}
		else
		{
			cout << "Exiting update menu. . ." << endl;
		}
		return;
	}
}

//deletes the customer
void AllCustomers::deleteCustomer(vector<AllCustomers>& customerList)
{
	if (customerList.empty())
	{
		cout << "There are no customers to delete." << endl;
		return;
	}

	cout << "Which customer would you like to delete?" << endl;
	for (int i = 0; i < customerList.size(); ++i)
	{
		cout << i + 1 << ". " << customerList[i].getFirstName() << ' ' << customerList[i].getLastName() << endl << "Account No.: " << customerList[i].getAccountNumber() << endl;
	}

	int choice;
	cout << "Enter the number of the customer to delete: ";
	cin >> choice;

	if (choice < 1 || choice > customerList.size())
	{
		cout << "Invalid selection. Returning to menu." << endl;
		return;
	}

	cout << "Are you sure you want to delete " << customerList[choice - 1].getFirstName() << ' ' << customerList[choice - 1].getLastName() << "? (y/n): ";
	char confirm;
	cin >> confirm;

	if (confirm == 'y' || confirm == 'Y')
	{
		customerList.erase(customerList.begin() + (choice - 1));
		cout << "Customer deleted." << endl;
	}

	else
	{
		cout << "Deletion canceled." << endl;
	}
}

//getters
string AllCustomers::getFirstName() { return firstName; }
string AllCustomers::getLastName() { return lastName; }
string AllCustomers::getStreetAddress() { return streetAddress; }
string AllCustomers::getCity() { return city; }
string AllCustomers::getState() { return state; }
string AllCustomers::getZipCode() { return zipCode; }
string AllCustomers::getAccountNumber() { return accountNumber; }
string AllCustomers::getPhoneNumber() { return phoneNumber; }

//setters
void AllCustomers::setFirstName(string fn) { firstName = fn; }
void AllCustomers::setLastName(string ln) { lastName = ln; }
void AllCustomers::setStreetAddress(string stA) { streetAddress = stA; }
void AllCustomers::setCity(string c) { city = c; }
void AllCustomers::setState(string s){ state = s; }
void AllCustomers::setZipCode(string zc) { zipCode = zc; }
void AllCustomers::setAccountNumber(int accN) {	accountNumber = accN; }
void AllCustomers::setPhoneNumber(int pn) {	phoneNumber = pn; }



