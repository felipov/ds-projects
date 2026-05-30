#include <iostream>
#include "OrderBook.hpp"

NodeOrder::NodeOrder(Order order){
    this->order = order;
    this->next = nullptr;
}

NodeTransaction::NodeTransaction(Transaction transaction){
    this->transaction = transaction;
    this->next = nullptr;
}


// Funções da classe BuyList
BuyList::BuyList(){
    this->head = nullptr;
    this->size = 0;
}

BuyList::~BuyList(){
    NodeOrder* current = head;
    while (current != nullptr) {
        NodeOrder* prev = current;
        current = current->next;
        delete prev;
    }
}

int BuyList::getSize() const{
    return this->size;
}

void BuyList::insertEnd(Order order){
    NodeOrder* newNode = new NodeOrder(order);

    if (head == nullptr) {
        head = newNode;
    } else {
        NodeOrder* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

void BuyList::remove(Order order){
    if (head == nullptr) return;

    if (head->order.getID() == order.getID()) {
        NodeOrder* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }

    NodeOrder* current = head;
    while (current->next != nullptr && current->next->order.getID() != order.getID()) {
        current = current->next;
    }

    if (current->next == nullptr) return;

    NodeOrder* temp = current->next;
    current->next = current->next->next;
    delete temp;
    size--;
}

bool BuyList::search(Order order) const{
    NodeOrder* current = head;

    while (current != nullptr) {
        if (current->order.getID() == order.getID()) return true;
        current = current->next;
    }

    return false;
}

void BuyList::printList(){
    NodeOrder* current = head;

    std::cout << "Buy Orders:" << std::endl;

    if (current == nullptr) {
        std::cout << "(empty)" << std::endl;
        std::cout << std::endl;
        return;
    }

    while (current != nullptr) {
        std::cout << "[ " << current->order.getID() << " | " 
        << current->order.getPrice() << " | " << current->order.getTimestamp()
        << " ]" << std::endl;

        current = current->next;
    }

    std::cout << std::endl;
}




// Funções da classe SellList
SellList::SellList(){
    this->head = nullptr;
    this->size = 0;
}

SellList::~SellList(){
    NodeOrder* current = head;
    while (current != nullptr) {
        NodeOrder* prev = current;
        current = current->next;
        delete prev;
    }
}

int SellList::getSize() const{
    return this->size;
}

void SellList::insertEnd(Order order){
    NodeOrder* newNode = new NodeOrder(order);

    if (head == nullptr) {
        head = newNode;
    } else {
        NodeOrder* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

void SellList::remove(Order order){
    if (head == nullptr) return;

    if (head->order.getID() == order.getID()) {
        NodeOrder* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }

    NodeOrder* current = head;
    while (current->next != nullptr && current->next->order.getID() != order.getID()) {
        current = current->next;
    }

    if (current->next == nullptr) return;

    NodeOrder* temp = current->next;
    current->next = current->next->next;
    delete temp;
    size--;
}

bool SellList::search(Order order) const{
    NodeOrder* current = head;

    while (current != nullptr) {
        if (current->order.getID() == order.getID()) return true;
        current = current->next;
    }

    return false;
}

void SellList::printList(){
    NodeOrder* current = head;

    std::cout << "Sell Orders:" << std::endl;

    if (current == nullptr) {
        std::cout << "(empty)" << std::endl;
        std::cout << std::endl;
        return;
    }

    while (current != nullptr) {
        std::cout << "[ " << current->order.getID() << " | " 
        << current->order.getPrice() << " | " << current->order.getTimestamp()
        << " ]" << std::endl;

        current = current->next;
    }

    std::cout << std::endl;
}

// Funções da classe TransactionList
TransactionList::TransactionList(){
    this->head = nullptr;
    this->size = 0;
}

TransactionList::~TransactionList(){
    NodeTransaction* current = head;
    while (current != nullptr) {
        NodeTransaction* prev = current;
        current = current->next;
        delete prev;
    }
}

int TransactionList::getSize() const{
    return this->size;
}

void TransactionList::insertEnd(Transaction transaction){
    NodeTransaction* newNode = new NodeTransaction(transaction);

    if (head == nullptr) {
        head = newNode;
    } else {
        NodeTransaction* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

void TransactionList::remove(Transaction transaction){
    if (head == nullptr) return;

    if (head->transaction.getTransactionID() == transaction.getTransactionID()) {
        NodeTransaction* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }

    NodeTransaction* current = head;
    while (current->next != nullptr && current->next->transaction.getTransactionID() != transaction.getTransactionID()) {
        current = current->next;
    }

    if (current->next == nullptr) return;

    NodeTransaction* temp = current->next;
    current->next = current->next->next;
    delete temp;
    size--;
}

bool TransactionList::search(Transaction transaction) const{
    NodeTransaction* current = head;

    while (current != nullptr) {
        if (current->transaction.getTransactionID() == transaction.getTransactionID()) return true;
        current = current->next;
    }

    return false;
}

void TransactionList::printList(){
    NodeTransaction* current = head;
    std::cout << "Transactions: " << std:: endl;

    if (current == nullptr) {
        std::cout << "(empty)" << std::endl;
        std::cout << std::endl;
        return;
    }

    while (current != nullptr) {
        std::cout << "[ " << current->transaction.getBuyID() << " | " 
        << current->transaction.getSellID() << " | " << current->transaction.getPrice()
        << " | " << current->transaction.getTransactionID() << " ]" << std::endl;

        current = current->next;
    }

    std::cout << std::endl;
}


// Funções da classe OrderBook
OrderBook::OrderBook(){
    this->buyList = new BuyList();
    this->sellList = new SellList();
    this->transactionList = new TransactionList();
    this->nextTransactionID = 1;
}

OrderBook::~OrderBook(){
    if (this->buyList != nullptr) {
        delete this->buyList;
        this->buyList = nullptr;
    }

    if (this->sellList != nullptr) {
        delete this->sellList;
        this->sellList = nullptr;
    }

    if (this->transactionList != nullptr) {
        delete this->transactionList;
        this->transactionList = nullptr;
    }

}

bool OrderBook::submit(Order order){
    if (order.getType() == 'B') {
        NodeOrder* current = sellList->head;
        NodeOrder* best = nullptr;

        while (current != nullptr) {
            if (current->order.getPrice() <= order.getPrice()) {
                if (best == nullptr || 
                    current->order.getPrice() < best->order.getPrice() ||
                    (current->order.getPrice() == best->order.getPrice() &&
                     current->order.getTimestamp() < best->order.getTimestamp())) {
                        best = current;
                     }
            }
            current = current->next;
        }

        if (best == nullptr) {
            buyList->insertEnd(order);

            return false;
        }

        transactionList->insertEnd(Transaction(order.getID(), best->order.getID(), best->order.getPrice(), nextTransactionID++));
        buyList->remove(best->order);
        sellList->remove(best->order);

        return true;
    }
    else if (order.getType() == 'S') {
        NodeOrder* current = buyList->head;
        NodeOrder* best = nullptr;

        while (current != nullptr) {
            if (current->order.getPrice() >= order.getPrice()) {
                if (best == nullptr ||
                    current->order.getPrice() > best->order.getPrice() ||
                    (current->order.getPrice() == best->order.getPrice() &&
                     current->order.getTimestamp() < best->order.getTimestamp())) {
                        best = current;
                     }
            }
            current = current->next;
        }

        if (best == nullptr) {
            sellList->insertEnd(order);

            return false;
        }

        transactionList->insertEnd(Transaction(best->order.getID(), order.getID(), best->order.getPrice(), nextTransactionID++));
        buyList->remove(best->order);
        sellList->remove(best->order);

        return true;
    }
    return false;
}
bool OrderBook::cancel(int id){
    NodeOrder* current = buyList->head;

    while (current != nullptr) {
        if (current->order.getID() == id) {
            buyList->remove(current->order);

            return true;
        }
        current = current->next;
    }

    current = sellList->head;
    
    while (current != nullptr) {
        if (current->order.getID() == id) {
            sellList->remove(current->order);

            return true;
        }
        current = current->next;
    }
    return false;
}

Order* OrderBook::getBuyOrders(int* n){
    *n = buyList->getSize();
    if (*n == 0) return nullptr;

    Order* array = new Order[*n];

    NodeOrder* current = buyList->head;
    for (int i = 0; i < *n; i++) {
        array[i] = current->order;
        current = current->next;
    }

    return array;
}

Order* OrderBook::getSellOrders(int* n){
    *n = sellList->getSize();
    if (*n == 0) return nullptr;

    Order* array = new Order[*n];

    NodeOrder* current = sellList->head;
    for (int i = 0; i < *n; i++) {
        array[i] = current->order;
        current = current->next;
    }

    return array;
}

Transaction* OrderBook::getTransactions(int* n){
    *n = transactionList->getSize();
    if (*n == 0) return nullptr;

    Transaction* array = new Transaction[*n];

    NodeTransaction* current = transactionList->head;
    for (int i = 0; i < *n; i++) {
        array[i] = current->transaction;
        current = current->next;
    }

    return array;
}

void OrderBook::printBuyOrders(){
    this->buyList->printList();
}
void OrderBook::printSellOrders(){
    this->sellList->printList();
}
void OrderBook::printTransactions(){
    this->transactionList->printList();
}