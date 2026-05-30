#include <iostream>
#include "Order.hpp"
#include "Transaction.hpp"
#include "OrderBook.hpp"

int main(){

    // Criação do sistema
    OrderBook sistema;

    // Inserção de ordens
    Order compra1(0, 'B', 9.50, 1);
    Order compra2(1, 'B', 4.50, 2);
    
    sistema.submit(compra1);
    sistema.submit(compra2);

    Order venda1(2, 'S', 12.30, 3);
    Order venda2(3, 'S', 5.30, 4);

    sistema.submit(venda1);
    sistema.submit(venda2);

    std::cout << "Primeiro estado do sistema" << std::endl;
    sistema.printBuyOrders();
    sistema.printSellOrders();
    sistema.printTransactions();

    sistema.cancel(0);
    sistema.cancel(1);

    std::cout << "Segundo estado do sistema" << std::endl;
    sistema.printBuyOrders();
    sistema.printSellOrders();
    sistema.printTransactions();

    Order compra3(4, 'B', 15.0, 5);
    Order compra4(5, 'B', 3.50, 6);
    Order venda3(6, 'S', 5, 7);
    sistema.submit(compra3);
    sistema.submit(compra4);
    sistema.submit(venda3);

    std::cout << "Terceiro estado do sistema" << std::endl;
    sistema.printBuyOrders();
    sistema.printSellOrders();
    sistema.printTransactions();

    Order compra5(7, 'B', 6.50, 8);
    sistema.submit(compra5);

    std::cout << "Quarto estado do sistema" << std::endl;
    sistema.printBuyOrders();
    sistema.printSellOrders();
    sistema.printTransactions();

    sistema.cancel(5);
    std::cout << "Quarto estado do sistema" << std::endl;
    sistema.printBuyOrders();
    sistema.printSellOrders();
    sistema.printTransactions();

    // Recuperação dos dados
    int b;
    int s;
    int t;
    Order* buy = sistema.getBuyOrders(&b);
    Order* sell = sistema.getSellOrders(&s);
    Transaction* transaction = sistema.getTransactions(&t);

    std::cout << "Recuperação dos dados" << std::endl;
    std::cout << "Número Atual de Ordens de Compra: " << b << std::endl;
    std::cout << "Número Atual de Ordens de Venda: " << s << std::endl;
    std::cout << "Número Atual de Transações: " << t << std::endl;

    for (int i = 0; i < t; i++) {
        std::cout << "Transaction ID: " << transaction[i].getTransactionID() << std::endl;
    }



    return 0;
}