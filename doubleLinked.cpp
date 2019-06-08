#include<iostream>
using namespace std;
struct Node{
      int data;
      Node *prev,*next;
};
class doubleLinked{
      Node *head;
    public:
      doubleLinked(){
         head=NULL;
       }
      void menu();
      Node* createNode();
      void insertBeg();
      void insertEnd();
      void deleteVal();
      void displayBeg();
      void displayRev();
};
/*main*/
int main(){
    doubleLinked list;
     int op;
    while(1){
        list.menu();
      cout<<"Enter an option from menu: ";
      cin>>op;
      switch(op){
          case 1: list.insertBeg();
                  break;
          case 2: list.insertEnd();
                  break;
          case 3: list.deleteVal(); 
                  break;
          case 4: list.displayBeg();
                  break;
          case 5: list.displayRev();
          default: cout<<"Wromg option! Try Again"<<endl;
    }
        list.displayBeg();
 }

}
void doubleLinked::menu(){
cout<<"1.Insert Element at Begining \n"
    <<"2.Insert Element at End \n"
    <<"3.Delete a Element in the list \n"
    <<"4.Display all Elements of list \n"
    <<"5.Display Elements in reverse order\n";
    cout<<endl;
}
Node* doubleLinked::createNode(){
      Node *newnode; int val;
      newnode=new Node;
      cout<<"Enter the number you want to insert in list: ";
      cin>>val;
       newnode->data=val;
       newnode->prev=NULL;
       newnode->next=NULL;
    return newnode;
    
}
void doubleLinked::insertBeg(){
     Node *temp=createNode();
     if(head==NULL)  
        head=temp;
     else{
        temp->next=head;
        head->prev=temp;
        head=temp;
        } 
}
void doubleLinked::insertEnd(){
     Node *temp=createNode(),*start=head;
     while(start->next!=NULL)
          start=start->next;
     temp->prev=start;
     start->next=temp;
}
void doubleLinked::deleteVal(){
     int val;
     Node *start=head;
    cout<<"Enter the number you want to be deleted in list: ";
    cin>>val;
    if(start->data==val){
       head=head->next;
       head->prev=NULL;
      }
    else{
       while(start->data!=val)
         start=start->next;
    Node *p=start->prev;
    p->next=start->next;
    if(start->next!=NULL)
    start->next->prev=p;
   }   

}
void doubleLinked::displayBeg(){
     Node *start=head;   
     if(start==NULL)
       cout<<"List is empty!"<<endl;
     else
       cout<<"The list is: ";
     while(start!=NULL){
       cout<<start->data<<"  ";
       start=start->next;
     }
    cout<<endl<<endl;  
    delete start;
}
void doubleLinked::displayRev(){
     Node *start=head;
     if(start==NULL)
       cout<<"List is empty!"<<endl;
     else
       cout<<"The list in reverse order is: ";
     while(start->next!=NULL)
       start=start->next;
     while(start!=NULL){
       cout<<start->data<<"  ";
       start=start->prev;
    }
   delete start;
}