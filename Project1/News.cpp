#include "News.h"

void News::setTitle(string t)
{
	title = t;
}

void News::setDescription(string d)
{
	description = d;
}

string News::getTitle()
{
	return title;
}

string News::getDescription()
{
	return description;
}

void News::createNew()
{
	cin.ignore();
	cout << "\n\t\t\tEnter the title: ";          getline(cin, title);
	cout << "\n\t\t\tEnter the description: ";    getline(cin, description);
}

void News::showInfo()
{
	cout << title << "\n" << description;
}
