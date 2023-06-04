#pragma once

#include "Student.hpp"

class Database {
public:
    bool add(const Student& s);

private:
    bool isAdded_ = false;
};