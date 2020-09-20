#include "definitions.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

int main() {
    int amount;
    char session;
    string login, password;
    User *logUser = new User();

    cout << "Para criar uma conta, digite a\n\nPara fazer login, digite b" <<endl;
    cin >> session;

    ValidateUser *UserSession = new ValidateUser();

    if (session == 'a') {
        cout << "Escolha seu login" << endl;
        cin.ignore();
        getline(cin, login);
        cout << "Escolha sua senha" << endl;
        getline(cin, password);

        logUser->setLogin(login);
        logUser->setPassword(password);

        UserSession->ValidateNewUser("user.csv", logUser);

        cout << "\033[1;4;32m\nBem vindo(a) ao gestor de carteira de ações\033[0m" << endl;
        cout << "\033[33mDigite quantas ações há na sua carteira\033[0m" << endl;
        cin >> amount;
        vector <Stock> vectorOfStocks(amount);
        newUserStocks(vectorOfStocks);
        CSVfile *userStocks = new CSVfile(logUser->getLogin());

        finalMenu(vectorOfStocks, userStocks);

    } else if (session == 'b') {
        cout << "Escreva seu login" << endl;
        cin.ignore();
        getline(cin, login);
        cout << "Escreva sua senha" << endl;
        getline(cin, password);

        logUser->setLogin(login);
        logUser->setPassword(password);

        UserSession->ValidateExistingUser("user.csv", logUser);
        CSVfile *userStocks = new CSVfile(logUser->getLogin());
        vector <Stock> vectorOfStocks = userStocks->readExistingStocks();
        finalMenu(vectorOfStocks, userStocks);

    } else {
        throw invalid_argument("Opção inválida");
        vector <Stock> vectorOfStocks;
    }
        
    return 0;
}