#include "Sqlite3Manager.hpp"
#include <iostream>
#include <memory>
#include <sqlite3.h>
#include <string>
#include <vector>
using namespace std;

static int callback( void* NotUsed, int argc, char** argv, char** azColName ) {
    for ( int i = 0; i < argc; ++i ) {
        std::cout << azColName[ i ] << " = " << ( argv[ i ] ? argv[ i ] : "NULL" ) << endl;
    }
    return 0;
}

int main( int argc, char* argv[] ) {
    Sqlite3Manager manager( "file:comics.db",
                            []( const std::string entry ) { std::cout << entry << '\n'; } );

    manager.connection();
    manager.execute( "CREATE TABLE t(x INTEGER PRIMARY KEY ASC, y, z);" );

    for ( int i = 0; i < argc; ++i ) {
        std::cout << argv[ i ] << endl;
    }

    sqlite3* db;
    char* zErrMsg = 0;
    int rc;

    rc = sqlite3_open( "comicsdb.sqlite", &db );
    if ( rc ) {
        cout << " Can't open database: " << sqlite3_errmsg( db ) << endl;
        sqlite3_close( db );
        return 1;
    }

    const char* sql = "";
    rc = sqlite3_exec( db, sql, callback, 0, &zErrMsg );
    if ( rc != SQLITE_OK ) {
        cout << "SQL error: " << zErrMsg << endl;
        sqlite3_free( zErrMsg );
    }
    sqlite3_close( db );

    cout << "koniec" << endl;
    return 0;
}
