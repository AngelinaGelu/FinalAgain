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
	int accountNumber;
	string item, date;
	double amount;
public:
	AllPurchases(int accNum, string item, string date, double amount);

	void printCustomerTotalSpent();
	void printCustomerPurchaseInfo();
};

#endif
