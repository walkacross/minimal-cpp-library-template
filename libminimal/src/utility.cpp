#include <libminimal/utility.h>
#include <cstddef>
using std::size_t; // 将 std::size_t 引入当前作用域

namespace libminimal { namespace utility {

    std::vector<double> vector2vector(const std::vector<double>& tensor, double number){
        std::vector<double> vector(tensor.size());

        for(size_t i =0; i < vector.size(); i++){
            vector[i] = tensor[i] * number;
        }
        return vector;
    }
}
}

