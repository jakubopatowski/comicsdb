#pragma once

#include <string>
using namespace std;

class Sqlite3ErrorCodes {
  public:
    static const string& statusToStr( const int );
};