#include<iostream>
#define m 50
using namespace std;
class stack {
	public:
	char arr[m];
	int top;

	stack() {
		top = -1;
	}
	bool flag = 1;
	char pop();
	void push(char);
//void top();
};

void stack::push(char c)
{
	arr[top+1] = c;
	top = top + 1 ;
}
char stack::pop()
{
	top = top - 1 ;
	return arr[top+1];
}


int main() {
	while(1) {
		string s;
		cout<<"Enter string : "<<endl;
		cin>>s;
		stack st;
		bool flag = 1;
		for(int i=0;i<s.size();i++) {
			if(s[i]=='(') {
				st.push('(');
			}
			else if(s[i]=='[') {
				st.push('[');
			}
			else if(s[i]=='{') {
				st.push('{');
			}
			else if(s[i]==')' && st.top >=0) {
				char c ;
				c = st.pop();
				if(c!='(') {
					flag=0;
					break;
				}
			}
			else if(s[i]==']') {
				char c ;
				c = st.pop();
				if(c!='[') {
					flag=0;
					break;
				}
			}
			else if(s[i]=='}') {
				char c ;
				c = st.pop();
				if(c!='{') {
					flag=0;
					break;
				}
			}
		}
		if(flag==1 && st.top == -1) {
			cout<<"Valid Parenthesis "<<endl;
		}
		else {
			cout<<"Invalid Parenthesis "<<endl;
		}
	}
}
