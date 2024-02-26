#include "ToDoList.h"
#include <iostream>

void ToDoList::addItem(const std::string& item) {
    items.push_back(item);
}

bool ToDoList::removeItem(int index) {
    if(index >= 0 && index < items.size()) {
        items.erase(items.begin() + index);
        return true;
    }
    return false;
}

bool ToDoList::changeItem(int index, const std::string& newItem) {
    if(index >= 0 && index < items.size()) {
        items[index] = newItem;
        return true;
    }
    return false;
}

void ToDoList::displayItems() const {
    for(int i = 0; i < items.size(); ++i) {
        std::cout << i + 1 << ". " << items[i] << std::endl;
    }
}
