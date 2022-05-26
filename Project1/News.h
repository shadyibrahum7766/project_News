#pragma once
#include <string>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include "cassert"
#include <string>
using namespace std;

class News
{

public:
	string title;
	string description;
	
	// Setter
	void setTitle(string t);
	void setDescription(string d);

	// Getter
	string getTitle();
	string getDescription();

	void createNew();
	void showInfo();

};

