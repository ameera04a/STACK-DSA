#include<iostream>
#include<string>
#include<cstring>
#include<stack>
using namespace std;
class PalindromeChecker {
    stack<char> str;
    stack<char> revStr;
    public:
    void pushString(string input){
        for(char ch: input ){
            if( isalnum(ch) ){
                ch = tolower(ch);//note if lowercase letter it stays lowercase
            }
            str.push(ch);
        }
    }
    void reverseString(){
        stack <char> temp = str;//copy constructor 
        /*note: use temp cuz we wud be popping and 
        we dont want our original stack to get empty */

        while( !temp.empty() ){
            
            revStr.push( temp.top() );
            temp.pop();
        }
    }
    /*visual 1                                visual 2
    og    reversed    match tops           og   reversed     match tops
    t     c           no match break       c    c            match
    a     a                                a    a            match
    c     t                                c    c            match       */
    bool isPalindrome(string input){
        //push string onto stack 
        pushString(input);
        //reverse string store in  another stack
        reverseString();
        //match tops
        bool match= true;
        while( !str.empty() ){
            
            if( str.top() != revStr.top() ){
                match= false;
                break;
            }
            //top matched, pop so that the lower char is now top
            str.pop();
            revStr.pop();

        }

        return match;
    }
};
int main(){
    string input="";
    cout << "Enter a string: ";
    getline(cin, input);

    PalindromeChecker  p;
  
    if( p.isPalindrome(input) ){
        cout << "'" << input << "' is a palindrome!" << endl;

    }
    else{
        cout << "'" << input << "' is not a palindrome." <<endl;
    }
}


/*note if we cant use <cctype> or <cstring> do this
for isallnum() do this
if ((c >= 'A' && c <= 'Z') ||
   (c >= 'a' && c <= 'z') ||
   (c >= '0' && c <= '9')) {
    // It's alphanumeric
}
for tolower() do this
Only convert if uppercase
if (c >= 'A' && c <= 'Z') {
   c = c + 32; // 'A' (65) + 32 = 'a' (97)
}*/