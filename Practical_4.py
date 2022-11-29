#Code By Atharva J Khodke 21481 SE4 H4
'''
Write a program to implement
sequential search
sentinel search
Binary iterative search
Binary Recurrsive Search
'''

def seqSearch(a,n,x):
    for i in range(n):
        if (a[i]==x):
            return i
    return  -1  

def sentinelSearch(a,n,x):
    a.append(x)
    i=0
    while(a[i]!=x):
        i+=1
    if(i<n):
        return i
    else:
        return -1
    
def Bsearch_p(a,n,x):
    low=0
    high=n-1
    while(low<high):
        mid=(high+low)//2
        if (a[mid]==x):
            return mid
        elif(x<a[mid]):
            high=mid-1
        else:
            low=mid+1
    if(a[low]==a[high]):
        return low
    else:
        return -1


def Bsearch_recur(a,n,x,low,high):
    if(low==high):
        if a[low]==x:
            return low
        else:
            return -1
    mid=(high+low)//2
    if(x==a[mid]):
        return mid
    elif(x<a[mid]):
        return Bsearch_recur(a,n,x,low,mid-1)
    elif(x>a[mid]):
        return Bsearch_recur(a,n,x,mid+1,high)


def display(i):
    if i>-1:
        print("Element found at index: ",i)
    else:
        print("Element not flound.")




def menu():
    
    loop=True
    while loop==True:
        a=[]
        countofarr=int(input("Enter count of elemnt you want to add in array: "))
        for i in range(countofarr):
            inn=int(input("Enter element at index = "))
            a.append(inn)
        while True:
            x=int(input("Enter Element you want to search: "))

            print("\nSelect Searching Method:")
            print("1.Sequential Search")
            print("2.Sentinel Search")
            print("3.Binary Procedural Search")
            print("4.Binary Recursive Search\n")
            
            user_in=input("Enter Choice number: ")
            
            if user_in=="1":
                res=seqSearch(a,countofarr,x)
                display(res)

            
            if user_in=="2":
                res=sentinelSearch(a,countofarr,x)
                display(res)

            
            if user_in=="3":
                res=Bsearch_p(a,n,x)
                display(res)

            
            if user_in=="4":
                res=Bsearch_recur(a,countofarr,x,0,countofarr)
                display(res)
            
            user_end1=input("\n\nPress R to try another searching techniques, Press S to re-enter array , Press Q to quit: ")
            if user_end1.upper()=="R":
                continue
            if user_end1.upper()=="S":
                break
            elif user_end1.upper()=="Q":
                loop=False
        

a =[5,6,7,8,9,10,11]
n=7
x= 10

#i=Bsearch_p(a,n,x)
# i=Bsearch_recur(a,n,x,0,n)
# display(i)
menu()