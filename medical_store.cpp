#include <iostream>
#include <bits/stdc++.h>
#include <sqlite3.h>
#include <iomanip>

using namespace std;

class store {
    private:
        int createTable();
        string query, query1,query2;
        string supplierName,productName;
        string Name, address, Gender, blood_g;
        int Age, Date, Month, year;
        int ID,bill,total,unit,price;
        string state, Nationality,aadhar,mobile,doctor_name,Medicine;
        string check_in_date, check_in_time;

    public:
        store(bool flag){
           createTable();
        }
        store(){
            string getData(bool flag);
            void setData(int ID,string Name,string address,int Age,string doctor_name,string mobile,string check_in_date,string check_in_time,int bill,string Medicine);
        }

        void setData(int ID,string Name,string address,int Age,string doctor_name,string mobile,string check_in_date,string check_in_time,int bill,string Medicine){
            this->ID=ID;
            this->Name=Name;
            this->address=address;
            this->Age = Age;
            this->doctor_name=doctor_name;
            this->mobile=mobile;
            this->bill=bill;
            this->Medicine=Medicine;
            this->check_in_date=check_in_date;
            this->check_in_time=check_in_time;
         }
            string getData(bool flag){
            string data = "INSERT INTO AJAX_MED_order_DB VALUES("+to_string(ID)+",'"+Name+"','"+address+"',"+to_string(Age)+",'"+doctor_name+"','"+mobile+"','"+check_in_date+"','"+check_in_time+"', "+to_string(bill)+" , '"+Medicine+"');";
            
            return data;
         }

         void setData1(int ID,string supplierName,string mobile,string check_in_date,string check_in_time,int bill,string Medicine){
            this->ID=ID;
            this->supplierName=supplierName;
            this->mobile=mobile;
            this->bill=bill;
            this->Medicine=Medicine;
            this->check_in_date=check_in_date;
            this->check_in_time=check_in_time;
         }
        string getData1(bool flag){
            string data = "INSERT INTO AJAX_stock_order_DB VALUES("+to_string(ID)+",'"+supplierName+"','"+mobile+"','"+check_in_date+"','"+check_in_time+"', "+to_string(bill)+" ,'"+Medicine+"');";
            
            return data;
           
        }
            //  ID,supplierName,check_in_date,check_in_time,price,unit,productName
         void setData2(int ID,string supplierName,string check_in_date,string check_in_time,int price,int unit, string productName){
            this->ID=ID;
            this->supplierName=supplierName;
            this->bill=price;
            this->Medicine=productName;
            this->check_in_date=check_in_date;
            this->check_in_time=check_in_time;
            this->unit=unit;
         }
        string getData2(bool flag){
            string data = "INSERT INTO AJAX_store_DB VALUES("+to_string(ID)+",'"+supplierName+"','"+check_in_date+"','"+check_in_time+"', "+to_string(bill)+" ,"+to_string(unit)+" ,'"+Medicine+"');";
            
            return data;
           
        }


         
        int add_customer_order();
        int orderproducts();
        int display_patient_orderdetail();
        int display_stock_orderdetail();
        int medicine_stock();
        int display_store_detail();
    
    

};

