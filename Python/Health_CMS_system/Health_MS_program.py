##=============================================================
##        HEALTH MANAGEMENT SYSTEM                            =
##        KFUPM CLINIC                                        =
##=============================================================

import time
import os
import fileinput
import re #for regular expression
    #imports libraries
    ####--------------------Control Functions Definition----------------
def delay_optmizer1():
    time.sleep(1)
    #delays execution for 1s
    
def seperator_line_format():
    print("\t|\n\t|-------------------------------------------------------------------\n\t|")
    input("\t|\tPress Enter key to continue...")
    #waits for user to press Enter key
    print("\t|\n\t|-------------------------------------------------------------------\n\t|\n\t|")

def getWeight(weight):
    records_title = "\t|\t  Patient ID |\tPatient Name\t|    Weight  |\tAve. Weight  |\tP(%)\t  |\tVisits\t"
        #forms record file title
    with open('Patient_records.txt') as record_file:
            #opens file
        contents = record_file.read()
            #reads record file content
        search_word = weight
            #initialize search word to max weight value
            
            #validating user i/p value
        if(int(search_word) > 0):
            #displays available patient info 
            with open('Patient_records.txt', 'r') as read_obj:
            # Read all lines in the file one by one
                for line in read_obj:
                    #trims patient record line info into a list
                    line_list = []
                    stripped_line = line.strip()
                    line_list = stripped_line.split()
                    # For each line, check if line contains the string
                    # if str(search_word) in line:
                    if (str(0) or str(1) or str(2) or str(3) or str(4) or str(5) or str(6) or str(7) or str(8) or str(9)) in line:
                            
                        P = ((float(line_list[3]) - float(line_list[4]))/ float(line_list[4])) * 100
                            #Patients' percentage weight increase computation formula
                        P = "{:.2f}".format(P)
                            #formats the percentage weight value to 2 d.p
                        patient_record_format = " %10s" %""+str(line_list[0])+" %8s" %""+str(line_list[1])+" "+str(line_list[2])+" %10s" %""+ str(line_list[3]) +" %7s" %""+ str(line_list[4]) +" %7s" %""+ str(P) +" %8s" %""+ str(line_list[5]) +""
                            #fetched patient information
                        print("\n\t|\t---------------------------------------------------------------------------------------")
                        print(records_title)
                        print("\t|\t---------------------------------------------------------------------------------------")
                            #formatting title section
                        print('\t|\n\t|'+patient_record_format+'\n\t|')
                            #prints specific clients information  
        else:
            print ("\t|\t Error: Invalid withdraw amount.")
                #error msg for invalid patient ID
            
    seperator_line_format()

def getAllPatientRecord():
    print("\t|\tDisplay all patients record information\n\t|")
    delay_optmizer1();
    record_file = open("Patient_records.txt","r+")
        #opens record file in read/write mode
    print(record_file.read())
    record_file.close()
        #close file
    print("\t|")
    seperator_line_format()
        #calls seperator format line
    #prints registered patients info
    
def getPatient(patientID):
    records_title = "\t|\t  Patient ID |\tPatient Name\t|    Weight  |\tAve. Weight  |\tVisits\t"
        #forms record file title
        
        #validates patient ID if exists in the record
    with open('Patient_records.txt') as record_file:
            #opens file
        contents = record_file.read()
            #reads file content
        search_word = patientID
            #initialize search word to patient ID
        if(int(search_word) > 0):
                #search patient info by ID through the file content
            if search_word in contents:
                #displays patient available info 
                with open('Patient_records.txt', 'r') as read_obj:
                # Read all lines in the file one by one
                    for line in read_obj:
                        # For each line, check if line contains the string
                        if str(search_word) in line:
                            print("\n\t|\t-------------------------------------------------------------------------------")
                            print(records_title)
                            print("\t|\t-------------------------------------------------------------------------------")
                                #formatting title section
                            print('\t|\n\t|'+line+'\n\t|')
                                #prints specific line with client info                            
            else:
                print ("\t|\t Error! Invalid Patient ID("+patientID+")")
                    #error msg for invalid patient ID
        else:
            print ("\t|\t Error! Invalid Patient ID("+patientID+")")
                #error msg for invalid patient ID
            
    seperator_line_format()
        #calls seperator format line
        #prompts user for patient ID info
    #displays specific patient info
    
