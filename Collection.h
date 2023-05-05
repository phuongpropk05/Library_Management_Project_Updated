#pragma once
#include <vector>
#include <string>
#include "Book.h"
using namespace std;

class Member;

#ifndef  COLLECTION_H
#define COLLECTION_H

class Collection {
private:
	int ID;
	string name;
	vector<Book*> bookList;
	vector<Member*> subcribeUser;
	int catogories;
	static int count;
public:
	Collection();
	Collection(string name);
	~Collection();
	void setId(int id);
	void setName(string name);
	void addBook(Book* book);
	void addUser(Member* user);
	int getId();
	string getName();
	vector<Book*> getBookList();
	vector<Member*> getUserList();
	int getBookListSize();
	int getsSubcribeUserSize();
	void addBook(Book* book, Member* user);
	void removeUser(Member* user);
	Book* getBook(int index);
};

#endif