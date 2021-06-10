##=============================================================
#         FORMS THE PROJECT MAIN WINDOW INSTANCE              =
#         HANDLES BOTH PYTHON2.7/3.X                          =
#							      =
#	Author: ochieno eliud				      =
#	University of Nairobi				      =
#	Dept: Elec. $ Info. Eng.			      =
#==============================================================

try:
    # for Python2
    from Tkinter import *         # imports everything from Tkinter 
    import tkMessageBox
except ImportError:
    # for Python3
    from tkinter import*         # imports everything from Tkinter 
    from tkinter import messagebox
                                 #handles python2.7/3.x interpreters
import random
import time
import datetime
import itertools
                                #imports related modules


'''
Here is the algorithm
1. Find the prime implicants
2. Make Prime implicant chart
3. Find essential prime implicants
4. Use Petrick's Method to find all solutions

'''


#compare two binary strings, check where there is one difference
def compBinary(s1,s2):
    count = 0
    pos = 0
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            count+=1
            pos = i
    if count == 1:
        return True, pos
    else:
        return False, None


#compare if the number is same as implicant term
#s1 should be the term
def compBinarySame(term,number):
    for i in range(len(term)):
        if term[i] != '-':
            if term[i] != number[i]:
                return False

    return True


#combine pairs and make new group
def combinePairs(group, unchecked):
    #define length
    l = len(group) -1

    #check list
    check_list = []

    #create next group
    next_group = [[] for x in range(l)]

    #go through the groups
    for i in range(l):
        #first selected group
        for elem1 in group[i]:
            #next selected group
            for elem2 in group[i+1]:
                b, pos = compBinary(elem1, elem2)
                if b == True:
                    #append the ones used in check list
                    check_list.append(elem1)
                    check_list.append(elem2)
                    #replace the different bit with '-'
                    new_elem = list(elem1)
                    new_elem[pos] = '-'
                    new_elem = "".join(new_elem)
                    next_group[i].append(new_elem)
    for i in group:
        for j in i:
            if j not in check_list:
                unchecked.append(j)

    return next_group, unchecked


#remove redundant lists in 2d list
def remove_redundant(group):
    new_group = []
    for j in group:
        new=[]
        for i in j:
            if i not in new:
                new.append(i)
        new_group.append(new)
    return new_group


#remove redundant in 1d list
def remove_redundant_list(list):
    new_list = []
    for i in list:
        if i not in new_list:
            new_list.append(i)
    return new_list


#return True if empty
def check_empty(group):

    if len(group) == 0:
        return True

    else:
        count = 0
        for i in group:
            if i:
                count+=1
        if count == 0:
            return True
    return False


#find essential prime implicants ( col num of ones = 1)
def find_prime(Chart):
    prime = []
    for col in range(len(Chart[0])):
        count = 0
        pos = 0
        for row in range(len(Chart)):
            #find essential
            if Chart[row][col] == 1:
                count += 1
                pos = row

        if count == 1:
            prime.append(pos)

    return prime

def check_all_zero(Chart):
    for i in Chart:
        for j in i:
            if j != 0:
                return False
    return True

#find max value in list
def find_max(l):
    max = -1
    index = 0
    for i in range(len(l)):
        if l[i] > max:
            max = l[i]
            index = i
    return index

#multiply two terms (ex. (p1 + p2)(p1+p4+p5) )..it returns the product
def multiplication(list1, list2):
    list_result = []
    #if empty
    if len(list1) == 0 and len(list2)== 0:
        return list_result
    #if one is empty
    elif len(list1)==0:
        return list2
    #if another is empty
    elif len(list2)==0:
        return list1

    #both not empty
    else:
        for i in list1:
            for j in list2:
                #if two term same
                if i == j:
                    #list_result.append(sorted(i))
                    list_result.append(i)
                else:
                    #list_result.append(sorted(list(set(i+j))))
                    list_result.append(list(set(i+j)))

        #sort and remove redundant lists and return this list
        list_result.sort()
        return list(list_result for list_result,_ in itertools.groupby(list_result))

