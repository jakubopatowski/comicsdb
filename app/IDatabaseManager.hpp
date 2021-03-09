#pragma once

#include <string>

class IDatabaseManager {
public:
    virtual int open_db() = 0;
    virtual int close_db() = 0;
    virtual int execute( const std::string& sql ) = 0;
};
