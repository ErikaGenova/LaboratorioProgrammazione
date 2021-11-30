//
// Created by erika on 30/11/2021.
//

#include "gtest/gtest.h"
#include "../ListaMemo.h"
#include "../Promemoria.h"

TEST(MemoTest, ctorTest){
    Promemoria a("descrizione", "oggi", false);
    EXPECT_EQ(a.getDescription(), "descrizione");
    EXPECT_EQ(a.getDate(), "oggi");
    EXPECT_EQ(a.isUrgent(), false);
}