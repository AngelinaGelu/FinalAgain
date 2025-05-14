//using namespace std;
//#include <iomanip>
//#include <fstream>
//#include <iostream>
//#include <string>
//#include <vector>
//#include "FileStuff.h"
#include "Customers.h"
#include "Purchases.h"

//default constructor
AllPurchases::AllPurchases(string accNum, string item, string date, double amount)
{
	this->accountNumber = accNum;
	this->item = item;
	this->date = date;
	this->amount = amount;
}

//prints the total spent by each customer
void AllPurchases::printCustomerTotalSpent(vector<AllPurchases>& purchaseList)
{
	double total = 0;
	for (int i = 0; i < purchaseList.size(); i++)
	{
		if (purchaseList[i].getAccNumber() == this->accountNumber)
		{
			total += purchaseList[i].getAmount();
		}
	}

	cout << "Total amount spent by Account No. " << this->accountNumber << " is: $" << fixed << setprecision(2) << total << endl;
}

//prints the purchase information for a customer

void AllPurchases::printCustomerPurchaseInfo()
{
	cout << "\n--------------------" << endl;
	cout << "Account No.: " << getAccNumber() << endl;
	cout << "Item: " << getItem() << endl;
	cout << "Date: " << getDate() << endl;
	cout << "Amount: " << getAmount() << endl;
	cout << "\n--------------------" << endl;



	/*if (customerList.empty())
	{
		cout << "No customers found. " << endl;
		return;
	}

	cout << "Select a customer: " << endl;
	for (int i = 0; i < customerList.size(); i++)
	{
		cout << i + 1 << ". " << customerList[i].getFirstName() << " " << customerList[i].getLastName() << endl <<  "Account No.: " << customerList[i].getAccountNumber() << endl;
	}

	int choice;
	cout << "Enter which customer you'd like to view: ";
	cin >> choice;

	if (choice < 1 || choice > customerList.size())
	{
		cout << "Invalid choice. " << endl;
		return;
	}

	printCustomerList(customerList);

	printCustomerTotalSpent(purchaseList);*/








	/*for (int i = 0; i < customerList.size(); i++)
	{
		cout << "--------------------" << endl;
		cout << "Customer #" << (i + 1) << endl;
		cout << "Account No.: " << customerList[i].getAccountNumber() << endl;
		cout << "Name: " << customerList[i].getFirstName() << ' ' << customerList[i].getLastName() << endl;
		cout << "Items Purchased: " << endl;

		AllPurchases temp(customerList[i].getAccountNumber(), "", "", "0.00");
		temp.printCustomerTotalSpent(purchaseList);
		cout << "--------------------" << endl;
	}*/
}

//adds a new purchase for a customer
AllPurchases AllPurchases::addNewPurchase(vector<AllCustomers>& customerList)
{
	if (customerList.empty())
	{
		cout << "No customers available. Cannot add a purchase." << endl;
		return AllPurchases("", "", "", 0.00);
	}

	// Display numbered list of customers
	cout << "Select a customer by number:\n";
	for (size_t i = 0; i < customerList.size(); ++i)
	{
		cout << "\n--------------------" << endl;
		cout << (i + 1) << ". " << "Account: " << customerList[i].getAccountNumber() << endl << "Name: " << customerList[i].getFirstName() << customerList[i].getLastName() << endl;
		cout << "--------------------" << endl;
	}

	size_t selectedIndex;
	cout << "Enter your choice (1 - " << customerList.size() << "): ";
	cin >> selectedIndex;

	if (cin.fail() || selectedIndex < 1 || selectedIndex > customerList.size())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid selection. Purchase not added." << endl;
		return AllPurchases("", "", "", 0.00);
	}

	string accNum = customerList[selectedIndex - 1].getAccountNumber();

	string item, date;
	double amount;

	cout << "Enter the item name: ";
	cin >> ws;
	getline(cin, item);

	cout << "Enter the date (MM/DD/YYYY): ";
	getline(cin, date);

	cout << "Enter the amount: $";
	cin >> amount;
	while (cin.fail())
	{
		cout << "Invalid input. Please enter a number: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> amount;
	}

	return AllPurchases(accNum, item, date, amount);

}

//adds multiple purchases to a customer
AllPurchases AllPurchases::addMultipleNewPurchases(vector<AllCustomers>& customerList)
{
	char choice;

	AllPurchases newPurchase = addNewPurchase(customerList);
	purchaseList.push_back(newPurchase);

	cout << "Would you like to add a purchase? (y/n): ";
	cin >> choice;

	if (choice == 'y' || choice == 'Y')
	{
		addMultipleNewPurchases(customerList);
	}
	else
	{
		cout << "Finished adding purchases." << endl;
	}

	return newPurchase;
}


//getters
string AllPurchases::getAccNumber() { return accountNumber;  }
string AllPurchases::getItem() { return item;  }
string AllPurchases::getDate() { return date; }
double AllPurchases::getAmount() { return amount;  }