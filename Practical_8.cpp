//============================================================================
// Name        : assignment8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
void menu() {
	cout<<"Enter your choice "<<endl;
	cout<<"Press 1 to display all slot (booked and unbooked)"<<endl;
	cout<<"Press 2 to book slot "<<endl;
	cout<<"Press 3 to cancel slot "<<endl;
	cout<<"Press 0 to exit "<<endl;
}


class slot {
public:
	int s_time;
	int e_time;
	bool flag ;
	slot *next;
	slot() {
		s_time = 0;
		e_time = 0;
		flag = 0;
		next = NULL;
	}
	slot(int i,int j,int k) {
		s_time = i ;
		e_time = j ;
		flag = k ;
		next=NULL;
	}
};
class appointment {
public:
	slot *head;
	appointment() { head = NULL; }
	void insert_slot(int i,int j ,int k);
	void create_slot();
	void book();
	void cancel();
	void display();
};

void appointment::insert_slot(int i,int j,int k)
{
    slot  *newslot ;
    newslot = new slot( i, j ,k);

    if (head == NULL) {
        head = newslot;
        return;
    }
    slot* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newslot;
}
void appointment::create_slot() {
	int i=1;
	int j=2;
	int k=0;
	while(i<9 && j<9) {
		insert_slot(i,j,k);
		i++;
		j++;
	}
}
void appointment :: book() {
	int i,j;
	cout<<"Enter your sutable time to for oppintment "<<endl;
	cin>>i;
	j = i+1;
	if(i<1||i>7||j<2||j>8) {
		cout<<"Sorry this is not available "<<endl;
	}
	else {
		slot *temp;
		temp = new slot;
		temp = head;
		while(temp->s_time != i) {
			temp=temp->next;
		}
		temp->flag = 1;
	}

}
void appointment::cancel() {
	int i,j;
	cout<<"Enter oppintment time "<<endl;
	cin>>i;
	j = i+1;
	if(i<1||i>7||j<2||j>8) {
		cout<<"Sorry wrong time "<<endl;
	}
	else {
		slot *temp;
		temp = head;
		while(temp->s_time != i) {
			temp = temp->next;
		}
		temp->flag = 0;
	}

}
void appointment::display() {
	slot *temp = head;
	cout<<"*********All slots****************************"<<endl;
	cout<<"Start time "<<" "<<"end time "<<"Status "<<endl;
	while(temp!=NULL) {
		cout<<temp->s_time<<"\t"<<temp->e_time<<"\t ";
		if(temp->flag==0){
			cout<<"Available"<<endl;
		}
		else {
			cout<<"Booked "<<endl;
		}
		temp = temp->next;
	}
	cout<<"**************************************************"<<endl;
}

int main() {
	appointment d;
	d.create_slot();
	menu();

	bool flag = 1;
	while(flag==1) {
		int c;
		cout<<"Enter choice "<<endl;
		cin>>c;
		switch(c) {
		case 1:
			d.display();
			break;
		case 2:
			d.book();
			break;
		case 3:
			d.cancel();
			break;
		default:
			flag = c;
			break;

		}
	}

	return 0;
}
