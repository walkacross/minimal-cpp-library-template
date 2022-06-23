#include <libminimal/intermediate/config/project_config.h>

using namespace libminimal::intermediate::config;

int model(int input_dim, int hidden_size){
    return input_dim + hidden_size;
}


int fine_tune_model(ProjectConfig config){
    int output = model(config.input_dim, config.hidden_size);
    std::cout << "output:　" << output << std::endl;
    return output;
}

int main(){
    // step1: create config object
    ProjectConfig project_config(/*input_dim=*/10, /*hidden_size=*/6);
    std::cout << "config.hidden_size: " << project_config.hidden_size << std::endl;

    // step2: run_config
    int output = fine_tune_model(project_config);

    // step3: config serializing
    std::string save_dir = "./";
    project_config.save_pretrained(save_dir);

    // step4: load a json
    ProjectConfig another_config;
    another_config.from_pretrained(save_dir);
    int another_output = fine_tune_model(another_config);

    return 0;
}

