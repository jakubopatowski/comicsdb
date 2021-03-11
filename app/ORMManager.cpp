#include "ORMManager.hpp"
#include "tools.hpp"
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

    if ( j.contains( "primary_key" ) ) {
        j.at( "primary_key" ).get_to( f.primary_key );
    }
    else {
        f.primary_key = false;
    }

    if ( j.contains( "nullable" ) ) {
        j.at( "nullable" ).get_to( f.nullable );
    }
    else {
        f.nullable = false;
    }
}

void orm::to_json( json& j, const Table& t ) {
    json field_json;
    for ( Field item : t.fields ) {
        json i;
        to_json( i, item );
        field_json.push_back( i );
    }
    j = json{ { "name", t.name }, { "fields", field_json } };
}

void orm::from_json( const json& j, Table& t ) {
    j.at( "name" ).get_to( t.name );
    j.at( "fields" ).get_to< std::vector< Field > >( t.fields );
}

void orm::to_json( json& j, const Database& d ) {
    json table_json;
    for ( Table item : d.tables ) {
        json i;
        to_json( i, item );
        table_json.push_back( i );
    }
    j = json{ { "name", d.name }, { "tables", table_json } };
}

void orm::from_json( const json& j, Database& d ) {
    j.at( "name" ).get_to( d.name );
    j.at( "tables" ).get_to< std::vector< Table > >( d.tables );
}

int ORMManager::ParseFile( const std::string& file_path, orm::Database& database ) {
    std::fstream fileStream;
    fileStream.open( file_path );
    if ( fileStream.fail() ) {
        return -1;
    }

    json j;
    fileStream >> j;
    database = j.at( "database" ).get< orm::Database >();

    int result = 0;
    return result;
}

int ORMManager::CreateBuildDbQueries( const orm::Database& database ) {
    int result = 0;

    return result;
}

std::string orm::Field::to_sql() {
    std::string sql;
    sql = name + " " + type;
    if ( primary_key ) {
        sql += " PRIMARY KEY ASC AUTOINCREMENT";
    }
    if ( nullable ) {
        sql += " NOT NULL";
    }
    return sql;
}

std::string orm::Table::to_sql() {
    std::string sql;
    sql = "CREATE TABLE IF NOT EXISTS ";
    sql += name + " (";
    sql += Join( fields );
    sql += ");";
    return sql;
}
