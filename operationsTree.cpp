#include <iostream>
#include <cmath>
using namespace std;
struct node
{
	node* left=NULL;
	node* right=NULL;
	node* prec;
	int cont;
};
class tree
{
	private:
		node* root;
		string add;
	public:
		tree();
		void insertNode();
		node* getRoot(){return root;	};
		float calculate(node* p);
		void Pot(node* p);
};
tree::tree()
{
	root=NULL;
	add="Root";
}
void tree::insertNode()
{
	string c;
	char  b;
	bool end=false;
	if(!root)
	{	
		cout<<"insert value for root\n";
		cin>>c;
		if(c.length()>1)
		{
			int sum=0;
			for(int n=c.length()-1; n>-1; n--)
			{
				sum+=(c[n]-48)*pow(10,(c.length()-n-1));
			}
			c[0]=sum;
		}
		else c[0]-=48;
		root= new node;
		root->cont=c[0]+48;
	}
	node* p=root;
	while(!end)
	{
		
			
			int a;
			while(p->left!=NULL&&a!=3)
			{
				a=0;
				do
				{
					cout<<add<<endl;
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
				if(c.length()>1)
				{
					char sum=0;
					for(int n=c.length()-1; n>-1; n--)
					{
						sum+=(c[n]-48)*pow(10,(c.length()-n-1));
					}
					c[0]=sum;
				}
				else c[0]-=48;
				if(!p->left)
				{
					p->left=new node;
					p->left->cont=c[0]+48;
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
							p->left->cont=c[0];
						}
						if(b=='n')
						{
							continue;
						}
					}while(b!='n'&&b!='y');
					
				}
				cout<<"add right value for this node (nothing if null)\n";
				cin>>c;
				if(c.length()>1)
				{
					int sum=0;
					for(int n=c.length()-1; n>-1; n--)
					{
						sum+=(c[n]-48)*pow(10,(c.length()-n-1));
					}
					c[0]=sum;

				}
				else c[0]-=48;
				if(!p->right)
				{
					p->right=new node;
					p->right->cont=c[0]+48;
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
							p->right->cont=c[0];
						}
						if(b=='n')
						{
							continue;
						}
					}while(b!='n'&&b!='y');
					
				}
			}
		}
}
float tree::calculate(node* p)
{

	if(p)
	{
		switch(p->cont)
		{
			case '+':
				return calculate(p->left)+calculate(p->right);
				break;
			case '-':
				return calculate(p->left)-calculate(p->right);
				break;
			case '*':
				return calculate(p->left)*calculate(p->right);
				break;
			case '/':
				return calculate(p->left)/calculate(p->right);
				break;
			default:
				return p->cont-48;//N.B. '0'=48 in ascii table;
				break;
		}
		

	}
	else
	{
		cout<<"0\n";
		return 0;
		
	}
	
} 
int main()
{
	tree a;
	a.insertNode();
	float c=0;
	c=a.calculate(a.getRoot());
	cout<<"total is "<<c;
}
