#include "ORMManager.hpp"
#include "tools.hpp"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int ORMManager::ParseFile( const std::string& file_path, Database& database ) {
    std::fstream fileStream;
    fileStream.open( file_path );
    if ( fileStream.fail() ) {
        return -1;
    }

    json j;
    fileStream >> j;
    database = j.at( "database" ).get< Database >();

    int result = 0;
    return result;
}

int ORMManager::CreateBuildDbQueries( const Database& database,
                                      std::vector< std::string >& sqls ) {
    int result = 0;
    for ( const Table& item: database.tables ) {
        auto sql = item.to_sql();
        sqls.push_back( sql );
    }
    return result;
}
