#include <iostream>
#include <stdexcept>
#include <libminimal/low_level/base.h>

namespace libminimal { namespace low_level {

    // function implementation
    int add(int a, int b){
        return a+b;
    }

    // class implementation
    NaiveClass::NaiveClass(){}
    NaiveClass::NaiveClass(const std::vector<double>& a_double_vector, int a_int_var){
        if (a_double_vector.size() < 3){
            throw std::invalid_argument("libminimal::low_level::LowLevelClass: a_double_vector size must greater than 3");
        }
        a_protected_var_ = a_double_vector;
        a_private_var_ = true;
}

    NaiveClass::~NaiveClass() {}
    void NaiveClass::show() const{
        std::cout << "the bool private var is: " << a_private_var_ << std::endl;

        std::cout << "the element in a_protected_var_ is: " << std::endl;
        for(int i=0; i<a_protected_var_.size(); i++){
            std::cout << a_protected_var_[i] << std::endl;
        }
    }
}
}
