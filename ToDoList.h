#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include <string>
#include "ToDo.h"
#include "Subject.h"

class ToDoList : public Subject {
private:
    std::vector<Todo> items;
    std::string title;
public:
    ToDoList(const std::string &title);
    void addItem(const Todo& item);
    bool removeItem(int index);
    bool changeItem(int index, const Todo& item);
    int getItemsCount() const;
    void displayItems() const;
    Todo getItem(int index) const;
    std::vector<Todo> findItemsByName(const std::string& name) const;
    int getItemsToDoCount() const;

    std::string getTitle() const;
    void setTitle(const std::string& newTitle);
};

#endif
