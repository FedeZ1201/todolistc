#include "ToDoList.h"
#include <iostream>

int main() {
    ToDoList list;
    list.addItem("Compra la pasta");
    list.addItem("Fai la spesa");
    list.addItem("Pulisci casa");
    list.addItem("Fai i compiti");
    std::cout << "Elementi nella lista dopo l'aggiunta degli elementi\n";
    list.displayItems();
    std::cout << "--------------------------------\n";

    list.removeItem(1);
    std::cout << "Elementi nella lista dopo la rimozione di un elemento:\n";
    list.displayItems();
    std::cout << "--------------------------------\n";

    list.changeItem(1, "studia matematica");
    std::cout << "Elementi nella lista dopo la modifica di un elemento:\n";
    list.displayItems();
    std::cout << "--------------------------------\n";

    std::cout << "Numero di elementi nella lista:";
    list.getItemsCount();


    return 0;
}
