#include "Order.hpp"

Order::Order(int ID, char type, float price, int timestamp) : ID(ID), type(type), price(price), timestamp(timestamp) {}

Order::~Order() {
    // Não houve alocação dinâmica na memória.
}

int Order::getID() { 
    return ID; 
}

char Order::getType() {
    return type;
}

float Order::getPrice() {
    return price;
}

int Order::getTimestamp() {
    return timestamp;
}