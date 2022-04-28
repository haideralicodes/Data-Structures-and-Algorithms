#include<iostream>
#include<string.h>
using namespace std;

class stack{
	public:
		int top;
		int size;
		int arr[20];
		
	stack(){
		top = -1;
		size = 20;
	}	

void push(int x){
	if(is_full()){
		cout<<"\n\n\tStack is Full!!!";
	}
	else{
		arr[++top] = x;
		cout<<"\n\n\t"<<x<<" pushed in the stack";
	}
}

int pop(){
	int x = 0;
	if(is_empty()){
		cout<<"\n\n\tStack is Empty!!!";
	}
	else{
		return arr[top--];
	}
}

bool is_empty(){
	if(top==-1){
		return true;
	}
	return false;
}

bool is_full(){
	if(top == size-1){
		return true;
	}
	return false;
}

void display(){
	if(top == -1){
		cout<<"\n\n\tNothing to display.....";
		cout<<"\n\n\tStack is Empty!!!!";
	}
	else{
		cout<<"\n";
		for(int i = top; i >= 0; i--){
			cout<<"\t"<<arr[i]<<"\t";
		}
	}
}


void binary_to_decimal(int number) {
   while(number > 0) {
      int reminder = number % 2; //calculate remainder
      number = number / 2;
      push(reminder);
   }
   cout<<"\n\n\t";
   while(!(is_empty())) {
      int item;
      item = arr[top];
      pop();
      cout<<item;
   }
}

void reverse(string str){
	for(int i = 0; i < str.length(); i++){
		push(str[i]);
	}
	
	string rev = "";
	
	while(!(is_empty())){
		rev += pop();
	}
	
	cout<<"\n\n\tReversed string is: "<<rev;
}
	
};

int opt;

int main(){
	
	stack s1 = stack(); 
	
	int id;
	
	int num1;
	
	string num2;
	
	do{
		
		cout<<"\n\n\t[0].Exit";
		cout<<"\n\n\t[1].Push";
		cout<<"\n\n\t[2].Pop";
		cout<<"\n\n\t[3].Display";
		cout<<"\n\n\t[4].Decimal to Binary";
		cout<<"\n\n\t[5].Reverse";
		
		cout<<"\n\n\tEnter your choice: ";
		cin>>opt;
		
		switch(opt){
			case 1:{
				cout<<"\n\n\tEnter the id: ";
				cin>>id;
				s1.push(id);
				break;
			}
			case 2:{
				s1.pop();
				break;
			}
			case 3:{
				s1.display();
				break;
			}
			case 4:{
				cout<<"\n\n\tEnter num: ";
				cin>>num1;
				s1.binary_to_decimal(num1);
				break;
			}
			case 5:{
				cout<<"\n\n\tEnter string: ";
				cin>>num2;
				s1.reverse(num2);
				break;
			}
		}
		
	}
	while(opt != 0);
	
	return 0;
}