#include <iostream>
#include <nlohmann/json.hpp>   
#include <spdlog/spdlog.h>    
#include <libminimal/libminimal.h>

int main()
{
    // 验证 nlohmann_json 可用（由 libminimal PUBLIC 传递，无需消费者手动 find_package）
    nlohmann::json j = {{"name", "libminimal"}, {"version", "0.0.2"}};
    std::cout << j.dump(2) << std::endl;

    // 验证 spdlog 可用（同上）
    spdlog::info("libminimal consumer works!");

    return 0;
}