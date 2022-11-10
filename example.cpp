#include <iostream>
#include <sqlite3.h>
#include<bits/stdc++.h>
using namespace std;
static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
  
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
  
    printf("\n");
    return 0;
}


int main(int argc, char** argv)
{

    // --------------------------creating a database file----------------------------
	sqlite3* DB;
	int exit = 0;
	exit = sqlite3_open("example1.db", &DB);

	if (exit) {
		std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
		return (-1);
	}
	else
		std::cout << "Opened Database Successfully!" << std::endl;
        
        
//-----------------------creating a table ------------------------------
   string sql = "CREATE TABLE PERSON("
                      "ID INT PRIMARY KEY     NOT NULL, " 
                      "NAME           TEXT    NOT NULL, "
                      "SURNAME          TEXT     NOT NULL, "
                      "AGE            INT     NOT NULL, "
                      "ADDRESS        CHAR(50), "
                      "SALARY         REAL );";
    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
  
    if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Table created Successfully" << std::endl;
    
    

    // --------------------------- inserting And delete the data----------------------------
    string query = "SELECT * FROM PERSON;";
  
    cout << "STATE OF TABLE BEFORE INSERT" << endl;
  
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
  
     sql = "INSERT INTO PERSON VALUES('id', 'STEVE', 'GATES', 30, 'PALO ALTO', 1000.0);" \
               "INSERT INTO PERSON VALUES(2, 'BILL', 'ALLEN', 20, 'SEATTLE', 300.22);" \
               "INSERT INTO PERSON VALUES(3, 'PAUL', 'JOBS', 24, 'SEATTLE', 9900.0);";
  
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Records created Successfully!" << std::endl;
  
    cout << "STATE OF TABLE AFTER INSERT" << endl;
  
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
  
    sql = "DELETE FROM PERSON WHERE ID = 2;";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error DELETE" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Record deleted Successfully!" << std::endl;
  
    cout << "STATE OF TABLE AFTER DELETE OF ELEMENT" << endl;
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    //-----------------------------------call back function -------------------------------
  
    string data("CALLBACK FUNCTION");
  
     sql="SELECT * FROM PERSON;";
    if (exit) {
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        return (-1);
    }
    else
        std::cout << "Opened Database Successfully!" << std::endl;
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL);
  
    if (rc != SQLITE_OK)
        cerr << "Error SELECT" << endl;
    else {
        cout << "Operation OK!" << endl;
    }
  
    sqlite3_close(DB);

    return (0);
}



	