int store :: createTable()
{
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
        string query = "CREATE TABLE IF NOT EXISTS AJAX_store_DB(ID INT PRIMARY KEY NOT NULL, " 
                                                        "SUPPLIER_NAME TEXT NOT NULL, "
                                                        "IN_DATE TEXT NOT NULL, "
                                                        "IN_TIME TEXT NOT NULL, "
                                                        "BILL INT NOT NULL, "
                                                        "UNIT INT NOT NULL, "
                                                        "MEDICINE TEXT NOT NULL );";

        myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
        if(myCursor != SQLITE_OK){
            cerr << "ERROR CREATING MEDICAL STORE INFORMATION TABLE\n";
            cout << error << "\n";
            sqlite3_free(error);
        }
        

        query = "CREATE TABLE IF NOT EXISTS AJAX_MED_order_DB(ID INT PRIMARY KEY NOT NULL, " 
                                                        "NAME TEXT NOT NULL, "
                                                        "ADDRESS TEXT, "
                                                        "Age INT NOT NULL, "
                                                        "DOCTOR TEXT NOT NULL, "
                                                        "MOBILE TEXT NOT NULL, "
                                                        "IN_DATE TEXT NOT NULL, "
                                                        "IN_TIME TEXT NOT NULL, "
                                                        "BILL INT NOT NULL, "
                                                        "MEDICINE TEXT NOT NULL );";

        myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
        if(myCursor != SQLITE_OK){
            cerr << "ERROR CREATING MEDICAL STORE INFORMATION TABLE\n";
            cout << error << "\n";
            sqlite3_free(error);
        }
        query = "CREATE TABLE IF NOT EXISTS AJAX_stock_order_DB(ID INT PRIMARY KEY NOT NULL, " 
                                                        "SUPPLIER NAME TEXT NOT NULL, "
                                                        "MOBILE TEXT NOT NULL, "
                                                        "IN_DATE TEXT NOT NULL, "
                                                        "IN_TIME TEXT NOT NULL, "
                                                        "BILL INT NOT NULL, "
                                                        "MEDICINE TEXT NOT NULL );";

        myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
        if(myCursor != SQLITE_OK){
            cerr << "ERROR CREATING MEDICAL STORE INFORMATION TABLE\n";
            cout << error << "\n";
            sqlite3_free(error);
        }
        return 0;
}

static int callbackstore(void *data, int argc, char **argv, char **colName)
{
    for (int i = 0; i < argc; i++)
    {
        ID = atoi(argv[i]);
    }
    return 0;
}

static int callbackstore1(void *data, int argc, char **argv, char **colName)
{
    for (int i = 0; i < argc; i++)
    {
        ID1 = atoi(argv[i]);
    }
    return 0;
}

int store :: add_customer_order(){
    sqlite3 *DB;
    int myCursor = 0;
    char *error;
    //int ID,ID1;

    myCursor = sqlite3_open("HMS_AJAX store.db", &DB); // AJAX stands for Asynchronous JavaScript And XML
    // error handling 
    if (myCursor)
    {
        cerr << "Error While Loading Database!\n";
        cout << sqlite3_errmsg(DB) << "\n";
        return -1;
    }

    string query, query1;
    {
        query = "SELECT ID FROM AJAX_MED_order_DB ORDER BY ID DESC LIMIT 1;";
        query1 = "SELECT ID FROM AJAX_MED_order_DB ORDER BY ID DESC LIMIT 1;";
        myCursor = sqlite3_exec(DB, query.c_str(), callbackstore, NULL, NULL);
        myCursor = sqlite3_exec(DB, query.c_str(), callbackstore1, NULL, NULL);
        

        ID = max(ID, ID1) + 1;
    }

    cout << "--------------Enter the "<< ID  <<" order detail --------------" << endl;
    cout << "Enter the Name of the patient :"<< " ";
    cin.clear();
    cin.ignore();
    fflush(stdin);
    getline(cin, Name);
    cout << "Enter the Age :" << " ";
    cin >> Age;
    cout<<"Enter the Doctor Name "<<" ";
    fflush(stdin);
    cout<<"(DR.)"<<" ";
    getline(cin,doctor_name);
     cout << "Enter the Address :"<< " ";
    fflush(stdin);
    getline(cin, address);
    cout<<"Enter the mobile number :"<<endl;
    fflush(stdin);
    getline(cin,mobile);
    int opt,num=0,price;
    string MED=" ";
    while(true)
    {
        cout<<"\t\t 1. Add Medicine "<<endl;
        cout<<"\t\t 2. Exit..... "<<endl;
        cout<<"\t\t Enter the option : "<<endl;
        cin>>opt;
        if(opt==1)
        {
            cout<<"Enter medicine Name : ";
            fflush(stdin);
            getline(cin,productName);
            cout<<"\nEnter Number of Unit : ";
            cin>>unit;
            cout<<"Enter the per unit price :";
            cin>>price;
            bill=price*unit;
            num = num + bill;
            MED = MED + " " + productName +",";
            

        }
        else if(opt==2)
        {
            break;
        }
        else{
            cout<<"WRONG CHOICE !!!"<<endl;
        }
    }
    bill = num;
    Medicine = MED;
    auto ztime = time(0);
    stringstream _time_date, _time_time;
    _time_date << put_time(localtime(&ztime), "%Y-%m-%d");
    check_in_date = _time_date.str();
    _time_time << put_time(localtime(&ztime), "%H:%M");
    check_in_time = _time_time.str();

    store s;
    s.setData(ID,Name,address,Age,doctor_name,mobile,check_in_date,check_in_time,bill,Medicine);
    query = s.getData(true);
    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
    insertion_check(myCursor, error); 

    sqlite3_close(DB);
    return 0;

}

