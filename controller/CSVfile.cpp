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

void CSVfile :: write(User *newUser) {
    // this->fileData.at(0).second.push_back(newUser->getLogin());
    // this->fileData.at(1).second.push_back(newUser->getPassword());

    ofstream test(this->filename, ios_base::app);
    test << newUser->getLogin() << "," << newUser->getPassword();

    

    // updatedAllUsers.close();

    cout << "Usuário criado com sucesso" << endl;
}

void CSVfile :: writeStocks(vector<Stock> stockData) {
    string name = "./data/" + this->filename + ".csv";
    cout << name;
    ofstream stocksFile(name);
    for (int i = 0; i < stockData.size(); i++) {
        stocksFile << "Ação " << i;
        if (i != stockData.size() - 1) stocksFile << ",";
    }

    stocksFile << "\n";

        for (int j = 0; j < stockData.size(); j++) {
            stocksFile << stockData[j].getTicker();
            if (j != stockData.size() - 1) stocksFile << ",";
            else stocksFile << "\n";
        }
        for (int j = 0; j < stockData.size(); j++) {
            stocksFile << stockData[j].getReasonToBuy();
            if (j != stockData.size() - 1) stocksFile << ",";
            else stocksFile << "\n";
        }
        for (int j = 0; j < stockData.size(); j++) {
            stocksFile << stockData[j].getBoughtPrice();
            if (j != stockData.size() - 1) stocksFile << ",";
            else stocksFile << "\n";
        }
        for (int j = 0; j < stockData.size(); j++) {
            stocksFile << stockData[j].getSoldPrice();
            if (j != stockData.size() - 1) stocksFile << ",";
            else stocksFile << "\n";
        }
        for (int j = 0; j < stockData.size(); j++) {
            stocksFile << stockData[j].getAmountBought();
            if (j != stockData.size() - 1) stocksFile << ",";
            else stocksFile << "\n";
        }
        for (int j = 0; j < stockData.size(); j++) {
            stocksFile << stockData[j].getSoldAmount();
            if (j != stockData.size() - 1) stocksFile << ",";
            else stocksFile << "\n";
        }

    stocksFile.close();
}