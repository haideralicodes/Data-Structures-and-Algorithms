#include<iostream>
using namespace std;

class Qeue{
	public:
		int front;
		int rear;
		int *q;
		int size;
		
	Qeue(){	//default constructor
		size = 3;
		q = new int[size];
		front = -1;
		rear = -1;
	}	
	
	Qeue(int x){
		size = x;
		q = new int[size];
		front  = -1;
		rear = -1;
	}
	
	bool is_empty(){
		if(rear == -1){
			cout<<"\n\nThe Qeue is Empty";
			return true;
		}
		else{
			return false;
		}
	}
	
	bool is_full(){
		if(rear == size-1){
			cout<<"\n\nThe Qeue is full";
			return true;
		}
		else{
			return false;
		}
	}
	
	void enqeue(){
		
		int input;
		
		if(is_empty()){
			cout<<"\n\nQeue is empty";
			cout<<"\n\nEnter the input: ";
			cin>>input;
			front = rear = 0;
			q[rear] = input;
		}
		else{
			if(is_full()){
				cout<<"\n\nQeue is full";
			}
			else{
				cout<<"\n\nEnter the input: ";
				cin>>input;
				rear++;
				q[rear] = input;
			}
		}
//		cout<<"\n\nThe enqeued number is: "<<input;
	}
	
	void deqeue(){
		if(is_empty()){
			cout<<"\n\nQeue is empty";
		}
		else if(rear == 0){
				rear = front = -1;
		}
		else{
			front++;
		}
	}
	
	void diaplay(){
		cout<<"\n\n";
		if(is_empty()){
			cout<<"\n\nQeue is empty";
		}
		else{
			for(int i = front; i <=rear; i++){
				cout<<q[i]<<" ";
			}
		}
		cout<<"\n\n";
	}
	
};

int main(){
	
	int opt;
	
	Qeue q1 = Qeue();
	
	do{
		
		cout<<"\n[0]Exit";
		cout<<"\n[1]Enqeue";
		cout<<"\n[2]Deqeue";
		cout<<"\n[3]Display";
		
		cout<<"\n\nEnter your choice: ";
		cin>>opt;
	
		switch(opt){
			case 1:{
				q1.enqeue();
				break;
			}
			case 2:{
				q1.deqeue();
				break;
			}
			case 3:{
				q1.diaplay();
				break;
			}
		}
	
	}
	while(opt != 0);
	return 0;
}