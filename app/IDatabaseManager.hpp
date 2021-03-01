#include <string>

class IDatabaseManager {
  public:
    virtual void connection( const std::string& dbName ) = 0;
    virtual int execute( const std::string& sql ) = 0;
};
