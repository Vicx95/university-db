#include "Student.hpp"

Student::Student(std::string name,
                 std::string lastName,
                 std::string address,
                 int indexNumber,
                 std::string pesel,
                 Gender gender)
    : name_(name),
      lastName_(lastName),
      address_(address),
      indexNumber_(indexNumber),
      pesel_(pesel),
      gender_(gender) {}

std::string Student::show() const {
  return name_ + " " + lastName_ + "; " + address_ + "; " +
         std::to_string(indexNumber_) + "; " + pesel_ + "; " +
         convertGenderToString(gender_);
}

std::string Student::getLastName() const {
  return lastName_;
}

std::string Student::getPesel() const {
  return pesel_;
}

int Student::getIndexNumber() const {
  return indexNumber_;
}

bool Student::operator==(const Student& other) const {
  return name_ == other.name_ && lastName_ == other.lastName_ &&
         address_ == other.address_ && indexNumber_ == other.indexNumber_ &&
         pesel_ == other.pesel_ && gender_ == other.gender_;
}

std::string convertGenderToString(const Gender& gender) {
  switch (gender) {
    case Gender::Male:
      return "Male";
    case Gender::Female:
      return "Female";
    default:
      return "Unknown";
  }
}
