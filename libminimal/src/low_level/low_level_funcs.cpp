#include <libminimal/low_level_funcs.h>

namespace libminimal { namespace low_level {

    bool check_anormaly(int a, int b){
        bool flag = true;
        if (a != b) {
            flag = false;
        }
        return flag;
    }


    std::tuple<int, int> try_ouptut_is_tuple(int a, int b) {

        int c, d;
        c = a + b;
        d = a - b;

        return std::make_tuple(c, d);

    }

}
}

