#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "../models/user/User.hpp"

using namespace std;

class ValidateUser {
    private:
        string filename = "../user.csv";
        User *loggingUser;
        vector <User> allUsers;

    public: 
        ValidateUser(string filename, User *loggingUser);
        void ValidateNewUser(string filename, User *loggingUser);
};