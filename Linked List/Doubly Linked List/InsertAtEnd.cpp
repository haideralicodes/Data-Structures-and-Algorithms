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

void insert_end();
void display();

int main(){
	
	do{
		
	cout<<"\n\n\t0.Exit";
	cout<<"\n\t1.insert at end";
	cout<<"\n\t2.display";
	
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
		while(p != NULL){	
			cout<< p->id << " ";
			p = p->next;	//next node ko print karne k lie
		}
	}
	
	cout<<"\n";
	
}
