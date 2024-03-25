//
// Created by Fede & Isa on 06/03/24.
//

#ifndef TODOLIST_TODO_H
#define TODOLIST_TODO_H

#include <string>

class Todo {
private:
    std::string date;
    std::string title;
    std::string description;
    bool isCompleted = false;
public:
    explicit Todo(const std::string &title, const std::string &description = "", const std::string &date="" ,const bool isCompleted= false): date(date), title(title), description(description) , isCompleted(isCompleted){}

    // Getters
    std::string getTitle() const { return title; }
    std::string getDescription() const { return description; }
    std::string getDate() const { return date; }
    bool getIsCompleted() const { return isCompleted; }

    // Setters
    void setTitle(const std::string &newTitle) { title = newTitle; }
    void setDescription(const std::string &newDescription) { description = newDescription; }
    void setDate(const std::string &newDate) { date = newDate; }
    void setIsCompleted(bool completed) { isCompleted = completed; }

};


#endif //TODOLIST_TODO_H
