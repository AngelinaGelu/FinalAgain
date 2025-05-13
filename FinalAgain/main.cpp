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
    cout << endl << "What would you like to do?" << endl;
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
    vector<AllCustomers> customers;
    vector<AllPurchases> purchases;

    string customerFile = "CustomerInfo.txt";
    string purchaseFile = "PurchaseInfo.txt";

    if (!readInCustomersFromFile(customerFile, customers)) return 1;
    if (!readInPurchasesFromFile(purchaseFile, purchases)) return 1;

    int choice;
    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1: //prints all customers in the file
        {
            AllCustomers temp;
            temp.printCustomerList(customers);
            break;
        }
        //space
        case 2: //prints total spent for all customers
        {
            for (int i = 0; i < customers.size(); i++)
            {
                AllPurchases temp(customers[i].getAccountNumber(), "", "", "0.00");
                cout << "Customer: " << customers[i].getFirstName() << " " << customers[i].getLastName() << endl;
                temp.printCustomerTotalSpent(purchases);
                cout << "--------------------" << endl;
            }
            break;
        }
        //space
        case 3: //prints a specific customer's info
        {
            cout << endl << "Select a customer:" << endl;
            for (int i = 0; i < customers.size(); ++i)
            {
                cout << i + 1 << ". " << customers[i].getFirstName() << " " << customers[i].getLastName()
                    << " Account No.: " << customers[i].getAccountNumber() << endl;
            }

            int choice;
            cout << endl << "Enter which customer you'd like to view: ";
            cin >> choice;

            if (choice >= 1 && choice <= customers.size())
            {
                int selectedIndex = choice - 1;
                AllPurchases temp(customers[selectedIndex].getAccountNumber(), "", "", "0.00");

                temp.printCustomerTotalSpent(purchases);

                temp.printCustomerPurchaseInfo(customers, purchases);
            }
            else
            {
                cout << endl << "Invalid choice. Please select a valid customer." << endl;
            }

            cout << endl << "Press Enter to return to the menu..." << endl;
            cin.ignore();
            cin.get();

            break;
        }
        //space
        case 4: //adds a new customer
        {
            AllCustomers temp;
            AllCustomers newCustomer = temp.addNewCustomer();
            customers.push_back(newCustomer);
            cout << "New customer added." << endl;
            break;
        }
        //space
        case 5: //adds multiple customers (recursive function)
        {
            AllCustomers obj;
            obj.addMultipleCustomers(customers);
            break;
        }

        }
    } while (choice != 0);
    

    return 0;

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