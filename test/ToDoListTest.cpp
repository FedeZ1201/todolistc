#include <gtest/gtest.h>
#include "../ToDoList.h"

TEST(ToDoList, AddActionItems) {
    ToDoList list;
    list.addItem(Todo("Compra la pasta"));
    list.addItem(Todo("Fai la spesa", "Alle ore 15:00"));
    list.addItem(Todo("Pulisci casa"));
    list.addItem(Todo("Fai i compiti", "Matematica, Fisica, Informatica"));
    ASSERT_EQ(list.getItemsCount(), 4) << "La dimensione della lista dovrebbe essere 4 dopo l'aggiunta di azioni specifiche";
}

TEST(ToDoList, CheckActionItemContent) {
    ToDoList list;
    list.addItem(Todo("Vai a scuola", "Alle 8:00"));
    EXPECT_EQ(list.getItem(0).title, "Vai a scuola") << "Il contenuto dell'item non corrisponde all'azione 'Vai a scuola'";
    EXPECT_EQ(list.getItem(0).description, "Alle 8:00") << "Il contenuto dell'item non corrisponde alla descrizione 'Alle 8:00'";
}

TEST(ToDoList, RemoveActionItem) {
    ToDoList list;
    list.addItem(Todo("Prendi il cane"));
    list.removeItem(0);
    ASSERT_EQ(list.getItemsCount(), 0) << "La dimensione della lista dovrebbe essere 0 dopo la rimozione dell'azione";
}
TEST(ToDoListTest, RemoveItemOnEmptyList) {
    ToDoList list;
    ASSERT_FALSE(list.removeItem(0)) << "Rimuovere un item da una lista vuota dovrebbe restituire false";
}

TEST(ToDoList, ChangeActionItem) {
    ToDoList list;
    list.addItem(Todo("Vai a nuoto"));
    list.changeItem(0,Todo("Mangia le medicine", "Dopo pranzo"));
    EXPECT_EQ(list.getItem(0).title,"Mangia le medicine") << "Dovrebbe cambiare l'azione in 'Mangia le medicine'";
    EXPECT_EQ(list.getItem(0).description,"Dopo pranzo") << "Dovrebbe cambiare la descrizione in 'Dopo pranzo'";
}



