#include "Sqlite3ErrorCodes.hpp"
#include <catch2/catch.hpp>

TEST_CASE( "statusToStr test" ) {
    CHECK( std::string( Sqlite3ErrorCodes::statusToStr( 29 ) ) == "Unknown status" );
    CHECK( std::string( Sqlite3ErrorCodes::statusToStr( -1 ) ) == "Unknown status" );
    CHECK( std::string( Sqlite3ErrorCodes::statusToStr( 0 ) ) == "Successful result" );
}