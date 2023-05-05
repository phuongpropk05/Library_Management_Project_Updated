#include <iostream>
#include "Member.h"
#include "Library.h"
using namespace std;

Member::Member(string userName, string password, string phoneNumber, string fullName) : RegisterUser(userName, password, phoneNumber, fullName)
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);

	startYear = 1900 + ltm.tm_year;
	endYear = startYear + 4;
}

Member::Member(string userName, string password, string phoneNumber, string fullName, int startYear, int endYear) : RegisterUser(userName, password, phoneNumber, fullName)
{
	this->startYear = startYear;
	this->endYear = endYear;
}

Member::~Member()
{
	if (!borrowList.empty()) {
		for (int i = 0; i < borrowList.size(); i++) {
			if (borrowList[i]) {
				delete borrowList[i];
			}
		}
		borrowList.clear();
	}
	if (!subscribedCollections.empty()) {
		for (int i = 0; i < subscribedCollections.size(); i++) {
			if (subscribedCollections[i]) {
				delete subscribedCollections[i];
			}
		}
		subscribedCollections.clear();
	}
}

void Member::setStartYear(int sy)
{
	startYear = sy;
}

void Member::setEndYear(int ey)
{
	endYear = ey;
}

int Member::getStartYear()
{
	return startYear;
}

int Member::getEndYear()
{
	return endYear;
}

void Member::borrow(Book* b, Library* l)
{
	borrowList.push_back(b);
	b->setAvailabilityStatus(false);
	cout << "Book \"" << b->getTitle() << "\" borrowed successfully!" << endl;
}

void Member::returnBook(Book* b, Library* l)
{
	Book* tmp;
	Book* book = NULL;
	for (int i = 0; i < borrowList.size(); i++) {
		tmp = borrowList[i];
		if (tmp == b) {
			book = tmp;
		}
	}
	if(book!=NULL) {
		cout << "You have returned this book sucessfully!\n";
	}
	vector<Book*> borrowNew;
	for (int i = 0; i < borrowList.size(); i++) {
		tmp = borrowList[i];
		if (tmp != book) {
			borrowNew.push_back(tmp);
		}
	}
	borrowList = borrowNew;
}

void Member::subscribe(Collection* c)
{
	subscribedCollections.push_back(c);
	c->addUser(this);
	cout << "Successfully subscribed to the collection: " << c->getName() << endl;
}



void Member::unsubscribe(Collection* c)
{
	auto it = find(subscribedCollections.begin(), subscribedCollections.end(), c);
	if (it != subscribedCollections.end()) {
		subscribedCollections.erase(it);
		c->removeUser(this);
		cout << "Successfully unsubscribed from the collection: " << c->getName() << endl;
	}
	else {
		cout << "You are not subscribed to the collection: " << c->getName() << endl;
	}
}

Collection* Member::searchCollection(string name, Library* l)
{
	Collection* c ;
	Collection* tmp = NULL;
	for (int i = 0; i < l->getListCollectionSize(); i++) {
		c = l->getCollection(i);
		if (c->getName() == name) {
			tmp = c;
		}
	}
	return tmp;
}

int Member::getBorrowNumber()
{
	return borrowList.size();
}

void Member::displayCollectionList(bool onlySubcribe)
{
	cout << "Displaying all the books in your subscribed collection lists:" << endl;
	for (int i = 0; i < subscribedCollections.size(); i++) {
		cout << "Collection #" << i + 1 << endl;
		for (int j = 0; j < subscribedCollections[i]->getBookListSize(); i++) {
			cout << "Book #" << j + 1 << subscribedCollections[i]->getBook(j);
		}
	}
}

void Member::displayBorrowList()
{
	cout << "Displaying borrowed books list:" << endl;
	for (int i = 0; i < borrowList.size(); i++) {
		cout << i + 1 << borrowList[i] << endl;
	}
}

bool Member::isSubcribe(Collection* c, Library* l)
{
	bool check = false;
	for (int i = 0; i < subscribedCollections.size(); i++) {
		if (c == subscribedCollections[i]) {
			check = true;
		}
	}
	return check;
}




