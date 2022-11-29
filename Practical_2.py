#Code By Atharva J Khodke 21481 SE4 H4
'''Write a Python program to compute following operations on String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular character in the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string'''


def lenofstr(str):
    str=str+"$"
    flag= True
    i=0 
    count=0
    
    while str[i]!='$':
       count+=1
       i+=1
    return count
     
def addletter(str,start,end):
    word=""
    for i in range(start,end):
        word=word+str[i];
    #print(word)
    return word

def strtolist(str):
    len=lenofstr(str)
    newlist=[]
    start=0
    end=0
    count=0
    str=str+" "
    print(str)
    for i in range(len+1):
        if (str[i]==" " ) :
            newlist.append(addletter(str,start,i))
            start=i+1
            count+=1
    #print(newlist, count)
    return newlist,count
   
def longest_word(list,listlen):
    print(list)
    wcountmax=0
    wcount=0
    indexofmax=0
    for i in range(listlen):
        wordlen=lenofstr(list[i])
        wcount=0
        for j in range(wordlen):
            wcount+=1
        if wcount>wcountmax:
            wcountmax=wcount
            indexofmax=i
    return indexofmax,wcountmax
    

def charoccurance(str):
    c=input("Enter a character you want to search times of occurance in string: ")
    c=c.upper()
    str=str.upper()
    len=lenofstr(str)
    count=0
    for i in range(len):
        if str[i]==c:
            count+=1
    print(count)

def reversestr(str,n):# reverses the strig passed to this and return reversedd string
    rev_str=""
    for i in range(n):
        rev_str=str[i]+rev_str
    return rev_str

def palindrome(str):
    str=str.lower()
    n=lenofstr(str)
    rev=reversestr(str,n)
    ispalindrom=False
    for i in range(n):
        if str[i]==rev[i]:
            ispalindrom=True
            
            
        else:
            ispalindrom=False
            break
    if ispalindrom==True:
        print("The entered string '",str,"' is Palindrome")
    else:
        print("The entered string '",str,"' is not a Palindrome")
        
def substring_appear(str,substr):
    str=str.lower()
    substr=substr.lower()
    n1=lenofstr(str)
    n2=lenofstr(substr)
    index=0
    flag=False
    for i in range(n1):
        if str[i]==substr[0]:
            index=i
            flag=True
            for j in range(1,n2):
                if str[i+j]!=substr[j]:
                    flag=False
                    index=0
                    break
    print(index,flag)

def sameoccur_index(strlist,n1,newlist,n2):
    countlist=[]
    newlist.append(strlist[0])
    n2=1
    countlist.append(1)
    for i in range(1,n1):
        flag=False
        for j in range(n2):
            
            if strlist[i]==newlist[j]:
                tofill=countlist[j]+1
                countlist.pop(j)
                countlist.insert(j,tofill)
                flag=True
                break
        if flag==False:
            newlist.append(strlist[i])
            n2=n2+1
            countlist.append(1)
    return newlist,countlist,n2
                
            
def occurance_check(str):
    str=str.lower()
    strlist,countofstrlist=strtolist(str)
    newlist=[]
    newlist,countlist,len_newlist=sameoccur_index(strlist,countofstrlist,newlist,0)
    print("Occurence of each charaters are as follows: ")
    for i in range(len_newlist):
        print("\n\"",newlist[i],"\"    \toccurs ",countlist[i]," times.")

if __name__=="__main__":
    #1.longest length word 
    #2.occurence of charater
    #3.string palindrome
    #4.index frist appearc substring
    #5.occur of each word
    flag=True
    
    while flag:
        givenstr=input("Enter the string: ")
        strlist,listlen=strtolist(givenstr)
        while True:
            print("\nChoose a option :")

            print("\f1. Find word having longest length?")
            print("\f2. Find occurence of a character?")
            print("\f3. Find if entered string is palindrome?")
            print("\f4. Find substring in given string (returns index if found)?")
            print("\f5. Find occurence of each word in string?")
            user_in=int(input("\n\fEnter your option(number): "))
            if user_in==1:
                longestwordindex,longwordlen=longest_word(strlist,listlen)
                print("The longest word is ",strlist[longestwordindex]," at position= ",longestwordindex," length = ",longwordlen)
            elif user_in==2:
                charoccurance(givenstr)
            elif user_in==3:
                palindrome(givenstr)
            elif user_in==4:
                substr=input("Enter the sub string: ")
                substring_appear(givenstr,substr)
            elif user_in==5:
                occurance_check(givenstr)
            
            user_end_in=input("\n\nWant to return to menu (press M), For Restart (Press R), For Quiting (Press Q): ")
            if user_end_in.upper()=="Q":
                flag=False
                break
            if user_end_in.upper()=="R":
                break
            if user_end_in.upper()=="M":
                continue



    
    
    
    
    
    # str="White goat eat yellow grass and another white goat eat green grass"




