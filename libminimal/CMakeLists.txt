cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(libminimal)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE ALL_SRC_FILES CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_library(${PROJECT_NAME} SHARED ${ALL_SRC_FILES})

# 命名空间别名
# 作用：让 add_subdirectory 和 find_package 两种使用方式的 target 名称完全一致
# 消费者始终写 libminimal::libminimal，不管是源码构建还是安装后使用
add_library(libminimal::libminimal ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        # 构建时（源码编译）：指向源码树的 include 目录
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        # 安装后（消费者 find_package）：指向 prefix/include
        # 这个路径会被写入 Targets.cmake，消费者链接后自动添加到编译路径
        $<INSTALL_INTERFACE:include>
)

# PUBLIC：两个依赖的头文件暴露在 libminimal 的公开头文件中
# 如果依赖只在 .cpp 内部使用，改为 PRIVATE，Config.in 里也不需要 find_dependency
target_link_libraries(${PROJECT_NAME}
    PUBLIC
        nlohmann_json::nlohmann_json
        spdlog::spdlog
)

# ── 安装规则 ──
include(GNUInstallDirs)
# GNUInstallDirs 提供平台无关的标准路径变量：
#   CMAKE_INSTALL_LIBDIR     → lib 或 lib64
#   CMAKE_INSTALL_INCLUDEDIR → include
#   CMAKE_INSTALL_BINDIR     → bin

install(TARGETS ${PROJECT_NAME}
    # EXPORT 给这次 install 的 targets 起一个集合名
    # 后续 install(EXPORT ...) 用同一个名字把集合写成文件
    EXPORT   libminimalTargets
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}          # .so / .dylib
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}          # .a
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}          # Windows .dll
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}      # 记录头文件路径到 Targets
)

# 安装头文件（源码树 include/ → prefix/include/）
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# 把 EXPORT 集合序列化成 Targets.cmake 文件并安装
# NAMESPACE：所有 target 加上 libminimal:: 前缀，避免与消费者项目的同名 target 冲突
install(EXPORT libminimalTargets
    FILE        libminimalTargets.cmake
    NAMESPACE   libminimal::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/libminimal
)