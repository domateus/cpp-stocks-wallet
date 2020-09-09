#include "definitions.hpp"
#include <iostream>

using namespace std;

int main() {
    Stock *stock = new Stock();
    Wallet *wallet = new Wallet();
    User *user = new User();
    cout << stock->getString() << endl;
    return 0;
}