#include <bits/stdc++.h>
#include <sqlite3.h>
#include <string>
#include<iostream>
#include<conio.h>

#include "insertion_check.cpp"
#include "patient.cpp"
#include "addpatient.cpp"
#include "doctor_detail.cpp"
#include "addDoctor.cpp"
#include "staff.cpp"
#include "add_staff.cpp"
#include "query_exec.cpp"
#include "update.cpp"
#include "deleteRecord.cpp"
#include "patientInfo.cpp"
#include "medical_store.cpp"

void Quarycases();
using namespace std;
bool flagmain = true;

int mainMenu()
{
    int choice;
    int choice1;
    flagmain = true;
    while (flagmain)
    {   
        system("cls");
        cout<<"\n\n";
        cout << "<<-------------------------------* ADD DATA *------------------------------->>" << endl;
        cout << "\t1. Add New patient      \t << 1 >>" << endl;
        cout << "\t2. Add Doctor detail    \t << 2 >>" << endl;
        cout << "\t3. Add staff detail     \t << 3 >>" << endl;
        cout << "<<-----------------------------* UPDATE DATA *----------------------------->>" << endl;
        cout << "\t4. Update patient Record\t << 4 >>" << endl;
        cout << "\t5. Update Doctor Record \t << 5 >>" << endl;
        cout << "\t6. Update staff Record  \t << 6 >>" << endl;
        cout << "<<-----------------------------* DELETE DATA *----------------------------->>" << endl;
        cout << "\t7. Delete patient Record\t << 7 >>" << endl;
        cout << "\t8. Delete Doctor Record \t << 8 >>" << endl;
        cout << "\t9. Delete staff Record  \t << 9 >>" << endl;
        cout << "<<--------------------* CHECk (Patient/Doctor/Staff) DATA *------------------>>" << endl;
        cout << "\t10. Quary Menu          \t << 10 >>" << endl;
        cout << "<<------------------------------* STORE DATA *------------------------------->>" << endl;
        cout << "\t11. Check medical store Data    \t<< 11 >>" << endl;
        cout << "\t12. Update medical store Data   \t<< 12 >>" << endl;
        cout << "<<-------------------------------*  EXIT   *------------------------------>>" << endl;
        cout << "\t13. exit " << endl;
        
        cout << "\tPlease Enter the choice(1-13): " <<"  ";

        cin >> choice;
         
        switch (choice)
        {
        case 1:
        {
            cout << "\n";
            system("cls");
            cout << "   <<--------------------------- ENTER PATIENT DETAIL --------------------------->>\n";
            addpatient();
            cout<<"DATA ADDED SUCCESFULLY !!!"<<endl;
            system("pause");
            break;
        }
        case 2:
        {
            
            system("cls");
            cout << "\n";
            cout << "<<--------------------------- ENTER DOCTOR DETAIL --------------------------->>\n";
            addDoctor();
            cout<<"DATA ADDED SUCCESFULLY !!!"<<endl;
            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            cout << "\n";
            cout << "<<--------------------------- ENTER STAFF DETAIL --------------------------->>\n";
            addstaff();
            cout<<"Data ADDED SUCCESFULLY !!!"<<endl;
            system("pause");
            break;
        }
        case 4:
        {
            system("cls");
            cout << "\n";
            cout << "<<--------------------------- UPDATE PATIENT RECORD --------------------------->>\n";
            updatePatientRecord();
            cout<<"DATA UPDATED SUCCESFULLY !!!"<<endl;
            system("pause");
            break;
        }
        case 5:
        {
            system("cls");
            cout << "\n";
            cout << "<<--------------------------- UPDATE DOCTOR RECORD --------------------------->>\n";
            updateDoctorRecord();
            cout<<"DATA UPDATED SUCCESFULLY !!!"<<endl;
            system("pause");
            break;
        }
        case 6:
        {
            system("cls");
            cout << "\n";
            cout << "<<--------------------------- UPDATE STAFF RECORD --------------------------->>\n";
            updatestaffRecord();
            cout<<"DATA UPDATED SUCCESFULLY !!!"<<endl;
            system("pause");
            break;
        }
        case 7:
        {
            system("cls");
            cout << "\n";
            cout << "<<--------------------------- DELETE PATIENT DETAIL --------------------------->>\n";
            deletePatientRecord();
            cout<<"DATA DELETED SUCCESFULLY !!!"<<endl;
            system("pause");
            break;
        }
        case 8:
        {
            system("cls");
            cout << "\n";
            cout << "<<--------------------------- DELETE DOCTOR DETAIL --------------------------->>\n";
            deleteDoctorRecord();
            cout<<"DATA DELETED SUCCESFULLY !!!"<<endl;
            system("pause");
            break;
        }
        case 9:
        {
            system("cls");
            cout << "\n";
            cout << "<<--------------------------- DELETE STAFF DETAIL --------------------------->>\n";
            deletestaffRecord();
            cout<<"DATA DELETED SUCCESFULLY !!!"<<endl;
            system("pause");
            break;
        }
        case 10:
        {
            system("cls");
            cout << "\n";
            Quarycases();
            break;
        }
        case 11:
        {
            system("cls");
            store s;
            cout << "\n";
            cout << "<<--------------------------- MEDICINE STOCK DETAIL --------------------------->>\n";
            s.display_store_detail();
            break;
        }
        case 12:
        {   system("cls");
            store s;
            cout << "\n";
            cout << "<<--------------------------- UPDATE STORE DETAIL --------------------------->>\n";
            s.medicine_stock();
            cout<<"DATA UPDATED SUCCESFULLY !!!"<<endl;
            system("pause");
            break;
        }
        case 13:
        {
            flagmain = false;
            break;
        }
        default:
            cout << "\n";
            cout << "Sorry, Wrong Choice !!!\n"<< endl;
             system("pause");
            break;
        }
    }
    return 0;
}
int main()
{
    string password, userID;
    int flag = 0;
    int flag2 = 0;
    patient P(true);
    Doctor D(true);
    Staff S(true);
    store s(true);
    int ch;
    string pass;

    system("cls");
    do
    {
        system("cls");
        //system("color C");
        cout<<"\n";
        cout<<"\n";
        cout<<"\t\t       |      *************** MAIN MENU ***************        | " <<endl;
        cout<<"\t\t       |               HOSPITAL MANAGEMENT SYSTEM              | " <<endl;
        cout<<"\t\t       | ===================================================   | " <<endl;
        cout<<"\n\n"<<endl;
        cout << "   <---------------------------------------CHOICES------------------------------------------>\n";
        cout << "\t1. Admin\n";
        cout << "\t2. Receptionist\n";
        cout << "\t3. Doctor\n";
        cout << "\t4. Store Manager\n";
        cout << "\t5. Exit From The SYSTEM\n";
        cout << "   <------------------------------------------------------------------------------------------>\n";
        cout << "\tPlease Enter Your Choice (1-5) : ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
            case 1: //  Admin
            {
                //system("cls");
                if (flag == 0)
                {
                    cout << "<---------------------------ENTER ADMIN DETAIL----------------------->\n";
                    cout << "\tEnter the Admin user ID : " << " ";
                    fflush(stdin);
                    getline(cin, userID);
                    int Y = userID.compare("Admin");
                    if (Y == 0)
                    {
                       string pass ="";
                        char ch2;
                        cout << "\tEnter Admin password :";
                        ch2 = _getch();
                        while(ch2 != 13){//character 13 is enter
                            pass.push_back(ch2);
                            cout << '*';
                            ch2 = _getch();
                        }
                        if(pass == "Admin")
                        {
                            int exit = mainMenu();
                            if (exit)
                                return 0;
                        }
                        else
                        {

                            cout<<"\n";
                            cout << "You Entered a wrong password !!!" << endl;
                            system("pause");

                        }
                    }
                    else
                    {
                        cout<<"\n";
                        cout << "You Entered a wrong user ID !!! " << endl;
                        system("pause");
                    }
                
                
                break;
             }
            case 2: // Receptionist
            {
                //system("cls");
                string rec_UserID;
                cout << "<---------------------------ENTER RECEPTIONIST DETAIL----------------------->\n";
                cout << "\tEnter the Receptionist userId: ";
                fflush(stdin);
                getline(cin, rec_UserID);
                int Y = rec_UserID.compare("receptionist");
                if (Y == 0)
                {
                     string pass ="";
                        char ch2;
                        cout << "\tEnter Receptionist password :";
                        ch2 = _getch();
                        while(ch2 != 13){//character 13 is enter
                            pass.push_back(ch2);
                            cout << '*';
                            ch2 = _getch();
                        }
                    if(pass == "receptionist")
                    {
                        system("cls");
                        do
                        {  
                            system("cls");
                            cout<<"\n";
                            cout << "<<---------------------------ENTRY MENU--------------------------->>\n";
                            cout << "\t1.CREATE PATIENT RECORD\n";
                            cout << "\t2.DISPLAY ALL PATIENTS RECORDS\n";
                            cout << "\t3.DISPLAY  PATIENTS RECORDS BY ID\n";
                            cout << "\t4.MODIFY PATIENT RECORD\n";
                            cout << "\t5.DELETE PATIENT RECORD\n";
                            cout << "\t6.CHECK DOCTOR AVAILABILITY\n";
                            cout << "\t7.ROOM ALLOTMENT\n";
                            cout << "\t8.ADD PATIENT SUMMARY\n";
                            cout << "\t9.CREATE PATIENT BILL\n";
                            cout << "\t10.TO EXIT\n";
                            cout << "<<---------------------------------------------------------------->>\n";
                            cout << "\t\nPlease Enter Your Choice (1-10) ";
                            cin >> ch;
                            //system("cls");
                            switch (ch)
                            {
                            case 1:
                            {
                                system("cls");
                                cout << "<<--------------------------- CREATE PATIENT DETAIL --------------------------->>\n";
                                addpatient();
                                cout<<"Data ADDED SUCCESFULLY !!!"<<endl;
                                system("pause");
                                break;
                            }
                            case 2:
                            {
                                system("cls");
                                cout << "<<---------------------------PATIENT DETAIL--------------------------->>\n";
                                queryExec("SELECT * FROM AJAX_PATIENT_DB ORDER BY NAME ASC;");
                                break;
                            }
                            case 3:
                            {
                                int search_ID;
                                //system("cls");
                                cout << "\n";
                                cout << "<<--------------------------- ENTER PATIENT DETAIL --------------------------->>\n";
                                cout << "Enter PATIENT ID to search ->> ";
                                cin >> search_ID;
                                system("cls");
                                cout << "<<---------------------------PATIENT DETAIL--------------------------->>\n";
                                queryExec("SELECT * FROM AJAX_PATIENT_DB WHERE ID = " + to_string(search_ID) + ";");
                                system("pause");
                                break;
                            }
                            case 4:
                            {
                                system("cls");
                                cout << "<<---------------------------UPDATE PATIENT DETAIL--------------------------->>\n";
                                updatePatientRecord();
                                cout<<"DATA UPDATED SUCCESFULLY !!!"<<endl;
                                system("pause");
                                break;
                            }
                            case 5:
                            {
                                system("cls");
                                cout << "<<---------------------------DELETE PATIENT DETAIL--------------------------->>\n";
                                deletePatientRecord();
                                cout<<"Data DELETED SUCCESFULLY !!!"<<endl;
                                system("pause");
                                break;
                            }
                             case 6:
                            {
                                system("cls");
                                cout << "<<--------------------------- ENTER DOCTOR DETAIL --------------------------->>\n";
                                queryExec1("SELECT * FROM AJAX_Doctor_receptionist_DB;");
                                break;
                            }
                            case 7:
                            {
                                system("cls");
                                cout << "<<--------------------------- ROOM ALLOTMENT TO PATIENT --------------------------->>\n";
                                room_allotment();
                                cout<<"ROOM ALLOTED SUCCESFULLY !!!"<<endl;
                                system("pause");
                                break;
                            }
                            case 8:
                            {
                                system("cls");
                                cout << "<<--------------------------- ADD PATIENT SUMMARY --------------------------->>\n";
                                patient_Summary();
                                system("pause");
                                break;
                            }
                            case 9:
                            {
                                system("cls");
                                cout << "<<---------------------------PATIENT BILL--------------------------->>\n";
                                patient_bill();
                                system("pause");
                                break;
                            }
                             case 10:
                            {
                                break;
                            }
                            default:
                            {
                                cout << "You Entered Wrong choice !!!" << endl;
                                system("pause");
                                break;
                            }
                            }
                        } while (ch != 10);
                        //return 0;
                    }
                    else
                    {
                        cout << "\tYou Entered a wrong password !!!" << endl;
                         system("pause");
                    }
                }
                else
                {
                    cout << "\tYou Entered a wrong user ID !!! " << endl;
                     system("pause");
                }
               
                break;
            }

            case 3:
            {
                system("cls");
                string doc_UserID;
                cout << "<---------------------------ENTER DOCTOR DETAIL----------------------->\n";
                cout << "\tEnter the doctor userId: "; // this is common for every doctor so that every doctor can use this id to enter for updation
                fflush(stdin);
                getline(cin, doc_UserID);
                int Y = doc_UserID.compare("doctor");
                if (Y == 0)
                {
                   string pass ="";
                        char ch2;
                        cout << "\tEnter Doctor password :";
                        ch2 = _getch();
                        while(ch2 != 13){//character 13 is enter
                            pass.push_back(ch2);
                            cout << '*';
                            ch2 = _getch();
                        }
                    if(pass == "doctor")
                    {
                        do
                        {
                            system("cls");
                            cout << "\t\t\n\n\n";
                            cout << "<<--------------------------- ADD PATIENT PRESCRIPTION DETAIL --------------------------->>\n";
                            cout << "\t\t\n1. Prescribe Medicine for patient ->>" << endl;
                            cout << "\t\t\n2. Search DOCTOR ->>" << endl;
                            cout << "\t\t\n3. Check  Patient Update ->>" << endl;
                            cout << "\t\t\n4. To exit....." << endl;
                            cout << "<<--------------------------------------------------------------------------------------->>\n";
                            cout << "\t\t\nPlease Select Your Option (1-4)" << " ";
                            cin >> ch;
                            system("cls");
                            switch (ch)
                            {
                            case 1:
                            {
                                Patient_prescription();
                                system("pause");
                                break;
                            }
                            case 2:
                            {
                                int search_ID;
                                cout << "\n";
                                cout << "<<--------------------------- ENTER DOCTOR DETAIL --------------------------->>\n";
                                cout << "Enter DOCTOR ID to search ->> ";
                                cin >> search_ID;
                                //cout << "---DOCTOR DETAILS ---\n\n";
                                queryExec1("SELECT * FROM AJAX_Doctor_DB WHERE ID = " + to_string(search_ID) + ";");
                                break;
                            }
                            case 3:
                            {
                                patientinfo();
                                break;
                            }
                            case 4:
                            {
                                cout << " " << endl;
                                break;
                            }
                            default:
                            {
                                cout<<"\n";
                                cout << "You Entered wrong choice !!! " << endl;
                                system("pause");
                                break;
                            }
                            break;
                            }
                            } while (ch != 4);
                    
                    }
                    else
                    {
                        cout<<"\n";
                        cout << "You Entered a wrong password !!!" << endl;
                        system("pause");
                    }
                }
                else
                {
                    cout<<"\n";
                    cout << "You Entered a wrong user ID !!! " << endl;
                    system("pause");
                }
                break;
                return 0;
            }

            case 4:
            {
                system("cls");
                string store_userId,password;
                cout << "<---------------------------ENTER STORE MANAGER DETAIL----------------------->\n";
                cout<<"\tEnter the store managers Used Id : "<<" ";
                fflush(stdin);
                getline(cin,store_userId);
                int Y = store_userId.compare("store");
                if(Y==0)
                {
                    string pass ="";
                        char ch2;
                        cout << "\tEnter store manager password : ";
                        ch2 = _getch();
                        while(ch2 != 13){//character 13 is enter
                            pass.push_back(ch2);
                            cout << '*';
                            ch2 = _getch();
                        }
                    if(pass == "store")
                    {
                        do
                        {
                            system("cls");
                            cout << "<<--------------------------- MED + STORE DETAIL --------------------------->>\n";
                           // cout << "\t\t\n\n\n";
                            cout << "\t1. Patient order  ->>" << endl;
                            cout << "\t2. Show Order Products    ->>" << endl;
                            //cout << "\t\t\n3. Create bill   ->>" << endl;
                            cout << "\t3. Check Medicine stock   ->>" << endl;
                            cout << "\t4. Update stock Medicine   ->>" << endl;
                            cout << "\t5. Order stock Medicine   ->>" << endl;
                            cout << "\t6. show stock Order Medicine detail  ->>" << endl;
                            cout << "\t7. To exit....." << endl;
                            cout << "<<---------------------------------------------------------------->>\n";
                            cout << "\tPlease Select Your Option (1-7)" << " ";
                            cin >> ch;
                            switch (ch)
                            {
                                case 1:
                                {
                                    system("cls");
                                    store s;
                                    cout << "<<--------------------------- ADD PATIENT ORDER DETAIL --------------------------->>\n";
                                    s.add_customer_order();
                                    cout<<"PATIENT ORDER SUCCESFULLY !!!"<<endl;
                                    system("pause");
                                    break;
                                }
                                case 2:
                                {   
                                    system("cls");
                                    store s;
                                     cout << "<<--------------------------- PATIENT MEDICINE ORDER DETAIL --------------------------->>\n";
                                    s.display_patient_orderdetail();
                                    //system("pause");
                                     break;
                                }
                                case 3:
                                {
                                    system("cls");
                                    store s;
                                    cout << "<<--------------------------- MEDICINE STOCK DETAIL --------------------------->>\n";
                                    s.display_store_detail();
                                    //system("pause");
                                    break;
                                }
                                case 4:
                                {   system("cls");
                                    store s;
                                     cout << "<<--------------------------- UPDATE STORE DETAIL --------------------------->>\n";
                                    s.medicine_stock();
                                    cout<<"STORE DATA UPDATED SUCCESFULLY !!!"<<endl;
                                    system("pause");
                                    break;
                                }
                                case 5:
                                {
                                    system("cls");
                                    store s;
                                    cout << "<<--------------------------- UPDATE STOCK ORDER DETAIL --------------------------->>\n";
                                    s.orderproducts();
                                   // cout<<"PATIENT ORDER SUCCESFULLY !!!"<<endl;
                                    system("pause");
                                    break; 
                                }
                                case 6:
                                {   
                                    system("cls");
                                    store s;
                                    cout << "<<--------------------------- STOCK MEDICINE ORDER DETAIL--------------------------->>\n";
                                    s.display_stock_orderdetail();
                                    //system("pause");
                                    break;
                                }
                                case 7:
                                {
                                    cout<<" "<<endl;
                                    break;
                                }                        
                                default:
                                {
                                    //cout << "You Entered wrong choice !!! " << endl;
                                     system("pause");
                                    break;
                                }
                                break;
                            }
                        } while (ch != 7);
                    }
                    else
                    {
                        cout<<"\n";
                        cout << "You Entered a wrong password !!!" << endl;
                         system("pause");
                    }
                }
                else
                {
                    cout<<"\n";
                    cout << "You Entered a wrong user ID !!! " << endl;
                    system("pause");
                }

                break;
            }

            case 5:
            {
                cout<<"\n";
                cout<<"\n";
                cout << "   <------------------------------------------------------------------------------------------>\n";
                cout << "\t\t\t\t\tTHANK YOU \n";
                cout << "\t\t\t\t\tFOR USING \n";
                cout << "\t\t\t\tHOSPITAL MANAGEMENT SYSTEM !!! \n";
                cout << "   <--------------------------------************************************----------------------->\n";
                return 1;
            }
            }
            default:
                cout << "Wrong Choice !!!" << endl;
                break;
        }
    }
    while (ch != 5);
    return 0;
    }



