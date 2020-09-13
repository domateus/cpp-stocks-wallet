#pragma once
#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "ValidateUser.hpp"
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

        while (getline(userFileLineStream, values, ',')) {
            column.at(columnIndex).second.push_back(values);
            if(userFileLineStream.peek() == ',') userFileLineStream.ignore();

            columnIndex++;
        }
    }

    allUsers.close();

    bool foundUser = false;

    for (auto it = column.at(0).second.begin(); it != column.at(0).second.end(); it++) {
        string login = it->data();
        string u = loggingUser->getLogin();
        if (loggingUser->getLogin() == login) {
            int size = column.at(1).second.size();
            for (int index = 0; index < size; index++) {
                if (loggingUser->getPassword() == column[1].second[index]) {
                    cout << "Usuario validado com sucesso" << endl;
                    foundUser = true;
                } 
            }

        }

        if (!foundUser) {
            cout << "to aqui" << endl;
            throw invalid_argument("Não foi possível validar seu usuário, tente novamente");
        }
    }
}

void ValidateUser :: ValidateNewUser(string filename, User *loggingUser) {
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

    int dataIndex;

    for (auto it = column.at(0).second.begin(); it != column.at(0).second.end(); it++) {
        string login = it->data();
        if (loggingUser->getLogin() == login) {
            throw invalid_argument("Login inválido, por favor, escolha outro");
        }
    }
    column.at(0).second.push_back(loggingUser->getLogin());
    column.at(1).second.push_back(loggingUser->getPassword());

    ofstream updatedAllUsers(filename);

    for (int i = 0; i < column.size(); i++) {
        updatedAllUsers << column.at(i).first;
        if (i != column.size() - 1) updatedAllUsers << ",";
    }

    updatedAllUsers << "\n";

    for (int i = 0; i < column.at(0).second.size(); i++) {
        for (int j = 0; j < column.size(); j++) {
            updatedAllUsers << column.at(j).second.at(i);
            if (j != column.size() - 1) updatedAllUsers << ",";
        }
        updatedAllUsers << "\n";
    }

    updatedAllUsers.close();

    cout << "Usuário criado com sucesso" << endl;
}