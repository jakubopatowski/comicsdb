#include "Sqlite3ErrorCodes.hpp"
#include <catch2/catch.hpp>

TEST_CASE( "statusToStr test" ) {
    REQUIRE( Sqlite3ErrorCodes::statusToStr( 29 ) == "Unknown status" );
    REQUIRE( Sqlite3ErrorCodes::statusToStr( -1 ) == "Unknown status" );
}