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
string state, Nationality,aadhar,mobile;
string check_in_date, check_in_time, check_out_date, check_out_time;
*/
string post;
static int callback_staff(void *data, int argc, char **argv, char **colName)
{
    for (int i = 0; i < argc; i++)
    {
        ID = atoi(argv[i]);
    }
    return 0;
}

static int callback_staff1(void *data, int argc, char **argv, char **colName)
{
    for (int i = 0; i < argc; i++)
    {
        ID1 = atoi(argv[i]);
    }
    return 0;
}

void staffInfo()
{
    cout << "staff ID " << ID << "\n";
    cout << "Enter the Name of the staff :"<< " ";
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
    cout<<"Enter the Post"<<endl;
    fflush(stdin);
    getline(cin,post);
    cout<<"Enter the salary "<< endl;
    fflush(stdin);
    getline(cin,salary);
    cout << "Enter the Blood group :"<< " ";
    fflush(stdin);
    getline(cin, blood_g);
}

int addstaff()
{

    sqlite3 *DB;
    int myCursor = 0;
    char *error;

    myCursor = sqlite3_open("AJAX HMS_staff.db", &DB); // AJAX stands for Asynchronous JavaScript And XML
    // error handling 
    if (myCursor)
    {
        cerr << "Error While Loading Database!\n";
        cout << sqlite3_errmsg(DB) << "\n";
        return -1;
    }
    string query, query1;
    {
        query = "SELECT ID FROM AJAX_staff_DB ORDER BY ID DESC LIMIT 1;";
        query1 = "SELECT ID FROM AJAX_staff_DB ORDER BY ID DESC LIMIT 1;";
        myCursor = sqlite3_exec(DB, query.c_str(), callback_staff, NULL, NULL);
        myCursor = sqlite3_exec(DB, query1.c_str(), callback_staff1, NULL, NULL);

        ID = max(ID, ID1) + 1;
    }

    cout << "--------------Enter the staff detail --------------" << endl;
    staffInfo();  
    auto ztime = time(0);
    stringstream _time_date, _time_time;
    _time_date << put_time(localtime(&ztime), "%Y-%m-%d");
    check_in_date = _time_date.str();
    _time_time << put_time(localtime(&ztime), "%H:%M");
    check_in_time = _time_time.str();

   Staff S;
    S.setData(ID,Name,address,Age,mobile,aadhar,post,salary,check_in_date,check_in_time,check_out_date,check_out_time);

    query = S.getData(true);
    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
    insertion_check(myCursor, error); 

    sqlite3_close(DB);

    return 0;
}

