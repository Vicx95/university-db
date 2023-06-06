#include <gtest/gtest.h>
#include "../src/Database.hpp"

struct DatabaseTest : ::testing::Test {
  Database db;
  Database emptyDb;

  void SetUp() override {
    Student adam{"Adam", "Kowalski",    "ul. Dobra 134, 00-200 Warszawa",
                 123456, "11223344567", Gender::Male};
    Student beata{"Beata", "Kowalska",    "ul.Gwiazdzista 24, 10-200, Warszawa",
                  444,     "11223344564", Gender::Female};

    db.add(adam);
    db.add(beata);
  }
};

TEST_F(DatabaseTest, DisplayEmptyDb) {
  auto content = emptyDb.show();
  auto expected = "";
  EXPECT_EQ(content, expected);
  emptyDb.display();
}

TEST_F(DatabaseTest, DisplayNonEmptyDb) {
  auto content = db.show();
  std::string expected =
      "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; "
      "Male";
  expected +=
      "Beata Kowalska; ul.Gwiazdzista 24, 10-200, Warszawa; 444; 11223344564; "
      "Female";
  EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, AddOnlyNonDuplicatedStudentToDb) {
  Student jaroslaw{"Jaroslaw", "Nowakowski",  "ul.Wolna 24, 30-200, Warszawa",
                   444,        "11223344569", Gender::Male};
  EXPECT_EQ(ErrorCode::Success, db.add(jaroslaw));
  EXPECT_EQ(ErrorCode::StudentAlreadyExist, db.add(jaroslaw));
}

TEST_F(DatabaseTest, SearchBySurnameTest) {
  EXPECT_EQ(ErrorCode::RecordFound, db.searchByLastName("Kowalska"));
  EXPECT_EQ(ErrorCode::RecordNotFound, db.searchByLastName("Nowak"));
}

TEST_F(DatabaseTest, SearchByPeselTest) {
  EXPECT_EQ(ErrorCode::RecordFound, db.searchByPesel("11223344567"));
  EXPECT_EQ(ErrorCode::RecordNotFound, db.searchByPesel("11223344111"));
}