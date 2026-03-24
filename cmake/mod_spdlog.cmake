include_guard(GLOBAL)

macro(load_spdlog root_dir release_version)
    # 打开 install 规则
    set(SPDLOG_INSTALL      ON  CACHE BOOL "" FORCE)
    # 关闭不需要编译的子目标
    set(SPDLOG_BUILD_EXAMPLE OFF CACHE BOOL "" FORCE)
    set(SPDLOG_BUILD_TESTS   OFF CACHE BOOL "" FORCE)
    set(SPDLOG_BUILD_BENCH   OFF CACHE BOOL "" FORCE)

    load_or_download_library(
        spdlog
        spdlog::spdlog
        ${root_dir}
        v1.12.0
        https://github.com/gabime/spdlog.git
    )
endmacro()