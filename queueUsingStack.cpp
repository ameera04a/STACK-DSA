#include<iostream>
#include<string>
#include<stack>
using namespace std;
//global function, y cuz we hv to reverse two times on differnt stack
void reverseStack(stack<int> & first, stack<int> & sec){
    while(!first.empty() ){
        sec.push( first.top() );
        first.pop();
    }
}
class Queue{
    stack<int> enqueue;
    stack<int> dequeue;
    public:
    void pushNumber(int value){
        enqueue.push(value);
    }
   
    int popNumber(){
        //reverse the stack to get the 1st element and so on
        if(dequeue.empty()){
            reverseStack(enqueue, dequeue);//enqueue popped and stored in dequeued
        }
        if(dequeue.empty()){
            cout<<"Queue is empty";
            return -1;
        }

        int poppedValue = dequeue.top();
        dequeue.pop();

        return poppedValue;
    }
    int frontElement(){
        if(dequeue.empty()){
            reverseStack(enqueue, dequeue);//enqueue popped and stored in dequeued
        }
        if(dequeue.empty()){
            cout<<"Queue is empty";
            return -1;
        }

        int front = dequeue.top();
        
        return front;
    }
    void display(){

        stack<int> tempenqueue = enqueue, tempdequeue = dequeue;

        while(!tempdequeue.empty() ){
            cout<<tempdequeue.top()<<endl;
            tempdequeue.pop();
        }
        reverseStack(tempenqueue, tempdequeue);//enqueue popped and stored in dequeue

        while(!tempdequeue.empty() ){
            cout<<tempdequeue.top()<<endl;
            tempdequeue.pop();
        }
       
    }
};
int main(){
    Queue q;

    q.pushNumber(3);
    q.pushNumber(5);
    q.pushNumber(7);
    cout<<"front element in queue is: " << q.frontElement()<<endl;
    cout<<"popped value: "<<q.popNumber();
    cout<<"\nfront element in queue is: " << q.frontElement()<<endl;
    cout<<"\ndisplaying queue: ";
    q.display();

    
}
/*visual1       visual2 pop    visual 3 push/pop   visual 4 when de gets empty
en      de      en    de        en     de           en    de
3                     5         2       4                 0
4                     4         0       3                 2 
5                     3  */