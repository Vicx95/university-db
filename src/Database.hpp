#pragma once

#include <vector>
#include "Student.hpp"

enum class ErrorCode {
  Success,
  StudentAlreadyExist,
  RecordFound,
  RecordNotFound
};

class Database {
 public:
  ErrorCode add(const Student& s);
  void display() const;
  std::string show() const;
  ErrorCode searchByLastName(const std::string& lastName);
  ErrorCode searchByPesel(const std::string& pesel);
  void sortByPesel();
  void sortByLastName();
  std::vector<Student> getData() const;

 private:
  bool isStudentExist(const Student& student);
  std::vector<Student> students_;
};