//
// Created by erika on 25/01/2022.
//

#include "gtest/gtest.h"
#include "../List.h"
#include "../Activity.h"
#include "../CollectionLists.h"

TEST(Data, setDayTest) {
    Date d;
    Date e(5, Febbraio, 1970);
    Date f;
    Date g(2, Marzo, 2020);

    d.setDay(4);
    e.setDay(12);
    f.setDay(25);
    EXPECT_EQ((d.getDay()), 4);
    EXPECT_EQ((e.getDay()), 12);
    EXPECT_EQ((f.getDay()), 25);


    EXPECT_THROW(g.setDay(45), std::out_of_range);
}


TEST(Data, setYearTest) {
    Date d;
    Date e(5, Febbraio, 1970);
    Date f;
    Date g(2, Marzo, 2020);

    d.setYear(2013);
    e.setYear(1988);
    f.setYear(2000);
    EXPECT_EQ((d.getYear()), 2013);
    EXPECT_EQ((e.getYear()), 1988);
    EXPECT_EQ(f.getYear(), 2000);

    EXPECT_THROW(g.setYear(1800), std::out_of_range);
}

TEST(Data, setMonthTest){
    Date d;
    Date e(31, Gennaio, 1970);
    Date f(30, Marzo, 2020);

    d.setMonth(Luglio);
    EXPECT_EQ(d.getMonth(), Luglio);
    EXPECT_THROW(e.setMonth(Novembre), std::out_of_range);
    EXPECT_THROW(f.setMonth(Febbraio), std::out_of_range);

}
