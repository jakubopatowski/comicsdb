#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

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

void to_json( json& j, const Field& f ) {
    j = json{ { "type", f.type }, { "primary_key", f.primary_key }, { "nullable", f.nullable } };
}

} // namespace orm

class ORMManager {
public:
    int ParseFile( const std::string& file_path );

private:
    std::vector< orm::Table > m_tables;
};