#petrick's method
def petrick_method(Chart):
    #initial P
    P = []
    for col in range(len(Chart[0])):
        p =[]
        for row in range(len(Chart)):
            if Chart[row][col] == 1:
                p.append([row])
        P.append(p)
    #do multiplication
    for l in range(len(P)-1):
        P[l+1] = multiplication(P[l],P[l+1])

    P = sorted(P[len(P)-1],key=len)
    final = []
    #find the terms with min length = this is the one with lowest cost (optimized result)
    min=len(P[0])
    for i in P:
        if len(i) == min:
            final.append(i)
        else:
            break
    #final is the result of petrick's method
    return final

#chart = n*n list
def find_minimum_cost(Chart, unchecked):
    P_final = []
    #essential_prime = list with terms with only one 1 (Essential Prime Implicants)
    essential_prime = find_prime(Chart)
    essential_prime = remove_redundant_list(essential_prime)

    #print out the essential primes
    if len(essential_prime)>0:
        s = "\nEssential Prime Implicants :\n"
        for i in range(len(unchecked)):
            for j in essential_prime:
                if j == i:
                    s= s+binary_to_letter(unchecked[i])+' , '
        # print s[:(len(s)-3)]

        essntl_prim_impl_lbl_txt.insert(END, s[:(len(s)-3)])  


#------------------------------------------------------------------

        essntl_prim_impl.set(s[:(len(s)-3)])
                        #prints out the Essential Prime Implicants

#------------------------------------------------------------------

    #modifiy the chart to exclude the covered terms
    for i in range(len(essential_prime)):
        for col in range(len(Chart[0])):
            if Chart[essential_prime[i]][col] == 1:
                for row in range(len(Chart)):
                    Chart[row][col] = 0

    #if all zero, no need for petrick method
    if check_all_zero(Chart) == True:
        P_final = [essential_prime]
    else:
        #petrick's method
        P = petrick_method(Chart)

        #find the one with minimum cost
        #see "Introduction to Logic Design" - Alan B.Marcovitz Example 4.6 pg 213
        '''
        Although Petrick's method gives the minimum terms that cover all,
        it does not mean that it is the solution for minimum cost!
        '''

        P_cost = []
        for prime in P:
            count = 0
            for i in range(len(unchecked)):
                for j in prime:
                    if j == i:
                        count = count+ cal_efficient(unchecked[i])
            P_cost.append(count)


        for i in range(len(P_cost)):
            if P_cost[i] == min(P_cost):
                P_final.append(P[i])

        #append prime implicants to the solution of Petrick's method
        for i in P_final:
            for j in essential_prime:
                if j not in i:
                    i.append(j)

    return P_final

#calculate the number of literals
def cal_efficient(s):
    count = 0
    for i in range(len(s)):
        if s[i] != '-':
            count+=1

    return count

#print the binary code to letter
def binary_to_letter(s):
    out = ''
    c = 'a'
    more = False
    n = 0
    for i in range(len(s)):
        #if it is a range a-zA-Z
        if more == False:
            if s[i] == '1':
                out = out + c
            elif s[i] == '0':
                out = out + c+'\''

        if more == True:
            if s[i] == '1':
                out = out + c + str(n)
            elif s[i] == '0':
                out = out + c + str(n) + '\''
            n+=1
        #conditions for next operations
        if c=='z' and more == False:
            c = 'A'
        elif c=='Z':
            c = 'a'
            more = True

        elif more == False:
            c = chr(ord(c)+1)
    return out

#main function
def main():
    #get the num of variables (bits) as input
    # n_var = int(raw_input("Enter the number of variables(bits): "))
    #get the mintermss as input
    # minterms = raw_input("Enter the mintermss (ex. 0 1 2 5 9 10) : ")

