#include<iostream>
#include<string.h>
using namespace std;

class stack{
	
	public:
	int size, top;
	char arr[100];
	
stack(){
	top = -1;
	size = 100;
}	
	
void push(char x){
	
	if(is_full()){
		cout<<"\n\nStack is full";
	}
	else{
		arr[++top] = x;
//		cout<<"\n\nThe pushed number is: "<<arr[top];
	}
}
	
char pop(){
	char x = NULL;
	if(is_empty()){
		cout<<"\n\nStack is empty";
	}
	else{
		x = arr[top--];
		return x;
	}
}

bool is_full(){
	if(top == size-1){
		return true;
	}
	return false;
}

bool is_empty(){
	if(top==-1){
		return true;
	}
	return false;
}
	
void display(){
	if(top == -1){
		cout<<"\n\nEmpty stack";
	}
	else{
		for(int i = top; i >= 0; i--){
			cout<<"\nValue at index "<<i<<" is: "<<arr[i];
		}
	}
}	

int precedence(char expr){
	if(expr == '^'){
		return 3;
	}
	else if(expr == '*' || expr == '/'){
		return 2;
	}
	else if(expr == '+' || expr == '-'){
		return 1;
	}
	else{
		return -1;
	}
}	

string postfix(string s){
	
	string result = "";
	
	for(int i =0; i < s.size(); i++){
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){//oprend should be from a to z or A to Z
		result += s[i];	//jo jo oprend string me he uss ko result me shamil kar do
	}
	else if(s[i] == '('){//agr ( aa jae to stack pe push() kar do
		push(s[i]);	
	}
	else if(s[i] == ')'){//agr ) aa jae to:
		while(!is_empty() && arr[top] != '('){//jab tak ( na ae stack me se push karte raho
			result += arr[top];//jo bach jae use result me add kar do
			pop();//baki ko pop() kar do
		}
		if(!is_empty()){	//aur agr stack non-empty he to pop() kar lo
			pop();
		}
	}
	else{
//yaha operator precedence check ho gi
//Jab tak stack k top wale operator ki precedence
//string k opertator ki pprecedence se ziada he
//to stack k top wale operator ko result me add kar do
//aur sath hi pop()	karte jao
		while(!is_empty() && precedence(arr[top]) > precedence(s[i])){
			result += arr[top];
			pop();
		}
//aur nae operators aur opperands ko stack me push karo		
		push(s[i]);
	}
	
}
//jab tak stack empty na ho jae
//result ko add karo
//stack me se pop karo	
	while(!is_empty()){
		result += arr[top];
		pop();
	}
//finally result ko return kar do	
	return result;
}
	
};


int main(){
	
	string a = "(a*(b+c))";
	
	stack s1 = stack();
	
	cout<<"\nYou can see the result: "<<s1.postfix(a);
	
	
	return 0;
}
