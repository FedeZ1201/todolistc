//
// Created by Fede & Isa on 06/03/24.
//

#include <gtest/gtest.h>
#include "../ToDoCollection.h"

class ToDoCollectionTest : public ::testing::Test {
protected:
    ToDoCollection* collection;

    void SetUp() override {
        collection = new ToDoCollection("Test Collection");
    }

    void TearDown() override {
        delete collection;
    }
};

TEST_F(ToDoCollectionTest, AddList) {
    ToDoList list("Shopping");
    collection->addList(list);
    ASSERT_EQ(collection->getListsCount(), 1);
}

TEST_F(ToDoCollectionTest, RemoveListByName) {
    ToDoList list("Shopping");
    collection->addList(list);
    bool result = collection->removeList("Shopping");
    ASSERT_TRUE(result);
    ASSERT_EQ(collection->getListsCount(), 0);
}

TEST_F(ToDoCollectionTest, RemoveListByNameNotFound) {
    bool result = collection->removeList("NonExisting");
    ASSERT_FALSE(result);
}

TEST_F(ToDoCollectionTest, RemoveListByIndex) {
    ToDoList list1("Shopping");
    ToDoList list2("Work");
    collection->addList(list1);
    collection->addList(list2);
    bool result = collection->removeListByIndex(0);
    ASSERT_TRUE(result);
    ASSERT_EQ(collection->getListsCount(), 1);
}

TEST_F(ToDoCollectionTest, RemoveListByInvalidIndex) {
    bool result = collection->removeListByIndex(100); // Assuming no list has been added
    ASSERT_FALSE(result);
}

TEST_F(ToDoCollectionTest, GetListByName) {
    ToDoList list("Shopping");
    collection->addList(list);
    ToDoList* retrievedList = collection->getList("Shopping");
    ASSERT_NE(retrievedList, nullptr);
    ASSERT_EQ(retrievedList->getTitle(), "Shopping");
}

TEST_F(ToDoCollectionTest, GetListByNameNotFound) {
    ToDoList* retrievedList = collection->getList("NonExisting");
    ASSERT_EQ(retrievedList, nullptr);
}

TEST_F(ToDoCollectionTest, DisplayLists) {
    // This test might simply ensure the function runs, as testing console output can be complex and often not very meaningful
    ASSERT_NO_THROW(collection->displayLists());
}

// More tests can be added for other methods and edge cases

