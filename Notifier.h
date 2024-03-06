
#ifndef TODOLIST_NOTIFIER_H
#define TODOLIST_NOTIFIER_H

#include "Observer.h"
#include <iostream>

class Notifier : public Observer {
public:
    void update(const std::string& message, const Todo& item) override {
        std::cout << "Notifica: " << message << " - Titolo Todo: " << item.getTitle() << std::endl;
    }
};

#endif //TODOLIST_NOTIFIER_H
