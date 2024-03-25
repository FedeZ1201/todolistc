//
// Created by Fede & Isa on 06/03/24.
//

#ifndef TODOLIST_OBSERVER_H
#define TODOLIST_OBSERVER_H

#include "ToDo.h"

class Observer {
public:
    virtual void update(const std::string& message, const Todo& item) = 0;

    virtual ~Observer() {}
};

#endif //TODOLIST_OBSERVER_H
