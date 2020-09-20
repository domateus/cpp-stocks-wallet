#include <iostream>
#include <vector>
#include "../models/stock/Stock.hpp"
#include "../controller/CSVfile.hpp"

using namespace std;

void newUserStocks(vector <Stock>& vectorOfStocks);
void finalMenu(vector <Stock>& vectorOfStocks, CSVfile *userStocks);