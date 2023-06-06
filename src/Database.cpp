#include "Database.hpp"
#include <iostream>
#include <ranges>

ErrorCode Database::add(const Student& s) {
  if (!isStudentExist(s)) {
    students_.push_back(s);
    return ErrorCode::Success;
  }
  return ErrorCode::StudentAlreadyExist;
}

void Database::display() const {
  std::cout << show();
}

std::string Database::show() const {
  std::string result = "";
  for (auto&& student : students_) {
    result += student.show();
  }
  return result;
}

bool Database::isStudentExist(const Student& student) {
  return std::find(students_.begin(), students_.end(), student) !=
                 students_.end()
             ? true
             : false;
}