#------------------------------------------------------------------

    n_var = variable.get() 
    n_varToflt = float(n_var)
    n_varToInt = int(n_varToflt)
    n_var = n_varToInt
    a = []
    #                     #gets user i/p for varibles
    if(minterms.get() == 1):
        a.append(minterm1.get())   
                                #creates a list
                                #for 1 minterm(s)
    elif(minterms.get() == 2):
        a.append(minterm1.get(), minterm2.get())   
                                #creates a list
                                #for 2 minterm(s)
    elif(minterms.get() == 3):
        a.append ([minterm1.get(), minterm2.get(), minterm3.get()])   
                                #creates a list
                                #for 3 minterm(s)
    elif(minterms.get() == 4):
        a.append ([minterm1.get(), minterm2.get(), minterm3.get(), minterm4.get()])      
                                #creates a list
                                #for 4 minterm(s)
    elif(minterms.get() == 5):
        a.append ([minterm1.get(), minterm2.get(), minterm3.get(), minterm4.get(), minterm5.get()])   
                                #creates a list
                                #for 5 minterm(s)
    elif(minterms.get() == 6):
        a.append ([minterm1.get(), minterm2.get(), minterm3.get(), minterm4.get(), minterm5.get(), minterm6.get()])   
                                #creates a list
                                #for 8 minterm(s)
    elif(minterms.get() == 7):
        a.append ([minterm1.get(), minterm2.get(), minterm3.get(), minterm4.get(), minterm5.get(), minterm6.get(), minterm7.get()])   
                                #creates a list
                                #for 7 minterm(s)
    elif(minterms.get() == 8):
        a.append ([minterm1.get(), minterm2.get(), minterm3.get(), minterm4.get(), minterm5.get(), minterm6.get(), minterm7.get(), minterm8.get()])    
                                #creates a list
                                #for 8 minterm(s)

    #                     #gets user i/p for minterms from the list
    
    # num1 = variable.get()
    # num2 = minterms.get()

    # sum = num1 + num2

    # prim_imp.set(sum)

    # essntl_prim_impl.set(num1 - num2)

    # ans.set(num1 * num2)

     

#------------------------------------------------------------------

    #a = minterms_lst.split()
    #put the numbers in list in int form

    #a = map(int, a)

    #make a group list
    group = [[] for x in range(n_var+1)]

    for i in range(len(a)):
        #convert to binary
        print("\n\tTest")
        print(a)
        print("\n\tTest")
        if type(a[i]) is list:
            for j in range(len(a[i])):
                print("\n\tTest")
                print(a[i][j])
                print("\n\tTest")
                print(bin(a[i][j])[2:])
                a[i][j] = bin(a[i][j])[2:]

                if len(a[i][j]) < n_var:
                    #add zeros to fill the n-bits
                    for j in range(n_var - len(a[i][j])):
                        a[i][j] = '0'+ a[i][j]
                #if incorrect input
                elif len(a[i][j]) > n_var:
                    print ('\nError : Choose the correct number of variables(bits)\n')
                    return

            else:
                a[i] = bin(a[i])[2:]
                if len(a[i]) < n_var:
                    #add zeros to fill the n-bits
                    for j in range(n_var - len(a[i])):
                        a[i] = '0'+ a[i]
                #if incorrect input
                elif len(a[i]) > n_var:
                    print ('\nError : Choose the correct number of variables(bits)\n')
                    return

        #count the num of 1
        index = a[i].count('1')
        #group by num of 1 separately
        group[index].append(a[i])


    all_group=[]
    unchecked = []
    #combine the pairs in series until nothing new can be combined
    while check_empty(group) == False:
        all_group.append(group)
        next_group, unchecked = combinePairs(group,unchecked)
        group = remove_redundant(next_group)

    s = "\nPrime Implicants :\n"
    for i in unchecked:
        s= s + binary_to_letter(i) + " , "
    print s[:(len(s)-3)]

    prim_imp_lbl_txt.insert(END, s[:(len(s)-3)])   


#------------------------------------------------------------------

    print(prim_imp.set(s[:(len(s)-3)]))
                 #make the prime implicant chart

