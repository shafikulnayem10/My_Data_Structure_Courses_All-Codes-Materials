#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

int precedence(char op)
{
    if(op == '^')
    {
        return 3;
    }
    else if(op == '*' || op == '/')
    {
        return 2;
    }
    else if(op == '+' || op == '-')
    {
        return 1;
    }
    else {
        return -1;
    }
}

string infixToPrefix(string infix)
{
    reverse(infix.begin(), infix.end());

    for(int i = 0; i <infix.length(); i++)
    {
        if(infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if(infix[i] == ')')
        {
            infix[i] = '(';
        }
    }
    stack<char> s1;
    string result;

    for(char c: infix)
    {
        if(isalnum(c))
        {
            result+=c;
        }
        else if(c ==  '(')
        {
            s1.push(c);
        }
        else if(c == ')')
        {
            while(!s1.empty() && s1.top() != '(')
            {
                result = result + s1.top();
                s1.pop();
            }
            if(!s1.empty())
            {
                s1.pop();
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            while(!s1.empty() && precedence(s1.top()) >= precedence(c) )
            {
                result = result + s1.top();
                s1.pop();
            }
            s1.push(c);
        }
    }
    while(!s1.empty())
    {
        result = result + s1.top();
        s1.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main ()
{
    string infix;
    cout << "Enter Infix Expression: ";
    getline(cin, infix);

    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: "<< prefix <<endl;
}

