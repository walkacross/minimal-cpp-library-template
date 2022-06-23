#include "libminimal/intermediate/config/config.h"

namespace libminimal {
    namespace intermediate {
        namespace config {

            class ProjectConfig : public PretrainedConfig{
            public:
                std::string model_type = "LSTM";
                int input_dim;
                int hidden_size;
                int num_layers;
                double dropout;

                // model train kwargs
                int seq_length{3};
                int min_epochs{5};
                int max_epochs{10};

                // dataset

                // optimizer

                ProjectConfig(int input_dim=6, int hidden_size=64, int num_layers=2, double dropout=0.0);
                json to_json() override;
                ProjectConfig& from_json(json config_json) override;
            };
        }
    }
}
