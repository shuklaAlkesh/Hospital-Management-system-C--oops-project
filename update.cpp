#include <bits/stdc++.h>
#include <string>
#include<sqlite3.h>

using namespace std;
int count__=0;
static int callback_get_count1(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        count__ = atoi(argv[i]);
    }
    return 0;
}
static int callback_get_count3(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        count__ = atoi(argv[i]);
    }
    return 0;
}


int updatePatientRecord()
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
    cout << "Enter ID Number To Update Patient record ->> ";
    cin >> ID;
    string query;

    query = "SELECT COUNT (ALL) FROM AJAX_PATIENT_DB WHERE ID = "+to_string(ID)+";";
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_count1, NULL, NULL);
    if(count__==0){
        cout << "No Patient Found\n";
        return 0;
    }
    system("cls");
    int ch1;
    cout << "<<---------------------------ENTRY MENU--------------------------->>\n";
    cout << "\n\n\n\tENTRY MENU TO UPDATE DATA ";
    cout << "\n\n\t1.UPDATE Name ";
    cout << "\n\n\t2.UPDATE ADDRESS ";
    cout << "\n\n\t3.UPDATE AGE ";
    cout << "\n\n\t4.UPDATE ADDHARCARD NUMBER ";
    cout << "\n\n\t5.UPDATE MOBILE NUMBER ";
    cout << "\n\n\t6.UPDATE CheckOutDate & checkInTime :";
    cout << "\n\n\t7.exit... ";
    cout << "\n<<---------------------------------------------------------------->>\n";
    cout<<"Choose A Number that you want to update : "<<" " ;
    cin>>ch1;
    system("cls");
    if(ch1==1){
        //system("cls");
        string Name;
        cout<<"Enter the New Name : ";
        fflush(stdin);
        getline(cin,Name);
        query = "UPDATE AJAX_PATIENT_DB SET NAME = '"+Name+"' WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        //cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        //system("pause");
    }
    else if(ch1==2){
        //system("cls");
        string Address;
        cout<<"Enter the New ADDRESS : ";
        fflush(stdin);
        getline(cin,Address);
        query = "UPDATE AJAX_PATIENT_DB SET ADDRESS = '"+Address+"' WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        // system("pause");
    }
    else if(ch1==3){
       // system("cls");
        int Age;
        cout<<"Enter the New Age : ";
        fflush(stdin);
        cin>>Age;
        query = "UPDATE AJAX_PATIENT_DB SET Age = "+to_string(Age)+" WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        // system("pause");
    }
    else if(ch1==4){
        //system("cls");
        string Aadhar_NO;
        cout<<"Enter the New Aadhar card number : ";
        fflush(stdin);
        getline(cin,Aadhar_NO);
        query = "UPDATE AJAX_PATIENT_DB SET AADHAR= '"+Aadhar_NO+"' WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        // system("pause");
    }
    else if(ch1==5){

        string Mobile_NO;
        cout<<"Enter the New Mobile Number : ";
        fflush(stdin);
        getline(cin,Mobile_NO);
        query = "UPDATE AJAX_PATIENT_DB SET MOBILE= '"+Mobile_NO+"' WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        // system("pause");
    }
    else if(ch1==6){
        string checkOutdate,checkoutTime;
        cout<<"Enter the checkout date (YYYY-MM-DD) of the patient ID-"<<ID<<" : "<<" ";
        fflush(stdin);
        getline(cin,checkOutdate);
        cout<<"Enter the CheckOut time (HH:MM) :"<<" ";
        fflush(stdin);
        getline(cin,checkoutTime);

        query = "UPDATE AJAX_PATIENT_DB SET OUT_DATE = '"+checkOutdate+"', OUT_TIME = '"+checkoutTime+"' WHERE ID = "+to_string(ID)+";";
        //char *error;
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        // system("pause");
    }
    else if(ch1==7)
    {
        return 0;
    }
    else{
        cout<<"Sorry You Entered Wrong choice !!!"<<endl;
        system("pause");
        return 0;
    }
    sqlite3_close(DB);
    return 0;
}

    int room_allotment()
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
    
        cout << "\t\t\n\n\n";
        int ID;
        cout << "Enter Patient ID Number To Room Allotment  ->> ";
        cin >> ID;
        cout << "\n\n";
        cout << "<<--------------------------- ROOM ALLOTMENT MENU --------------------------->>\n";
        cout << "\t\t\n1. GENERAL WARD      (GN) ->> 300 Rs/Day " << endl;
        cout << "\t\t\n2. Twin Sharing Room (TS) ->> 500 Rs/Day "<< endl;
        cout << "\t\t\n3. Private room      (PR) ->> 800 Rs/Day " << endl;
        cout << "\t\t\n4. To exit....." << endl;
        cout << "<<--------------------------------------------------------------------------------------->>\n";
        cout << "\t\t\nPlease Select Your Option (1-4)" << " ";
        int ch;
        cin >> ch;
        system("cls");
        switch (ch)
        {
            case 1:
            {
            string room;
            cout << "<<--------------------------- ENTER GENERAL WARD ROOM DETAIL --------------------------->>\n";
                cout<< "\tEnter Room number "<<" ";
                fflush(stdin);
                getline(cin,room);
                string room_NO = "GN-"+room+" ";
                query = "UPDATE AJAX_PATIENT_DB SET ROOM_ALLOTED = '"+room_NO+"' WHERE ID = "+to_string(ID)+";";
                myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
                insertion_check(myCursor, error);
                //system("pause");
                break;
            }
            case 2:
            {
            string room;
            cout << "<<--------------------------- ENTER TWIN SHARING ROOM DETAIL --------------------------->>\n";
                cout<< "\tEnter Room number "<<" ";
                fflush(stdin);
                getline(cin,room);
                string room_NO = "TS-"+room+" ";
                query = "UPDATE AJAX_PATIENT_DB SET ROOM_ALLOTED = '"+room_NO+"' WHERE ID = "+to_string(ID)+";";
                myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
                insertion_check(myCursor, error);
                //system("pause");
                break;
            }
            case 3:
            {
            string room;
            cout << "<<--------------------------- ENTER PRIVATE ROOM DETAIL --------------------------->>\n";
                cout<< "\tEnter Room number "<<" ";
                fflush(stdin);
                getline(cin,room);
                string room_NO = "PR-"+room+" ";
                query = "UPDATE AJAX_PATIENT_DB SET ROOM_ALLOTED = '"+room_NO+"' WHERE ID = "+to_string(ID)+";";
                myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
                insertion_check(myCursor, error);
                //system("pause");
                break;
            }
            case 4:
            {
                break;
            }
            default:
            {
                cout<<"\n";
                cout << "You Entered wrong choice !!! " << endl;
                system("pause");
                break;
            }
        }
        sqlite3_close(DB);
        return 0;

    }

   int patient_Summary()
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
        cout << "Enter patient ID Number to Add Patient Summary ->> ";
        cin >> ID;
        string patient_Summary;
        cout<<"Enter the patient_Summary : ";
        fflush(stdin);
        getline(cin,patient_Summary);
        query = "UPDATE AJAX_PATIENT_DB SET PATIENT_SUMMARY = '"+patient_Summary+"' WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        sqlite3_close(DB);
        return 0;
    }

