#pragma once
#include <string>
#include "user.h"
#include "Book.h"
using namespace std;


#ifndef REGISTERUSER_H
#define REGISTERUSER_H

class RegisterUser : public User {
private:
	int id;
	string phone, fullName;
	static vector<string> username ;
	static vector<string> password ;
	static vector<string> adname ;
	static vector<string> adpassword ;
	static int userCount;
public:
	RegisterUser();
	RegisterUser(string userName, string passWord, string phone, string fullName);
	~RegisterUser();
	void addUserName(string username);
	void addPass(string password);
	void addAdName(string adName);
	void addAdPass(string adPassword);
	void setPhone(string phone);
	void setFullName(string fullName);
	void setID(int id);
	int getID();
	string getUserName(int index);
	string getPass(int index);
	string getAdName(int index);
	string getAdPass(int index);
	string getPhone();
	string getFullName();
	void read(Book* b);
	int logIn(string username, string password);
	void logOut();
};

#endif