#include<iostream>
using namespace std;

struct Qeue{
	int id;
	Qeue *next = NULL;
};
Qeue *front = NULL;	//first
Qeue *rear = NULL;	//last


void enqeue();
void deqeue();
void display();

int opt;

int main(){
	
	do{
		
		cout<<"\n[0]Exit";
		cout<<"\n[1]Enqeue";
		cout<<"\n[2]Deqeue";
		cout<<"\n[3]Display";
		
		cout<<"\n\nEnter your choice: ";
		cin>>opt;
		
		switch(opt){
			case 1:{
				enqeue();
				break;
			}
			case 2:{
				deqeue();
				break;
			}
			case 3:{
				display();
				break;
			}
		}
		
	}
	while(opt != 0);
	
}


	
void enqeue(){	//insert at end
	
	Qeue *current = new Qeue;
	
	cout<<"\n\nEnter id: ";
	cin>>current->id;
	
	if(front == NULL){	//first == NULL
		cout<<"\nQeue is Empty";
		front = rear = current;		//first = last = current
	}
	else{
		rear->next = current;	//last->next = current
		rear = current;			//last = current
	}
	cout<<"\n";
}

void deqeue(){	//delete from start
	
	Qeue *p = front;	//stu *p = first----------1st node
	Qeue *p1 = p->next;	//stu *p1 = p->next-------2nd node

	front = p1;		//now 2nd node will be first node
	delete p;		//delete 1st node
}

void display(){	//display from start
	cout<<"\n";
	Qeue *p = front;	//stu *p = first
	
	if(front == NULL){	//first == NULL
		cout<<"\nQeue is Empty";
	}
	else{
	
	do{
		cout<<p->id<<" ";
		p = p->next;
	}
	while(p != NULL);
	
	}
	cout<<"\n";
	
}