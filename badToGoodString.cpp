#include<iostream>
#include<string>
#include<stack>
using namespace std;
class GoodString{
    stack<char> str;
    public:
    /* if stack top a   and   popped ch  Z       combo of small capital
       or stack top Z   and   popped ch  a       combo of capital small

            if combo found then further check if they r same?
            as A!=a so make both lower and check*/

    bool compare(char top, char poppedChar){
        if( ( islower(top) && isupper(poppedChar) ) || ( islower(poppedChar) && isupper(top) ) ){

            if( tolower(top) == tolower(poppedChar) ){
                return true;
            }
        }
        return false;
    }
    string reverseStack(){
        stack<char> finalStack;

        // move from working stack to finalStack
        while (!str.empty()) {
            finalStack.push(str.top());
            str.pop();
        }

        // build string from finalStack
        string result = "";
        while (!finalStack.empty()) {
            result += finalStack.top();
            finalStack.pop();
        }

        return result;
    }
    /*visual 
    Char	Stack Top	    Action	        Stack
    a	    (empty)	       Push	            ['a']
    b	    a 	           No match	        ['a', 'b']
    B	    b	           Match! Pop	    ['a']
    A	    a	           Match! Pop	    []
    c	    (empty)	       Push	            ['c']
    C	    c	           Match! Pop	    []
    */
    string makeGoodString(string input){
        
        /*compare ch from string and top one by one if match pop else push*/
        for(char ch : input){
            if (!str.empty() && compare(str.top(), ch)) {
                str.pop(); // A "bad" adjacent pair — remove both
            } else {
                str.push(ch); // Safe char — push it
            }
        }
        //reverse stack n make string
        return reverseStack();

    }
};
int main(){
    string input="";
    cout << "Enter a string: ";
    getline(cin, input);
    GoodString gs;
    cout<<"The good string is: "<< gs.makeGoodString(input);
}