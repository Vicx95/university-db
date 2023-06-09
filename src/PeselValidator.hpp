#pragma once
#include "Student.hpp"

class PeselValidator {
 public:
  bool validate(const std::string& pesel, Gender gender);

 private:
  bool isPeselLengthValid(const std::string& pesel);
  bool isMonthFromPeselValid(const std::string& pesel);
  bool isDayFromPeselValid(const std::string& pesel);
  bool isGenderValid(const std::string& pesel, Gender gender);
  bool isCheckSumValid(const std::string& pesel);
};