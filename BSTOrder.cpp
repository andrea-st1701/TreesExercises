#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
	int cont;
	node* left=NULL;
	node* right=NULL;
};
class tree
{
	private:
		node* root;
		int* ord; 
		int count;
	public:
		tree();
		void addNode();
		node* getRoot();
		 void InOrder(node* p);
		friend void shiftRight(int i, tree *a);
};
void shiftRight(int i, tree *a)
{
	for(int j=a->count-1; j>i; j--)
	{
		a->ord[j]=a->ord[j-1];
	}
}
void tree::InOrder(node* p)
{
	if(p)
	{
		InOrder(p->left);
		if(count==0)
		{
			ord[0]=p->cont;
			count++;
			
		}
		else
		{
			ord = (int*) realloc(ord, (count+1)*sizeof(int));
			for(int i=0; i<count; i++)
			{
				cout<<ord[i]<<" ";
			}
			cout<<"\n";
			if(!ord)
			{
				cout<<"ERROR";
			}
			count++;
			for(int i=0; i<count; i++)
			{
				if(ord[i]>p->cont)
				{
					
						shiftRight(i-1, this);
						ord[i]=p->cont;
						break;
					
				}
				else if(i==count-1)
				{
					ord[i]=p->cont;
				}
			}
		}
		InOrder(p->right);
		
	}
}
tree::tree()
{
	root=NULL;
	ord=(int*)malloc (1);
	count=0;
}
node* tree::getRoot()
{
	return root;
}
void tree::addNode()
{
	char a;
	node *p;
	do
	{
		int c;
		cout<<"insert number\n";
		cin>>c;
		if(!root)
		 {
		 	root=new node;
		 	root->cont=c;
		 	p=root;
		 }
		else
		{
			if(c>=p->cont)
			{
				if(!p->right)
				{
					cout<<"more than\n";
					p->right=new node;
					p->right->cont=c;
				}
				else
				{
					p=p->right;
					if(c>=p->cont)
					{
						p->right=new node;
						p->right->cont=c;
					}
				}
			}
			if(c<p->cont)
			{
				if(!p->left)
				{
					cout<<"less than\n";
					p->left=new node;
					p->left->cont=c;
				}
				else
				{
					p=p->left;
					if(c<p->cont)
					{
						p->left=new node;
						p->left->cont=c;
					}
					else
					{
						p->right=new node;
						p->right->cont=c;
					}
				}
			}
		}
		do
		{	
			cout<<"write a to add t to terminate\n";
			cin>>a;
		}while(a!='a'&&a!='t');
		
	}while(a=='a');
	cout<<"\nOrdering...\n\n";
	InOrder(root);
	for(int i=0; i<count; i++)
	{
		cout<<ord[i]<<" ";
	}
}

int main()
{
	tree a;
	a.addNode();
	
}
