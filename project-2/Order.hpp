#ifndef ORDER_HPP
#define ORDER_HPP

class Order {

private:

    int ID;
    char type;
    float price;
    int timestamp;

public:

    Order() {
        ID = 0;
        type = 'B';
        price = 0.0f;
        timestamp = 0;
    };
    Order(int ID, char type, float price, int timestamp);
    ~Order();

    int getID();
    char getType();
    float getPrice();
    int getTimestamp();
};



#endif