#------------------------------------------------------------------


    Chart = [[0 for x in range(len(a))] for x in range(len(unchecked))]

    for i in range(len(a)):
        for j in range (len(unchecked)):
            #term is same as number
            if compBinarySame(unchecked[j], a[i]):
                Chart[j][i] = 1

    #prime contains the index of the prime implicant terms
    #prime = remove_redundant_list(find_minimum_cost(Chart))
    primes = find_minimum_cost(Chart, unchecked)
    primes = remove_redundant(primes)


    print "\n--  Answers --\n"

    for prime in primes:
        s=''
        for i in range(len(unchecked)):
            for j in prime:
                if j == i:
                    s= s+binary_to_letter(unchecked[i])+' + '
        print s[:(len(s)-3)]

        ans_lbl_txt.insert(END, s[:(len(s)-3)])  

#------------------------------------------------------------------

        print(ans.set(s[:(len(s)-3)]))
                            #prints out the ans

 

#------------------------------------------------------------------

def q1Reset():
        q1Reset = tkMessageBox.askyesno("Reset Entry Form","All entry fields in your current working form will be cleared.\n\nDo you want to proceed on?")
                            #user prompt
        if q1Reset > 0:
            variable.set("")
            minterms.set("")
                            #resets the window

def q2Reset():
        q1Reset = tkMessageBox.askyesno("Reset Entry Form","All entry fields in your current working form will be cleared.\n\nDo you want to proceed on?")
                            #user prompt
        if q1Reset > 0:
            essntl_prim_impl.set("")
            prim_imp.set("")
            ans.set("")
                            #resets the window

def qExit():
    qExit = tkMessageBox.askyesno("Quit System"," Do you want to quit?")
    if qExit > 0:
        root.destroy()
        return          #------------------------------------------------|
                        #quit functionself upon user 'yes' confirmation. |
                        #kills the running instance (root)               |
                        #------------------------------------------------|


                        #-----------------------------------------------------|
                        #         WINDOW 1 STYLING                            |
                        #-----------------------------------------------------|

def qWindow():
    Header.pack(side=TOP)
    main_frame.pack_forget()
    frame2.pack()
    bottom_frame.pack()
    root.title("-Boolean Minimizer")
    root.config(bg = "#d6d6c2")
                #fns dfn for 1st frame window
                #------------selected system authentication---------------------


root = Tk()             #main window instance employing tkinter module fn
root.geometry("1200x1000+0+0")
                        #window geometrical size dfn(1280 by 750) from coordinate points (0,0)
root.title("-Boolean Minimizer")
                        #main window title
root.config(bg = "#d6d6c2", )
                        #main window bg color

                        ##=============================================================
                        #        MAIN FRAMES                                          =
                        #==============================================================
Header = Frame(root, width=1280, height=100, bd=12, relief="raised")
                        #frame forms the window Headerright
Header.pack(side=TOP)

Header_info = Label(Header, font=("arial", 20), text="Boolean Minimizer System\t", bd=10, fg="#222", bg="#d6d6c2", width=60, relief="sunken")
Header_info.grid(row=0, column=0)
                        #window title information
main_frame = Frame(root, width=1300, heigh=1000, padx=8, pady=10,  bd=8, relief="groove")
main_frame.pack(side=TOP)

left_frame = Frame(main_frame, width=1200, height=800, padx= 12, pady=8, bd=12, relief="flat")
left_frame.pack(side=TOP)
                        #sub-frame in 'left_frame' section in top position
bottom_frame = Frame(root, width=1300, height=180, padx= 6, pady=8, bd=12, relief="flat")
bottom_frame.pack(side=BOTTOM)
                        #sub-frame in 'left_frame' section in top position


                        #----------------------------------------------------------|
                        #       TOP WINDOW CONTENT                                 |
                        #----------------------------------------------------------|
variable = IntVar()
minterms = IntVar()
                    #variables dfn
variable.set("between 1 to 8")

