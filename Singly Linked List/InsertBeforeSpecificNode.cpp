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
void insert_end();
void display();
void insert_before_specific();

int opt;
string name;

int main(){

do{
		
		cout<<"\n\n\t0.Exit";
		cout<<"\n\t1.Insert at end";
		cout<<"\n\t2.Display";
		cout<<"\n\t3.Insert before specific";
		
		cout<<"\n\n\tEnter your choice: ";
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
				insert_before_specific();
				break;
			}
			
		}
		
	}
	while(opt != 0);
	
	return 0;
}

void insert_end(){
	
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
	else{	//if linked list is non empty
	
		last->next = current; 
		last = current; 
	}
	
}

void display(){
	
	student *p = first;
	
	if(first == NULL){
		cout<<"\n\n\tEmpty linked list";
	}
	
	else{
		
		while(p != NULL){
			
			cout<<"\n\tThe student name is: " << p->studentName<<endl;
			cout<<"\tThe student gpa is: " << p->gpa<<endl;
			cout<<"\tThe student phone number is: " << p->phoneNumber;
			
			p = p->next;
		}
		
	}
	
}


void insert_before_specific(){
	
	
	student *p = first;
	student *p1 = NULL;
	
	cout<<"\n\n\tEnter the student name: ";
	cin>>name;
	
	//searching the student name
	while(p->studentName != name && p != NULL){
		cout<<"\n\n\tStudent "<<name<<" is Found in the linked list";
		p1 = p;
		p = p->next;
	}
	
	student *current = new student;
	
	cout<<"\n\n\tEnter the student Name: ";
	cin>>current->studentName;
	
	cout<<"\n\tEnter the student gpa: ";
	cin>>current->gpa;
	
	cout<<"\n\tEnter the student phone number: ";
	cin>>current->phoneNumber;
	
	current->next = p;
	p1->next = current;
	
	
}
