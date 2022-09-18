#include "libminimal/intermediate/data_container/spreadsheet/spreadsheet.h"
#include "libminimal/intermediate/data_container/spreadsheet/select.h"
#include <gtest/gtest.h>

TEST(Select_Contains, NormalInput) {
std::stringstream ss;
std::string xp;
Spreadsheet sheet;

sheet.set_column_names({"First","Last"});
sheet.add_row({"Ash","Ketchum"});
sheet.add_row({"Brock","Harrison"});
sheet.add_row({"Misty","Williams"});
sheet.add_row({"Gary","Oak"});

sheet.set_selection(new Select_Contains(&sheet,"Last","Harrison"));
sheet.print_selection(ss);
xp = "Brock Harrison \n";

EXPECT_EQ(ss.str(),xp);

}
TEST(Select_Contains, SimilarInput){
std::stringstream ss;
std::string xp;
Spreadsheet sheet;

sheet.set_column_names({"First", "Last"});
sheet.add_row({"Ash","Ketchum"});
sheet.add_row({"Brock","Harrison"});
sheet.add_row({"Misty","Williams"});
sheet.add_row({"Gary","Oak"});

sheet.set_selection(new Select_Contains(&sheet,"Last","Haris"));
sheet.print_selection(ss);
xp = "";

EXPECT_EQ(ss.str(),xp);

}
TEST(Select_Contains, SimilarUpperCase){
std::stringstream ss;
std::string xp;
Spreadsheet sheet;

sheet.set_column_names({"First", "Last"});
sheet.add_row({"Ash","Ketchum"});
sheet.add_row({"Brock","Harrison"});
sheet.add_row({"Misty","Williams"});
sheet.add_row({"Gary","Oak"});

sheet.set_selection(new Select_Contains(&sheet,"Last","HarrisoN"));
sheet.print_selection(ss);
xp = "";

EXPECT_EQ(ss.str(),xp);

}
TEST(Select_Contains, EmptyInput){
std::stringstream ss;
std::string xp;
Spreadsheet sheet;

sheet.set_column_names({"First", "Last"});
sheet.add_row({"Ash","Ketchum"});
sheet.add_row({"Brock","Harrison"});
sheet.add_row({"Misty","Williams"});
sheet.add_row({"Gary","Oak"});

sheet.set_selection(new Select_Contains(&sheet,"Last",""));
sheet.print_selection(ss);
xp = "";

EXPECT_EQ("",xp);

}



TEST(Select_And, basicTest){
std::stringstream ss;
std::string expS;

Spreadsheet sheet;

sheet.set_column_names({"slimmy"});
sheet.add_row({"flippity"});
sheet.add_row({"dippity"});
sheet.add_row({"hippity"});
sheet.add_row({"hoppity"});

sheet.set_selection(new Select_And(new Select_Contains(&sheet,"slimmy","ipp"),new Select_Contains(&sheet,"slimmy","ity")));
sheet.print_selection(ss);
expS = "flippity \ndippity \nhippity \n";

EXPECT_EQ(ss.str(), expS);

}
TEST(Select_And, SimilarTest){
std::stringstream ss;
std::string expS;

Spreadsheet sheet;

sheet.set_column_names({"slimmy"});
sheet.add_row({"flippity"});
sheet.add_row({"dippity"});
sheet.add_row({"hippity"});
sheet.add_row({"hoppity"});

sheet.set_selection(new Select_And(new Select_Contains(&sheet,"slimmy","ipp"),new Select_Contains(&sheet,"slimmy","itY")));
sheet.print_selection(ss);
expS = "";

EXPECT_EQ(ss.str(), expS);

}
TEST(Select_And, OneInvalidInput){
std::stringstream ss;
std::string expS;

Spreadsheet sheet;

sheet.set_column_names({"slimmy"});
sheet.add_row({"flippity"});
sheet.add_row({"dippity"});
sheet.add_row({"hippity"});
sheet.add_row({"hoppity"});

sheet.set_selection(new Select_And(new Select_Contains(&sheet,"slimmy","ipp"),new Select_Contains(&sheet,"slimmy","itasy")));
sheet.print_selection(ss);
expS = "";

EXPECT_EQ(ss.str(), expS);

}
TEST(Select_And, TwoInvalidInput){
std::stringstream ss;
std::string expS;

Spreadsheet sheet;

sheet.set_column_names({"slimmy"});
sheet.add_row({"flippity"});
sheet.add_row({"dippity"});
sheet.add_row({"hippity"});
sheet.add_row({"hoppity"});

sheet.set_selection(new Select_And(new Select_Contains(&sheet,"slimmy","pa"),new Select_Contains(&sheet,"slimmy","")));
sheet.print_selection(ss);
expS = "";

EXPECT_EQ(ss.str(), expS);

}



