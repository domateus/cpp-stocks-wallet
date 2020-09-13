#pragma once
#include "User.hpp"
#include <iostream>

using namespace std;

User :: User() {
    this->id = 0;
    this->password = "";
    this->login = "";
}

string User :: getLogin() {
    return this->login;
}

string User :: getPassword() {
    return this->password;
}

void User :: setLogin(string value) {
    this->login = value;
}

void User :: setPassword(string value) {
    this->password = value;
}

void User :: setId(int value) {
    this->id = value;
}
