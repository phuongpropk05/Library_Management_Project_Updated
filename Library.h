#pragma once
#include <string>
#include <vector>
#include "Member.h"
#include "Admin.h"
#include "Book.h"
#include "Collection.h"
using namespace std;

#ifndef LIBRARY_H
#define LIBRARY_H

class Library {
private:
	vector<Collection*> listCollection ;
	vector<Book*> listBook ;
	vector<Member*> memberList;
	vector<Admin*> adminList;
public:
	Library();
	Library(Collection* c, Book* b);
	~Library();
	void addBook(Book* b);
	void addCollection(Collection* c);
	void addMember(Member* m);
	void addAd(Admin* a);
	Member* getMem(int index);
	Admin* getAd(int index);
	Book* getBook(int index);
	Collection* getCollection(int index);
	int getListBookSize();
	int getListCollectionSize();
	int getMemListSize();
	int getAdListSize();
	vector<Book*> getListBook();
	vector<Collection*> getListCollection();
	void changeListCollection(vector<Collection*> newCollection);
	void changeListBook(vector<Book*> newBookList);
	void changeListMem(vector<Member*> newMemList);
	Collection* searchCollection(string name, Library* l);
};


#endif