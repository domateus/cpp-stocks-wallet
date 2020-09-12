#pragma once
#include "User.hpp"
#include <iostream>

using namespace std;

User :: User() {
    string test = this->getString();
    cout << test << " ou ola mundo" << endl;
}

string User :: getString() {
    return this->hello;
}
