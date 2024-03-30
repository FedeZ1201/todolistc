#include "ToDoList.h"
#include "ToDoCollection.h"
#include "Notifier.h"
#include <iostream>

int main() {

    ToDoCollection collection1("Collezione 1");
    ToDoCollection collection2("Collezione 2");

    // Crea la lista di cose da fare con un nome
    ToDoList list1("Lista");
    ToDoList list2("Lista 2");
    ToDoList list3("Lista 3");

    // Aggiunge le liste alla collezione
    collection1.addList(list1);
    collection1.addList(list2);
    collection2.addList(list3);

    // Crea un observer
    Notifier notifier;

    // Registra l'observer con la lista di cose da fare
    list1.attach(&notifier);
    list2.attach(&notifier);
    list3.attach(&notifier);
    notifier.attachTo(&list1);
    notifier.attachTo(&list2);
    notifier.attachTo(&list3);


    // Aggiunge elementi alla lista, ciò scatenerà le notifiche
    list1.addItem(Todo("Compra la pasta"));
    list1.addItem(Todo("Fai la spesa", "Alle ore 15:00"));
    list1.addItem(Todo("Pulisci casa"));
    list1.addItem(Todo("Fai i compiti", "Matematica, Fisica, Informatica"));


    std::cout << "\n--------------------------------\n";
    std::cout << "Elementi nella lista dopo l'aggiunta degli elementi:\n";
    list1.displayItems();
    std::cout << "--------------------------------\n";

    // Rimuove un elemento dalla lista, ciò scatenerà una notifica
    list1.removeItem(1); // Assume indice corretto basato sugli elementi aggiunti sopra
    std::cout << "Elementi nella lista dopo la rimozione di un elemento:\n";
    list1.displayItems();
    std::cout << "--------------------------------\n";

    // Cambia un elemento nella lista, ciò non scatena notifiche se non implementato esplicitamente
    list1.changeItem(2, Todo("Studia matematica")); // Assume indice corretto dopo la rimozione
    std::cout << "Elementi nella lista dopo la modifica di un elemento:\n";
    list1.displayItems();
    std::cout << "--------------------------------\n";

    std::cout << "Numero di elementi nella lista: " << list1.getItemsCount() << std::endl;

    // Mostra titolo dell'elemento all'indice specificato
    std::cout << "Elemento 0: " << list1.getItem(0).getTitle() << std::endl;

    std::cout << "--------------------------------\n";
    list2.addItem(Todo("Vai in palestra", "Alle 8:00", "2024-03-24"));
    list2.addItem(Todo("Fai ginnastica", "Puoi farla in giardino", "2024-03-24"));
    list2.addItem(Todo("Pulisci la terrazza"));
    list3.addItem(Todo("Vai a nuoto", "Alle 10:00"));

    std::cout << "--------------------------------\n";
    collection1.displayLists();
    collection2.displayLists();

    std::cout << "--------------------------------\n";
    std::cout << "Numero di liste nella collezione 1: " << collection1.getListsCount() << std::endl;
    std::cout << "Numero di liste nella collezione 2: " << collection2.getListsCount() << std::endl;

    std::cout << "--------------------------------\n";
    std::cout << "Rimuovi la lista 2 dalla collezione 1: " << (collection1.removeList("Lista 2")?"Fatto":"Non riuscito") << std::endl;
    std::cout << "Numero di liste nella collezione 1 dopo la rimozione: " << collection1.getListsCount() << std::endl;

    std::cout << "--------------------------------\n";
    std::cout << "Nome Liste presenti dopo la rimozione:\n";
    collection1.displayLists();

    std::cout << "--------------------------------\n";
    std::cout << "Nome della collezione 1: " << collection1.getName() << std::endl;

    std::cout << "--------------------------------\n";
    collection1.setName("Collezione 1 - Nuovo Nome");
    std::cout << "Nuovo nome della collezione 1: " << collection1.getName() << std::endl;
    return 0;
}