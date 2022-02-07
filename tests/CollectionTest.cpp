//
// Created by erika on 24/01/2022.
//

#include "gtest/gtest.h"
#include "../List.h"
#include "../Activity.h"
#include "../CollectionLists.h"

TEST(CollTest, countListTest) {
    CollectionLists principale;
    List a("Lista a");
    List b("Lista b");
    List c("Lista c");
    principale.addList(a);
    principale.addList(b);
    principale.addList(c);
    principale.printLists();
    EXPECT_EQ(principale.countLists(), 3);
}

TEST(CollTest, delListTitleTest) {
    CollectionLists principale;
    List a("Lista a");
    List b("Lista b");
    List c("Lista c");
    principale.addList(a);
    principale.addList(b);
    principale.addList(c);
    principale.deleteList("Lista b");
    principale.printLists();
    EXPECT_EQ(principale.countLists(), 2);
    EXPECT_THROW(principale.deleteList("Lista principale"), std::invalid_argument);

}

TEST(CollTest, editListTest) {
    CollectionLists principale;
    List a("Lista 1");
    List b("Lista 2");
    List c("Lista 3");
    principale.addList(a);
    principale.addList(b);
    principale.addList(c);
    principale.printLists();
    principale.editList("Lista 3", "Terza lista");
    principale.printLists();
    EXPECT_EQ(principale.getList(2).getTitle(), "Terza lista");
}

TEST(CollTest, moveActTest) {   // test per spostare un'attività da una lista all'altra
    CollectionLists principale;
    List a("Lista casa");
    List b("Lista università");
    Date d(7, Febbraio, 2022);
    Activity actOne("casa", d, true);
    Activity actTwo("uni", d, true);
    a.addActivity(actTwo);
    b.addActivity(actOne);
    a.listActivities();
    b.listActivities();
    principale.addList(a);
    principale.addList(b);
    principale.moveActivity("Lista casa", "Lista università", "uni");
    principale.moveActivity("Lista università", "Lista casa", "casa");
    a.listActivities();
    b.listActivities();
}
