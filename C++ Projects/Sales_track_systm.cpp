

/*

##=============================================================
#				              
#	Author: ochieno eliud	                          
#	University of Nairobi			  
#	Dept: Elec. $ Info. Eng.		  
#					  
#==============================================================

            -------------------------SALES TRACK SYSTEM C++ PROGRAM-----------------------
*/

#include <iostream>
#include<vector>
#include <iomanip>

using namespace std;

    string sales_prsn1_id, sales_prsn2_id, sales_prsn3_id, sales_prsn4_id, sales_prsn5_id;
    int salesman1_qitem1, salesman1_qitem2, salesman1_qitem3, salesman1_qitem4, salesman1_qitem5, salesman1_qitem6, salesman1_qitem7, salesman1_qitem8, salesman1_qitem9, salesman1_qitem10;
    int salesman2_qitem1, salesman2_qitem2, salesman2_qitem3, salesman2_qitem4, salesman2_qitem5, salesman2_qitem6, salesman2_qitem7, salesman2_qitem8, salesman2_qitem9, salesman2_qitem10;
    int salesman3_qitem1, salesman3_qitem2, salesman3_qitem3, salesman3_qitem4, salesman3_qitem5, salesman3_qitem6, salesman3_qitem7, salesman3_qitem8, salesman3_qitem9, salesman3_qitem10;
    int salesman4_qitem1, salesman4_qitem2, salesman4_qitem3, salesman4_qitem4, salesman4_qitem5, salesman4_qitem6, salesman4_qitem7, salesman4_qitem8, salesman4_qitem9, salesman4_qitem10;
    int salesman5_qitem1, salesman5_qitem2, salesman5_qitem3, salesman5_qitem4, salesman5_qitem5, salesman5_qitem6, salesman5_qitem7, salesman5_qitem8, salesman5_qitem9, salesman5_qitem10;
    int prsn1_sales, prsn2_sales, prsn3_sales, prsn4_sales, prsn5_sales;
    int q_item1_grnd_ttl, q_item2_grnd_ttl, q_item3_grnd_ttl, q_item4_grnd_ttl, q_item5_grnd_ttl, q_item6_grnd_ttl, q_item7_grnd_ttl, q_item8_grnd_ttl, q_item9_grnd_ttl, q_item10_grnd_ttl;
    int numOfSalesPrsn, numOfSalesItms;
    int grnd_ttl_sales;
    q_item1_fn()
    {
        if(numOfSalesItms <= 10)
        {
            int products[numOfSalesItms];
            for(int y=0; y<numOfSalesItms; y++)
            {
                if(y==0)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman1_qitem1;
                }
                else if(y==1)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman1_qitem2;
                }
                else if(y==2)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman1_qitem3;
                }
                else if(y==3)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman1_qitem4;
                }
                else if(y==4)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman1_qitem5;
                }
                else if(y==5)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman1_qitem6;
                }
                else if(y==6)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman1_qitem7;
                }
                else if(y==7)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman1_qitem8;
                }
                else if(y==8)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman1_qitem9;
                }
                else if(y==9)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman1_qitem10;
                }
            }

        }
        else if(numOfSalesItms > 10)
        {
            cout << "\n\n\tError!\n\t  -Maximum number of items expected is 10.";
            cout << "\n\t   Please re-enter and try again.\n";
            cout << "\n\t   B. Number of items sold: ";
            cin >> numOfSalesItms;
                        //user dfns
            q_item1_fn();
        }
        cout<<"\n\n\t---------------------------------------\n";
    }

    q_item2_fn()
    {
        if(numOfSalesItms <= 10)
        {
            int products[numOfSalesItms];
            for(int y=0; y<numOfSalesItms; y++)
            {
                if(y==0)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman2_qitem1;
                }
                else if(y==1)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman2_qitem2;
                }
                else if(y==2)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman2_qitem3;
                }
                else if(y==3)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman2_qitem4;
                }
                else if(y==4)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman2_qitem5;
                }
                else if(y==5)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman2_qitem6;
                }
                else if(y==6)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman2_qitem7;
                }
                else if(y==7)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman2_qitem8;
                }
                else if(y==8)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman2_qitem9;
                }
                else if(y==9)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman2_qitem10;
                }
            }

        }
        else if(numOfSalesItms > 10)
        {
            cout << "\n\n\tError!\n\t  -Maximum number of items expected is 10.";
            cout << "\n\t   Please re-enter and try again.\n";
            cout << "\n\t   B. Number of items sold: ";
            cin >> numOfSalesItms;
                        //user dfns
            q_item2_fn();
        }
        cout<<"\n\n\t---------------------------------------\n";
    }

    q_item3_fn()
    {
        if(numOfSalesItms <= 10)
        {
            int products[numOfSalesItms];
            for(int y=0; y<numOfSalesItms; y++)
            {
                if(y==0)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman3_qitem1;
                }
                else if(y==1)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman3_qitem2;
                }
                else if(y==2)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman3_qitem3;
                }
                else if(y==3)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman3_qitem4;
                }
                else if(y==4)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman3_qitem5;
                }
                else if(y==5)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman3_qitem6;
                }
                else if(y==6)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman3_qitem7;
                }
                else if(y==7)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman3_qitem8;
                }
                else if(y==8)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman3_qitem9;
                }
                else if(y==9)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman3_qitem10;
                }
            }

        }
        else if(numOfSalesItms > 10)
        {
            cout << "\n\n\tError!\n\t  -Maximum number of items expected is 10.";
            cout << "\n\t   Please re-enter and try again.\n";
            cout << "\n\t   B. Number of items sold: ";
            cin >> numOfSalesItms;
                        //user dfns
            q_item3_fn();
        }
        cout<<"\n\n\t---------------------------------------\n";
    }

    q_item4_fn()
    {
        if(numOfSalesItms <= 10)
        {
            int products[numOfSalesItms];
            for(int y=0; y<numOfSalesItms; y++)
            {
                if(y==0)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman4_qitem1;
                }
                else if(y==1)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman4_qitem2;
                }
                else if(y==2)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman4_qitem3;
                }
                else if(y==3)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman4_qitem4;
                }
                else if(y==4)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman4_qitem5;
                }
                else if(y==5)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman4_qitem6;
                }
                else if(y==6)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman4_qitem7;
                }
                else if(y==7)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman4_qitem8;
                }
                else if(y==8)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman4_qitem9;
                }
                else if(y==9)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman4_qitem10;
                }
            }

        }
        else if(numOfSalesItms > 10)
        {
            cout << "\n\n\tError!\n\t  -Maximum number of items expected is 10.";
            cout << "\n\t   Please re-enter and try again.\n";
            cout << "\n\t   B. Number of items sold: ";
            cin >> numOfSalesItms;
                        //user dfns
            q_item4_fn();
        }
        cout<<"\n\n\t---------------------------------------\n";
    }

    q_item5_fn()
    {
        if(numOfSalesItms <= 10)
        {
            int products[numOfSalesItms];
            for(int y=0; y<numOfSalesItms; y++)
            {
                if(y==0)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman5_qitem1;
                }
                else if(y==1)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman5_qitem2;
                }
                else if(y==2)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman5_qitem3;
                }
                else if(y==3)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman5_qitem4;
                }
                else if(y==4)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman5_qitem5;
                }
                else if(y==5)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman5_qitem6;
                }
                else if(y==6)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman5_qitem7;
                }
                else if(y==7)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman5_qitem8;
                }
                else if(y==8)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman5_qitem9;
                }
                else if(y==9)
                {
                    cout << "\n\t  "<<y+1<<".ITEM"<<y+1<<": ";
                    cin >> salesman5_qitem10;
                }
            }

        }
        else if(numOfSalesItms > 10)
        {
            cout << "\n\n\tError!\n\t  -Maximum number of items expected is 10.";
            cout << "\n\t   Please re-enter and try again.\n";
            cout << "\n\t   B. Number of items sold: ";
            cin >> numOfSalesItms;
                        //user dfns
            q_item5_fn();
        }
        cout<<"\n\n\t---------------------------------------\n";
    }


