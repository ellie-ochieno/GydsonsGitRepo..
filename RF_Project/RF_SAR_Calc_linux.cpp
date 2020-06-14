#include<iostream>
#include<math.h>
#include<cmath>
#include<ctime>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<fstream>
#include<string.h>
#include<bits/stdc++.h>
        //log library
//#include "windows.h"
#define avatar "RF-Activty"

/*
    ##  ---------RF Activity Project----------
    ##
    ##  Radio Frequency properties simple calculator program
    ##
    ##  **********author: Ochieno Eliud*********
*/

using namespace std;

        //------functions instantiation-----
float t_impedance(float rel_u, float rel_e);
float depth(float freq_val, float condvty_val);
float pwr_d(float Pwr_val);
float e_field(float t_er_val);
float sar_val(float condvty_val, float dnsty_val);
float pwr_trsmtd(float trans_pwr_val, float brn_sz);
float compute_tissue_rds(float head_circ);
void prog_init();
void oprtn_flow();
void compute_t_rads();
void prnt_tissue_rds_file(float head_sz_val);
void prnt_sar_file();

        //----constant vars-------
float pi = M_PI;
        // pi value
float eo = 8.854187*pow(10, -12);
        // Permittivity [F/m]
float uo = 4*pi*pow(10, -7);
        // Permeability [H/m]
float co = 3*pow(10, 8);
        // Speed of EM [m/s]
float no = 120*pi;
        // free space x-tic impedance


        // ------variables------
int range_span, min_rang_val, max_range_val, oprtn_actn, optmr_flag, max_tm, min_tm, shrt_oprtns_tmr, long_oprtns_tmr, confrm_flag;
int tissue_choice, analysis_actn, num_of_rds_vals;
string tissue_type, oprtn_prompt, anlyss_optn, print_prmpt;
float brain_sz, head_sz, head_sz1, head_sz2, head_sz3, head_sz4, head_sz5, head_sz6, head_sz7, skin_sz, bone_sz, fat_sz, head_rds, head_sz_val_trck;
float fc = 0;
float t_cndvty = 0;
float t_min_cndvty = 0;
float t_dnsty = 0;
float t_impdnc = 0;
float dpth = 0;
float Pt = 0;
float Gt = 1;    // antenna gain set to unity by default
float d = 0;
float da = 0;
float S = 0;
float E = 0;
float Sar = 0;
float er = 0;
float ur = 1;   
            // tissue relative Permeability set to unity by default
string powr_attntn_flag = "n";
            //operation flag for attenuation compututaion
float brn_pwr_attenuated;
float brn_pwr_rcvd1;
float brn_pwr_rcvd2;
            //brain power
float skin_tsse_pwr_attenuated, skin_tsse_pwr_rcvd1, skin_tsse_pwr_rcvd2;
            //brain power variables
float fat_tsse_pwr_attenuated, fat_tsse_pwr_rcvd1, fat_tsse_pwr_rcvd2;
            //brain power variables
float bone_tsse_pwr_attenuated, bone_tsse_pwr_rcvd1, bone_tsse_pwr_rcvd2;
            //brain power variables
float brain_tsse_pwr_attenuated, brain_tsse_pwr_rcvd1, brain_tsse_pwr_rcvd2;
            //brain power variables
float skin_tsse_thcknss,fat_tsse_thcknss,bone_tsse_thcknss, brain_tsse_thcknss;
            // tissues thickness

            //----global objects----
ofstream SAR_print_file;
            //SAR file object
ofstream tissue_rads_print_file;
            //tissue radius file object
            //----global objects----
void optmzr_t()
    {
        std::chrono::milliseconds timespan(250);
        std::this_thread::sleep_for(timespan);
        //Sleep(500); for windows
    }
void optmzr_hlf_sec_t()
    {
        std::chrono::milliseconds timespan(500);
        std::this_thread::sleep_for(timespan);
        //Sleep(500); for windows
    }
void optmzr_1_sec_t()
    {
        std::chrono::milliseconds timespan(1000);
        std::this_thread::sleep_for(timespan);
        //Sleep(500); for windows
    }
void optmzr_1_hlf_sec_t()
    {
        std::chrono::milliseconds timespan(1500);
        std::this_thread::sleep_for(timespan);
        //Sleep(1500); for windows
    }
void optmzr_2_sec_t()
    {
        std::chrono::milliseconds timespan(2000);
        std::this_thread::sleep_for(timespan);
        //Sleep(2000); for windows
    }
void optmzr_2_n_hlf_sec_t()
    {
        std::chrono::milliseconds timespan(2500);
        std::this_thread::sleep_for(timespan);
        //Sleep(2500); for windows
    }
void optmzr_3_sec_t()
    {
        std::chrono::milliseconds timespan(3000);
        std::this_thread::sleep_for(timespan);
        //Sleep(3000); for windows
    }
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
void loading_fn()
    {
        for(int z=0; z<3; z++)
        {
            int x;
            shrt_oprtns_optmzr_tmr();
                //operation tmr
            optmzr_t();
            if(z <= 1)
            {
                for(x=0; x<3; x++)
                {
                    cout <<". ";
                    std::chrono::milliseconds timespan(150);
                    std::this_thread::sleep_for(timespan);
                    //Sleep(150); for windows
                }
            }
            else if(z > 1)
            {
                for(x=0; x<shrt_oprtns_tmr-1; x++)
                {
                    cout <<". ";
                    std::chrono::milliseconds timespan(200);
                    std::this_thread::sleep_for(timespan);
                    //Sleep(200); for windows
                }
            }
        }
    }       //initialization operation auth fn
            //processes optimizer time fns
