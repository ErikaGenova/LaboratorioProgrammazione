//
// Created by erika on 30/11/2021.
//

#include "gtest/gtest.h"
#include "../List.h"
#include "../Activity.h"

TEST(MemoTest, ctorTest){
    Date d(01, Gennaio, 2020);
    Activity a("descrizione", d , false);
    EXPECT_EQ(a.getTitle(), "descrizione");
    EXPECT_EQ(a.getDate().toString(), "1/1/2020");
    EXPECT_EQ(a.isUrgent(), false);
}


TEST(MemoTest, setCompletedTest){
    Date d(01, Gennaio, 2020);
    Activity b("prova", d, true);
    EXPECT_EQ(b.isComplete(), false);
    b.setCompleted(true);
    EXPECT_EQ(b.isComplete(), true);
}