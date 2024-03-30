#include "ToDoList.h"
#include <iostream>

ToDoList::ToDoList(const std::string& title) : title(title) {}

ToDoList::~ToDoList() {
    for(auto observer : observers) {
        observers.remove(observer);
    }
}

void ToDoList::attach(Observer* observer) {
    observers.push_back(observer);
}

void ToDoList::detach(Observer* observer) {
    observers.remove(observer);
}

void ToDoList::notify(const std::string& message, const Todo& item) {
    for(auto observer : observers) {
        observer->update(message, item);
    }
}

void ToDoList::addItem(const Todo& item) {
    items.push_back(item);
    notify("Item added", item);
}

bool ToDoList::removeItem(int index) {
    if (index < 0 || index >= items.size()) {
        return false;
    }
    Todo removedItem = items[index];
    items.erase(items.begin() + index);
    notify("Item removed", removedItem); // Notifica gli observer
    return true;
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
    if (index < 0 || index >= items.size()) {
        throw std::out_of_range("Index out of range");
    }
    return items[index];
}

void ToDoList::displayItems() const {
    for(int i = 0; i < items.size(); ++i) {
        std::cout << i << ": " << items[i].getTitle();
        if (!items[i].getDescription().empty()) {
            std::cout << " - " << items[i].getDescription();
        }
        std::cout << ", Due Date: " << items[i].getDate() << ", Completed: "
                          << (items[i].getIsCompleted() ? "Yes" : "No") << std::endl;
    }
}

// Cerca items in base al nome
std::vector<Todo> ToDoList::findItemsByName(const std::string& name) const {
    std::vector<Todo> foundItems;
    for (const auto& item : items) {
        if (item.getTitle() == name) {
            foundItems.push_back(item);
        }
    }
    return foundItems;
}

// Restituisce il numero di items ancora da fare
int ToDoList::getItemsToDoCount() const {
    int count = 0;
    for (const auto& item : items) {
        if (!item.getIsCompleted()) {
            ++count;
        }
    }
    return count;
}

std::string ToDoList::getTitle() const {
    return title;
}

void ToDoList::setTitle(const std::string& newTitle) {
    title = newTitle;
}