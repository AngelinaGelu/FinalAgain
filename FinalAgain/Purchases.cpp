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
AllPurchases::AllPurchases(string accNum, string item, string date, string amount)
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
			total += stod(purchaseList[i].getAmount());
		}
	}

	cout << "Total amount spent by Account No. " << this->accountNumber << " is: $" << fixed << setprecision(2) << total << endl;
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

//getters
string AllPurchases::getAccNumber() { return accountNumber;  }
string AllPurchases::getItem() { return item;  }
string AllPurchases::getDate() { return date; }
string AllPurchases::getAmount() { return amount;  }