#include <gtest/gtest.h>
#include "../src/Database.hpp"

struct DatabaseTest : ::testing::Test {
  Database db;
};

TEST_F(DatabaseTest, DisplayEmptyDb) {
  auto content = db.show();
  auto expected = "";
  EXPECT_EQ(content, expected);
  db.display();
}

TEST_F(DatabaseTest, DisplayNonEmptyDb) {
  Student adam{"Adam", "Kowalski",    "ul. Dobra 134, 00-200 Warszawa",
               123456, "11223344567", Gender::Male};
  Student beata{"Beata", "Kowalska",    "ul.Gwiazdzista 24, 10-200, Warszawa",
                444,     "11223344564", Gender::Female};
  db.add(adam);
  db.add(beata);
  auto content = db.show();
  std::string expected =
      "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; "
      "Male";
  expected +=
      "Beata Kowalska; ul.Gwiazdzista 24, 10-200, Warszawa; 444; 11223344564; "
      "Female";
  EXPECT_EQ(content, expected);
}