#include <iostream>
#include "StackC.h"
#include "StackInt.h"
using namespace std;
int prec(int c){
    if (c == '+' || c == '-')return 1;
    else if (c=='*' || c== '/') return 2;
    else return 0;
}

string getPostFix(string infix){
    StackC st(10);
    st.push('(');
    string postfix;
    infix += ')';

    for(int i=0;i<infix.length();i++){
        char ch = infix[i];
        if(ch >='0' && ch <= '9'){
            postfix +=ch;
        }
        else if (ch == '('){
            st.push(ch);
        }
        else if(ch == ')'){
            while(st.getTop() != '('){
                postfix += st.getTop();
                st.pop();
            }
            st.pop();
        }
        else{
            if(prec(ch) > prec(st.getTop())){
                st.push(ch);
            }
            else{
                while(prec(st.getTop()) >= prec(ch)){
                    postfix += st.getTop();
                    st.pop();
                }
                st.push(ch);

            }

        }

    }
    return postfix;

}
int evaluate(string postfix){
    StackInt st(10);
    for(int i=0;i<postfix.length();i++){
        char ch = postfix[i];
        if(ch>='0' && ch <='9'){
                //stoi("111"); 111 int
            st.push(ch-48);
        }
        else{
            int op2 = st.getTop();
            st.pop();
            int op1 = st.getTop();
            st.pop();
            int rs=0;
            switch(ch){
            case '+':
                rs = op1+op2;
                break;
            case '-':
                rs = op1 - op2;
                break;
            case '*':
                rs = op1 * op2;
                break;
            case '/':
                rs = op1/op2;
                break;

            }
            st.push(rs);
        }
    }
    return st.getTop();
}



int main()
{
    string input = "2+3-4*5+6+(7-8)";
    string postfix = getPostFix(input);
    int result = evaluate(postfix);
    cout << result;

    return 0;
}
