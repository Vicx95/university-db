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

Json Student::toJson() const {
  Json studentJson =
      Json{{"name", name_},       {"lastName", lastName_},
           {"address", address_}, {"indexNumber", indexNumber_},
           {"pesel", pesel_},     {"gender", convertGenderToString(gender_)}};
  return studentJson;
}

Student Student::fromJson(const Json& data) {
  return Student{data["name"],    data["lastName"],
                 data["address"], data["indexNumber"],
                 data["pesel"],   convertStringToGender(data["gender"])};
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

Gender convertStringToGender(const std::string& gender) {
  if (gender == "Male") {
    return Gender::Male;
  }
  return Gender::Female;
}
