#include "Database.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
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

ErrorCode Database::searchByPesel(const Pesel& pesel) {
  auto searchResult =
      std::find_if(students_.cbegin(), students_.cend(),
                   [&pesel](const auto& el) { return pesel.getPesel() == el.getPesel(); });
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

void Database::sortByLastName() {
  std::sort(students_.begin(), students_.end(),
            [](const auto& lhs, const auto& rhs) {
              return lhs.getLastName() < rhs.getLastName();
            });
}

ErrorCode Database::deleteByIndexNumber(int index) {
  constexpr int expectedRemovedElements = 1;
  auto removedElements = std::erase_if(students_, [&index](const auto& el) {
    return index == el.getIndexNumber();
  });
  return removedElements == expectedRemovedElements ? ErrorCode::RecordDeleted
                                                    : ErrorCode::RecordNotFound;
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

Json Database::getJsonData() const {
  Json jsonData;
  std::transform(students_.cbegin(), students_.cend(),
                 std::back_inserter(jsonData),
                 [](const Student& student) { return student.toJson(); });
  return jsonData;
}

void Database::saveToFile(const std::string& fileName) {
  std::ofstream file(fileName);
  Json studentsJson = getJsonData();
  file << studentsJson.dump(4);
}

void Database::readFromFile(const std::string& fileName) {
  std::fstream file(fileName);
  Json jsonData = Json::parse(file);
  std::transform(jsonData.cbegin(), jsonData.cend(),
                 std::back_inserter(students_),
                 [](const auto& data) { return Student::fromJson(data); });
}
