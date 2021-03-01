#include <memory>
#include "IDatabaseManager.hpp"
#include <sqlite3.h>

//class sqlite3;

class Sqlite3Manager : public IDatabaseManager {
  public:
    Sqlite3Manager(): m_connectionStatus(-1), m_executeStatus(-1){};
    virtual void connection( const std::string& dbName );
    virtual int execute( const std::string& sql );

  private:
    struct sqlite3_deleter {
	void operator()(sqlite3* db);
    };
    using unique_sqlite3 = std::unique_ptr<sqlite3, sqlite3_deleter>;

    unique_sqlite3 m_db;
    int m_connectionStatus;
    int m_executeStatus;
};
