#include<iostream>
using namespace std;

class node {
	public:
	int seat_no;
	int seat_status ;
	node *next;
	node *prev;
	node () {
		seat_no = 0;
		seat_status = 0;
		next = NULL;
		prev = NULL;
	}
};

class Cinemax {
	public:
	node *head ,*tail ,*temp ;
	Cinemax() {
		head = NULL;
	}
	void create();
	void display();
	void book ();
	void cansel();
};

void Cinemax::create()
{
	temp = new node ;
	temp->seat_no = 1;
	temp->seat_status=0;
	tail = head = temp;
	for(int i=2;i<71;i++)
	{
		node *p;
		p= new node;
		p->seat_no=i;
		p->seat_status=0;
		tail->next=p;
		p->prev=tail;
		tail = p;
		tail->next=head;
		head->prev=tail;
	}
}

void Cinemax::display()
{
	node *current;
	current = head;
	int i=0;
	while(current->next!=head) {
		cout<<"|"<<current->seat_no;//"_"<<current->seat_status<<"* ";
		if(current->seat_status==1) {
		cout<<" B "<<"|";
	}
	else {
		cout<<" NB "<<"|";
	}
	i++;
	if(i%7==0) {
		cout<<"\n";
	}
		current = current->next;
	}
}

void Cinemax::book()
{
	cout<<endl;
	int num_seats ;
	int seat_num;
	cout<<"Enter number of seats "<<endl;
	cin>>num_seats;
	for(int i=0;i<num_seats;i++) {
		cout<<"Enter seat number "<<endl;
		cin>>seat_num;
		if(seat_num <1 || seat_num>70)
		{
			cout<<"Enter seat number bitween 1-70 "<<endl;
		}
		node *current;
		current = new node;
		current = head;
		while(current->seat_no!=seat_num)
		{
			current = current->next;
		}
		current->seat_status = 1;
	}
}
void Cinemax::cansel()
{
	cout<<endl;
	int num_seats ;
	int seat_num;
	cout<<"Enter number of seats "<<endl;
	cin>>num_seats;
	for(int i=0;i<num_seats;i++) {
		cout<<"Enter seat number "<<endl;
		cin>>seat_num;
		if(seat_num <1 || seat_num>70)
		{
			cout<<"Enter seat number bitween 1-70 "<<endl;
		}
		node *current;
		current = new node;
		current = head;
		while(current->seat_no!=seat_num)
		{
			current = current->next;
		}
		current->seat_status = 0;
	}

}
void menu() {
	cout<<"Enter your choice "<<endl;
	cout<<"Press 1 to display all seats (booked and unbooked)"<<endl;
	cout<<"Press 2 to book seat "<<endl;
	cout<<"Press 3 to cancel slot "<<endl;
	cout<<"Press 4 to exit "<<endl;
}
int main () {
	Cinemax obj;
	obj.create();
	int choice;
	bool flag = 1;
	while(flag==1) {
		menu();
		cin>>choice;
		switch(choice) {
		case 1 :
			obj.display();
			break;
		case 2:
			obj.book();
			break;
		case 3:
			obj.cansel();
			break;
		case 4:
			flag = 0;
		}
	}
}
