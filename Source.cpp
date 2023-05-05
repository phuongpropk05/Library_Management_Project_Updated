//#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "RegisterUser.h"
#include "Member.h"
#include "Admin.h"
#include "Guest.h"
#include "Book.h"
#include "Collection.h"
#include "Menu.h"
#include "Library.h"
using namespace std;

enum ACTION {
	LOGIN,
	LOGOUT,
	REGISTER,
	GUEST,
	ADD,
	SHOW,
	HIDE,
	EDIT,
	REMOVE,
	CREATE_COLLECTION,
	DELETE_COLLECTION,
	CREATE_ADMIN,
	BORROW,
	RETURN,
	SUBCRIBE,
	UNSUBCRIBE,
	READ,
	READG,
	SEARCH_TITLE,
	SEARCH_SERIAL,
	SHOW_BOOKS,
	SHOW_COLLECTIONS,
	EXIT
};

int main() {
	Menu* mainMenu = new Menu("Main Menu", "Welcome");
	Menu* login = new Menu("Login", "Welcome Back", LOGIN);
	Menu* registering = new Menu("Register", "Welcome New Member", REGISTER);
	Menu* guest = new Menu("Login As Guess", "Welcome To Our Community", GUEST);
	Menu* exit = new Menu("Exit", "See you soon", EXIT);

	mainMenu->addSubMenu(login);
	mainMenu->addSubMenu(registering);
	mainMenu->addSubMenu(guest);
	mainMenu->addSubMenu(exit);

	login->addSubMenu(mainMenu);
	registering->addSubMenu(mainMenu);

	Menu* logout = new Menu("Log out", "See you again", LOGOUT);
	Menu* readBookA = new Menu("Read Book", "", READ);
	Menu* readBookM = new Menu("Read Book", "", READ);
	Menu* readBookG = new Menu("Read Book", "", READG);
	Menu* searchBookA = new Menu("Search Book", "");
	Menu* searchBookM = new Menu("Search Book", "");
	Menu* searchBookG = new Menu("Search Book", "");
	Menu* byTitleA = new Menu("Search by Title", "", SEARCH_TITLE);
	Menu* byTitleM = new Menu("Search by Title", "", SEARCH_TITLE);
	Menu* byTitleG = new Menu("Search by Title", "", SEARCH_TITLE);
	Menu* bySerialA = new Menu("Search by Serial", "", SEARCH_SERIAL);
	Menu* bySerialM = new Menu("Search by Serial", "", SEARCH_SERIAL);
	Menu* bySerialG = new Menu("Search by Serial", "", SEARCH_SERIAL);

	searchBookA->addSubMenu(byTitleA);
	byTitleA->addSubMenu(searchBookA);
	searchBookA->addSubMenu(bySerialA);
	bySerialA->addSubMenu(searchBookA);

	searchBookM->addSubMenu(byTitleM);
	byTitleM->addSubMenu(searchBookM);
	searchBookM->addSubMenu(bySerialM);
	bySerialM->addSubMenu(searchBookM);

	searchBookG->addSubMenu(byTitleG);
	byTitleG->addSubMenu(searchBookG);
	searchBookG->addSubMenu(bySerialG);
	bySerialG->addSubMenu(searchBookG);

	// Menu sau khi Admin Login
	Menu* menuAdmin = new Menu("Admin's Menu", "Welcom Admin");

	Menu* addBook = new Menu("Add Book", "", ADD);
	Menu* showBook = new Menu("Show Book", "", SHOW);
	Menu* hideBook = new Menu("Hide Book", "", HIDE);
	Menu* removeBook = new Menu("Remove Book", "", REMOVE);
	Menu* editBook = new Menu("Edit Book", "", EDIT);
	Menu* manageCollection = new Menu("Manage Collection", "");
	Menu* createCollection = new Menu("Create Collection", "", CREATE_COLLECTION);
	Menu* deleteCollection = new Menu("Delete Collection", "", DELETE_COLLECTION);
	Menu* createAdmin = new Menu("Create Admin", "", CREATE_ADMIN);
	Menu* bookListA = new Menu("See Book List", "", SHOW_BOOKS);
	Menu* collectionListA = new Menu("See Collection List", "", SHOW_COLLECTIONS);

	menuAdmin->addSubMenu(bookListA);
	bookListA->addSubMenu(menuAdmin);
	menuAdmin->addSubMenu(addBook);
	addBook->addSubMenu(menuAdmin);
	menuAdmin->addSubMenu(showBook);
	showBook->addSubMenu(menuAdmin);
	menuAdmin->addSubMenu(hideBook);
	hideBook->addSubMenu(menuAdmin);
	menuAdmin->addSubMenu(removeBook);
	removeBook->addSubMenu(menuAdmin);
	menuAdmin->addSubMenu(editBook);
	editBook->addSubMenu(menuAdmin);
	menuAdmin->addSubMenu(createAdmin);
	createAdmin->addSubMenu(menuAdmin);
	menuAdmin->addSubMenu(manageCollection);
	manageCollection->addSubMenu(createCollection);
	createCollection->addSubMenu(manageCollection);
	manageCollection->addSubMenu(deleteCollection);
	deleteCollection->addSubMenu(manageCollection);
	manageCollection->addSubMenu(collectionListA);
	collectionListA->addSubMenu(manageCollection);
	manageCollection->addSubMenu(menuAdmin);
	menuAdmin->addSubMenu(readBookA);
	readBookA->addSubMenu(menuAdmin);
	menuAdmin->addSubMenu(searchBookA);
	searchBookA->addSubMenu(menuAdmin);
	menuAdmin->addSubMenu(logout);


	// Menu sau khi Member Login
	Menu* menuMember = new Menu("Member's Menu", "Welcom Our Member");

	Menu* borrowBook = new Menu("Borrow Book", "", BORROW);
	Menu* returnBook = new Menu("Return Book", "", RETURN);
	Menu* subcribeCollection = new Menu("Subcribe Book Collection", "", SUBCRIBE);
	Menu* unsubcribeCollection = new Menu("Unsubcribe Book Collection", "", UNSUBCRIBE);
	Menu* bookListM = new Menu("See Book List", "", SHOW_BOOKS);
	Menu* collectionListM = new Menu("See Collection List", "", SHOW_COLLECTIONS);

	menuMember->addSubMenu(bookListM);
	bookListM->addSubMenu(menuMember);
	menuMember->addSubMenu(borrowBook);
	borrowBook->addSubMenu(menuMember);
	menuMember->addSubMenu(returnBook);
	returnBook->addSubMenu(menuMember);
	menuMember->addSubMenu(collectionListM);
	collectionListM->addSubMenu(menuMember);
	menuMember->addSubMenu(subcribeCollection);
	subcribeCollection->addSubMenu(menuMember);
	menuMember->addSubMenu(unsubcribeCollection);
	unsubcribeCollection->addSubMenu(menuMember);
	menuMember->addSubMenu(readBookM);
	readBookM->addSubMenu(menuMember);
	menuMember->addSubMenu(searchBookM);
	searchBookM->addSubMenu(menuMember);
	menuMember->addSubMenu(logout);

	// Menu sau khi Login As Guess
	Menu* bookListG = new Menu("See Book List", "", SHOW_BOOKS);
	Menu* collectionListG = new Menu("See Collection List", "", SHOW_COLLECTIONS);

	guest->addSubMenu(bookListG);
	bookListG->addSubMenu(guest);
	guest->addSubMenu(readBookG);
	readBookG->addSubMenu(guest);
	guest->addSubMenu(searchBookG);
	searchBookG->addSubMenu(guest);
	guest->addSubMenu(registering);
	guest->addSubMenu(mainMenu);

	logout->addSubMenu(mainMenu);

	Menu* currentMenu = mainMenu;

	Book* book1 = new Book("000001", "Book 1", "Author 1", 201, 75, true, true, 0);
	Book* book2 = new Book("000002", "Book 2", "Author 2", 111, 12, true, true, 2);
	Book* book3 = new Book("000003", "Book 3", "Author 3", 321, 62, true, true, 2);
	Book* book4 = new Book("000004", "Book 4", "Author 4", 231, 0, true, true, 1);

	Library* l = new Library();
	l->addBook(book1);
	l->addBook(book2);
	l->addBook(book3);
	l->addBook(book4);

	Collection* c = new Collection("Sample");
	c->addBook(book1);
	c->addBook(book2);
	l->addCollection(c);

	bool a = true;

	//User user;
	RegisterUser* reUser = new RegisterUser();
	string u, p;
	Guest* guest1 = new Guest();
	Book* tmp = new Book("","","",0,0,false,false);
	string titles, sNumber, author, nameC;
	int pc, pf, ca, vs, as, level = -1;
	char choose, choose1;

	Admin* admin = new Admin();
	l->addAd(admin);
	vector<Member*> memList;
	Member* member1 = new Member("phuong", "phuong", "123456", "Nguyen Nhu Hoang Phuong");
	Member* member2 = new Member("abcd", "abcd", "999999", "abcd efgh");
	memList.push_back(member1);
	memList.push_back(member2);
	l->changeListMem(memList);

	Collection* temp;
	Member* mTmp;
	Member* currentMember = nullptr;
	Admin* curentAdmin = nullptr;

	while (a == true) {
		currentMenu->displayMenu();
		int choice = currentMenu->promtOption();
		currentMenu = currentMenu->getSubMenu(choice);
		switch (currentMenu->getAction()) {
		case -1:
			break;
		case LOGIN: // checked, no error
			system("cls");
			cout << "Enter your username: ";
			cin >> u;
			cout << "Enter your password: ";
			cin >> p;
			level = reUser->logIn(u, p);
			if (level == 2) {
				for (int i = 0; i < l->getAdListSize(); i++) {
					if (u == l->getAd(i)->getAdName(i) && p == l->getAd(i)->getAdPass(i)) {
						curentAdmin = l->getAd(i);
						currentMenu = menuAdmin;
						currentMenu->setDescription("Welcom " + l->getAd(i)->getFullName());
					}
				}
			}
			else if (level == 1) {
				for (int i = 0; i < l->getMemListSize(); i++) {
					if (u == l->getMem(i)->getUserName(i) && p == l->getMem(i)->getPass(i)) {
						currentMember = l->getMem(i);
						currentMenu = menuMember;
						currentMenu->setDescription("Welcom " + l->getMem(i)->getFullName());
					}
				}
			}
			else if (level == 0) {
				cout << "Your usermame or password was wrong" << endl;
				currentMenu = mainMenu;
				system("pause");
			}
			break;
		case REGISTER: // checked, no error
			system("cls");
			mTmp = guest1->registering();
			l->addMember(mTmp);
			currentMember = mTmp;
			level = 1;
			cout << "Welcome " << mTmp->getFullName() << endl;
			currentMenu = menuMember;
			currentMenu->setDescription("Welcom " + mTmp->getFullName());
			break;
		case GUEST:
			guest1 = new Guest();
			level = -1;
			break;
		case ADD: //checked, no error
			system("cls");
			cout << "Enter the book's title: ";
			cin.ignore();
			getline(cin, titles);
			tmp->setTitle(titles);
			cout << "Enter the book's serial number: ";
			getline(cin, sNumber);
			tmp->setSerialNumber(sNumber);
			cout << "Enter the book's author: ";
			getline(cin, author);
			tmp->setAuthor(author);
			cout << "Enter the number of page of this book: ";
			cin >> pc;
			tmp->setPageCount(pc);
			cout << "Enter the number of free page of this book: ";
			cin >> pf;
			tmp->setFreePage(pf);
			cout << "Enter the book's categories (0: culture, 1: science, 2: fiction): ";
			cin >> ca;
			tmp->setCategorie(ca);
			cout << "Enter the book's visibility status (0: hide, 1: show): ";
			cin >> vs;
			if (vs == 1) {
				tmp->setVisibilityStatus(true);
			}
			else if (vs == 0) {
				tmp->setVisibilityStatus(false);
			}
			cout << "Enter the book's availability status (0: unavailable, 1: available): ";
			cin >> as;
			if (as == 1) {
				tmp->setAvailabilityStatus(true);
			}
			else if (as == 0) {
				tmp->setAvailabilityStatus(false);
			}
			curentAdmin->addBook(tmp, l);
			system("pause");
			break;
		case SHOW: //checked, no error
			system("cls");
			cout << "Enter the book's title that you  want to show: ";
			cin.ignore();
			getline(cin, titles);
			tmp = curentAdmin->searchByTitle(titles,l);
			if (tmp != NULL) {
				curentAdmin->show(tmp, l);
			}
			else {
				cout << "This book is not exist" << endl;
			}
			system("pause");
			break;
		case HIDE: //checked, no error
			system("cls");
			cout << "Enter the book's title that you  want to hide: ";
			cin.ignore();
			getline(cin, titles);
			tmp = curentAdmin->searchByTitle(titles, l);
			if (tmp != NULL) {
				curentAdmin->hide(tmp, l);
			}
			else {
				cout << "This book is not exist" << endl;
			}
			system("pause");
			break;
		case EDIT: //checked, no error
			system("cls");
			cout << "Enter the book's title that you  want to edit: ";
			cin.ignore();
			getline(cin, titles);
			tmp = curentAdmin->searchByTitle(titles, l);
			if (tmp != NULL) {
				admin->edit(tmp, l);
			}
			else {
				cout << "This book is not exist" << endl;
			}
			system("pause");
			break;
		case REMOVE: //checked, no error
			system("cls");
			cout << "Enter the book's title that you  want to remove: ";
			cin.ignore();
			getline(cin, titles);
			tmp = curentAdmin->searchByTitle(titles, l);
			if (tmp != NULL) {
				curentAdmin->remove(tmp, l);
			}
			else {
				cout << "This book is not exist" << endl;
			}
			system("pause");
			break;
		case CREATE_COLLECTION: // checked, no error
			system("cls");
			cout << "Enter the new collection's name: ";
			cin.ignore();
			getline(cin, nameC);
			temp = curentAdmin->createCollection(nameC, l);
			l->addCollection(temp);
			cout << "This collection created succesfully!" << endl;
			break;
		case DELETE_COLLECTION: // checked, no error
			system("cls");
			cout << "Enter the collection's name that you want to delete: ";
			cin.ignore();
			getline(cin, nameC);
			temp = curentAdmin->searchCollection(nameC, l);
			if (temp != NULL) {
				curentAdmin->deleteCollection(nameC, l);
			}
			else {
				cout << "Can't find this collection" << endl;
			}
			system("pause");
			break;
		case BORROW: // checked, no error
			system("cls");
			cout << "Enter the tile of book you want to borrow: ";
			cin.ignore();
			getline(cin, titles);
			tmp = currentMember->searchByTitle(titles, l);
			if (tmp != NULL) {
				currentMember->borrow(tmp, l);
			}
			else {
				cout << "\"" << titles << "\" doesn't exist in our library or it has been borrowed" << endl;
			}
			system("pause");
			break;
		case RETURN: // checked, no error
			system("cls");
			cout << "Enter the tile of book you want to return: ";
			cin.ignore();
			getline(cin, titles);
			tmp = currentMember->searchByTitle(titles, l);
			if (tmp != NULL) {
				currentMember->returnBook(tmp, l);
			}
			else {
				cout << "\"" << titles << "\" doesn't exist" << endl;
			}
			system("pause");
			break;
		case SUBCRIBE: // checked, no error
			system("cls");
			cout << "Enter the collection's name you want to subcribe: ";
			cin.ignore();
			getline(cin, nameC);
			temp = currentMember->searchCollection(nameC, l);
			if (temp != NULL) {
				currentMember->subscribe(temp);
			}
			else {
				cout << "Can't find this collection";
			}
			system("pause");
			break;
		case UNSUBCRIBE: // checked, no error
			system("cls");
			cout << "Enter the collection's name you want to unsubcribe: ";
			cin.ignore();
			getline(cin, nameC);
			temp = currentMember->searchCollection(nameC, l);
			if (temp != NULL) {
				currentMember->unsubscribe(temp);
			}
			else {
				cout << "Can't find this collection";
			}
			system("pause");
			break;
		case SEARCH_TITLE: // checked, no error
			system("cls");
			cout << "Enter the book's title to search: ";
			cin.ignore();
			getline(cin, titles);
			if (level == 1) {
				if (currentMember->searchByTitle(titles, l) != NULL && currentMember->searchByTitle(titles, l)->getVisibilityStatus() == true) {
					cout << "This book exists in our library" << endl;
					if (currentMember->searchByTitle(titles, l)->getAvailabilityStatus() == true) {
						cout << "You can borrow it" << endl;
					}
					else {
						cout << "Sorry, this book has been borrowed" << endl;
					}
				}
				else {
					cout << "Can't find this book" << endl;
				}
			}
			else if (level == 2) {
				if (curentAdmin->searchByTitle(titles, l) != NULL && curentAdmin->searchByTitle(titles, l)->getVisibilityStatus() == true) {
					cout << "This book exists in our library" << endl;
					if (curentAdmin->searchByTitle(titles, l)->getAvailabilityStatus() == true) {
						cout << "You can borrow it" << endl;
					}
					else {
						cout << "Sorry, this book has been borrowed" << endl;
					}
				}
				else {
					cout << "Can't find this book" << endl;
				}
			}
			else if(level == -1){
				if (guest1->searchByTitle(titles, l) != NULL && guest1->searchByTitle(titles, l)->getVisibilityStatus() == true) {
					cout << "This book exists in our library" << endl;
					if (guest1->searchByTitle(titles, l)->getAvailabilityStatus() == true) {
						cout << "You can borrow it" << endl;
					}
					else {
						cout << "Sorry, this book has been borrowed" << endl;
					}
				}
				else {
					cout << "Can't find this book" << endl;
				}
			}
			system("pause");
			break;
		case SEARCH_SERIAL: // checke, no error
			system("cls");
			cout << "Enter the book's serial number to search: ";
			cin.ignore();
			getline(cin, sNumber);
			if (level == 1) {
				if (currentMember->searchBySerial(sNumber, l) != NULL && currentMember->searchBySerial(sNumber, l)->getVisibilityStatus() == true) {
					cout << "This book exists in our library" << endl;
					if (currentMember->searchBySerial(sNumber, l)->getAvailabilityStatus() == true) {
						cout << "You can borrow it" << endl;
					}
					else {
						cout << "Sorry, this book has been borrowed" << endl;
					}
				}
				else {
					cout << "Can't find this book" << endl;
				}
			}
			else if (level == 2) {
				if (curentAdmin->searchBySerial(sNumber, l) != NULL && curentAdmin->searchBySerial(sNumber, l)->getVisibilityStatus() == true) {
					cout << "This book exists in our library" << endl;
					if (curentAdmin->searchBySerial(sNumber, l)->getAvailabilityStatus() == true) {
						cout << "You can borrow it" << endl;
					}
					else {
						cout << "Sorry, this book has been borrowed" << endl;
					}
				}
				else {
					cout << "Can't find this book" << endl;
				}
			}
			else if (level == -1) {
				if (guest1->searchBySerial(sNumber, l) != NULL && guest1->searchBySerial(sNumber, l)->getVisibilityStatus() == true) {
					cout << "This book exists in our library" << endl;
					if (guest1->searchBySerial(sNumber, l)->getAvailabilityStatus() == true) {
						cout << "You can borrow it" << endl;
					}
					else {
						cout << "Sorry, this book has been borrowed" << endl;
					}
				}
				else {
					cout << "Can't find this book" << endl;
				}
			}
			system("pause");
			break;
		case READ: // checked, no error
			system("cls");
			cout << "Enter the book's title you want to read: ";
			cin.ignore();
			getline(cin, titles);
			if (level == 1) {
				tmp = currentMember->searchByTitle(titles, l);
				if (tmp != NULL && tmp->getVisibilityStatus() == true ) {
					currentMember->read(tmp);
				}
				else if (tmp == NULL) {
					cout << "This book doesn't exist" << endl;
				}
				else if (tmp->getVisibilityStatus() != true) {
					cout << "Now, you can't read this book" << endl;
				}
			}
			else if (level == 2) {
				tmp = curentAdmin->searchByTitle(titles, l);
				if (tmp != NULL && tmp->getVisibilityStatus() == true) {
					curentAdmin->read(tmp);
				}
				else if (tmp == NULL) {
					cout << "This book doesn't exist" << endl;
				}
				else if (tmp->getVisibilityStatus() != true) {
					cout << "Now, you can't read this book" << endl;
				}
			}
			system("pause");
			break;
		case READG: // checked, no error
			system("cls");
			cin.ignore();
			cout << "Enter the book's title you want to read: ";
			getline(cin, titles);
			tmp = guest1->searchByTitle(titles, l);
			if (tmp != NULL && tmp->getVisibilityStatus() == true) {
				guest1->read(tmp);
			}
			else if (tmp == NULL) {
				cout << "This book doesn't exist" << endl;
			}
			else if (tmp->getVisibilityStatus() != true) {
				cout << "Now, you can't read this book" << endl;
			}
			system("pause");
			break;
		case LOGOUT:
			reUser->logOut();
			currentMenu = mainMenu;
			break;
		case CREATE_ADMIN: // checked, no error
			system("cls");
			l->addAd(curentAdmin->createAdmin());
			break;
		case EXIT:
			cout << "Bye Bye, See you again!" << endl;
			a = false;
			break;
		case SHOW_BOOKS:
			system("cls");
			for (int i = 0; i < l->getListBookSize(); i++) {
				cout << "Book #" << i + 1 << endl;
				cout << "Author: " << l->getBook(i)->getAuthor() << endl;
				cout << "Title: " << l->getBook(i)->getTitle() << endl;
				cout << "Serial Number: " << l->getBook(i)->getSerialNumber() << endl;
				cout << "Categorie: " << l->getBook(i)->getCategorie() << endl;
				cout << "Page count: " << l->getBook(i)->getPageCount() << endl;
				cout << "Page free: " << l->getBook(i)->getFreePage() << endl;
				cout << "Status: ";
				if (l->getBook(i)->getAvailabilityStatus() == true) {
					cout << "Available to borrow";
				}
				else {
					cout << "Not available to borrow";
				}
				if (l->getBook(i)->getVisibilityStatus() == true) {
					cout << " You can see it" << endl;
				}
				else {
					cout << " You can't see it" << endl;
				}
				cout << "______________________________________________________________" << endl;
			}
			system("pause");
			break;
		case SHOW_COLLECTIONS:
			system("cls");
			for (int i = 0; i < l->getListCollectionSize(); i++) {
				temp = l->getCollection(i);
				cout << "#" << i + 1 << ": " << temp->getName() << endl;
			}
			cout << "_______________________________________________________" << endl;
			cout << "Do you want to see list book in Collection?(Y/N): " << endl;
			cin >> choose;
			if (choose == 'y' || choose == 'Y') {
				do {
					cout << "Enter the name of the collection: ";
					cin.ignore();
					getline(cin, nameC);
					if (level == 2) {
						temp = curentAdmin->searchCollection(nameC, l);
						if (temp != NULL) {
							for (int i = 0; i < c->getBookListSize(); i++) {
								cout << "Book #" << i + 1 << endl;
								cout << "Author: " << c->getBook(i)->getAuthor() << endl;
								cout << "Title: " << c->getBook(i)->getTitle() << endl;
								cout << "Serial Number: " << c->getBook(i)->getSerialNumber() << endl;
								cout << "Categorie: " << c->getBook(i)->getCategorie() << endl;
								cout << "Page count: " << c->getBook(i)->getPageCount() << endl;
								cout << "Page free: " << c->getBook(i)->getFreePage() << endl;
								cout << "Status: ";
								if (c->getBook(i)->getAvailabilityStatus() == true) {
									cout << "Available to borrow";
								}
								else {
									cout << "Not available to borrow";
								}
								if (c->getBook(i)->getVisibilityStatus() == true) {
									cout << " You can see it" << endl;
								}
								else {
									cout << " You can't see it" << endl;
								}
								cout << "______________________________________________________________" << endl;
							}
						}
					}
					else if (level == 1) {
						temp = currentMember->searchCollection(nameC, l);
						if (temp != NULL) {
							if (currentMember->isSubcribe(temp, l)) {
								for (int i = 0; i < c->getBookListSize(); i++) {
									cout << "Book #" << i + 1 << endl;
									cout << "Author: " << c->getBook(i)->getAuthor() << endl;
									cout << "Title: " << c->getBook(i)->getTitle() << endl;
									cout << "Serial Number: " << c->getBook(i)->getSerialNumber() << endl;
									cout << "Categorie: " << c->getBook(i)->getCategorie() << endl;
									cout << "Page count: " << c->getBook(i)->getPageCount() << endl;
									cout << "Page free: " << c->getBook(i)->getFreePage() << endl;
									cout << "Status: ";
									if (c->getBook(i)->getAvailabilityStatus() == true) {
										cout << "Available to borrow";
									}
									else {
										cout << "Not available to borrow";
									}
									if (c->getBook(i)->getVisibilityStatus() == true) {
										cout << " You can see it" << endl;
									}
									else {
										cout << " You can't see it" << endl;
									}
									cout << "______________________________________________________________" << endl;
								}
							}
							else {
								cout << "Only subcriber can see the list of book in this collection" << endl;
							}
						}
						else {
							cout << "Can't find this collection!\n";
						}
					}
					cout << "Do you want to continue?(Y/N): ";
					cin >> choose1;
				} while (choose == 'Y' || choose1 == 'y');
			}
			system("pause");
			break;
		default:
			cout << "Invalid action!" << endl;
			break;
		}
	}

	return 0;
}