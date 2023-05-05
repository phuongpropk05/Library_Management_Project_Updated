#pragma once
#include <string>
#include <vector>
#include "Book.h"
using namespace std;

class Library;

#ifndef USER_H
#define USER_H

class User {
public:
	User();
	//User(accessibilityType level);
	~User();
	/*void setAccessLevel(accessibilityType level);
	int getAccessLevel();*/
	virtual void read(Book* b) = 0;
	Book* searchByTitle(string title, Library* l);
	Book* searchBySerial(string serialNumber, Library* l);
};

#endif