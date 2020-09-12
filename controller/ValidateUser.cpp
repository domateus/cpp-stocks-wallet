#pragma once
#include "ValidateUser.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "../models/user/User.hpp"

using namespace std;

ValidateUser :: ValidateUser(string filename, User *loggingUser) {
    ifstream allUsers(filename);

    if (!allUsers.is_open()) throw runtime_error("Registro de usuários não foi encontrado");

    vector<pair<string, vector <string>>> column;

    string line, columnName, values;
    
    if (allUsers.good()) {
        // read header line from csv file
        getline(allUsers, line);

        // creates a stringstream from line
        stringstream userFileLineStream(line);

        while (getline(userFileLineStream, columnName, ',')) {
            column.push_back({columnName, vector<string> {}});
        }
    }

    while(getline(allUsers, line)) {
        stringstream userFileLineStream(line); 

        int columnIndex = 0;

        while (userFileLineStream >> values) {
            column.at(columnIndex).second.push_back(values);

            if(userFileLineStream.peek() == ',') userFileLineStream.ignore();

            columnIndex++;
        }
    }

    allUsers.close();

    for (auto it = column.at(0).second.begin(); it != column.at(0).second.end(); it++) {
        string teste = it->data();
        if (loggingUser->getLogin() == teste) {
            
        }
    }
}