#pragma once
#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "ValidateUser.hpp"
#include "CSVfile.hpp"
#include "../models/user/User.hpp"

using namespace std;

void ValidateUser :: ValidateExistingUser(string filename, User *loggingUser) {
    CSVfile *fileLogs = new CSVfile(filename);

    vector<pair<string, vector<string>>> file = fileLogs->read();

    bool foundUser = false;

    for (auto it = file.at(0).second.begin(); it != file.at(0).second.end(); it++) {
        string login = it->data();
        if (loggingUser->getLogin() == login) {
            int size = file.at(1).second.size();
            for (int index = 0; index < size; index++) {
                if (loggingUser->getPassword() == file[1].second[index]) {
                    cout << "Usuario validado com sucesso" << endl;
                    foundUser = true;
                    index = size;
                } 
            }

        }

    }
    if (!foundUser) {
        throw invalid_argument("Não foi possível validar seu usuário, tente novamente");
    }
}

void ValidateUser :: ValidateNewUser(string filename, User *loggingUser) {
    CSVfile *fileLogs = new CSVfile(filename);

    vector<pair<string, vector<string>>> file = fileLogs->read();

    int dataIndex;

    for (auto it = file.at(0).second.begin(); it != file.at(0).second.end(); it++) {
        string login = it->data();
        if (loggingUser->getLogin() == login) {
            throw invalid_argument("Login inválido, por favor, escolha outro");
        }
    }
    fileLogs->write(loggingUser);
}