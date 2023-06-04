#include <gtest/gtest.h>
#include "../src/Database.hpp"

struct DatabaseTest : ::testing::Test {
    Database db;
};

TEST_F(DatabaseTest, CanAddStudentToDb) {
    Student adam{"Adam", "Kowalski", "ul. Dobra 134, 00-200 Warszawa", 123456, "11223344567", Gender::Male};
    EXPECT_TRUE(db.add(adam));
    EXPECT_FALSE(db.add(adam));
}

TEST_F(DatabaseTest, DisplayEmptyDb) {
    auto content = db.show();
    auto expected = "";
    EXPECT_EQ(content, expected);
    db.display();
}