#include<iostream>
using namespace std;

class stack
{
	public:
		int top;
		int size;
		char arr[20];
		
	stack()
	{
		top = -1;	
		size = 20;	
	}	
	
	void push(char x)
	{
		if(is_full())
		{
			cout<<"\n\n\t\tStack is FULL...//";
		}
		else
		{
			arr[++top] = x;
			cout<<"\n\n\t\t"<<x<<" is pushed in the stack";
		}
	}
	
	void pop()
	{
		char x;
		
		if(is_empty())
		{
			cout<<"\n\n\t\tStack is EMPTY...//";
		}
		else
		{
			x = arr[top--];
			cout<<"\n\n\t\t "<<x<<" is popped from the stack";
		}
	}
	
	bool is_empty()
	{
		if(top == -1)
		{
			return true;
		}
		return false;
	}
	
	bool is_full()
	{
		if(size == top-1)
		{
			return true;
		}
		return false;
	}
	
	void display()
	{
		if(is_empty())
		{
			cout<<"\n\n\t\tStack is EMPTY...//";
		}
		else
		{
			for(int i = top; i >=0; i--)
			{
				cout<<"\n\n\t"<<arr[i];
			}
		}
	}
	
	bool check_parenthisis_round(string str)
	{
		
		int count1 = 0;
		int count2 = 0;
		
		for(int i = 0; i < str.length(); i++)
		{
			if(str[i] == '(')
			{
				push(str[i]);
				count1++;
				cout<<"\n\n\t\tcount1 is: "<<count1;
			}
		}
		
		for(int i = 0; i < str.length(); i++)
		{
			if(str[i] == ')')
			{
				pop();
				count2++;
				cout<<"\n\n\t\tcount2 is: "<<count2;
			}
		}
		
		if(count1 == count2)
		{
			return true;
		}
		
		return false;
	}
	
};


int main()
{
	int opt;
	
	stack s1 = stack();
	
	do
	{
		cout<<"\n\n\tEnter [0] to EXIT";
		cout<<"\n\n\tEnter [1] to PUSH";
		cout<<"\n\n\tEnter [2] to POP";
		cout<<"\n\n\tEnter [3] to DISPLAY";
		cout<<"\n\n\tEnter [4] to check balanced ROUND paernthesis";
		
		cout<<"\n\n\n\t=====> Enter your choice: ";
		cin>>opt;
		
		switch(opt)
		{
			case 1:
			{
				char ch;
				cout<<"\n\n\t\tEnter a char to push in the stack: ";
				cin>>ch;
				s1.push(ch);
				break;
			}
			case 2:
			{
				s1.pop();
				break;
			}
			case 3:
			{
				s1.display();
				break;
			}
			case 4:
			{
				string expr;
				cout<<"\n\n\t<============> Enter the string to check balanced paernthisis: ";
				cin>>expr;
				if(s1.check_parenthisis_round(expr))
				{
					cout<<"\n\n\n\t<=====> YES <=====>";
				}
				else
				{
					cout<<"\n\n\n\t<=====> NO <=====>";
					cout<<"\n\n";
				}
				break;
			}		
		}
	}
	while(opt != 0);
	
	return 0;
}