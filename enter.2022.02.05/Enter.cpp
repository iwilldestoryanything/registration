//#include "Enter.h"
#include <string>
using namespace std;
class User {
private:
	string login;
	string password;
	int index;
public:
	User(string log_w, string pas_w, int index_w);
	
	void in_f(string tx);
	bool open(string tx);	

	string getShiverPasswors() {
		return password;
	}
	string getLogin() {
		return login;
	}
	int getIndex() {
		return index;
	}
	bool operator ==(User val) {
		return login == val.login && password == val.password;
	}
	
};