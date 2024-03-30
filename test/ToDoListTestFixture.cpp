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

TEST_F(ToDoListTestFixture, RemoveNonExistentItem) {
    Todo item("Task 1", "Description", "2023-03-07", false);
    testList->addItem(item);
    ASSERT_FALSE(testList->removeItem(1));
}

TEST_F(ToDoListTestFixture, ChangeNonExistentItem) {
    Todo item("Task 1", "Description", "2023-03-07");
    testList->addItem(item);
    Todo newItem("Task 2", "New Description", "2023-03-07");
    ASSERT_FALSE(testList->changeItem(1, newItem));
}

TEST_F(ToDoListTestFixture, SetTitle) {
    testList->setTitle("New Title");
    ASSERT_EQ(testList->getTitle(), "New Title");
}

TEST_F(ToDoListTestFixture, FindItemsByName) {
    testList->addItem(Todo("Task 1", "Description", "2023-03-07", false));
    testList->addItem(Todo("Task 2", "Description", "2023-03-07", false));
    testList->addItem(Todo("Task 3", "Description", "2023-03-07", false));
    testList->addItem(Todo("Task 4", "Description", "2023-03-07", false));
    std::vector<Todo> foundItems = testList->findItemsByName("Task 2");
    ASSERT_EQ(foundItems.size(), 1);
    ASSERT_EQ(foundItems[0].getTitle(), "Task 2");
}