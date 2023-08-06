#pragma once
#include "../external/json.hpp"

enum class Gender { Male, Female };
using Json = nlohmann::json;

class Pesel {
 public:
  Pesel(std::string pesel);
  bool validate(const std::string& pesel, Gender gender);
  std::string getPesel() const;
  Json toJson() const;
  static Pesel fromJson(const Json& data);

 private:
  bool isPeselLengthValid(const std::string& pesel);
  bool isMonthFromPeselValid(const std::string& pesel);
  bool isDayFromPeselValid(const std::string& pesel);
  bool isGenderValid(const std::string& pesel, Gender gender);
  bool isCheckSumValid(const std::string& pesel);
  std::string pesel_;
};
