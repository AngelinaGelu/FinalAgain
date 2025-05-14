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
	AllPurchases(string accNum = "0", string item = "0", string date = "0", string amount = "0");

	void printCustomerTotalSpent(vector<AllPurchases>& purchaseList); //done
	void printCustomerPurchaseInfo(); //done

	AllPurchases addNewPurchase(vector<AllCustomers>& customerList); //done

	AllPurchases addMultipleNewPurchases(vector<AllCustomers>& customerList);

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

