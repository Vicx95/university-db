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

ErrorCode Database::searchByLastName(const std::string& lastName) {
  auto searchResult = std::find_if(
      students_.cbegin(), students_.cend(),
      [&lastName](const auto& el) { return lastName == el.getLastName(); });
  if (searchResult != students_.cend()) {
    std::cout << searchResult->show() << '\n';
    return ErrorCode::RecordFound;
  }
  return ErrorCode::RecordNotFound;
}

ErrorCode Database::searchByPesel(const std::string& pesel) {
  auto searchResult =
      std::find_if(students_.cbegin(), students_.cend(),
                   [&pesel](const auto& el) { return pesel == el.getPesel(); });
  if (searchResult != students_.cend()) {
    std::cout << searchResult->show() << '\n';
    return ErrorCode::RecordFound;
  }
  return ErrorCode::RecordNotFound;
}

void Database::sortByPesel() {
  std::sort(students_.begin(), students_.end(),
            [](const auto& lhs, const auto& rhs) {
              return std::stoul(lhs.getPesel()) < std::stoul(rhs.getPesel());
            });
}

std::vector<Student> Database::getData() const {
  return students_;
}

bool Database::isStudentExist(const Student& student) {
  return std::find(students_.begin(), students_.end(), student) !=
                 students_.end()
             ? true
             : false;
}