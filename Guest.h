#include "user.h"
#include "Member.h"
#include <string>
using namespace std;

class Guest : public User {
private:
	int id;
public:
	Guest();
	Member* registering();
	void read(Book* b);
	int getId();
	~Guest();
};