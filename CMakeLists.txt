cmake_minimum_required(VERSION 2.8)
# Download and unpack gtest at configure time
set(URL_TO_USE https://github.com/google/googletest/archive/master.zip)
if(USE_LOCAL_GTEST)
    set(URL_TO_USE ${USE_LOCAL_GTEST})
endif()

configure_file(gtest-CMakeLists.txt gtest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gtest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gtest-download )

# Add gtest directly to our build
add_subdirectory(${CMAKE_BINARY_DIR}/gtest-src
                 ${CMAKE_BINARY_DIR}/gtest-build
                 EXCLUDE_FROM_ALL )

# Add the gtest include directory, since gtest
# doesn't add that dependency to its gtest target
target_include_directories(gtest INTERFACE
  "${CMAKE_BINARY_DIR}/gtest-src/googletest/include"
  "${CMAKE_BINARY_DIR}/gtest-src/googlemock/include")

project(entryPointTests)
aux_source_directory(. SRC_LIST)

add_subdirectory(ServiceLib)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME}  gtest gmock ServiceLib)
