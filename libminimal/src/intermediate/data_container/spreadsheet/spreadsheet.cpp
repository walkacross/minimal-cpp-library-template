#include <algorithm>
#include <iostream>
#include "libminimal/intermediate/data_container/spreadsheet/spreadsheet.h"
#include "libminimal/intermediate/data_container/spreadsheet/select.h"

Spreadsheet::~Spreadsheet(){
    delete select;
}

void Spreadsheet::set_selection(Select* new_select){
    delete select;
    select = new_select;
}

void Spreadsheet::clear(){
    column_names.clear();
    data.clear();
    delete select;
    select = nullptr;
}

void Spreadsheet::set_column_names(const std::vector<std::string>& names){
    column_names=names;
}

void Spreadsheet::add_row(const std::vector<std::string>& row_data){
    data.push_back(row_data);
}

int Spreadsheet::get_column_by_name(const std::string& name) const{
    for(int i=0; i<column_names.size(); i++)
        if(column_names.at(i) == name)
            return i;
    return -1;
}

void Spreadsheet::print_selection(std::ostream& out) const {
    if(select == nullptr){
        for(int i = 0; i < this->data.size(); i++) {
            for(int j = 0; j < data.at(i).size(); j++) {
                out << data.at(i).at(j) << ' ';
            }
            out << std::endl;
        }
    }
    else {
        for(int i = 0; i < this->data.size(); i++) {
            for(int j = 0; j < data.at(i).size(); j++) {
                if(select->select(this, i)) {
                    out << data.at(i).at(j) << ' ';
                    if(j == data.at(i).size() - 1) {
                        out << std::endl;
                    }
                }
            }
        }
    }
}