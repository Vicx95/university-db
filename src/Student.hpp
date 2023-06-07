#pragma once
#include <string>

enum class Gender { Male, Female };

std::string convertGenderToString(const Gender& gender);

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

  bool operator==(const Student& other) const;

 private:
  std::string name_;
  std::string lastName_;
  std::string address_;
  int indexNumber_;
  std::string pesel_;
  Gender gender_;
};