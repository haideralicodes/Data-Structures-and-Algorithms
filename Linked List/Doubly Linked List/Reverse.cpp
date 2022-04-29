#include <iostream>
using namespace std;

struct stu{
	int id;
	stu *next = NULL;
	stu *prev = NULL;
};

stu *first = NULL;
stu *last = NULL;

int opt;
int key;

void insert_end();
void display();
void insert_start();
void reverse();

int main(){
	
	do{
		
	cout<<"\n\n\t0.Exit";
	cout<<"\n\t1.Insert at end";
	cout<<"\n\t2.Display";
	cout<<"\n\t3.Insert at start";
	cout<<"\n\t4.Reverse the doubly linked list";

	cout<<"\n\n\n\tEnter your choice:: ";
	cin>> opt;		
		
		switch(opt){
			
			case 1:{
				insert_end();
				break;
			}
			case 2:{
				display();
				break;
			}
			
			case 3:{
				insert_start();
				break;
			}
			case 4:{
				reverse();
				break;
			}
		}
	}
	while(opt != 0);
	
	return 0;
}

void insert_end(){
	
	stu *current  = new stu;
	cout<<"\n\tEnter the id:: ";
	cin>> current->id;
	
	// if empty
	if(first == NULL){
		first = last = current;
	}
	//if non-empty
	else{
		last->next = current;
		current->prev = last;
		last = current;	// current hi last node he
	}
	
}

void display(){
	
	stu *current  = new stu;	//1, 2, 3, 4, 5
	stu *p = first;	// p = 1
	
	if(first == NULL){			//1 == NULL(false)
		first = last = current; //first aur last hi current he
	}
	else{
		cout<<"\n";
		while(p != NULL){	
			cout<<"\t"<<p->id;
			p = p->next;	//next node ko print karne k lie
		}
		cout<<"\n";
	}	
}


void insert_start(){
	
	stu *current = new stu;
	cout<<"\n\tEnter the id:: ";
	cin>> current->id;
	
	// if empty
	if(first == NULL){
		first = last = current;
	}
	// if not empty
	else{
		 current->next = first;	// backward linking
		 first->prev = current; // forward linking
		 first = current;		// cuurent node hi first node he
	}
	
}

void reverse(){
	
	stu *current = new stu;
	stu *k = last;
	
	if(first == NULL){
		first = last = current;
	}
	else{
		cout<<"\n";
		while(k->prev != NULL || k->prev == NULL){	// ?????????????
		cout<<"\t"<< k->id;
		k = k->prev;
	}
		cout<<"\n";
}
	
}