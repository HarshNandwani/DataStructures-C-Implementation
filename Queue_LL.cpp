#include<iostream>
using namespace std;
struct Node{
      int data;
      Node *next;
}*front,*rear;
Node* create_node(){
      Node *newnode;
      newnode= new Node;
      if(newnode==NULL)
        cout<<"Memory Not allocated.";
      else{
         int value;
         cout<<"Enter value you want to enter in node: ";
         cin>>value;
        newnode->data=value;
        newnode->next=NULL;
        }
    return newnode;
}
void EnQueue(){
     Node *temp=create_node();
     if(rear==NULL)
       front=rear=temp;
     else{
        rear->next=temp;
        rear=temp;
       }
    rear->next=front;   
}
void deQueue(){
     if(front==NULL)
       cout<<"No Queue"<<endl;
     else{
        int t=front->data;
      if(front==rear)
         front=rear=NULL;
    
      else{
        front=front->next;
        rear->next=front;
      }
   cout<<t<<" removed from Queue\n";
    }
}
void Display(){
    Node *temp=front;
    cout<<temp->data<<" ";
    temp=temp->next;
        while(temp!=rear){
          cout<<temp->data<<" ";
          temp=temp->next;
        }
}
int main(){
    int op;
    
  while(1){
        cout<<"Enter option: ";
    cin>>op;
    switch(op){
        case 1: EnQueue();
                break;
        case 2: deQueue();
                break;
       
    }
        Display();
  }
  return 0;
}