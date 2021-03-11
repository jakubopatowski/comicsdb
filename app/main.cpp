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

int main( int argc, char* argv[] ) {
    ORMManager orm;
    orm::Database database;
    orm.ParseFile( "test.json", database );
    orm.CreateBuildDbQueries( database );

    Sqlite3Manager manager( "file:comics.db",
                            []( const std::string& entry ) { std::cout << entry << '\n'; } );
    manager.open_db();
    manager.execute( "CREATE TABLE t(x INTEGER PRIMARY KEY ASC, integer y,  integer z);" );
    manager.execute( "insert into t values(1,1,1);" );
    manager.close_db();

    return 0;
}
