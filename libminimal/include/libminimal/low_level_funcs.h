#pragma once

#include <tuple>
//think why include this here?  #include<low_level_funcs> in libminimal will also include all heads in low_level folder
#include <libminimal/low_level/base.h>

namespace libminimal { namespace low_level {

        bool check_anormaly(int a, int b);

        std::tuple<int, int> try_ouptut_is_tuple(int a, int b);

    } // namespace low_level

} // namespace libminimal

