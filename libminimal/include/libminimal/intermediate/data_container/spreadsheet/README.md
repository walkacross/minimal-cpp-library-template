# Strategy Pattern

> Author: Craig Schroeder

In this lab you will use a strategy pattern coupled with a composite pattern to perform custom queries on a spreadsheet.  This lab consists of three tasks:
* Writing classes to implement the selection criteria
* Implement a routine to query the spreadsheet and print the results
* Test your routines

## Printing the Selection

The `Spreadsheet` class stores a grid of strings `data` as a list of rows.  It also stores column labels `column_names` identifying the contents of each column.  Our primary interest for this lab is the `print_selection` routine, which prints to `out` the contents of the selected rows.  The criteria for selecting rows is chosen by the user by setting the `select` pointer to point to an object that implements the desired critera.  This routine should visit the rows of the spreadsheet in order, querying the selection object to decide whether the routine should be printed or ignored.  If the `select` pointer is null, all rows should be printed.

## Selection classes

The `Select` class has a pure virtual function `bool select(sheet, row)` that represents its interface.  This function returns `true` if the row should be printed and `false` if the row should be ignored.  You are also given the derived `Select_Column` helper class to simplify writing selectcion criteria that apply to the contents of a column.

You will need to implement four selection classes: `Select_Contains`, `Select_Not`, `Select_And`, and `Select_Or`.  The `Select_Contains::select` routine should return true if the contents of the specified cell contains the given substring. The strings do not need to be equal; the substring may occur anywhere inside the cell's string.  The other three classes allow simpler queries to be combined into more complex queries.  These are examples of the types of queries that should be possible:

```c++
sheet.set_selection(new Select_Contains(&sheet,"Last","Dole"));
sheet.print_selection(std::cout);

sheet.set_selection(
    new Select_And(
         new Select_Contains(&sheet,"Last","Dole"),
         new Select_Not(
             new Select_Contains(&sheet,"First","v"))));
sheet.print_selection(std::cout);
 
sheet.set_selection(
    new Select_Or(
        new Select_Contains(&sheet,"First","Amanda"),
        new Select_Or(
            new Select_Contains(&sheet,"Last","on"),
            new Select_Contains(&sheet,"Age","9"))));
sheet.print_selection(std::cout);
```

These queries are contained within `main.cpp`; uncomment them as you implement the required classes.  When completed, with the code in `main.cpp` uncommented, the program should produce the output shown in `sample_output.txt`.  Note that it is not sufficient to pass this test; you will need to perform more extensive testing on your own, and you will need to thoroughly unit test all of the routines that you write.

Hint: it will be easier for you to have `Select_Contains` inherit from `Select_Column` whereas `Select_And`, `Select_Or` and `Select_Not` should directly inherit from `Select`.

For this lab, you must ensure that selection classes delete their children to prevent memory leaks.  Note that the setter for the selection class deletes the old selection class automatically before replacing it.  Use `valgrind` to identify and track down memory leaks.  You may need to use `hammer` to run valgrind.

## Unit Testing

Unit testing routines that print to `std::cout` is normally difficult.  In this case, however, the selection routine prints to a specified stream, which need not be `std::cout`.  This is going to make the routine much simpler to test, since there is a special stream type `std::stringstream` that allows you to obtain its contents as a string (via `str()`).

You will need to make tests that contain different data (see the the `main.cpp` file for examples showing how this class is populated with data and queried).  There are many special cases that you should be testing.  For example, "" should match "cat", "dog" should not match "Dog", "apple" matches "apples" and "Snapple" but not "APPLE" or "app".  Does anything match ""?  What will happen if the user queries a column that does not exist?  What if there are two columns with the same name?

## Submission

To receive credit for this lab you must show an example program to your TA that demonstrates the full functionality of this pattern, including any interactions with other patterns. You must also show your TA the tests that you have created for validating that your classes are functioning correctly.  You must demonstrate to the TA that you pass the test case in `main.cpp` and that your code does not leak memory.
