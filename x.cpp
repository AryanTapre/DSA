#include <iostream>
#include <sqlite3.h>

using namespace std;

// Singleton class for managing the database connection
class DatabaseConnection {
public:
    static DatabaseConnection& getInstance() {
        static DatabaseConnection instance;
        return instance;
    }

    sqlite3* getConnection() {
        return db;
    }

private:
    DatabaseConnection() {
        int rc = sqlite3_open("mydatabase.db", &db);
        if (rc != SQLITE_OK) {
            cerr << "Cannot open database: " << sqlite3_errmsg(db) << endl;
        }
    }

    ~DatabaseConnection() {
        sqlite3_close(db);
    }

    sqlite3* db;
};

int main() {
    // Get the singleton instance of the database connection
    DatabaseConnection& dbConnection = DatabaseConnection::getInstance();

    // Use the connection to execute SQL statements
    sqlite3* db = dbConnection.getConnection();
    const char* sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT, email TEXT)";
    int rc = sqlite3_exec(db, sql, NULL, NULL, NULL);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
    }

    // ... other database operations ...

    return 0;
}