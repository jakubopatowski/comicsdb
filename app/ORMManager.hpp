#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using nlohmann::json;

namespace orm {

struct Field {
    std::string name;
    std::string type;
    bool primary_key;
    bool nullable;
};

struct Table {
    std::string name;
    std::vector< Field > fields;
};

void to_json( json& j, const Field& f );
void from_json( const json& j, Field& f );
void to_json( json& j, const Table& t );
void from_json( const json& j, Table& t );

} // namespace orm

class ORMManager {
public:
    int ParseFile( const std::string& file_path );

private:
    std::vector< orm::Table > m_tables;
};