static int callbackstore4(void *data, int argc, char **argv, char **colName)
{
    for (int i = 0; i < argc; i++)
    {
        ID = atoi(argv[i]);
    }
    return 0;
}

static int callbackstore5(void *data, int argc, char **argv, char **colName)
{
    for (int i = 0; i < argc; i++)
    {
        ID1 = atoi(argv[i]);
    }
    return 0;
}

 int store :: orderproducts(){
    sqlite3 *DB;
    int myCursor = 0;
    char *error;
    myCursor = sqlite3_open("HMS_AJAX store.db", &DB); // AJAX stands for Asynchronous JavaScript And XML
    // error handling 
    if (myCursor)
    {
        cerr << "Error While Loading Database!\n";
        cout << sqlite3_errmsg(DB) << "\n";
        return -1;
    }

    string query, query1;
    {
        query = "SELECT ID FROM AJAX_stock_order_DB ORDER BY ID DESC LIMIT 1;";
        query1 = "SELECT ID FROM AJAX_stock_order_DB ORDER BY ID DESC LIMIT 1;";
        myCursor = sqlite3_exec(DB, query.c_str(), callbackstore4, NULL, NULL);
        myCursor = sqlite3_exec(DB, query.c_str(), callbackstore5, NULL, NULL);
        
        ID = max(ID, ID1) + 1;
    }
    
    cout<<"\n\n|----------- ORDER Products & SUPPLIES ----------|"<<endl<<endl;
    cout<<"\nORDER NUMBER : "<< ID <<" ";
    cout<<"\nEnter Supplier's Name: ";
    fflush(stdin);
    getline(cin,supplierName);
    cout<<"\nEnter Supplier's MOBILE NO : ";
    fflush(stdin);
    getline(cin,mobile);
    int opt,num=0,price;
    string MED=" ";
    while(true){
        cout<<"\t\t 1. Add Medicine "<<endl;
        cout<<"\t\t 2. Exit..... "<<endl;
        int opt;
        cin>>opt;
        if(opt==1)
        {
            cout<<"Enter Product Name: ";
            fflush(stdin);
            getline(cin,productName);
            cout<<"\nEnter Number of Unit: ";
            cin>>unit;
            cout<<"Enter the per unit price :";
            cin>>price;
            bill=price*unit;
            num = num + bill;
            MED = MED + " " + productName + ",";
           // string data = "INSERT INTO AJAX_stock_order_DB () VALUES()
        }
        else if(opt==2)
        {
            break;
        }
        else{
            cout<<"WRONG CHOICE !!!"<<endl;
        }
        
    }
    bill = num;
    Medicine=MED;
    
    auto ztime = time(0);
    stringstream _time_date, _time_time;
    _time_date << put_time(localtime(&ztime), "%Y-%m-%d");
    check_in_date = _time_date.str();
    _time_time << put_time(localtime(&ztime), "%H:%M");
    check_in_time = _time_time.str();
    store s;
    s.setData1(ID,supplierName,mobile,check_in_date,check_in_time,bill,Medicine);
    query = s.getData1(true);
    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
    insertion_check(myCursor, error); 

    sqlite3_close(DB);
    return 0;
}

