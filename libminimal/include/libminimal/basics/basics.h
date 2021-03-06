#pragma once

#include <vector>
#include "libminimal/basics/namespace_duration_scope_linkage/external.h"
#include "libminimal/basics/namespace_duration_scope_linkage/global.h"

namespace libminimal { namespace basics {

int add(int a, int b);

class NaiveClass{

    public:
        NaiveClass();
        NaiveClass(const std::vector<double>& a_double_vector, int a_int_var);
        ~NaiveClass();

        void show() const;

    protected:
        std::vector<double> a_protected_var_ ;


    private:
        bool a_private_var_ = false;



};

} // namespace low_level

} // namespace libminimal
