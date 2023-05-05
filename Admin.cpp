#include <iostream>
#include <string>
#include "Admin.h"
#include "Library.h"
using namespace std;

Admin::Admin()
{
    addAdName("root");
    addAdPass("root");
    setPhone("0235");
    setFullName("#1 Admin");
}

Admin::Admin(string userName, string passWord, string phone, string fullname)
{
    addAdName(userName);
    addAdPass(passWord);
    setPhone(phone);
    setFullName(fullname);
}


Admin::~Admin()
{
}

void Admin::addBook(Book* b, Library* l)
{
    l->addBook(b);
    cout << b->getTitle() << " has added succesfully!\n";
}

Admin* Admin::createAdmin()
{
    string userName, passWord, phone, fullname;
    cout << "Enter admin's username: ";
    cin >> userName;
    cout << "Enter admin's password: ";
    cin >> passWord;
    cout << "Enter admin's phone number: ";
    cin >> phone;
    cout << "Enter admin's full name: ";
    cin.ignore();
    getline(cin, fullname);
    Admin* newAd = new Admin(userName, passWord, phone, fullname);
    newAd->addAdName(userName);
    newAd->addAdPass(passWord);
    cout << newAd->getFullName() << " have added as a new admin" << endl;
    return newAd;
}

void Admin::show(Book* b, Library* l)
{
    for (int i = 0; i < l->getListBookSize(); i++) {
        if (l->getBook(i) == b) {
            b->setVisibilityStatus(true);
            cout << b->getTitle() << " has showed succesfully!\n";
        }
    }
}

void Admin::hide(Book* b, Library* l)
{
    for (int i = 0; i < l->getListBookSize(); i++) {
        if (l->getBook(i) == b) {
            b->setVisibilityStatus(false);
            cout << b->getTitle() << " has hided succesfully!\n";
        }
    }
}

void Admin::remove(Book* b, Library *l)
{
    bool found = false;
    vector<Book*> newBookList;
    Book* tmp = nullptr;
    for (int i = 0; i < l->getListBookSize(); i++) {
        tmp = l->getBook(i);
        if (tmp == b) {
            found = true;
            break;
        }
    }
    if (found) {
        for (int i = 0; i < l->getListBookSize(); i++) {
            if (tmp != l->getBook(i)) {
                newBookList.push_back(l->getBook(i));
            }
        }
        cout << "Book with serial number " << b->getSerialNumber() << " has been removed." << endl;
    }
    l->changeListBook(newBookList);
}

void Admin::edit(Book* b, Library* l)
{
    char choice;
    string nTitle, nSerial, nAuthor, nCa;
    int nPc, nPf;
    cout << "Do you want to change the title?(y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        cout << "Enter the new title: ";
        cin.ignore();
        getline(cin, nTitle);
        b->setTitle(nTitle);
    }
    cout << "Do you want to change the serial  number?(y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        cout << "Enter the new serial number: ";
        cin.ignore();
        getline(cin, nSerial);
        b->setSerialNumber(nSerial);
    }
    cout << "Do you want to change the author?(y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        cout << "Enter the new author: ";
        cin.ignore();
        getline(cin, nAuthor);
        b->setAuthor(nAuthor);
    }
    cout << "Do you want to change the page count?(y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        cout << "Enter the new page count: ";
        cin.ignore();
        cin >> nPc;
        b->setPageCount(nPc);
    }
    cout << "Do you want to change the free page number?(y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        cout << "Enter the new free page number: ";
        cin >> nPf;
        b->setFreePage(nPf);
    }
    cout << b->getTitle() << " has edited succesfully!\n";
}

void Admin::createCollection(string name, Library* l)
{
    char choice, more;
    string titles;
    Book* tmp = nullptr;
    Collection* collection = new Collection(name);
    l->addCollection(collection);
    cout << collection->getName() << " has created succesfully!\n";
    cout << "Do you want to add some books?(y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        do{
            cout << "Enter the book's title that you  want to add: ";
            cin.ignore();
            getline(cin, titles);
            tmp = searchByTitle(titles, l);
            if (tmp != NULL) {
                collection->addBook(tmp);
                cout << titles << " has been added succesfully!\n";
            }
            else {
                cout << "This book is not exist" << endl;
            }
            cout << "Do you want to add one more book?(Y/N): ";
            cin >> more;
        } while (more == 'y' || more == 'Y');
    }
}

void Admin::deleteCollection(string name, Library* l)
{
    vector<Collection*> newCollection;
    Collection* c = nullptr;
    bool found = false;
    for (int i = 0; i < l->getListCollectionSize(); i++) {
        c = l->getCollection(i);
        if (c->getName() == name) {
            found = true;
            break;
        }
    }
    if (found) {
        for (int i = 0; i < l->getListCollectionSize(); i++) {
            if (c != l->getCollection(i)) {
                newCollection.push_back(l->getCollection(i));
            }
        }
        l->changeListCollection(newCollection);
        cout << c->getName() << " has deleted succesfully!\n";
    }
    else {
        cout << name << " colletion doesn't exist" << endl;
    }
}


//void Admin::deleteCollection(Collection* collection, Library* l)
//{
//    Library* l = new Library();
//    for (auto it = l->getListCollection().begin(); it != l->getListCollection().end(); ++it) {
//        if (*it == collection) {
//            l->getListCollection().erase(it);
//            break;
//        }
//    }
//    delete collection;
//}