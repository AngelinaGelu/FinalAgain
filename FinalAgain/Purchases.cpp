using namespace std;
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Purchases.h"

void AllPurchases::printCustomerPurchaseInfo()
{
	for (int i = 0; i < customerList.size(); i++)
	{
		cout << "--------------------" << endl;
		cout << "Customer #" << (i + 1) << endl;
		cout << "Account No.: " << customerList[i].accountNumber << endl;
		cout << "Name: " << customerList[i].firstName << ' ' << customerList[i].lastName << endl;
		cout << "Items Purchased: " << endl;
		//cout << "Total Amount Spent: $" << fixed << setprecision(2) << customerList[i].totalSpent << endl;
		cout << "--------------------" << endl;
	}
}