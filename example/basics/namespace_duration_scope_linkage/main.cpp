#include <libminimal/libminimal.h>
#include <iostream>

int main(){
    // use global variable
    int the_global_value = libminimal::global::clock_rate;
    std::cout << "the value of global value is: " << the_global_value << std::endl;

    int a = 1;
    int output = libminimal::external::understand_external_internal_linkage(a);
    std::cout << " the output is: " << output << std::endl;

    return 0;
}