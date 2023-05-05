#include <iostream>
#include "Member.h"
#include "Collection.h"
using namespace std;

int Collection::count = 0;

Collection::Collection()
{
	ID = 0;
	name = "";
	bookList.clear();
	subcribeUser.clear();
}

Collection::Collection(string name)
{
	ID = ++count;
	this->name = name;
	bookList.clear();
	subcribeUser.clear();
}

Collection::~Collection()
{
	if (!bookList.empty()) {
		for (int i = 0; i < bookList.size(); i++) {
			if (bookList[i]) {
				delete bookList[i];
			}
		}
		bookList.clear();
	}
	if (!subcribeUser.empty()) {
		for (int i = 0; i < subcribeUser.size(); i++) {
			if (subcribeUser[i]) {
				delete subcribeUser[i];
			}
		}
		subcribeUser.clear();
	}
}

void Collection::setId(int id)
{
	ID = id;
}

void Collection::setName(string name)
{
	this->name = name;
}

void Collection::addBook(Book* book)
{
	bookList.push_back(book);
}

void Collection::addUser(Member* user)
{
	subcribeUser.push_back(user);
}

int Collection::getId()
{
	return ID;
}

string Collection::getName()
{
	return name;
}

vector<Book*> Collection::getBookList()
{
	vector<Book*> books;
	for (int i = 0; i < bookList.size(); i++) {
		books.push_back(bookList[i]);
	}
	return books;
}

vector<Member*> Collection::getUserList()
{
	vector<Member*> Member;
	for (int i = 0; i < subcribeUser.size(); i++) {
		Member.push_back(subcribeUser[i]);
	}
	return Member;
}

int Collection::getBookListSize()
{
	return bookList.size();
}

int Collection::getsSubcribeUserSize()
{
	return subcribeUser.size();
}

void Collection::addBook(Book* book, Member* user)
{
	bookList.push_back(book);
	subcribeUser.push_back(user);
}

void Collection::removeUser(Member* user)
{
	// Find the user in the subscribed user list
	auto it = find(subcribeUser.begin(), subcribeUser.end(), user);

	// If user is found, remove it
	if (it != subcribeUser.end()) {
		subcribeUser.erase(it);
	}
}

Book* Collection::getBook(int index)
{
	if (index >= 0 && index <= bookList.size()) {
		return bookList[index];
	}
	else {
		return NULL;
	}
}
