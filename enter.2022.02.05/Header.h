#pragma once

#include <iostream>
#include <ostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <vector>
#include "Enter.cpp"

#define CENZ '*'
#define PATH "users.txt"

using namespace std;
User Atorziation(vector<User> users, User user);
int Find(vector<User> users, string name);
vector<User> load(string path);
void save(vector<User> us, string path);

bool reges(string log_w, string pas_w1, string pas_w2);
User Log(vector<User>& us);
User Regist(vector<User>& us);
vector<User> Menu(vector<User> us);

string dShiverPassword(string passw, int idx);