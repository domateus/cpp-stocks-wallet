#pragma once
#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "CSVfile.hpp"
#include "../models/user/User.hpp"

using namespace std;

CSVfile :: CSVfile(string file) {
    this->filename = file;
};

vector<pair<string, vector<string>>> CSVfile :: read() {
    ifstream allUsers(this->filename);

    if (!allUsers.is_open()) throw runtime_error("Registro de usuários não foi encontrado");

    if (allUsers.good()) {
        // read header line from csv file
        getline(allUsers, this->auxLine);

        // creates a stringstream from line
        stringstream userFileLineStream(this->auxLine);

        while (getline(userFileLineStream, this->auxColname, ',')) {
            this->fileData.push_back({this->auxColname, vector<string> {}});
        }
    }

    while(getline(allUsers, this->auxLine)) {
        stringstream userFileLineStream(this->auxLine); 

        int columnIndex = 0;

        while (getline(userFileLineStream, this->auxValues, ',')) {
            this->fileData.at(columnIndex).second.push_back(this->auxValues);
            // cout << "\ncoluna: " << columnIndex << "\nvalues: " << values;
            if(userFileLineStream.peek() == ',') userFileLineStream.ignore();

            columnIndex++;
        }
    }

    allUsers.close();

    return this->fileData;
}

void CSVfile :: write(string file, User *newUser) {

}