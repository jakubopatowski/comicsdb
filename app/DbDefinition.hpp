#pragma once

#include <string>
#include <sstream>
#include <nlohmann/json.hpp>

using nlohmann::json;

struct Field {
    std::string name;
    std::string type;
    bool primary_key;
    bool nullable;

    std::string to_sql();
    friend std::ostream& operator<<( std::ostream& os, const Field& f ) {
        os << f.name << " " << f.type;
        if ( f.primary_key ) {
            os << " PRIMARY KEY ASC AUTOINCREMENT";
        }
        if ( f.nullable ) {
            os << " NOT NULL";
        }
        return os;
    };
};

void to_json( json& j, const Field& f );
void from_json( const json& j, Field& f );

struct Table {
    std::string name;
    std::vector< Field > fields;

    std::string to_sql() const;
};

void to_json( json& j, const Table& t );
void from_json( const json& j, Table& t );

struct Database {
    std::string name;
    std::vector< Table > tables;
};

void to_json( json& j, const Database& d );
void from_json( const json& j, Database& d );