def update(patientID, weight):       
    err_check_flag = "OFF"
        #error check flag in low state
    err_msg = ""
    ave_weight = float(input("\t|\t 3. Patient average weight (Kg): "))
    print("\t|")
    visits = int(input("\t|\t 4. Patient number of visits: "))
    print("\t|")
        #prompt for patient data 
    if((weight <= 0) or (ave_weight <= 0)):    
        err_check_flag = "ON"
        #error takes check flag high
        err_msg = "Error: Invalid weight"
        #invalid weight error msg
    if(visits <= 0):
        err_check_flag = "ON"
        #error takes check flag high
        err_msg = "Error: Invalid visits value"
        #invalid visits value error msg
    
    if(err_check_flag == "OFF"):
        Ave_weight = ((weight + (ave_weight*visits)) / (visits + 1))
            #Patient average weight computation formula
        Ave_weight = "{:.2f}".format(Ave_weight)
            #formats the value to 2 d.p
            
            #validates patient ID if exists in the record
        with open('Patient_records.txt') as record_file:
                #opens file
            contents = record_file.read()
                #reads file content
            search_word = patientID
                #initialize search word to patient ID
                
                #search patient info by ID through the file content
            if search_word in contents:
        
                #displays patient available info 
                with open('Patient_records.txt', 'r') as read_obj:
                # Read all lines in the file one by one
                    for line in read_obj:
                        # For each line, check if line contains the string
                        if str(search_word) in line:
                            #trims patient record line info into a list
                            line_list = []
                            stripped_line = line.strip()
                            line_list = stripped_line.split()
                            
                            #updates patient info
                            target_record_file = "Patient_records.txt"
                            with fileinput.FileInput(target_record_file, inplace = True, backup ='.bak') as f:
                                for line_specific in f:
                                    if str(search_word) in line_specific:
                                        print(line_specific.replace(str(line_list[3]), str(weight), 1), end ='')
                                        #update new record by replacing the previous record values
                                        #'1' means replace only one item specified
                                    else:
                                        print(line_specific, end ='')
                                    #update patient weight
                
                            target_record_file = "Patient_records.txt"
                            with fileinput.FileInput(target_record_file, inplace = True, backup ='.bak') as f:
                                for line_specific in f:                      
                                    if str(search_word) in line_specific:
                                        print(line_specific.replace(str(line_list[4]), str(Ave_weight), 1), end ='')
                                        #update new record by replacing the previous record values
                                        #'1' means replace only one item specified
                                    else:
                                        print(line_specific, end ='')
                                    #update patient average weight
                                    
                            target_record_file = "Patient_records.txt"
                            with fileinput.FileInput(target_record_file, inplace = True, backup ='.bak') as f:
                                for line_specific in f:                    
                                    if str(search_word) in line_specific:
                                        print(line_specific.replace(str(line_list[5]), str(visits)), end ='') 
                                        #update new record by replacing the previous record values
                                        #'1' means replace only one item specified
                                        # line_specific = re.sub(r"\b"+str(line_list[5])+"\b", str(visits), line_specific)
                                        # print(line_specific, end ='')
                                    else:
                                        print(line_specific, end ='')
                                    #update patient number of visits
                                    
                print ("\t|\t Patient’s information has been updated . . .")
                    #operation confirmation msg
            else:
                print ("\t|\t Error! Invalid Patient ID")
                    #error msg for invalid patient ID
    else:
        print ("\t|\t "+err_msg)
            #error msg
    seperator_line_format()
        #calls seperator format line
    #updates patient info
    
