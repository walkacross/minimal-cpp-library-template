#pragma once

#include <cstring>
#include <string>
#include "libminimal/intermediate/data_container/spreadsheet/spreadsheet.h"

class Select{
public:
    virtual ~Select() = default;

    // Return true if the specified row should be selected.
    virtual bool select(const Spreadsheet* sheet, int row) const = 0;
};

// A common type of criterion for selection is to perform a comparison based on
// the contents of one column.  This class contains contains the logic needed
// for dealing with columns. Note that this class is also an abstract base
// class, derived from Select.  It introduces a new select function (taking just
// a string) and implements the original interface in terms of this.  Derived
// classes need only implement the new select function.  You may choose to
// derive from Select or Select_Column at your convenience.
class Select_Column: public Select{
protected:
    int column;
public:
    Select_Column(const Spreadsheet* sheet, const std::string& name){
        column = sheet->get_column_by_name(name);
    }

    virtual bool select(const Spreadsheet* sheet, int row) const{
        return select(sheet->cell_data(row, column));
    }

    // Derived classes can instead implement this simpler interface.
    virtual bool select(const std::string& s) const = 0;
};


class Select_Contains : public Select_Column{
protected:
    std::string str;
public:
    Select_Contains(const Spreadsheet* sheet, const std::string& colNam, const std::string& sstr) : Select_Column(sheet, colNam) {
        str = sstr;
    }
    virtual bool select(const std::string& s) const {
        if(s.find(str) != std::string::npos)
        {
            return true;
        }
        return false;
    }
};

class Select_Not: public Select {
protected:
    Select* con;
public:
    Select_Not(Select* var) {
        con = var;
    }

    virtual bool select(const Spreadsheet* sheet, int row) const {
        if(con->select(sheet,row) == true) {
            return false;
        }
        else {
            return true;
        }
    }

    virtual ~Select_Not() {
        delete con;
    }
};

class Select_And : public Select {
protected:
    Select* and1;
    Select* and2;

public:
    Select_And(Select* var1, Select* var2) {
        and1 = var1;
        and2 = var2;
    }

    bool select(const Spreadsheet* sheet, int row) const {
        if (and1->select(sheet, row) == true && and2->select(sheet, row) == true) {
            return true;
        } else {
            return false;
        }
    }

    virtual ~Select_And() {
        delete and1;
        delete and2;
    }
};

class Select_Or : public Select {
protected:
    Select* or1;
    Select* or2;

public:
    Select_Or(Select* var1, Select* var2) {
        or1 = var1;
        or2 = var2;
    }

    bool select(const Spreadsheet* sheet, int row) const {
        if (or1->select(sheet, row) == true || or2->select(sheet, row) == true) {
            return true;
        } else {
            return false;
        }
    }

    virtual ~Select_Or() {
        delete or1;
        delete or2;
    }
};