#pragma once
#include <string>
using namespace std;

#ifndef BOOK_H
#define BOOK_H


class Book {
private:
	enum BookCategorie {
		CULTURE,
		SCIENCE,
		FICTION
	};
	string serialNumber;
	string title;
	string author;
	int pageCount;
	int freePage;
	int categorie;
	bool visibilityStatus;
	bool availabilityStatus;

public:
	Book();
	Book(string sn, string t, string a, int pc, int fp, bool vs, bool as, int c = -1);
	~Book();
	string getSerialNumber();
	string getTitle();
	string getAuthor();
	int getPageCount();
	int getFreePage();
	string getCategorie();
	bool getVisibilityStatus();
	bool getAvailabilityStatus();
	void setSerialNumber(string sn);
	void setTitle(string);
	void setAuthor(string);
	void setPageCount(int);
	void setFreePage(int);
	void setCategorie(int);
	void setVisibilityStatus(bool);
	void setAvailabilityStatus(bool);
	Book& operator=(const Book& b);
};

#endif