#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
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
    return -1;
}

string infixToPrefix (string infix)
{
    stack<char> st;
    string result;
    for(char c: infix)
    {
        if(isalnum(c))
        {
            result = result+c;
        }
        else if(c == '(')
        {
            st.push(c);
        }
        else if(c == ')')
        {
            while(!st.empty() && st.top()!= '(')
            {
                result = result+st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();  // Remove '('
            }
        }
        else if(c == '^' || c == '+' || c == '-' || c == '*' || c == '/')
        {
            while(!st.empty() && precedence(st.top()) >= precedence(c))
            {
                result = result+st.top();
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

int main ()
{
    string infix;
    cout<< "Infix Expression: ";
    getline(cin, infix);

    string result = infixToPrefix(infix);
    cout << "Postfix Expression: " <<result <<endl;
}

