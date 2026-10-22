#include <iostream>
#include <cctype>
#include <queue>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(const string& input){

    stack<char> s;
    queue<char> q;

    for (char c : input) {
        s.push(c);
        q.push(c);
    }

    while (!s.empty()) {
        if (s.top() != q.front()) {
            return false;
        }

        s.pop();
        q.pop();
    }

    return true;

}
int main(){
    cout<<boolalpha;
    cout<<" Is 'racecar' a palindrome? "<<isPalindrome("racecar")<<endl;
    cout<<" Is 'hello' a palindrome? "<<isPalindrome("hello")<<endl;
    return 0;
}