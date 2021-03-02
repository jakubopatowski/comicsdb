#include "Sqlite3ErrorCodes.hpp"

const string& Sqlite3ErrorCodes::statusToStr(const int){
    static constexpr auto ok = "Successful result";
    static constexpr auto error = "Generic error";
    static constexpr auto internal = "Internal logic error in SQLite";
    static constexpr auto perm = "Access permission denied";
    static constexpr auto abort = "Callback routine requested an abort";
    static constexpr auto busy = "The database file is locked";
    static constexpr auto locked = "The table in the database is locked";
    static constexpr auto nomem = "A malloc() failed";
    static constexpr auto readonly = "Attempt to write a readonly database";
    static constexpr auto interrupt = "Operation terminated by sqlite3_interrupt()";
    static constexpr auto ioerr = "Some kind of disk I/O error occurred";
    static constexpr auto corrupt = "The database disk image is malformed";
    static constexpr auto notfound = "Unknown opcode in sqlite3_file_control()";
    static constexpr auto full = "Insertion failed bexause database is full";
    static constexpr auto cantopen = "Unable to open the database file";
    static constexpr auto protocol = "Database lock protocol error";
    static constexpr auto empty = "Internal use only";
    static constexpr auto schema = "The database schema changed";
    static constexpr auto toobig = "String or BLOB exceeds size limit";
    static constexpr auto contraint = "Abort due to contraint violation";
    static constexpr auto mismatch = "Data type mismatch";
    static constexpr auto misuse = "Library used incorrectly";
    static constexpr auto nolfs = "Uses OS features not supported on host"
    static constexpr auto auth = "Authorization denied";

    return std::string();
}
