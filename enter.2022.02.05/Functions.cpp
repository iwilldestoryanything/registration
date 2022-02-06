#include "Header.h"
string dShiverPassword(string passw, int idx) {
	for (int i = 0; i < passw.length(); ++i) {
		passw[i] -= idx;
	}
	return passw;
}

User::User(string log_w, string pas_w, int index_w) {
	password = dShiverPassword(pas_w, index_w * -1);
	login = log_w;
	index = index_w;
}


	void User::in_f(string tx) {
		ofstream fin(tx, ios_base::app);
		fin << login << ' ' << password << endl;
		fin.close();


	}

	bool User::open(string tx) {
		ifstream fout(tx);
		string s; // считываем строку
		string ns = login + " " + password;
		bool otv = false;
		while (getline(fout, s)) {
			cout << s << "    " << ns << endl;
			if (s == ns) {
				return true;
			}
		}
		return false;
	}


	
string input_password() {
	char ch;
	string pa;
	while (true) {

		cin.clear();
		ch = _getch();

		if (ch == VK_RETURN)
			break;
		else if (ch == VK_BACK && pa.length() > 0) {
			cout << (char)8 << ' ' << (char)8;
			pa = pa.substr(0, pa.length() - 1);
		}
		else if (ch != VK_BACK) {
			cout << CENZ;
			pa += (char)ch;
		}
	}
	cout << endl;
	return pa;
}


