//
// Created by erika on 28/11/2021.
//

#include "gtest/gtest.h"
#include "../ListaMemo.h"
#include "../Promemoria.h"

TEST(Lista, testAddActivity){
    ListaMemo test("provaLista");
    Promemoria a("prova","oggi", true);
    test.addActivity(&a);
    EXPECT_EQ(test.countActivities(),1);

}

TEST(Lista, testRemoveActivity){
    ListaMemo test("prova");
    Promemoria a("prova", "settimana", false);
    test.addActivity(&a);
    test.removeActivity(&a);
    EXPECT_EQ(0, 0);
}

