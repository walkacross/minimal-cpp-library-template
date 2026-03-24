cmake_minimum_required(VERSION 3.15)
project(libminimal_consumer VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ── 查找 libminimal ──
# REQUIRED：找不到直接报错，不静默失败
# 0.0.2：最低版本要求，由 libminimalConfigVersion.cmake 校验
find_package(libminimal 0.0.2 REQUIRED)

add_executable(consumer_app src/main.cpp)

# ── 链接 libminimal ──
# 效果：
#   1. 自动添加 prefix/include 到编译器头文件搜索路径
#   2. 自动链接 libminimal.so
#   3. nlohmann_json 和 spdlog 的头文件路径和链接也自动传播过来
#      消费者完全不需要手动 find_package 这两个库
target_link_libraries(consumer_app
    PRIVATE
        libminimal::libminimal
)