add_library(csv_parser_lib
    src/csv_parser.cpp
)
target_include_directories(csv_parser_lib PUBLIC src)

add_executable(csv_parser src/main.cpp)
target_link_libraries(csv_parser PRIVATE csv_parser_lib)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()