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
	vector<AllPurchases> purchaseList;
public:
	AllPurchases(string accNum, string item, string date, string amount);

	void printCustomerTotalSpent(vector<AllPurchases>& purchaseList); //done
	void printCustomerPurchaseInfo(vector<AllCustomers>& customerList, vector<AllPurchases>& purchaseList);

	//getters all done
	string getAccNumber();
	string getItem();
	string getDate();
	string getAmount();
};

#endif

//AllPurchases purchase1;
//
//purchase1[i].getAccount() == accNumber{
//
//	 total += purchase1[i].amount;
//}
//purchase1[1].getAccount();

