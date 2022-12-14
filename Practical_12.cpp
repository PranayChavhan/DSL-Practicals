//============================================================================
// Name        : assignment12.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream>
using namespace std;

class job
{
   string id_name;
   int pri;
   public:

  friend bool operator >=(job &obj1, job &obj2);
   int getpri(){
    return pri;
   }
   string getname(){
    return id_name;
   }
   void setdata(){
    cout<<"Enter Employee ID/Name ";
    cin>>id_name;
    cout<<"Enter Employee Priority ";
    cin>>pri;
   }

   void Display(){
    cout<<id_name<<"\t\t"<<pri<<endl;
   }

};

bool operator>=(job &obj1, job &obj2){
   if(obj1.getpri()>=obj2.getpri()){
      return true;
    }
    else{
      return false ;
    }
}

class PriQueue{
    int fr,re;
    job Q[100];
    int size=100;
    public:
    PriQueue(){
      fr=re=-1;
    }
    bool isEmpty(){
      if(fr==-1 || fr==re+1){
        return true;
      }
      else{
        return false;
      }
    }
    bool isFull(){
      if(re==size-1){
        return true;
      }
      else return false;
    }

    void enqueue(job ele){
      if(isFull()){
        cout<<"Queue is Full!!"<<endl;
      }
      else if(fr==-1){
        fr=0;
        re=0;
        Q[re]=ele;

      }
      else{
        re++;
        int j=re-1;
        while(ele.getpri()>=Q[j].getpri() && j>=0){
          Q[j+1]=Q[j];
          j=j-1;
        }
        Q[j+1]=ele;
      }
    }

    void dequeue(){
      if(isEmpty()){
        cout<<"Queue is Empty!!"<<endl;
      }
      else{
        cout<<"Employee"<<Q[fr].getname()<<"is Hired!"<<endl;
        fr=fr+1;
      }

    }

    void DisplayQueue(){

      cout<<"\nId/Name\t\t Job Priority"<<endl;

      for(int i=fr;i<=re;i++){
         Q[i].Display();
      }
    }




};

int main()
{
    cout<<"\n********************* MENU *********************"<<endl;
    cout<<"1.Add Job"<<endl;
    cout<<"2.Delete{Accept} Job."<<endl;
    cout<<"3.Display Job list"<<endl;
    cout<<"0.Exit the Program"<<endl;
    cout<<"************************************************"<<endl;
    PriQueue p1;

    while(true){
            int choice;
            cout<<"Enter choice.";
            cin>>choice;
            if(choice==1){
              int n;
              cout<<"Enter the number of Job to enter.";
              cin>>n;
              while(n--){
              job j1;
              j1.setdata();
              p1.enqueue(j1);
              }
            }

            else if(choice==2){
              p1.dequeue();
            }
            else if(choice==3){
              p1.DisplayQueue();
            }
            else if(choice==0){
              cout<<"-----------Thankyou fo using the program!!-----------"<<endl;
              break;
            }
            else{
              cout<<"Wrong choice!!!!"<<endl;
            }

            }
    return 0;
}
