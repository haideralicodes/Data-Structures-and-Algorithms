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

void insert_start();
void display();


int main(){
	
	do{
		
	cout<<"\n\n\t0.Exit";
	cout<<"\n\t1.Insert at start";
	cout<<"\n\t2.Display";

	cout<<"\n\n\n\tEnter your choice:: ";
	cin>> opt;
	
			
		
		switch(opt){
			
			case 1:{
				insert_start();
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

void display(){
	
	stu *current  = new stu;	//1, 2, 3, 4, 5
	stu *p = first;	// p = 1
	
	if(first == NULL){			//1 == NULL(false)
		first = last = current; //first aur last hi current he
	}
	else{
		cout<<"\n";
		while(p != NULL){	
			cout<<"\t"<< p->id;
			p = p->next;	//next node ko print karne k lie
		}
		cout<< "\n";
	}
	
}
