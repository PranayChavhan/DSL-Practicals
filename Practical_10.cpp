//============================================================================
// Name        : assignment10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template<class T>
class Stack
{
    int top;
    int size;
    T *s;

public:
    Stack(int k)
    {
        size = k;
        top = -1;
        s = new T[size];
    }

    void push(char x)
    {
        if (top == (size - 1))
        {
            cout << "Stack OverFlow" << endl;
        }
        else
        {
            top++;
            s[top] = x;
        }
    }

    char pop()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        else
        {
            T k = s[top];
            top = top - 1;
            return k;
        }
    }

    void Display()
    {
        for (int i = top; i > -1; i--)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }

    bool isempty()
    {
        if (top == -1)
        {
            return true;
        }
        else
            return false;
    }

    bool isfull()
    {
        if (top == size - 1)
        {
            return true;
        }
        else
            return false;
    }
    T gettop()
    {
        return s[top];
    }
};

bool isOperand(char a){
if(a=='+' || a=='-'|| a=='/'||a=='*'||a=='('||a==')'){
return false;
}
else return true;
}

int pre(char a){
if(a=='+' || a=='-'){
return 1;
}
else if( a=='/'||a=='*'){
return 2;
}
else if( a=='('){
return 3;
}

}

string inTopost(string s){
string post ="";
Stack <char> st(100);
    int n=s.size();
for(int i=0;i<n;i++){

if(isOperand(s[i])){
post=post + s[i];
}
else if(s[i]==')'){
while(st.gettop()!='('){
post=post+st.pop();
}
st.pop();
}
else{
if(st.isempty()){
st.push(s[i]);
}
else{
                    while(!st.isempty()&& st.gettop()!='(' && pre(s[i])<=pre(st.gettop())){
post=post+ st.pop();;
                    }
st.push(s[i]);

}
}
}
while(!st.isempty()){
post=post+st.gettop();
st.pop();
}

return post;

}


int Evaluatepost(string s){
Stack <int> st(100);
int n=s.size();
for(int i=0;i<n;i++){
if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')){
cout<<"Enter the value of "<<s[i]<<endl;
int t;
cin>>t;
st.push(t);
}

else{
int x1,x2,r;
x2=st.pop();
x1=st.pop();

switch(s[i])
{
case '+':
r=x1+x2;
st.push(r);
break;
case '-':
r=x1-x2;
st.push(r);
break;
case '*':
r=x1*x2;
st.push(r);
break;
case '/':
r=x1/x2;
st.push(r);
break;

default:
break;
}
}
}
return st.pop();
}

int main(){

string s;
    cout << "Enter the Expression" << endl;
    cin >> s;


    cout<<"------------------ Menu -----------------------"<<endl;
    cout<<"1.Display the Postfix Expresion for the input."<<endl;
    cout<<"2.Evaluate the expresion by taking some integer values of the variables."<<endl;
    cout<<"0.Exit the Program."<<endl;
    cout<<"-----------------------------------------------"<<endl;
    int choice;
    while(true){
        cout<<"Enter the Choice."<<endl;
        cin>>choice;
        if(choice==1){
            cout<<"The postfix Expresion of the Entered infix Exp. is :-- ' "<<inTopost(s)<<" '"<<endl;
        }
        else if(choice==2){
           string a=inTopost(s);
           int k=Evaluatepost(a);
           cout<<"The Final ans of the Expresion according to the entered varialbles is :-- "<<k<<endl;
        }
        else if(choice==0){
            cout<<"__ __ __ __ __ __-!!ThankYou!!-__ __ __ __ __ __"<<endl;
            break;
        }
        else{
            cout<<"Choice Out Of Range!!!!"<<endl;
        }
    }

return 0;
}
