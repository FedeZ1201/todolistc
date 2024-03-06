//
// Created by Fede & Isa on 06/03/24.
//

#include "ToDoCollection.h"
#include <iostream>


ToDoCollection::ToDoCollection(const std::string& name) : name(name) {}

void ToDoCollection::addList(const ToDoList& list) {
    lists.push_back(list);
}

bool ToDoCollection::removeList(const std::string& name) {
    for (auto it = lists.begin(); it != lists.end(); ++it) {
        if (it->getTitle() == name) {
            lists.erase(it);
            return true;
        }
    }
    return false;
}

bool ToDoCollection::removeListByIndex(const int index) {
    if (index < 0 || index >= lists.size()) {
        return false;
    }
    lists.erase(lists.begin() + index);
    return true;
}

ToDoList* ToDoCollection::getList(const std::string& name) {
    for (auto& list : lists) {
        if (list.getTitle() == name) {
            return &list;
        }
    }
    return nullptr;
}


int ToDoCollection::getListsCount() const {
    return lists.size();
}

// Visualizza i nomi di tutte le ToDoList nella collezione
void ToDoCollection::displayLists() const {
    std::cout << "ToDo Lists in the collection "<< name << std::endl;
    for (const auto& list : lists) {
        std::cout << "- " << list.getTitle() << std::endl;
    }
}

std::string ToDoCollection::getName() const {
    return name;
}

void ToDoCollection::setName(const std::string& newName) {
    name = newName;
}