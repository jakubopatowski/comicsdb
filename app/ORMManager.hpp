#pragma once

#include "DbDefinition.hpp"
#include <string>
#include <vector>

class ORMManager {
public:
    // parsowanie
    int ParseFile( const std::string& file_path, Database& database );

    // tworzenie zapytan
    int CreateBuildDbQueries( const Database& database, std::vector< std::string >& sqls );
};