int store::display_patient_orderdetail()
{  
       
    //cout << "--- PATIENT MEDICINE ORDER DETAIL ---\n\n";
    queryExec3("SELECT * FROM AJAX_MED_order_DB ORDER BY NAME ASC;");
    return 0;
}

int store::display_stock_orderdetail()
{  
       
    //cout << "--- STOCK MEDICINE ORDER DETAIL ---\n\n";
    queryExec3("SELECT * FROM AJAX_stock_order_DB;");
    return 0;
        
}

static int callbackstore2(void *data, int argc, char **argv, char **colName)
{
    for (int i = 0; i < argc; i++)
    {
        ID = atoi(argv[i]);
    }
    return 0;
}

static int callbackstore3(void *data, int argc, char **argv, char **colName)
{
    for (int i = 0; i < argc; i++)
    {
        ID1 = atoi(argv[i]);
    }
    return 0;
}


int store::medicine_stock(){
    sqlite3 *DB;
    int myCursor = 0;
    char *error;
    //int ID,ID1;

    myCursor = sqlite3_open("HMS_AJAX store.db", &DB); // AJAX stands for Asynchronous JavaScript And XML
    // error handling 
    if (myCursor)
    {
        cerr << "Error While Loading Database!\n";
        cout << sqlite3_errmsg(DB) << "\n";
        return -1;
    }

    string query, query1;
    {
        query = "SELECT ID FROM AJAX_store_DB ORDER BY ID DESC LIMIT 1;";
        query1 = "SELECT ID FROM AJAX_store_DB ORDER BY ID DESC LIMIT 1;";
        myCursor = sqlite3_exec(DB, query.c_str(), callbackstore2, NULL, NULL);
        myCursor = sqlite3_exec(DB, query.c_str(), callbackstore3, NULL, NULL);
        

        //ID = max(ID, ID1) + 1;
    }

    cout << "--------------Enter the medicine detail in stock--------------" << endl;
    while(true){
        ID = max(ID, ID1) + 1;
        cout<<"\t\t 1. Add Medicine "<<endl;
        cout<<"\t\t 2. Exit..... "<<endl;
        int opt;
        cin>>opt;
        if(opt==1)
        {
            cout<<"\nEnter Supplier's Name: ";
            fflush(stdin);
            getline(cin,supplierName);
            cout<<"Enter Product Name: ";
            fflush(stdin);
            getline(cin,productName);
            cout<<"\nEnter Number of Unit: ";
            cin>>unit;
            cout<<"Enter the per unit price :";
            cin>>price;

            auto ztime = time(0);
            stringstream _time_date, _time_time;
            _time_date << put_time(localtime(&ztime), "%Y-%m-%d");
            check_in_date = _time_date.str();
            _time_time << put_time(localtime(&ztime), "%H:%M");
            check_in_time = _time_time.str();
            store s;
            s.setData2(ID,supplierName,check_in_date,check_in_time,price,unit,productName);
            query = s.getData2(true);
            myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
            insertion_check(myCursor, error); 

        }
        else if(opt==2)
        {
            break;
        }
        else{
            cout<<"WRONG CHOICE !!!"<<endl;
        }

    }
sqlite3_close(DB);
return 0;
}

int store::display_store_detail()
{  
       
    //cout << "--- MEDICINE STOCK DETAIL ---\n\n";
    queryExec3("SELECT * FROM AJAX_store_DB;");
    return 0;
}