void prnt_tissue_rds_file(float head_sz_val){
        tissue_rads_print_file << "\n\n\n" <<setw(21)<<"    2.2.0. "<<setw(6)<<"Tissue Radius Properties";
        tissue_rads_print_file << "\n" <<setw(21)<<"           "<<setw(6)<<"------------------------------------------------\n";
        tissue_rads_print_file << "\n\n" <<setw(35)<<"    2.2.1. "<<setw(6)<<"Head size by circumference: "<<head_sz_val<<" [m]";
        tissue_rads_print_file << "\n\n" <<setw(35)<<"    2.2.2. "<<setw(6)<<"Skin radius: "<<skin_sz<<" [m]";
        tissue_rads_print_file << "\n\n" <<setw(36)<<"    2.2.3. "<<setw(6)<<"Fat radius: "<<fat_sz<<" [m]";
        tissue_rads_print_file << "\n\n" <<setw(36)<<"    2.2.4. "<<setw(6)<<"Bone radius: "<<bone_sz<<" [m]";
        tissue_rads_print_file << "\n\n" <<setw(36)<<"    2.2.5. "<<setw(6)<<"Brain radius: "<<brain_sz<<" [m]";
        tissue_rads_print_file << "\n\n\n" <<setw(21)<<"           "<<setw(6)<<"---------------------------------< "<<(avatar)<<" >-------------------------------\n\n";
}
void compute_t_rads(){
    oprtn_prompt= "y";
    while((oprtn_prompt=="y") || (oprtn_prompt=="Y"))
    {
        optmzr_t(); //flow optimizer fn
        cout << "\n" <<setw(23)<<"    1.0.0.2. "<<setw(6)<<"NOTE: \n";
        cout << "\n" <<setw(23)<<"   -> "<<setw(6)<<"The system allows you to compute up to 8 values in a cycle.";
        cout << "\n\n" <<setw(23)<<"   -> "<<setw(6)<<"Define the number of head size values(between 1-8).";
        optmzr_1_sec_t(); //flow optimizer fn
        cout << "\n\n" <<setw(24)<<"      "<<setw(6)<<"Number of values e.g 1 or 2 or 4 etc: ";
        cin >> num_of_rds_vals;
        if(num_of_rds_vals >= 1 && num_of_rds_vals <= 8){
            int x;
            for(x=0; x<num_of_rds_vals; x++){
                cout << "\n\n" <<setw(23)<<"      "<<setw(6)<<"Enter: ";
                optmzr_1_sec_t(); //flow optimizer fn
                if(num_of_rds_vals == 1){
                    cout << "\n\n" <<setw(24)<<"    "<<(x+1)<<". "<<setw(6)<<"Value in metres (m) e.g .43232123 : ";
                }
                else if(num_of_rds_vals > 1){
                    cout << "\n\n" <<setw(24)<<"    "<<(x+1)<<". "<<setw(6)<<"Value "<<(x+1)<<" in metres (m) e.g .43232123 : ";
                }
                if(x==0){
                    cin >> head_sz;
                    head_sz_val_trck = head_sz;
                    compute_tissue_rds(head_sz);
                        //calls tissue radius computation fn
                    head_sz_val_trck = head_sz;
                        // holds specific head size val
                }
                else if(x==1){
                    cin >> head_sz1;
                    compute_tissue_rds(head_sz1);
                        //calls tissue radius computation fn
                    head_sz_val_trck = head_sz1;
                        // holds specific head size val
                }
                else if(x==2){
                    cin >> head_sz2;
                    compute_tissue_rds(head_sz2);
                        //calls tissue radius computation fn
                    head_sz_val_trck = head_sz2;
                        // holds specific head size val
                }
                else if(x==3){
                    cin >> head_sz3;
                    compute_tissue_rds(head_sz3);
                        //calls tissue radius computation fn
                    head_sz_val_trck = head_sz3;
                        // holds specific head size val
                }
                else if(x==4){
                    cin >> head_sz4;
                    compute_tissue_rds(head_sz4);
                        //calls tissue radius computation fn
                    head_sz_val_trck = head_sz4;
                        // holds specific head size val
                }
                else if(x==5){
                    cin >> head_sz5;
                    compute_tissue_rds(head_sz5);
                        //calls tissue radius computation fn
                    head_sz_val_trck = head_sz5;
                        // holds specific head size val
                }
                else if(x==6){
                    cin >> head_sz6;
                    compute_tissue_rds(head_sz6);
                        //calls tissue radius computation fn
                    head_sz_val_trck = head_sz6;
                        // holds specific head size val
                }
                else if(x==7){
                    cin >> head_sz7;
                    compute_tissue_rds(head_sz7);
                        //calls tissue radius computation fn
                    head_sz_val_trck = head_sz7;
                        // holds specific head size val
                }
                        //head size dfn
                // compute 8 sets of user input values in 8 cycles
                // can be manipulated to scale this number up r down

                cout << "\n\n" <<setw(35)<<"    2.2.9. "<<setw(6)<<"Skin size: "<<skin_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(36)<<"    2.2.10. "<<setw(6)<<"Fat size: "<<fat_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(36)<<"    2.2.11. "<<setw(6)<<"Bone size: "<<bone_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(36)<<"    2.2.12. "<<setw(6)<<"Brain size: "<<brain_sz<<" [m]";
                            // prints out cmputed values 
                optmzr_t(); //flow optimizer fn
                cout << "\n\n\n" <<setw(22)<<"     "<<setw(6)<<"---------------LIST "<<(x+1)<<"---------------\n";
            }
        }
        else if(num_of_rds_vals < 1 || num_of_rds_vals > 8){
            cout << "\n\n" <<setw(24)<<"          "<<setw(6)<<"Error! Undefined choice ["<<(num_of_rds_vals)<<"].";
            optmzr_1_sec_t(); //flow optimizer fn
            cout << "\n\n\n" <<setw(24)<<"          "<<setw(6)<<"Program Reloading.";
            optmzr_1_sec_t(); //flow optimizer fn
            loading_fn();
            cout <<"\n"<<endl;
                //optimizer fn
        }
                //-----print file prompt---------
        cout<<"\n\n\t   Print the generated information into a file?: ";
        cout << "\n\n" <<setw(23)<<"    1.0.0.2. "<<setw(6)<<"NOTE: \n";
        cout << "\n" <<setw(23)<<"   -> "<<setw(6)<<"This will OVERWRITE (Tissues_radius.txt) file if already exists!";
        cout<< "\n\n" <<setw(23)<<"      "<<setw(6)<<"Your choice?(y/n): ";
        cin >> print_prmpt;
        optmzr_1_sec_t(); //flow optimizer fn
        if(print_prmpt == "y" || print_prmpt == "Y"){
            tissue_rads_print_file.open("Tissues_radius.txt");
                       //file 'SAR_Results.txt' opened
                        //in the current dir
            prnt_tissue_rds_file(head_sz_val_trck);
                        // calls file print fn
            optmzr_1_sec_t(); //flow optimizer fn
            cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<" Print Report";
            cout << "\n" <<setw(14)<<"          "<<setw(6)<<" -------------------------------------------";
            cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<" Generating results file.";
            optmzr_1_sec_t(); //flow optimizer fn
            loading_fn();
            optmzr_1_sec_t(); //flow optimizer fn
            cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<" Success!.";
            cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<" Check the file (Tissues_radius.txt) in your\n" <<setw(14)<<"          "<<setw(6)<<" current program directory.";
            optmzr_1_sec_t(); //flow optimizer fn
            cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<" -------------------------------------------";

            tissue_rads_print_file.close();
                //close printed file
        }
        else if(print_prmpt == "n" || print_prmpt == "N"){
            cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<" Okay!.";
            optmzr_1_sec_t(); //flow optimizer fn
        }else if ((print_prmpt == "y" || print_prmpt == "Y") && (print_prmpt == "n" || print_prmpt == "N"))
        {
            cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<"Error! Undefined choice ["<<(oprtn_prompt)<<"].";
            optmzr_2_sec_t(); //flow optimizer fn
        }
                //-----print file prompt---------

        cout<<"\n\n\t   Reload the program to perform other\n\n\t   operations?(y/n)\n\n\t\t: ";
        cin>>oprtn_prompt;
            //operations prompt
        if(oprtn_prompt == "y" || oprtn_prompt == "Y"){
            optmzr_1_sec_t(); //flow optimizer fn
            cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<"Program Reloading. ";
            optmzr_1_sec_t(); //flow optimizer fn
            loading_fn();
            optmzr_1_sec_t(); //flow optimizer fn
            std::system("clear");
                //system("CLS"); for windows
                //clears console
            cout <<"\n\n"<<endl;
                //optimizer fn
            prog_init();
        }
        else if(oprtn_prompt == "n" || oprtn_prompt == "N"){
            cout << "\n\n" <<setw(10)<<"          "<<setw(6)<<"------------------Great!------------------";
            optmzr_2_sec_t(); //flow optimizer fn
            cout << "\n\n\n" <<setw(10)<<"          "<<setw(6)<<"Program exiting.";
            optmzr_2_sec_t(); //flow optimizer fn
            loading_fn();
            cout <<"\n\n"<<endl;
                //optimizer fn
        }
        else if((oprtn_prompt != "y" || oprtn_prompt != "Y") && (oprtn_prompt != "n" || oprtn_prompt != "N")){
            cout << "\n\n" <<setw(10)<<"          "<<setw(6)<<"Error! Undefined choice ["<<(oprtn_prompt)<<"].";
            optmzr_2_sec_t(); //flow optimizer fn
            cout << "\n\n\n" <<setw(10)<<"          "<<setw(6)<<"Program Exiting.";
            optmzr_2_sec_t(); //flow optimizer fn
            loading_fn();
            cout <<"\n\n"<<endl;
                //optimizer fn
        }
    }
        //computes tissues radius
}
void prnt_sar_file(){
        SAR_print_file << "\n\n\n" <<setw(21)<<"    2.1.0. "<<setw(6)<<"SAR Tissue Properties";
        SAR_print_file << "\n" <<setw(21)<<"           "<<setw(6)<<"------------------------------------------\n";


        SAR_print_file << "\n" <<setw(21)<<"    2.1.1. "<<setw(6)<<"Constants:";
        SAR_print_file << "\n" <<setw(21)<<"           "<<setw(6)<<"-----------------------------";
        SAR_print_file << "\n\n" <<setw(21)<<"    2.1.2. "<<setw(6)<<"Free space impedance : "<<no<<" [ohms]";
        SAR_print_file << "\n\n" <<setw(21)<<"    2.1.3. "<<setw(6)<<"Free space permeability : "<<uo<<" [H/m]";
        SAR_print_file << "\n\n" <<setw(21)<<"    2.1.4. "<<setw(6)<<"Free space permittivity : "<<eo<<" [F/m]";
        SAR_print_file << "\n\n" <<setw(21)<<"    2.1.5. "<<setw(6)<<"Free space EM wave speed: "<<co<<" [m/s]";
        SAR_print_file << "\n\n" <<setw(21)<<"           "<<setw(6)<<"------------------------------------------";

        SAR_print_file << "\n\n\n" <<setw(21)<<"    2.2.0. "<<setw(6)<<"Variables:";
        SAR_print_file << "\n\n" <<setw(21)<<"           "<<setw(6)<<"-----------------------------";
        SAR_print_file << "\n\n" <<setw(21)<<"    2.2.2. "<<setw(6)<<"Transmission power : "<<Pt<<" [W]";
        SAR_print_file << "\n\n" <<setw(21)<<"    2.2.3. "<<setw(6)<<"Device distance : "<<da<<" [m]";
        SAR_print_file << "\n\n" <<setw(21)<<"    2.2.4. "<<setw(6)<<"Tissue minimum conductivity : "<<t_min_cndvty<<" [S/m]";
        SAR_print_file << "\n\n" <<setw(21)<<"    2.2.5. "<<setw(6)<<"Tissue maximum conductivity : "<<t_cndvty<<" [S/m]";
        SAR_print_file << "\n\n" <<setw(21)<<"    2.2.6. "<<setw(6)<<"Tissue density : "<<t_dnsty<<" [Kg/m^3]";
        SAR_print_file << "\n\n" <<setw(21)<<"    2.2.7. "<<setw(6)<<"Center frequency : "<<fc<<" [Hz]";
        SAR_print_file << "\n\n" <<setw(21)<<"    2.2.8. "<<setw(6)<<"Tissue type : "<<tissue_type<<"";
        if(tissue_type == "Brain" || anlyss_optn == "y" || anlyss_optn == "Y"){
            if(tissue_type == "Brain" && (anlyss_optn == "y" || anlyss_optn == "Y")){
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n\n" <<setw(21)<<"           "<<setw(6)<<"-----------------2.2.1 :Tissues Size----------------------";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(21)<<"    2.2.1.1. "<<setw(6)<<"Skin size by radius: "<<skin_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.1.2. "<<setw(6)<<"Fat size by radius: "<<fat_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.1.3. "<<setw(6)<<"Bone size by radius: "<<bone_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.1.4. "<<setw(6)<<"Brain size by radius: "<<brain_sz<<" [m]";

                // -------tissues thickness--------

                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.1.5. "<<setw(6)<<"Skin size by thickness: "<<(skin_tsse_thcknss)<<" [m]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.1.6. "<<setw(6)<<"Fat size by thickness: "<<(fat_tsse_thcknss)<<" [m]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.1.7. "<<setw(6)<<"Bone size by thickness: "<<(bone_tsse_thcknss)<<" [m]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.1.8. "<<setw(6)<<"Brain size by thickness: "<<(brain_tsse_thcknss)<<" [m]";
                optmzr_t(); //flow optimizer fn

            }

            else if(tissue_type == "Brain" && (anlyss_optn == "n" || anlyss_optn == "N")){
                SAR_print_file << "\n\n" <<setw(21)<<"    2.2.9. "<<setw(6)<<"Brain size by radius: "<<brain_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
            }
            else if(tissue_type != "Brain" && (anlyss_optn == "y" || anlyss_optn == "Y")){
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n\n" <<setw(21)<<"           "<<setw(6)<<"-----------------2.2.1 :Tissues Size----------------------";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(21)<<"    2.2.9. "<<setw(6)<<"Skin size by radius: "<<skin_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.10. "<<setw(6)<<"Fat size by radius: "<<fat_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.11. "<<setw(6)<<"Bone size by radius: "<<bone_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.12. "<<setw(6)<<"Brain size by radius: "<<brain_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
                // -------tissues thickness--------

                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.13. "<<setw(6)<<"Skin size by thickness: "<<(skin_tsse_thcknss)<<" [m]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.14. "<<setw(6)<<"Fat size by thickness: "<<(fat_tsse_thcknss)<<" [m]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.15. "<<setw(6)<<"Bone size by thickness: "<<(bone_tsse_thcknss)<<" [m]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.16. "<<setw(6)<<"Brain size by thickness: "<<(brain_tsse_thcknss)<<" [m]";
                optmzr_t(); //flow optimizer fn

            }
        }           
        if(powr_attntn_flag == "y" || powr_attntn_flag == "y"){
            optmzr_t(); //flow optimizer fn
            SAR_print_file << "\n\n\n" <<setw(21)<<"           "<<setw(6)<<"-----------------2.2.2 :Tissues Power----------------------";
            optmzr_t(); //flow optimizer fn
            if(tissue_type == "Skin"){
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.1. "<<setw(6)<<"Skin tissue attenuated power : "<<skin_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.2. "<<setw(6)<<"Power out of skin tissue(after attenuation) : "<<skin_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
            }
            if(tissue_type == "Fat"){
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.1. "<<setw(6)<<"Skin tissue attenuated power : "<<skin_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.2. "<<setw(6)<<"Power out of skin tissue(after attenuation) : "<<skin_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.3. "<<setw(6)<<"Fat tissue attenuated power : "<<fat_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.4. "<<setw(6)<<"Power out of fat tissue(after attenuation) : "<<fat_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
         }
            if(tissue_type == "Bone"){
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.1. "<<setw(6)<<"Skin tissue attenuated power : "<<skin_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.2. "<<setw(6)<<"Power out of skin tissue(after attenuation) : "<<skin_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.3. "<<setw(6)<<"Fat tissue attenuated power : "<<fat_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.4. "<<setw(6)<<"Power out of fat tissue(after attenuation) : "<<fat_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.5. "<<setw(6)<<"Bone tissue attenuated power : "<<bone_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.6. "<<setw(6)<<"Power out of bone tissue(after attenuation) : "<<bone_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
            }
            if(tissue_type == "Brain"){
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.1. "<<setw(6)<<"Skin tissue aattenuated power : "<<skin_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.2. "<<setw(6)<<"Power out of skin tissue(after attenuation) : "<<skin_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.3. "<<setw(6)<<"Fat tissue attenuated power : "<<fat_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.4. "<<setw(6)<<"Power out of fat tissue(after attenuation) : "<<fat_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.5. "<<setw(6)<<"Bone tissue attenuated power : "<<bone_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.6. "<<setw(6)<<"Power out of bone tissue(after attenuation) : "<<bone_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.7. "<<setw(6)<<"Brain tissue attenuated power : "<<brain_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                SAR_print_file << "\n\n" <<setw(22)<<"    2.2.2.8. "<<setw(6)<<"Power at brain tissue surface(after attenuation) : "<<brain_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
            }
        }
        SAR_print_file << "\n\n" <<setw(21)<<"           "<<setw(6)<<"------------------------------------------";
        SAR_print_file << "\n\n" <<setw(21)<<"    2.3.0. "<<setw(6)<<"Results:";
        SAR_print_file << "\n" <<setw(21)<<"           "<<setw(6)<<"----------------------------- ";
        SAR_print_file << "\n\n" <<setw(21)<<"    2.3.1. "<<setw(6)<<"Tissue impedance : "<<t_impdnc<<" [ohms]";
        SAR_print_file << "\n\n" <<setw(21)<<"    2.3.2. "<<setw(6)<<"Skin depth : "<<dpth<<" [m]";
        SAR_print_file << "\n\n" <<setw(21)<<"    2.3.3. "<<setw(6)<<"Power density : "<<S<<" [W/m^2]";
        SAR_print_file << "\n\n" <<setw(21)<<"    2.3.4. "<<setw(6)<<"Electric field intensity : "<<E<<" [V/m]";
        SAR_print_file << "\n\n" <<setw(21)<<"    2.3.5. "<<setw(6)<<"Specific Absorption Rate (SAR) : "<<Sar<<" [W/Kg]\n";
        SAR_print_file << "\n\n\n" <<setw(21)<<"           "<<setw(6)<<"---------------------------------< "<<(avatar)<<" >-------------------------------\n\n\n";
            //---------printing to SAR file---------
}
void oprtn_flow(){
        cout << "\n\n\n" <<setw(19)<<"    1.0.1. "<<setw(6)<<"Tissue type: ";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"    1.0.1.1. "<<setw(6)<<"Use (1) for Skin (2) for Fat (3) for Bone or (4) for Brain : ";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"    1.0.1.2. "<<setw(6)<<"Choice: ";
        cin >> tissue_choice;
        optmzr_t(); //flow optimizer fn
        if(tissue_choice == 1){
            tissue_type = "Skin";
        }
        else if(tissue_choice == 2){
            tissue_type = "Fat";
        }
        else if(tissue_choice == 3){
            tissue_type = "Bone";
        }
        else if(tissue_choice == 4){
            tissue_type = "Brain";
            if(anlyss_optn == "n" || anlyss_optn == "N"){
                cout << "\n\n" <<setw(23)<<"    1.0.0.1. "<<setw(6)<<"Enter brain size by radius in metres (m): ";
                cin >> brain_sz;
                        //head size dfn
            }
        }
        else if((tissue_choice != 2) && (tissue_choice != 3) && (tissue_choice != 4)){
            cout << "\n" <<setw(21)<<"    Error! "<<setw(6)<<"Undefined choice ["<<(tissue_choice)<<"]. Try again. ";
            optmzr_1_sec_t(); //flow optimizer fn
            cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<"Program Restarting. ";
            optmzr_1_sec_t(); //flow optimizer fn
            loading_fn();
            optmzr_1_sec_t(); //flow optimizer fn
            std::system("clear");
                //system("CLS"); for windows
                //clears console
            cout <<"\n\n"<<endl;
                //optimizer fn
            prog_init();
        }
                //defines tissue type
        // direct variables initialization
        // fc = 93300000;
        // da = 0;
        // Pt = .1305;
        // Gt = 1;
        // ur = 1;

        // er = 70.26359;
        // t_dnsty = 1030.0;
        // t_min_cndvty = 0.036134;
        // t_cndvty = 0.435428;
            //initialized variablle for trial

        cout << "\n" <<setw(21)<<"    1.1.0. "<<setw(6)<<"Enter: \n";
            optmzr_1_sec_t(); //flow optimizer fn
        cout << "\n" <<setw(21)<<"    1.1.1. "<<setw(6)<<"Center frequency in [Hz]: ";
        cin >> fc;
        cout << "\n" <<setw(21)<<"    1.1.2. "<<setw(6)<<"Device distance (da) in [m]: ";
        cin >> da;
        cout << "\n" <<setw(21)<<"    1.1.3. "<<setw(6)<<"Transmission power [Pt] after TDM conversion in Watts [W]: ";
        cin >> Pt;
        cout << "\n" <<setw(21)<<"    1.1.3. "<<setw(6)<<"Antenna gain [Gt]: ";
        cin >> Gt;
        cout << "\n" <<setw(21)<<"    1.1.4. "<<setw(6)<<"Relative permittivity [er]: ";
        cin >> er;
        cout << "\n" <<setw(21)<<"    1.1.5. "<<setw(6)<<"Relative permeability [ur] (normally unity): ";
        cin >> ur;
        cout << "\n" <<setw(21)<<"    1.1.6. "<<setw(6)<<"Tissue density [p] in [Kg/m^3]: ";
        cin >> t_dnsty;
        cout << "\n" <<setw(21)<<"    1.1.7. "<<setw(6)<<"Tissue minimum conductivity [σ] in [S/m]: ";
        cin >> t_min_cndvty;
        cout << "\n" <<setw(21)<<"    1.1.7. "<<setw(6)<<"Tissue maximum conductivity [σ] in [S/m]: ";
        cin >> t_cndvty;
        optmzr_1_sec_t(); //flow optimizer fn

            // -------calling operator fns--------
        depth(fc, t_min_cndvty);
        t_impedance(ur, er);
        pwr_trsmtd(Pt, brain_sz);
        pwr_d(Pt);
        e_field(er);
        sar_val(t_cndvty, t_dnsty);
            // -------calling operator fns--------

        cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<". . . . . . .ORGANIZING INFO. ";
        optmzr_1_sec_t(); //flow optimizer fn
        loading_fn();
        cout <<"\n\n"<<endl;
            //optimizer fn
        optmzr_1_sec_t(); //flow optimizer fn
        cout << "\n" <<setw(21)<<"    2.1.0. "<<setw(6)<<"Tissue Properties";
        cout << "\n" <<setw(21)<<"           "<<setw(6)<<"-------------------------------------------------------\n";


        cout << "\n" <<setw(21)<<"    2.1.1. "<<setw(6)<<"Constants:";
            optmzr_t(); //flow optimizer fn
        cout << "\n" <<setw(21)<<"           "<<setw(6)<<"-----------------------------";
            optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"    2.1.3. "<<setw(6)<<"Free space permeability : "<<no<<" [H/m]";
            optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"    2.1.4. "<<setw(6)<<"Free space permittivity : "<<eo<<" [F/m]";
            optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"    2.1.5. "<<setw(6)<<"Free space EM wave speed: "<<co<<" [m/s]";
            optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"           "<<setw(6)<<"-------------------------------------------------------";

        optmzr_1_sec_t(); //flow optimizer fn
        cout << "\n\n\n" <<setw(21)<<"    2.2.0. "<<setw(6)<<"Variables:";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"           "<<setw(6)<<"-----------------------------";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"    2.2.2. "<<setw(6)<<"Transmission power : "<<Pt<<" [W]";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"    2.2.3. "<<setw(6)<<"Device distance : "<<da<<" [m]";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"    2.2.4. "<<setw(6)<<"Tissue minimum conductivity : "<<t_min_cndvty<<" [S/m]";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"    2.2.5. "<<setw(6)<<"Tissue maximum conductivity : "<<t_cndvty<<" [S/m]";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"    2.2.6. "<<setw(6)<<"Tissue density : "<<t_dnsty<<" [Kg/m^3]";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"    2.2.7. "<<setw(6)<<"Center frequency : "<<fc<<" [Hz]";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"    2.2.8. "<<setw(6)<<"Tissue type : "<<tissue_type<<"";
        if(tissue_type == "Brain" || anlyss_optn == "y" || anlyss_optn == "Y"){
            if(tissue_type == "Brain" && (anlyss_optn == "y" || anlyss_optn == "Y")){
                optmzr_t(); //flow optimizer fn
                cout << "\n\n\n" <<setw(21)<<"           "<<setw(6)<<"-----------------2.2.1 :Tissues Size----------------------";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(21)<<"    2.2.1.1. "<<setw(6)<<"Skin size by radius: "<<skin_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.1.2. "<<setw(6)<<"Fat size by radius: "<<fat_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.1.3. "<<setw(6)<<"Bone size by radius: "<<bone_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.1.4. "<<setw(6)<<"Brain size by radius: "<<brain_sz<<" [m]";

                // -------tissues thickness--------

                cout << "\n\n" <<setw(22)<<"    2.2.1.5. "<<setw(6)<<"Skin size by thickness: "<<(skin_tsse_thcknss)<<" [m]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.1.6. "<<setw(6)<<"Fat size by thickness: "<<(fat_tsse_thcknss)<<" [m]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.1.7. "<<setw(6)<<"Bone size by thickness: "<<(bone_tsse_thcknss)<<" [m]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.1.8. "<<setw(6)<<"Brain size by thickness: "<<(brain_tsse_thcknss)<<" [m]";
                optmzr_t(); //flow optimizer fn

            }
            else if(tissue_type == "Brain" && (anlyss_optn == "n" || anlyss_optn == "N")){
                cout << "\n\n" <<setw(21)<<"    2.2.9. "<<setw(6)<<"Brain size by radius: "<<brain_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
            }
            else if(tissue_type != "Brain" && (anlyss_optn == "y" || anlyss_optn == "Y")){
                optmzr_t(); //flow optimizer fn
                cout << "\n\n\n" <<setw(21)<<"           "<<setw(6)<<"-----------------2.2.1 :Tissues Size----------------------";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(21)<<"    2.2.9. "<<setw(6)<<"Skin size by radius: "<<skin_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.10. "<<setw(6)<<"Fat size by radius: "<<fat_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.11. "<<setw(6)<<"Bone size by radius: "<<bone_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.12. "<<setw(6)<<"Brain size by radius: "<<brain_sz<<" [m]";
                optmzr_t(); //flow optimizer fn
                // -------tissues thickness--------

                cout << "\n\n" <<setw(22)<<"    2.2.13. "<<setw(6)<<"Skin size by thickness: "<<(skin_tsse_thcknss)<<" [m]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.14. "<<setw(6)<<"Fat size by thickness: "<<(fat_tsse_thcknss)<<" [m]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.15. "<<setw(6)<<"Bone size by thickness: "<<(bone_tsse_thcknss)<<" [m]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.16. "<<setw(6)<<"Brain size by thickness: "<<(brain_tsse_thcknss)<<" [m]";
                optmzr_t(); //flow optimizer fn

            }
        }            
        if(powr_attntn_flag == "y" || powr_attntn_flag == "y"){
            optmzr_t(); //flow optimizer fn
            cout << "\n\n\n" <<setw(21)<<"           "<<setw(6)<<"-----------------2.2.2 :Tissues Power----------------------";
            optmzr_t(); //flow optimizer fn
            if(tissue_type == "Skin"){
                cout << "\n\n" <<setw(22)<<"    2.2.2.1. "<<setw(6)<<"Skin tissue attenuated power : "<<skin_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.2.2. "<<setw(6)<<"Power out of skin tissue(after attenuation) : "<<skin_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
            }
            if(tissue_type == "Fat"){
                cout << "\n\n" <<setw(22)<<"    2.2.2.1. "<<setw(6)<<"Skin tissue attenuated power : "<<skin_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.2.2. "<<setw(6)<<"Power out of skin tissue(after attenuation) : "<<skin_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.2.3. "<<setw(6)<<"Fat tissue attenuated power : "<<fat_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.2.4. "<<setw(6)<<"Power out of fat tissue(after attenuation) : "<<fat_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
            }
            if(tissue_type == "Bone"){
                cout << "\n\n" <<setw(22)<<"    2.2.2.1. "<<setw(6)<<"Skin tissue attenuated power : "<<skin_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.2.2. "<<setw(6)<<"Power out of skin tissue(after attenuation) : "<<skin_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.2.3. "<<setw(6)<<"Fat tissue attenuated power : "<<fat_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.2.4. "<<setw(6)<<"Power out of fat tissue(after attenuation) : "<<fat_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.2.5. "<<setw(6)<<"Bone tissue attenuated power : "<<bone_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.2.6. "<<setw(6)<<"Power out of bone tissue(after attenuation) : "<<bone_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
            }
            if(tissue_type == "Brain"){
                cout << "\n\n" <<setw(22)<<"    2.2.2.1. "<<setw(6)<<"Skin tissue aattenuated power : "<<skin_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.2.2. "<<setw(6)<<"Power out of skin tissue(after attenuation) : "<<skin_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.2.3. "<<setw(6)<<"Fat tissue attenuated power : "<<fat_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.2.4. "<<setw(6)<<"Power out of fat tissue(after attenuation) : "<<fat_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.2.5. "<<setw(6)<<"Bone tissue attenuated power : "<<bone_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.2.6. "<<setw(6)<<"Power out of bone tissue(after attenuation) : "<<bone_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.2.7. "<<setw(6)<<"Brain tissue attenuated power : "<<brain_tsse_pwr_attenuated<<" [dBm]";
                optmzr_t(); //flow optimizer fn
                cout << "\n\n" <<setw(22)<<"    2.2.2.8. "<<setw(6)<<"Power at brain tissue surface(after attenuation) : "<<brain_tsse_pwr_rcvd2<<" [W]";
                optmzr_t(); //flow optimizer fn
            }
        }
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"           "<<setw(6)<<"-------------------------------------------------------";

        optmzr_1_sec_t(); //flow optimizer fn
        cout << "\n\n\n" <<setw(14)<<"          "<<setw(6)<<" . . . . . . .COMPUTING RESULTS. ";
        optmzr_1_sec_t(); //flow optimizer fn
        loading_fn();
        cout <<"\n\n"<<endl;
            //optimizer fn
        optmzr_1_sec_t(); //flow optimizer fn
        cout << "\n" <<setw(21)<<"    2.3.0. "<<setw(6)<<"Results:";
        optmzr_t(); //flow optimizer fn
        cout << "\n" <<setw(21)<<"           "<<setw(6)<<"----------------------------- ";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"    2.3.1. "<<setw(6)<<"Tissue impedance : "<<t_impdnc<<" [ohms]";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"    2.3.2. "<<setw(6)<<"Skin depth : "<<dpth<<" [m]";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"    2.3.3. "<<setw(6)<<"Power density : "<<S<<" [W/m^2]";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"    2.3.4. "<<setw(6)<<"Electric field intensity : "<<E<<" [V/m]";
        optmzr_1_hlf_sec_t(); //flow optimizer fn
        cout << "\n\n" <<setw(21)<<"    2.3.5. "<<setw(6)<<"Specific Absorption Rate (SAR) : "<<Sar<<" [W/Kg]\n";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n\n" <<setw(22)<<"           "<<setw(6)<<"-------------------------------------------------------";

        optmzr_1_sec_t(); //flow optimizer fn
        cout << "\n\n\n" <<setw(14)<<"          "<<setw(6)<<" . . . . . . .FINISHING. ";
        optmzr_1_sec_t(); //flow optimizer fn
        loading_fn();

                //-----print file prompt---------
        cout<<"\n\n\t   Print the generated information into a file?: ";
        cout << "\n\n" <<setw(23)<<"    1.0.0.2. "<<setw(6)<<"NOTE: \n";
        cout << "\n" <<setw(23)<<"   -> "<<setw(6)<<"This will OVERWRITE (SAR_Results.txt) file if already exists!";
        cout<< "\n\n" <<setw(23)<<"      "<<setw(6)<<"Your choice?(y/n): ";
        cin >> print_prmpt;
        optmzr_1_sec_t(); //flow optimizer fn
        if(print_prmpt == "y" || print_prmpt == "Y"){
            SAR_print_file.open("SAR_Results.txt");
                       //file 'SAR_Results.txt' opened
                        //in the current dir
            prnt_sar_file();
                        // calls SAR file print fn
            optmzr_1_sec_t(); //flow optimizer fn
            cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<" Print Report";
            cout << "\n" <<setw(14)<<"          "<<setw(6)<<" -------------------------------------------";
            cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<" Generating results file.";
            optmzr_1_sec_t(); //flow optimizer fn
            loading_fn();
            optmzr_1_sec_t(); //flow optimizer fn
            cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<" Success!.";
            cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<" Check the file (SAR_Results.txt) in your\n" <<setw(14)<<"          "<<setw(6)<<" current program directory.";
            optmzr_1_sec_t(); //flow optimizer fn
            optmzr_1_sec_t(); //flow optimizer fn
            cout << "\n" <<setw(14)<<"          "<<setw(6)<<" -------------------------------------------";

            SAR_print_file.close();
                            //close the printed file file
        }
        else if(print_prmpt == "n" || print_prmpt == "N"){
            cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<" Okay!.";
            optmzr_1_sec_t(); //flow optimizer fn
        }else if ((print_prmpt == "y" || print_prmpt == "Y") && (print_prmpt == "n" || print_prmpt == "N"))
        {
            cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<"Error! Undefined choice ["<<(oprtn_prompt)<<"].";
            optmzr_2_sec_t(); //flow optimizer fn
        }
                //-----print file prompt---------

        cout<<"\n\n\t   Reload the program to perform other\n\n\t   operations?(y/n)\n\n\t\t: ";
        cin>>oprtn_prompt;
            //operations prompt
        if(oprtn_prompt == "y" || oprtn_prompt == "Y"){
            optmzr_1_sec_t(); //flow optimizer fn
            cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<"Program Reloading. ";
            optmzr_1_sec_t(); //flow optimizer fn
            loading_fn();
            optmzr_1_sec_t(); //flow optimizer fn
            std::system("clear");
                //system("CLS"); for windows
                //clears console
            cout <<"\n\n"<<endl;
                //optimizer fn
            prog_init();
        }
        else if(oprtn_prompt == "n" || oprtn_prompt == "N"){
            cout << "\n\n" <<setw(10)<<"          "<<setw(6)<<"------------------Great!------------------";
            optmzr_2_sec_t(); //flow optimizer fn
            cout << "\n\n\n" <<setw(10)<<"          "<<setw(6)<<"Program exiting.";
            optmzr_2_sec_t(); //flow optimizer fn
            loading_fn();
            cout <<"\n\n"<<endl;
                //optimizer fn
        }
        else if((oprtn_prompt != "y" || oprtn_prompt != "Y") && (oprtn_prompt != "n" || oprtn_prompt != "N")){
            cout << "\n\n" <<setw(10)<<"          "<<setw(6)<<"Error! Undefined choice ["<<(oprtn_prompt)<<"].";
            optmzr_2_sec_t(); //flow optimizer fn
            cout << "\n\n\n" <<setw(10)<<"          "<<setw(6)<<"Program Exiting.";
            optmzr_2_sec_t(); //flow optimizer fn
            loading_fn();
            cout <<"\n\n"<<endl;
                //optimizer fn
        }
}
void prog_init(){
        optmzr_t(); //flow optimizer fn
        cout << "\n\n\t=====================================================================================\t\n\t\t\t\t          RF COMPUTATIONS SYSTEM\n\t=====================================================================================";
        optmzr_t(); //flow optimizer fn << endl
        cout << "\n\n\tThis is a simple RF calculator. With it we're capable of\n";
        cout << "\n\tperforming RF calculation for human tissues which include:";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(14)<<"    1.0. "<<setw(6)<<"Depth of radiation penetration. ";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(14)<<"    1.1. "<<setw(6)<<"Power density in the tissue. ";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(14)<<"    1.2. "<<setw(6)<<"Electric field intensity in the tissue. ";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(14)<<"    1.3. "<<setw(6)<<"Specific absorption rate  (SAR) in the tissue: ";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n" <<setw(14)<<"    NOTE: "<<setw(6)<<"This involves use of various parameters";
        cout << "\n" <<setw(14)<<"          "<<setw(6)<<"which are to be defined .";

        optmzr_1_sec_t(); //flow optimizer fn
        cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<". . . . . . .LOADING. ";
        optmzr_1_hlf_sec_t(); //flow optimizer fn
        loading_fn();
            //optimizer fn
        cout << "\n\n\t   --------------------------------------------------------";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n\n\t    1.1. RF PARAMETERS DEFINITION: ";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n\t    Fill ALL the fields as required below.";
        optmzr_1_sec_t(); //flow optimizer fn
        cout << "\n\n\t    ------------Initialization-----------.";
        optmzr_t(); //flow optimizer fn
        cout << "\n\n\n" <<setw(21)<<"    1.0.1. "<<setw(6)<<"Select your analysis action use (1) or (2)): ";
        optmzr_1_sec_t(); //flow optimizer fn
        cout << "\n\n" <<setw(23)<<"    1. "<<setw(6)<<"Determine tissue radius ONLY.";
        optmzr_1_sec_t(); //flow optimizer fn
        cout << "\n\n" <<setw(23)<<"    2. "<<setw(6)<<"Perform overall SAR computation.";
        optmzr_1_sec_t(); //flow optimizer fn
        cout << "\n\n" <<setw(25)<<"     "<<setw(6)<<"Enter your action choice: ";
        cin >> analysis_actn;
        if(analysis_actn == 1){
            compute_t_rads();
                // calls radius computation fn
        }
        else if(analysis_actn == 2){
            cout << "\n\n" <<setw(21)<<"    1.0.0.0. "<<setw(6)<<"Does your analysis involve general body size e.g head? (y/n): ";
            cin >> anlyss_optn;
            optmzr_t(); //flow optimizer fn
            if(anlyss_optn == "y" || anlyss_optn == "Y"){
                cout << "\n\n" <<setw(23)<<"    1.0.0.1. "<<setw(6)<<"Enter head size by circumference in metres (m): ";
                cin >> head_sz;
                        //head size dfn
                optmzr_1_sec_t(); //flow optimizer fn
                cout << "\n\n" <<setw(23)<<"    1.0.0.2. "<<setw(6)<<"Do you want to consider power dissipation in each tissue?(y/n): ";
                cin >> powr_attntn_flag;
                        // prompt flag to confirm attenuation effects
                optmzr_t(); //flow optimizer fn
                cout << "\n\n\n" <<setw(14)<<"          "<<setw(6)<<". . . . . .RESUMING. ";
                optmzr_1_hlf_sec_t(); //flow optimizer fn
                loading_fn();
                    //optimizer fn
                compute_tissue_rds(head_sz);
                    //tissues size computation fn
                oprtn_flow();
                        //calls program guide flow fn
            }
            else if(anlyss_optn == "n" || anlyss_optn == "N"){
                optmzr_1_sec_t(); //flow optimizer fn
                oprtn_flow();
                        //calls program guide flow fn
            }
            else if((oprtn_prompt != "y" || oprtn_prompt != "Y") && (oprtn_prompt != "n" || oprtn_prompt != "N")){
                cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<"Error! Undefined choice ["<<(oprtn_prompt)<<"].";
                optmzr_1_sec_t(); //flow optimizer fn
                cout << "\n\n\n" <<setw(14)<<"          "<<setw(6)<<"Program Restarting.";
                optmzr_1_sec_t(); //flow optimizer fn
                loading_fn();
                std::system("clear");
                    //system("CLS"); for windows
                    //clears console
                prog_init();
                    //recursion for program re-initialisation
            }
        }
        else if(analysis_actn != 1 && analysis_actn != 2){
            cout << "\n\n" <<setw(14)<<"          "<<setw(6)<<"Error! Undefined choice ["<<(analysis_actn)<<"].";
            optmzr_1_sec_t(); //flow optimizer fn
            cout << "\n\n\n" <<setw(14)<<"          "<<setw(6)<<"Program Restarting.";
            optmzr_1_sec_t(); //flow optimizer fn
            loading_fn();
            std::system("clear");
                //system("CLS"); for windows
                //clears console
        }
}
int main()
{
    oprtn_prompt= "y";
    while((oprtn_prompt=="y") || (oprtn_prompt=="Y"))
    {
        prog_init();
            //calling initializer fn
    }
    return 0;
}

        //------control functions------

