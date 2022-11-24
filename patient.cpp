//                completed 

#include <iostream>
#include <bits/stdc++.h>
#include <sqlite3.h>
#include <iomanip>

int Room_A=25,Room_B=25,Room_C=25;
using namespace std;
class patient
{

    private:
        int createTable();
        int addpatientdetail();
       // int patient_bill();
        string query, query1;
        string Name, address, Gender, blood_g,patient_summary,room;
        int Age, Date, Month, year;
       int ID,bill,total;
        string state, Nationality,aadhar,mobile,doctor_name,prescription;
        string check_in_date, check_in_time, check_out_date, check_out_time;

    public:
        patient(bool flag){
           createTable();
        }
        patient(){
            string getData(bool flag);
            void setData(int ID,string Name,string address,int Age,string doctor_name,string mobile,string aadhar,string check_in_date,string check_in_time,string check_out_date,string check_out_time,string room,int bill,string prescription,string patient_summary);
        }

        void setData(int ID,string Name,string address,int Age,string doctor_name,string mobile,string aadhar,string check_in_date,string check_in_time,string check_out_date,string check_out_time,string room,int bill,string prescription,string patient_summary){
            this->ID=ID;
            this->Name=Name;
            this->address=address;
            this->Age = Age;
            this->doctor_name=doctor_name;
            this->mobile=mobile;
            this->aadhar=aadhar;
            this->bill=bill;
            this->prescription=prescription;
            this->check_in_date=check_in_date;
            this->check_in_time=check_in_time;
            this->check_out_date=check_out_date;
            this->check_out_time=check_out_time;
            this->room=room;
            this->patient_summary=patient_summary;
         }
            string getData(bool flag){
            string data = "INSERT INTO AJAX_PATIENT_DB VALUES("+to_string(ID)+",'"+Name+"','"+address+"',"+to_string(Age)+",'"+doctor_name+"','"+mobile+"','"+aadhar+"','"+check_in_date+"','"+check_in_time+"','"+check_out_date+"','"+check_out_time+"' ,'"+room+"', "+to_string(bill)+" , '"+prescription+"','"+patient_summary+"');";
            
            return data;
           
        }
};

int patient :: createTable(){
    sqlite3 *DB;
    int myCursor = 0;
    char *error;

    myCursor = sqlite3_open("HMS_AJAX HMS5.db", &DB);
    //error handling
    if(myCursor){
        cerr << "Error While Loading Database!\n";
        cout << sqlite3_errmsg(DB) << "\n";
        return -1;
    }

    string query = "CREATE TABLE IF NOT EXISTS AJAX_PATIENT_DB(ID INT PRIMARY KEY NOT NULL, " 
                                                    "NAME TEXT NOT NULL, "
                                                    "ADDRESS TEXT, "
                                                    "Age INT NOT NULL, "
                                                    "DOCTOR TEXT NOT NULL, "
                                                    "MOBILE TEXT NOT NULL, "
                                                    "AADHAR TEXT NOT NULL, "
                                                    "IN_DATE TEXT NOT NULL, "
                                                    "IN_TIME TEXT NOT NULL, "
                                                    "OUT_DATE TEXT NOT NULL, "
                                                    "OUT_TIME TEXT NOT NULL,"
                                                    "ROOM_ALLOTED TEXT NOT NULL, "
                                                    "BILL INT NOT NULL, "
                                                    "PRESCRIPTION TEXT NOT NULL,"
                                                    "PATIENT_SUMMARY TEXT NOT NULL);";

    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
    if(myCursor != SQLITE_OK){
        cerr << "ERROR CREATING PATIENT INFORMATION TABLE\n";
        cout << error << "\n";
        sqlite3_free(error);
    }

    query = "CREATE TABLE IF NOT EXISTS AJAX_OLD_PATIENT_DB(ID INT PRIMARY KEY NOT NULL, " 
                                                    "NAME TEXT NOT NULL, "
                                                    "ADDRESS TEXT, "
                                                    "Age INT NOT NULL, "
                                                    "DOCTOR TEXT NOT NULL, "
                                                    "MOBILE TEXT NOT NULL, "
                                                    "AADHAR TEXT NOT NULL, "
                                                    "IN_DATE TEXT NOT NULL, "
                                                    "IN_TIME TEXT NOT NULL, "
                                                    "OUT_DATE TEXT NOT NULL, "
                                                    "OUT_TIME TEXT NOT NULL,"
                                                    "ROOM_ALLOTED TEXT, "
                                                    "BILL INT NOT NULL, "
                                                    "PRESCRIPTION TEXT NOT NULL,"
                                                    "PATIENT_SUMMARY TEXT NOT NULL);";



    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
    if(myCursor != SQLITE_OK){
        cerr << "ERROR CREATING PATIENT INFORMATION TABLE\n";
        cout << error << "\n";
        sqlite3_free(error);
    }

    sqlite3_close(DB);
    return 0;
}

int count_=0;
static int callback_get_count5(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        count_= atoi(argv[i]);
    }
    return 0;
}
int patient_bill()  //using scope resolution operator to define function outside class
{
    system("CLS");
    sqlite3 *DB;
    int myCursor = 0;
    char *error;
    int ID,total;
    myCursor = sqlite3_open("HMS_AJAX HMS5.db", &DB);
    //error handling
    if(myCursor){
        cerr << "Error While Loading Database!\n";
        cout << sqlite3_errmsg(DB) << "\n";
        return -1;
    }
    cout << "<<---------------------------PATIENT ID --------------------------->>\n";
    cout << "\tEnter Patient ID Number to create Bill   ->> ";
    cin >> ID;
    string query;

    query = "SELECT COUNT (ALL) FROM AJAX_PATIENT_DB WHERE ID = "+to_string(ID)+";";
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_count5, NULL, NULL);
    if(count_==0){
        cout << "No Patient Found\n";
        return 0;
    }
     //system("cls");
    int bill;
    cout<<"\tEnter the BILL of the patient ->>" <<" ";
    cin>>bill;
   system("cls");
    cout<<"\n\n\t"<<endl;
    cout << "********************************************************************************";
    cout << "\n\n\t\t\t\tPatient Fee Charge\n\n ";
    cout << "*******************************************************************************";
    //cout << "\nHospital Room Charges                      :\t  1000";
    cout << "\n\tHospital Care Charges                      :\t  100";
    cout << "\n\tHospital Maintaince Charges                :\t  100";
    cout << "\n\tPatient Individual  Charges                :\t  " << bill;
    total = 100 + 100 + bill;
    cout << "\n\tTotal Fee Charge                           :\t  "  << total<<"\n";
    cout << "********************************************************************************";

    query = "UPDATE AJAX_PATIENT_DB SET BILL = "+to_string(total)+" WHERE ID = "+to_string(ID)+";";
    myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
    insertion_check(myCursor, error);
    cout<<"\n\n\n";
    //cout<<"Press continue......."<<" ";
    
    
    sqlite3_close(DB);
    return 0;
}