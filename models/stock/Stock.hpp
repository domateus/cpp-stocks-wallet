#pragma once
#include <iostream>

using namespace std;

// Stock class
class Stock {
    private:
        string ticker;
        string reasonToBuy;
        double boughtPrice;
        double soldPrice;
        int amountBought;
        int soldAmount;

    public:
        /**
        * Class Constructor
        * 
        * defines its atributes default values
        * 
        * recives no params
        */
        Stock();
        // return ticker
        string getTicker();
        // return reason to buy
        string getReasonToBuy();
        // return bough price
        double getBoughtPrice();
        // return sold price if sold
        double getSoldPrice();
        // return current amount of stocks
        int getAmountBought();
        // return amount of stocks sold if any
        int getSoldAmount();

        // set ticker
        void setTicker(string value);
        // set reason to buy
        void setReasonToBuy(string value);
        // set bough price
        void setBoughtPrice(double value);
        // set sold price if sold
        void setSoldPrice(double value);
        // set current amount of stocks
        void setAmountBought(int value);
        // set amount of stocks sold if any
        void setSoldAmount(int value);

};
