#include <gtest/gtest.h>
#include "../src/Pesel.hpp"

struct PeselTest : public ::testing::Test {
  Pesel emptyPesel{""};
  Pesel tooShortPesel{"0123456"};
  Pesel tooLongPesel{"01234567891011"};
  Pesel peselWithIncorrectMonth{"90990515836"};
  Pesel peselWithIncorrectDay{"90093215836"};
  Pesel peselWithCorrectMonth{"90090515836"};
  Pesel peselWithCorrectDay{"90090515836"};
  Pesel peselWithMaleGender{"90090515836"};
  Pesel peselWithFemaleGender{"92071314764"};
  Pesel peselWithCorrectControlSum{"90090515836"};
  Pesel peselWithUncorrectControlSum{"90090515837"};
};

TEST_F(PeselTest, EmptyPeselIsNotValid) {
  ASSERT_EQ(false, emptyPesel.validate(emptyPesel.getPesel(), Gender::Male));
}

TEST_F(PeselTest, TooShortOrTooLongPeselIsNotValid) {
  ASSERT_EQ(false,
            tooShortPesel.validate(tooShortPesel.getPesel(), Gender::Female));
  ASSERT_EQ(false,
            tooShortPesel.validate(tooLongPesel.getPesel(), Gender::Male));
}

TEST_F(PeselTest, PeselWithIncorrectValuesOfDayAndMonthIsNotValid) {
  ASSERT_EQ(false, peselWithIncorrectMonth.validate(
                       peselWithIncorrectMonth.getPesel(), Gender::Male));
  ASSERT_EQ(false, peselWithIncorrectDay.validate(
                       peselWithIncorrectDay.getPesel(), Gender::Male));
  ASSERT_EQ(true, peselWithCorrectMonth.validate(
                      peselWithCorrectMonth.getPesel(), Gender::Male));
  ASSERT_EQ(true, peselWithCorrectDay.validate(peselWithCorrectDay.getPesel(),
                                               Gender::Male));
}

TEST_F(PeselTest, CheckThatNumberForGivenGenderIsValid) {
  ASSERT_EQ(true, peselWithMaleGender.validate(peselWithMaleGender.getPesel(),
                                               Gender::Male));
  ASSERT_EQ(true, peselWithFemaleGender.validate(
                      peselWithFemaleGender.getPesel(), Gender::Female));
}

TEST_F(PeselTest, CheckThatControlSumOfPeselIsValid) {
  ASSERT_EQ(true, peselWithCorrectControlSum.validate(
                      peselWithCorrectControlSum.getPesel(), Gender::Male));
  ASSERT_EQ(false, peselWithUncorrectControlSum.validate(
                       peselWithUncorrectControlSum.getPesel(), Gender::Male));
}
