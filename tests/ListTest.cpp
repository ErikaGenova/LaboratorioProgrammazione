//
// Created by erika on 28/11/2021.
//

#include "gtest/gtest.h"
#include "../List.h"
#include "../Activity.h"

TEST(Lista, testAddActivity){
    List test("provaLista");
    Activity a("prova","oggi", true);
    test.addActivity(a);
    EXPECT_EQ(test.countActivities(),1);

}


TEST(Lista, testRemoveActivity){
    List test("prova");
    Activity a("prova", "settimana", false);
    test.addActivity(a);
    test.removeActivity(0);
    EXPECT_EQ(test.countActivities(), 0);
}

TEST(Lista, testListActivities){
    List test("prova");
    Activity b("uno", "domani", true);
    Activity c("due", "oggi", true);
    Activity d("tre", "lunedì", false);
    test.addActivity(b);
    test.addActivity(c);
    test.addActivity(d);
    EXPECT_EQ(test.listActivities(), 3);
}

