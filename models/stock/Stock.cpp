#pragma once
#include "Stock.hpp"
#include <iostream>

using namespace std;

Stock :: Stock() {
    this->ticker = "";
    this->reasonToBuy = "";
    this->boughtPrice = 0.0;
    this->soldPrice = 0.0;
    this->amountBought = 0;
    this->soldAmount = 0;
}

string Stock :: getTicker() {
    return this->ticker;
}

string Stock :: getReasonToBuy() {
    return this->reasonToBuy;
}

double Stock :: getBoughtPrice() {
    return this->boughtPrice;
}

double Stock :: getSoldPrice() {
    return this->soldPrice;
}

int Stock :: getAmountBought() {
    return this->amountBought;
}

int Stock :: getSoldAmount() {
    return this->soldAmount;
}


void Stock :: setTicker(string value) {
    this->ticker = value;
}

void Stock :: setReasonToBuy(string value) {
    this->reasonToBuy = value;
}

void Stock :: setBoughtPrice(double value) {
    this->boughtPrice = value;
}

void Stock :: setSoldPrice(double value) {
    this->soldPrice = value;
}

void Stock :: setAmountBought(int value) {
    this->amountBought = value;
}

void Stock :: setSoldAmount(int value) {
    this->soldAmount = value;
}
