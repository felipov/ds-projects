#include "Order.hpp"
#include "Transaction.hpp"

#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

class NodeOrder {

public:

    Order order;
    NodeOrder* next;

    NodeOrder(Order order);

};

class NodeTransaction {

public:

    Transaction transaction;
    NodeTransaction* next;

    NodeTransaction(Transaction transaction);

};

class BuyList {

public:

    NodeOrder* head;
    int size;

    BuyList();
    ~BuyList();
    int getSize() const;

    void insertEnd(Order order);
    void remove(Order order); // Mexer na assinatura da função.
    bool search(Order order) const;
    void printList();

};

class SellList {

public:

    NodeOrder* head;
    int size;

    SellList();
    ~SellList();
    int getSize() const;

    void insertEnd(Order order);
    void remove(Order order); // Mexer na assinatura da função.
    bool search(Order order) const;
    void printList();

};

class TransactionList {

public:

    NodeTransaction* head;
    int size;

    TransactionList();
    ~TransactionList();
    int getSize() const;

    void insertEnd(Transaction transaction);
    void remove(Transaction transaction);
    bool search(Transaction transaction) const;
    void printList();

};

class OrderBook {

private:
    BuyList* buyList;
    SellList* sellList;
    TransactionList* transactionList;
    int nextTransactionID;

public:

    OrderBook();
    ~OrderBook();

    bool submit(Order order);
    bool cancel(int id);

    Order* getBuyOrders(int* n);
    Order* getSellOrders(int* n);
    Transaction* getTransactions(int* n);

    void printBuyOrders();
    void printSellOrders();
    void printTransactions();

};

#endif