int updateDoctorRecord()
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
    cout << "Enter ID Number To Update Doctor record ->> ";
    cin >> ID;
    string query;

    query = "SELECT COUNT (ALL) FROM AJAX_Doctor_DB WHERE ID = "+to_string(ID)+";";
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_count3, NULL, NULL);
    if(count__==0){
        cout << "No Doctor Found\n";
        return 0;
    }
    int ch1;
    system("cls");
    cout << "<<------------------------------ENTRY MENU------------------------------>>\n";
    cout << "\n\n\n\tENTRY MENU TO UPDATE DATA ";
    cout << "\n\n\t1.UPDATE Name ";
    cout << "\n\n\t2.UPDATE ADDRESS ";
    cout << "\n\n\t3.UPDATE AGE ";
    cout << "\n\n\t4.UPDATE ADDHARCARD NUMBER ";
    cout << "\n\n\t5.UPDATE MOBILE NUMBER ";
    cout << "\n\n\t6.UPDATE Specialisation ";
    cout << "\n\n\t7.UPDATE SALARY";
    cout << "\n\n\t8.UPDATE Date & Time :";
    cout << "\n\n\t9.EXIT... ";
    cout << "\n<<----------------------------------------------------------------------->>\n";



    cout<<"Choose A Number that you want to update : "<<" ";
    cin>>ch1;
    if(ch1==1){
        system("cls");
        string Name;
        cout<<"Enter the New Name : ";
        fflush(stdin);
        getline(cin,Name);
        query = "UPDATE AJAX_Doctor_DB SET NAME = '"+Name+"' WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        // system("pause");
    }
    else if(ch1==2){
        system("cls");
        string Address;
        cout<<"Enter the New ADDRESS : ";
        fflush(stdin);
        getline(cin,Address);
        query = "UPDATE AJAX_Doctor_DB SET ADDRESS = '"+Address+"' WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        // system("pause");
    }
    else if(ch1==3){
        system("cls");
        int Age;
        cout<<"Enter the New Age : ";
        fflush(stdin);
        cin>>Age;
        query = "UPDATE AJAX_Doctor_DB SET Age = "+to_string(Age)+" WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        // system("pause");
    }
    else if(ch1==4){
        string Aadhar_NO;
        cout<<"Enter the New Aadhar card number : ";
        fflush(stdin);
        getline(cin,Aadhar_NO);
        query = "UPDATE AJAX_Doctor_DB SET AADHAR= '"+Aadhar_NO+"' WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        // system("pause");
    }
    else if(ch1==5){
        string Mobile_NO;
        cout<<"Enter the New Mobile Number : ";
        fflush(stdin);
        getline(cin,Mobile_NO);
        query = "UPDATE AJAX_Doctor_DB SET MOBILE= '"+Mobile_NO+"' WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
    //     cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
    //     system("pause");
    }
    else if(ch1==8){
        system("cls");
        cout << "<<---------------------------ENTRY MENU--------------------------->>\n";
        cout << "\n\t1.UPDATE CHECK IN TIME ";
        cout << "\n\n\t2.UPDATE CHECK OUT TIME";
        cout << "\n\n\t3.UPDATE CHECK OUT DATE ";
        cout << "\n\n\t4. EXIT...";
        cout << "\n<<--------------------------------------------------------------->>\n";
        cout << "\n\t ENTER CHOICE (1-4) : "<<" ";
        int ch;
        cin>> ch;
        string checkOutdate,checkoutTime,checkInTime;
        if(ch==1){
            cout<<"Enter the CheckIN TIME (HH:MM)"<<" ";
            fflush(stdin);
            getline(cin,checkInTime);
            query = "UPDATE AJAX_Doctor_DB SET  IN_TIME = '"+checkInTime+"' WHERE ID = "+to_string(ID)+";";
             query = "UPDATE AJAX_Doctor_receptionist_DB SET  IN_TIME = '"+checkInTime+"' WHERE ID = "+to_string(ID)+";";
            myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
            insertion_check(myCursor, error);
            // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
            // system("pause");
        }
        else if(ch==2){
            cout<<"Enter the CheckOUT time (HH:MM)"<<" ";
            fflush(stdin);
            getline(cin,checkoutTime);  
            query = "UPDATE AJAX_Doctor_DB SET  OUT_TIME = '"+checkoutTime+"' WHERE ID = "+to_string(ID)+";";
             query = "UPDATE AJAX_Doctor_receptionist_DB SET  IN_TIME = '"+checkInTime+"' WHERE ID = "+to_string(ID)+";";
            myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
            insertion_check(myCursor, error);
            // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
            // system("pause");

        }
        else if(ch==3){
            cout<<"Enter the checkout date (YYYY-MM-DD) of the patient ID "<<ID<<" : "<<" ";
            fflush(stdin);
            getline(cin,checkOutdate);
            query = "UPDATE AJAX_Doctor_DB SET OUT_DATE = '"+checkOutdate+"' WHERE ID = "+to_string(ID)+";";
             query = "UPDATE AJAX_Doctor_receptionist_DB SET  IN_TIME = '"+checkInTime+"' WHERE ID = "+to_string(ID)+";";
            myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
            insertion_check(myCursor, error);
            // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
            // system("pause");
        }
       else if(ch==4) {
        return 0;
       }
    }
    else if(ch1==6)
    {
        string Specialisation;
        cout<<"Enter the New Specialisation : ";
        fflush(stdin);
        getline(cin,Specialisation);
        query = "UPDATE AJAX_Doctor_DB SET Specialisation= '"+Specialisation+"' WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        // system("pause");

    }
    else if(ch1==7){
        string salary;
        cout<<"Enter the New salary : ";
        fflush(stdin);
        getline(cin,salary);
        query = "UPDATE AJAX_Doctor_DB SET Salary = '"+salary+"' WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        // system("pause");
    }
    else if(ch1==9){
        return 0;
    }
    else{
        cout<<"Sorry You Entered Wrong choice !!!"<<endl;
        system("pause");
    }
    sqlite3_close(DB);
    return 0;
}

