#include <iostream>

namespace libminimal { namespace external {

    extern int tom; //tom defined elsewhere
    static int dick =10; // overrides external dick
    int harry = 200; // external variable definition, no conflicts with harry in external.cpp


    int remote_access(){

        std::cout << "remote_access report the following address: \n";
        std::cout << "&tom = " << &tom << " &dict = " << &dick << std::endl;
        std::cout << "&harry = " << &harry << std::endl;

        // modifies global variables
        extern int tom; // optional redeclaration
        tom += 1; //uses global warming
        std::cout << "updating global tome to " << tom << std::endl;
        return harry;
    }

    void local_not_conflict(){
        // define a local scope variable with same name, what happens??
        int tom = 111;
        std::cout << "local tom = " << tom << std::endl;

        std::cout << "but global tom = " << libminimal::external::tom << std::endl;

    }


}
}



