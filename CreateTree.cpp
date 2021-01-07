#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
struct node
{
	char cont;
	node* left=NULL;
	node* right=NULL;
	node* prec=NULL;
};
class tree
{
	private:
		node* root;
	public:
		string add;
		tree();
		void addRoot();
		void addNode();
		node* getRoot();
		void Pot(node* p);
};

tree::tree()
{
	root=NULL;
	add="Root";
}
node* tree::getRoot()
{
	return root;
}
void tree::Pot(node* p)
{
	if(p)
	{
		cout<<p->cont<<" ";
		Pot(p->left);
		Pot(p->right);
	}
}
void tree::addRoot()
{
	char c;
	
		cout<<"insert value for root\n";
		cin>>c;
		root= new node;
		root->cont=c;	
	
}
void tree::addNode()
{
	char c, b;
	bool end=false;
	node* p=root;
	while(!end)
	{
		
			
			int a=0;
			while(p->left!=NULL&&a!=3)
			{
				a=0;
				do
				{
					cout<<add<<endl;;
					cout<<"do you want to go left (write 0), right (write 1), or back (write 2) to stop the navigation write 3, to save the tree and close write 4\n";
					cin>>a;
				}while(a!=0&&a!=1&&a!=2&&a!=3&&a!=4);
				if(a==0)
				{
					p=p->left;
					add+="\\l";
				}
				if(a==1)
				{
					p=p->right;
					add+="\\r";
				}
				if(a==2)
				{
					if(p->prec)
					{
						p=p->prec;
						add.erase(add.size()-1);
						add.erase(add.size()-1);
					}
					else
					{
						cout<<"ERROR";
					}
				}
				if(a==4)
				{
					end=true;
					break;
				}
			}
			if(!end)
			{
				cout<<"add left value for this node (nothing if null)\n";
				cin>>c;
				if(!p->left)
				{
					p->left=new node;
					p->left->cont=c;
					p->left->prec=p;
				}
				else
				{
					do
					{
						cout<<"left value for this node is "<<p->left->cont<<" overwrite? (y/n)";
						cin>>b;
						if(b=='y')
						{
							p->left->cont=c;
						}
						if(b=='n')
						{
							continue;
						}
					}while(b!='n'&&b!='y');
					
				}
				cout<<"add right value for this node (nothing if null)\n";
				cin>>c;
				if(!p->right)
				{
					p->right=new node;
					p->right->cont=c;
					p->right->prec=p;
				}
				else
				{
					do
					{
						cout<<"right value for this node is "<<p->right->cont<<" overwrite? (y/n)";
						cin>>b;
						if(b=='y')
						{
							p->right->cont=c;
						}
						if(b=='n')
						{
							continue;
						}
					}while(b!='n'&&b!='y');
					
				}
			}
		}
		Pot(root);
	}
bool compareNode( node *n0, node *n1)
{
	bool eq=1;
	if(!n0||!n1)
	{
		if(!n0&&!n1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	cout<<endl<<n0->cont<<" "<<n1->cont<<endl;
	if(n0->cont!=n1->cont)
	{
		eq=0;
		return eq;
	}
	if(eq)
	{
		eq=compareNode( n0->left, n1->left);
		eq=compareNode( n0->right, n1->right);
	}
	return eq;
}
bool compareTree(tree* t0, tree* t1)
{
	node* p;
	node* t;
	bool eq= true;
	p=new node;
	t=new node;
	p=t0->getRoot();
	t=t1->getRoot();
	eq=compareNode( p, t);
	return eq;
}

int main()
{
	bool eq;
	char f;
	int  n=0;
	tree** Trees;
	Trees=(tree**)malloc (1);
	if (!Trees) exit (1);
	Trees[0]=new tree;
	do 
	{
		cout<<"\nTree "<<n+1<<endl;
		Trees[n]->addRoot();
		Trees[n]->addNode();
		do
		{
			cout<<"\ndo you want to add another tree(a), or compare two trees (c)\n";
			cin>>f;
		}while(f!='a'&&f!='c');
		if(f=='a')
		{
			n++;
			Trees=(tree**)realloc(Trees, (n+1)*sizeof(tree*));
			if(!Trees) exit(1);
			Trees[n]=new tree;
		}
	}while(f=='a');
	int comp1, comp2;
	do
	{
		cout<<"\nwhich trees do you want to compare?\n";
		cin>>comp1>>comp2;
	}while(!Trees[comp1-1]||!Trees[comp2-1]);
	
	
	cout<<"\ncomparing trees...\n";
	eq=compareTree(Trees[comp1-1], Trees[comp2-1]);
	if(eq)
	{
		cout<<"the selected trees are equal";
	}
	else
	{
		cout<<"the selected trees are NOT equal";
	}	
}
