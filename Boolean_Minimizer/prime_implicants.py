
num_of_var=int(input("\n\tEnter the number of variables(between 1-8) ="))
if((num_of_var > 8) or (num_of_var < 1)):
    print("\n\tThe entered value is not within the required range\n")
    num_of_var=int(input("\n\tEnter the number of variables(between 1-8) ="))

num_of_min_terms=int(input("\n\tEnter the number of minterms ="))
#-------------------initializing------------
min_terms=[]
min_term_dir={}
for i0 in range (num_of_var+1):
    min_term_dir[i0]={}
#-----------------User inputs --------------
i0=0
while i0 <num_of_min_terms:
    print("enter the min term",i0," =",end='')
    y=int(input())
    x=bin(y)[2:]
    if len(x)<=num_of_var:
        x='0'*(num_of_var-len(x)) + x
        count_1=x.count('1')
        min_terms+=[x]
        min_term_dir[count_1][y]=x
        i0+=1
    else:
        print("Wrong in put")
#print(min_term_dir)
#--------------Processing------------------------
check_set=set([1,2,3])
prime_im=()
X=min_term_dir
all_ele=set()
used_ele=set()
roots_of_ele={}
while len(check_set)>0:
    Y={}
    check_set=set()
    new_len_of_tab=len(X)-1
    for i in range (new_len_of_tab):
        Y[i]={}
    for i in range(new_len_of_tab):
        checking_set1=X[i]
        checking_set2=X[i+1]
        p=checking_set1.keys()
        
        for j in checking_set1.keys():
            J=checking_set1[j]
            all_ele.add(J)
            
            for k in checking_set2.keys():
                K=checking_set2[k]
                all_ele.add(K)
                unmatch=0
                
                for count in range (num_of_var):
                    
                    if J[count]!=K[count]:
                        unmatch +=1
                        unmatch_location=count
                    if unmatch >1:
                        break
                
                if unmatch==1:
                    new_K=K[:unmatch_location]+'X'+K[unmatch_location+1:]
                    used_ele.add(K)
                    used_ele.add(J)
                    check_set.add(str(j)+','+str(k))
                    Y[i][str(j)+','+str(k)]=new_K
                    
                    if new_K in roots_of_ele.keys():
                        roots_of_ele[new_K]+=[j,k]
                    else:
                        roots_of_ele[new_K]=[j,k]
                    if K in roots_of_ele.keys():
                        del roots_of_ele[K]
                    if J in roots_of_ele.keys():
                        del roots_of_ele[J]
    X=Y
    
prime_im=all_ele
used_ele=list(used_ele)
for i in used_ele:
    prime_im.discard(i)
print(prime_im)
print(roots_of_ele)
                    

                
    
