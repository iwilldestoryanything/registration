#include "Header.h"

string input_password();

int main() {
	vector<User> users;
	users = load(PATH);
	
	users = Menu(users);

	save(users, PATH);
	return EXIT_SUCCESS;
}
