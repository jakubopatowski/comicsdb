#include "Sqlite3ErrorCodes.hpp"

const char* Sqlite3ErrorCodes::statusToStr( const int status ) {
    static constexpr auto unknown = "Unknown status";
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
    static constexpr auto constraint = "Abort due to contraint violation";
    static constexpr auto mismatch = "Data type mismatch";
    static constexpr auto misuse = "Library used incorrectly";
    static constexpr auto nolfs = "Uses OS features not supported on host";
    static constexpr auto auth = "Authorization denied";
    static constexpr auto format = "Not used";
    static constexpr auto range = "2nd parameter to sqlite3_bind out of range";
    static constexpr auto notadb = "File opened tht is not a database file";
    static constexpr auto notice = "Notifications from sqlite3_log()";
    static constexpr auto warning = "Warnings from sqlite3_log()";
    static constexpr auto row = "sqlite3_step() has anotehr row ready";
    static constexpr auto done = "sqlite3_step() has finished executing";

    switch ( status ) {
    case 0: return ok;
    case 1: return error;
    case 2: return internal;
    case 3: return perm;
    case 4: return abort;
    case 5: return busy;
    case 6: return locked;
    case 7: return nomem;
    case 8: return readonly;
    case 9: return interrupt;
    case 10: return ioerr;
    case 11: return corrupt;
    case 12: return notfound;
    case 13: return full;
    case 14: return cantopen;
    case 15: return protocol;
    case 16: return empty;
    case 17: return schema;
    case 18: return toobig;
    case 19: return constraint;
    case 20: return mismatch;
    case 21: return misuse;
    case 22: return nolfs;
    case 23: return auth;
    case 24: return format;
    case 25: return range;
    case 26: return notadb;
    case 27: return notice;
    case 28: return warning;
    case 100: return row;
    case 101: return done;
    default: return unknown;
    }
}
