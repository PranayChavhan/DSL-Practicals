//============================================================================
// Name        : assignment11.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

class job{
public:
	string job_name;
	job *next;
	job() {
		job_name = "";
	}
	job(string s) {
		job_name = s;
	}
};

class queue {
	public:
	job *head;
	job *tail;
	queue () {
		head = NULL;
		tail = NULL;
	}
	void add_job();
	void display();
	void delet();
};

void queue::add_job()
{
	int n;
	cout<<"Enter no of jobs to enter "<<endl;
	cin>>n;
	while(n>0) {
		job *newjob;
		string s;
		cout<<"Enter highest qualification "<<endl;
		cin>>s;
		newjob = new job(s);

		if(head == NULL && tail == NULL ) {
			head = newjob;
			tail = newjob;
		}
		else {
			tail->next = newjob;
			tail = newjob;
		}
		n--;
	}

}

void queue::delet()
{
	if(head==NULL) {
		cout<<"Underflow"<<endl;
	}
	else if(head==tail) {
		cout<<"Job list is empty now "<<endl;
		delete head;
		delete tail;
		head = NULL;
		tail = NULL;
	}

	else {
		job *temp;
		temp = new job;
		temp = head ;
		head = temp->next;
		delete temp;

	}
}

void queue::display()
{
	job *temp;
	temp = new job;
	temp = head;
	int cnt=1;
	while(temp != tail) {
		cout<<cnt<<" ";
		cout<<temp->job_name<<endl;
		temp = temp->next;
		cnt++;
	}
	cout<<cnt<<" "<<temp->job_name<<endl;
}

void menu() {
	cout<<"Enter your choice : "<<endl;
	cout<<"Press 1 to add job "<<endl;
	cout<<"press 2 delet job "<<endl;
	cout<<"Press 3 to display job list "<<endl;
	cout<<"Press 0 to exit "<<endl;
}
int main () {
	queue q;
	menu();

	bool flag = 1;
	while(flag==1) {
		int c;
		cout<<"Enter choice : "<<endl;
		cin>>c;
		switch(c) {
		case 1:
			q.add_job();
			break;
		case 2:
			q.delet();
			break;
		case 3:
			q.display();
			break;
		default:
			flag = c;

		}
	}


}

