#include "DbDefinition.hpp"
#include "ORMManager.hpp"
#include "Sqlite3Manager.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using json = nlohmann::json;

int main( int argc, char* argv[] ) {
    ORMManager orm;
    Database database;
    std::vector< std::string > sqls;
    orm.ParseFile( "test.json", database );
    orm.CreateBuildDbQueries( database, sqls );

    Sqlite3Manager manager( "file:comics.db",
                            []( const std::string& entry ) { std::cout << entry << '\n'; } );
    manager.open_db();
    for ( const auto& item : sqls ) {
        manager.execute( item );
    }

    manager.close_db();

    return 0;
}
