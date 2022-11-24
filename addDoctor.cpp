#include <bits/stdc++.h>
#include <sqlite3.h>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;


/*
int ID;
int ID1;
string query, query1;
string Name, address, Gender, blood_g;
int Age, Date, Month, year;
string state, Nationality,aadhar,mobile,DOC_spec,salary;
string check_in_date, check_in_time, check_out_date, check_out_time;
*/

string DOC_spec,salary;
static int callback_Doc(void *data, int argc, char **argv, char **colName)
{
    for (int i = 0; i < argc; i++)
    {
        ID = atoi(argv[i]);
    }
    return 0;
}

static int callback_Doc1(void *data, int argc, char **argv, char **colName)
{
    for (int i = 0; i < argc; i++)
    {
        ID1 = atoi(argv[i]);
    }
    return 0;
}



void doctorInfo()
{
    cout << "Doctor ID " << ID << "\n";
    cout << "Enter the Name of the Doctor :"<< " ";
    cin.clear();
    cin.ignore();
    fflush(stdin);
    getline(cin, Name);
    cout << "Enter the Gender :"<< " ";
    fflush(stdin);
    getline(cin, Gender); // you can enter both full name ot char also lke M or Male
    cout << "Enter the Age :" << " ";
    cin >> Age;
    cout << "Enter the Nationality :"<< " ";
    fflush(stdin);
    getline(cin, Nationality);
    cout << "Enter the Address :"<< " ";
    fflush(stdin);
    getline(cin, address);
    cout<<"Enter the Addhar Number "<<endl;
    fflush(stdin);
    getline(cin,aadhar);
    cout<<"Enter the mobile number "<<endl;
    fflush(stdin);
    getline(cin,mobile);
    cout<<"Enter the specialisation "<<endl;
    fflush(stdin);
    getline(cin,DOC_spec);
    cout<<"Enter the salary "<< endl;
    fflush(stdin);
    getline(cin,salary);
    cout << "Enter the Blood group :"<< " ";
    fflush(stdin);
    getline(cin, blood_g);
    string checkOutdate,checkoutTime;
    cout<<"Enter the CheckIN time (HH:MM)"<<" ";
    fflush(stdin);
    getline(cin,check_in_time);
    cout<<"Enter the CheckOut time (HH:MM)"<<" ";
    fflush(stdin);
    getline(cin,check_out_time);
 }

int addDoctor()
{ 
    sqlite3 *DB;
    int myCursor = 0;
    char *error;

    myCursor = sqlite3_open("AJAX HMS_Doc.db", &DB); // AJAX stands for Asynchronous JavaScript And XML
    // error handling 
    if (myCursor)
    {
        cerr << "Error While Loading Database!\n";
        cout << sqlite3_errmsg(DB) << "\n";
        return -1;
    }
    string query, query1;
    {
        query = "SELECT ID FROM AJAX_Doctor_DB ORDER BY ID DESC LIMIT 1;";
        query1 = "SELECT ID FROM AJAX_Doctor_OLD_DB ORDER BY ID DESC LIMIT 1;";
        myCursor = sqlite3_exec(DB, query.c_str(), callback_Doc, NULL, NULL);
        myCursor = sqlite3_exec(DB, query1.c_str(), callback_Doc1, NULL, NULL);

        ID = max(ID, ID1) + 1;
    }

    //cout << "--------------Enter the Doctor detail --------------" << endl;
    doctorInfo();
    auto ztime = time(0);
    stringstream _time_date, _time_time;
    _time_date << put_time(localtime(&ztime), "%Y-%m-%d");
    check_in_date = _time_date.str();
    /*
    _time_time << put_time(localtime(&ztime), "%H:%M");
    check_in_time = _time_time.str();
    */

   Doctor D;
    D.setData(ID,Name,DOC_spec,address,Age,mobile,aadhar,salary,check_in_date,check_in_time,check_out_date,check_out_time);
    D.setData_doctor(ID,Name,DOC_spec,Age,mobile,check_in_time,check_out_time,check_in_date,check_out_date);
    query = D.getData(true);
    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
    query =D.getData_Doc(true);
    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);

    insertion_check(myCursor, error); 

    sqlite3_close(DB);

    return 0;
}

