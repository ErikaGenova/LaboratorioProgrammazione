//
// Created by erika on 24/01/2022.
//

#include "gtest/gtest.h"
#include "../List.h"
#include "../Activity.h"
#include "../CollectionLists.h"

TEST(CollTest, countListTest){
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

TEST(CollTest, delListTitleTest){
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

   // principale.deleteList("Lista principale");
    //TODO come faccio a fare passare il test con l'errore? Voglio che sia corretto che dia errore quando la lista non esiste
}

TEST(CollTest, editListTest){
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
  //  EXPECT_EQ(principale.getList(2), "Terza lista");
}