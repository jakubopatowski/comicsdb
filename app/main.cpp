#include "Sqlite3Manager.hpp"
#include "ORMManager.hpp"
#include <iostream>
#include <memory>
#include <sqlite3.h>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

static int callback( void* NotUsed, int argc, char** argv, char** azColName ) {
    for ( int i = 0; i < argc; ++i ) {
        std::cout << azColName[ i ] << " = " << ( argv[ i ] ? argv[ i ] : "NULL" ) << endl;
    }
    return 0;
}

int main( int argc, char* argv[] ) {
    Sqlite3Manager manager( "file:comics.db",
                            []( const std::string& entry ) { std::cout << entry << '\n'; } );

    ORMManager orm;
    orm.ParseFile( "test.json" );

    manager.open_db();
    manager.execute( "CREATE TABLE t(x INTEGER PRIMARY KEY ASC, integer y,  integer z);" );
    manager.execute( "insert into t values(1,1,1);" );
    manager.close_db();



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
