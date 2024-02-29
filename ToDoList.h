#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include <string>

class Todo {
public:
    std::string title;
    std::string description;

    Todo(const std::string &title, const std::string &description = ""):title(title), description(description) {}
};


class ToDoList {
private:
    std::vector<Todo> items;
public:
    void addItem(const Todo& item);
    bool removeItem(int index);
    bool changeItem(int index, const Todo& item);
    int getItemsCount() const;
    void displayItems() const;
    Todo getItem(int index) const;
};

#endif
