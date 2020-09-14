#include "definitions.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

int main() {
    int amount, amountBought, soldAmmount, index;
    char option = 'z';
    char session;
    string ticker, reasonToBuy, login, password;
    double boughtPrice, soldPrice;
    bool hasSold, foundIndex = false;
    Stock *addedStock = new Stock();
    vector <Stock>::iterator delIt;
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

    } else if (session == 'b') {
        cout << "Escreva seu login" << endl;
        cin.ignore();
        getline(cin, login);
        cout << "Escreva sua senha" << endl;
        getline(cin, password);

        logUser->setLogin(login);
        logUser->setPassword(password);

        UserSession->ValidateExistingUser("user.csv", logUser);

    } else {
        throw invalid_argument("Opção inválida");
    }


    CSVfile *userStocks = new CSVfile(logUser->getLogin());

    do {
        cout << "\033[1;4;32m\nBem vindo(a) ao gestor de carteira de ações\033[0m" << endl;
        cout << "\033[33mDigite quantas ações há na sua carteira\033[0m" << endl;
        cin >> amount;
        vector <Stock> vectorOfStocks(amount);
        cout << "\033[33mAgora, vamos adicionar os dados para cada uma das ações\033[0m" << endl;
        vector <Stock>::iterator it;
        for (it = vectorOfStocks.begin(); it != vectorOfStocks.end(); it++) {
            cout << "\033[33mQual o ticker da ação?\033[0m" << endl;
            cin >> ticker;
            it->setTicker(ticker);

            cout << "\033[33mNos conte, por que você comprou essa ação? (iremos lembrar-te no futuro)\033[0m" << endl;
            cin.ignore();
            getline(cin, reasonToBuy);
            it->setReasonToBuy(reasonToBuy);

            cout << "\033[33mE qual foi o preço que você pagou por cada uma ?\033[0m" << endl;
            cin >> boughtPrice;
            it->setBoughtPrice(boughtPrice);

            cout << "\033[33mPara nós fazermos as contas, quantas ações você comprou no total ?\033[0m" << endl;
            cin >> amountBought;
            it->setAmountBought(amountBought);

            cout << "\033[33mPor acaso, você já vendeu algumas dessas ações?\033[0m" << endl;
            cout << "\033[33mSe sim, por favor digite 1\033[0m" << endl;
            cout << "\033[33mSe não, digite 0\033[0m" << endl;
            cin >> hasSold;

            if(hasSold) {
                cout << "\033[33mBem, já que você vendeu, nós precisamos fazer mais duas perguntas\033[0m" << endl;
                cout << "\033[33mA primeira, é qual foi o preço da venda ?\033[0m" << endl;
                cin >> soldPrice;
                it->setSoldPrice(soldPrice);

                cout << "\033[33mE a segunda é quantas ações você vendeu ?\033[0m" << endl;
                cin >> soldAmmount;
                it->setSoldAmount(soldAmmount);
            } else {
                cout << "\033[33mMuito bem, podemos continuar então\033[0m" << endl;
            }
        }

        option = 'e';
        while(option != 'z') {
        cout << "\033[1;4;34m\n\nCerto, nós já criamos a sua carteira, mas você ainda pode fazer algumas mudanças antes de salvarmos ela\033[0m" << endl;
        switch (option)
        {
        case 'e':
            cout << "\033[33mPara adicionar mais uma ação, digite \033[1;37ma\033[0;33m" << endl;
            cout << "Para remover uma ação, digite \033[1;37mb\033[0;33m" << endl;
            cout << "Para editar alguma ação, digite \033[1;37mc\033[0;33m" << endl;
            cout << "Para salvar sua carteira, como ela está, digite \033[1;37md\033[0m" << endl;
            cin >> option;
            break;
        
        case 'a':
            cout << "\033[33mEntão escreva: " << endl;
            cout << "ticker > ";
            cin.ignore();
            cin >> ticker;
            cout << "motivo da compra > ";
            cin.ignore();
            getline(cin, reasonToBuy);
            cout << "preço da ação > ";
            cin >> boughtPrice;
            cout << "quantidade de ações > ";
            cin >> amountBought;
            cout << "Caso não tenha vendido ainda, digite 0 para as próximas perguntas\n" << endl;
            cout << "preço de venda > ";
            cin >> soldPrice;
            cout << "quantidade de ações vendidas > ";
            cin >> soldAmmount;
            addedStock->setTicker(ticker);
            addedStock->setReasonToBuy(reasonToBuy);
            addedStock->setBoughtPrice(boughtPrice);
            addedStock->setSoldAmount(soldAmmount);
            addedStock->setSoldPrice(soldPrice);
            addedStock->setAmountBought(amountBought);
            vectorOfStocks.push_back(*addedStock);
            option = 'e';
            break;

        case 'b':
            foundIndex = false;
            cout << "Digite o ticker da ação que você quer remover, da mesma forma como foi adicionada" << endl;
            cin.ignore();
            cin >> ticker;
            for(delIt = vectorOfStocks.begin(); delIt != vectorOfStocks.end(); delIt++) {
                if (delIt->getTicker() == ticker) {
                    cout << "A ação do ticker digitado foi removida" << endl;
                    foundIndex = true;
                    index = distance(vectorOfStocks.begin(), delIt);
                } 
            }
            
            if(foundIndex){
                vectorOfStocks.erase(vectorOfStocks.begin() + index);
            }
            
            if(!foundIndex) {
                cout << "A ação não foi encontrada" << endl;
            }

            option = 'e';
            break;

        case 'c':
            foundIndex = false;
            cout << "Digite o ticker da ação que você quer editar, da mesma forma como foi adicionada" << endl;
            cin.ignore();
            cin >> ticker;
            for(delIt = vectorOfStocks.begin(); delIt != vectorOfStocks.end(); delIt++) {
                if (delIt->getTicker() == ticker) {
                    cout << "A ação do ticker digitado será editada" << endl;
                    foundIndex = true;
                    index = distance(vectorOfStocks.begin(), delIt);
                    cout << "\033[33mEntão escreva: " << endl;
                    cout << "ticker > ";
                    cin.ignore();
                    cin >> ticker;
                    cout << "motivo da compra > ";
                    cin.ignore();
                    getline(cin, reasonToBuy);
                    cout << "preço da ação > ";
                    cin >> boughtPrice;
                    cout << "quantidade de ações > ";
                    cin >> amountBought;
                    cout << "Caso não tenha vendido ainda, digite 0 para as próximas perguntas\n" << endl;
                    cout << "preço de venda > ";
                    cin >> soldPrice;
                    cout << "quantidade de ações vendidas > ";
                    cin >> soldAmmount;
                    delIt->setTicker(ticker);
                    delIt->setReasonToBuy(reasonToBuy);
                    delIt->setBoughtPrice(boughtPrice);
                    delIt->setSoldAmount(soldAmmount);
                    delIt->setSoldPrice(soldPrice);
                    delIt->setAmountBought(amountBought);
                } 
            }

            if(!foundIndex) {
                cout << "A ação não foi encontrada" << endl;
                option = 'e';
            }
            option = 'e';
            break;

        case 'd':
            userStocks->writeStocks(vectorOfStocks);
            option = 'e';
            break;
        
        default:
            cout << "Ocorreu algum erro, tente novamente\n\n" << endl;
            option = 'e';
            break;
        }
        
        }
    } while(1);
    Stock *stock = new Stock();
    Wallet *wallet = new Wallet();
    User *user = new User();
    cout << stock->getTicker() << endl;
    return 0;
}