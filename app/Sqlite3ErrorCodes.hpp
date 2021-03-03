#pragma once

#include <string>
using namespace std;

class Sqlite3ErrorCodes {
public:
    static const char* statusToStr( const int status );
};