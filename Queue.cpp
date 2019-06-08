#include<iostream>
using namespace std;
class Queue{
      int front;
      int rear;
      int list[100];
    public:
       void EnQueue();
       void deQueue();
       bool QueueIsEmpty();
    
    Queue(){
         front=-1;
         rear=-1;
    }


};


/*Inserting from rear & deletion from front.*/

void Queue::EnQueue(){
    int x;
     cout<<"Enter elememt: ";
     cin>>x;
     if(QueueIsEmpty()){
        front++;
        rear++;
        list[rear]=x;
    }
    else{
        rear++;
        list[rear]=x;  
    }    
}
void Queue::deQueue(){
     if(QueueIsEmpty()){
        cout<<"Queue is already Empty.";
       }
     else{
       int temp=list[front];
           front++;
       cout<<"The element "<<temp<<"is deleted from Queue"<<endl;
        }
}
bool Queue::QueueIsEmpty(){
     if(front==-1&&rear==-1) 
         return true;
    else
       return false;
}
void menu(){
   cout<<"\t\t MENU"<<endl;
   cout<<"1.Add element to queue"<<endl;
   cout<<"2.Delete from queue"<<endl;
   cout<<"3.Display Queue"<<endl;
}
int main(){
    Queue A;
    char Continue='Y';
    int option;
    while(Continue=='Y'||Continue=='y'){
        menu();
       cout<<"Enter Option from menu: ";
       cin>>option;
     switch(option){
        case 1: A.EnQueue();
                break;
        case 2: A.deQueue();
                break;
    }
     }
    
    
}