row_val = IntVar();
col_val = IntVar();
minterm1 = IntVar()
minterm2 = IntVar()
minterm3 = IntVar()
minterm4 = IntVar()
minterm5 = IntVar()
minterm6 = IntVar()
minterm7 = IntVar()
minterm8 = IntVar()
def qMinterms():
    for i in range(minterms.get()):
        if(i == 0):
            row_val = 11;
            col_val = 1;
            minterms_lbl_txt = Entry(left_frame, bd=8, bg="#fff", fg="#555", font=("arial", 14), justify="left", width=5, textvariable=minterm1)
            minterms_lbl_txt.grid(row=row_val, column=col_val, sticky=W)
            #setting row and column values
        elif(i == 1):
            row_val = 11;
            col_val = 2;
            minterms_lbl_txt = Entry(left_frame, bd=8, bg="#fff", fg="#555", font=("arial", 14), justify="left", width=5, textvariable=minterm2)
            minterms_lbl_txt.grid(row=row_val, column=col_val, sticky=W)
            #setting row and column values
        elif(i == 2):
            row_val = 11;
            col_val = 3;
            minterms_lbl_txt = Entry(left_frame, bd=8, bg="#fff", fg="#555", font=("arial", 14), justify="left", width=5, textvariable=minterm3)
            minterms_lbl_txt.grid(row=row_val, column=col_val, sticky=W)
            #setting row and column values
        elif(i == 3):
            row_val = 12;
            col_val = 1;
            minterms_lbl_txt = Entry(left_frame, bd=8, bg="#fff", fg="#555", font=("arial", 14), justify="left", width=5, textvariable=minterm4)
            minterms_lbl_txt.grid(row=row_val, column=col_val, sticky=W)
            #setting row and column values
        elif(i == 4):
            row_val = 12;
            col_val = 2;
            minterms_lbl_txt = Entry(left_frame, bd=8, bg="#fff", fg="#555", font=("arial", 14), justify="left", width=5, textvariable=minterm5)
            minterms_lbl_txt.grid(row=row_val, column=col_val, sticky=W)
            #setting row and column values
        elif(i == 5):
            row_val = 12;
            col_val = 3;
            minterms_lbl_txt = Entry(left_frame, bd=8, bg="#fff", fg="#555", font=("arial", 14), justify="left", width=5, textvariable=minterm6)
            minterms_lbl_txt.grid(row=row_val, column=col_val, sticky=W)
            #setting row and column values
        elif(i == 6):
            row_val = 13;
            col_val = 1;
            minterms_lbl_txt = Entry(left_frame, bd=8, bg="#fff", fg="#555", font=("arial", 14), justify="left", width=5, textvariable=minterm7)
            minterms_lbl_txt.grid(row=row_val, column=col_val, sticky=W)
            #setting row and column values
        elif(i == 7):
            row_val = 13;
            col_val = 2;
            minterms_lbl_txt = Entry(left_frame, bd=8, bg="#fff", fg="#555", font=("arial", 14), justify="left", width=5, textvariable=minterm8)
            minterms_lbl_txt.grid(row=row_val, column=col_val, sticky=W)
            #setting row and column values




hspace_lbl = Label(left_frame, text="", bg="#d6d6c2")
hspace_lbl.grid(row=0, column=0, sticky=W)
                    #creates a hspace btn labels
hspace_lbl = Label(left_frame, text="", bg="#d6d6c2")
hspace_lbl.grid(row=1, column=0, sticky=W)
                    #creates a hspace btn labels
header_lbl = Label(left_frame, text="Enter: ", bg="#d6d6c2",  fg="#222",  bd=8, font=("arial", 14, 'bold'))
header_lbl.grid(row=2, column=0, sticky=W)
                    #creates a hspace btn labels
hspace_lbl = Label(left_frame, text="", bg="#d6d6c2")
hspace_lbl.grid(row=3, column=0, sticky=W)
                    #creates a hspace btn labels
variable_lbl = Label(left_frame, text=" 1. Number of variables ", bg="#d6d6c2",  fg="#555",  bd=8, font=("arial", 14))
variable_lbl.grid(row=4, column=0, sticky=W)
variable_lbl_txt = Entry(left_frame, bd=8, bg="#fff", fg="#555", font=("arial", 14), justify="left", width=18, textvariable=variable)
variable_lbl_txt.grid(row=4, column=1, sticky=W)
                    #1st prompt for variables