def addPatient(Name, patientID):
    weight = 0
    ave_weight = 0
    visits = 0;
    patient_record_format = "\n\n %10s" %""+patientID+" %8s" %""+Name+" %14s" %""+ str(weight) +" %11s" %""+ str(ave_weight) +" %11s" %""+ str(visits) +""
    # patient_record_format = "\n\n %10s" %""+patientID+" %8s" %""+Name+" %12s" %""+ str(weight) +" %8s" %""+ str(ave_weight) +" %4s" %""+ str(visits) +""
        #formats patient record info
        #'%10s" %"' sets fixed with 
        #the '%' character informs python to substitute something to a token
        #the 's' character informs python the token will be a string
        #the '10'(or any number) refers to width size of string characters
        
        #validates patient ID if already exists in the record
    with open('Patient_records.txt') as record_file:
            #opens file
        contents = record_file.read()
            #reads file content
        search_word = patientID
            #initialize search word to patient ID
            
            #search patient info by ID through the file content
        if search_word in contents:
            print ("\t|\t Error! Patient ID("+patientID+") already exists.")
                #error msg for already existing patient ID
        else:
            record_file = open("Patient_records.txt","a")
                #open file in append mode   
            record_file.write(patient_record_format)
                #adds new patient info to the record file
            record_file.close()
                #close file after appending
            print ("\t|\t Patient information successively saved...")
    seperator_line_format()
        #calls seperator format line
    #adds new patient to records
    
def deletePatient(patientID):
    # search through record file for patient ID to be deleted
    with open('Patient_records.txt', 'r') as record_file:
            #opens file in r/w mode
        contents = record_file.read()
            #reads file content
        search_word = patientID
            #initialize search word to patient ID
            
            #search patient info by ID through the file content
        if search_word in contents:
            #displays patient available info 
            with open('Patient_records.txt', 'r') as read_obj:
                # Read all lines in the file one by one
                for line in read_obj:
                    # For each line, check if line contains the string
                    if str(search_word) in line:
                        # line_info = line
                        
                        with open("Patient_records.txt", "r") as f:
                            lines = f.readlines()

                        with open("Patient_records.txt", "w") as f:

                            for line_specific in lines:

                                if line_specific.strip("\n") != line:
                                    f.write(line_specific)
                                    
                #deletes patient info using the ID as unique identity
            delay_optmizer1()
            print ('\t|\t Operation success! ')
            print ('\t|\t Patient information deleted')
        else:
            print ("\t|\t Error! Invalid Patient ID")
                #error msg for already existing patient ID
    seperator_line_format()
        #calls seperator format line
    #deletes patient's info from system records
    
    ####---------------------------------------------------------------
    
    
    ####-----------------main system control---------------------------
delay_optmizer1();
print("\n\t=================================================================================")
print("\t=\t\tKFUPM CLINIC SYSTEM CONTROL MENU\t\t\t\t=")
print("\t=================================================================================\n")
    #control system title format
