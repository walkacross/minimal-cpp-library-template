# Create project third party open api
# auto load cmake module startwith "mod" and endwith ".cmake"

# using cmake filesystem to glob all cmake modules
FILE(GLOB EXTEND_MODULE "${CMAKE_CURRENT_LIST_DIR}/mod*.cmake")

# loop glob list and load module
foreach(ext ${EXTEND_MODULE})
    message(STATUS "load ${ext} module successfully")
    include(${ext})
endforeach()