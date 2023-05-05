#include <iostream>
#include "user.h"
#include "Library.h"
using namespace std;

User::User()
{
	//listBook.clear();
	//listCollection.clear();
}

//User::User(accessibilityType level)
//{
//	accessibilityLevel = level;
//}

User::~User()
{
}

//void User::setAccessLevel(accessibilityType level)
//{
//	accessibilityLevel = level;
//}
//
//int User::getAccessLevel()
//{
//	return accessibilityLevel;
//}

//void User::read(Book* b)
//{
//}

Book* User::searchByTitle(string title, Library* l)
{
	Book* tmp;
	Book* temp = NULL;
	for (int i = 0; i < l->getListBookSize(); i++) {
		tmp = l->getBook(i);
		if (tmp->getTitle() == title) {
			temp = tmp;
		}
	}
	return temp;
}

Book* User::searchBySerial(string serialNumber, Library* l)
{
	Book* tmp;
	Book* temp = NULL;
	for (int i = 0; i < l->getListBookSize(); i++) {
		tmp = l->getBook(i);
		if (tmp->getSerialNumber() == serialNumber) {
			temp = tmp;
		}
	}
	return temp;
}