#include <catch2/catch_test_macros.hpp>

#include "csv_parser.hpp"

TEST_CASE("parse_line splits on comma", "[csv]") {
    auto fields = csv::parse_line("a,b,c");
    REQUIRE(fields.size() == 3);
    REQUIRE(fields[0] == "a");
    REQUIRE(fields[1] == "b");
    REQUIRE(fields[2] == "c");
}

TEST_CASE("parse_line handle empty fields", "[csv]") {
    auto fields = csv::parse_line("a,,c");
    REQUIRE(fields.size() == 3);
    REQUIRE(fields[1].empty());
}

TEST_CASE("parse_line handle single field", "[csv]") {
    auto fields = csv::parse_line("only");
    REQUIRE(fields.size() == 1);
    REQUIRE(fields[0] == "only");
}

TEST_CASE("compute_stats calculates sum, mean, count", "[csv]") {
    auto stats = csv::compute_stats({"1","2","3"});
    REQUIRE(stats.sum == 6.0);
    REQUIRE(stats.mean == 2.0);
    REQUIRE(stats.count == 3);
}

TEST_CASE("compute_stats skips non-numericand empty values","[csv]"){
    auto stats= csv::compute_stats({"1", "", "abc", "3"});
    REQUIRE(stats.count == 2);
    REQUIRE(stats.sum == 4.0);

}