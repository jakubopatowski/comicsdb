#include "ORMManager.hpp"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void orm::to_json( json& j, const Field& f ) {
    j = json{ { "name", f.name },
              { "type", f.type },
              { "primary_key", f.primary_key },
              { "nullable", f.nullable } };
}

void orm::from_json( const json& j, Field& f ) {
    j.at( "name" ).get_to( f.name );
    j.at( "type" ).get_to( f.type );
    j.at( "primary_key" ).get_to( f.primary_key );
    j.at( "nullable" ).get_to( f.nullable );
}

void orm::to_json( json& j, const Table& t ) {
    j = json{ { "name", t.name }, { "fields", t.fields } };
}

void orm::from_json( const json& j, Table& t ) {
    j.at( "name" ).get_to( t.name );
    auto tmp = j.at( "fields" );// .get_to( t.fields );
}

int ORMManager::ParseFile( const std::string& file_path ) {
    std::fstream fileStream;
    fileStream.open( file_path );
    if ( fileStream.fail() ) {
        return -1;
    }

    json j;
    auto db = j.get< orm::Table >();

    int result = 0;
    return result;
}
