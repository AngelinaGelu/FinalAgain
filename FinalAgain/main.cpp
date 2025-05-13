//using namespace std;
//#include <iomanip>
//#include <fstream>
//#include <iostream>
//#include <string>
//#include <vector>
#include "FileStuff.h"
//#include "Customers.h"
//#include "Purchases.h"

void menu()
{
    cout << "Welcome to my final! (It was really bad)" << endl;
    cout << "What would you like to do?" << endl;
    cout << "---------- Manager Menu ----------" << endl;
    cout << "1. Print all customers" << endl;
    cout << "2. Print total spent for all customers" << endl;
    cout << "3. Print a specific customer's account + purchases" << endl;
    cout << "4. Add a new customer" << endl;
    cout << "5. Add multiple customers (recursive)" << endl;
    cout << "6. Update a customer" << endl;
    cout << "7. Delete a customer" << endl;
    cout << "8. Add a new customer purchase" << endl;
    cout << "9. Add multiple new purchases (recursive)" << endl;
    cout << "10. Save to file (overwrite or new copy)" << endl;
    cout << "11. Sort customers by first name (ascending)" << endl;
    cout << "12. Sort customers by first name (descending)" << endl; 
    cout << "0. Exit" << endl;
    cout << "---------- Manager Menu ----------" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    //vector<AllCustomers> customers;
    //vector<AllPurchases> purchases;

    //string customerFile = "CustomerInfo.txt";
    //string purchaseFile = "PurchaseInfo.txt";

    //if (!readInCustomersFromFile(customerFile, customers)) return 1;
    //if (!readInPurchasesFromFile(purchaseFile, purchases)) return 1;

    //AllPurchases dummy("", "", "", "0.00");
    //dummy.printCustomerPurchaseInfo(customers, purchases);

    //int choice;
    //do
    //{
    //    menu();
    //    cin >> choice;

    //    switch (choice)
    //    {
    //    case 1:
    //    {
    //        AllCustomers temp;
    //        temp.printCustomerList(customers);
    //        break;
    //    }
    //    case 2:
    //    {
    //        // print total spent for all customers
    //        for (int i = 0; i < customers.size(); i++)
    //        {
    //            AllPurchases temp(customers[i].getAccountNumber(), "", "", "0.00");
    //            cout << "Customer: " << customers[i].getFirstName() << " " << customers[i].getLastName() << endl;
    //            temp.printCustomerTotalSpent(purchases);
    //            cout << "--------------------" << endl;
    //        }
    //        break;
    //    }
    //    }
    //} while (choice != 0);
    //

    //return 0;

    /*if (!readInCustomersFromFile(customerFile, customers)) return 1;
    if (!readInPurchasesFromFile(purchaseFile, purchases)) return 1;

    int choice;

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            AllCustomers temp;
            temp.printCustomerList(customers);
            break;
        }
        case 2:
            break;
        }
    } while (choice != 0);*/

    //vector<AllCustomers> customers;
    //vector<AllPurchases> purchases;

    //string customerFile = "CustomerInfo.txt";
    //string purchaseFile = "PurchaseInfo.txt";

    //if (!readInCustomersFromFile(customerFile, customers)) return 1;
    //if (!readInPurchasesFromFile(purchaseFile, purchases)) return 1;

    ////loop through each customer and print their total purchases
    //for (int i = 0; i < customers.size(); i++)
    //{
    //    string accNum = customers[i].getAccountNumber();

    //    //create a temp AllPurchases object using their account number
    //    AllPurchases temp(accNum, "", "", "");
    //    cout << "Customer: " << customers[i].getFirstName() << " " << customers[i].getLastName() << endl;
    //    temp.printCustomerTotalSpent(purchases);
    //    cout << "--------------------" << endl;
    //}

    //return 0;
}