int updatestaffRecord()
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
    cout << "Enter ID Number To Update staff record ->> ";
    cin >> ID;
    string query;

    query = "SELECT COUNT (ALL) FROM AJAX_staff_DB WHERE ID = "+to_string(ID)+";";
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_count3, NULL, NULL);
    if(count__==0){
        cout << "No Guest Found\n";
        return 0;
    }
    int ch1;
    system("cls");
    cout << "<<---------------------------ENTRY MENU--------------------------->>\n";
    cout << "\n\n\n\tENTRY MENU TO UPDATE DATA ";
    cout << "\n\n\t1.UPDATE Name ";
    cout << "\n\n\t2.UPDATE ADDRESS ";
    cout << "\n\n\t3.UPDATE AGE ";
    cout << "\n\n\t4.UPDATE ADDHARCARD NUMBER ";
    cout << "\n\n\t5.UPDATE MOBILE NUMBER ";
    cout << "\n\n\t6.UPDATE post ";
    cout << "\n\n\t7.UPDATE salary";
    cout << "\n\n\t8.UPDATE Date & Time :";
    cout << "\n\n\t9.EXIT... : ";
    cout << "\n<<---------------------------------------------------------------->>";


    cout<<"\nChoose A Number that you want to update : "<<" ";
    cin>>ch1;
    if(ch1==1){
        string Name;
        cout<<"Enter the New Name : ";
        fflush(stdin);
        getline(cin,Name);
        query = "UPDATE AJAX_staff_DB SET NAME = '"+Name+"' WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        // system("pause");
    }
    else if(ch1==2){
        string Address;
        cout<<"Enter the New ADDRESS : ";
        fflush(stdin);
        getline(cin,Address);
        query = "UPDATE AJAX_staff_DB SET ADDRESS = '"+Address+"' WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        // system("pause");
    }
    else if(ch1==3){
        int Age;
        cout<<"Enter the New Age : ";
        fflush(stdin);
        cin>>Age;
        query = "UPDATE AJAX_staff_DB SET Age = "+to_string(Age)+" WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        // system("pause");
    }
    else if(ch1==4){
        string Aadhar_NO;
        cout<<"Enter the New Aadhar card number : ";
        fflush(stdin);
        getline(cin,Aadhar_NO);
        query = "UPDATE AJAX_staff_DB SET AADHAR= '"+Aadhar_NO+"' WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
    //     cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
    //     system("pause");
    }
    else if(ch1==5){
        string Mobile_NO;
        cout<<"Enter the New Mobile Number : ";
        fflush(stdin);
        getline(cin,Mobile_NO);
        query = "UPDATE AJAX_staff_DB SET MOBILE= '"+Mobile_NO+"' WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        // system("pause");
    }
    else if(ch1==6)
    {
        string post;
        cout<<"Enter the New post : ";
        fflush(stdin);
        getline(cin,post);
        query = "UPDATE AJAX_staff_DB SET POST = '"+post+"' WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        // system("pause");

    }
    else if(ch1==7){
        string salary;
        cout<<"Enter the New salary : ";
        fflush(stdin);
        getline(cin,salary);
        query = "UPDATE AJAX_staff_DB SET SALARY = '"+salary+"' WHERE ID = "+to_string(ID)+";";
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        // system("pause");
    }
    else if(ch1==8){
        system("cls");
        cout << "<<---------------------------ENTRY MENU--------------------------->>\n";
        cout << "\n\n\t1.UPDATE CHECK IN TIME ";
        cout << "\n\n\t2.UPDATE CHECK OUT TIME";
        cout << "\n\n\t3.UPDATE CHECK OUT DATE ";
        cout << "\n\n\t4. EXIT...";
        cout << "\n\t ENTER CHOICE (1-4) : "<<" ";
        cout << "\n<<---------------------------------------------------------------->>\n";
        int ch;
        cin>> ch;
        string checkOutdate,checkoutTime,checkInTime;
        if(ch==1){
            cout<<"Enter the CheckIN TIME (HH:MM)"<<" ";
            fflush(stdin);
            getline(cin,checkInTime);
            query = "UPDATE AJAX_staff_DB SET  IN_TIME = '"+checkInTime+"' WHERE ID = "+to_string(ID)+";";
            myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
            insertion_check(myCursor, error);
            // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
            // system("pause");
        }
        else if(ch==2){
            cout<<"Enter the CheckOUT time (HH:MM)"<<" ";
            fflush(stdin);
            getline(cin,checkoutTime);  
            query = "UPDATE AJAX_staff_DB SET  OUT_TIME = '"+checkoutTime+"' WHERE ID = "+to_string(ID)+";";
            myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
            insertion_check(myCursor, error);
            // cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
            // system("pause");

        }
        else if(ch==3){
            cout<<"Enter the checkout date (YYYY-MM-DD) of the patient ID "<<ID<<" : "<<" ";
            fflush(stdin);
            getline(cin,checkOutdate);
            query = "UPDATE AJAX_staff_DB SET OUT_DATE = '"+checkOutdate+"' WHERE ID = "+to_string(ID)+";";
            myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
            insertion_check(myCursor, error);
        //     cout << "DATA UPDATED SUCCESSFULLY !!!"<<endl;
        //     system("pause");
        }
       else if(ch==4) {
        return 0;
       }
    }
    else if(ch1==9){
        return 0;
    }
    else{
        cout<<"Sorry You Entered Wrong choice !!!"<<endl;
        system("pause");
    }
    sqlite3_close(DB);
    return 0;
}