TEST(Select_Not, RegularInput){
std::stringstream ss;
std::string expS;

Spreadsheet sheet;

sheet.set_column_names({"slimmy"});
sheet.add_row({"flippity"});
sheet.add_row({"dippity"});
sheet.add_row({"hippity"});
sheet.add_row({"hoppity"});

sheet.set_selection(new Select_Not(new Select_Contains(&sheet,"slimmy","dip")));
sheet.print_selection(ss);
expS = "flippity \nhippity \nhoppity \n";

EXPECT_EQ(ss.str(), expS);

}
TEST(Select_Not, SelectAllInput){
std::stringstream ss;
std::string expS;

Spreadsheet sheet;

sheet.set_column_names({"slimmy"});
sheet.add_row({"flippity"});
sheet.add_row({"dippity"});
sheet.add_row({"hippity"});
sheet.add_row({"hoppity"});

sheet.set_selection(new Select_Not(new Select_Contains(&sheet,"slimmy","asdp")));
sheet.print_selection(ss);
expS = "flippity \ndippity \nhippity \nhoppity \n";

EXPECT_EQ(ss.str(), expS);

}
TEST(Select_Not, SelectNoneInput){
std::stringstream ss;
std::string expS;

Spreadsheet sheet;

sheet.set_column_names({"slimmy"});
sheet.add_row({"flippity"});
sheet.add_row({"dippity"});
sheet.add_row({"hippity"});
sheet.add_row({"hoppity"});

sheet.set_selection(new Select_Not(new Select_Contains(&sheet,"slimmy","p")));
sheet.print_selection(ss);
expS = "";

EXPECT_EQ(ss.str(), expS);

}
TEST(Select_Not, OtherSelectsInput){
std::stringstream ss;
std::string expS;

Spreadsheet sheet;

sheet.set_column_names({"slimmy"});
sheet.add_row({"flippity"});
sheet.add_row({"dippity"});
sheet.add_row({"hippity"});
sheet.add_row({"hoppity"});

sheet.set_selection(new Select_Not( Select_Not(new Select_Contains(&sheet,"slimmy","p"))));
sheet.print_selection(ss);
expS = "";

EXPECT_EQ(ss.str(), expS);

}



TEST(Select_Or, RegularInput){
std::stringstream ss;
std::string expS;

Spreadsheet sheet;

sheet.set_column_names({"slimmy"});
sheet.add_row({"flippity"});
sheet.add_row({"dippity"});
sheet.add_row({"hippity"});
sheet.add_row({"hoppity"});

sheet.set_selection(new Select_Or(new Select_Contains(&sheet,"slimmy","dip"), new Select_Contains(&sheet, "slimmy", "hop")));
sheet.print_selection(ss);
expS = "dippity \nhoppity \n";

EXPECT_EQ(ss.str(), expS);

}
TEST(Select_Or, AllInput){
std::stringstream ss;
std::string expS;

Spreadsheet sheet;

sheet.set_column_names({"slimmy"});
sheet.add_row({"flippity"});
sheet.add_row({"dippity"});
sheet.add_row({"hippity"});
sheet.add_row({"hoppity"});

sheet.set_selection(new Select_Or(new Select_Contains(&sheet,"slimmy","dip"), new Select_Contains(&sheet, "slimmy", "p")));
sheet.print_selection(ss);
expS = "flippity \ndippity \nhippity \nhoppity \n";

EXPECT_EQ(ss.str(), expS);

}
TEST(Select_Or, OneInput){
std::stringstream ss;
std::string expS;

Spreadsheet sheet;

sheet.set_column_names({"slimmy"});
sheet.add_row({"flippity"});
sheet.add_row({"dippity"});
sheet.add_row({"hippity"});
sheet.add_row({"hoppity"});

sheet.set_selection(new Select_Or(new Select_Contains(&sheet,"slimmy","dip"), new Select_Contains(&sheet, "slimmy", "sadsadas")));
sheet.print_selection(ss);
expS = "dippity \n";

EXPECT_EQ(ss.str(), expS);

}
TEST(Select_Or, EmptyInput){
std::stringstream ss;
std::string expS;

Spreadsheet sheet;

sheet.set_column_names({"slimmy"});
sheet.add_row({"flippity"});
sheet.add_row({"dippity"});
sheet.add_row({"hippity"});
sheet.add_row({"hoppity"});

sheet.set_selection(new Select_Or(new Select_Contains(&sheet,"slimmy","assd"), new Select_Contains(&sheet, "slimmy", "hosaddsap")));
sheet.print_selection(ss);
expS = "";

EXPECT_EQ(ss.str(), expS);

}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}