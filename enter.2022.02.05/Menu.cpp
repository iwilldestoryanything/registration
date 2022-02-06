#include "Header.h"

string input_password();

enum ConsoleColor
{
	Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, (WORD)((background << 4) | text));
}

void showcursor(bool flag)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(hOut, &info);
	info.bVisible = flag;
	SetConsoleCursorInfo(hOut, &info);
}

void setCursorPosition(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}



bool reges(string log_w, string pas_w1, string pas_w2) {
	if (log_w.length() <= 2)
		return false;
	else if (pas_w1.length() <= 5)
		return false;
	else if (pas_w1 != pas_w2)
		return false;
	else
		return true;
}

User Log(vector<User>& us) {
	string l, p;
	system("cls");
	cout << "User login: ";
	cin >> l;
	cout << "\nUser password: ";
	p = input_password();
	int ind = Find(us, l);
	if (ind >= 0)
	{
		if (dShiverPassword(us[ind].getShiverPasswors(), us[ind].getIndex()) == p)
		{
			cout << "Logged seccesfull " << us[ind].getLogin() << "!";
			_getch();
			return us[ind];
		}
	}
		cout << "Error log/pass";
		_getch();
		return User("","",0);
	/*if (old_user1.open(PATH))
		cout << "ln open ";
	else
		cout << "error ";*/
}

User Regist(vector<User>& us) {
	int ind;
	ind = false;
	system("cls");
	while (!ind) {
		string l, p2, p1 = "", tmp;

		cout << "User login: ";
		cin >> l;
		cout << "\nUser password: ";
		p1 = input_password();


		cout << "\nRepeat password: ";
		p2 = input_password();

		if (reges(l, p1, p2)) {
			if (Find(us, l) == -1) {
				ind = (rand() % (24 - 2)) + 2;
				us.push_back(User(l, p1, ind));
				cout << "registratin successful";
				_getch();
				return User(l, p1, ind);
			}
			else {
				cout << "Already registred\n";
			}
		}
		else
			cout << "Err 404\n";
		_getch();
		return User("","",0);

	}

}
vector<User> Menu(vector<User> us) {
	User user("", "", 0);
	char key;
	bool reg = true;
	bool exit = true;
	short pos = 0;
	while (exit) {
		reg = true;
		SetColor(0, LightMagenta);
		system("cls");

		ShowCursor(false);

		string menu[3]{ "Login","Registratin", "Exit" };
		for (int i = 0; i < 3; ++i) {
			setCursorPosition(0, 2 + i);
			cout << "\t" << menu[i];
		}
		while (reg) {
			SetColor(White, Magenta);
			setCursorPosition(2, 2 + pos);
			cout << '>';
			setCursorPosition(0, 2 + pos);
			cout << "\t" << menu[pos];
			cin.clear();
			key = _getch();
			SetColor(0, LightMagenta);
			setCursorPosition(2, 2 + pos);
			cout << ' ';
			setCursorPosition(0, 2 + pos);
			cout << "\t" << menu[pos];
			switch (key) {
			case 'W': case 'w':
				pos--;
				break;
			case 'S': case 's':
				pos++;
				break;
			case VK_RETURN:
				reg = false;
				break;
			}
			if (pos > 2)
				pos = 0;
			else if (pos < 0)
				pos = 2;
		}
		switch (pos) {
		case 0:
			user = Log(us);
			if (user.getIndex() == 0) {
				setCursorPosition(0, 0);
				cout << "You logged by " << user.getLogin();
			}
			break;
		case 1:
			user = Regist(us);
			if (user.getIndex() == 0) {
				setCursorPosition(0, 0);
				cout << "You logged by " << user.getLogin();
			}
			break;
		case 2:
			exit = false;
			return us;
			break;
		}
	}
}
