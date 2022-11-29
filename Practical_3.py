#Code By Atharva J Khodke 21481 SE4 H4
'''Write a Python program to compute following computation on matrix:
a) Addition of two matrices B) Subtraction of two matrices
c) Multiplication of two matrices d) Transpose of a matrix'''

def matrix_add(A,n1,B,n2):
    res=[[0,0,0],
        [0,0,0],
        [0,0,0]]
    for i in range(n1):
        for j in range(n2):
            res[i][j]=A[i][j]+B[i][j]
    return res
def matrix_subs(A,n1,B,n2):
    res=[[0,0,0],
        [0,0,0],
        [0,0,0]]
    for i in range(n1):
        for j in range(n2):
            res[i][j]=A[i][j]-B[i][j]
    return res
def matrix_multiply(A,B):
    res=[[0,0,0],
        [0,0,0],
        [0,0,0]]
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                res[i][j]+=A[i][k]*B[k][j]
    return res
def matrix_transpose(A):
    res=[[0,0,0],
        [0,0,0],
        [0,0,0]]
    for i in range(len(A)):
        for j in range(len(A[0])):
            res[j][i]=A[i][j]
    return res
def display(res):
    for i in range(len(res)):
        for j in range(len(res[i])):
            print(res[i][j],end=" ")
        print()

def input_matrix():
    print('Inset elements in to 1st matrix as per below shown sequence:\n')
    print(''' Matrix=[[1,2,3],
        [4,5,6],
        [7,8,9]]''')
    A=[ [1,2,3],
    [4,5,6],
    [7,8,9]]
    B=[ [1,2,3],
    [4,5,6],
    [7,8,9]]
    n=0
    for i in range(3):
        for j in range(3):
            num=int(input('Insert element in 1st matrix: '))
            A[i][j]=num
    print("\nInsert number into 2nd matrix following above sequence: \n")
    for i in range(3):
        for j in range(3):
            num=int(input('Insert element in 2nd matrix: '))
            B[i][j]=num
    return A,B

#main
# A=[ [1,2,3],
#     [4,5,6],
#     [7,8,9]]
# B=[ [10,11,12],
#     [13,14,15],
#     [16,17,18]]
res=[]
A,B=input_matrix()
print("#############################################")
print("#############################################")
print("\nYou have entered 1st matrix as below: ")
display(A)
print("\nYou have entered 2nd matrix as below: ")
display(B)

print("\nAdding matrices A+B: ")
res=matrix_add(A,3,B,3)
display(res)

print("\nSubtracting matrices B-A: ")
res2=matrix_subs(B,3,A,3)
display(res2)

print("\nMultiplying matrices A*B: ")
res4=matrix_multiply(A,B)
display(res4)

print("\nTranspose of 1st matrix A: ")
res3=matrix_transpose(A)
display(res3)

print("\nTranspose of 2nd matrix B: ")
res5=matrix_transpose(B)
display(res5)

C=[]