hspace_lbl = Label(left_frame, text="", bg="#d6d6c2")
hspace_lbl.grid(row=5, column=0, sticky=W)
                    #creates a hspace btn labels
hspace_lbl = Label(left_frame, text="", bg="#d6d6c2")
hspace_lbl.grid(row=6, column=0, sticky=W)
                    #creates a hspace btn labels
minterms_lbl = Label(left_frame, text=" 2. minterms ", bg="#d6d6c2",  fg="#555",  bd=8, font=("arial", 14))
minterms_lbl.grid(row=8, column=0, sticky=W)

minterms_lbl = Label(left_frame, text="\tEnter the number of minterms ", bg="#d6d6c2",  fg="#555",  bd=8, font=("arial", 14))
minterms_lbl.grid(row=9, column=0, sticky=W)

numOf_minterms_lbl_txt = Entry(left_frame, bd=8, bg="#fff", fg="#555", font=("arial", 14), justify="left", width=5, textvariable=minterms)
numOf_minterms_lbl_txt.grid(row=9, column=1, sticky=W)
ans_right_frame_btn = Button(left_frame, padx=4, pady=6, bd=4, text="Minterms", width=8, fg="#fff", bg="#737373", cursor="hand2", font=("arial", 12, 'bold'), command=qMinterms)
ans_right_frame_btn.grid(row=9, column=2)
                     #reset btn for top window
hspace_lbl = Label(left_frame, text="", bg="#d6d6c2")
hspace_lbl.grid(row=10, column=0, sticky=W)
                    #creates a hspace btn labels

# hspace_lbl = Label(left_frame, text="", bg="#d6d6c2")
# hspace_lbl.grid(row=12, column=0, sticky=W)
#                     #creates a hspace btn labels
# hspace_lbl = Label(left_frame, text="", bg="#d6d6c2")
# hspace_lbl.grid(row=12, column=1, sticky=W)
#                     #creates a hspace btn labels


                        #----------------------------------------------------------|
                        #       BOTTOM WINDOW CONTENT                              |
                        #----------------------------------------------------------|
essntl_prim_impl = IntVar()
prim_imp = IntVar()
ans = IntVar()
                    #variables dfn
frame2 = Frame(root, width=1300, height=1000, padx=8, pady=10,  bd=8, relief="groove")
frame2.config(bg = "#d6d6c2")
                    #frame2      
right_frame = Frame(frame2, width=1200, height=900, padx= 12, pady=8, bd=12, relief="flat")
right_frame.pack(side=TOP)
                        #sub-frame in 'left_frame' section in top position

                        #----------------------------------------------------------|
                        #       MAIN FRAMES CONFIGURATION                          |
                        #----------------------------------------------------------|

right_frame.config(bg="#d6d6c2")


hspace_lbl = Label(right_frame, text="", bg="#d6d6c2")
hspace_lbl.grid(row=0, column=0, sticky=W)
                    #creates a hspace btn labels

# S = Scrollbar(right_frame)
# S.pack(side=RIGHT, fill=Y)

prim_imp_lbl = Label(right_frame, text=" 1. Prime Implicants", bg="#d6d6c2", fg="#222",  bd=8, font=("arial", 14))
prim_imp_lbl.grid(row=1, column=0, sticky=W)
prim_imp_lbl_txt = Text(right_frame, bd=8, bg="#fff", fg="#555", font=("arial", 14), height=3, width=40)
prim_imp_lbl_txt.grid(row=1, column=1, sticky=W)
                    #1st prompt for variables

hspace_lbl = Label(right_frame, text="", bg="#d6d6c2")
hspace_lbl.grid(row=2, column=0, sticky=W)
                    #creates a hspace btn labels
