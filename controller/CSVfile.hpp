#pragma once
#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "../models/user/User.hpp"
#include "../models/stock/Stock.hpp"

using namespace std;

class CSVfile {
    private:
        string filename;
        vector<pair<string, vector<string>>> fileData;
        string auxLine, auxColname, auxValues;

    public:
        CSVfile(string file);
        vector<pair<string, vector<string>>> read();
        void write(User *newUser);
        void writeStocks(vector<Stock> stockData);
        void updateStocks(vector<Stock> stockData);
        vector <Stock> readExistingStocks();
};