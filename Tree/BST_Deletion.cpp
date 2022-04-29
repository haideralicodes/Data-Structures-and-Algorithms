#include<iostream>
using namespace std;

/////////////////////////////////////

struct BST{
	int id;
	BST *left = NULL;
	BST *right = NULL;
};

BST *root = NULL;

////////////////////////////////////////////////////////////////////

void insert(int k);
void preorder(BST *p);
void inorder(BST *p);
void postorder(BST *p);
void search(int key, BST *p);
void del(int key);
void root_node(BST *p);
void average(BST *p);

////////////////////////////////////////////////////////////////////

int opt;
int k;
int key;

////////////////////////////////////////////////////////////////////

int main(){

////////////////////////////////////////////////////////////////////
	
	do{
		
		cout<<"\n\n\t[1]Insert";
		cout<<"\n\t[2]Pre-order";
		cout<<"\n\t[3]In-order";
		cout<<"\n\t[4]Post-order";
		cout<<"\n\t[5]Search";
		cout<<"\n\t[6]Delete node";
		cout<<"\n\t[7]Check root of tree";
		cout<<"\n\t[8]Calculate Average";
		
		cout<<"\n\n\n\tEnter your choice: ";
		cin>>opt;
		
////////////////////////////////////////////////////////////////////		
		
		switch(opt){
//..................................................................			
			case 1:{
				cout<<"\n\n\t\tEnter the id: ";
				cin>>k;	
				insert(k);
				break;
			}
			case 2:{
				preorder(root);
				break;
			}
			case 3:{
				inorder(root);
				break;
			}
			case 4:{
				postorder(root);
				break;
			}
			case 5:{
				cout<<"\n\tEnter the key: ";
				cin>>key;
				search(key, root);
				break;
			}
			case 6:{
				int ke;
				cout<<"\n\n\tEnter the key: ";
				cin>>ke;
				del(ke);
				break;
			}
			case 7:{
				root_node(root);
				break;
			}
			case 8:{
				average(root);
				break;
			}
//..................................................................			
		}
//..................................................................		
	}
	while(opt != 0);
//..................................................................		
	return 0;
}

////////////////////////////////////////////////////////////////////

void insert(int k){
	
	BST *curr = new BST;
	
	curr->id = k;
//..................................................................	
	if(root == NULL){
		cout<<"\n\n\tTree is empty";
		root = curr;
	}
//..................................................................	
	else{
		BST *p = root;
		BST *p2 = NULL;	//wo node he
		
		while(p != NULL){
//..................................................................			
			p2 = p;
			if(k < p->id){
				p = p->left;
			}
//..................................................................			
			else{
				p = p->right;
			}
//..................................................................			
		}	//yaha par usse node k right/left me null mill jae ga
//..................................................................		
		if(k > p2->id){
			
		p2->right = curr;
		
		}
//..................................................................		
		else{
			
		p2->left = curr;
		
		}
//..................................................................		
	}
//..................................................................	
}

////////////////////////////////////////////////////////////////////
                                     
void preorder(BST *p){
	if(p != NULL){
//..................................................................		
		cout<<"\t"<<p->id<<" ";
		preorder(p->left);
		preorder(p->right);
//..................................................................	
	}
}                                     
                                     
////////////////////////////////////////////////////////////////////

void inorder(BST *p){
	if(p != NULL){
//..................................................................		
		inorder(p->left);
		cout<<"\t"<<p->id<<" ";
		inorder(p->right);
//..................................................................		
	}
}

////////////////////////////////////////////////////////////////////

void postorder(BST *p){
//..................................................................	
	if(p != NULL){
		postorder(p->left);
		postorder(p->right);
		cout<<"\t"<<p->id<<" ";
	}
//..................................................................	
}

////////////////////////////////////////////////////////////////////

void search(int key, BST *p){
//..................................................................		
	if(p == NULL){
		cout<<"\n\n\tNo Tree exists";
	}
//..................................................................		
	else if(p->id == key){
		cout<<"\n\n\tFound";
	}
//..................................................................		
	else if(p->id < key){
			search(key, p->left);
	}
//..................................................................		
	else{
		search(key, p->right);
	}
//..................................................................		
}

void del(int key){
	
	BST *p = root;
	BST *p1 = NULL;
	
	while(p->id != key && p != NULL){
		
		p1 = p;
		
		if(p->id == NULL){
			cout<<"\n\n\t\tNo Tree exits";
		}
		else if(key > p->id){
			p = p->right;
		}
		else{
			p = p->left;
			}
		}
		
	//for deleting the leaf node of BST	
	
	if(p->right == NULL && p->left == NULL){
		if(p == p1->left){
			p1->left = NULL;
			delete p;
		}
		else{
			p1->right = NULL;
			delete p;
		}
	}
	
	//for deleting the node of BST having one branch on either side
		
	else if(p->right == NULL || p->left == NULL){
	
	while(p->id != key && p != NULL){
		
		p1 = p;
		
		if(key == p->id){
			cout<<"\n\n\tId found";
		}
		else if(key > p->id){
			p = p->right;
		}
		else{
			p = p->left;
		}
	}//while loop end
	
	if(p->left == NULL){
		p1->left = p->right;
	}
	
	else{
		p1->right = p->left;
	}
		
	}
	
	//for deleting the node of BST having one branch on both sides
	
	else{
		
		while(p->id != key && p != NULL){
		
		if(key == p->id){
			cout<<"\n\n\tId found";
		}
		else if(key > p->id){
			p = p->right;
		}
		else{
			p = p->left;
		}
	}//while loop end
	
	BST *k = p->right;	//farz karin 50 ko delete karna he to 50 k first right me jana he
	cout<<"\n\n\tThe id of k should be 80 & is: "<<k->id;
	BST *k2 = NULL;
	
	
	while(k->left != NULL){
		k2 = k;
		k = k->left;
	}//while loop for moving to left most node
	
	cout<<"\n\n\tThe id of k2 should be 55 & is: "<<k2->id;
	cout<<"\n\n\tThe id of k should be 52 & is: "<<k->id;
	
	p->id = k->id;
	
	k2->left = k->right;
	
	delete k;		
		
	}
	
}

void root_node(BST *p){
	
	p = root;
	
	cout<<"\n\n\tThe root node is: "<<p->id;
}

void average(BST *p){
	
	int sum = 0;
	int count = 0;
	double average1 = 0;
	
	if(p != NULL){
		average(p->left);
		sum = sum + p->id;
		count++;
		average(p->right);
		count++;
		
	cout<<"\n\n\tThe total sum is: "<<sum;
	cout<<"\n\n\tThe total nodes are: "<<count;
	
	average1 = sum/count;
	
	cout<<"\n\n\tThe average is: "<<average1;
	
		
	}
	
}