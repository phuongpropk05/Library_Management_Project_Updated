#include <iostream>
#include "RegisterUser.h"
using namespace std;

int RegisterUser::userCount = 0;
vector<string> RegisterUser::username = {};
vector<string> RegisterUser::password = {};
vector<string> RegisterUser::adname = {};
vector<string> RegisterUser::adpassword = {};

RegisterUser::RegisterUser()
{
	id = 0;
	username.clear();
	password.clear();
	phone = "";
	fullName = "";
	userCount++;
}

RegisterUser::RegisterUser(string userName, string passWord, string phone, string fullName)
{
	username.push_back(userName);
	password.push_back(passWord);
	this->phone = phone;
	this->fullName = fullName;
	userCount++;
	id = userCount;
}

RegisterUser::~RegisterUser()
{
		username.clear();
		password.clear();
		adname.clear();
		adpassword.clear();
}

void RegisterUser::addUserName(string userName)
{
	username.push_back(userName);
}

void RegisterUser::addPass(string passWord)
{
	password.push_back(passWord);
}

void RegisterUser::addAdName(string adName)
{
	adname.push_back(adName);
}

void RegisterUser::addAdPass(string adPassword)
{
	adpassword.push_back(adPassword);
}

void RegisterUser::setPhone(string phone)
{
	this->phone = phone;
}

void RegisterUser::setFullName(string fullName)
{
	this->fullName = fullName;
}

void RegisterUser::setID(int id)
{
	this->id = id;
}

int RegisterUser::getID()
{
	return id;
}

string RegisterUser::getUserName(int index)
{
	if (index >= 0 && index < username.size()) {
		return username[index];
	}
	else {
		return NULL;
	}
}

string RegisterUser::getPass(int index)
{
	if (index >= 0 && index < password.size()) {
		return password[index];
	}
	else {
		return NULL;
	}
}

string RegisterUser::getAdName(int index)
{
	if (index >= 0 && index < adname.size()) {
		return adname[index];
	}
	else {
		return NULL;
	}
}

string RegisterUser::getAdPass(int index)
{
	if (index >= 0 && index < adpassword.size()) {
		return adpassword[index];
	}
	else {
		return NULL;
	}
}

string RegisterUser::getPhone()
{
	return phone;
}

string RegisterUser::getFullName()
{
	return fullName;
}

void RegisterUser::read(Book* b)
{
	if (b->getAvailabilityStatus())
	{
		cout << "You are reading whole the book " << b->getTitle() << " by " << b->getAuthor() << endl;
	}
	else
	{
		cout << "The book " << b->getTitle() << " by " << b->getAuthor() << " is not available for reading." << endl;
	}
}

int RegisterUser::logIn(string userName, string passWord)
{
	int loginLevel = 0;
	for (int i = 0; i < username.size(); i++) {
		if (userName == username[i] && passWord == password[i]) {
			loginLevel = 1; // 1: Member
		}
	}
	for (int i = 0; i < adname.size(); i++) {
		if (userName == adname[i] && passWord == adpassword[i]) {
			loginLevel = 2; // 2: Admin
		}
	}
	return loginLevel;
}

void RegisterUser::logOut()
{
	cout << "loguut sucessfully" << endl;
}