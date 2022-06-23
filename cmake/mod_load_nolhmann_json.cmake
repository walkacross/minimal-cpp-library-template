function(download_nlohmann_json path_dir release_version)
    # set creature git repository(consider using cn source.)
    set(JSON_URL "https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent")
    # Read creature version form cache or set release-1.11.0
    # Determines creature version to download(for more visit offical site)
    set(JSON_TAG "${release_version}")

    # debug message
    message(STATUS "Downloading nlohmann_json from tag ${JSON_TAG},fetch url is: ${JSON_URL}")

    # Download creature to third party folder
    include(FetchContent)

    FetchContent_Declare(
            json
            GIT_REPOSITORY ${JSON_URL}
            GIT_PROGRESS TRUE
            GIT_SHALLOW TRUE
            GIT_TAG ${JSON_TAG}
            SOURCE_DIR ${path_dir})

    FetchContent_MakeAvailable(json)

endfunction()

# root_dir      - top directory of current project
# release_ver   - libtorch release version,such as 1.9.1, etc
# device_ver    - libtorch device version,such as cpu, cu102, etc
macro(load_nlohmann_json root_dir release_version)
    # libtorch dir
    set(JSON_DIR "${root_dir}/third_party/nlohmann_json")
    # debug message
    message(STATUS "Searching ${JSON_DIR} directory to load nlohmann_json.")

    if(EXISTS ${JSON_DIR})
        # debug message
        message(STATUS "${JSON_DIR} is already existed,skip downloading.")
        # friendly load creature
        add_subdirectory(${JSON_DIR})
    else()
        download_nlohmann_json(${JSON_DIR} ${release_version})
    endif()

    # debug message
    message(STATUS "** Load nlohmann_json - done. **")

    # clear cache
    unset(JSON_DIR)

endmacro()