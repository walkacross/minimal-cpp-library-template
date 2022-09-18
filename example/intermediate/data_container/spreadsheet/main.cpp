#include <libminimal/libminimal.h>
#include <iostream>

int main(int argc, char* argv[]){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","Jackson","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"Dominick","Dole","22","communications"});
    sheet.add_row({"George","Genius","9","astrophysics"});

    sheet.print_selection(std::cout);
    std::cout << std::endl;

    // Sample usage 1
    sheet.set_selection(new Select_Contains(&sheet,"Last","Dole"));
    sheet.print_selection(std::cout);
    std::cout << std::endl;

    // Sample usage 2
    sheet.set_selection(
            new Select_And(
                    new Select_Contains(&sheet,"Last","Dole"),
                    new Select_Not(
                            new Select_Contains(&sheet,"First","v"))));

    sheet.print_selection(std::cout);
    std::cout << std::endl;

    // Sample usage 3
    sheet.set_selection(
            new Select_Or(
                    new Select_Contains(&sheet,"First","Amanda"),
                    new Select_Or(
                            new Select_Contains(&sheet,"Last","on"),
                            new Select_Contains(&sheet,"Age","9"))));

    sheet.print_selection(std::cout);
    std::cout << std::endl;

    return 0;
}