float t_impedance(float rel_u, float rel_e){
    ur = rel_u;
    er = rel_e;
    t_impdnc = no * sqrt(ur / er);
    return 0;
    }
        // computes tissue impedance

float depth(float freq_val, float condvty_val){
    fc = freq_val;
    t_min_cndvty = condvty_val;
    dpth = sqrt(1 / (pi*fc*uo*t_min_cndvty));
    d = da + dpth;
    return 0;
    }
        // computes signal depth in the tissue

float pwr_trsmtd(float trans_pwr_val, float brn_sz){
    brain_sz = brn_sz;
            //brain size;
    Pt = trans_pwr_val;
            // initial transmitted power
    if(powr_attntn_flag == "Y" || powr_attntn_flag == "y")
    {
            skin_tsse_pwr_attenuated = 8.686 * (skin_tsse_thcknss / dpth);
                //power attenuated at the skin in dB
            skin_tsse_pwr_rcvd1 = ((Pt*1000)*.095916 )- skin_tsse_pwr_attenuated;
                //power received at the skin in dBm
                //'.095916'dBm = 1mW
                //Math.pow(10,((dbm-30)/10))
            skin_tsse_pwr_rcvd2 = pow(10, ((skin_tsse_pwr_rcvd1-30)/10));
                //power received at the skin in watts
                //1W = 30dBm
                // -----skin tissue power after attenuation----

            fat_tsse_pwr_attenuated = 8.686 * (fat_tsse_thcknss / dpth);
                //power attenuated at the fat in dB
            fat_tsse_pwr_rcvd1 = ((skin_tsse_pwr_rcvd2*1000)*.095916 )- fat_tsse_pwr_attenuated;
                //power received at the fat in dBm
                //'.095916'dBm = 1mW
                //Math.pow(10,((dbm-30)/10))
            fat_tsse_pwr_rcvd2 = pow(10, ((fat_tsse_pwr_rcvd1-30)/10));
                //power received at the fat in watts
                //1W = 30dBm
                // -----fat tissue power after attenuation----

            bone_tsse_pwr_attenuated = 8.686 * (bone_tsse_thcknss / dpth);
                //power attenuated at the bone in dB
            bone_tsse_pwr_rcvd1 = ((fat_tsse_pwr_rcvd2*1000)*.095916 )- bone_tsse_pwr_attenuated;
                //power received at the bone in dBm
                //'.095916'dBm = 1mW
                //Math.pow(10,((dbm-30)/10))
            bone_tsse_pwr_rcvd2 = pow(10, ((bone_tsse_pwr_rcvd1-30)/10));
                //power received at the bone in watts
                //1W = 30dBm
                // -----bone tissue power after attenuation----

            brain_tsse_pwr_attenuated = 8.686 * (brain_tsse_thcknss / dpth);
                //power attenuated at the brain in dB
            brain_tsse_pwr_rcvd1 = ((bone_tsse_pwr_rcvd2*1000)*.095916 )- brain_tsse_pwr_attenuated;
                //power received at the brain in dBm
                //'.095916'dBm = 1mW
                //Math.pow(10,((dbm-30)/10))
            brain_tsse_pwr_rcvd2 = pow(10, ((brain_tsse_pwr_rcvd1-30)/10));
                //power received at the brain in watts
                //1W = 30dBm
                // -----brain tissue power after attenuation----
    }
    else if(powr_attntn_flag != "Y" || powr_attntn_flag != "y")
    {
        if(tissue_type == "Brain"){
            brn_pwr_attenuated = 8.686 * (dpth / brain_sz);
                //power attenuated at the brain in dB
            brn_pwr_rcvd1 = ((Pt*1000)*.095916 )- brn_pwr_attenuated;
                //power received at the brain in dBm
                //'.095916'dBm = 1mW
                //Math.pow(10,((dbm-30)/10))
            brn_pwr_rcvd2 = pow(10, ((brn_pwr_rcvd1-30)/10));
                //power received at the brain in watts
                //1W = 30dBm
        }
        else if(tissue_type != "Brain"){
            Pt = trans_pwr_val;
        }
    }
    return 0;
    }   //power transmitted to brain

