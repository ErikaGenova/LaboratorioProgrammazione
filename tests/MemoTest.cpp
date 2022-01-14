//
// Created by erika on 30/11/2021.
//

#include "gtest/gtest.h"
#include "../List.h"
#include "../Activity.h"

TEST(MemoTest, ctorTest){
    Activity a("descrizione", "oggi", false);
    EXPECT_EQ(a.getTitle(), "descrizione");
    EXPECT_EQ(a.getDate(), "oggi");
    EXPECT_EQ(a.isUrgent(), false);
}

TEST(MemoTest, getDescriptionTest){
    Activity b("prova", "domani", false);
    EXPECT_EQ(b.getDescription(), "prova,domani,non urgente");
}