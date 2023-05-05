#include <iostream>
#include "Guest.h"
#include "Library.h"
#include "Book.h"
#include "Collection.h"
using namespace std;

Guest::Guest()
{
    id = rand();
}

Member* Guest::registering()
{
    string userName, passWord, phone, fullname;
    cout << "Enter a username: ";
    cin >> userName;
    cout << "Enter a password: ";
    cin >> passWord;
    cout << "Enter your full name: ";
    cin.ignore();
    getline(cin, fullname);
    cout << "Enter your phone number: ";
    cin >> phone;
    Member* newUser = new Member(userName, passWord, phone, fullname);
    newUser->addUserName(userName);
    newUser->addPass(passWord);
    cout << "Congratulation " << newUser->getFullName() << ", you have registered successfully" << endl;
    return newUser;
}

void Guest::read(Book* b)
{
    cout << "You are reading " << b->getFreePage() << " free pages of " << b->getTitle() << " book" << endl;
}

int Guest::getId()
{
    return id;
}

Guest::~Guest()
{
}