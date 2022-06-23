#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "nlohmann/json.hpp"
using json=nlohmann::json;

namespace libminimal {
    namespace intermediate {
        namespace config {


            class PretrainedConfig {
            public:

                virtual json to_json() = 0;

                virtual PretrainedConfig &from_json(json config_json) = 0;

                void save_pretrained(std::string save_directory) {

                    std::string config_path = save_directory + "/pretrained_config.json";

                    std::ofstream ofs(config_path);

                    json config_json;
                    config_json = to_json();
                    ofs << config_json.dump(4) << std::endl;
                }

                PretrainedConfig& from_pretrained(std::string save_directory) {
                    std::string config_path = save_directory + "/pretrained_config.json";
                    std::ifstream input_stream(config_path);

                    json config_json;
                    input_stream >> config_json;
                    PretrainedConfig &config_object = from_json(config_json);
                    return config_object;
                }

            };

        } //config
    } //intermediate
} //libminimal