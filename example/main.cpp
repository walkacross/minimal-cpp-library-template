#include <iostream>
#include <libminimal/libminimal.h>

int main(int argc, char *argv[]){
    int output;
    int a = 5;
    int b = 3;
    output = libminimal::low_level::add(a, b);
    std::cout << "the add output is: " << output << std::endl;


    int c, d;
    std::tie(c, d) = libminimal::low_level::try_ouptut_is_tuple(a, b);
    std::cout << "the first output is: " << c << "\n the second output is: " << d << std::endl;

    std::vector<double> v{0.45, 1.22, 3.14, 2.22};
    libminimal::low_level::NaiveClass naive_obj(v, 3);
    naive_obj.show();


    return 0;
}

