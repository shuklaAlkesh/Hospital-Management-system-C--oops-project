#include <bits/stdc++.h>
#include <string>

using namespace std;

static int rent;
static int callback_get_rent(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        rent = atoi(argv[i]);
    }
    return 0;
}
int calculateRent(string check_in_date, string check_out_date, string room_type){
    sqlite3 *DB;
    int days, months, years;
    int myCursor = 0;
    char *error;
    
    myCursor = sqlite3_open("AJAX HMS.db", &DB);
    //error handling
    if(myCursor){
        cerr << "Error While Loading Database!\n";
        cout << sqlite3_errmsg(DB) << "\n";
        return -1;
    }

    days = stoi(check_out_date.substr(8,10)) - stoi(check_in_date.substr(8, 10)); // here stoi function is used to convert string to integer
    months = stoi(check_out_date.substr(5,7)) - stoi(check_in_date.substr(5,7));
    years = stoi(check_out_date.substr(0,4)) - stoi(check_in_date.substr(0,4));

    int nodStay = days + months*30 + years*12*30;
    


