#include <gtest/gtest.h>

#include "../ToDoList.h"

class ToDoListTestFixture : public ::testing::Test {
protected:

    void SetUp()  {
        // Configura qui lo stato iniziale comune per i test
        list.addItem(Todo("Compra la pasta"));
        list.addItem(Todo("Fai la spesa", "Alle ore 15:00"));
    }

    ToDoList list;
};

TEST_F(ToDoListTestFixture, CheckInitialSize) {
    ASSERT_EQ(list.getItemsCount(), 2) << "La dimensione iniziale della lista dovrebbe essere 2";
}

TEST_F(ToDoListTestFixture, RemoveItem) {
    ASSERT_TRUE(list.removeItem(0)) << "Dovrebbe restituire true quando un item è rimosso con successo";
    ASSERT_EQ(list.getItemsCount(), 1) << "La dimensione della lista dovrebbe essere 1 dopo la rimozione di un item";
}

TEST_F(ToDoListTestFixture, RemoveItemOnEmptyList) {
    list.removeItem(0);
    list.removeItem(0);
    ASSERT_FALSE(list.removeItem(0)) << "Rimuovere un item da una lista vuota dovrebbe restituire false";
}

TEST_F(ToDoListTestFixture, ChangeItem) {
    list.changeItem(0, Todo("Mangia le medicine", "Dopo pranzo"));
    EXPECT_EQ(list.getItem(0).title,"Mangia le medicine") << "Dovrebbe cambiare l'azione in 'Mangia le medicine'";
    EXPECT_EQ(list.getItem(0).description,"Dopo pranzo") << "Dovrebbe cambiare la descrizione in 'Dopo pranzo'";
}

TEST_F(ToDoListTestFixture, AddItem) {
    list.addItem(Todo("Pulisci casa"));
    ASSERT_EQ(list.getItemsCount(), 3) << "La dimensione della lista dovrebbe essere 3 dopo l'aggiunta di un item";
}



