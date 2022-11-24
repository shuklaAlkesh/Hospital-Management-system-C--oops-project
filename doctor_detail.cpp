#include <iostream>
#include <bits/stdc++.h>
#include <sqlite3.h>
#include <iomanip>


class Doctor
{
    private:
        int createDocTable();
        int addDoctor();
        int checkdoctor();
        string query, query1;
        string Name, address, Gender, blood_g;
        int Age, Date, Month, year;
        int ID;
        string state, Nationality,aadhar,mobile,DOC_spec,salary;
        string check_in_date, check_in_time, check_out_date, check_out_time;
        
    public:
        Doctor(bool flag){
           createDocTable();
        }
        Doctor(){
            string getData(bool flag);
            string getData_Doc(bool flag);
            void setData(int ID,string Name,string DOC_spec,string address,int Age,string mobile,string aadhar,string salary,string check_in_date,string check_in_time,string check_out_date,string check_out_time);
            void setData(int ID,string Name,string DOC_spec,int Age,string mobile,string check_in_time,string check_out_time,string check_out_date,string check_in_date);
        }

        void setData(int ID,string Name,string DOC_spec,string address,int Age,string mobile,string aadhar,string salary,string check_in_date,string check_in_time,string check_out_date,string check_out_time){
            this->ID=ID;
            this->Name=Name;
            this->DOC_spec=DOC_spec;
            this->address=address;
            this->Age = Age;
            this->mobile=mobile;
            this->aadhar=aadhar;
            this->salary=salary;
            this->check_in_date=check_in_date;
            this->check_in_time=check_in_time;
            this->check_out_date=check_out_date;
            this->check_out_time=check_out_time;
         }
            string getData(bool flag){
            string data = "INSERT INTO  AJAX_Doctor_DB VALUES("+to_string(ID)+", '"+Name+"', '"+DOC_spec+"', '"+address+"',"+to_string(Age)+",'"+mobile+"', '"+aadhar+"', '"+salary+"', '"+check_in_date+"', '"+check_in_time+"', '"+check_out_date+"', '"+check_out_time+"');";
            
            return data;
           
        }
        //ID,Name,DOC_spec,Age,mobile,check_in_time,check_out_time,check_in_date,check_out_date

        void setData_doctor(int ID,string Name,string DOC_spec,int Age,string mobile,string check_in_time,string check_out_time,string check_in_date,string check_out_date){
            this->ID=ID;
            this->Name=Name;
            this->DOC_spec=DOC_spec;
            this->Age = Age;
            this->mobile=mobile;
            this->check_in_date=check_in_date;
            this->check_in_time=check_in_time;
            this->check_out_date=check_out_date;
            this->check_out_time=check_out_time;
        }
         string getData_Doc(bool flag){
            string data = "INSERT INTO  AJAX_Doctor_receptionist_DB VALUES("+to_string(ID)+", '"+Name+"', '"+DOC_spec+"', "+to_string(Age)+",'"+mobile+"', '"+check_in_time+"', '"+check_out_time+"','"+check_in_date+"','"+check_out_date+"');";
            return data;
        }

};

int  Doctor :: createDocTable(){
    sqlite3 *DB;
    int myCursor = 0;
    char *error;

    myCursor = sqlite3_open("AJAX HMS_Doc.db", &DB);
    //error handling
    if(myCursor){
        cerr << "Error While Loading Database!\n";
        cout << sqlite3_errmsg(DB) << "\n";
        return -1;
    }

    string query = "CREATE TABLE IF NOT EXISTS AJAX_Doctor_DB(ID INT PRIMARY KEY NOT NULL, " 
                                                    "NAME TEXT NOT NULL, "
                                                    "specialisation TEXT, "
                                                    "ADDRESS TEXT, "
                                                    "Age INT NOT NULL, "
                                                    "MOBILE TEXT NOT NULL, "
                                                    "AADHAR TEXT NOT NULL, "
                                                    "Salary TEXT NOT NULL, "
                                                    "IN_DATE TEXT NOT NULL, "
                                                    "IN_TIME TEXT NOT NULL, "
                                                    "OUT_DATE TEXT NOT NULL, "
                                                    "OUT_TIME TEXT NOT NULL );";

    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
    if(myCursor != SQLITE_OK){
        cerr << "ERROR CREATING DOCTOR INFORMATION TABLE\n";
        cout << error << "\n";
        sqlite3_free(error);
    }

    query = "CREATE TABLE IF NOT EXISTS AJAX_Doctor_receptionist_DB(ID INT PRIMARY KEY NOT NULL, " 
                                                    "NAME TEXT NOT NULL, "
                                                    "specialisation TEXT NOT NULL, "
                                                   // "ADDRESS TEXT NOT NULL, "
                                                    "Age INT NOT NULL, "
                                                    "MOBILE TEXT NOT NULL, "
                                                   // "AADHAR TEXT NOT NULL, "
                                                   // "Salary TEXT NOT NULL, "
                                                    "IN_TIME TEXT NOT NULL, "
                                                    "OUT_TIME TEXT NOT NULL, "
                                                    "IN_DATE TEXT NOT NULL, "
                                                    "OUT_DATE TEXT NOT NULL );";


    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
    if(myCursor != SQLITE_OK){
        cerr << "ERROR CREATING DOCTOR INFORMATION TABLE\n";
        cout << error << "\n";
        sqlite3_free(error);
    }

    sqlite3_close(DB);
    return 0;
}