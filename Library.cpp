#include <iostream>
#include <string>
#include "Library.h"
using namespace std;

Library::Library()
{
	listBook.clear();
	listCollection.clear();
}

Library::Library(Collection* c, Book* b)
{
	listCollection.push_back(c);
	listBook.push_back(b);
}

Library::~Library()
{
}

void Library::addBook(Book* b)
{
	listBook.push_back(b);
}

void Library::addCollection(Collection* c)
{
	listCollection.push_back(c);
}

void Library::addMember(Member* m)
{
	memberList.push_back(m);
}

void Library::addAd(Admin* a)
{
	adminList.push_back(a);
}

Member* Library::getMem(int index)
{
	if (index >= 0 && index <= memberList.size()) {
		return memberList[index];
	}
	else {
		return NULL;
	}
}

Admin* Library::getAd(int index)
{
	if (index >= 0 && index <= adminList.size()) {
		return adminList[index];
	}
	else {
		return NULL;
	}
}

int Library::getListBookSize()
{
	return listBook.size();
}

int Library::getListCollectionSize()
{
	return listCollection.size();
}

vector<Book*> Library::getListBook()
{
	return listBook;
}

int Library::getMemListSize()
{
	return memberList.size();
}

vector<Collection*> Library::getListCollection()
{
	return listCollection;
}

int Library::getAdListSize()
{
	return adminList.size();
}

void Library::changeListCollection(vector<Collection*> newCollection)
{
	listCollection = newCollection;
}

void Library::changeListBook(vector<Book*> newBookList)
{
	listBook = newBookList;
}

Collection* Library::searchCollection(string name, Library* l)
{
	Collection* tmp;
	Collection* temp = NULL;
	for (int i = 0; i < l->getListBookSize(); i++) {
		tmp = l->getCollection(i);
		if (tmp->getName() == name) {
			temp = tmp;
		}
	}
	return temp;
}

void Library::changeListMem(vector<Member*> newMemList)
{
	memberList = newMemList;
}

Book* Library::getBook(int index)
{
	if (index >= 0 && index <= listBook.size()) {
		return listBook[index];
	}
	else {
		return NULL;
	}
}

Collection* Library::getCollection(int index)
{
	if (index >= 0 && index <= getListCollectionSize()) {
		return listCollection[index];
	}
	else {
		return NULL;
	}
}





