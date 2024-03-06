#include <gtest/gtest.h>
#include "../ToDoList.h"

class ToDoListTestFixture : public ::testing::Test {
protected:
    ToDoList* testList;

    void SetUp() override {
        testList = new ToDoList("Test List");
    }

    void TearDown() override {
        delete testList;
    }
};

TEST_F(ToDoListTestFixture, AddItem) {
    Todo item("Compra Latte", "2 litri", "2023-03-07", false);
    testList->addItem(item);
    ASSERT_EQ(testList->getItemsCount(), 1);
}

TEST_F(ToDoListTestFixture, RemoveItem) {
    Todo item("Compra Latte", "2 litri", "2023-03-07", false);
    testList->addItem(item);
    ASSERT_TRUE(testList->removeItem(0));
    ASSERT_EQ(testList->getItemsCount(), 0);
}

TEST_F(ToDoListTestFixture, RemoveItemAtInvalidIndex) {
    ASSERT_FALSE(testList->removeItem(0)); // No items added yet
}

TEST_F(ToDoListTestFixture, ChangeItem) {
    Todo item("Compra Latte", "2 litri", "2023-03-07");
    testList->addItem(item);
    Todo newItem("Compra Pane", "2 etti", "2023-03-07");
    ASSERT_TRUE(testList->changeItem(0, newItem));
    Todo updatedItem = testList->getItem(0);
    ASSERT_EQ(updatedItem.getTitle(), "Compra Pane");
}

TEST_F(ToDoListTestFixture, GetItemsCount) {
    testList->addItem(Todo("Task 1", "", "2023-03-07", false));
    testList->addItem(Todo("Task 2", "", "2023-03-07", true));
    ASSERT_EQ(testList->getItemsCount(), 2);
}

TEST_F(ToDoListTestFixture, GetItemsToDoCount) {
    testList->addItem(Todo("Task 1", "", "2023-03-07", false));
    testList->addItem(Todo("Task 2", "", "2023-03-07", true));
    ASSERT_EQ(testList->getItemsToDoCount(), 1);
}


