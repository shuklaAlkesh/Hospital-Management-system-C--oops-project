#include <bits/stdc++.h>
#include <string>
#include<sqlite3.h>

using namespace std;

//int count__=0;
static int callback_get_count2(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        count__ = atoi(argv[i]);
    }
    return 0;
}
int deletePatientRecord()
{
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

    int ID;
    cout << "ENTER ID NUMBER TO DELETE PATIENT RECORD ->> ";
    cin >> ID;
    string query;

    query = "SELECT COUNT (ALL) FROM AJAX_PATIENT_DB WHERE ID = "+to_string(ID)+";";
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_count2, NULL, NULL);
    if(count__==0){
        cout << "No Guest Found\n";
        return 0;
    }
    query = "DELETE FROM AJAX_PATIENT_DB WHERE ID = "+to_string(ID)+";";
    //cout << "DATA DELETED SUCCESSFULLY !!!"<<endl;
    myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
    insertion_check(myCursor, error);
    sqlite3_close(DB);
    return 0;

}

int deleteDoctorRecord()
{
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

    int ID;
    cout << "ENTER ID NUMBER TO DELETE PATIENT RECORD ->> ";
    cin >> ID;
    string query;

    query = "SELECT COUNT (ALL) FROM AJAX_Doctor_DB WHERE ID = "+to_string(ID)+";";
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_count2, NULL, NULL);
    if(count__==0){
        cout << "No Guest Found\n";
        return 0;
    }
    query = "DELETE FROM AJAX_Doctor_DB WHERE ID = "+to_string(ID)+";";
    myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
    insertion_check(myCursor, error);
    //cout << "DATA DELETED SUCCESSFULLY !!!"<<endl;
    sqlite3_close(DB);
    return 0;

}

int deletestaffRecord()
{
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

    int ID;
    cout << "ENTER ID NUMBER TO DELETE STAFF RECORD ->> ";
    cin >> ID;
    string query;

    query = "SELECT COUNT (ALL) FROM AJAX_staff_DB WHERE ID = "+to_string(ID)+";";
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_count2, NULL, NULL);
    if(count__==0){
        cout << "No Guest Found\n";
        return 0;
    }
    query = "DELETE FROM AJAX_staff_DB WHERE ID = "+to_string(ID)+";";
    myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
    insertion_check(myCursor, error);
    //cout << "DATA DELETED SUCCESSFULLY !!!"<<endl;
    sqlite3_close(DB);
    return 0;

}
