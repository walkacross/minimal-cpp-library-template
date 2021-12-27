#include <iostream>
#include "libminimal/basics/namespace_duration_scope_linkage/external.h"

namespace libminimal { namespace external {

    double warming = 0.3;

    int dick = 30;      // static (implicit) external linkage
    extern int tom = 3; // static duration, (explicit) external linkage;

    static int harry = 300; // static duration, internal linkage

    // forward declaration

    int remote_access();

    void local_not_conflict();



    int understand_external_internal_linkage(int a){
        std::cout <<"&tom = " << &tom << "&dick =" << &dick << std::endl;
        std::cout << "&harry " << &harry << std::endl;

        int remote_return_value = remote_access();
        int output = harry + remote_return_value + a;

        local_not_conflict();

        return output;
    };



}
}

