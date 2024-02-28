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

int ToDoList::getItemsCount() const {
    int count = 0;
    for (auto it = items.begin(); it != items.end(); ++it) {
        count++;
    }
    return count;
}
std::string ToDoList::getItem(int index) const {
    return items[index];
}

void ToDoList::displayItems() const {
    for(int i = 0; i < items.size(); ++i) {
        std::cout << i + 1 << ". " << items[i] << std::endl;
    }
}