int Patient_detail()
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
    cout << "Enter Patient ID Number To Update Patient prescribe medicine -->> ";
    cin >> ID;
    string query;

    query = "SELECT COUNT (ALL) FROM AJAX_PATIENT_DB WHERE ID = "+to_string(ID)+";";
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_count1, NULL, NULL);
    if(count__==0){
        cout << "No PATIENT Found\n";
        return 0;
    }
    string prescription;
    cout<<"Enter the prescription to the patient "<<endl;
    fflush(stdin);
    getline(cin,prescription);
    query = "UPDATE AJAX_PATIENT_DB SET PRESCRIPTION = '"+prescription+"' WHERE ID = "+to_string(ID)+";";
    myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
    insertion_check(myCursor, error);
    cout << "PRESCRIPTION UPDATED SUCCESSFULLY !!!"<<endl;
    //system("pause");


    return 0;
}

int Patient_prescription()
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
    string DOC_name;
    cout << "Enter Doctor ID Number To Update patient Prescription ->> ";
    cin >> ID;
    string query;

    query = "SELECT COUNT (ALL) FROM AJAX_Doctor_DB WHERE ID = "+to_string(ID)+";";
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_count3, NULL, NULL);
    if(count__==0){
        cout << "No Doctor Id not Found\n";
        return 0;
    }
   
    cout << "\n\n\n\t UPDATE Prescribe Medicine for patient  "<<endl;
    Patient_detail();
    return 0;


}

        
    