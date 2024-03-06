//
// Created by Fede & Isa on 06/03/24.
//

#ifndef TODOLIST_TODOCOLLECTION_H
#define TODOLIST_TODOCOLLECTION_H

#include "ToDoList.h"
#include <vector>
#include <string>

class ToDoCollection {

private:
    std::string name;
    std::vector<ToDoList> lists;

public:
    ToDoCollection(const std::string& name);
    void addList(const ToDoList& list);
    bool removeList(const std::string& name);
    bool removeListByIndex(const int index);
    ToDoList* getList(const std::string& name);
    int getListsCount() const;
    void displayLists() const;
    std::string getName() const;
    void setName(const std::string& newName);
};


#endif //TODOLIST_TODOCOLLECTION_H
