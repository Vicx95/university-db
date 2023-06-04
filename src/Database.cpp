#include "Database.hpp"

bool Database::add(const Student& s) {
    if (isAdded_) {
        return false;
    } else {
        isAdded_ = true;
        return true;
    }
}