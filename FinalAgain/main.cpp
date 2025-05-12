//using namespace std;
//#include <iomanip>
//#include <fstream>
//#include <iostream>
//#include <string>
//#include <vector>
#include "FileStuff.h"
//#include "Customers.h"
//#include "Purchases.h"

int main()
{
    vector <AllCustomers> customers;
    string customerName = "CustomerInfo.txt";
    readInCustomersFromFile(customerName, customers);

    return 0;
}