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
            if(userFileLineStream.peek() == ',') userFileLineStream.ignore();

            columnIndex++;
        }
    }

    allUsers.close();

    return this->fileData;
}

void CSVfile :: write(User *newUser) {
    ofstream test(this->filename, ios_base::app);
    test << "\n" << newUser->getLogin() << "," << newUser->getPassword();

    cout << "Usuário criado com sucesso" << endl;
}

void CSVfile :: writeStocks(vector<Stock> stockData) {
    string name = "./data/" + this->filename + ".csv";    
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

vector <Stock> CSVfile :: readExistingStocks() {
    string name = "./data/" + this->filename + ".csv";
    ifstream userStockData(name);

    if (!userStockData.is_open()) throw runtime_error("Registro de usuários não foi encontrado");

    if (userStockData.good()) {
        // read header line from csv file
        getline(userStockData, this->auxLine);

        // creates a stringstream from line
        stringstream userFileLineStream(this->auxLine);

        while (getline(userFileLineStream, this->auxColname, ',')) {
            this->fileData.push_back({this->auxColname, vector<string> {}});
        }
    }

    while(getline(userStockData, this->auxLine)) {
        stringstream userFileLineStream(this->auxLine); 

        int columnIndex = 0;

        while (getline(userFileLineStream, this->auxValues, ',')) {
            this->fileData.at(columnIndex).second.push_back(this->auxValues);
            // cout << "\ncoluna: " << columnIndex << "\nvalues: " << values;
            if(userFileLineStream.peek() == ',') userFileLineStream.ignore();

            columnIndex++;
        }
    }

    userStockData.close();

    vector <Stock> formatedData (this->fileData.size());

    for (int i = 0; i < this->fileData.size(); i++){
        auto data = this->fileData[i].second;
        formatedData[i].setTicker(data[0]);
        formatedData[i].setReasonToBuy(data[1]);
        formatedData[i].setBoughtPrice(stod(data[2]));
        formatedData[i].setSoldPrice(stod(data[3]));
        formatedData[i].setAmountBought(stoi(data[4]));
        formatedData[i].setSoldAmount(stoi(data[5]));       
    }
    return formatedData;
}

void CSVfile :: updateStocks(vector<Stock> stockData) {
    string name = "./data/" + this->filename + ".csv";    
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