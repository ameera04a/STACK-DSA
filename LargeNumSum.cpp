#include<iostream>
#include<string>
#include<stack>
using namespace std;
class LargeNumber{
   
    stack<char> s1;//to store 1st num digit by digit
    stack<char> s2;//to store 2nd num digit by digit
    stack<int> result;//to store sum digit by digit
    public:
    
    void pushNumber(string num1, string num2){
        for(char ch: num1){
            s1.push(ch);      
        }
        for(char ch: num2){
            s2.push(ch);    
        }
    }
    
    //note num cud be 234 and 32                             result stack
    // 4             add top of both stacks we get 4+2 =6     2
    // 3   2         add top 3+3 = 6                          6
    // 2   3         add top (2nd stack empty) so 2+0 = 2     6
    void sum(){
        int x, y, carry =0;

       while(!s1.empty() || !s2.empty()){
            x = y= 0; //incase one stack gets empty
            if(!s1.empty()){
                x = s1.top() - 48;
                s1.pop();
            }
            if(!s2.empty()){
                y = s2.top() - 48;
                s2.pop();
            }
            int answer = x+y+carry;
            if(answer>9){
                string temp = to_string(answer);
                //12 answer 
                //push 2 in result 1 in carry
                answer = temp[1] - 48;
                carry = temp[0] - 48;
                
            }
            else{
                carry = 0;
            }
            
            result.push(answer);

       }
       displaySum();
    }
    void displaySum(){
        
        while(!result.empty() ){
            cout<<result.top();
            result.pop();

        }

    }
};
int main(){
    string n1, n2 = "";
    cout<<"Input 1st non-negative number: ";
    getline(cin, n1);
    while(stoi(n1)<0){
        cout<<"Please input a non-negative number: ";
        getline(cin, n1);
    }

    cout<<"\nInput 2nd non-negative number: ";
    getline(cin, n2);
    while(stoi(n2)<0){
        cout<<"Please input a non-negative number: ";
        getline(cin, n2);
    }

    LargeNumber l;
    l.pushNumber(n1, n2);
    cout<<"\nThe sum is: ";
    l.sum();

}