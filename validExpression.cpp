#include<iostream>
#include<string>
#include<stack>
using namespace std;
class ParenthesisChecker{
    stack<char> str;
    public:
   
    bool isValid(string input ){
        bool match = false;
        for(char ch: input ){
            if(ch=='(' || ch=='[' || ch=='{'){
                str.push(ch);
            }
            else {
                if (str.empty()) return false;
    
                char top = str.top();
                if ((ch == ')' && top == '(') ||
                    (ch == ']' && top == '[') ||
                    (ch == '}' && top == '{')) {
                    str.pop(); // matched pair
                } else {
                    return false; // mismatch
                }
            }
        }
    
        return str.empty(); // all brackets matched

        
       
    }
};
int main(){
    string input="";
    cout << "Enter a string: ";
    getline(cin, input);

    ParenthesisChecker  p;
}
/*visual
({}[])

'(' → push → ['(']

'{' → push → ['(', '{']

'}' → matches '{' → pop → ['(']

'[' → push → ['(', '[']

']' → matches '[' → pop → ['(']

')' → matches '(' → pop → []

Final stack: empty →  Valid*/
    