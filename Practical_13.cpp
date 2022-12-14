//============================================================================
// Name        : assignment13.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;
class node {
public:
	string data;
	node *next;
	node() {
		data = "";
		next = NULL;
	}
	node(string s) {
		data = s;
		next = NULL;
	}
};

class dequeue {
public:
	node *head;
	dequeue() {
		head = NULL;
	}
	void push_front();
	void push_back();
	void pop_front();
	void pop_back();
	void display();
};

void dequeue::push_front()
{
	node *newnode;
	string s;
	cout<<"Enter string to push at front : "<<endl;
	cin>>s;
	newnode = new node(s);
	if(head==NULL) {
		head = newnode;
	}
	else {
		newnode->next = head;
		head = newnode;
	}
}
void dequeue::push_back()
{
	node *newnode;
	string s;
	cout<<"Enter string  to push at back: "<<endl;
	cin>>s;
	newnode = new node(s);
	if(head==NULL) {
		head = newnode;
	}
	else {
		node *temp;
		temp = new node;
		temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
}
void dequeue::display()
{
	node *temp;
	temp = new node;
	temp = head;
	int cnt = 1;
	while(temp != NULL) {
		cout<<cnt<<" ";
		cout<<temp->data<<endl;
		cnt++;
		temp = temp->next ;
	}
}

void dequeue::pop_front()
{
	node *temp;
	temp = new node;
	temp = head;
	head = temp->next;
	temp->next = NULL;
	delete temp;
}

void dequeue::pop_back()
{
	node *temp;
	temp = new node;
	temp = head;
	while(temp->next->next != NULL) {
		temp = temp->next;
	}
	node *temp2;
	temp2 = new node;
	temp2 = temp->next;
	temp->next = NULL;
	delete temp2;
}

void menu() {
	cout<<"Enter ur choice "<<endl;
	cout<<"1. Press 1 to push at front "<<endl;
	cout<<"2. Press 2 to push at back "<<endl;
	cout<<"3. Press 3 to pop from front "<<endl;
	cout<<"4. Press 4 to pop from  back "<<endl;
	cout<<"4. Press 5 to display "<<endl;
	cout<<"Press 0 to Exit"<<endl;
}
int main () {
dequeue d;
menu();

bool flag = 1;
while(flag==1) {
	int c;
	cout<<"Enter choice "<<endl;
	cin>>c;
	switch(c) {
	case 1:
		d.push_front();
		break;
	case 2:
		d.push_back();
		break;
	case 3:
		d.pop_front();
		break;
	case 4:
		d.push_back();
		break;
	case 5:
		d.display();
		break;
	default:
		flag = c;
		break;

	}
}


}
