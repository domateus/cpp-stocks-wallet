#include "definitions.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int amount;
    do {
        cout << "Bem vindo(a) ao gestor de carteira de ações" << endl;
        cout << "Digite quantas ações há na sua carteira" << endl;
        cin >> amount;
        vector <Stock> vectorOfStocks(amount);
        cout << "Agora, vamos adicionar os dados para cada uma das ações" << endl;
        vector <Stock>::iterator it;
        for (it = vectorOfStocks.begin(); it != vectorOfStocks.end(); it++) {
            cout << "Qual o ticker da ação?" << endl;
            string ticker;
            cin >> ticker;
            it->setTicker(ticker);

            cout << "Nos conte, por que você comprou essa ação? (iremos lembrar-te no futuro)" << endl;
            string reasonToBuy;
            cin.ignore();
            getline(cin, reasonToBuy);
            it->setReasonToBuy(reasonToBuy);

            cout << "E qual foi o preço que você pagou por cada uma ?" << endl;
            double boughtPrice;
            cin >> boughtPrice;
            it->setBoughtPrice(boughtPrice);

            cout << "Para nós fazermos as contas, quantas ações você comprou no total ?" << endl;
            int amountBought;
            cin >> amountBought;
            it->setAmountBought(amountBought);

            cout << "Por acaso, você já vendeu algumas dessas ações?" << endl;
            cout << "Se sim, por favor digite 1" << endl;
            cout << "Se não, digite 0" << endl;
            bool hasSold;
            cin >> hasSold;

            if(hasSold) {
                cout << "Bem, já que você vendeu, nós precisamos fazer mais duas perguntas" << endl;
                cout << "A primeira, é qual foi o preço da venda ?" << endl;
                double soldPrice;
                cin >> soldPrice;
                it->setSoldPrice(soldPrice);

                cout << "E a segunda é quantas ações você vendeu ?" << endl;
                int soldAmmount;
                cin >> soldAmmount;
                it->setSoldAmount(soldAmmount);
            } else {
                cout << "Muito bem, podemos continuar então" << endl;
            }
        }


    } while(1);
    Stock *stock = new Stock();
    Wallet *wallet = new Wallet();
    User *user = new User();
    cout << stock->getTicker() << endl;
    return 0;
}