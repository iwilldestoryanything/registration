#include "Header.h"

User Atorziation(vector<User> users, User user) {
    for (int i = 0; i < users.size(); ++i) {
        if (users[i] == user)
            return users[i];
    }
}
int Find(vector<User> users, string name) {
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].getLogin() == name)
        {
            return i;
        }
    }
    return -1;
}

vector<User> load(string path){
        vector<User>  users;
        ifstream fin;
        string login;
        string  password;
        int index;

        fin.open(path);
        if (fin.is_open())
        {
            while (!fin.eof())
            {
                fin >> login >> password >> index;
                users.push_back(User(login, dShiverPassword(password, index), index));
            }
        }
        fin.close();
        return  users;
    }

void save(vector<User> us, string path) {
    ofstream fout;
    fout.open(path);
    if (fout.is_open()) {
        for (int i = 1; i < us.size(); ++i) {
            fout << us[i].getLogin() << ' ' << us[i].getShiverPasswors() << ' ' << us[i].getIndex() << ' ';
       }
    }
}