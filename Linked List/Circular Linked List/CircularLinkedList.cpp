#include <iostream>
using namespace std;

struct student{
  int id;
  student *next = NULL;
};

student *last = NULL;

int opt;

void insert_end();
void display();

int main()
{
	
	do
	{ 
        cout<<"\n\n\t0.Exit";
        cout<<"\n\t1.Insert at end";
        cout<<"\n\t2.Display";

        cout<<"\n\n\tEnter your choice: ";
        cin>>opt;
        
        switch(opt)
		{
            case 1:
			{
                insert_end();
                break;
            }
            case 2:
			{
                display();
                break;
            }
    	}
	}
    while(opt != 0);

    return 0;
}


void insert_end()
{
    student *current = new student;
	
	cout<<"\n\n\tEnter the id:: ";
	cin>>current->id;
	
	if(last == NULL)
	{
		last = current;
        last->next = current;
	}
	else
	{
		current->next = last->next;
		last->next = current;
		last = current;
	}
}

void display()
{
    student *p = last->next;
	student *temp = last;
	
	do
	{
	cout<<"\t"<<p->id;
	p = p->next;
	}
	while(p != temp->next) ;
}