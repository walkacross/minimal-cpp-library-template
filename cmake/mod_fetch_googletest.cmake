# Create project third party --googletest

function(download_googletest)
    # googletest root dir
    set(GTEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/googletest)

    # if googletest exists, then skip download step
    if(EXISTS ${GTEST_DIR})
        message(STATUS "${GTEST_DIR} is already exists, skip download googletest, auto building ...")
        # auto compile gtest
        add_subdirectory(${GTEST_DIR})
        # clear cache
        unset(GTEST_VER)
    else()
        # set googletest git repository(using cn source.)
        set(GTEST_URL "https://github.com.cnpmjs.org/google/googletest.git")
        # Read googletest version form cache or set release-1.11.0
        set(GTEST_VER "1.11.0" CACHE STRING "Determines googletest version to download(for more visit offical site).")
        set(GTEST_TAG "release-${GTEST_VER}")

        # debug message
        message(STATUS "Downloading googletest tag ${GTEST_TAG},fetch url is: ${GTEST_URL}")

        # download googletest to third_party folder
        include(FetchContent)

        FetchContent_Declare(
                gtest_suites
                GIT_REPOSITORY ${GTEST_URL}
                GIT_TAG ${GTEST_TAG}
                SOURCE_DIR ${GTEST_DIR}
        )

        FetchContent_MakeAvailable(gtest_suites)

        # debug message
        message(STATUS "download googletest successfully")
    endif()

    # avoid googletest auto install
    set(INSTALL_GTEST OFF)

endfunction(download_googletest)