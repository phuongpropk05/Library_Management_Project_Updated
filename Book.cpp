#include <iostream>
#include "Book.h"
using namespace std;

Book::Book()
{
    serialNumber = " ";
    title = " ";
    author = " ";
    pageCount = 0;
    freePage = 0;
    categorie = -1;
    visibilityStatus = false;
    availabilityStatus = false;
}

Book::Book(string sn, string t, string a, int pc, int fp, bool vs, bool as, int c)
    : serialNumber(sn), title(t), author(a), pageCount(pc), freePage(fp),
    visibilityStatus(vs), availabilityStatus(as), categorie(c) {}

Book::~Book() {}

string Book::getSerialNumber() {
    return serialNumber;
}

string Book::getTitle() {
    return title;
}

string Book::getAuthor() {
    return author;
}

int Book::getPageCount() {
    return pageCount;
}

int Book::getFreePage() {
    return freePage;
}

string Book::getCategorie() {
    if (categorie == 0) {
        return "Culture";
    }
    if (categorie == 1) {
        return "Science";
    }
    if (categorie == 2) {
        return "Fiction";
    }
}

bool Book::getVisibilityStatus() {
    return visibilityStatus;
}

bool Book::getAvailabilityStatus() {
    return availabilityStatus;
}

void Book::setSerialNumber(string sn) {
    serialNumber = sn;
}

void Book::setTitle(string t) {
    title = t;
}

void Book::setAuthor(string a) {
    author = a;
}

void Book::setPageCount(int pc) {
    pageCount = pc;
}

void Book::setFreePage(int fp) {
    freePage = fp;
}

void Book::setCategorie(int c) {
    categorie = c;
}

void Book::setVisibilityStatus(bool vs) {
    visibilityStatus = vs;
}

void Book::setAvailabilityStatus(bool as) {
    availabilityStatus = as;
}

Book& Book::operator=(const Book& b)
{
    // TODO: insert return statement here
    if (this != &b) {
        this->author = b.author;
        this->availabilityStatus = b.availabilityStatus;
        this->categorie = b.categorie;
        this->freePage = b.freePage;
        this->pageCount = b.pageCount;
        this->serialNumber = b.serialNumber;
        this->title = b.title;
        this->visibilityStatus = b.visibilityStatus;
    }
    return *this;
}
