
/*
##=============================================================
#							      =
#	Author: ochieno eliud				      =
#	University of Nairobi				      =
#	Dept: Elec. $ Info. Eng.			      =
#							      =
#==============================================================
            -------------------------BANKING SYSTEM SIMULATOR C++ PROGRAM-----------------------
*/

#include <iostream>
#include <ctime>
#include <iomanip>
#include<string>
#include<cstdlib>
#include <fstream>
#include <string.h>
#include "windows.h"
#include "Accounts.h"

using namespace std;

    void shrt_oprtns_optmzr_tmr();
    void long_oprtns_optmzr_tmr();
    void main_oprtn();
    void acc_auto_compltn();
    void client1_acc_crtn(int);
    void Make_Deposit();
    void withdrawal_prmpt();
    void withdrawal_cnfrm(int);
    void Make_Withdrawal();
    void Bank_sttmnt(int);
    void Check_statement();
    void banking_info();
    void operation_fn(int);
    void initializer_fn();
    void deposit_prmpt();
    void deposit_cnfrm(int);
    void acc_crtn_edit_name();
    void acc_crtn_cnfrm(int);
    void acc_crtn_edit_country();
    void acc_crtn_edit_county();
    void acc_crtn_edit_brth_dt();
    void acc_crtn_edit_PIN_no();
    void acc_crtn_edit_ID_no();
    void updtt_acc_fl();
    void updtt_acc_fl();
            //fctns prototyping

    string customer1_id_name, customer2_id_name, customer3_id_name, customer4_id_name, customer5_id_name, customer6_id_name, customer7_id_name, customer8_id_name, customer9_id_name, customer10_id_name;
    string customer1_id_no, customer2_id_no, customer3_id_no, customer4_id_no, customer5_id_no, customer6_id_no, customer7_id_no, customer8_id_no, customer9_id_no, customer10_id_no;
    string customer1_pin, customer2_pin, customer3_pin, customer4_pin, customer5_pin, customer6_pin, customer7_pin, customer8_pin, customer9_pin, customer10_pin;
    string customer1_brth_dt, customer2_brth_dt, customer3_brth_dt, customer4_brth_dt, customer5_brth_dt, customer6_brth_dt, customer7_brth_dt, customer8_brth_dt, customer9_brth_dt, customer10_brth_dt;
    int customer1_acc_no, customer2_acc_no, customer3_acc_no, customer4_acc_no, customer5_acc_no, customer6_acc_no, customer7_acc_no, customer8_acc_no, customer9_acc_no, customer10_acc_no;
    string customer1_county_id, customer2_county_id, customer3_county_id, customer4_county_id, customer5_county_id, customer6_county_id, customer7_county_id, customer8_county_id, customer9_county_id, customer10_county_id;
    string customer1_country_id, customer2_country_id, customer3_country_id, customer4_country_id, customer5_country_id, customer6_country_id, customer7_country_id, customer8_country_id, customer9_country_id, customer10_country_id;
    double customer1_blnc_info, customer2_blnc_info, customer3_blnc_info, customer4_blnc_info, customer5_blnc_info, customer6_blnc_info, customer7_blnc_info, customer8_blnc_info, customer9_blnc_info, customer10_blnc_info;
    double amnt_dpst, amnt_wthdrw;
    int client_acc_no, range_span, min_rang_val, max_range_val, oprtn_actn, choice, sttmnt_type, optmr_flag, max_tm, min_tm, shrt_oprtns_tmr, accs_no, acc_cntr, long_oprtns_tmr, confrm_flag;
    string f_name, m_name, l_name, id_no, bz_pin, brth_dt, county_id, country_id, oprtn_prompt;
    time_t crrnt_dt= time(0);
    tm *l_tm =  localtime(&crrnt_dt);
    //global variables

    void optmzr_t()
    {
        Sleep(250);
    }
    void optmzr_hlf_sec_t()
    {
        Sleep(500);
    }
    void optmzr_1_sec_t()
    {
        Sleep(1000);
    }
    void optmzr_1_hlf_sec_t()
    {
        Sleep(1500);
    }
    void optmzr_2_sec_t()
    {
        Sleep(2000);
    }
    void optmzr_2_n_hlf_sec_t()
    {
        Sleep(2500);
    }
    void optmzr_3_sec_t()
    {
        Sleep(3000);
    }
            //processes optimizer time fns
    void shrt_oprtns_optmzr_tmr()
    {
	    min_tm = 1;
	    max_tm = 3;
	            //random no. ranges
	    range_span = ((max_tm - min_tm) + 1);
	            //random no. scope
	    shrt_oprtns_tmr = min_tm+int(range_span*rand()/(RAND_MAX + 1.0));
                //account_no generator fn
    }   //short operations optmzr fn
    void long_oprtns_optmzr_tmr()
    {
	    min_tm = 1;
	    max_tm = 28;
	            //random no. ranges
	    range_span = ((max_tm - min_tm) + 1);
	            //random no. scope
	    long_oprtns_tmr = min_tm+int(range_span*rand()/(RAND_MAX + 1.0));
                //account_no generator fn
    }   //long operations optmzr fn
    void main_oprtn()
    {
        cout << "\n\n\t=====================================================================================\t\n\t\t\t\t          BANKING SYSTEM\n\t=====================================================================================" << endl;
        cout << "\n\n\tOPERATIONS:\t\t\t\t\t\t\t\t   "<<l_tm->tm_mday<<"/"<<l_tm->tm_mon<<"/"<<l_tm->tm_year<<"\n\t-----------\t\t\t\t\t\t                   ----------\n\t------------------------------------------------------------------------------------- \n";
        cout << "\n" <<setw(16)<<"1. "<<setw(6)<<"Create Account."<<endl;
        cout << "\n" <<setw(16)<<"2. "<<setw(6)<<"Make Deposits."<<endl;
        cout << "\n" <<setw(16)<<"3. "<<setw(6)<<"Make Withdrawals."<<endl;
        cout << "\n" <<setw(16)<<"4. "<<setw(6)<<"Check Statements."<<endl;
        cout << "\n" <<setw(16)<<"5. "<<setw(6)<<"Learn More."<<endl;
        cout << "\n\t=====================================================================================\n";
        if(optmr_flag == 1)
            cout << "\n\t   Loading details ";
            //operation controller flag
    }       //program initials fn
    void loading_fn()
    {
        for(int z=0; z<3; z++)
        {
            int x;
            shrt_oprtns_optmzr_tmr();
                //operation tmr
            optmzr_1_sec_t();
            if(z <= 1)
            {
                for(x=0; x<3; x++)
                {
                    cout <<". ";
                    Sleep(150);
                }
            }
            else if(z > 1)
            {
                for(x=0; x<shrt_oprtns_tmr-1; x++)
                {
                    cout <<". ";
                    Sleep(200);
                }
            }
            x = 0;
            system("CLS");
            if(z == 2)
            {
                optmr_flag = 0;
                        //sets operation flag down
            }
            main_oprtn();
        }
    }       //initialization operation auth fn
    void saving_fn()
    {
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        cout << "\n\t      Saving operation \n\n\t\t   ";
        optmzr_1_sec_t();
        for(int x=0; x<3; x++)
        {
            long_oprtns_optmzr_tmr();
                //operation tmr
            cout <<". ";
            optmzr_2_sec_t();
            if(x==2)
            {
                cout << "\n\n\t      Success! ";
                optmzr_2_sec_t();
                cout << "\n\n\t   ";
                for(int z=0; z<long_oprtns_tmr; z++)
                {
                    cout <<"- ";
                    Sleep(120);
                }
                cout << "\n\n\t";
                optmzr_1_sec_t;
                system("CLS");
                main_oprtn();
            }
        }
    }       //information saving auth fn
    void submit_fn()
    {
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        cout << "\n\t      Submiting Request \n\n\t\t   ";
        optmzr_1_sec_t();
        for(int x=0; x<3; x++)
        {
            long_oprtns_optmzr_tmr();
                //operation tmr
            cout <<". ";
            optmzr_1_sec_t();
            if(x==2)
            {
                cout << "\n\n\t      Request recieved ";
                optmzr_2_sec_t();
                cout << "\n\n\t   ";
                for(int z=0; z<long_oprtns_tmr; z++)
                {
                    cout <<"- ";
                    Sleep(120);
                }
                cout << "\n\n\t";
                optmzr_1_sec_t;
                system("CLS");
                main_oprtn();
            }
        }
    }       //information submission auth fn
    void loadin_optmzr()
    {
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        cout << "\n\t   Completing operation \n\n\t\t";
        optmzr_1_sec_t();
        for(int x=0; x<5; x++)
        {
            long_oprtns_optmzr_tmr();
                //operation tmr
            cout <<". ";
            optmzr_1_sec_t();
            if(x==4)
            {
                cout << "\n\n\t   Success! ";
                optmzr_1_sec_t();
                cout << "\n\n\t   ";
                for(int z=0; z<long_oprtns_tmr; z++)
                {
                    cout <<"- ";
                    Sleep(120);
                }
                cout << "\n\n\t";
                optmzr_1_sec_t;
                system("CLS");
                main_oprtn();
                //links to main section
            }
        }
    }           //operation scrollbar
    void acc_auto_compltn()
	{
	    min_rang_val = 100001;
	    max_range_val = 990099;
	            //random no. ranges
        customer1_blnc_info = 0;
                //generates client acc_no
	    range_span = ((max_range_val - min_rang_val) + 1);
	            //random no. scope
	    client_acc_no = min_rang_val+int(range_span*rand()/(RAND_MAX + 1.0));
                //account_no generator fn
        customer1_acc_no = client_acc_no;
                //presets client acc_info
	}
        //account auto-completition fn
    void acc_crtn_edit_name()
    {
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
        cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
        cout << "\n" <<setw(21)<<"    1.1.1. "<<setw(6)<<"First name: ";
        cin >> f_name;
        cout << "\n" <<setw(21)<<"    1.1.2. "<<setw(6)<<"Middle name: ";
        cin >> m_name;
        cout << "\n" <<setw(21)<<"    1.1.3. "<<setw(6)<<"Surname name: ";
        cin >> l_name;
        customer1_id_name = ""+f_name+" "+m_name+" "+l_name;
        optmzr_t();
            //client biz info initialisation
        acc_auto_compltn();
            //xternal fn to regenerate acc. credentials
        optmzr_1_sec_t();
        cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       NEW ACCOUNT INFORMATION";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer1_id_name<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer1_id_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer1_pin<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer1_brth_dt<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_county_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_country_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
                //account summary info
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
        cin >> choice;
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation optio
        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        acc_crtn_cnfrm(choice);
                //edit new client acc name
    }
    void acc_crtn_edit_ID_no()
    {
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        cout << "\n\n\t    1.2. CLIENT ID NO. INFORMATION: \n";
        cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
        cout << "\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
        cin >> id_no;
        customer1_id_no = id_no;
        optmzr_t();
            //client biz info initialisation
        acc_auto_compltn();
            //xternal fn to regenerate acc. credentials
        optmzr_1_sec_t();
        cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       NEW ACCOUNT INFORMATION";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer1_id_name<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer1_id_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer1_pin<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer1_brth_dt<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_county_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_country_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                //account summary info
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
        cin >> choice;
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation optio
        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        acc_crtn_cnfrm(choice);
    }
                //edit new client ID_NO
    void acc_crtn_edit_PIN_no()
    {
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        cout << "\n\n\t    1.2. CLIENT PIN INFORMATION: \n";
        cout << "\n\t    Fill ALL the fields as required below to complete editing process.";

        cout << "\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
        cin >> bz_pin;
        customer1_pin = bz_pin;
        optmzr_t();
            //client biz info initialisation
        acc_auto_compltn();
            //xternal fn to regenerate acc. credentials
        cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       NEW ACCOUNT INFORMATION";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer1_id_name<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer1_id_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer1_pin<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer1_brth_dt<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_county_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_country_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
                //account summary info
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
        cin >> choice;
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation optio

        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        acc_crtn_cnfrm(choice);
    }
                //edit new client PIN
    void acc_crtn_edit_brth_dt()
    {
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
        cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
        cout << "\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
        cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
        cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
        cin >> brth_dt;
        customer1_brth_dt = brth_dt;
        optmzr_t();
            //client biz info initialisation
        acc_auto_compltn();
            //xternal fn to regenerate acc. credentials
        optmzr_1_sec_t();
        cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       NEW ACCOUNT INFORMATION";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer1_id_name<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer1_id_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer1_pin<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer1_brth_dt<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_county_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_country_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
                //account summary info
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
        cin >> choice;
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation optio
        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        acc_crtn_cnfrm(choice);
    }
                //edit new client date of birth
    void acc_crtn_edit_county()
    {
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        cout << "\n\n\t    1.3. CLIENT COUNTY INFORMATION: \n";
        cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
        cout << "\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
        cin >> county_id;
        customer1_county_id = county_id;
        optmzr_t();
            //client biz info initialisation
        acc_auto_compltn();
            //xternal fn to regenerate acc. credentials
        optmzr_1_sec_t();
        cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       NEW ACCOUNT INFORMATION";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer1_id_name<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer1_id_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer1_pin<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer1_brth_dt<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_county_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_country_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
                //account summary info
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
        cin >> choice;
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation optio
        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        acc_crtn_cnfrm(choice);
    }
                //edit new client COUNTY
    void acc_crtn_edit_country()
    {
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        cout << "\n\n\t    1.3. CLIENT COUNTRY INFORMATION: \n";
        cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
        cout << "\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
        cin >> country_id;
        customer1_country_id = country_id;
        optmzr_t();
            //client biz info initialisation
        acc_auto_compltn();
            //xternal fn to regenerate acc. credentials
        optmzr_1_sec_t();
        cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       NEW ACCOUNT INFORMATION";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer1_id_name<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer1_id_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer1_pin<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer1_brth_dt<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_county_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_country_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
                //account summary info
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
        cin >> choice;
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation optio
        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        acc_crtn_cnfrm(choice);
    }
                //edit new client COUNTRY
    void auth_acc_fl()
    {
        ifstream Read_acc_fl;
                //read file object
        Read_acc_fl.open("No_accounts.txt");
        Read_acc_fl >> acc_cntr;
        Read_acc_fl.close();
                //reads no of acc available
        if(Read_acc_fl.fail())
        {
            ifstream Read_acc_fl;
                    //read file object
            Read_acc_fl.open("No_accounts.txt");
            Read_acc_fl >> acc_cntr;
            Read_acc_fl.close();
                    //reads no of acc available
            //cerr << "\n  " <<setw(16)<<"   "<<setw(6)<<"Error in opening the file!";
            //exit(1);
        }   //exception handler
    }       //validates no. of accs
    void create_acc_fl()
    {
        auth_acc_fl();
                    //no of accs validator fn

    }//accounts file creator fn
    void updtt_acc_fl()
    {
        auth_acc_fl();
                    //no of accs validator fn
        int x;
        for(x=0; x<10; x++)
        {
            if(acc_cntr == x)
            {
                string line;
                string find;
                ifstream acc_fl; //for reading records
                acc_fl.open("No_accounts.txt");

                ofstream temp;  //temporary file object
                temp.open("temp.tmp");
                                //opens temporary file
                while (getline(acc_fl, line))
                {
                  if (line != find)
                    temp << line << endl;
                }
                acc_fl.close();
                temp.close();
                remove("No_accounts.txt");
                rename("temp.txt", "No_accounts.txt");
                                //deletes pevious file and renames it

                ofstream nw_acc_fl;
                nw_acc_fl.open("No_accounts.txt", ios::app | ios::out);
                nw_acc_fl << x+1; //updates accounts file for new accounts creation
                nw_acc_fl.close();
                ifstream rd_acc_fl;
                rd_acc_fl.open("No_accounts.txt");
                rd_acc_fl >> acc_cntr;
                rd_acc_fl.close();
                        //reads no of acc available
                x = 10;
            }
        }
    }//accounts file updater fn
    void acc_crtn_cnfrm(int acc_crtn_optn)
    {
        if(acc_crtn_optn == 1)
        {
            loadin_optmzr();
            create_acc_fl();
                    //call accounts creator and counter file
            updtt_acc_fl();
                    //calls accounts file updater fn
                    //saving session fn
        }
        else if(acc_crtn_optn == 2)
        {
            cout << "\n\t      Reloading account section for client name editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            acc_crtn_edit_name();
                    //recalls fn for acc. name editing
        }
        else if(acc_crtn_optn == 3)
        {
            cout << "\n\t      Reloading account section for client ID No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            acc_crtn_edit_ID_no();
                    //recalls fn for making changes
        }
        else if(acc_crtn_optn == 4)
        {
            cout << "\n\t      Reloading account section for client PIN No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            acc_crtn_edit_PIN_no();
                    //recalls fn for making changes
        }
        else if(acc_crtn_optn == 5)
        {
            cout << "\n\t      Reloading account section for client date of birth editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            acc_crtn_edit_brth_dt();
                    //recalls fn for making changes
        }
        else if(acc_crtn_optn == 6)
        {
            cout << "\n\t      Reloading account section for client county id editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            acc_crtn_edit_county();
                    //recalls fn for making changes
        }
        else if(acc_crtn_optn == 7)
        {
            cout << "\n\t      Reloading account section for client nationality editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            acc_crtn_edit_country();
                    //recalls fn for making chan
        }
        else
        {
            cout<<"\n\t         -----------------------------\n\n\t             ERROR!\n\t                   -Undefined option.\n\t                   -Please enter appropriate choice\n\t                    as guided above and try again.\n\n\t                    System waiting...\n\n\t\t              : ";
            cin>>choice;
                //operation actn dfn
            cout<<"\n\t             -----------------------------\n\n";
            deposit_cnfrm(choice);
                //recalls the fn
        }   //exception error handler
    }   //deposit process confirmation fn
    void client1_acc_crtn(int clnt1)
    {
        ofstream client1_acc_file;
                    //file object
        client1_acc_file.open("Client1_Acc_File.txt");

        cout << "\n\n\t   1.B.1: NEW ACCOUNT CREATION\n\t   --------------------------------------------------------\n";
        cout << "\n\t   Fill ALL the fields as required below to complete the process.";
        cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.1.1. "<<setw(6)<<"First name: ";
        cin >> f_name;
        cout << "\n" <<setw(21)<<"1.1.2. "<<setw(6)<<"Middle name: ";
        cin >> m_name;
        cout << "\n" <<setw(21)<<"1.1.3. "<<setw(6)<<"Surname name: ";
        cin >> l_name;
        customer1_id_name = ""+f_name+" "+m_name+" "+l_name;
        optmzr_t();
            //client name initialisation
        cout << "\n\n\t    1.2. CLIENT BUSINESS CREDENTIALS: \n";
        cout << "\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
        cin >> id_no;
        cout << "\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
        cin >> bz_pin;
        customer1_id_no = id_no;
        customer1_pin = bz_pin;
        optmzr_t();
            //client biz info initialisationcoutry_id
        cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
        cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
        cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
        cin >> brth_dt;
        cout << "\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
        cin >> county_id;
        cout << "\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
        cin >> country_id;
        customer1_brth_dt = brth_dt;
        customer1_county_id = county_id;
        customer1_country_id = country_id;
        optmzr_t();
            //client biz info initialisation
        acc_auto_compltn();
            //xternal fn to regenerate acc. credentials
        optmzr_1_sec_t();
        cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 1 ACCOUNT INFORMATION";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer1_id_name<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer1_id_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer1_pin<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer1_brth_dt<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_county_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_country_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
                //account summary info
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
        cin >> choice;
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation option
        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n";

        if(choice == 1)
        {
            loadin_optmzr();
            create_acc_fl();
                    //call accounts creator and counter file
            updtt_acc_fl();
                    //calls accounts file updater fn
                    //----------------file writing-----------------------------
            client1_acc_file << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 1 ACCOUNT INFORMATION";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer1_id_name<<"";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer1_id_no<<"";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer1_pin<<"";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer1_brth_dt<<"";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_county_id<<"";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_country_id<<"";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client1_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client1_acc_file.close();
                    //close file after writing mode
                    //----------------file writing-----------------------------
                    //saving session fn
        }
        else if(choice == 2)
        {
            cout << "\n\t      Reloading account section for client name editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"    1.1.1. "<<setw(6)<<"First name: ";
            cin >> f_name;
            cout << "\n" <<setw(21)<<"    1.1.2. "<<setw(6)<<"Middle name: ";
            cin >> m_name;
            cout << "\n" <<setw(21)<<"    1.1.3. "<<setw(6)<<"Surname name: ";
            cin >> l_name;
            customer1_id_name = ""+f_name+" "+m_name+" "+l_name;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 1 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer1_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer1_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer1_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer1_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client1_acc_crtn(choice);
                        //recalls fn for acc. name editing
        }
                //edit new client acc name
        else if(choice == 3)
        {
            cout << "\n\t      Reloading account section for client ID No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT ID NO. INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
            cin >> id_no;
            customer1_id_no = id_no;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 1 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer1_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer1_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer1_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer1_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                    //account summary info
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client1_acc_crtn(choice);
                    //acc_crtn_cnfrm(choice);
                    //client ID edit
        }
        else if(choice == 4)
        {
            cout << "\n\t      Reloading account section for client PIN No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT PIN INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
            cin >> bz_pin;
            customer1_pin = bz_pin;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 1 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer1_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer1_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer1_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer1_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client1_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 5)
        {
            cout << "\n\t      Reloading account section for client date of birth editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
            cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
            cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
            cin >> brth_dt;
            customer1_brth_dt = brth_dt;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 1 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer1_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer1_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer1_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer1_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client1_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 6)
        {
            cout << "\n\t      Reloading account section for client county id editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
            cin >> county_id;
            customer1_county_id = county_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 1 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer1_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer1_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer1_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer1_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client1_acc_crtn(choice);
                        //recalls fn for making changes
        }
        else if(choice == 7)
        {
            cout << "\n\t      Reloading account section for client nationality editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTRY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
            cin >> country_id;
            customer1_country_id = country_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 1 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer1_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer1_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer1_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer1_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer1_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client1_acc_crtn(choice);
                    //recalls fn for making chan
        }
        else
        {
            cout<<"\n\t         -----------------------------\n\n\t             ERROR!\n\t                   -Undefined option.\n\t                   -Please enter appropriate choice\n\t                    as guided above and try again.\n\n\t                    System waiting...\n\n\t\t              : ";
            cin>>choice;
                //operation actn dfn
            cout<<"\n\t             -----------------------------\n\n";
            client1_acc_crtn(choice);
                //recalls the fn
        }   //exception error handler
            //client details input
    }
                //account creator fn
    void client2_acc_crtn(int clnt2)
    {
        ofstream client2_acc_file;
                    //file object
        client2_acc_file.open("Client2_Acc_File.txt");

        cout << "\n\n\t   1.B.1: NEW ACCOUNT CREATION\n\t   --------------------------------------------------------\n";
        cout << "\n\t   Fill ALL the fields as required below to complete the process.";
        cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.1.1. "<<setw(6)<<"First name: ";
        cin >> f_name;
        cout << "\n" <<setw(21)<<"1.1.2. "<<setw(6)<<"Middle name: ";
        cin >> m_name;
        cout << "\n" <<setw(21)<<"1.1.3. "<<setw(6)<<"Surname name: ";
        cin >> l_name;
        customer2_id_name = ""+f_name+" "+m_name+" "+l_name;
        optmzr_t();
            //client name initialisation
        cout << "\n\n\t    1.2. CLIENT BUSINESS CREDENTIALS: \n";
        cout << "\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
        cin >> id_no;
        cout << "\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
        cin >> bz_pin;
        customer2_id_no = id_no;
        customer2_pin = bz_pin;
        optmzr_t();
            //client biz info initialisationcoutry_id
        cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
        cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
        cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
        cin >> brth_dt;
        cout << "\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
        cin >> county_id;
        cout << "\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
        cin >> country_id;
        customer2_brth_dt = brth_dt;
        customer2_county_id = county_id;
        customer2_country_id = country_id;
        optmzr_t();
            //client biz info initialisation
        acc_auto_compltn();
            //xternal fn to regenerate acc. credentials
        optmzr_1_sec_t();
        cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 2 ACCOUNT INFORMATION";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer2_id_name<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer2_id_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer2_pin<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer2_brth_dt<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer2_county_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer2_country_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
                //account summary info
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
        cin >> choice;
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation option
        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n";

        if(choice == 1)
        {
            loadin_optmzr();
            create_acc_fl();
                    //call accounts creator and counter file
            updtt_acc_fl();
                    //calls accounts file updater fn
                    //----------------file writing-----------------------------
            client2_acc_file << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 2 ACCOUNT INFORMATION";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer2_id_name<<"";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer2_id_no<<"";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer2_pin<<"";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer2_brth_dt<<"";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer2_county_id<<"";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer2_country_id<<"";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client2_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client2_acc_file.close();
                    //close file after writing mode
                    //----------------file writing-----------------------------
                    //saving session fn
        }
        else if(choice == 2)
        {
            cout << "\n\t      Reloading account section for client name editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"    1.1.1. "<<setw(6)<<"First name: ";
            cin >> f_name;
            cout << "\n" <<setw(21)<<"    1.1.2. "<<setw(6)<<"Middle name: ";
            cin >> m_name;
            cout << "\n" <<setw(21)<<"    1.1.3. "<<setw(6)<<"Surname name: ";
            cin >> l_name;
            customer2_id_name = ""+f_name+" "+m_name+" "+l_name;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 2 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer2_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer2_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer2_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer2_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer2_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer2_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client2_acc_crtn(choice);
                        //recalls fn for acc. name editing
        }
                //edit new client acc name
        else if(choice == 3)
        {
            cout << "\n\t      Reloading account section for client ID No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT ID NO. INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
            cin >> id_no;
            customer2_id_no = id_no;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 2 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer2_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer2_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer2_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer2_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer2_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer2_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                    //account summary info
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client2_acc_crtn(choice);
                    //acc_crtn_cnfrm(choice);
                    //client ID edit
        }
        else if(choice == 4)
        {
            cout << "\n\t      Reloading account section for client PIN No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT PIN INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
            cin >> bz_pin;
            customer2_pin = bz_pin;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 2 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer2_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer2_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer2_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer2_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer2_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer2_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client2_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 5)
        {
            cout << "\n\t      Reloading account section for client date of birth editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
            cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
            cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
            cin >> brth_dt;
            customer2_brth_dt = brth_dt;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 2 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer2_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer2_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer2_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer2_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer2_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer2_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client2_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 6)
        {
            cout << "\n\t      Reloading account section for client county id editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
            cin >> county_id;
            customer2_county_id = county_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 2 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer2_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer2_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer2_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer2_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer2_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer2_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client2_acc_crtn(choice);
                        //recalls fn for making changes
        }
        else if(choice == 7)
        {
            cout << "\n\t      Reloading account section for client nationality editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTRY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
            cin >> country_id;
            customer2_country_id = country_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 2 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer2_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer2_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer2_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer2_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer2_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer2_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client2_acc_crtn(choice);
                    //recalls fn for making chan
        }
        else
        {
            cout<<"\n\t         -----------------------------\n\n\t             ERROR!\n\t                   -Undefined option.\n\t                   -Please enter appropriate choice\n\t                    as guided above and try again.\n\n\t                    System waiting...\n\n\t\t              : ";
            cin>>choice;
                //operation actn dfn
            cout<<"\n\t             -----------------------------\n\n";
            client2_acc_crtn(choice);
                //recalls the fn
        }   //exception error handler
            //client details input
    }
                //account creator fn
    void client3_acc_crtn(int clnt3)
    {
        ofstream client3_acc_file;
                    //file object
        client3_acc_file.open("Client3_Acc_File.txt");

        cout << "\n\n\t   1.B.1: NEW ACCOUNT CREATION\n\t   --------------------------------------------------------\n";
        cout << "\n\t   Fill ALL the fields as required below to complete the process.";
        cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.1.1. "<<setw(6)<<"First name: ";
        cin >> f_name;
        cout << "\n" <<setw(21)<<"1.1.2. "<<setw(6)<<"Middle name: ";
        cin >> m_name;
        cout << "\n" <<setw(21)<<"1.1.3. "<<setw(6)<<"Surname name: ";
        cin >> l_name;
        customer3_id_name = ""+f_name+" "+m_name+" "+l_name;
        optmzr_t();
            //client name initialisation
        cout << "\n\n\t    1.2. CLIENT BUSINESS CREDENTIALS: \n";
        cout << "\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
        cin >> id_no;
        cout << "\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
        cin >> bz_pin;
        customer3_id_no = id_no;
        customer3_pin = bz_pin;
        optmzr_t();
            //client biz info initialisationcoutry_id
        cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
        cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
        cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
        cin >> brth_dt;
        cout << "\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
        cin >> county_id;
        cout << "\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
        cin >> country_id;
        customer3_brth_dt = brth_dt;
        customer3_county_id = county_id;
        customer3_country_id = country_id;
        optmzr_t();
            //client biz info initialisation
        acc_auto_compltn();
            //xternal fn to regenerate acc. credentials
        optmzr_1_sec_t();
        cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 3 ACCOUNT INFORMATION";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer3_id_name<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer3_id_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer3_pin<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer3_brth_dt<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer3_county_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer3_country_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
                //account summary info
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
        cin >> choice;
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation option
        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n";

        if(choice == 1)
        {
            loadin_optmzr();
            create_acc_fl();
                    //call accounts creator and counter file
            updtt_acc_fl();
                    //calls accounts file updater fn
                    //saving session fn
                    //----------------file writing-----------------------------
            client3_acc_file << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 3 ACCOUNT INFORMATION";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer3_id_name<<"";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer3_id_no<<"";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer3_pin<<"";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer3_brth_dt<<"";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer3_county_id<<"";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer3_country_id<<"";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client3_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client3_acc_file.close();
                    //close file after writing mode
                    //----------------file writing-----------------------------
        }
        else if(choice == 2)
        {
            cout << "\n\t      Reloading account section for client name editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"    1.1.1. "<<setw(6)<<"First name: ";
            cin >> f_name;
            cout << "\n" <<setw(21)<<"    1.1.2. "<<setw(6)<<"Middle name: ";
            cin >> m_name;
            cout << "\n" <<setw(21)<<"    1.1.3. "<<setw(6)<<"Surname name: ";
            cin >> l_name;
            customer3_id_name = ""+f_name+" "+m_name+" "+l_name;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 3 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer3_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer3_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer3_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer3_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer3_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer3_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client3_acc_crtn(choice);
                        //recalls fn for acc. name editing
        }
                //edit new client acc name
        else if(choice == 3)
        {
            cout << "\n\t      Reloading account section for client ID No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT ID NO. INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
            cin >> id_no;
            customer3_id_no = id_no;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 3 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer3_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer3_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer3_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer3_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer3_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer3_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                    //account summary info
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client3_acc_crtn(choice);
                    //acc_crtn_cnfrm(choice);
                    //client ID edit
        }
        else if(choice == 4)
        {
            cout << "\n\t      Reloading account section for client PIN No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT PIN INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
            cin >> bz_pin;
            customer3_pin = bz_pin;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 3 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer3_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer3_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer3_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer3_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer3_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer3_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client3_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 5)
        {
            cout << "\n\t      Reloading account section for client date of birth editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
            cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
            cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
            cin >> brth_dt;
            customer3_brth_dt = brth_dt;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 3 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer3_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer3_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer3_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer3_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer3_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer3_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client3_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 6)
        {
            cout << "\n\t      Reloading account section for client county id editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
            cin >> county_id;
            customer3_county_id = county_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 3 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer3_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer3_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer3_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer3_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer3_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer3_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client3_acc_crtn(choice);
                        //recalls fn for making changes
        }
        else if(choice == 7)
        {
            cout << "\n\t      Reloading account section for client nationality editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTRY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
            cin >> country_id;
            customer3_country_id = country_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 3 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer3_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer3_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer3_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer3_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer3_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer3_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client3_acc_crtn(choice);
                    //recalls fn for making chan
        }
        else
        {
            cout<<"\n\t         -----------------------------\n\n\t             ERROR!\n\t                   -Undefined option.\n\t                   -Please enter appropriate choice\n\t                    as guided above and try again.\n\n\t                    System waiting...\n\n\t\t              : ";
            cin>>choice;
                //operation actn dfn
            cout<<"\n\t             -----------------------------\n\n";
            client3_acc_crtn(choice);
                //recalls the fn
        }   //exception error handler
            //client details input
    }
    void client4_acc_crtn(int clnt4)
    {
        ofstream client4_acc_file;
                    //file object
        client4_acc_file.open("Client4_Acc_File.txt");

        cout << "\n\n\t   1.B.1: NEW ACCOUNT CREATION\n\t   --------------------------------------------------------\n";
        cout << "\n\t   Fill ALL the fields as required below to complete the process.";
        cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.1.1. "<<setw(6)<<"First name: ";
        cin >> f_name;
        cout << "\n" <<setw(21)<<"1.1.2. "<<setw(6)<<"Middle name: ";
        cin >> m_name;
        cout << "\n" <<setw(21)<<"1.1.3. "<<setw(6)<<"Surname name: ";
        cin >> l_name;
        customer4_id_name = ""+f_name+" "+m_name+" "+l_name;
        optmzr_t();
            //client name initialisation
        cout << "\n\n\t    1.2. CLIENT BUSINESS CREDENTIALS: \n";
        cout << "\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
        cin >> id_no;
        cout << "\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
        cin >> bz_pin;
        customer4_id_no = id_no;
        customer4_pin = bz_pin;
        optmzr_t();
            //client biz info initialisationcoutry_id
        cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
        cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
        cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
        cin >> brth_dt;
        cout << "\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
        cin >> county_id;
        cout << "\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
        cin >> country_id;
        customer4_brth_dt = brth_dt;
        customer4_county_id = county_id;
        customer4_country_id = country_id;
        optmzr_t();
            //client biz info initialisation
        acc_auto_compltn();
            //xternal fn to regenerate acc. credentials
        optmzr_1_sec_t();
        cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 4 ACCOUNT INFORMATION";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer4_id_name<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer4_id_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer4_pin<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer4_brth_dt<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer4_county_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer4_country_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
                //account summary info
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
        cin >> choice;
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation option
        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n";

        if(choice == 1)
        {
            loadin_optmzr();
            create_acc_fl();
                    //call accounts creator and counter file
            updtt_acc_fl();
                    //calls accounts file updater fn
                    //saving session fn
                    //----------------file writing-----------------------------
            client4_acc_file << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 4 ACCOUNT INFORMATION";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer4_id_name<<"";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer4_id_no<<"";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer4_pin<<"";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer4_brth_dt<<"";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer4_county_id<<"";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer4_country_id<<"";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client4_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client4_acc_file.close();
                    //close file after writing mode
                    //----------------file writing-----------------------------
        }
        else if(choice == 2)
        {
            cout << "\n\t      Reloading account section for client name editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"    1.1.1. "<<setw(6)<<"First name: ";
            cin >> f_name;
            cout << "\n" <<setw(21)<<"    1.1.2. "<<setw(6)<<"Middle name: ";
            cin >> m_name;
            cout << "\n" <<setw(21)<<"    1.1.3. "<<setw(6)<<"Surname name: ";
            cin >> l_name;
            customer4_id_name = ""+f_name+" "+m_name+" "+l_name;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 4 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer4_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer4_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer4_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer4_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer4_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer4_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client4_acc_crtn(choice);
                        //recalls fn for acc. name editing
        }
                //edit new client acc name
        else if(choice == 3)
        {
            cout << "\n\t      Reloading account section for client ID No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT ID NO. INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
            cin >> id_no;
            customer4_id_no = id_no;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 4 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer4_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer4_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer4_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer4_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer4_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer4_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                    //account summary info
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client4_acc_crtn(choice);
                    //acc_crtn_cnfrm(choice);
                    //client ID edit
        }
        else if(choice == 4)
        {
            cout << "\n\t      Reloading account section for client PIN No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT PIN INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
            cin >> bz_pin;
            customer4_pin = bz_pin;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 4 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer4_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer4_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer4_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer4_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer4_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer4_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client4_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 5)
        {
            cout << "\n\t      Reloading account section for client date of birth editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
            cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
            cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
            cin >> brth_dt;
            customer4_brth_dt = brth_dt;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 4 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer4_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer4_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer4_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer4_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer4_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer4_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client4_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 6)
        {
            cout << "\n\t      Reloading account section for client county id editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
            cin >> county_id;
            customer4_county_id = county_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 4 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer4_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer4_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer4_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer4_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer4_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer4_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client4_acc_crtn(choice);
                        //recalls fn for making changes
        }
        else if(choice == 7)
        {
            cout << "\n\t      Reloading account section for client nationality editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTRY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
            cin >> country_id;
            customer4_country_id = country_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 4 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer4_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer4_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer4_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer4_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer4_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer4_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client4_acc_crtn(choice);
                    //recalls fn for making chan
        }
        else
        {
            cout<<"\n\t         -----------------------------\n\n\t             ERROR!\n\t                   -Undefined option.\n\t                   -Please enter appropriate choice\n\t                    as guided above and try again.\n\n\t                    System waiting...\n\n\t\t              : ";
            cin>>choice;
                //operation actn dfn
            cout<<"\n\t             -----------------------------\n\n";
            client4_acc_crtn(choice);
                //recalls the fn
        }   //exception error handler
            //client details input
    }
                //account creator fn
    void client5_acc_crtn(int clnt5)
    {
        ofstream client5_acc_file;
                    //file object
        client5_acc_file.open("Client5_Acc_File.txt");

        cout << "\n\n\t   1.B.1: CLIENT 5 ACCOUNT CREATION\n\t   --------------------------------------------------------\n";
        cout << "\n\t   Fill ALL the fields as required below to complete the process.";
        cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.1.1. "<<setw(6)<<"First name: ";
        cin >> f_name;
        cout << "\n" <<setw(21)<<"1.1.2. "<<setw(6)<<"Middle name: ";
        cin >> m_name;
        cout << "\n" <<setw(21)<<"1.1.3. "<<setw(6)<<"Surname name: ";
        cin >> l_name;
        customer5_id_name = ""+f_name+" "+m_name+" "+l_name;
        optmzr_t();
            //client name initialisation
        cout << "\n\n\t    1.2. CLIENT BUSINESS CREDENTIALS: \n";
        cout << "\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
        cin >> id_no;
        cout << "\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
        cin >> bz_pin;
        customer5_id_no = id_no;
        customer5_pin = bz_pin;
        optmzr_t();
            //client biz info initialisationcoutry_id
        cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
        cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
        cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
        cin >> brth_dt;
        cout << "\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
        cin >> county_id;
        cout << "\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
        cin >> country_id;
        customer5_brth_dt = brth_dt;
        customer5_county_id = county_id;
        customer5_country_id = country_id;
        optmzr_t();
            //client biz info initialisation
        acc_auto_compltn();
            //xternal fn to regenerate acc. credentials
        optmzr_1_sec_t();
        cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 5 ACCOUNT INFORMATION";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer5_id_name<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer5_id_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer5_pin<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer5_brth_dt<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer5_county_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer5_country_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
                //account summary info
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
        cin >> choice;
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation option
        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n";

        if(choice == 1)
        {
            loadin_optmzr();
            create_acc_fl();
                    //call accounts creator and counter file
            updtt_acc_fl();
                    //calls accounts file updater fn
                    //saving session fn
                    //----------------file writing-----------------------------
            client5_acc_file << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 5 ACCOUNT INFORMATION";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer5_id_name<<"";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer5_id_no<<"";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer5_pin<<"";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer5_brth_dt<<"";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer5_county_id<<"";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer5_country_id<<"";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client5_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client5_acc_file.close();
                    //close file after writing mode
                    //----------------file writing-----------------------------
        }
        else if(choice == 2)
        {
            cout << "\n\t      Reloading account section for client name editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"    1.1.1. "<<setw(6)<<"First name: ";
            cin >> f_name;
            cout << "\n" <<setw(21)<<"    1.1.2. "<<setw(6)<<"Middle name: ";
            cin >> m_name;
            cout << "\n" <<setw(21)<<"    1.1.3. "<<setw(6)<<"Surname name: ";
            cin >> l_name;
            customer5_id_name = ""+f_name+" "+m_name+" "+l_name;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 5 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer5_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer5_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer5_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer5_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer5_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer5_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client5_acc_crtn(choice);
                        //recalls fn for acc. name editing
        }
                //edit new client acc name
        else if(choice == 3)
        {
            cout << "\n\t      Reloading account section for client ID No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT ID NO. INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
            cin >> id_no;
            customer5_id_no = id_no;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 5 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer5_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer5_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer5_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer5_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer5_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer5_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                    //account summary info
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client5_acc_crtn(choice);
                    //acc_crtn_cnfrm(choice);
                    //client ID edit
        }
        else if(choice == 4)
        {
            cout << "\n\t      Reloading account section for client PIN No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT PIN INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
            cin >> bz_pin;
            customer5_pin = bz_pin;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 5 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer5_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer5_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer5_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer5_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer5_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer5_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client5_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 5)
        {
            cout << "\n\t      Reloading account section for client date of birth editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
            cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
            cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
            cin >> brth_dt;
            customer5_brth_dt = brth_dt;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 5 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer5_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer5_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer5_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer5_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer5_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer5_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client5_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 6)
        {
            cout << "\n\t      Reloading account section for client county id editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
            cin >> county_id;
            customer5_county_id = county_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 5 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer5_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer5_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer5_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer5_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer5_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer5_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client5_acc_crtn(choice);
                        //recalls fn for making changes
        }
        else if(choice == 7)
        {
            cout << "\n\t      Reloading account section for client nationality editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTRY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
            cin >> country_id;
            customer5_country_id = country_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 5 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer5_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer5_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer5_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer5_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer5_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer5_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client5_acc_crtn(choice);
                    //recalls fn for making chan
        }
        else
        {
            cout<<"\n\t         -----------------------------\n\n\t             ERROR!\n\t                   -Undefined option.\n\t                   -Please enter appropriate choice\n\t                    as guided above and try again.\n\n\t                    System waiting...\n\n\t\t              : ";
            cin>>choice;
                //operation actn dfn
            cout<<"\n\t             -----------------------------\n\n";
            client5_acc_crtn(choice);
                //recalls the fn
        }   //exception error handler
            //client details input
    }
                //account creator fn
    void client6_acc_crtn(int clnt6)
    {
        ofstream client6_acc_file;
                    //file object
        client6_acc_file.open("Client6_Acc_File.txt");

        cout << "\n\n\t   1.B.1: NEW ACCOUNT CREATION\n\t   --------------------------------------------------------\n";
        cout << "\n\t   Fill ALL the fields as required below to complete the process.";
        cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.1.1. "<<setw(6)<<"First name: ";
        cin >> f_name;
        cout << "\n" <<setw(21)<<"1.1.2. "<<setw(6)<<"Middle name: ";
        cin >> m_name;
        cout << "\n" <<setw(21)<<"1.1.3. "<<setw(6)<<"Surname name: ";
        cin >> l_name;
        customer6_id_name = ""+f_name+" "+m_name+" "+l_name;
        optmzr_t();
            //client name initialisation
        cout << "\n\n\t    1.2. CLIENT BUSINESS CREDENTIALS: \n";
        cout << "\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
        cin >> id_no;
        cout << "\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
        cin >> bz_pin;
        customer6_id_no = id_no;
        customer6_pin = bz_pin;
        optmzr_t();
            //client biz info initialisationcoutry_id
        cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
        cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
        cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
        cin >> brth_dt;
        cout << "\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
        cin >> county_id;
        cout << "\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
        cin >> country_id;
        customer6_brth_dt = brth_dt;
        customer6_county_id = county_id;
        customer6_country_id = country_id;
        optmzr_t();
            //client biz info initialisation
        acc_auto_compltn();
            //xternal fn to regenerate acc. credentials
        optmzr_1_sec_t();
        cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 6 ACCOUNT INFORMATION";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer6_id_name<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer6_id_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer6_pin<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer6_brth_dt<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer6_county_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer6_country_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
                //account summary info
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
        cin >> choice;
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation option
        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n";

        if(choice == 1)
        {
            loadin_optmzr();
            create_acc_fl();
                    //call accounts creator and counter file
            updtt_acc_fl();
                    //calls accounts file updater fn
                    //saving session fn
                    //----------------file writing-----------------------------
            client6_acc_file << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 6 ACCOUNT INFORMATION";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer6_id_name<<"";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer6_id_no<<"";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer6_pin<<"";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer6_brth_dt<<"";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer6_county_id<<"";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer6_country_id<<"";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client6_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client6_acc_file.close();
                    //close file after writing mode
                    //----------------file writing-----------------------------
        }
        else if(choice == 2)
        {
            cout << "\n\t      Reloading account section for client name editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"    1.1.1. "<<setw(6)<<"First name: ";
            cin >> f_name;
            cout << "\n" <<setw(21)<<"    1.1.2. "<<setw(6)<<"Middle name: ";
            cin >> m_name;
            cout << "\n" <<setw(21)<<"    1.1.3. "<<setw(6)<<"Surname name: ";
            cin >> l_name;
            customer6_id_name = ""+f_name+" "+m_name+" "+l_name;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 6 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer6_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer6_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer6_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer6_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer6_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer6_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client6_acc_crtn(choice);
                        //recalls fn for acc. name editing
        }
                //edit new client acc name
        else if(choice == 3)
        {
            cout << "\n\t      Reloading account section for client ID No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT ID NO. INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
            cin >> id_no;
            customer6_id_no = id_no;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 6 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer6_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer6_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer6_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer6_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer6_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer6_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                    //account summary info
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client6_acc_crtn(choice);
                    //acc_crtn_cnfrm(choice);
                    //client ID edit
        }
        else if(choice == 4)
        {
            cout << "\n\t      Reloading account section for client PIN No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT PIN INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
            cin >> bz_pin;
            customer6_pin = bz_pin;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 6 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer6_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer6_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer6_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer6_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer6_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer6_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client6_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 5)
        {
            cout << "\n\t      Reloading account section for client date of birth editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
            cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
            cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
            cin >> brth_dt;
            customer6_brth_dt = brth_dt;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 6 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer6_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer6_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer6_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer6_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer6_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer6_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client6_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 6)
        {
            cout << "\n\t      Reloading account section for client county id editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
            cin >> county_id;
            customer6_county_id = county_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 6 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer6_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer6_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer6_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer6_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer6_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer6_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client6_acc_crtn(choice);
                        //recalls fn for making changes
        }
        else if(choice == 7)
        {
            cout << "\n\t      Reloading account section for client nationality editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTRY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
            cin >> country_id;
            customer6_country_id = country_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 6 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer6_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer6_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer6_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer6_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer6_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer6_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client6_acc_crtn(choice);
                    //recalls fn for making chan
        }
        else
        {
            cout<<"\n\t         -----------------------------\n\n\t             ERROR!\n\t                   -Undefined option.\n\t                   -Please enter appropriate choice\n\t                    as guided above and try again.\n\n\t                    System waiting...\n\n\t\t              : ";
            cin>>choice;
                //operation actn dfn
            cout<<"\n\t             -----------------------------\n\n";
            client6_acc_crtn(choice);
                //recalls the fn
        }   //exception error handler
            //client details input
    }
                //account creator fn
    void client7_acc_crtn(int clnt7)
    {
        ofstream client7_acc_file;
                    //file object
        client7_acc_file.open("Client7_Acc_File.txt");

        cout << "\n\n\t   1.B.1: NEW ACCOUNT CREATION\n\t   --------------------------------------------------------\n";
        cout << "\n\t   Fill ALL the fields as required below to complete the process.";
        cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.1.1. "<<setw(6)<<"First name: ";
        cin >> f_name;
        cout << "\n" <<setw(21)<<"1.1.2. "<<setw(6)<<"Middle name: ";
        cin >> m_name;
        cout << "\n" <<setw(21)<<"1.1.3. "<<setw(6)<<"Surname name: ";
        cin >> l_name;
        customer7_id_name = ""+f_name+" "+m_name+" "+l_name;
        optmzr_t();
            //client name initialisation
        cout << "\n\n\t    1.2. CLIENT BUSINESS CREDENTIALS: \n";
        cout << "\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
        cin >> id_no;
        cout << "\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
        cin >> bz_pin;
        customer7_id_no = id_no;
        customer7_pin = bz_pin;
        optmzr_t();
            //client biz info initialisationcoutry_id
        cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
        cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
        cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
        cin >> brth_dt;
        cout << "\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
        cin >> county_id;
        cout << "\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
        cin >> country_id;
        customer7_brth_dt = brth_dt;
        customer7_county_id = county_id;
        customer7_country_id = country_id;
        optmzr_t();
            //client biz info initialisation
        acc_auto_compltn();
            //xternal fn to regenerate acc. credentials
        optmzr_1_sec_t();
        cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 7 ACCOUNT INFORMATION";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer7_id_name<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer7_id_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer7_pin<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer7_brth_dt<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer7_county_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer7_country_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
                //account summary info
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
        cin >> choice;
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation option
        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n";

        if(choice == 1)
        {
            loadin_optmzr();
            create_acc_fl();
                    //call accounts creator and counter file
            updtt_acc_fl();
                    //calls accounts file updater fn
                    //saving session fn
                    //----------------file writing-----------------------------
            client7_acc_file << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 7 ACCOUNT INFORMATION";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer7_id_name<<"";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer7_id_no<<"";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer7_pin<<"";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer7_brth_dt<<"";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer7_county_id<<"";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer7_country_id<<"";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client7_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client7_acc_file.close();
                    //close file after writing mode
                    //----------------file writing-----------------------------
        }
        else if(choice == 2)
        {
            cout << "\n\t      Reloading account section for client name editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"    1.1.1. "<<setw(6)<<"First name: ";
            cin >> f_name;
            cout << "\n" <<setw(21)<<"    1.1.2. "<<setw(6)<<"Middle name: ";
            cin >> m_name;
            cout << "\n" <<setw(21)<<"    1.1.3. "<<setw(6)<<"Surname name: ";
            cin >> l_name;
            customer7_id_name = ""+f_name+" "+m_name+" "+l_name;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 7 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer7_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer7_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer7_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer7_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer7_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer7_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client7_acc_crtn(choice);
                        //recalls fn for acc. name editing
        }
                //edit new client acc name
        else if(choice == 3)
        {
            cout << "\n\t      Reloading account section for client ID No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT ID NO. INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
            cin >> id_no;
            customer7_id_no = id_no;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 7 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer7_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer7_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer7_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer7_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer7_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer7_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                    //account summary info
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client7_acc_crtn(choice);
                    //acc_crtn_cnfrm(choice);
                    //client ID edit
        }
        else if(choice == 4)
        {
            cout << "\n\t      Reloading account section for client PIN No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT PIN INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
            cin >> bz_pin;
            customer7_pin = bz_pin;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 7 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer7_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer7_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer7_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer7_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer7_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer7_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client7_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 5)
        {
            cout << "\n\t      Reloading account section for client date of birth editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
            cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
            cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
            cin >> brth_dt;
            customer7_brth_dt = brth_dt;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 7 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer7_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer7_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer7_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer7_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer7_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer7_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client7_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 6)
        {
            cout << "\n\t      Reloading account section for client county id editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
            cin >> county_id;
            customer7_county_id = county_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 7 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer7_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer7_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer7_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer7_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer7_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer7_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client7_acc_crtn(choice);
                        //recalls fn for making changes
        }
        else if(choice == 7)
        {
            cout << "\n\t      Reloading account section for client nationality editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTRY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
            cin >> country_id;
            customer7_country_id = country_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 7 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer7_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer7_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer7_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer7_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer7_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer7_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client7_acc_crtn(choice);
                    //recalls fn for making chan
        }
        else
        {
            cout<<"\n\t         -----------------------------\n\n\t             ERROR!\n\t                   -Undefined option.\n\t                   -Please enter appropriate choice\n\t                    as guided above and try again.\n\n\t                    System waiting...\n\n\t\t              : ";
            cin>>choice;
                //operation actn dfn
            cout<<"\n\t             -----------------------------\n\n";
            client7_acc_crtn(choice);
                //recalls the fn
        }   //exception error handler
            //client details input
    }
                //account creator fn
    void client8_acc_crtn(int clnt8)
    {
        ofstream client8_acc_file;
                    //file object
        client8_acc_file.open("Client8_Acc_File.txt");

        cout << "\n\n\t   1.B.1: NEW ACCOUNT CREATION\n\t   --------------------------------------------------------\n";
        cout << "\n\t   Fill ALL the fields as required below to complete the process.";
        cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.1.1. "<<setw(6)<<"First name: ";
        cin >> f_name;
        cout << "\n" <<setw(21)<<"1.1.2. "<<setw(6)<<"Middle name: ";
        cin >> m_name;
        cout << "\n" <<setw(21)<<"1.1.3. "<<setw(6)<<"Surname name: ";
        cin >> l_name;
        customer8_id_name = ""+f_name+" "+m_name+" "+l_name;
        optmzr_t();
            //client name initialisation
        cout << "\n\n\t    1.2. CLIENT BUSINESS CREDENTIALS: \n";
        cout << "\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
        cin >> id_no;
        cout << "\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
        cin >> bz_pin;
        customer8_id_no = id_no;
        customer8_pin = bz_pin;
        optmzr_t();
            //client biz info initialisationcoutry_id
        cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
        cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
        cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
        cin >> brth_dt;
        cout << "\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
        cin >> county_id;
        cout << "\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
        cin >> country_id;
        customer8_brth_dt = brth_dt;
        customer8_county_id = county_id;
        customer8_country_id = country_id;
        optmzr_t();
            //client biz info initialisation
        acc_auto_compltn();
            //xternal fn to regenerate acc. credentials
        optmzr_1_sec_t();
        cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 8 ACCOUNT INFORMATION";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer8_id_name<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer8_id_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer8_pin<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer8_brth_dt<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer8_county_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer8_country_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
                //account summary info
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
        cin >> choice;
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation option
        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n";

        if(choice == 1)
        {
            loadin_optmzr();
            create_acc_fl();
                    //call accounts creator and counter file
            updtt_acc_fl();
                    //calls accounts file updater fn
                    //saving session fn
                    //----------------file writing-----------------------------
            client8_acc_file << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       NEW ACCOUNT INFORMATION";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer8_id_name<<"";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer8_id_no<<"";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer8_pin<<"";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer8_brth_dt<<"";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer8_county_id<<"";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer8_country_id<<"";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client8_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client8_acc_file.close();
                    //close file after writing mode
                    //----------------file writing-----------------------------
        }
        else if(choice == 2)
        {
            cout << "\n\t      Reloading account section for client name editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"    1.1.1. "<<setw(6)<<"First name: ";
            cin >> f_name;
            cout << "\n" <<setw(21)<<"    1.1.2. "<<setw(6)<<"Middle name: ";
            cin >> m_name;
            cout << "\n" <<setw(21)<<"    1.1.3. "<<setw(6)<<"Surname name: ";
            cin >> l_name;
            customer8_id_name = ""+f_name+" "+m_name+" "+l_name;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 8 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer8_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer8_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer8_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer8_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer8_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer8_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client8_acc_crtn(choice);
                        //recalls fn for acc. name editing
        }
                //edit new client acc name
        else if(choice == 3)
        {
            cout << "\n\t      Reloading account section for client ID No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT ID NO. INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
            cin >> id_no;
            customer8_id_no = id_no;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 8 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer8_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer8_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer8_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer8_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer8_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer8_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                    //account summary info
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client8_acc_crtn(choice);
                    //acc_crtn_cnfrm(choice);
                    //client ID edit
        }
        else if(choice == 4)
        {
            cout << "\n\t      Reloading account section for client PIN No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT PIN INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
            cin >> bz_pin;
            customer8_pin = bz_pin;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 8 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer8_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer8_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer8_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer8_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer8_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer8_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client8_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 5)
        {
            cout << "\n\t      Reloading account section for client date of birth editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
            cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
            cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
            cin >> brth_dt;
            customer8_brth_dt = brth_dt;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 8 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer8_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer8_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer8_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer8_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer8_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer8_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client8_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 6)
        {
            cout << "\n\t      Reloading account section for client county id editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
            cin >> county_id;
            customer8_county_id = county_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 8 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer8_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer8_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer8_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer8_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer8_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer8_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client8_acc_crtn(choice);
                        //recalls fn for making changes
        }
        else if(choice == 7)
        {
            cout << "\n\t      Reloading account section for client nationality editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTRY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
            cin >> country_id;
            customer8_country_id = country_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 8 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer8_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer8_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer8_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer8_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer8_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer8_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client8_acc_crtn(choice);
                    //recalls fn for making chan
        }
        else
        {
            cout<<"\n\t         -----------------------------\n\n\t             ERROR!\n\t                   -Undefined option.\n\t                   -Please enter appropriate choice\n\t                    as guided above and try again.\n\n\t                    System waiting...\n\n\t\t              : ";
            cin>>choice;
                //operation actn dfn
            cout<<"\n\t             -----------------------------\n\n";
            client8_acc_crtn(choice);
                //recalls the fn
        }   //exception error handler
            //client details input
    }
                //account creator fn
    void client9_acc_crtn(int clnt9)
    {
        ofstream client9_acc_file;
                    //file object
        client9_acc_file.open("Client9_Acc_File.txt");

        cout << "\n\n\t   1.B.1: NEW ACCOUNT CREATION\n\t   --------------------------------------------------------\n";
        cout << "\n\t   Fill ALL the fields as required below to complete the process.";
        cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.1.1. "<<setw(6)<<"First name: ";
        cin >> f_name;
        cout << "\n" <<setw(21)<<"1.1.2. "<<setw(6)<<"Middle name: ";
        cin >> m_name;
        cout << "\n" <<setw(21)<<"1.1.3. "<<setw(6)<<"Surname name: ";
        cin >> l_name;
        customer9_id_name = ""+f_name+" "+m_name+" "+l_name;
        optmzr_t();
            //client name initialisation
        cout << "\n\n\t    1.2. CLIENT BUSINESS CREDENTIALS: \n";
        cout << "\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
        cin >> id_no;
        cout << "\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
        cin >> bz_pin;
        customer9_id_no = id_no;
        customer9_pin = bz_pin;
        optmzr_t();
            //client biz info initialisationcoutry_id
        cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
        cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
        cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
        cin >> brth_dt;
        cout << "\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
        cin >> county_id;
        cout << "\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
        cin >> country_id;
        customer9_brth_dt = brth_dt;
        customer9_county_id = county_id;
        customer9_country_id = country_id;
        optmzr_t();
            //client biz info initialisation
        acc_auto_compltn();
            //xternal fn to regenerate acc. credentials
        optmzr_1_sec_t();
        cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 9 ACCOUNT INFORMATION";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer9_id_name<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer9_id_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer9_pin<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer9_brth_dt<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer9_county_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer9_country_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
                //account summary info
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
        cin >> choice;
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation option
        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n";

        if(choice == 1)
        {
            loadin_optmzr();
            create_acc_fl();
                    //call accounts creator and counter file
            updtt_acc_fl();
                    //calls accounts file updater fn
                    //saving session fn
                    //----------------file writing-----------------------------
            client9_acc_file << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 9 ACCOUNT INFORMATION";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer9_id_name<<"";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer9_id_no<<"";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer9_pin<<"";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer9_brth_dt<<"";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer9_county_id<<"";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer9_country_id<<"";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client9_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client9_acc_file.close();
                    //close file after writing mode
                    //----------------file writing-----------------------------
        }
        else if(choice == 2)
        {
            cout << "\n\t      Reloading account section for client name editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"    1.1.1. "<<setw(6)<<"First name: ";
            cin >> f_name;
            cout << "\n" <<setw(21)<<"    1.1.2. "<<setw(6)<<"Middle name: ";
            cin >> m_name;
            cout << "\n" <<setw(21)<<"    1.1.3. "<<setw(6)<<"Surname name: ";
            cin >> l_name;
            customer9_id_name = ""+f_name+" "+m_name+" "+l_name;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 9 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer9_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer9_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer9_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer9_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer9_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer9_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client9_acc_crtn(choice);
                        //recalls fn for acc. name editing
        }
                //edit new client acc name
        else if(choice == 3)
        {
            cout << "\n\t      Reloading account section for client ID No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT ID NO. INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
            cin >> id_no;
            customer9_id_no = id_no;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 9 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer9_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer9_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer9_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer9_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer9_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer9_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                    //account summary info
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client9_acc_crtn(choice);
                    //acc_crtn_cnfrm(choice);
                    //client ID edit
        }
        else if(choice == 4)
        {
            cout << "\n\t      Reloading account section for client PIN No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT PIN INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
            cin >> bz_pin;
            customer9_pin = bz_pin;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 9 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer9_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer9_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer9_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer9_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer9_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer9_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client9_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 5)
        {
            cout << "\n\t      Reloading account section for client date of birth editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
            cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
            cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
            cin >> brth_dt;
            customer9_brth_dt = brth_dt;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 9 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer9_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer9_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer9_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer9_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer9_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer9_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client9_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 6)
        {
            cout << "\n\t      Reloading account section for client county id editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
            cin >> county_id;
            customer9_county_id = county_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 9 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer9_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer9_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer9_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer9_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer9_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer9_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client9_acc_crtn(choice);
                        //recalls fn for making changes
        }
        else if(choice == 7)
        {
            cout << "\n\t      Reloading account section for client nationality editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTRY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
            cin >> country_id;
            customer9_country_id = country_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 9 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer9_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer9_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer9_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer9_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer9_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer9_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client9_acc_crtn(choice);
                    //recalls fn for making chan
        }
        else
        {
            cout<<"\n\t         -----------------------------\n\n\t             ERROR!\n\t                   -Undefined option.\n\t                   -Please enter appropriate choice\n\t                    as guided above and try again.\n\n\t                    System waiting...\n\n\t\t              : ";
            cin>>choice;
                //operation actn dfn
            cout<<"\n\t             -----------------------------\n\n";
            client9_acc_crtn(choice);
                //recalls the fn
        }   //exception error handler
            //client details input
    }
                //account creator fn
    void client10_acc_crtn(int clnt10)
    {
        ofstream client10_acc_file;
                    //file object
        client10_acc_file.open("Client10_Acc_File.txt");

        cout << "\n\n\t   1.B.1: NEW ACCOUNT CREATION\n\t   --------------------------------------------------------\n";
        cout << "\n\t   Fill ALL the fields as required below to complete the process.";
        cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.1.1. "<<setw(6)<<"First name: ";
        cin >> f_name;
        cout << "\n" <<setw(21)<<"1.1.2. "<<setw(6)<<"Middle name: ";
        cin >> m_name;
        cout << "\n" <<setw(21)<<"1.1.3. "<<setw(6)<<"Surname name: ";
        cin >> l_name;
        customer10_id_name = ""+f_name+" "+m_name+" "+l_name;
        optmzr_t();
            //client name initialisation
        cout << "\n\n\t    1.2. CLIENT BUSINESS CREDENTIALS: \n";
        cout << "\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
        cin >> id_no;
        cout << "\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
        cin >> bz_pin;
        customer10_id_no = id_no;
        customer10_pin = bz_pin;
        optmzr_t();
            //client biz info initialisationcoutry_id
        cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
        cout << "\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
        cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
        cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
        cin >> brth_dt;
        cout << "\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
        cin >> county_id;
        cout << "\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
        cin >> country_id;
        customer10_brth_dt = brth_dt;
        customer10_county_id = county_id;
        customer10_country_id = country_id;
        optmzr_t();
            //client biz info initialisation
        acc_auto_compltn();
            //xternal fn to regenerate acc. credentials
        optmzr_1_sec_t();
        cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 10 ACCOUNT INFORMATION";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer10_id_name<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer10_id_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer10_pin<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer10_brth_dt<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer10_county_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer10_country_id<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
                //account summary info
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
        cin >> choice;
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation option
        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n";

        if(choice == 1)
        {
            loadin_optmzr();
            create_acc_fl();
                    //call accounts creator and counter file
            updtt_acc_fl();
                    //calls accounts file updater fn
                    //saving session fn
                    //----------------file writing-----------------------------
            client10_acc_file << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 10 ACCOUNT INFORMATION";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer10_id_name<<"";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer10_id_no<<"";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer10_pin<<"";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer10_brth_dt<<"";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer10_county_id<<"";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer10_country_id<<"";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            client10_acc_file << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            client10_acc_file.close();
                    //close file after writing mode
                    //----------------file writing-----------------------------
        }
        else if(choice == 2)
        {
            cout << "\n\t      Reloading account section for client name editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.1. CLIENT NAME INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"    1.1.1. "<<setw(6)<<"First name: ";
            cin >> f_name;
            cout << "\n" <<setw(21)<<"    1.1.2. "<<setw(6)<<"Middle name: ";
            cin >> m_name;
            cout << "\n" <<setw(21)<<"    1.1.3. "<<setw(6)<<"Surname name: ";
            cin >> l_name;
            customer10_id_name = ""+f_name+" "+m_name+" "+l_name;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 10 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer10_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer10_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer10_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer10_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer10_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer10_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client10_acc_crtn(choice);
                        //recalls fn for acc. name editing
        }
                //edit new client acc name
        else if(choice == 3)
        {
            cout << "\n\t      Reloading account section for client ID No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT ID NO. INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.1. "<<setw(6)<<"National/Passport ID Number: ";
            cin >> id_no;
            customer10_id_no = id_no;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 10ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer10_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer10_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer10_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer10_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer10_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer10_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                    //account summary info
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client10_acc_crtn(choice);
                    //acc_crtn_cnfrm(choice);
                    //client ID edit
        }
        else if(choice == 4)
        {
            cout << "\n\t      Reloading account section for client PIN No. editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.2. CLIENT PIN INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.2.2. "<<setw(6)<<"KRA PIN: ";
            cin >> bz_pin;
            customer10_pin = bz_pin;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 10 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer10_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer10_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer10_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer10_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer10_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer10_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client10_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 5)
        {
            cout << "\n\t      Reloading account section for client date of birth editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT AGE INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.1. "<<setw(6)<<"Date of Birth.";
            cout << "\n\n" <<setw(21)<<""<<setw(8)<<"-Use formart e.g 15/09/1995\n";
            cout << "\n" <<setw(21)<<""<<setw(8)<<"Date: ";
            cin >> brth_dt;
            customer10_brth_dt = brth_dt;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 10 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer10_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer10_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer10_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer10_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer10_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer10_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client10_acc_crtn(choice);
                    //recalls fn for making changes
        }
        else if(choice == 6)
        {
            cout << "\n\t      Reloading account section for client county id editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.2. "<<setw(6)<<"Home County: ";
            cin >> county_id;
            customer10_county_id = county_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 10 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer10_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer10_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer10_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer10_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer10_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer10_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client10_acc_crtn(choice);
                        //recalls fn for making changes
        }
        else if(choice == 7)
        {
            cout << "\n\t      Reloading account section for client nationality editing \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\n\t    1.3. CLIENT COUNTRY INFORMATION: \n";
            cout << "\n\t    Fill ALL the fields as required below to complete editing process.";
            cout << "\n\n" <<setw(21)<<"1.3.3. "<<setw(6)<<"Nationality: ";
            cin >> country_id;
            customer10_country_id = country_id;
            optmzr_t();
                //client biz info initialisation
            acc_auto_compltn();
                //xternal fn to regenerate acc. credentials
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 10 ACCOUNT INFORMATION";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  ACCOUNT DETAILS"<<setw(8)<<"        |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"     |    "<<setw(8)<<customer10_id_name<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"     |    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID NUMBER:"<<setw(8)<<"       |    "<<setw(8)<<customer10_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    KRA PIN NUMBER:"<<setw(7)<<"|    "<<setw(8)<<customer10_pin<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  5.    DATE OF BIRTH:"<<setw(8)<<"   |    "<<setw(8)<<customer10_brth_dt<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  6.    HOME COUNTY:"<<setw(8)<<"     |    "<<setw(8)<<customer10_county_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  7.    NATIONALITY:"<<setw(8)<<"     |    "<<setw(8)<<customer10_country_id<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //account summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Edit Name.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    3.  Edit ID Number.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    4.  Edit PIN.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    5.  Edit Date of Birth.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    6.  Edit County.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    7.  Edit Nationality.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation optio
            optmzr_2_sec_t();
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            client10_acc_crtn(choice);
                    //recalls fn for making chan
        }
        else
        {
            cout<<"\n\t         -----------------------------\n\n\t             ERROR!\n\t                   -Undefined option.\n\t                   -Please enter appropriate choice\n\t                    as guided above and try again.\n\n\t                    System waiting...\n\n\t\t              : ";
            cin>>choice;
                //operation actn dfn
            cout<<"\n\t             -----------------------------\n\n";
            client10_acc_crtn(choice);
                //recalls the fn
        }   //exception error handler
            //client details input
    }
                //account creator fn
    void deposit_prmpt()
    {
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        cout << "\n\n\t   1.B.3: DEPOSIT AMONUT\n\t   --------------------------------------------------------\n";
        cout << "\n\t   Re-enter deposit amount to complete the transaction process.\n";
        auth_acc_fl();
                    //calls accs auth fn
        if(accs_no == 1)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_dpst;
                    //client withdraw amount
            customer1_blnc_info = amnt_dpst;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer1_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer1_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }           //client1 deposit info
        if(accs_no == 2)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_dpst;
                    //client withdraw amount
            customer2_blnc_info = amnt_dpst;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer2_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer2_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }           //client2 deposit info
        if(accs_no == 3)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_dpst;
                    //client withdraw amount
            customer3_blnc_info = amnt_dpst;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer3_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer3_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }           //client1 deposit info
        if(accs_no == 4)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_dpst;
                    //client withdraw amount
            customer4_blnc_info = amnt_dpst;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer4_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer4_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }           //client1 deposit info
        if(accs_no == 5)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_dpst;
                    //client withdraw amount
            customer5_blnc_info = amnt_dpst;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer5_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer5_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }           //client1 deposit info
        if(accs_no == 6)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_dpst;
                    //client withdraw amount
            customer6_blnc_info = amnt_dpst;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer6_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer6_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }           //client1 deposit info
        if(accs_no == 7)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_dpst;
                    //client withdraw amount
            customer7_blnc_info = amnt_dpst;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer7_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer7_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }           //client1 deposit info
        if(accs_no == 8)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_dpst;
                    //client withdraw amount
            customer8_blnc_info = amnt_dpst;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer8_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer8_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }           //client1 deposit info
        if(accs_no == 9)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_dpst;
                    //client withdraw amount
            customer9_blnc_info = amnt_dpst;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer9_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer9_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }           //client1 deposit info
        if(accs_no == 10)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_dpst;
                    //client withdraw amount
            customer10_blnc_info = amnt_dpst;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer10_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer10_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }           //client1 deposit info

        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        deposit_cnfrm(choice);
                //set client withdraw info
    }
    void deposit_cnfrm(int dpst_optn)
    {
        if(dpst_optn == 1)
        {
            auth_acc_fl();
                    //calls accs auth fn
            saving_fn();
                    //saving session fn
            if(accs_no == 1)
            {
                ofstream deposits_file1;
                        //file object
                deposits_file1.open("Client1_deposits_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-------------file writing-------------------------
                deposits_file1 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file1 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
                deposits_file1 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file1 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file1 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                deposits_file1 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file1 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file1 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<customer1_id_name<<"";
                deposits_file1 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file1 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                deposits_file1 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file1 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer1_id_no<<"";
                deposits_file1 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file1 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer1_blnc_info<<"";
                deposits_file1 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file1 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file1 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file1.close();
            }       //client1 deposit info
            else if(accs_no == 2)
            {
                ofstream deposits_file2;
                        //file object
                deposits_file2.open("Client2_deposits_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-------------file writing-------------------------
                deposits_file2 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file2 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
                deposits_file2 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file2 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file2 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                deposits_file2 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file2 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file2 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<customer2_id_name<<"";
                deposits_file2 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file2 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                deposits_file2 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file2 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer2_id_no<<"";
                deposits_file2 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file2 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer2_blnc_info<<"";
                deposits_file2 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file2 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file2 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file2.close();
            }       //client1 deposit info
            else if(accs_no == 3)
            {
                ofstream deposits_file3;
                        //file object
                deposits_file3.open("Client3_deposits_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-------------file writing-------------------------
                deposits_file3 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file3 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
                deposits_file3 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file3 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file3 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                deposits_file3 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file3 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file3 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<customer3_id_name<<"";
                deposits_file3 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file3 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                deposits_file3 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file3 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer3_id_no<<"";
                deposits_file3 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file3 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer3_blnc_info<<"";
                deposits_file3 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file3 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file3 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file3.close();
            }       //client3 deposit info
            else if(accs_no == 4)
            {
                ofstream deposits_file4;
                        //file object
                deposits_file4.open("Client4_deposits_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-------------file writing-------------------------
                deposits_file4 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file4 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
                deposits_file4 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file4 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file4 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                deposits_file4 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file4 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file4 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<customer4_id_name<<"";
                deposits_file4 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file4 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                deposits_file4 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file4 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer4_id_no<<"";
                deposits_file4 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file4 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer4_blnc_info<<"";
                deposits_file4 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file4 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file4 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file4.close();
            }       //client4 deposit info
            else if(accs_no == 5)
            {
                ofstream deposits_file5;
                        //file object
                deposits_file5.open("Client5_deposits_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-------------file writing-------------------------
                deposits_file5 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file5 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
                deposits_file5 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file5 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file5 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                deposits_file5 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file5 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file5 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<customer5_id_name<<"";
                deposits_file5 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file5 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                deposits_file5 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file5 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer5_id_no<<"";
                deposits_file5 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file5 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer5_blnc_info<<"";
                deposits_file5 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file5 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file5 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file5.close();
            }       //client1 deposit info
            else if(accs_no == 6)
            {
                ofstream deposits_file6;
                        //file object
                deposits_file6.open("Client6_deposits_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-------------file writing-------------------------
                deposits_file6 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file6 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
                deposits_file6 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file6 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file6 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                deposits_file6 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file6 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file6 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<customer6_id_name<<"";
                deposits_file6 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file6 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                deposits_file6 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file6 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer6_id_no<<"";
                deposits_file6 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file6 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer6_blnc_info<<"";
                deposits_file6 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file6 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file6 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file6.close();
            }       //client6 deposit info
            else if(accs_no == 7)
            {
                ofstream deposits_file7;
                        //file object
                deposits_file7.open("Client7_deposits_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-------------file writing-------------------------
                deposits_file7 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file7 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
                deposits_file7 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file7 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file7 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                deposits_file7 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file7 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file7 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<customer7_id_name<<"";
                deposits_file7 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file7 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                deposits_file7 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file7 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer7_id_no<<"";
                deposits_file7 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file7 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer7_blnc_info<<"";
                deposits_file7 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file7 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file7 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file7.close();
            }       //client1 deposit info
            else if(accs_no == 8)
            {
                ofstream deposits_file8;
                        //file object
                deposits_file8.open("Client8_deposits_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-------------file writing-------------------------
                deposits_file8 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file8 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
                deposits_file8 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file8 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file8 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                deposits_file8 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file8 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file8 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<customer8_id_name<<"";
                deposits_file8 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file8 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                deposits_file8 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file8 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer8_id_no<<"";
                deposits_file8 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file8 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer8_blnc_info<<"";
                deposits_file8 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file8 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file8 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file8.close();
            }       //client8 deposit info
            else if(accs_no == 9)
            {
                ofstream deposits_file9;
                        //file object
                deposits_file9.open("Client9_deposits_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-------------file writing-------------------------
                deposits_file9 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file9 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
                deposits_file9 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file9 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file9 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                deposits_file9 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file9 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file9 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<customer9_id_name<<"";
                deposits_file9 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file9 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                deposits_file9 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file9 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer9_id_no<<"";
                deposits_file9 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file9 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer9_blnc_info<<"";
                deposits_file9 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file9 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file9 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file9.close();
            }       //client9 deposit info
            else if(accs_no == 10)
            {
                ofstream deposits_file10;
                        //file object
                deposits_file10.open("Client10_deposits_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-------------file writing-------------------------
                deposits_file10 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file10 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
                deposits_file10 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file10 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file10 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                deposits_file10 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file10 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file10 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<customer10_id_name<<"";
                deposits_file10 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file10 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                deposits_file10 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file10 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer10_id_no<<"";
                deposits_file10 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file10 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer10_blnc_info<<"";
                deposits_file10 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file10 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                deposits_file10 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                deposits_file10.close();
            }       //client10 deposit info
                    //withdrawal summary info
                    //close file after writing process
                    //-------------file writing-------------------------
        }
        else if(dpst_optn == 2)
        {
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\t      Reloading deposit section \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            deposit_prmpt();
                    //recalls fn for making changes
        }
        else
        {
            cout<<"\n\t         -----------------------------\n\n\t             ERROR!\n\t                   -Undefined option.\n\t                   -Please enter appropriate choice\n\t                    as guided above and try again.\n\n\t                    System waiting...\n\n\t\t              : ";
            cin>>choice;
                //operation actn dfn
            cout<<"\n\t             -----------------------------\n\n";
            deposit_cnfrm(choice);
                //recalls the fn
        }   //exception error handler
    }   //deposit process confirmation fn
    void Make_Deposit()
    {
        cout << "\n\n\t   1.B.2: DEPOSIT AMOUNT\n\t   --------------------------------------------------------\n";
        cout << "\n\t   Fill ALL the fields as required below to complete the transaction process.";
        cout << "\n\n\t    2.1. CLIENT CREDENTTIALS: \n";
        cout << "\n" <<setw(21)<<"2.1.1. "<<setw(6)<<"Account Number: ";
        cin >> client_acc_no;
        cout << "\n" <<setw(21)<<"2.1.2. "<<setw(6)<<"ID Number: ";
        cin >> id_no;
        cout << "\n" <<setw(21)<<"2.1.3. "<<setw(6)<<"Amount to deposit: ";
        cin >> amnt_dpst;
                //client deposit amount
        customer1_acc_no = client_acc_no;
        customer1_id_no = id_no;
        customer1_blnc_info = amnt_dpst;
                //set client deposit info
                //------------reads from file----------------------

        ifstream Read_dpst_fl;
                //read file object
        Read_dpst_fl.open("Client1_Acc_File.txt");
        if(Read_dpst_fl.fail())
        {
            cerr << "\n  " <<setw(16)<<"   "<<setw(6)<<"Error in opening the file!";
            exit(1);
        }       //exception handler
        Read_dpst_fl >> customer1_id_name;
                //reads file content
                //------------reads from file----------------------

        optmzr_1_sec_t();
        cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       DEPOSIT INFORMATION SUMMARY";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<customer1_id_name<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer1_id_no<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer1_blnc_info<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
                //withdrawal summary info
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
        cin >> choice;
        cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation option
        optmzr_2_sec_t();
        deposit_cnfrm(choice);
    }
                //deposits  fn
    void withdrawal_prmpt()
    {
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        cout << "\n\n\t   1.B.3: WITHDRAW AMONUT\n\t   --------------------------------------------------------\n";
        cout << "\n\t   Re-enter withdrawal amount to complete the transaction process.\n";
        auth_acc_fl();
            //calls accs auth fn
        if(accs_no == 1)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer1_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer1_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer1_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            //confirmation option
        }   //client1 withdraw info
        else if(accs_no == 2)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer2_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer2_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer2_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            //confirmation option
        }   //client2 withdraw info
        else if(accs_no == 3)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer3_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer3_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer3_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            //confirmation option
        }   //client3 withdraw info
        else if(accs_no == 4)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer4_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer4_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer4_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            //confirmation option
        }   //client4 withdraw info
        else if(accs_no == 5)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer5_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer5_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer5_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            //confirmation option
        }   //client5 withdraw info
        else if(accs_no == 6)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer6_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer6_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer6_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            //confirmation option
        }   //client6 withdraw info
        else if(accs_no == 7)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer7_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer7_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer7_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            //confirmation option
        }   //client7 withdraw info
        else if(accs_no == 8)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer8_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer8_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer8_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            //confirmation option
        }   //client8 withdraw info
        else if(accs_no == 9)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer9_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer9_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer9_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            //confirmation option
        }   //client9 withdraw info
        else if(accs_no == 10)
        {
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer10_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer10_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer10_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            //confirmation option
        }   //client10 withdraw info
        optmzr_2_sec_t();
        cout << "\n\n\t   --------------------------------------------------------\n\n";
        withdrawal_cnfrm(choice);
                //set client withdraw info
    }
    void withdrawal_cnfrm(int withdrwl_optn)
    {
        auth_acc_fl();
            //calls accs auth fn
        if(withdrwl_optn == 1)
        {
            submit_fn();
                    //submitting fn
            if(accs_no == 1)
            {
                ofstream withdrawals_file1;
                        //file object
                withdrawals_file1.open("Client1_withdrawals_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-----------------file writing-------------------------
                withdrawals_file1 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file1 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 1 WITHDRAWAL INFORMATION SUMMARY";
                withdrawals_file1 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"---------------------------------------------------------";
                withdrawals_file1 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file1 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                withdrawals_file1 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file1 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file1 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file1 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file1 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file1 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file1 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer1_id_no<<"";
                withdrawals_file1 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file1 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer1_blnc_info<<"";
                withdrawals_file1 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file1 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file1 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file1.close();
                    //close file after writing process
            }//client1 withdraw info
            else if(accs_no == 2)
            {
                ofstream withdrawals_file2;
                        //file object
                withdrawals_file2.open("Client2_withdrawals_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-----------------file writing-------------------------
                withdrawals_file2 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file2 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 2 WITHDRAWAL INFORMATION SUMMARY";
                withdrawals_file2 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"------------------------------------------------------------";
                withdrawals_file2 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file2 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                withdrawals_file2 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file2 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file2 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file2 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file2 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file2 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file2 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer2_id_no<<"";
                withdrawals_file2 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file2 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer2_blnc_info<<"";
                withdrawals_file2 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file2 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file2 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file2.close();
                    //close file after writing process
            }//client2 withdraw info
            else if(accs_no == 3)
            {
                ofstream withdrawals_file3;
                        //file object
                withdrawals_file3.open("Client3_withdrawals_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-----------------file writing-------------------------
                withdrawals_file3 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file3 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
                withdrawals_file3 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file3 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file3 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                withdrawals_file3 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file3 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file3 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file3 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file3 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file3 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file3 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer3_id_no<<"";
                withdrawals_file3 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file3 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer3_blnc_info<<"";
                withdrawals_file3 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file3 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file3 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file3.close();
                    //close file after writing process
            }//client3 withdraw info
            else if(accs_no == 4)
            {
                ofstream withdrawals_file4;
                        //file object
                withdrawals_file4.open("Client4_withdrawals_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-----------------file writing-------------------------
                withdrawals_file4 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file4 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
                withdrawals_file4 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file4 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file4 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                withdrawals_file4 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file4 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file4 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file4 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file4 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file4 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file4 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer4_id_no<<"";
                withdrawals_file4 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file4 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer4_blnc_info<<"";
                withdrawals_file4 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file4 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file4 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file4.close();
                    //close file after writing process
            }//client4 withdraw info
            else if(accs_no == 5)
            {
                ofstream withdrawals_file5;
                        //file object
                withdrawals_file5.open("Client5_withdrawals_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-----------------file writing-------------------------
                withdrawals_file5 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file5 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
                withdrawals_file5 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file5 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file5 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                withdrawals_file5 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file5 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file5 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file5 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file5 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file5 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file5 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer5_id_no<<"";
                withdrawals_file5 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file5 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer5_blnc_info<<"";
                withdrawals_file5 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file5 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file5 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file5.close();
                    //close file after writing process
            }//client5 withdraw info
            else if(accs_no == 6)
            {
                ofstream withdrawals_file6;
                        //file object
                withdrawals_file6.open("Client6_withdrawals_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-----------------file writing-------------------------
                withdrawals_file6 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file6 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
                withdrawals_file6 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file6 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file6 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                withdrawals_file6 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file6 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file6 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file6 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file6 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file6 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file6 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer6_id_no<<"";
                withdrawals_file6 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file6 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer6_blnc_info<<"";
                withdrawals_file6 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file6 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file6 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file6.close();
                    //close file after writing process
            }//client6 withdraw info
            else if(accs_no == 7)
            {
                ofstream withdrawals_file7;
                        //file object
                withdrawals_file7.open("Client7_withdrawals_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-----------------file writing-------------------------
                withdrawals_file7 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file7 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
                withdrawals_file7 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file7 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file7 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                withdrawals_file7 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file7 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file7 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file7 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file7 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file7 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file7 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer7_id_no<<"";
                withdrawals_file7 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file7 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer7_blnc_info<<"";
                withdrawals_file7 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file7 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file7 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file7.close();
                    //close file after writing process
            }//client7 withdraw info
            else if(accs_no == 8)
            {
                ofstream withdrawals_file8;
                        //file object
                withdrawals_file8.open("Client8_withdrawals_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-----------------file writing-------------------------
                withdrawals_file8 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file8 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
                withdrawals_file8 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file8 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file8 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                withdrawals_file8 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file8 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file8 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file8 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file8 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file8 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file8 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer8_id_no<<"";
                withdrawals_file8 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file8 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer8_blnc_info<<"";
                withdrawals_file8 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file8 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file8 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file8.close();
                    //close file after writing process
            }//client8 withdraw info
            else if(accs_no == 9)
            {
                ofstream withdrawals_file9;
                        //file object
                withdrawals_file9.open("Client9_withdrawals_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-----------------file writing-------------------------
                withdrawals_file9 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file9 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
                withdrawals_file9 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file9 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file9 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                withdrawals_file9 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file9 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file9 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file9 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file9 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file9 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file9 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer9_id_no<<"";
                withdrawals_file9 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file9 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer9_blnc_info<<"";
                withdrawals_file9 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file9 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file9 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file9.close();
                    //close file after writing process
            }//client9 withdraw info
            else if(accs_no == 10)
            {
                ofstream withdrawals_file10;
                        //file object
                withdrawals_file10.open("Client10_withdrawals_file.txt");
                        //opens file for writing mode
                        //creates deposits .txt file in the main parent directory

                        //-----------------file writing-------------------------
                withdrawals_file10 << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file10 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       WITHDRAWAL INFORMATION SUMMARY";
                withdrawals_file10 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file10 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file10 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
                withdrawals_file10 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file10 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file10 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file10 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file10 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
                withdrawals_file10 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file10 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer10_id_no<<"";
                withdrawals_file10 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file10 << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer10_blnc_info<<"";
                withdrawals_file10 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file10 << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                withdrawals_file10 << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
                withdrawals_file10.close();
                    //close file after writing process
            }//client10 withdraw info
                    //-----------------file writing-------------------------
        }
        else if(withdrwl_optn == 2)
        {
            cout << "\n\n\t   --------------------------------------------------------\n\n";
            cout << "\n\t      Reloading withdrawal section \n\n\t\t   ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
            }
            withdrawal_prmpt();
                    //recalls fn for making changes
        }
        else
        {
            cout<<"\n\t         -----------------------------\n\n\t             ERROR!\n\t                   -Undefined option.\n\t                   -Please enter appropriate choice\n\t                    as guided above and try again.\n\n\t                    System waiting...\n\n\t\t              : ";
            cin>>choice;
                //operation actn dfn
            cout<<"\n\t             -----------------------------\n\n";
            withdrawal_cnfrm(choice);
                //recalls the fn
        }   //exception error handler
    }
    void Make_Withdrawal()
    {
        cout << "\n\n\t   1.B.3: WITHDRAW AMONUT\n\t   --------------------------------------------------------\n";
        cout << "\n\t   Fill ALL the fields as required below to complete the transaction process.";
        cout << "\n\n\t    3.1. CLIENT CREDENTTIALS: \n";
        submit_fn();
                //submitting fn
        if(accs_no == 1)
        {
            cout << "\n" <<setw(21)<<"3.1.1. "<<setw(6)<<"Account Number: ";
            cin >> client_acc_no;
            cout << "\n" <<setw(21)<<"3.1.2. "<<setw(6)<<"ID Number: ";
            cin >> id_no;
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount to withdraw: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer1_acc_no = client_acc_no;
            customer1_id_no = id_no;
            customer1_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 1 WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"---------------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer1_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer1_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }       //client1 withdraw info
        else if(accs_no == 2)
        {
            cout << "\n" <<setw(21)<<"3.1.1. "<<setw(6)<<"Account Number: ";
            cin >> client_acc_no;
            cout << "\n" <<setw(21)<<"3.1.2. "<<setw(6)<<"ID Number: ";
            cin >> id_no;
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount to withdraw: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer2_acc_no = client_acc_no;
            customer2_id_no = id_no;
            customer2_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 2 WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"---------------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer2_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer2_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }       //client2 withdraw info
        else if(accs_no == 3)
        {
            cout << "\n" <<setw(21)<<"3.1.1. "<<setw(6)<<"Account Number: ";
            cin >> client_acc_no;
            cout << "\n" <<setw(21)<<"3.1.2. "<<setw(6)<<"ID Number: ";
            cin >> id_no;
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount to withdraw: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer3_acc_no = client_acc_no;
            customer3_id_no = id_no;
            customer3_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 3 WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"---------------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer3_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer3_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                //confirmation option
        }       //client3 withdraw info
        else if(accs_no == 4)
        {
            cout << "\n" <<setw(21)<<"3.1.1. "<<setw(6)<<"Account Number: ";
            cin >> client_acc_no;
            cout << "\n" <<setw(21)<<"3.1.2. "<<setw(6)<<"ID Number: ";
            cin >> id_no;
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount to withdraw: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer4_acc_no = client_acc_no;
            customer4_id_no = id_no;
            customer4_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 4 WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"---------------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer4_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer4_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }       //client4 withdraw info
        else if(accs_no == 5)
        {
            cout << "\n" <<setw(21)<<"3.1.1. "<<setw(6)<<"Account Number: ";
            cin >> client_acc_no;
            cout << "\n" <<setw(21)<<"3.1.2. "<<setw(6)<<"ID Number: ";
            cin >> id_no;
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount to withdraw: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer5_acc_no = client_acc_no;
            customer5_id_no = id_no;
            customer5_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 5 WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"---------------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer5_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer5_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }       //client5 withdraw info
        else if(accs_no == 6)
        {
            cout << "\n" <<setw(21)<<"3.1.1. "<<setw(6)<<"Account Number: ";
            cin >> client_acc_no;
            cout << "\n" <<setw(21)<<"3.1.2. "<<setw(6)<<"ID Number: ";
            cin >> id_no;
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount to withdraw: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer6_acc_no = client_acc_no;
            customer6_id_no = id_no;
            customer6_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 6 WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"---------------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer6_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer6_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }       //client6 withdraw info
        else if(accs_no == 7)
        {
            cout << "\n" <<setw(21)<<"3.1.1. "<<setw(6)<<"Account Number: ";
            cin >> client_acc_no;
            cout << "\n" <<setw(21)<<"3.1.2. "<<setw(6)<<"ID Number: ";
            cin >> id_no;
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount to withdraw: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer7_acc_no = client_acc_no;
            customer7_id_no = id_no;
            customer7_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 7 WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"---------------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer7_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer7_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }       //client7 withdraw info
        else if(accs_no == 8)
        {
            cout << "\n" <<setw(21)<<"3.1.1. "<<setw(6)<<"Account Number: ";
            cin >> client_acc_no;
            cout << "\n" <<setw(21)<<"3.1.2. "<<setw(6)<<"ID Number: ";
            cin >> id_no;
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount to withdraw: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer8_acc_no = client_acc_no;
            customer8_id_no = id_no;
            customer8_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 8 WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"---------------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer8_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer8_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }       //client8 withdraw info
        else if(accs_no == 9)
        {
            cout << "\n" <<setw(21)<<"3.1.1. "<<setw(6)<<"Account Number: ";
            cin >> client_acc_no;
            cout << "\n" <<setw(21)<<"3.1.2. "<<setw(6)<<"ID Number: ";
            cin >> id_no;
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount to withdraw: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer9_acc_no = client_acc_no;
            customer9_id_no = id_no;
            customer9_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 9 WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"---------------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer9_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer9_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }       //client9 withdraw info
        else if(accs_no == 10)
        {
            cout << "\n" <<setw(21)<<"3.1.1. "<<setw(6)<<"Account Number: ";
            cin >> client_acc_no;
            cout << "\n" <<setw(21)<<"3.1.2. "<<setw(6)<<"ID Number: ";
            cin >> id_no;
            cout << "\n" <<setw(21)<<"3.1.3. "<<setw(6)<<"Amount to withdraw: ";
            cin >> amnt_wthdrw;
                    //client withdraw amount
            customer10_acc_no = client_acc_no;
            customer10_id_no = id_no;
            customer10_blnc_info = amnt_wthdrw;
                    //set client withdraw info
            optmzr_1_sec_t();
            cout << "\n\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"       CLIENT 10 WITHDRAWAL INFORMATION SUMMARY";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"---------------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  CLIENT DETAILS"<<setw(8)<<"       |    "<<setw(8)<<"SUBMITTED INPUT"<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  1.    CLIENT NAME:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  2.    ACC. NUMBER:"<<setw(8)<<"|    "<<setw(8)<<client_acc_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  3.    ID. NUMBER:"<<setw(8)<<"    |    "<<setw(8)<<customer10_id_no<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(10)<<"  4.    AMOUNT:"<<setw(8)<<"        |    "<<setw(8)<<customer10_blnc_info<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            optmzr_hlf_sec_t();
                    //withdrawal summary info
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"  Confirm your amount and proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    Use 1 or 2 to make confirmation.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    1.  Proceed.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"    2.  Re-edit amount.";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"        Your choice: ";
            cin >> choice;
            cout << "\n  " <<setw(16)<<"|   "<<setw(6)<<"";
            cout << "\n  " <<setw(16)<<"|   "<<setw(0)<<"-------------------------------------------------";
                    //confirmation option
        }       //client10 withdraw info
        optmzr_2_sec_t();
        withdrawal_cnfrm(choice);
    }
                //withdrawals fn
    void Bank_sttmnt(int sttmnt_optn)
    {
        if(sttmnt_optn == 1)
        {
            cout << "\n\n\t      1.B.4.1: Mini-statement\n\t       --------------------------------------------------------\n";
            cout << "\n\n\t            ->Generating mini-statement for account no.: "<<customer1_acc_no<<"\n\n\t\t              ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
                if(x==2)
                {
                    cout << "\n\n\t            ->Statement file generation success!";
                    optmzr_3_sec_t();
                    cout << "\n\n\t   ";
                    for(int z=0; z<long_oprtns_tmr; z++)
                    {
                        cout <<"- ";
                        Sleep(100);
                    }
                    cout << "\n\n\t";
                    optmzr_1_sec_t;
                    system("CLS");
                    main_oprtn();
                }
            }
        }   //mini-statement generator fn
        else if(sttmnt_optn == 2)
        {
            cout << "\n\n\t      1.B.4.2: Comprehensive Statement\n\t      --------------------------------------------------------\n";
            cout << "\n\n\t            ->Generating comprehensive statement for account no.: "<<customer1_acc_no<<"\n\n\t\t              ";
            optmzr_1_sec_t();
            for(int x=0; x<3; x++)
            {
                long_oprtns_optmzr_tmr();
                    //operation tmr
                cout <<". ";
                optmzr_1_sec_t();
                if(x==2)
                {
                    cout << "\n\n\t            ->Statement file generation success! ";
                    optmzr_3_sec_t();
                    cout << "\n\n\t   ";
                    for(int z=0; z<long_oprtns_tmr; z++)
                    {
                        cout <<"- ";
                        Sleep(100);
                    }
                    cout << "\n\n\t";
                    optmzr_1_sec_t;
                    system("CLS");
                    main_oprtn();
                }
            }
        }   //comprehensive statement generator fn
        else
        {
            cout<<"\n\t         -----------------------------\n\n\t             ERROR!\n\t                   -Undefined option.\n\t                   -Please enter appropriate choice\n\t                    as guided above and try again.\n\n\t                    System waiting...\n\n\t\t              : ";
            cin>>choice;
                //operation actn dfn
            cout<<"\n\t             -----------------------------\n\n";
            Bank_sttmnt(choice);
                //pass elements by value
        }   //exception error handler
    }
    void Check_statement()
    {
        cout << "\n\n\t   1.B.4: BANK ACCOUNT STATEMENTS\n\t   --------------------------------------------------------\n";
        cout << "\n\t   Fill ALL the fields as required below to complete the request.";
        cout << "\n\n\t    4.1. CLIENT CREDENTTIALS: \n";
        cout << "\n" <<setw(21)<<"4.1.1. "<<setw(6)<<"Account Number: ";
        cin >> client_acc_no;
        cout << "\n" <<setw(21)<<"4.1.2. "<<setw(6)<<"ID Number: ";
        cin >> id_no;
        cout << "\n" <<setw(21)<<"4.1.3. "<<setw(6)<<"Select statement type(use 1 or 2): \n";
        cout << "\n" <<setw(21)<<"1. "<<setw(6)<<"Mini-statement. \n";
        cout << "\n" <<setw(21)<<"2. "<<setw(6)<<"Comprehensive statement. \n";
        cout << "\n" <<setw(21)<<"   "<<setw(6)<<"Enter your choice: ";
        cin >> sttmnt_type;
                //client statement prompt
        customer1_acc_no = client_acc_no;
        customer1_id_no = id_no;
                //get client info
        Bank_sttmnt(sttmnt_type);
                //calls statement generation fn
    }      //statement generation fn
    void banking_info()
    {
        optmzr_1_sec_t();
        cout << "\n\n\t   1.B.5: BUSINESS INFORMATION\n\t   --------------------------------------------------------\n";
        cout << "\n  " <<setw(12)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(12)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(12)<<"|   "<<setw(6)<<"-Thank you for making US your first priority";
        cout << "\n  " <<setw(12)<<"|   "<<setw(6)<<"-We are here to to serve you  and grow with you in every step of your journey";
        cout << "\n  " <<setw(12)<<"|   "<<setw(6)<<"-ALL flexible, affordable and efficient banking packages are avaiable";
        cout << "\n  " <<setw(12)<<"|   "<<setw(6)<<"";
        optmzr_hlf_sec_t();
        cout << "\n  " <<setw(12)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(12)<<"|   "<<setw(6)<<"-For more information reach us our site through: www.smartbanksyst.com";
        cout << "\n  " <<setw(12)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(12)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(12)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(12)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(12)<<"|   "<<setw(6)<<"  **********************snmart banking system************************";
        cout << "\n  " <<setw(12)<<"|   "<<setw(6)<<"";
        cout << "\n  " <<setw(12)<<"|   "<<setw(6)<<"";
        cout << "\n\n\t   --------------------------------------------------------\n";
    }   //banking info sctn fn
    void operation_fn(int actn_choice)
    {
        auth_acc_fl();
                    //calls accs auth fn
        if(actn_choice == 1)
        {
            if(accs_no == 0)
            {
                client1_acc_crtn(0);
            }
            else if(accs_no == 1)
            {
                client2_acc_crtn(0);
            }
            else if(accs_no == 2)
            {
                client3_acc_crtn(0);
            }
            else if(accs_no == 3)
            {
                client4_acc_crtn(0);
            }
            else if(accs_no == 4)
            {
                client5_acc_crtn(0);
            }
            else if(accs_no == 5)
            {
                client6_acc_crtn(0);
            }
            else if(accs_no == 6)
            {
                client7_acc_crtn(0);
            }
            else if(accs_no == 7)
            {
                client8_acc_crtn(0);
            }
            else if(accs_no == 8)
            {
                client9_acc_crtn(0);
            }
            else if(accs_no == 9)
            {
                client10_acc_crtn(0);
            }
        }

        else if(actn_choice == 2)
        {
            Make_Deposit();
        }
        else if(actn_choice == 3)
        {
            Make_Withdrawal();
        }
        else if(actn_choice == 4)
        {
            Check_statement();
        }
        else if(actn_choice == 5)
        {
            banking_info();
        }else
        {
            cout<<"\n\t-----------------------------\n\n\t   ERROR!\n\t      -Undefined option.\n\t      -Please enter appropriate choice\n\t       as guided above and try again.\n\n\t       System waiting...\n\n\t\t: ";
            cin>>choice;
                //operation actn dfn
            cout<<"\n\t-----------------------------\n\n";
            system("CLS");
                //clears console
            operation_fn(choice);
                //recalss operation fn
        }//exception error handling
    }   //operations redirector fn
    void initializer_fn()
    {
        main_oprtn();
        loading_fn();
        cout << "\n\t-------------------------------------------------------------------------------------\n\t1.A. GUIDE SECTION\n\t-------------------------------------------------------------------------------------\n\t";
        optmzr_hlf_sec_t();
        cout << "\n\tGUIDE:\n\t-------\n";
        cout << "\n" <<setw(12)<<"1. "<<setw(6)<<"Create Account.\n";
        cout << "\t   -Here, the user will be allowed to create new account by submitting\n\t    his/her credentials.\n";
        cout << "\n" <<setw(12)<<"2. "<<setw(6)<<"Make Deposits.\n";
        cout << "\t   -This section allows the user to deposit amounts to an existing registered\n\t    account using the account number.\n";
        cout << "\n\t ";
        optmzr_hlf_sec_t();
        cout << "\n" <<setw(12)<<"3. "<<setw(6)<<"Make Withdrawals.\n";
        cout << "\t   -Under this, the user is allowed to make withdrawals from an existing registered\n\t    account using the account number.\n";
        cout << "\n" <<setw(12)<<"4. "<<setw(6)<<"Check Statements.\n";
        cout << "\t   -Here, both mini and  overall client's bank account statements can be generated\n\t    depicting account operatons.\n";
        cout << "\n\t ";
        optmzr_hlf_sec_t();
        cout << "\n" <<setw(12)<<"5. "<<setw(6)<<"Learn More.\n";
        cout << "\t   -This section provides banking and business information essential to clients and\n\t    entrepreneurs in various diversified fields.\n";
        cout << "\n\t   -Select your action using the number label\n\t    e.g '2' to make deposits\n\n\t-------------------------------------------------------------------------------------\n\n\t";
        cout << "\n\n\t-------------------------------------------------------------------------------------\n\t1.B. ACTIONS SECTION\n\t-------------------------------------------------------------------------------------\n\t";
                //short use guide info
        optmzr_1_hlf_sec_t();
        cout << "\n\t   1. Enter your choice \n\n\t\t\t: ";
        cin >> oprtn_actn;
                //operation user entry choice
        operation_fn(oprtn_actn);
                //calls operation fn
    }   //operations initializer  fn
int main()
{
    auth_acc_fl();
    optmzr_hlf_sec_t();
    acc_auto_compltn();
        //xternal fn to regenerate acc. credentials
    //srand((unsigned)time(0));
        //Accounts acc;
    oprtn_prompt= "y";
    optmr_flag = 1;
    accs_no = acc_cntr;
    while((oprtn_prompt=="y") || (oprtn_prompt=="Y"))
    {
        optmr_flag = 1;
            //sets operation flag up
        initializer_fn();
        cout<<"\n\n\t   Perform other operations?(y/n)\n\n\t\t: ";
        cin>>oprtn_prompt;
            //operations prompt
        system("CLS");
            //clears console
    }
    customer1_blnc_info = 10;
    return 0;
}


