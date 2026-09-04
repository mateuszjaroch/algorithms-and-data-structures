add_executable(csv_parser_tests
    test_csv_parser.cpp
)
target_link_libraries(csv_parser_tests PRIVATE csv_parser_lib Catch2::Catch2WithMain)

catch_discover_tests(csv_parser_tests)