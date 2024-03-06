#include <gtest/gtest.h>
#include "../ToDoList.h"

TEST(ToDoList, AddActionItems) {
    ToDoList lista("Lista della spesa");
    lista.addItem(Todo("Compra la pasta"));
    lista.addItem(Todo("Fai la spesa", "Alle ore 15:00"));
    lista.addItem(Todo("Pulisci casa"));
    lista.addItem(Todo("Fai i compiti", "Matematica, Fisica, Informatica"));
    ASSERT_EQ(lista.getItemsCount(), 4) << "La dimensione della lista dovrebbe essere 4 dopo l'aggiunta di elementi.";
}

TEST(ToDoList, CheckActionItemContent) {
    ToDoList list("Lista delle azioni");
    list.addItem(Todo("Vai a scuola", "Alle 8:00"));
    EXPECT_EQ(list.getItem(0).getTitle(), "Vai a scuola") << "Il contenuto dell'item non corrisponde all'azione 'Vai a scuola'";
    EXPECT_EQ(list.getItem(0).getDescription(), "Alle 8:00") << "Il contenuto dell'item non corrisponde alla descrizione 'Alle 8:00'";
}

TEST(ToDoList, RemoveActionItem) {
    ToDoList list("Lista delle azioni");
    list.addItem(Todo("Prendi il cane"));
    list.removeItem(0);
    ASSERT_EQ(list.getItemsCount(), 0) << "La dimensione della lista dovrebbe essere 0 dopo la rimozione dell'azione";
}
TEST(ToDoListTest, RemoveItemOnEmptyList) {
    ToDoList list("Lista delle azioni");
    ASSERT_FALSE(list.removeItem(0)) << "Rimuovere un item da una lista vuota dovrebbe restituire false";
}

TEST(ToDoList, ChangeActionItem) {
    ToDoList list("Lista delle azioni");
    list.addItem(Todo("Vai a nuoto"));
    list.changeItem(0,Todo("Mangia le medicine", "Dopo pranzo"));
    EXPECT_EQ(list.getItem(0).getTitle(),"Mangia le medicine") << "Dovrebbe cambiare l'azione in 'Mangia le medicine'";
    EXPECT_EQ(list.getItem(0).getDescription(),"Dopo pranzo") << "Dovrebbe cambiare la descrizione in 'Dopo pranzo'";
}



