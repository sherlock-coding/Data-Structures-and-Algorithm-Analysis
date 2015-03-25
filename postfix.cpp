/*
 * =====================================================================================
 *
 *       Filename:  postfix.cpp
 *
 *    Description:  中缀到后缀的转换
 *
 *        Version:  1.0
 *        Created:  2015年03月25日 19时43分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <stack>

using namespace std;


stack<char> s;

// 判断运算符的优先级
// 0,1,2三种
int getPriority(const char op) 
{
    switch (op) {
    case '+':
    case '-':
        return 0;
    case '*':
    case '/':
        return 1;
    case '(':
    case ')':
        return 2;
    }
}

//判断栈顶运算符和当前运算符的级别，决定入栈还是输出
void process(const char op, string& postfix)
{
    int nCount = s.size();
    if(nCount == 0) {
        s.push(op);
        return;
    }

    for (int i=0; i<nCount; ++i) {
        if(s.top()== '(') {
            s.push(op);
            break;
        }
        if(getPriority(op) > getPriority(s.top())) {
            s.push(op);
            break;
        }
        else {
            postfix += s.top();
            s.pop();
        }
    }
    if (s.size()==0) {
        s.push(op);
    }
}

void Infix2Postfix(const string& infix, string& postfix) {
    for (int i = 0; i < infix.size(); ++i) {
        switch(infix[i]) {
        case '+':
        case '-':
        case '*':
        case '/':
            process(infix[i], postfix);
            break;
        case '(':
            s.push(infix[i]);
            break;
        case ')':
            while(s.top()!= '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
            break;
        default:
            postfix += infix[i];
            break;
        }
    }
    while (s.size()!=0) {
        postfix += s.top();
        s.pop();
    }
}

int main()
{
    string istr = "a+b*c+(d*e+f)*g";
    string ostr = "";

    Infix2Postfix(istr, ostr);
    cout << ostr << endl;

    return 0;
}
