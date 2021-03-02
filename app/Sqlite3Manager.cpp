#include "Sqlite3Manager.hpp"
#include <sqlite3.h>

void Sqlite3Manager::sqlite3_deleter::operator()( sqlite3* db ) {
    sqlite3_close_v2( db );
}

int Sqlite3Manager::connection( const std::string& dbName ) {
    if ( !m_db ) {
        auto db = m_db.get();
        m_connectionStatus = sqlite3_open( dbName.c_str(), &db );
        if ( m_connectionStatus ) {
            m_log( "Can't open database: " +
                   std::string( sqlite3_errmsg( db ) ) );
        }
    }
    return m_connectionStatus;
}

int Sqlite3Manager::execute( const std::string& sql ) {
    auto db = m_db.get();
    char* m_errorMsg = nullptr;
    m_executeStatus = sqlite3_exec( db, sql.c_str(), 0, 0, &m_errorMsg );
    if ( m_executeStatus != SQLITE_OK ) {
        m_log( "SQL error: " +
               std::string( m_errorMsg == nullptr ? "" : m_errorMsg ) );
        sqlite3_free( m_errorMsg );
    }
    return m_executeStatus;
}
