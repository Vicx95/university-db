#include <gtest/gtest.h>
#include "../src/PeselValidator.hpp"

struct PeselValidatorTest : public ::testing::Test {
  PeselValidator pv;
};

TEST_F(PeselValidatorTest, EmptyPeselIsNotValid) {
  std::string emptyPesel{""};
  ASSERT_EQ(false, pv.validate(emptyPesel, Gender::Male));
}

TEST_F(PeselValidatorTest, TooShortOrTooLongPeselIsNotValid) {
  std::string tooShortPesel{"0123456"};
  std::string tooLongPesel{"01234567891011"};
  ASSERT_EQ(false, pv.validate(tooShortPesel, Gender::Female));
  ASSERT_EQ(false, pv.validate(tooLongPesel, Gender::Male));
}

TEST_F(PeselValidatorTest, PeselWithIncorrectValuesOfDayAndMonthIsNotValid) {
  std::string peselWithIncorrectMonth{"90990515836"};
  std::string peselWithIncorrectDay{"90093215836"};
  std::string peselWithCorrectMonth{"90090515836"};
  std::string peselWithCorrectDay{"90090515836"};

  ASSERT_EQ(false, pv.validate(peselWithIncorrectMonth, Gender::Male));
  ASSERT_EQ(false, pv.validate(peselWithIncorrectDay, Gender::Male));
  ASSERT_EQ(true, pv.validate(peselWithCorrectMonth, Gender::Male));
  ASSERT_EQ(true, pv.validate(peselWithCorrectDay, Gender::Male));
}

TEST_F(PeselValidatorTest, CheckThatNumberForGivenGenderIsValid) {
  std::string peselWithMaleGender{"90090515836"};
  std::string peselWithFemaleGender{"92071314764"};
  ASSERT_EQ(true, pv.validate(peselWithMaleGender, Gender::Male));
  ASSERT_EQ(true, pv.validate(peselWithFemaleGender, Gender::Female));
}

TEST_F(PeselValidatorTest, CheckThatControlSumOfPeselIsValid) {
  std::string peselWithCorrectControlSum{"90090515836"};
  std::string peselWithUncorrectControlSum{"90090515837"};
  ASSERT_EQ(true, pv.validate(peselWithCorrectControlSum, Gender::Male));
  ASSERT_EQ(false, pv.validate(peselWithUncorrectControlSum, Gender::Male));
}
