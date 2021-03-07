#include "Sqlite3Manager.hpp"
#include "Sqlite3ErrorCodes.hpp"
#include <sqlite3.h>

void Sqlite3Manager::sqlite3_deleter::operator()( sqlite3* db ) { sqlite3_close_v2( db ); }

int Sqlite3Manager::connection() {
    if ( !m_db ) {
        m_db = make_unique_connection();
    }
    return m_connectionStatus;
}

Sqlite3Manager::unique_sqlite3 Sqlite3Manager::make_unique_connection() {
    sqlite3* connection = nullptr;
    m_connectionStatus = sqlite3_open( m_db_name.c_str(), &connection );
    if ( m_connectionStatus != SQLITE_OK ) {
        m_log( "Error creating connection" +
               std::string( Sqlite3ErrorCodes::statusToStr( m_connectionStatus ) ) );
    }

    return unique_sqlite3( connection );
}

int Sqlite3Manager::execute( const std::string& sql ) {
    auto db = m_db.get();
    char* m_errorMsg = nullptr;
    m_executeStatus = sqlite3_exec( db, sql.c_str(), 0, 0, &m_errorMsg );
    if ( m_executeStatus != SQLITE_OK ) {
        m_log( "SQL error: " +
               std::string( m_errorMsg == nullptr ? "Unknown error." : m_errorMsg ) );
        m_log( "SQL error: " + std::string( Sqlite3ErrorCodes::statusToStr( m_executeStatus ) ) );
        sqlite3_free( m_errorMsg );
    }
    return m_executeStatus;
}
