#include "ORMManager.hpp"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int ORMManager::ParseFile( const std::string& file_path ) {
    std::fstream fileStream;
    fileStream.open( file_path );
    if ( fileStream.fail() ) {
        return -1;
    }

    json j;
    fileStream >> j;

    for( auto table_data: j[0]["tables"] ) {
        Table table;
        table.name = table_data[ "name" ];
        for( auto field_data : table_data[ "fields" ] ) {
            Field field;
            field.name = field_data[ "name" ];
            field.type = field_data[ "type" ];
            field.is_nullable = field_data[ "nullable" ];
            field.primary_key = field_data[ "primary_key" ];
        }
    }
    int result = 0;
    return result;
}
