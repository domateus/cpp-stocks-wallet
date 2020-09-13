#pragma once
#include <iostream>

using namespace std;

class User {
    private:
        string login;
        string password;
        int id;
    public:
        User();
        
        string getLogin();
        string getPassword();
        int getId();

        void setLogin(string value);
        void setPassword(string value);
        void setId(int value);
};
