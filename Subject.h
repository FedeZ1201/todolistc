//
// Created by Fede & Isa on 06/03/24.
//

#ifndef TODOLIST_SUBJECT_H
#define TODOLIST_SUBJECT_H

#include "Observer.h"
#include <list>

class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify(const std::string& message, const Todo& item) = 0;
    virtual ~Subject() {}
};

#endif //TODOLIST_SUBJECT_H
