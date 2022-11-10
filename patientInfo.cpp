#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int patientinfo(){
    int choice1;
    cout << "<<--------------------------- PATIENT DETAIL --------------------------->>\n";
    cout << "1. Get PATIENT Details Alphabetically...->>" << endl;
    cout << "2. Get PATIENT Details ID Wise...->> " << endl;
    cout << "3. Get PATIENT Details Check IN Date Wise...->> " << endl;
    cout << "4. Get PATIENT Details Check OUT Date Wise...->> " << endl;
    cout << "<<----------------------------------------------------------------------->>\n";
    cout << "5. Back To Main Menu... ->> " << endl;
    cout << "\nEnter Choice ->> " << endl;
    cin >> choice1;
    cout << "\n";
    system("cls");
    switch (choice1)
    {
    case 1:
    {
        cout << "<<--------------------------- PATIENT DETAIL --------------------------->>\n";
        queryExec("SELECT * FROM AJAX_PATIENT_DB ORDER BY NAME ASC;");
        break;
    }
    case 2:
    {
        int search_ID;
        cout << "\n";
        cout << "<<--------------------------- ENTER PATIENT DETAIL --------------------------->>\n";
        cout << "Enter PATIENT ID to search ->> ";
        cin >> search_ID;
        //cout << "--- PATIENT DETAILS ---\n\n";
        queryExec("SELECT * FROM AJAX_PATIENT_DB WHERE ID = " + to_string(search_ID) + ";");
        break;
    }
    case 3:
    {
        string search_check_in_date;
        cout << "\n";
        cout << "Enter Check IN Date to search (YYYY-MM-DD) ->> ";
        cin >> search_check_in_date;
        cout << "--- PATIENT DETAILS ---\n\n";
        queryExec("SELECT * FROM AJAX_PATIENT_DB WHERE IN_DATE = '" + search_check_in_date + "';");
        break;
    }
    case 4:
    {
        string search_check_out_date;
        cout << "\n";
        cout << "Enter Check OUT Date to search (YYYY-MM-DD) ->> ";
        cin >> search_check_out_date;
        cout << "<<--------------------------- PATIENT DETAIL --------------------------->>\n";
        queryExec("SELECT * FROM AJAX_PATIENT_DB WHERE OUT_DATE = '" + search_check_out_date + "';");
        break;
    }
    case 5:
    {
        break;
    }
    default:
        cout << "Sorry, Wrong Choice !!!\n";
    }
    return 0;
}


