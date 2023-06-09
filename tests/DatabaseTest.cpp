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
    Student konrad{"Konrad", "Berek",       "ul.Norweska 50, 55-600, Wroclaw",
                   9876,     "11245344564", Gender::Male};
    Student iwona{"Iwona", "Syntezator",  "ul.Krakowska 30, 55-500, Wroclaw",
                  9873,    "76345344564", Gender::Female};

    db.add(adam);
    db.add(beata);
    db.add(konrad);
    db.add(iwona);
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
  expected +=
      "Konrad Berek; ul.Norweska 50, 55-600, Wroclaw; 9876; 11245344564; "
      "Male";
  expected +=
      "Iwona Syntezator; ul.Krakowska 30, 55-500, Wroclaw; 9873; 76345344564; "
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

TEST_F(DatabaseTest, SortingByPeselTest) {
  std::vector<Student> expectedOutput{
      {"Beata", "Kowalska", "ul.Gwiazdzista 24, 10-200, Warszawa", 444,
       "11223344564", Gender::Female},
      {"Adam", "Kowalski", "ul. Dobra 134, 00-200 Warszawa", 123456,
       "11223344567", Gender::Male},
      {"Konrad", "Berek", "ul.Norweska 50, 55-600, Wroclaw", 9876,
       "11245344564", Gender::Male},
      {"Iwona", "Syntezator", "ul.Krakowska 30, 55-500, Wroclaw", 9873,
       "76345344564", Gender::Female}};
  db.sortByPesel();
  auto data = db.getData();
  ASSERT_EQ(data, expectedOutput);
}

TEST_F(DatabaseTest, SortingByLastNameTest) {
  std::vector<Student> expectedOutput{
      {"Konrad", "Berek", "ul.Norweska 50, 55-600, Wroclaw", 9876,
       "11245344564", Gender::Male},
      {"Beata", "Kowalska", "ul.Gwiazdzista 24, 10-200, Warszawa", 444,
       "11223344564", Gender::Female},
      {"Adam", "Kowalski", "ul. Dobra 134, 00-200 Warszawa", 123456,
       "11223344567", Gender::Male},
      {"Iwona", "Syntezator", "ul.Krakowska 30, 55-500, Wroclaw", 9873,
       "76345344564", Gender::Female}};
  db.sortByLastName();
  auto data = db.getData();
  ASSERT_EQ(data, expectedOutput);
}

TEST_F(DatabaseTest, DeletingByIndexNumberTest) {
  std::vector<Student> expectedOutput{
      {"Adam", "Kowalski", "ul. Dobra 134, 00-200 Warszawa", 123456,
       "11223344567", Gender::Male},
      {"Iwona", "Syntezator", "ul.Krakowska 30, 55-500, Wroclaw", 9873,
       "76345344564", Gender::Female}};

  ASSERT_EQ(ErrorCode::RecordDeleted, db.deleteByIndexNumber(444));
  ASSERT_EQ(ErrorCode::RecordDeleted, db.deleteByIndexNumber(9876));
  ASSERT_EQ(ErrorCode::RecordNotFound, db.deleteByIndexNumber(455));
  auto data = db.getData();
  ASSERT_EQ(data, expectedOutput);
}