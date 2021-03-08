#include "IDatabaseManager.hpp"
#include <functional>
#include <memory>

struct sqlite3;

class Sqlite3Manager : public IDatabaseManager {
    using Log = std::function< void( const std::string& ) >;

public:
    Sqlite3Manager( const std::string& db_name, Log log )
        : m_db_name( db_name ), m_connectionStatus( -1 ), m_executeStatus( -1 ), m_log( log ){};
    int open_db() override;
    int close_db() override;
    int execute( const std::string& sql ) override;

private:
    struct sqlite3_deleter {
        void operator()( sqlite3* db );
    };
    using unique_sqlite3 = std::unique_ptr< sqlite3, sqlite3_deleter >;

    unique_sqlite3 make_unique_connection();

    unique_sqlite3 m_db;
    int m_connectionStatus;
    int m_executeStatus;
    Log m_log;
    const std::string m_db_name;
};
