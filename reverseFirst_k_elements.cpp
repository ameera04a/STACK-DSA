#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

class ReverseElements{
    queue<int> q;
    public:
    void display(int k){
        queue<int> temp = q;
        cout << "Queue after reversing first " << k << " elements: ";
        while( !temp.empty() ){
            cout<<temp.front()<<" ";
            temp.pop();
        }
    }
    void pushElements(int value){
        q.push(value);
    }
    void reverseFirstK(int k){
        //pop k elements and push onto stack 
        stack <int> tempStack;
        int size = q.size();

        for(int i=0; i<k; i++){
            tempStack.push( q.front() );
            q.pop();
        }
        // pop stack n push in queue
        while( !tempStack.empty() ){
            q.push( tempStack.top() );
            tempStack.pop();
        }

        //pop and push the remaining elements to maintain order
        for(int i=0; i<size-k; i++){
            q.push( q.front() );
            q.pop();
        }
        
    }
    void reverseElements( int k ){
        int size = q.size();

        if(k == 0 || k==1){
            //no reverse needed print original
            display(k);
        }
        else if(k>size){
            //make k equal to size and reverse the whole queue
            cout<<"\nonly "<<size<<" elements in queue not "<<k<<endl;
            k= size;
            reverseFirstK(k);
            display(k);
        }
        else{
            //main part
            cout<<"k";
            reverseFirstK(k);
            display(k);
        }
    }
    
};
int main() {
    ReverseElements re;
    int n, element, k;

    cout << "Enter number of elements in queue: ";
    cin >> n;

    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> element;
        re.pushElements(element);
    }

    cout << "Enter value of K: ";
    cin >> k;

    re.reverseElements(k);

    return 0;
}
/*Input Queue:
10 20 30 40 50

K = 3
Steps:

Push 10, 20, 30 into stack → Stack = [30, 20, 10]

Pop from stack and push into queue → Queue = [ 40, 50, 30, 20, 10]

pop and push size - k times meaning
pop 40 push 40 in queue it gives  [ 50, 30, 20, 10, 40]
pop 50 and push again it gives    [ 30, 20, 10, 40, 50]

✅ Done!*/