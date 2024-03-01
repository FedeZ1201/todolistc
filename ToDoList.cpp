#include "ToDoList.h"
#include <iostream>

void ToDoList::addItem(const Todo& item) {
    items.push_back(item);
}

bool ToDoList::removeItem(int index) {
    try{
        if(index >= 0 && index < items.size()) {
            items.erase(items.begin() + index);
            return true;
        }
        return false;
    }
    catch (std::out_of_range& e) {
        std::cerr << "Errore: " << e.what() << std::endl;
    }
}

bool ToDoList::changeItem(int index, const Todo& newItem) {
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
Todo ToDoList::getItem(int index) const {
    try {
        if (index >= 0 && index < items.size()) {
            return items[index];
        }
    }
    catch (std::out_of_range& e) {
        std::cerr << "Errore: " << e.what() << std::endl;
    }
}

void ToDoList::displayItems() const {
    for(int i = 0; i < items.size(); ++i) {
        std::cout << i << ": " << items[i].title;
        if (!items[i].description.empty()) {
            std::cout << " - " << items[i].description;
        }
        std::cout << std::endl;
    }
}
