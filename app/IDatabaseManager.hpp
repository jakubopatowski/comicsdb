#include <string>

class IDatabaseManager {
public:
    virtual int connection() = 0;
    virtual int execute( const std::string& sql ) = 0;
};
