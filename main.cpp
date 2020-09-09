#include "definitions.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int amount;
    do {
        cout << "\033[1;4;32m\nBem vindo(a) ao gestor de carteira de ações\033[0m" << endl;
        cout << "\033[33mDigite quantas ações há na sua carteira\033[0m" << endl;
        cin >> amount;
        vector <Stock> vectorOfStocks(amount);
        cout << "\033[33mAgora, vamos adicionar os dados para cada uma das ações\033[0m" << endl;
        vector <Stock>::iterator it;
        for (it = vectorOfStocks.begin(); it != vectorOfStocks.end(); it++) {
            cout << "\033[33mQual o ticker da ação?\033[0m" << endl;
            string ticker;
            cin >> ticker;
            it->setTicker(ticker);

            cout << "\033[33mNos conte, por que você comprou essa ação? (iremos lembrar-te no futuro)\033[0m" << endl;
            string reasonToBuy;
            cin.ignore();
            getline(cin, reasonToBuy);
            it->setReasonToBuy(reasonToBuy);

            cout << "\033[33mE qual foi o preço que você pagou por cada uma ?\033[0m" << endl;
            double boughtPrice;
            cin >> boughtPrice;
            it->setBoughtPrice(boughtPrice);

            cout << "\033[33mPara nós fazermos as contas, quantas ações você comprou no total ?\033[0m" << endl;
            int amountBought;
            cin >> amountBought;
            it->setAmountBought(amountBought);

            cout << "\033[33mPor acaso, você já vendeu algumas dessas ações?\033[0m" << endl;
            cout << "\033[33mSe sim, por favor digite 1\033[0m" << endl;
            cout << "\033[33mSe não, digite 0\033[0m" << endl;
            bool hasSold;
            cin >> hasSold;

            if(hasSold) {
                cout << "\033[33mBem, já que você vendeu, nós precisamos fazer mais duas perguntas\033[0m" << endl;
                cout << "\033[33mA primeira, é qual foi o preço da venda ?\033[0m" << endl;
                double soldPrice;
                cin >> soldPrice;
                it->setSoldPrice(soldPrice);

                cout << "\033[33mE a segunda é quantas ações você vendeu ?\033[0m" << endl;
                int soldAmmount;
                cin >> soldAmmount;
                it->setSoldAmount(soldAmmount);
            } else {
                cout << "\033[33mMuito bem, podemos continuar então\033[0m" << endl;
            }
        }

        cout << "\033[1;4;34m\n\nCerto, nós já criamos a sua carteira, mas você ainda pode fazer algumas mudanças antes de salvarmos ela\033[0m" << endl;
        cout << "\033[33mPara adicionar mais uma ação, digite \033[1;37m1\033[0;33m" << endl;
        cout << "Para remover uma ação, digite \033[1;37m2\033[0;33m" << endl;
        cout << "Para editar alguma ação, digite \033[1;37m3\033[0;33m" << endl;
        cout << "Para salvar sua carteira, como ela está, digite \033[1;37m4\033[0m" << endl;
    } while(1);
    Stock *stock = new Stock();
    Wallet *wallet = new Wallet();
    User *user = new User();
    cout << stock->getTicker() << endl;
    return 0;
}