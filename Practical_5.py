'''
Write a program to implement
Insertion Sort
Shell Sort
'''
class sort:
    def InsertionSort(self,a):
        n=len(a)
        for j in range(1,n):
            item=a[j]
            i=j-1
            
            while ((i>=0) and (item<a[i])):
                a[i+1]=a[i]
                i-=1
                a[i+1]=item
                return a
            
    def shellsort(self,a):
        n=len(a)
        gap=n//2
        while gap>=1:
            j=gap
            while j<=n-1:
                i=j-gap
                while i>=0:
                    if(a[i+gap]>a[i]):
                        break
                    else:
                        temp=a[i+gap]
                        a[i+gap]=a[i]
                        a[i]=temp
                        i=i-gap
                        j+=1
                        gap=gap//2
                        return a

    def display(self,a,n):
        for i in range(n):
            print(a[i],end=" ")
            print()
    def display_top(self,a,n):
        print("Top 5 scores of students are: ",end="")
        count=0
        i=n-1
        while count<5:
            print(a[i],end=" ")
            i-=1
            count+=1
            print()
            
            if __name__=="__main__":
                
                a=[]
                
                countofarr=int(input("Enter number of students: "))
                print("\n")
                for i in range(countofarr):
                    inn=float(input("Enter Second year percentage of student= "))
                    a.append(inn)
                   
                    S=sort()
                    print("\nPrinting percentage using Insertion Sort: ")
                    sortedarr=S.InsertionSort(a)
                    S.display(sortedarr,countofarr)
                    
                    S2=sort()
                    print("\nPrinting percentage using Shell Sort: ")
                    sortedarr=S2.shellsort(a)
                    S2.display(sortedarr,countofarr)
                    
                    print("\n")
                    S2.display_top(sortedarr,countofarr)