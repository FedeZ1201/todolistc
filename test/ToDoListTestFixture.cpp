#include <gtest/gtest.h>

#include "../ToDoList.h"

class ToDoListTestFixture : public ::testing::Test {
protected:

    void SetUp()  {
        // Configura qui lo stato iniziale comune per i test
        list.addItem("Compra il latte");
        list.addItem("Compra il pane");
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

