#include <iostream>
#include <bits/stdc++.h>
#include <sqlite3.h>
#include <iomanip>

using namespace std;

class Staff:public person{
    private:
        int createTable();
        int addstaff();
        string salary,post;
        int staffid;
    public:
        Staff(bool flag){
           createTable();
        }
        Staff(){
            string getData(bool flag);
            void setData(int ID,string Name,string address,int Age,string mobile,string aadhar,string post,string salary,string check_in_date,string check_in_time,string check_out_date,string check_out_time);
        }

        void setData(int ID,string Name,string address,int Age,string mobile,string aadhar,string post,string salary,string check_in_date,string check_in_time,string check_out_date,string check_out_time){
            this->ID=ID;
            this->Name=Name;
            this->address=address;
            this->Age = Age;
            this->mobile=mobile;
            this->aadhar=aadhar;
            this->post = post;
            this->salary = salary;
            this->check_in_date=check_in_date;
            this->check_in_time=check_in_time;
            this->check_out_date=check_out_date;
            this->check_out_time=check_out_time;
         }
            string getData(bool flag){
            string data = "INSERT INTO AJAX_staff_DB VALUES("+to_string(ID)+", '"+Name+"', '"+address+"', "+to_string(Age)+",'"+mobile+"', '"+aadhar+"', '"+post+"', '"+salary+"', '"+check_in_date+"', '"+check_in_time+"', '"+check_out_date+"', '"+check_out_time+"');";
            
            return data;
           
        }
};

int Staff :: createTable(){
    sqlite3 *DB;
    int myCursor = 0;
    char *error;

    myCursor = sqlite3_open("AJAX HMS_staff.db", &DB);
    //error handling
    if(myCursor){
        cerr << "Error While Loading Database!\n";
        cout << sqlite3_errmsg(DB) << "\n";
        return -1;
    }

    string query = "CREATE TABLE IF NOT EXISTS AJAX_staff_DB(ID INT PRIMARY KEY NOT NULL, " 
                                                    "NAME TEXT NOT NULL, "
                                                    "ADDRESS TEXT, "
                                                    "Age INT NOT NULL, "
                                                    "MOBILE TEXT NOT NULL, "
                                                    "AADHAR TEXT NOT NULL, "
                                                    "POST TEXT NOT NULL, "
                                                    "SALARY TEXT NOT NULL, "
                                                    "IN_DATE TEXT NOT NULL, "
                                                    "IN_TIME TEXT NOT NULL, "
                                                    "OUT_DATE TEXT NOT NULL, "
                                                    "OUT_TIME TEXT NOT NULL );";

    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
    if(myCursor != SQLITE_OK){
        cerr << "ERROR CREATING STAFF INFORMATION TABLE\n";
        cout << error << "\n";
        sqlite3_free(error);
    }

    query = "CREATE TABLE IF NOT EXISTS AJAX_staff_Old__DB(ID INT PRIMARY KEY NOT NULL, " 
                                                    "NAME TEXT NOT NULL, "
                                                    "ADDRESS TEXT, "
                                                    "Age INT NOT NULL, "
                                                    "MOBILE TEXT NOT NULL, "
                                                    "AADHAR TEXT NOT NULL, "
                                                    "POST TEXT NOT NULL, "
                                                    "SALARY TEXT NOT NULL, "
                                                    "IN_DATE TEXT NOT NULL, "
                                                    "IN_TIME TEXT NOT NULL, "
                                                    "OUT_DATE TEXT NOT NULL, "
                                                    "OUT_TIME TEXT NOT NULL );";


    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
    if(myCursor != SQLITE_OK){
        cerr << "ERROR CREATING STAFF INFORMATION TABLE\n";
        cout << error << "\n";
        sqlite3_free(error);
    }

    sqlite3_close(DB);
    return 0;
}