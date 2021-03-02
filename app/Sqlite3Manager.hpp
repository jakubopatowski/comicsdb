#include "IDatabaseManager.hpp"
#include <functional>
#include <memory>

struct sqlite3;

class Sqlite3Manager : public IDatabaseManager {
    using Log = std::function< void( std::string ) >;

  public:
    Sqlite3Manager( const Log& log )
        : m_connectionStatus( -1 ), m_executeStatus( -1 ), m_log(log){};
    virtual int connection( const std::string& dbName );
    virtual int execute( const std::string& sql );

  private:
    struct sqlite3_deleter {
        void operator()( sqlite3* db );
    };
    using unique_sqlite3 = std::unique_ptr< sqlite3, sqlite3_deleter >;

    unique_sqlite3 m_db;
    int m_connectionStatus;
    int m_executeStatus;
    const Log& m_log;
};
