function(download_library library_name path_dir release_version library_url)
    include(FetchContent)
    FetchContent_GetProperties(${library_name})
    if(${library_name}_POPULATED)
        message(STATUS "${library_name} has already been populated. Skipping download.")
        return()
    endif()
    string(STRIP "${library_url}" LIBRARY_URL)
    set(LIBRARY_GIT_TAG "${release_version}")
    message(STATUS "Downloading ${library_name} from tag ${LIBRARY_GIT_TAG}")
    message(STATUS "Source directory: ${path_dir}")
    FetchContent_Declare(
        ${library_name}
        GIT_REPOSITORY ${LIBRARY_URL}
        GIT_TAG        ${LIBRARY_GIT_TAG}
        GIT_PROGRESS   TRUE
        GIT_SHALLOW    TRUE
        SOURCE_DIR     ${path_dir}
    )
    FetchContent_Populate(${library_name})
endfunction()

macro(load_or_download_library library_name target_name root_dir release_version library_url)
    set(LIBRARY_DIR "${root_dir}/third_party/${library_name}")
    message(STATUS "Looking for ${library_name} in: ${LIBRARY_DIR}")

    if(EXISTS ${LIBRARY_DIR})
        message(STATUS "Found existing ${library_name} at ${LIBRARY_DIR}. Using local copy.")
        if(NOT TARGET ${target_name})
            # ★ 去掉 EXCLUDE_FROM_ALL
            # 原来：add_subdirectory(${LIBRARY_DIR} EXCLUDE_FROM_ALL)
            # EXCLUDE_FROM_ALL 会同时屏蔽 install() 规则，导致依赖的 Config 文件无法安装
            add_subdirectory(${LIBRARY_DIR})
        else()
            message(STATUS "${target_name} already exists. Skipping add_subdirectory.")
        endif()
    else()
        download_library(${library_name} ${LIBRARY_DIR} ${release_version} ${library_url})
        if(EXISTS ${LIBRARY_DIR} AND NOT TARGET ${target_name})
            add_subdirectory(${LIBRARY_DIR})
        endif()
    endif()

    message(STATUS "** load_or_download_library (${library_name}) - done. **")
    unset(LIBRARY_DIR)
endmacro()