// completed

#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <typeinfo>
#include<sqlite3.h>

using namespace std;

class Data_Query
{

private:
    vector<string> column_names;
    vector<pair<string, string>> query_data;

public:
    void setData(string value, string col)
    {
        int temp = 0;
        for (int i = 0; i < column_names.size(); i++)
        {
            if (column_names[i] == col)
            {
                temp = 1;
                break;
            }
        }
        if (!temp)
            column_names.push_back(col);
        query_data.push_back(make_pair(col, value));
    }
    void getData()
    {
        if (query_data.size() == 0)
        {
            cout << "No detail Found !!!\n";
        }
        else
        {
            cout << "\n";
            for (int i = 0; i < column_names.size(); i++)
            {
                if (i == 0)
                {
                    cout << left << setw(9) << column_names[i];
                }
                else if (i != column_names.size() - 1)
                    cout << left << setw(13.5) << column_names[i];
                else
                    cout << column_names[i] << "\n";
            }

            for (int i = 0; i < column_names.size(); i++)
            {
                if (i == 0)
                {
                    cout << left << setw(9) << "-------";
                }
                else if (i != column_names.size() - 1)
                    cout << left << setw(13.5) << "----------";
                else
                    cout << "----------\n";
            }
            for (int i = 0, j = 0; i < query_data.size(); i++, j++)
            {
                if (j == column_names.size())
                {
                    j = 0;
                    cout << "\n";
                }
                if (query_data[i].first == column_names[j] && j == 0)
                    cout << left << setw(9) << query_data[i].second;
                else if (query_data[i].first == column_names[j])
                    cout << left << setw(13.5) << query_data[i].second;
            }
            cout << "\n\n";
            system("pause");
        }
        query_data.clear();
        column_names.clear();
    }
};

Data_Query P;
Data_Query D;
Data_Query S;
Data_Query s;

//  data quary patient
static int callback_get_queryData(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        P.setData(string(argv[i] ? argv[i] : "NULL"), (string)colName[i]);
    }
    return 0;
}
//  data quary Doctor
static int callback_get_DOC_queryData(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        D.setData(string(argv[i] ? argv[i] : "NULL"), (string)colName[i]);
    }
    return 0;
}


int queryExec(string query){
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
    
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_queryData, NULL, NULL);
    P.getData();

    sqlite3_close(DB);
    

    return 0;    
}


int queryExec1(string query){
    sqlite3 *DB;
    int mycursor1 = 0;
    char *error;

    mycursor1 = sqlite3_open("AJAX HMS_Doc.db", &DB);
    if(mycursor1){
        cerr << "Error While Loading Database!\n";
        cout << sqlite3_errmsg(DB) << "\n";
        return -1;
    }
    
    mycursor1 = sqlite3_exec(DB, query.c_str(), callback_get_DOC_queryData, NULL, NULL);
    D.getData();
    sqlite3_close(DB);
    return 0;

}
 //  data quary staff
static int callback_get_staff_queryData(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        P.setData(string(argv[i] ? argv[i] : "NULL"), (string)colName[i]);
    }
    return 0;
}


int queryExec2(string query){
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
    
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_staff_queryData, NULL, NULL);
    P.getData();

    sqlite3_close(DB);
    

    return 0;    
}


static int callback_get_store_queryData(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        s.setData(string(argv[i] ? argv[i] : "NULL"), (string)colName[i]);
    }
    return 0;
}

int queryExec3(string query){
    sqlite3 *DB;
    int myCursor = 0;
    char *error;

    myCursor = sqlite3_open("HMS_AJAX store.db", &DB);
    //error handling
    if(myCursor){
        cerr << "Error While Loading Database!\n";
        cout << sqlite3_errmsg(DB) << "\n";
        return -1;
    }
    
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_store_queryData, NULL, NULL);
    s.getData();

    sqlite3_close(DB);
    

    return 0;    
}



