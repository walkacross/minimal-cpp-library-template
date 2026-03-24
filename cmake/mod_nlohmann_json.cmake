include_guard(GLOBAL)

macro(load_nlohmann_json root_dir release_version)
    # 打开 install 规则
    set(JSON_Install        ON  CACHE BOOL "" FORCE)
    # 关闭不需要编译的子目标，避免拖慢构建
    set(JSON_BuildTests     OFF CACHE BOOL "" FORCE)
    set(JSON_MultipleHeaders OFF CACHE BOOL "" FORCE)

    load_or_download_library(
        nlohmann_json
        nlohmann_json::nlohmann_json
        ${root_dir}
        v3.10.5
        https://github.com/nlohmann/json.git
    )
endmacro()