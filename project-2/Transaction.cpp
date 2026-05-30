#include "Transaction.hpp"

Transaction::Transaction(int buy_order_ID, int sell_order_ID, float price, int transaction_ID) :
    buy_order_ID(buy_order_ID), sell_order_ID(sell_order_ID), price(price), transaction_ID(transaction_ID) {}

Transaction::~Transaction() {
    // Não houve alocação dinâmica de memória.
}

int Transaction::getBuyID() {
    return buy_order_ID;
}

int Transaction::getSellID() {
    return sell_order_ID;
}

float Transaction::getPrice() {
    return price;
}

int Transaction::getTransactionID(){
    return transaction_ID;
}