void Quarycases()
{
    int choice1;
    cout<<"\n";
    cout << "<<--------------------------- CHECK (PATIENT/DOCTOR/STAFF) RECORDS  --------------------------->>\n";
    cout << "\t<< 1 >>  Patient Info  " << endl;
    cout << "\t<< 2 >>  Doctor Info  " << endl;
    cout << "\t<< 3 >>  staff Info  " << endl;
    cout << "\t<< 4 >>  exit->>  " << endl;
    cout << "<<----------------------------------------------------------------------------=----------------->>\n";
    cout << "\t\t\nEnter the choice that you want to know the Information " << " ";
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        system("cls");
        cout<<"\n";
        cout << "<<--------------------------- ENTER PATIENT DETAIL --------------------------->>\n";
        cout << "\t1. Get PATIENT Details Alphabetically...->>" << endl;
        cout << "\t2. Get PATIENT Details ID Wise...->> " << endl;
        cout << "\t3. Get PATIENT Details Check IN Date Wise...->> " << endl;
        cout << "\t4. Get PATIENT Details Check OUT Date Wise...->> " << endl;
        cout << "\t5. Back To Main Menu... ->> " << endl;
        cout << "<<----------------------------------------------------------------------------->>\n";
        cout << "\t\t\nEnter Choice ->> " <<" ";
        cin >> choice1;
        cout << "\n";
        switch (choice1)
        {
        case 1:
        {
            //cout << "--- PATIENT DETAILS ---\n\n";
            system("cls");
            queryExec("SELECT * FROM AJAX_PATIENT_DB ORDER BY NAME ASC;");
            break;
        }
        case 2:
        {
            int search_ID;
            system("cls");
            cout << "Enter PATIENT ID to search ->> ";
            cin >> search_ID;
            cout << "--- PATIENT DETAILS ---\n\n";
            queryExec("SELECT * FROM AJAX_PATIENT_DB WHERE ID = " + to_string(search_ID) + ";");
            break;
        }
        case 3:
        {
             system("cls");
            string search_check_in_date;
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
            cout << "--- PATIENT DETAILS ---\n\n";
            queryExec("SELECT * FROM AJAX_PATIENT_DB WHERE OUT_DATE = '" + search_check_out_date + "';");
            break;
        }
        case 5:
        {
            break;
        }
        default:
            cout << "Sorry, Wrong Choice !!!\n";
            break;
        }
        break;
    }
    case 2:
    {
        system("cls");
        cout<<"\n";
        cout << "<<--------------------------- ENTER DOCTOR DETAIL --------------------------->>\n";
        cout << "\t1. Get Doctor Details Alphabetically...->>" << endl;
        cout << "\t2. Get Doctor Details ID Wise...->> " << endl;
        cout << "\t3. Get Doctor Details Check OUT Date Wise...->> " << endl;
        cout << "\t5. Back To Main Menu... ->> " << endl;
        cout << "<<----------------------------------------------------------------------------->>\n";
        cout << "\nEnter Choice ->> " << " ";

        cin >> choice1;
        cout << "\n";
        switch (choice1)
        {
        case 1:
        {
            system("cls");
            cout << "<<--------------------------- ENTER DOCTOR DETAIL --------------------------->>\n";
            queryExec1("SELECT * FROM AJAX_Doctor_DB ORDER BY NAME ASC;");
            break;
        }
        case 2:
        {
            system("cls");
            int search_ID;
            cout << "\n";
            cout << "Enter DOCTOR ID to search ->> ";
            cin >> search_ID;
            cout << "<<--------------------------- DOCTOR DETAIL --------------------------->>\n";
            queryExec1("SELECT * FROM AJAX_Doctor_DB WHERE ID = " + to_string(search_ID) + ";");
            break;
        }
        case 3:
        {
            system("cls");
            string search_check_in_date;
            cout << "\n";
            cout << "Enter Check IN Date to search (YYYY-MM-DD) ->> ";
            cin >> search_check_in_date;
            cout << "<<--------------------------- DOCTOR DETAIL --------------------------->>\n";
            queryExec1("SELECT * FROM AJAX_Doctor_DB WHERE IN_DATE = '" + search_check_in_date + "';");
            break;
        }
        case 4:
        {
            string search_check_out_date;
            cout << "\n";
            cout << "Enter Check OUT Date to search (YYYY-MM-DD) ->> ";
            cin >> search_check_out_date;
            cout << "<<--------------------------- DOCTOR DETAIL --------------------------->>\n";
            queryExec1("SELECT * FROM AJAX_Doctor_DB WHERE OUT_DATE = '" + search_check_out_date + "';");
            break;
        }
        case 5:
        {
            break;
        }
        default:
            cout << "Sorry, Wrong Choice !!!\n";
            break;
        }
        break;
    }
    case 3:
    {
        system("cls");
        cout << "<<--------------------------- ENTER STAFF DETAIL --------------------------->>\n";
        cout << "\t1. Get STAFF Details Alphabetically...->>" << endl;
        cout << "\t2. Get STAFF Details ID Wise...->> " << endl;
        cout << "\t3. Get STAFF Details Check IN Date Wise...->> " << endl;
        cout << "\t4. Get STAFF Details Check OUT Date Wise...->> " << endl;
        cout << "\t5. Back To Main Menu... ->> " << endl;
        cout << "\nEnter Choice ->> " << " ";
        cin >> choice1;
        cout << "\n";
        switch (choice1)
        {
        case 1:
        {
            system("cls");
            cout << "<<--------------------------- STAFF DETAIL --------------------------->>\n";
            queryExec2("SELECT * FROM AJAX_staff_DB ORDER BY NAME ASC;");
            break;
        }
        case 2:
        {
            system("cls");
            int search_ID;
            cout << "\n";
            cout << "Enter STAFF ID to search ->> ";
            cin >> search_ID;
            cout << "<<--------------------------- STAFF DETAIL --------------------------->>\n";
            queryExec2("SELECT * FROM AJAX_staff_DB WHERE ID = " + to_string(search_ID) + ";");
            break;
        }
        case 3:
        {
            system("cls");
            string search_check_in_date;
            cout << "\n";
            cout << "Enter Check IN Date to search (YYYY-MM-DD) ->> ";
            cin >> search_check_in_date;
            cout << "<<--------------------------- STAFF DETAIL --------------------------->>\n";
            queryExec2("SELECT * FROM AJAX_staff_DB WHERE IN_DATE = '" + search_check_in_date + "';");
            break;
        }
        case 4:
        {
            system("cls");
            string search_check_out_date;
            cout << "\n";
            cout << "Enter Check OUT Date to search (YYYY-MM-DD) ->> ";
            cin >> search_check_out_date;
            cout << "--- STAFF DETAILS ---\n\n";
            queryExec2("SELECT * FROM AJAX_staff_DB WHERE OUT_DATE = '" + search_check_out_date + "';");
            break;
        }
        case 5:
        {
            break;
        }
        default:
            cout << "Sorry, Wrong Choice !!!\n";
        }
        break;
    }
    case 4:
    {
        break;
    }
    default:
        cout << "Sorry, Wrong Choice !!!\n";
    }
}