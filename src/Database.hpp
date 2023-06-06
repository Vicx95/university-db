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

 private:
  bool isStudentExist(const Student& student);
  std::vector<Student> students_;
};