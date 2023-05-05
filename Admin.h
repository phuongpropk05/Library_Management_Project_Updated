#pragma once
#include <string>
#include<vector>
#include "RegisterUser.h"
#include "Book.h"
#include "Collection.h"
using namespace std;

class Library;

#ifndef ADMIN_H
#define ADMIN_H

class Admin : public RegisterUser {
public:
	Admin();
	Admin(string userName, string passWord, string phone, string fullname);
	~Admin();
	void addBook(Book* b, Library* l);
	Admin* createAdmin();
	void show(Book* b, Library* l);
	void hide(Book* b, Library* l);
	void remove(Book* b, Library *l);
	void edit(Book* b, Library* l);
	void createCollection(string name, Library* l);
	void deleteCollection(string name, Library* l);
	//void deleteCollection(Collection* c);
};

#endif