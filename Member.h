#pragma once
#include <vector>
#include "RegisterUser.h"
#include "Book.h"
#include "Collection.h"
using namespace std;

class Library;

#ifndef MEMBER_H
#define MEMBER_H

class Member : public RegisterUser {
private:
    int startYear;
    int endYear;
    vector<Book*> borrowList;
    vector<Collection*> subscribedCollections;
public:
    Member(string userName, string password, string phoneNumber, string fullName);
    Member(string userName, string password, string phoneNumber, string fullName, int startYear, int endYear);
    ~Member();
    void setStartYear(int sy);
    void setEndYear(int ey);
    int getStartYear();
    int getEndYear();
    void borrow(Book* b, Library* l);
    void returnBook(Book* b, Library* l);
    void subscribe(Collection* c);
    void unsubscribe(Collection* c);
    Collection* searchCollection(string name, Library* l);
    int getBorrowNumber();
    void displayCollectionList(bool onlySubscribed);
    void displayBorrowList();
};

#endif