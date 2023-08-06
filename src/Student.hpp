#pragma once
#include <string>
#include "../external/json.hpp"

enum class Gender { Male, Female };

std::string convertGenderToString(const Gender& gender);
Gender convertStringToGender(const std::string& gender);
using Json = nlohmann::json;

class Student {
 public:
  Student(std::string name,
          std::string lastName,
          std::string address,
          int indexNumber,
          std::string pesel,
          Gender gender);
  std::string show() const;
  std::string getLastName() const;
  std::string getPesel() const;
  int getIndexNumber() const;
  Json toJson() const;
  static Student fromJson(const Json& data);
  bool operator==(const Student& other) const;

 private:
  std::string name_;
  std::string lastName_;
  std::string address_;
  int indexNumber_;
  std::string pesel_;
  Gender gender_;
};
