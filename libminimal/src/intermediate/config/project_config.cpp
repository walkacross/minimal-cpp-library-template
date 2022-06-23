#include "libminimal/intermediate/config/project_config.h"

namespace libminimal { namespace intermediate { namespace config {


            ProjectConfig::ProjectConfig(int input_dim, int hidden_size, int num_layers, double dropout):
                    input_dim(input_dim),
                    hidden_size(hidden_size),
                    num_layers(num_layers),
                    dropout(dropout){

            }

            json ProjectConfig::to_json() {
                json j = json{
                        {"model_type", this->model_type},
                        {"input_dim", this->input_dim},
                        {"hidden_size", this->hidden_size},
                        {"num_layers", this->num_layers},
                        {"dropout", this->dropout},
                        {"seq_length", this->seq_length},
                        {"min_epochs", this->min_epochs},
                        {"max_epochs", this->max_epochs},
                };
                return j;
            }

            ProjectConfig& ProjectConfig::from_json(json config_json) {
                config_json.at("model_type").get_to(this->model_type);
                config_json.at("input_dim").get_to(this->input_dim);
                config_json.at("hidden_size").get_to(this->hidden_size);
                config_json.at("num_layers").get_to(this->num_layers);
                config_json.at("dropout").get_to(this->dropout);
                config_json.at("seq_length").get_to(this->seq_length);
                config_json.at("min_epochs").get_to(this->min_epochs);
                config_json.at("max_epochs").get_to(this->max_epochs);
                return *this;
            }
}
}
}
