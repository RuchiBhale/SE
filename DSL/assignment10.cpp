#include <iostream>
#include <cstring>
using namespace std;

#define max 100

class Stack 
{
    public:
        int top;
        char a[max];

    public:
        Stack() { top = -1; }
        bool isEmpty(){
            return (top < 0);
        }
        char peek(){
            return a[top];
        }
        char pop(){
            if(top<0)
    {
        return 0;
    }
    else
        return a[top--];
        }

        bool push(char x){
            if(top >=max-1)
    {
        return false;
    }
    else
    {
        a[++top] = x;
        return true;
         }
    }
 };

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
  

int main()
{
    Stack s;
    cout<<"Enter infix Expression: ";
    string exp;
    cin>>exp;
    bool flag=0;
    string result="";
    for(int i=0;i<exp.length();i++)
    {
        char c = exp[i];
        if(c=='{' or c=='[' or c=='(')
            s.push(c);
        
        if(c=='}' or c==']' or c==')')
        {
            char t = s.pop();
            if(c=='}' and t=='{')
                continue;
            else if(c==']' and t=='[')
                continue;
            else if(c==')' and t=='(')
                continue;
            else
                flag=1;
                break;
        }   
    }

    if(flag)
    {
        cout<<"Expression is not well parenthesized"<<endl;
        return 0;
    }
    else
    {
        for(int i=0;i<exp.length();i++)
        {
            char c = exp[i];
  
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
                || (c >= '0' && c <= '9'))
                result += c;
    
            else if (c == '(')
                s.push('(');
            else if (c == '{')
                s.push('{');
            else if (c == '[')
                s.push('[');

            else if (c == ')') 
            {
                while (s.peek() != '(')
                {
                    result += s.pop();
                }
                s.pop();
            }
            else if (c == '}') 
            {
                while (s.peek() != '{')
                {
                    result += s.pop();
                }
                s.pop();
            }
            else if (c == ']') 
            {
                while (s.peek() != '[')
                {
                    result += s.pop();
                }
                s.pop();
            }
            else
            {
                while (!s.isEmpty() && precedence(exp[i]) <= precedence(s.peek())) {
                    result += s.pop();
                }
                s.push(c);
            }
        }
        while (!s.isEmpty())
        {
            result += s.pop();
        }
    }

    cout<<endl<<"Postfix Expression: "<<result<<endl;

    for(int i=0;i<result.length();i++)
    {
        char c = result[i];
        if (c>=48 and c<=57)
        {
            s.push(c);
        }
        else
        {
            int a = s.pop()-48;
            int b = s.pop()-48;
            int res;
            if(c=='+')
                res = a+b;
            else if(c=='-')
                res = a-b;
            else if(c=='*')
                res = a*b;
            else if(c=='/')
                res = a/b;
            else if(c=='^')
                res = a^b;
            s.push(res+48);
        }
    }
    cout<<"Evaluation of postfix expression: "<<s.pop()<<endl;
    return 0;
}