float pwr_d(float Pwr_val){
    Pt = Pwr_val;
    if(powr_attntn_flag == "Y" || powr_attntn_flag == "y")
    {
        if(tissue_type == "Skin")
        {
            S = (Pt*Gt) / (4*pi*pow(d,2));
                //computes power density with power after attenuation
        }
        else if(tissue_type == "Fat")
        {
            S = (skin_tsse_pwr_rcvd2*Gt) / (4*pi*pow(d,2));
                //computes power density with power after attenuation
        }
        else if(tissue_type == "Bone")
        {
            S = (fat_tsse_pwr_rcvd2*Gt) / (4*pi*pow(d,2));
                //computes power density with power after attenuation
        }
        else if(tissue_type == "Brain")
        {
            S = (bone_tsse_pwr_rcvd2*Gt) / (4*pi*pow(brain_sz,2));
                //computes power density with power after attenuation
        }
    }
    else if(powr_attntn_flag != "Y" || powr_attntn_flag != "y")
    {
        if(tissue_type != "Brain"){
            Pt = Pwr_val;
            S = (Pt*Gt) / (4*pi*pow(d,2));
        }
        else if(tissue_type == "Brain"){
            S = (brn_pwr_rcvd2*Gt) / (4*pi*pow(brain_sz,2));
                //computes power density with power after attenuation
                //REF(Codra L. Chand Handbook)
        }
    }
    return 0;
}
        // computes signal power density in th tissue

