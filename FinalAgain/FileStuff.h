#pragma once
#pragma once
using namespace std;
#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#ifndef FILESTUFF_H
#define FILESTUFF_H

//reads in file info to the program
template <typename obj>
vector<obj> readInFromFile(string& filenname, obj (*parseFunc)(string&))
{
	vector<obj> data;
	ifstream file(filename);

	if (!file)
	{
		cout << "There was an error opening " << filename << endl;
		return data;
	}

	string line;
	while (getline(file, line))
	{
		data.push_back(parseFunc(line));
	}

	file.close();
	return data;
}

#endif