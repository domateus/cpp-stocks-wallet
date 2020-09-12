#pragma once
#include "User.hpp"
#include <iostream>

using namespace std;

User :: User() {
    string test = this->getLogin();
    cout << test << " ou ola mundo" << endl;
}

string User :: getLogin() {
    return this->login;
}
