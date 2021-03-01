#include "Sqlite3Manager.hpp"
#include <sqlite3.h>

void Sqlite3Manager::sqlite3_deleter::operator()(sqlite3* db){
    sqlite3_close_v2(db);
}

void Sqlite3Manager::connection( const std::string& dbName ) {
    if ( m_db ) {
        auto db = m_db.get();
        m_connectionStatus = sqlite3_open( dbName.c_str(), &db);
    }
}

int Sqlite3Manager::execute(const std::string &sql){
    auto db = m_db.get();
    char* m_errorMsg = 0;
    m_executeStatus = sqlite3_exec(db, sql.c_str(), 0, 0, &m_errorMsg);
    return m_executeStatus;
}