def main():
    weight = 0
    visits = 0
    ave_weight = 0
    patientID = ""
    patient_name = ""
    patient_record_format = ""
    Ave_weight = ((weight + (ave_weight*visits)) / (visits + 1))
        #Patient average weight computation formula
        #control variables declaration
    records_title = "\t  Patient ID |\tPatient Name\t|    Weight  |\tAve. Weight  |\tVisits\t"
        #forms record file title
        #-------opening patient record file-----------
    try:
        record_file = open("Patient_records.txt")
        #opens record file if exists
    except IOError:
        record_file = open("Patient_records.txt","w")
            #declaring file object 'record_file' in write mode
            #automatically creates record file at initial program execution if does not exist
        record_file.write("\n\t=================================================================================\n")
        record_file.write("\t=\t\tKFUPM CLINIC SYSTEM CONTROL MENU\t\t\t\t   =")
        record_file.write("\n\t=================================================================================\n")
        record_file.write("\n\t--------------------------------------------------------------------------------\n")
        record_file.write(records_title)
        record_file.write("\n\t--------------------------------------------------------------------------------\n")
            #writing and formating file title
    finally:
        record_file.close()
            #close file after writing operation

    print("\t|\n\t|  -Use the provided numbers to select a control operation\n\t|\n\t|")
    delay_optmizer1();
    print("\t|\t1. Display all Patient Record.\n\t|\t2. Display the Record of a particular Patient.\n\t|\t3. Display all Patient Weight.\n\t|\t4. Update Patient.\n\t|\t5. Add New Patient.\n\t|\t6. Delete Patient.\n\t|\n\t|\t0. Exit.\n\t|")
    delay_optmizer1();
    control_choice = input("\t|\tPlease select your choice: ")
        #user control choice prompt
    print("\t|\n\t|-------------------------------------------------------------------\n\t|\n\t|")
    
    #-------------validates user input datatype-----------------------
    datatype_flag = ""
    s = control_choice
    for i in range(len(s)):
        if s[i].isdigit() != True:
            datatype_flag = "ON"
            #turns datatype check flag ON if user input is NOT an integer
        elif s[i].isdigit() == True:
            datatype_flag = "OFF"
            #turns datatype check flag OFF if user input is an integer
    #-------------end of validation-----------------------
        
    if(datatype_flag == "OFF"):
        # print("\t|\tLoading operation...\n\t|")
        delay_optmizer1();
            #short delay before loading an operatiom
        control_choice = int(control_choice)
            #converts user input to integer
        if((control_choice <= 6) and (control_choice >= 0)):
            if(control_choice == 1):
                getAllPatientRecord();
                    #calls patients info display fn
                main() 
                    #calls main function to reload the system(recursion)
                
            elif(control_choice == 2):
                print("\t|\tDisplay specific patient information\n\t|")
                patientID = str(input("\t|\t Please enter patient ID: "))
                print("\t|")
                    #prompt for patient ID
                getPatient(patientID)
                    #calls fn to display particular patient info
                main() 
                    #calls main function to reload the system(recursion)
                
            elif(control_choice == 3):
                print("\t|\tDisplay patients' weight information\n\t|")
                weight = float(input("\t|\t Please enter max. weight (Kg): "))
                    #prompts user for max patients' weight
                print("\t|")
                getWeight(weight)
                    #calls fn to display all patients weight
                main() 
                    #calls main function to reload the system(recursion)
                
            elif(control_choice == 4):
                print("\t|\tPlease enter patient details to be updated\n\t|")
                patientID = str(input("\t|\t 1. Patient ID: "))
                print("\t|")
                    #prompt for patient ID(to be used as unique key to update paient info in records)
                weight = float(input("\t|\t 2. Patient weight: "))
                print("\t|")
                    #prompt for patient new weight data
                update(patientID, weight)
                    #calls patient update fn
                main() 
                    #calls main function to reload the system(recursion)
                
            elif(control_choice == 5):
                print("\t|\tPlease enter new patient details\n\t|")
                patient_name = str(input("\t|\t 1. Patient name: "))
                print("\t|")
                    #prompt for new patient name
                patientID = str(input("\t|\t 2. Patient ID: "))
                print("\t|")
                    #prompt for new patient ID
                addPatient(patient_name, patientID)
                    #calls new patient add fn
                main() 
                    #calls main function to reload the system(recursion)
                
            elif(control_choice == 6):
                print("\t|\tDelete patient information from the record\n\t|")
                patientID = str(input("\t|\t Please enter patient ID: "))
                print("\t|")
                    #prompt for patient ID
                deletePatient(patientID)
                    #calls patient delete record fn
                main() 
                    #calls main function to reload the system(recursion)
                
            elif(control_choice == 0):
                print("\t|\tProgram exiting...\n\t|\n")
                #exits pogram operation
        else:
            print("\t|\n\t|\tError! Undefined input choice("+str(control_choice)+").\n\t|")
                #user choice validation
            seperator_line_format()
                #calls seperator format line
            main() 
                #calls main function to reload the system(recursion)
        #validates if user input is an integer
        
    elif (datatype_flag == "ON"):
        print("\t|\n\t|\tError! Invalid input("+str(control_choice)+").\n\t|")
            #user choice validation
        seperator_line_format()
            #calls seperator format line
        main() 
            #calls main function to reload the system(recursion)
        #handler if user input is NOT an integer
    #forms system main control function
    
if __name__ == '__main__':
    main()
            #making main fn as main instance of the program
            #executed first upon program start
    