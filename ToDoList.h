#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include <list>
#include <string>
#include "ToDo.h"
#include "Observer.h"
#include "Subject.h"

class ToDoList : public Subject {
private:
    std::list<Observer*> observers; // Manage observers within ToDoList
    std::vector<Todo> items;
    std::string title;

public:
    explicit ToDoList(const std::string &title);
    ~ToDoList() override;

    void attach(Observer* observer) override;
    void detach(Observer* observer) override;
    void notify(const std::string& message, const Todo& item) override;

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
