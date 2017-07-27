#include <iostream>
using namespace std;

struct node{
	char task;
	int data;
	node *next;
};

int main(){
	int p,r;
	cout<<"Enter no. of processes";
	cin>>p;
	cout<<"Enter no. of resources";
	cin>>r;
	int *res;
	res=new int[r];
	cout<<"Enter instancibility of resources\n";
	for(int i=0;i<r;i++){
		cout<<"Enter R"<<i<<endl;
		cin>>res[i];
	}
	cout<<"Enter proceses\n";
	node **head=new node*[p];
	node *temp;
	temp=new node;
	
	for(int i=0;i<p;i++){
		head[i]=new node;
		temp=head[i];
		cout<<"Enter process "<<i<<endl;
		while(true){
			cin>>temp->task;
			if(temp->task=='h'){
				temp->data=0;
				break;
			}
			else{
				cin>>temp->data;
				temp->next=new node;
				temp=temp->next;
			}
		}
	}
	
	cout<<endl<<endl;
	cout<<"T\t\t";
	for(int i=0;i<p;i++){
		cout<<"p"<<i<<"\t";
	}
	cout<<"\t\t";
	for(int i=0;i<r;i++){
		cout<<"r"<<i<<"\t";
	}
	cout<<endl;
	
	cout<<"0\t\t";
	for(int i=0;i<p;i++){
		cout<<"U "<<"\t";
	}
	cout<<"\t\t";
	for(int i=0;i<r;i++){
		cout<<res[i]<<"\t";
	}
	cout<<endl;
	int t=1;
	int *complete;
	complete = new int[p];
	for(int i=0;i<p;i++){
		complete[i]=0;
	}
	
	while(true){
		cout<<t<<"\t\t";
		for(int i=0;i<p;i++){
			if(head[i]->task=='c'){
				if(head[i]->data==0){
					head[i]=head[i]->next;
					i=i-1;
				}
					
				else{
					cout<<"C\t";
					head[i]->data=head[i]->data-1;
				}
					
				
			}
			else
			if(head[i]->task=='r'){
				
				if(res[head[i]->data]==0){
					cout<<"W\t";
				}
				else{
					res[head[i]->data]=res[head[i]->data]-1;
					head[i]=head[i]->next;
					i=i-1;
				}
			}
			else
			if(head[i]->task=='f'){
				res[head[i]->data]=res[head[i]->data]+1;
				head[i]=head[i]->next;
				i=i-1;
			}
			else
			if(head[i]->task=='h'){
				cout<<"H\t";
				complete[i]=1;
			}

			
		}
		cout<<"\t\t";
		
		
		for(int i=0;i<r;i++){
			cout<<res[i]<<"\t";
		}
		cout<<endl;
		t=t+1;
		int j=0;
		for(j=0;j<p;j++){
			if(complete[j]==0){
				break;
			}
		}
		if(j==p){
			break;
		}
	
		
	}
	
	
	return 0;
	
}
