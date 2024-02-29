#include "ToDoList.h"
#include <iostream>
int main() {
    ToDoList list;

    list.addItem(Todo("Compra la pasta"));
    list.addItem(Todo("Fai la spesa", "Alle ore 15:00"));
    list.addItem(Todo("Pulisci casa"));
    list.addItem(Todo("Fai i compiti", "Matematica, Fisica, Informatica"));

    std::cout << "Elementi nella lista dopo l'aggiunta degli elementi\n";
    list.displayItems();
    std::cout << "--------------------------------\n";

    list.removeItem(1); // Rimuove "Studiare C++"
    std::cout << "Elementi nella lista dopo la rimozione di un elemento:\n";
    list.displayItems();
    std::cout << "--------------------------------\n";

    list.changeItem(3, Todo("studia matematica"));
    std::cout << "Elementi nella lista dopo la modifica di un elemento:\n";
    list.displayItems();
    std::cout << "--------------------------------\n";

    std::cout << "Numero di elementi nella lista:" << list.getItemsCount() << std::endl;

    std::cout << "Elemento 0: "<< list.getItem(0).title << std::endl;

    return 0;
}