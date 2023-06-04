#pragma once

#include "Student.hpp"
#include <vector>

class Database {
public:
    void add(const Student& s);
    void display() const;
    std::string show() const;

private:
    std::vector<Student> students_;
};