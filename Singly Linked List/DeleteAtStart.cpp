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

void delete_start();

int opt;
string name;


int main(){

do{
		
		cout<<"\n\n0.Exit";
		cout<<"\n1.Insert at end";
		cout<<"\n2.Display";
		cout<<"\n3.Delete start";
		
		cout<<"\n\n\nEnter your choice: ";
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
				delete_start();
				break;
			}
		}
		
	}
	while(opt != 0);
	
	return 0;
}

void insert_end(){
	
	student *current = new student;
	
	cout<<"Enter the student Name: ";
	cin>>current->studentName;
	
	cout<<"Enter the student gpa: ";
	cin>>current->gpa;
	
	cout<<"Enter the student phone number: ";
	cin>>current->phoneNumber;
	
	
	if(first == NULL){
		cout<<"\n\nEmpty linked list";
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
		cout<<"\n\nEmpty linked list";
	}
	
	else{
		
		while(p != NULL){
			
			cout<<"\nThe student name is: " << p->studentName<<endl;
			cout<<"\nThe student gpa is: " << p->gpa<<endl;
			cout<<"\nThe student phone number is: " << p->phoneNumber;
			
			p = p->next;
		}
		
	}
	
}

void delete_start(){
	
	
	student *p = first;				//p points to the 1st node
	student *p1 = first->next;		//p1 points to the 2nd node
	
	
	if(first == NULL){	//if list is empty
		cout<<"\n\nThe linked list is empty";
	}
	
	else{
		
	first = p1;
	delete p;
		
	}

}


void delete_end(){
	
	
	student *p = first;
	student *p1 = first;
	
	while(p != NULL){
		p1 = p;
		p = p->next;
	}
	
	p1->next = NULL;
		delete p;
	
}