int main()
{
    cout << "\n\n  ==========================================================\t\n       PROGRAM TO TRACK COMPANY SALES\n  ==========================================================" << endl;
    cout << "\n\nEnter number of: \n\n\t  1. Salesmen: ";
    cin >> numOfSalesPrsn;
    int salesmen[numOfSalesPrsn];
                //user dfned array size
    cout << "\n\n\tEnter sales person name and the items sold by number.\n\te.g\n\t  NAME: Derrick\n\t  1.ITEM1: 5\n\t  2.ITEM1: 6 etc\n\n\t--------------------------------\n";
    for(int x=0; x<numOfSalesPrsn; x++)
    {
        if(x==0)
        {
            cout << "\n\t "<<x+1<<". Salesman "<<x+1<<"\n\n\t  A. NAME: ";
            cin >> sales_prsn1_id;
            cout << "\n\t  B. Number of items sold: ";
            cin >> numOfSalesItms;
                        //user dfns
            q_item1_fn();
                    //item qtty  dfn fctn
            prsn1_sales = (salesman1_qitem1 + salesman1_qitem2 + salesman1_qitem3 + salesman1_qitem4 + salesman1_qitem5 + salesman1_qitem6 + salesman1_qitem7 + salesman1_qitem8 + salesman1_qitem9 + salesman1_qitem10);
                    //computes sales
        }
        else if(x==1)
        {
            cout << "\n\t "<<x+1<<". Salesman "<<x+1<<"\n\n\t  NAME: ";
            cin >> sales_prsn2_id;
            cout << "\n\t  B. Number of items sold: ";
            cin >> numOfSalesItms;
                        //user dfns
            q_item2_fn();
                    //item qtty  dfn fctn
            prsn2_sales = (salesman2_qitem1 + salesman2_qitem2 + salesman2_qitem3 + salesman2_qitem4 + salesman2_qitem5 + salesman2_qitem6 + salesman2_qitem7 + salesman2_qitem8 + salesman2_qitem9 + salesman2_qitem10);
                    //computes sales
        }
        else if(x==2)
        {
            cout << "\n\t "<<x+1<<". Salesman "<<x+1<<"\n\n\t  NAME: ";
            cin >> sales_prsn3_id;
            cout << "\n\t  B. Number of items sold: ";
            cin >> numOfSalesItms;
                        //user dfns
            q_item3_fn();
                    //item qtty  dfn fctn
            prsn3_sales = (salesman3_qitem1 + salesman3_qitem2 + salesman3_qitem3 + salesman3_qitem4 + salesman3_qitem5 + salesman3_qitem6 + salesman3_qitem7 + salesman3_qitem8 + salesman3_qitem9 + salesman3_qitem10);
                    //computes sales
        }
        else if(x==3)
        {
            cout << "\n\t "<<x+1<<". Salesman "<<x+1<<"\n\n\t  NAME: ";
            cin >> sales_prsn4_id;
            cout << "\n\t  B. Number of items sold: ";
            cin >> numOfSalesItms;
                        //user dfns
            q_item4_fn();
                    //item qtty  dfn fctn
            prsn4_sales = (salesman4_qitem1 + salesman4_qitem2 + salesman4_qitem3 + salesman4_qitem4 + salesman4_qitem5 + salesman4_qitem6 + salesman4_qitem7 + salesman4_qitem8 + salesman4_qitem9 + salesman4_qitem10);
                    //computes sales
        }
        else if(x==4)
        {
            cout << "\n\t "<<x+1<<". Salesman "<<x+1<<"\n\n\t  NAME: ";
            cin >> sales_prsn5_id;
            cout << "\n\t  B. Number of items sold: ";
            cin >> numOfSalesItms;
                        //user dfns
            q_item5_fn();
                    //item qtty  dfn fctn
            prsn5_sales = (salesman5_qitem1 + salesman5_qitem2 + salesman5_qitem3 + salesman5_qitem4 + salesman5_qitem5 + salesman5_qitem6 + salesman5_qitem7 + salesman5_qitem8 + salesman5_qitem9 + salesman5_qitem10);
                    //computes sales
                    //----------------items grand total computation------------------------
            grnd_ttl_sales = (prsn1_sales + prsn2_sales + prsn3_sales + prsn4_sales + prsn5_sales);
                    //computes sales grand ttl
            q_item1_grnd_ttl = (salesman1_qitem1 + salesman2_qitem1 + salesman3_qitem1 + salesman4_qitem1 + salesman5_qitem1);
                    //computes item1 grand ttl
            q_item2_grnd_ttl = (salesman1_qitem2 + salesman2_qitem2 + salesman3_qitem2 + salesman4_qitem2 + salesman5_qitem2);
                    //computes item2 grand ttl
            q_item3_grnd_ttl = (salesman1_qitem3 + salesman2_qitem3 + salesman3_qitem3 + salesman4_qitem3 + salesman5_qitem3);
                    //computes item3 grand ttl
            q_item4_grnd_ttl = (salesman1_qitem4 + salesman2_qitem4 + salesman3_qitem4 + salesman4_qitem4 + salesman5_qitem4);
                    //computes item4 grand ttl
            q_item5_grnd_ttl = (salesman1_qitem5 + salesman2_qitem5 + salesman3_qitem5 + salesman4_qitem5 + salesman5_qitem5);
                    //computes item5 grand ttl
            q_item6_grnd_ttl = (salesman1_qitem6 + salesman2_qitem6 + salesman3_qitem6 + salesman4_qitem6 + salesman5_qitem6);
                    //computes item6 grand ttl
            q_item7_grnd_ttl = (salesman1_qitem7 + salesman2_qitem7 + salesman3_qitem7 + salesman4_qitem7 + salesman5_qitem7);
                    //computes item7 grand ttl
            q_item8_grnd_ttl = (salesman1_qitem8 + salesman2_qitem8 + salesman3_qitem8 + salesman4_qitem8 + salesman5_qitem8);
                    //computes item8 grand ttl
            q_item9_grnd_ttl = (salesman1_qitem9 + salesman2_qitem9 + salesman3_qitem9 + salesman4_qitem9 + salesman5_qitem9);
                    //computes item9 grand ttl
            q_item10_grnd_ttl = (salesman1_qitem10 + salesman2_qitem10 + salesman3_qitem10 + salesman4_qitem10 + salesman5_qitem10);
                    //computes item10 grand ttl
                    //------------------items grand totals---------------------------
            cout << "\n\n" <<setw(17)<<"NAME"<<setw(8)<<"ITEM1"<<setw(8)<<"ITEM2"<<setw(8)<<"ITEM3"<<setw(8)<<"ITEM4"<<setw(8)<<"ITEM5"<<setw(8)<<"ITEM6"<<setw(8)<<"ITEM7"<<setw(8)<<"ITEM8"<<setw(8)<<"ITEM9"<<setw(8)<<"ITEM10"<<setw(8)<<"TOTAL SALES"<<endl;
            cout <<setw(17)<<"  ------"<<setw(7)<<"  ------"<<setw(7)<<"  ------"<<setw(7)<<"  ------"<<setw(7)<<"  ------"<<setw(7)<<"  ------"<<setw(7)<<"  ------"<<setw(7)<<"  ------"<<setw(7)<<"  ------"<<setw(7)<<"  ------"<<setw(7)<<"  -----------------------"<<endl;
            cout << "\n" <<setw(17)<<sales_prsn1_id<<setw(6)<<salesman1_qitem1<<setw(8)<<salesman1_qitem2<<setw(8)<<salesman1_qitem3<<setw(8)<<salesman1_qitem4<<setw(8)<<salesman1_qitem5<<setw(8)<<salesman1_qitem6<<setw(8)<<salesman1_qitem7<<setw(8)<<salesman1_qitem8<<setw(8)<<salesman1_qitem9<<setw(8)<<salesman1_qitem10<<setw(8)<<prsn1_sales<<endl;
            cout << "\n" <<setw(17)<<sales_prsn2_id<<setw(6)<<salesman2_qitem1<<setw(8)<<salesman2_qitem2<<setw(8)<<salesman2_qitem3<<setw(8)<<salesman2_qitem4<<setw(8)<<salesman2_qitem5<<setw(8)<<salesman2_qitem6<<setw(8)<<salesman2_qitem7<<setw(8)<<salesman2_qitem8<<setw(8)<<salesman2_qitem9<<setw(8)<<salesman2_qitem10<<setw(8)<<prsn2_sales<<endl;
            cout << "\n" <<setw(17)<<sales_prsn3_id<<setw(6)<<salesman3_qitem1<<setw(8)<<salesman3_qitem2<<setw(8)<<salesman3_qitem3<<setw(8)<<salesman3_qitem4<<setw(8)<<salesman3_qitem5<<setw(8)<<salesman3_qitem6<<setw(8)<<salesman3_qitem7<<setw(8)<<salesman3_qitem8<<setw(8)<<salesman3_qitem9<<setw(8)<<salesman3_qitem10<<setw(8)<<prsn3_sales<<endl;
            cout << "\n" <<setw(17)<<sales_prsn4_id<<setw(6)<<salesman4_qitem1<<setw(8)<<salesman4_qitem2<<setw(8)<<salesman4_qitem3<<setw(8)<<salesman4_qitem4<<setw(8)<<salesman4_qitem5<<setw(8)<<salesman4_qitem6<<setw(8)<<salesman4_qitem7<<setw(8)<<salesman4_qitem8<<setw(8)<<salesman4_qitem9<<setw(8)<<salesman4_qitem10<<setw(8)<<prsn4_sales<<endl;
            cout << "\n" <<setw(17)<<sales_prsn5_id<<setw(6)<<salesman5_qitem1<<setw(8)<<salesman5_qitem2<<setw(8)<<salesman5_qitem3<<setw(8)<<salesman5_qitem4<<setw(8)<<salesman5_qitem5<<setw(8)<<salesman5_qitem6<<setw(8)<<salesman5_qitem7<<setw(8)<<salesman5_qitem8<<setw(8)<<salesman5_qitem9<<setw(8)<<salesman5_qitem10<<setw(8)<<prsn5_sales<<endl;
                    //grand totals
            cout << "      -------------------------------------------------------------------------------------------------------------\n";
            cout << "\n" <<setw(17)<<"Grand Totals"<<setw(6)<<q_item1_grnd_ttl<<setw(8)<<q_item2_grnd_ttl<<setw(8)<<q_item3_grnd_ttl<<setw(8)<<q_item4_grnd_ttl<<setw(8)<<q_item5_grnd_ttl<<setw(8)<<q_item6_grnd_ttl<<setw(8)<<q_item7_grnd_ttl<<setw(8)<<q_item8_grnd_ttl<<setw(8)<<q_item9_grnd_ttl<<setw(8)<<q_item10_grnd_ttl<<setw(8)<<grnd_ttl_sales<<endl;
            cout << "\n      -------------------------------------------------------------------------------------------------------------\n";
                    //PRINTS IN LIST FORM
        }
    }
    return 0;
}
