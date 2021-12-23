#include <libminimal/utility.h>

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