float e_field(float t_er_val){
    er = t_er_val;
    E = sqrt(S * t_impdnc);
    return 0;
    }
        // computes electric field intensity in V/m

float sar_val(float condvty_val, float dnsty_val){
    t_cndvty = condvty_val;
    t_dnsty = dnsty_val;
    Sar = (t_cndvty * pow(E, 2)) / (2*t_dnsty);
    return 0;
    }
        // computes tissue SAR value

float compute_tissue_rds(float head_circ){
    float skin_sz_pcntg = 1.1111;
    float fat_sz_pcntg = 1.5556;
    float bone_sz_pcntg = 7.3333;
    float brain_sz_pcntg = 90.00;

    head_rds = head_circ / (2*pi);
        //head radius
            // -------tissues radius(from brain center)------
    skin_sz = head_rds;
            //skin size dfn i.e 1.11 p.c of total head radius
    fat_sz = (head_rds - ((skin_sz_pcntg / 100) * head_rds));
            //fat size dfn i.e 1.56 p.c of total head radius
    bone_sz = (head_rds - (((skin_sz_pcntg + fat_sz_pcntg) / 100) * head_rds));
            //bone size dfn i.e 7.33 p.c of total head radius
    brain_sz = (head_rds - (((skin_sz_pcntg + fat_sz_pcntg + bone_sz_pcntg) / 100) * head_rds));
            //brain size dfn i.e 90 p.c of total head radius

            // -------tissues thickness------
    skin_tsse_thcknss = (head_rds * .0111);
            // skin thickness
    fat_tsse_thcknss = (head_rds * .0156);
            // fat layer thickness
    bone_tsse_thcknss = (head_rds * .0733);
            // bone layer thickness
    brain_tsse_thcknss = (head_rds * .9);
            // brain layer thickness(upto its center)
            //REF(Codra L. Chand Handbook)
    return 0;
}
        //computes tissues radius
