cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(libminimal VERSION 0.0.2)



# ================================================================
# prerequist
# ================================================================

# cxx compile standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# option for unittest switch
option(ENABLE_UNITTEST "unittest for libminimal" OFF)

# project version setup
#set(LIBMINIMAL_MAJOR_VERSION "0")
#set(LIBMINIMAL_MINOR_VERSION "0")
#set(LIBMINIMAL_PATCH_VERSION "2")

# debug message
#message(STATUS "======================================================")
#message(STATUS "libminimal release version: ${LIBMINIMAL_MAJOR_VERSION}.${LIBMINIMAL_MINOR_VERSION}.${LIBMINIMAL_PATCH_VERSION}")
#message(STATUS "libminimal unittest flag: ${ENABLE_UNITTEST}")
#message(STATUS "======================================================")

message(STATUS "======================================================")
message(STATUS "libminimal version:  ${PROJECT_VERSION}")
message(STATUS "unittest:            ${ENABLE_UNITTEST}")
message(STATUS "======================================================")

# load custom cmake module
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/api.cmake)

# load third-party
load_nlohmann_json(${CMAKE_CURRENT_SOURCE_DIR} v3.10.5)
load_spdlog(${CMAKE_CURRENT_SOURCE_DIR} v1.12.0)

# generate library
add_subdirectory(libminimal)
add_subdirectory(example)

# 处理 .in 模板 → 生成 libminimalConfig.cmake 到 build 目录
# INSTALL_DESTINATION 告诉 configure 函数 Config 文件将来安装在哪里
# 函数据此计算出从 Config 文件位置到 prefix 根的相对路径，写入 @PACKAGE_INIT@
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/libminimalConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/libminimalConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/libminimal
)

# 生成版本文件
# SameMajorVersion：major 相同视为兼容（0.x.x 系列互相兼容）
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/libminimalConfigVersion.cmake
    VERSION       ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

# 把 Config 和 ConfigVersion 安装到 prefix
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/libminimalConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/libminimalConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/libminimal
)


# generate a package
# ── CPack 打包配置 ──
# 效果：cmake --build build --target package
#       生成 libminimal-0.0.2-Linux-x86_64.tar.gz

include(CPack)

# 包的基本信息
set(CPACK_PACKAGE_NAME      "libminimal")
set(CPACK_PACKAGE_VERSION         ${PROJECT_VERSION})
set(CPACK_PACKAGE_VENDOR          "libminimal")
set(CPACK_PACKAGE_DESCRIPTION     "Minimal C++ library")

# 只打包 install 规则产生的内容，不打包源码
set(CPACK_GENERATOR               "TGZ")          # .tar.gz
set(CPACK_INSTALL_CMAKE_PROJECTS  "${CMAKE_BINARY_DIR};${PROJECT_NAME};ALL;/")

# CMAKE_SYSTEM_PROCESSOR 可能为空，用 uname 兜底
if(NOT CMAKE_SYSTEM_PROCESSOR)
    execute_process(
        COMMAND uname -m
        OUTPUT_VARIABLE SYS_ARCH
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
else()
    set(SYS_ARCH ${CMAKE_SYSTEM_PROCESSOR})
endif()

# 显式构造文件名，不依赖 CPack 默认拼接
set(CPACK_PACKAGE_FILE_NAME
    "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_NAME}-${SYS_ARCH}")
    
# 不把源码目录打进去
set(CPACK_SOURCE_IGNORE_FILES
    "${CMAKE_BINARY_DIR}"
    "\\.git"
    "third_party"
    "test"
)


if(ENABLE_UNITTEST)
    # download googletest, function from mod_fetch_googletest.cmake
    download_googletest()

    #enable cmake google test
    enable_testing()

    # include gtest library
    #include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
    #message(STATUS "gtest source directory is: ${gtest_SOURCE_DIR}")

    # unittest directory
    add_subdirectory(test)
else()
    # clear cache
    unset(GTEST_VER)
endif()
