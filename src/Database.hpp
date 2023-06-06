#pragma once

#include <vector>
#include "Student.hpp"

enum class ErrorCode {
  Success,
  StudentAlreadyExist
};

class Database {
 public:
  ErrorCode add(const Student& s);
  void display() const;
  std::string show() const;

 private:
  bool isStudentExist(const Student& student);
  std::vector<Student> students_;
};