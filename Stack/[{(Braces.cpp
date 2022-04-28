#include <iostream>
#include<string.h>
using namespace std;

class stack {
	public:
	int top;
	int size;
	char array[10];
	
	stack(){
		top=-1;
		size=10;
	}

void push(char x){
	if (is_full()){
		cout<<"No space";
		}		
		else{
		array[++top]= x;
		cout<<"\nPushed element is: "<<array[top];
//		return x;
	}
}
	
	
void pop(){
	char x = NULL;
	if (is_empty()){
		}
	else{
		x = array[top--];
		cout<<"\nPoped element is: "<<x;
	}
}
	
bool is_full(){
	if(top==size-1){
		return true;
	}
	else {
		return false;
	}
}
	
bool is_empty(){
	if(top== -1){
	}
	else {
		return false;
	}
}
	
void display(){
	if (top==-1){
		cout<<"No space";
		}
	else{
		for (int i = top ; i >=0 ; i--){
			cout<<array[i];
		}
	}
}
	
bool isBalanced(string s)
{
	for(int i = 0; i < s.length(); i++)
	{
		//checks for bracket
		if(s[i]=='[' || s[i]==']' || s[i]=='{' || s[i]=='}' || s[i]=='(' || s[i]==')')
		{
			//checks for open brackets
			if(s[i]=='[' || s[i]=='{' || s[i]=='(')
			{
				//invalid cases: ( -> { or [  ,  { -> [
				if( (array[top]=='('&& (s[i]=='['||s[i]=='{') ) || (array[top]=='{'&& s[i]=='['))
				   	return false;
				else
					push(s[i]);
			}
			//closing bracket and stack not empty
			else if(!is_empty())
			{
				//invalid cases: [ -> !]  ,  { -> !}  ,  ( -> !)
				if((array[top]=='[' && s[i] != ']') || (array[top] == '{'&& s[i] != '}') || (array[top] =='(' && s[i] !=')'))
					return false;
				else
					pop();
			} 
			//invalid: closing bracket but stack empty
			else{
				return false;
			}	
		}
	}
	//string finish, stack is not empty -> unbalanced
	if(is_empty()){
		return true;
	}
	//balanced
	else{
		return false;
	}
}

};

int main(){
	string s = "{[]}";
	stack st = stack();	

	// Function call
	if (st.isBalanced(s)){
		cout<<"\n\nGIVEN EXPRESSION: "<<s<<" HAS BALANCED PARENTHESIS";
	}
		
	else{
		cout<<"\n\nGIVEN EXPRESSION: "<<s<<" HAS NOT A BALANCED PARENTHESIS";
	}
		
	return 0;
}