essntl_prim_impl_lbl = Label(right_frame, text=" 2. Essential Prime Implicants ", bg="#d6d6c2",  fg="#222",  bd=8, font=("arial", 14))
essntl_prim_impl_lbl.grid(row=3, column=0, sticky=W)
essntl_prim_impl_lbl_txt = Text(right_frame, bd=8, bg="#fff", fg="#555", font=("arial", 14), height=3, width=40)
essntl_prim_impl_lbl_txt.grid(row=3, column=1, sticky=W)
                    #1st prompt for mintermss
hspace_lbl = Label(right_frame, text="", bg="#d6d6c2")
hspace_lbl.grid(row=4, column=0, sticky=W)
                    #creates a hspace btn labels
ans_lbl = Label(right_frame, text=" 3. Answer", bg="#d6d6c2",  fg="#222",  bd=8, font=("arial", 14))
ans_lbl.grid(row=5, column=0, sticky=W)
ans_lbl_txt = Text(right_frame, bd=8, bg="#fff", fg="#555", font=("arial", 14), height=3, width=40)
ans_lbl_txt.grid(row=5, column=1, sticky=W)
                    #1st prompt for mintermss
hspace_lbl = Label(right_frame, text="", bg="#d6d6c2")
hspace_lbl.grid(row=6, column=0, sticky=W)
                    #creates a hspace btn labels
hspace_lbl = Label(right_frame, text="", bg="#d6d6c2")
hspace_lbl.grid(row=7, column=0, sticky=W)
                    #creates a hspace btn labels
hspace_lbl = Label(right_frame, text="", bg="#d6d6c2")
hspace_lbl.grid(row=8, column=0, sticky=W)
                    #creates a hspace btn labels
result_btn = Button(right_frame, padx=4, pady=10, bd=4, text="Result ", width=8, fg="#fff", bg="#737373", cursor="hand2", font=("arial", 12, 'bold'), command=main)
result_btn.grid(row=8, column=1)
                         #reset btn for top window
back_btn = Button(right_frame, padx=4, pady=10, bd=4, text="Reset ", width=8, fg="#fff", bg="#737373", cursor="hand2", font=("arial", 12, 'bold'), command=q2Reset)
back_btn.grid(row=8, column=2)
                         #reset btn for top window
reset_right_frame_btn = Button(right_frame, padx=4, pady=10, bd=4, text="Back ", width=8, fg="#fff", bg="#737373", cursor="hand2", font=("arial", 12, 'bold'), command=qWindow1)
reset_right_frame_btn.grid(row=8, column=3)
                         #reset btn for top window
ans_right_frame_btn = Button(bottom_frame, padx=4, pady=10, bd=4, text="Next ", width=8, fg="#fff", bg="#737373", cursor="hand2", font=("arial", 12, 'bold'), command=qWindow2)
ans_right_frame_btn.grid(row=0, column=2)
                     #reset btn for top window
reset_right_frame_btn = Button(bottom_frame, padx=4, pady=10, bd=4, text="Reset ", width=8, fg="#fff", bg="#737373", cursor="hand2", font=("arial", 12, 'bold'), command=q1Reset)
reset_right_frame_btn.grid(row=0, column=3)
                    #reset btn for top window
exit_right_frame_btn = Button(bottom_frame, padx=4, pady=10, bd=4, text="Exit ", width=8, fg="#fff", bg="#737373", cursor="hand2", font=("arial", 12, 'bold'), command=qExit)
exit_right_frame_btn.grid(row=0, column=4)
                         #reset btn for top window
hspace_lbl = Label(bottom_frame, text="", bg="#d6d6c2")
hspace_lbl.grid(row=4, column=0, sticky=W)
                    #creates a hspace btn labels

                        #----------------------------------------------------------|
                        #       MAIN FRAMES CONFIGURATION                          |
                        #----------------------------------------------------------|
Header.config(bg="#d6d6c2")
main_frame.config(bg="#d6d6c2")
left_frame.config(bg="#d6d6c2")
bottom_frame.config(bg="#d6d6c2")

root.mainloop();
			       #infinite loop keeps the main window instance statically displayed on the screen
