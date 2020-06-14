
/*
            -------------------------GUESS GAME C++ PROGRAM-----------------------
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

    int randm_no, range_span, min_rang_val, level, score_cntr, max_range_val, guess_val;
    int init_rand_no, new_rand_no;
    string quit_check;
            //vars dfned as global
    int randm_no_gnrtr(int min_val, int span_val)
    {
        randm_no = min_val+int(span_val*rand()/(RAND_MAX + 1.0));
                //random no. initialization
        init_rand_no = randm_no;
    }
    querry_fn()
    {
        cout << "\n\tThe initial random number generated is: "<<init_rand_no<<"\n\n\t    --------------------------------------"<<endl;        cout << "\n\tWill the next number be higher or lower than this?\n";
        cout << "\n\tEnter your choice(use 1 or 2)\n";;
        cout << "\n"<<setw(15)<<"Choice"<<setw(17)<<"Value\n"<<setw(16)<<"  ---------"<<setw(18)<<"----------"<< endl;
        cout << "\n"<<setw(16)<<"Higher"<<setw(14)<<"1"<<endl;
        cout << "\n"<<setw(15)<<"Lower"<<setw(15)<<"2"<<endl;
        cout << "\n\t  Choice: ";
        cin >> guess_val;
                //user i/p for guess answer
    }
    operation_fn()
    {
        if(guess_val == 1)
        {
            randm_no = min_rang_val+int(range_span*rand()/(RAND_MAX + 1.0));
                    //random no. initialization
            new_rand_no = randm_no;
            if(new_rand_no > init_rand_no)
            {
                cout << "\n\n\t---------------------------\n";
                cout << "\n\t  CORRECT!\n";
                cout << "\n\t  Random number: "<<new_rand_no<<endl;
                cout << "\n\n\t---------------------------\n";
                randm_no_gnrtr(min_rang_val, range_span);
                        //call radom no. generator fn
                score_cntr ++;
                        //awards points counter
                level ++;
                        //levels
                querry_fn();
                        //call user prompt fn
                operation_fn();
                        //calls operation fn
            }
            else
            {
                cout << "\n\n\t---------------------------\n";
                cout << "\n\t  WRONG!";
                cout << "\n\t  Random number: "<<new_rand_no<<endl;
                cout << "\n\t  Score Results\n\t  -----------------------"<<endl;
                cout << "\n"<<setw(15)<<"Level(s)"<<setw(17)<<"Points\n"<<setw(16)<<" ---------"<<setw(18)<<"----------"<< endl;
                cout << "\n"<<setw(13)<<level<<setw(14)<<score_cntr<<endl;
                cout << "\n\t  Program exiting...\n\n";
                quit_check = "y";
            }
        }
        else if(guess_val == 2)
        {
            randm_no = min_rang_val+int(range_span*rand()/(RAND_MAX + 1.0));
                    //random no. initialization
            new_rand_no = randm_no;
            if(new_rand_no < init_rand_no)
            {
                cout << "\n\n\t---------------------------\n";
                cout << "\n\t  CORRECT!\n";
                cout << "\n\t  Random number: "<<new_rand_no<<endl;
                cout << "\n\n\t---------------------------\n";
                score_cntr ++;
                        //awards points counter
                level ++;
                        //levels
                randm_no_gnrtr(min_rang_val, range_span);
                        //call radom no. generator fn
                querry_fn();
                        //call user prompt fn
                operation_fn();
                        //calls operation fn
            }
            else
            {
                cout << "\n\n\t---------------------------\n";
                cout << "\n\t  WRONG!";
                cout << "\n\t  Random number: "<<new_rand_no<<endl;
                cout << "\n\t  Score Results\n\t  -----------------------"<<endl;
                cout << "\n"<<setw(15)<<"Level(s)"<<setw(17)<<"Points\n"<<setw(16)<<" ---------"<<setw(18)<<"----------"<< endl;
                cout << "\n"<<setw(13)<<level<<setw(14)<<score_cntr<<endl;
                cout << "\n\t  Program exiting...\n\n";
                quit_check = "y";
            }
        }
        else if(guess_val !=1 && guess_val !=2)
        {
            cout<<"\n   -----------------------------\n\n\t   ERROR!\n\t      -Undefined option.\n\t      -Please enter appropriate choice\n\t       as guided above and try again.\n\n\t       System waiting...\n\n\t\t: ";
            cin>>guess_val;
                //operation actn dfn
            cout<<"\n   -----------------------------\n\n";
            operation_fn();
                    //calls operation fn
        }//exception error handling
    }
    int main()
{
    cout << "\n\n  ==========================================================\t\n       PROGRAM SIMULATES A GUESSING GAME USING RAMDOM NUMBER\n  ==========================================================" << endl;
    cout << "\n\t------------INSTRUCTIONS-------------\n";
    cout << "\n\t -The game operates on a random number of scope 0-10";
    cout << "\n\t -User guess number should be within this range.";
    cout << "\n\n\t  GAME THEME:\n\t  --------------";
    cout << "\n\t   -User to guess whether the next random number\n\t    to be generated will be higher or lower than\n\t    his/her guess answer.\n\t   -If the guess is correct, a score of 1 mark\n\t    is awarded an the game continues.\n\t   -If the guess answer is wrong, the game ends\n\t    with 0 marks awarded.\n\n\t    --------------------------------------\n\n";
    srand((unsigned)time(0));
            //random no. operation fn

    min_rang_val = 1;
    max_range_val = 10;
            //random no. ranges
    range_span = ((max_range_val - min_rang_val) + 1);
            //random no. scope
    randm_no = min_rang_val+int(range_span*rand()/(RAND_MAX + 1.0));
            //random no. initialization
    quit_check="n";
            //quit program operator var
    score_cntr = 0;
            //initialize scores
    while(quit_check=="n")
    {
        randm_no_gnrtr(min_rang_val, range_span);
                //call radom no. generator fn
        querry_fn();
                //call user prompt fn
        operation_fn();
                //calls operation fn
    }
}
