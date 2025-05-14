//using namespace std;
//#include <iomanip>
//#include <fstream>
//#include <iostream>
//#include <string>
//#include <vector>
#include "FileStuff.h"
//#include "Customers.h"
//#include "Purchases.h"
#include <limits>

void printAllPurchases(string id, vector <AllPurchases>& purchase) {
    for (int i = 0; i < purchase.size(); i++) {
        if (id == purchase[i].getAccNumber()) {
            //cout << "\n--------------------" << endl;
            cout << endl << "\nAccount No.: " << purchase[i].getAccNumber();
            cout << endl << "Item: " << purchase[i].getItem();
            cout << endl << "Date: " << purchase[i].getDate();
            cout << endl << "Amount $:" << purchase[i].getAmount();
            //cout << "--------------------";
        }
    }
}

void menu()
{
    cout << endl << "What would you like to do?" << endl;
    cout << "\n---------- Manager Menu ----------" << endl;
    cout << "1. Print all customers" << endl;
    cout << "2. Print total spent for all customers" << endl;
    cout << "3. Print a specific customer's account info + purchases" << endl;
    cout << "4. Add a new customer" << endl;
    cout << "5. Add multiple customers (recursive)" << endl;
    cout << "6. Update a customer" << endl;
    cout << "7. Delete a customer" << endl;
    cout << "8. Add a new customer purchase" << endl;
    cout << "9. Add multiple new purchases (recursive)" << endl;
    cout << "10. Save to file" << endl;
    cout << "11. Sort customers by first name (ascending)" << endl;
    cout << "12. Sort customers by first name (descending)" << endl; 
    cout << "0. Exit" << endl;
    cout << "---------- Manager Menu ----------" << endl;
    cout << "\nEnter your choice: ";
}

int main()
{
    vector<AllCustomers> customers;
    vector<AllPurchases> purchases;

    string customerFile = "CustomerInfo.txt";
    string purchaseFile = "PurchaseInfo.txt";

    //needed
    readInCustomersFromFile(customerFile, customers);
    readInPurchasesFromFile(purchaseFile, purchases);

    /*if (!readInCustomersFromFile(customerFile, customers)) return 1;
    if (!readInPurchasesFromFile(purchaseFile, purchases)) return 1;*/


    
    int choice;
    do
    {
        menu();

        
		while (!(cin >> choice)) //input validation
		{
			cout << "Invalid input. Please enter a number: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

        switch (choice)
        {
        case 1: //prints all customers in the file
        {
            printCustomerList(customers);
            cout << endl << "Press Enter to return to the menu..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
        //space
        case 2: //prints total spent for all customers
        {
            for (int i = 0; i < customers.size(); i++)
            {
                cout << "--------------------" << endl;
                AllPurchases temp(customers[i].getAccountNumber(), "", "", 0.00);
                cout << "Customer: " << customers[i].getFirstName() << " " << customers[i].getLastName() << endl;
                temp.printCustomerTotalSpent(purchases);
                cout << "--------------------" << endl;
            }
            cout << endl << "Press Enter to return to the menu..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
        //space
        case 3: //prints a specific customer's info
        {
            cout << endl << "Select a customer:" << endl;
            for (int i = 0; i < customers.size(); ++i)
            {
                cout << "--------------------" << endl;
                cout << i + 1 << ". " << customers[i].getFirstName() << " " << customers[i].getLastName() << endl << " Account No.: " << customers[i].getAccountNumber() << endl;
                cout << "--------------------" << endl;
            }

            int poo;
            cout << endl << "Enter which customer you'd like to view: ";
            while (!(cin >> poo)) {
                cout << "Invalid input. Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (poo >= 1 && poo <= customers.size())
            {
                customers[poo-1].printCustomerInfo();
                /*purchases[poo-1].printCustomerPurchaseInfo();*/
                printAllPurchases(customers[poo - 1].getAccountNumber(), purchases);
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
            cout << endl << "Press Enter to return to the menu..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
        //space
        case 5: //adds multiple customers (recursive function)
        {
            AllCustomers obj;
            obj.addMultipleCustomers(customers);
            cout << endl << "Press Enter to return to the menu..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
        //space
        case 6: //update a customer
        {
            AllCustomers ac;
            ac.updateCustomerInfo(customers);
            cout << endl << "Press Enter to return to the menu..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
        //space
        case 7: //deletes a customer
        {
            AllCustomers ac;
            ac.deleteCustomer(customers);
            cout << endl << "Press Enter to return to the menu..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
        //space
        case 8: //add a new customer purchase
        {
            AllPurchases ap;
            AllPurchases newPurchase = ap.addNewPurchase(customers);
            purchases.push_back(newPurchase);
            cout << "New purchase added successfully." << endl;
            cout << "\nPress Enter to return to the menu..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
        //space
        case 9:
        {
            AllPurchases ap;
            AllPurchases newPurchase = ap.addMultipleNewPurchases(customers);
            purchases.push_back(newPurchase);
            cin.ignore();
            cin.get();
            break;
        }
        //space
        case 10: //saves purchases to file
        {
            savePurchasesToFile(purchases);
			saveCustomersToFile(customers);
            cout << "Press Enter to return to the menu..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
        //space
        case 11: //sorts customer list to ascending
        {
            sortCustomerListAscending(customers);
            cout << "Customer list sorted in ascending order." << endl;
            cout << "Press Enter to return to the menu..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
        //space
        case 12: //sorts customer list to descending
        {
            sortCustomerListDescending(customers);
            cout << "Customer list sorted in ascending order." << endl;
            cout << "Press Enter to return to the menu..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
        default:
			if ((choice >=1 && choice <= 12)) {
				cout << "Invalid choice. Please try again." << endl;
			}
			break;
		}
		if (choice == 0) {
			cout << "Exiting the program..." << endl;
			cout << "Press Enter to exit." << endl;
			cin.ignore();
			cin.get();
			break;
            

        }
    } while (choice != 0);
    

    return 0;
}
