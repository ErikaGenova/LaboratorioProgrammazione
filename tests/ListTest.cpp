//
// Created by erika on 28/11/2021.
//

#include "gtest/gtest.h"
#include "../List.h"
#include "../Activity.h"

TEST(Lista, testAddActivity){
    Date d(01, Gennaio, 2020);
    List test("provaLista");
    Activity a("prova",d, true);
    Activity b("provaB", d, true);
    Activity c("provaC", d, false);
    test.addActivity(a);
    test.addActivity(b);
    test.addActivity(c);
    EXPECT_EQ(test.countActivities(),3);
}


TEST(Lista, testRemoveActivity){
    Date d(01, Gennaio, 2020);

    List test("prova");
    Activity a("prova", d, false);
    Activity b("provaB", d, true);
    Activity c("provaC", d, false);

    test.addActivity(a);
    test.addActivity(b);
    test.addActivity(c);
    test.removeActivity(0);
    EXPECT_EQ(test.countActivities(), 2);
    test.removeActivity(1);
    EXPECT_EQ(test.countActivities(), 1);
}

TEST(Lista, testListActivities){
    Date d(01, Gennaio, 2020);

    List test("prova");
    Activity b("uno", d, true);
    Activity c("due", d, true);
    Activity e("tre", d, false);
    test.addActivity(b);
    test.addActivity(c);
    test.addActivity(e);
    EXPECT_EQ(test.listActivities(), 3);
}

TEST(Lista, findActivityTest){
    Date d(01, Gennaio, 2020);

    List test("Test");
    Activity a("prova1", d, false);
    Activity b("prova2", d, true);
    Activity c("prova3", d, true);
    test.addActivity(a);
    test.addActivity(b);
    test.addActivity(c);
    EXPECT_EQ(test.findActivity("prova3"), true);
    EXPECT_THROW(test.findActivity("attività"), std::invalid_argument);

}

TEST(Lista, howManyUrgentTest){
    Date d(01, Gennaio, 2020);

    List test("Prova");
    Activity a("prova 1", d, false);
    Activity b("prova 2", d, true);
    Activity c("prova 3", d, true);
    test.addActivity(a);
    test.addActivity(b);
    test.addActivity(c);
    EXPECT_EQ(test.howManyUrgent(), 2);

    test.editActivity(0, "Primo promemoria", d, true, false);
    EXPECT_EQ(test.howManyUrgent(), 3);

}

TEST(Lista, howManyCompletedTest){
    Date d(01, Gennaio, 2020);

    List test("Prova");
    Activity a("prova 1", d, false);
    Activity b("prova 2", d, false);
    Activity c("prova 3", d, true);
    test.addActivity(a);
    test.addActivity(b);
    test.addActivity(c);
    EXPECT_EQ(test.howManyCompleted(), 0);

    test.editActivity(0, "prova 1", d, false, true);
    test.editActivity(1, "prova 2", d, false, true);


    EXPECT_EQ(test.howManyCompleted(), 2);

}
