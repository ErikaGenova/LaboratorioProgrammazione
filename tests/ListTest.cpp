//
// Created by erika on 28/11/2021.
//

#include "gtest/gtest.h"
#include "../List.h"
#include "../Activity.h"

TEST(Lista, testAddActivity){
    List test("provaLista");
    Activity a("prova","oggi", true);
    test.addActivity(&a);
    EXPECT_EQ(test.countActivities(),1);

}

TEST(Lista, testRemoveActivity){
    List test("prova");
    Activity a("prova", "settimana", false);
    test.addActivity(&a);
    test.removeActivity(&a);
    EXPECT_EQ(0, 0);
}

