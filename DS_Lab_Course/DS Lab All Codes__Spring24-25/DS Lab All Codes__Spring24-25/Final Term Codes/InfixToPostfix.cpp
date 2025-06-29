#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int precedence (char op)
{
    if(op == '^')
    {
        return 3;
    }
    if(op == '*' || op == '/')
    {
        return 2;
    }
    if(op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string inFixToPostFix(string infix)
{
    stack<char> st;
    string result;

    for(char c: infix)
    {
        if(isalnum(c))
        {
            result = result+c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if(c == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                result = result+st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        result = result+st.top();
        st.pop();
    }
    return result;
}


int main()
{
    cout << "Enter the infix expression: ";
    string infix;
    getline(cin, infix);

    string prefix = inFixToPostFix(infix);
    cout << "\nPostfix expression: " << prefix;
}
