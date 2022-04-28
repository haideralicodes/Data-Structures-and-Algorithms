#include<iostream>
using namespace std;

struct stu{
	int id;
	stu *next = NULL;
};

stu *first = NULL;
stu *last = NULL;

int opt;

void insert_end();
void display();
void min();
void max();
void sum();
void multiply();
void type_of_id();
void print_type();


int main(){
	
	do{
		cout<<"\n\n0.Exit";
		cout<<"\n\n1.Insert at end";
		cout<<"\n\n2.Display";
		cout<<"\n\n3.Min";
		cout<<"\n\n4.Max";	
		cout<<"\n\n5.Sum";
		cout<<"\n\n6.multiply";
		cout<<"\n\n7.Type of ids";
		cout<<"\n\n8.Number";
		
						 
		cout<<"\n\nEnter your choice: ";
		cin>>opt;
		
		
		
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
				min();
				break;
			}
			case 4:{
				max();
				break;
			}
			case 5:{
				sum();
				break;
			}
			case 6:{
				multiply();
				break;
			}
			case 7:{
				type_of_id();
				break;
			}
			case 8:{
				print_type();
				break;
			}
		}
		
	}
	while(opt != 0);
	
	return 0;
}

void insert_end(){
	
	stu *current = new stu;
	
	cout<<"\n\nEnter the student id: ";
	cin>>current->id;
	
	if(first == NULL){
		cout<<"\n\nEmpty linked list";
		first = last = current;
	}
	else{
		last->next = current;
		last = current;
	}
}

void display(){
	cout<<"\n";
	
	stu *p = first;
	
	if(first == NULL){
		cout<<"\n\nEmpty linked list";
	}
	else{
		while(p != NULL){
			cout<<p->id<<" ";
			p = p->next;
		}
	}
}

void min(){	//..finds minimum id in the linked list
	
	cout<<"\n";
	
	stu *min = first;
	stu *p = first;
	
	while(p != NULL){
		if(p->id < min->id){
			min = p;
		}
		p = p->next;
	}
	cout<<min->id;
}


void max(){	//..finds maximum id in the linked list
	
	cout<<"\n";
	
	stu *max = first;
	stu *p = first;
	
	while(p != NULL){
		if(p->id > max->id){
			max = p;
		}
		p = p->next;
	}
	cout<<max->id;
}


void sum(){	//..finds the sum of ids in linked list
	
	cout<<"\n";
	
	stu *p = first;
	
	int sum = 0;
	
	
	while(p != NULL){
		sum = sum + p->id;
		p = p->next;
	}
	cout<<sum;
}

void multiply(){
	
	stu *p = first;
	
	stu *multiply = first;
	
	while(p != NULL){
		multiply->id = multiply->id * p->id;
		p = p->next;
	}
	cout<<multiply->id;
}

void type_of_id(){
	
	cout<<"\n";
	
	int count_even = 0;
	int count_odd = 0;
	
	stu *p = first;
	
	while(p != NULL){
		if(p->id % 2 == 0){
			count_even++;
			p = p->next;
		}
		else{
			count_odd++;
			p = p->next;	
		}	
	}
	
	cout<<"\nThe number of even ids in linked list are: "<<count_even;
	cout<<"\nThe number of odd ids in linked list are: "<<count_odd;
	
}

void print_type(){
	
	
	stu *p = first;
	
	while(p != NULL){
		if(p->id%2==0){
			cout<<"\nThe number of even ids are: "<<p->id;
			p = p->next;
		}
		else{
			cout<<"\nThe number of odd ids are: "<<p->id;
			p = p->next;
		}
	}
}
