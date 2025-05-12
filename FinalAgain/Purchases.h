#pragma once
using namespace std;
#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#ifndef PURCHASES_H
#define PURCHASES_H

class AllPurchases
{
private:
	string accountNumber;
	string item, date;
	string amount;
	//vector<AllCustomers> customerList;
public:
	AllPurchases(string accNum, string item, string date, string amount);

	//void printCustomerTotalSpent();
	void printCustomerPurchaseInfo(vector<AllCustomers>& customerList);
};

#endif
