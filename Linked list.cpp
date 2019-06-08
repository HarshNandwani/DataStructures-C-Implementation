#include<iostream>
using namespace std;
struct Node{
       int data;
       Node *next;
};
class linkedList{
      Node *head;
      public:
       linkedList(){
            head=NULL;
         }
       void menu();
       Node* createNode();
       void insertBeg();
       void insertPos();
       void insertEnd();
       void deleteVal();
       void Display();
};
int main(){
    linkedList l1;
    int op;
    while(1){
        l1.menu();
      cout<<"Enter an option from menu: ";
      cin>>op;
      switch(op){
          case 1: l1.insertBeg();
                  break;
          case 2: l1.insertPos();
                  break;
          case 3: l1.insertEnd();
                  break;
          case 4: l1.deleteVal(); 
                  break;
          case 5: l1.Display();
                  break;
          default: cout<<"Wromg option! Try Again"<<endl;
    }
        l1.Display();
 }
}
void linkedList::menu(){
cout<<"1.Insert Element at Begining \n"
    <<"2.Insert Element at Position \n"
    <<"3.Insert Element at End \n"
    <<"4.Delete a Element in the list \n"
    <<"5.Display all Elements of list \n";
    cout<<endl;
}
Node* linkedList::createNode(){
      int val;
      Node *temp=new Node;
    //check if temp is null 
    cout<<"Enter the number you want to insert in list: ";
    cin>>val;
    temp->data=val;
    temp->next=NULL;
    return temp;
}
void linkedList::insertBeg(){
     Node *temp=createNode();
     if(head==NULL)
       head=temp;
    else{
        temp->next=head;
        head=temp;
     }
    
}
void linkedList::insertEnd(){
     Node *temp,*start=head;
     temp=createNode();
    while(start->next!=NULL)
         start=start->next;
    start->next=temp;
}
void linkedList::insertPos(){
     Node *temp=createNode(),*start =head;
    int pos;
    cout<<"Enter the position at which you want to insert: ";
    cin>>pos;
    for(int i=1;i<pos-1;i++)
        start=start->next;
    temp->next=start->next;
    start->next=temp;
}
void linkedList::Display(){
     Node *start=head;
     if(start==NULL)
       cout<<"List is empty"<<endl;
     else
       cout<<"The list is: ";
     while(start!=NULL){
        cout<<start->data<<"  ";
        start=start->next;
    }
    cout<<endl<<endl;
    delete start;
}
void linkedList::deleteVal(){
     int val;
     Node *start=head,*p=NULL;
     cout<<"Enter the number you want to be deleted in list: ";
     cin>>val;
    if(start->data==val)
       head=head->next;
    else{
     while(start->data!=val){
         p=start;
         start=start->next;
      }
     p->next=start->next;   
    }  
}