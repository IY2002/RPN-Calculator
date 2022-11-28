#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cstdlib>

#include "list.h"
#include "stack.h"

using namespace std;

double CharToDouble(char ch);

int operandConverter (char j){
    if (j == '*' || j == '/' ) return 2;
    else if (j == '+' || j == '-') return 1;
    else return 0;
}

bool isOperator(char j){
    if(j == '*' || j == '/' ||j == '+' || j == '-'){
        return true;
    } else return false;
}

bool isNumber(char j){
    if ((j>='0' && j <= '9') ) return true;
    else return false;
}

double math(double x, double y, char sym){
    if(sym == '+') return x + y;
    if(sym == '-') return y - x;
    if(sym == '*') return y * x;
    if(sym == '/') return y/x;
    else return -1;
}

string InfixToPostfix(string infix)
{
    ///////////////////////////////////////////
    // Implement function body
   // throw "Rpn(const char* expr, int n, std::ostringstream& os) is not implemented.";
    string result;
    Stack<char> stack;
    int len = infix.length();
    for(int i =0; i < len ; i ++){
        char j = infix[i];
        // number is found
        if( (j>='0' && j <= '9') || (j >= 'a' && j <= 'z') || (j <= 'Z' && j >= 'A')){
            result +=  j;
        }
        // open brackets
        else if (j == '(') stack.Push(j);
        //closed brackets, pop till open brackets
        else if (j == ')'){
            while(stack.Top() != '('){
                result +=  stack.Pop();
            }
            stack.Pop();
        }
        else if (j == ';'){
            continue;
        }
        else {
            while(!stack.IsEmpty()&& operandConverter(j) <= operandConverter(stack.Top())  ){
                result += stack.Pop();
            }
            stack.Push(j);
        }
    }
    while (!stack.IsEmpty()){
        result += stack.Pop();
    }
    return result += ';';

    // Implement function body
    ///////////////////////////////////////////
}

double EvaluatePostfix(string postfix)
{
    ///////////////////////////////////////////
    // Implement function body
    //throw "Eval(const char* rpnexpr, int n) is not implemented.";
    Stack<double> stack;
    int len = postfix.length();
    double total, x, y;
    for (int i =0; i < len -1; i++){
        char j = postfix[i];
        if(isOperator(j)){
            x = stack.Pop();
            y = stack.Pop();
            stack.Push(math(x,y,j));

        } else if(isNumber(j))
            stack.Push(CharToDouble(j));
    }
    total = stack.Top();
    return total;

    // Implement function body
    ///////////////////////////////////////////
}
