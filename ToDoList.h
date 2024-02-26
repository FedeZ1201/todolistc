#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include <string>

class ToDoList {
private:
    std::vector<std::string> items;
public:
    void addItem(const std::string& item);
    bool removeItem(int index);
    bool changeItem(int index, const std::string& newItem);
    void displayItems() const;
};

#endif
