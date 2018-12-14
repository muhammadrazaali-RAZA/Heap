#include<iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct node{
	int no;
	node *left,*right;
	int noode;
};

class Complete_Binary_Tree{
	
	public:
		node *root;
		int key,height,node_count,local_height,one_inser;
		Complete_Binary_Tree();
		~Complete_Binary_Tree();
		int power_fun(int x,int n);
		void insertion(node *);
		void options();
		void in_order(node *);
		void small_top(node*);
		void destory(node *);
		void percolateDown(int n,node *);
		
};

Complete_Binary_Tree::Complete_Binary_Tree(){
	root=NULL;
	height=node_count=local_height=0;
	one_inser=1;
}

void Complete_Binary_Tree::insertion(node *temp){
	if(root==NULL){
		root=new node;
		root->no=key;
		root->left=NULL;
		root->right=NULL;
		node_count++;
		root->noode=node_count;
		return;
	}
	
	if( temp->no==key ){
		cout<<" \n Given numbe r is already present in tree.\n";
		return;
	}
	
	if(power_fun(2,height+1)-1== node_count)
	{
    	if( temp->left!=NULL )
       	{
       		local_height++;
			insertion(temp->left);
			local_height--;
			return;
       	}
      	else
       	{
	 		temp->left=new node;
	 		temp->left->no = key;
	 		temp->left->left=NULL;
	 		temp->left->right=NULL;
	 		node_count++;
	 		temp->left->noode=node_count;
	 		height++;
	 		return;
       	}
   	}
   	if(power_fun(2,height+1)-1 > node_count){
   		
		if(one_inser){
			
			if (local_height==height-1){
	   			
	   			if( temp->left==NULL ){
	       			temp->left=new node;
		 			temp->left->no = key;
		 			temp->left->left=NULL;
		 			temp->left->right=NULL;
		 			node_count++;
		 			temp->left->noode=node_count;
		 			one_inser=0;
		 			return;
		 			
	       		}
	       		
	       		if( temp->right==NULL ){
	       			temp->right=new node;
		 			temp->right->no = key;
		 			temp->right->left=NULL;
		 			temp->right->right=NULL;
		 			node_count++;
		 			temp->right->noode=node_count;
		 			local_height=height;
		 			one_inser=0;
		 			return;
		 			
	       		}
	       		
	       		return;
			}
	   	
			if( temp->left!=NULL ){
				local_height++;
				insertion(temp->left);
				local_height--;
			}
			
			if(	temp->right!=NULL){
				local_height++;
				insertion(temp->right);
				local_height--;
			}
			
			return;
		
		}else{	return;}
	}
	
	cout<<"wrong side...!"<<endl;
	return;
}



void Complete_Binary_Tree:: options()
{
 	cout<<"\n\n ************** Select Option *****************.\n";
 	cout<<"\n Enter any of choices.\n";
 	cout<<"\n 0 : Quitting the Program.\n";
 	cout<<"\n 1 : Print the whole BST .\n";
 	cout<<"\n 2 : Adding (inserting) node in BST.\n";
 	cout<<"\n------------------------------\n";
 	cout<<"height        : "<<height<<endl;
	cout<<"local_height  : "<<local_height<<endl;
	cout<<"Nodes         : "<<node_count<<endl;
	cout<<"------------------------------\n";
}//--------------------------------------------------------------


void Complete_Binary_Tree:: in_order(node *temp)
{
  if(root==NULL)
    {
	cout<<" Tree is empty.\n";
	return;
    }
  if( temp->left!=NULL ){
  	cout<<"("<<temp->no<<")left->";
  	in_order(temp->left);
  }
    		 
  cout<<temp->no<<"  ";
  if( temp->right!=NULL ){
  	cout<<"("<<temp->no<<")right->";
  	in_order(temp->right);
  }
		 
  return;
}//----------------------------    PROGRAM ENDS HERE  ---------------------------------------
/////--------------power function --------//////
int Complete_Binary_Tree::power_fun(int x,int n){
	int mul=1;
	for(int i=1; i<=n; i++){
		mul=mul*x;
	}
	return mul;
}
/////--------------power function --------//////

////---------------small_top--------------//////
void Complete_Binary_Tree::small_top(node *temp){
	
	for(int i=node_count/2; i>0 ; i--){
		percolateDown(i,root);
	}
	return;
}

void Complete_Binary_Tree::percolateDown(int n , node *temp){
	
	if(temp->noode==n){
		
		if(temp->right!=NULL && temp->no > temp->right->no){
			key=temp->right->no;
			temp->right->no=temp->no;
			temp->no=key;
		}
		
		if(temp->left!=NULL && temp->no > temp->left->no){
			key=temp->left->no;
			temp->left->no=temp->no;
			temp->no=key;
		}
		return;
	}
	
	if(temp->left !=NULL && temp->right != NULL){
		percolateDown(n,temp->left);
		percolateDown(n,temp->right);
		return;
	}
	
	if(temp->left !=NULL && temp->right == NULL){
		percolateDown(n,temp->left);
		return;
	}
	
	if(temp->left ==NULL && temp->right == NULL){
		return;
	}
	
	cout<<"Some problem....!"<<endl;
	return;
}
////---------------small_top--------------//////

//----------------------- destory tree Function Starts  -----------------------

Complete_Binary_Tree::~Complete_Binary_Tree(){
	destory(root);
	cout<<"Done "<<endl;
}

void Complete_Binary_Tree::destory(node *temp){
	if(temp->left!=NULL && temp->right!=NULL){
		destory(temp->left);
		destory(temp->right);
		delete temp;
		temp=NULL;
		return;
	}

	
	else if(temp->left!=NULL && temp->right==NULL){
		destory(temp->left);
		delete temp;
		temp=NULL;
		return;
	}

	else if(temp->left==NULL && temp->right!=NULL){
		destory(temp->right);
		delete temp;
		temp=NULL;
		return;
	}
	
	else{
		delete temp;
		temp=NULL;
		return;
	}
	root=NULL;
}



////-------------------destory function ends -----------//////



int main(){
	char ch;
  	Complete_Binary_Tree obj;
  	while( 4 )
  	{
    obj.options();
    ch=getch();
    switch(ch)
     {
       	case '0':
       		obj.destory(obj.root);
			cout<<"Done "<<endl;
			exit(0);
			break;
		
		case '1':
			obj.in_order(obj.root);
			break;
		case '2':
			cout<<"Enter key : ";
			cin>>obj.key;
			obj.one_inser=1;
			obj.insertion(obj.root);
			obj.local_height=0;
			obj.small_top(obj.root);
			break;
       	default :
			exit(0);
			break;
     } // end of switch.
  } // end of while.
}//-----------------------------------------------


