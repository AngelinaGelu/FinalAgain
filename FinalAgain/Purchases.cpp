using namespace std;
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "FileStuff.h"
#include "Customers.h"
#include "Purchases.h"

//default constructor
AllPurchases::AllPurchases(int accNum, string item, string date, double amount)
{
	this->accountNumber = accNum;
	this->item = item;
	this->date = date;
	this->amount = amount;
}

//prints the purchase information for a customer
void AllPurchases::printCustomerPurchaseInfo(vector<AllCustomers>& customerList)
{
	for (int i = 0; i < customerList.size(); i++)
	{
		cout << "--------------------" << endl;
		cout << "Customer #" << (i + 1) << endl;
		cout << "Account No.: " << customerList[i].getAccountNumber() << endl;
		cout << "Name: " << customerList[i].getFirstName() << ' ' << customerList[i].getLastName() << endl;
		cout << "Items Purchased: " << endl;
		//cout << "Total Amount Spent: $" << fixed << setprecision(2) << customerList[i].totalSpent << endl;
		cout << "--------------------" << endl;
	}
}