//
// Created by Fede & Isa on 06/03/24.
//

#ifndef TODOLIST_SUBJECT_H
#define TODOLIST_SUBJECT_H

#include "Observer.h"
#include <list>

class Subject {
private:
    std::list<Observer*> observers;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        observers.remove(observer);
    }

    void notify(const std::string& message, const Todo& item) {
        for (Observer* observer : observers) {
            observer->update(message, item);
        }
    }
};

#endif //TODOLIST_SUBJECT_H
