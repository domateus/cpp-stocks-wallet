#pragma once
#include "Wallet.hpp"
#include <iostream>

using namespace std;

Wallet :: Wallet() {
    string test = this->getString();
    cout << test << " ou ola mundo" << endl;
}

string Wallet :: getString() {
    return this->hello;
}
