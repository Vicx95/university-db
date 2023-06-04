#include <gtest/gtest.h>
#include "../src/Database.hpp"

TEST(CheckStructure, CanAddStudentToDb) {
    Student adam{"Adam", "Kowalski", "ul. Dobra 134, 00-200 Warszawa", 123456, "11223344567", Gender::Male};

    Database db;
    EXPECT_TRUE(db.add(adam));
    EXPECT_FALSE(db.add(adam));
}

TEST(DisplayDb, DisplayEmptyDb) {
    Database db;
    auto content = db.show();
    auto expected = "";
    EXPECT_EQ(content, expected);
    db.display();
}