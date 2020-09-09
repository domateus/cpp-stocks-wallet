#include "Stock.hpp"
#include <iostream>

using namespace std;

Stock :: Stock() {
    string test = this->getString();
    cout << test << " ou ola mundo" << endl;
}

string Stock :: getString() {
    return this->hello;
}
