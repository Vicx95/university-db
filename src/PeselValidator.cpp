#include "PeselValidator.hpp"
#include <array>
#include <iostream>
#include <numeric>
#include "Student.hpp"

bool PeselValidator::validate(const std::string& pesel, Gender gender) {
  if (!isPeselLengthValid(pesel)) {
    return false;
  }
  if (!isMonthFromPeselValid(pesel)) {
    return false;
  }
  if (!isDayFromPeselValid(pesel)) {
    return false;
  }
  if (!isGenderValid(pesel, gender)) {
    return false;
  }
  if (!isCheckSumValid(pesel)) {
    return false;
  }

  return true;
}

bool PeselValidator::isPeselLengthValid(const std::string& pesel) {
  constexpr size_t validPeselLength = 11;
  return pesel.length() != validPeselLength ? false : true;
}

bool PeselValidator::isMonthFromPeselValid(const std::string& pesel) {
  auto month = std::stoi(pesel.substr(2, 2));
  constexpr std::array<int, 4> numbersAddedToMonth{80, 20, 40, 60};
  auto isMonthValid =
      std::any_of(numbersAddedToMonth.begin(), numbersAddedToMonth.end(),
                  [month](const auto& el) {
                    return month % el < 1 || month % el <= 12;
                  }) ||
      (month > 0 && month <= 12);
  return isMonthValid;
}

bool PeselValidator::isDayFromPeselValid(const std::string& pesel) {
  if (auto day = std::stoi(pesel.substr(4, 2)); day < 1 || day > 31) {
    return false;
  }
  return true;
}

bool PeselValidator::isGenderValid(const std::string& pesel, Gender gender) {
  constexpr size_t genderNumberPosition = 9;
  auto genderNumber = pesel[genderNumberPosition] - '0';
  return (gender == Gender::Male && genderNumber % 2 != 0) ||
         (gender == Gender::Female && genderNumber % 2 == 0);
}

bool PeselValidator::isCheckSumValid(const std::string& pesel) {
  constexpr std::array<size_t, 10> weights{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
  std::array<size_t, 10> peselNumber{};
  for (size_t i = 0; i < pesel.size(); i++) {
    peselNumber[i] = pesel[i] - '0';
  }

  auto checkSum = std::inner_product(peselNumber.begin(), peselNumber.end(),
                                     weights.begin(), 0);

  auto expectedLastNumber = (checkSum % 10) == 0 ? 0 : 10 - (checkSum % 10);
  auto lastNumberFromPesel = pesel[10] - '0';
  return lastNumberFromPesel == expectedLastNumber;
}