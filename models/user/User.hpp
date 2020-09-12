#pragma once
#include <iostream>

using namespace std;

class User {
    private:
        string login = "";
        string password = "";
        int id;
    public:
        User();
        
        string getLogin();
        string getPasswor();
        int getId();

        void setLogin();
        void setPasswor();
        void setId();
};
