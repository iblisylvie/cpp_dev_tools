#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include "mysql_driver.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

void PrintMysqlRecord(sql::ResultSet* res) {
    sql::ResultSetMetaData* meta = res->getMetaData();
    for (size_t i = 1; i <= meta->getColumnCount(); ++i) {
        string column_name = meta->getColumnLabel(i).asStdString();
        cout << "name: " << meta->getColumnName(i)
             << ", type: " << meta->getColumnType(i)
             << ", type name: " << meta->getColumnTypeName(i).asStdString()
             << ", isSigned: " << meta->isSigned(i) << endl;
        int type = meta->getColumnType(i);
        string name = meta->getColumnName(i);
        switch (type) {
            case sql::DataType::VARCHAR:
                cout << res->getString(name) << endl;
            default:
                break;
        }
    }
}

void runSqlCmd(sql::Connection* connection, const string& sql_command) {
    try {
        cout << "Run command " << sql_command << endl;
        std::unique_ptr<sql::Statement> stmt(connection->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery(sql_command));

        while (res->next()) {
            PrintMysqlRecord(res.get());
        }

    } catch (sql::SQLException &e) {
        cout << "# ERR: " << e.what() << ", command : " << sql_command << endl;
    }
}

int main(void) {
    sql::Driver* driver = sql::mysql::get_driver_instance();
    unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", "root", "123456"));
    /* Connect to the MySQL test database */
    con->setSchema("demodb");
    runSqlCmd(con.get(), "insert into iblis_demo_table (message) values ('hello my sql')");
    runSqlCmd(con.get(), "select message from iblis_demo_table limit 1");
    return EXIT_SUCCESS;
}
