#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

class Transaction {

private:

    int buy_order_ID;
    int sell_order_ID;
    float price;
    int transaction_ID;

public:

    Transaction() {
        buy_order_ID = 0;
        sell_order_ID = 0;
        price = 0.0f;
        transaction_ID = 0;
    };
    Transaction(int buy_order_ID, int sell_order_ID, float price, int transaction_ID);
    ~Transaction();

    int getBuyID();
    int getSellID();
    float getPrice();
    int getTransactionID();
};

#endif