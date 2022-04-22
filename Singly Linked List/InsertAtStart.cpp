#include <iostream>
using namespace std;

struct student{
    string studentName;
    string phoneNumber;
    float gpa; 
    student *next = NULL;
};

student *first = NULL;
student *last = NULL;

//methods
void insert_start();
void display();

int opt;

int main(){

do{
		cout<<"\n\n\t0.Exit";
		cout<<"\n\t1.Insert at start";
		cout<<"\n\t2.Display";

		cout<<"\n\n\tEnter your choice: ";
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
	
	student *current = new student;
	
	cout<<"\n\n\tEnter the student Name: ";
	cin>>current->studentName;
	
	cout<<"\n\tEnter the student gpa: ";
	cin>>current->gpa;
	
	cout<<"\n\tEnter the student phone number: ";
	cin>>current->phoneNumber;
	
	
	if(first == NULL){
		cout<<"\n\n\tEmpty linked list";
		first = last = current;
	}
	else{
		
		current->next = first;
		first = current;
		
	}
	
	cout<<"\n\t";
	
}

void display(){
	
	student *p = first;
	
	if(first == NULL){
		cout<<"\n\n\tEmpty linked list";
	}
	
	else{
		
		while(p != NULL){
			
			cout<<"\n\n\tThe student name is: " << p->studentName<<endl;
			cout<<"\tThe student gpa is: " << p->gpa<<endl;
			cout<<"\tThe student phone number is: " << p->phoneNumber;
			
			p = p->next;
		}
		
	}
	
}
