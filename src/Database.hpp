#pragma once

#include <filesystem>
#include <vector>
#include "Student.hpp"

enum class ErrorCode {
  Success,
  StudentAlreadyExist,
  RecordFound,
  RecordNotFound,
  RecordDeleted
};

class Database {
 public:
  ErrorCode add(const Student& s);
  void display() const;
  std::string show() const;
  ErrorCode searchByLastName(const std::string& lastName);
  ErrorCode searchByPesel(const Pesel& pesel);
  void sortByPesel();
  void sortByLastName();
  ErrorCode deleteByIndexNumber(int index);
  std::vector<Student> getData() const;
  Json getJsonData() const;
  void saveToFile(const std::string& fileName);
  void readFromFile(const std::string& fileName);

 private:
  bool isStudentExist(const Student& student);
  std::vector<Student> students_;
};
