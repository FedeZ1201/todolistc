
#ifndef TODOLIST_NOTIFIER_H
#define TODOLIST_NOTIFIER_H

#include "Observer.h"
#include <iostream>
#include "Subject.h"
#include <vector>

class Notifier : public Observer {
private:
    std::vector<Subject*> subscribedSubjects;

public:
    void attachTo(Subject* subject) {
        subscribedSubjects.push_back(subject);
        subject->attach(this);
    }

    void dettachFrom(Subject* subject) {
        auto it = subscribedSubjects.begin();
        while (it != subscribedSubjects.end()) {
            if (*it == subject) {
                it = subscribedSubjects.erase(it);
                subject->detach(this);
            } else {
                ++it;
            }
        }
    }

    void update(const std::string& message, const Todo& item) override {
        std::cout << "Notifica: " << message << " - Titolo Todo: " << item.getTitle() << std::endl;
    }

    ~Notifier() {
        for (auto* subject : subscribedSubjects) {
            subject->detach(this);
        }
    }
};

#endif //TODOLIST_NOTIFIER_H
