#include <iostream>
#include <sqlite3.h>
#include <bits/stdc++.h>
#include "query_exec.cpp"

using namespace std;

    string customer_name;
    char type;
    int Money_deposite;
    string Address;
    int account_number;

   

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

void Addcustomer()
{
    sqlite3 *DB;
    int myCursor = 0;
    char *error;

    myCursor = sqlite3_open("Basic.db", &DB);
    //error handling
    if(myCursor){
        cerr << "Error While Loading Database!\n";
        cout << sqlite3_errmsg(DB) << "\n";
        

    }

    string query = "SELECT * FROM customer;";
    myCursor=sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);


    cout << " Please Enter the new Account_no that you want generated :" << endl;
    cin >> account_number;
    cout << "Enter the name of the new customer : " << endl;
    fflush(stdin);
    getline(cin, customer_name);
    cout << "Enter the Address :" << endl;
    fflush(stdin);
    getline(cin, Address);
    cout << "Enter the min(10,000) Amount that you want to deposite : " << endl;
    cin >> Money_deposite;
    cout << "Account has been created succesfully" << endl;

    string sql = "INSERT INTO PERSON VALUES("+to_string(account_number)+","+customer_name+","+Address+", "+to_string(Money_deposite)+");";

     char* messaggeError;
    int exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Records created Successfully!" << std::endl;


}




int main()
{
    sqlite3* DB;
	int exit = 0;
	exit = sqlite3_open("Basic.db", &DB);

	if (exit) {
		std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
		return (-1);
	}
	else
		std::cout << "Opened Database Successfully!" << std::endl;
    /
    string sql = "CREATE TABLE customer("
                      "Account_number INT PRIMARY KEY     NOT NULL, " 
                      "NAME           TEXT    NOT NULL, "
                      "ADDRESS        CHAR(50), "
                      "Money_deposite        REAL );";
    
    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
  
    if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Table created Successfully" << std::endl;
    
    Addcustomer();
    int account_number;
    cout << "\n";
    cout << "Enter the Account number for checking old detail ->> ";
    cin>>account_number;
     cout << "\n";
    cout << "--- Customer detail ---\n\n";
    queryExec("SELECT * FROM customer = '+account_number+';");

    



    return 0;
}