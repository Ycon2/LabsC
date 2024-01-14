#include <iostream>
#include <string>
#include <stack>


bool isValidBrackets(std::string userInput) {
    std::stack<char> stk;
    for (int i = 0; i < userInput.size(); i++) {
        if (stk.empty()) {
            stk.push(userInput[i]);
            continue;
        }
        char bracket;
        switch (stk.top()) {
            case '{':
                bracket = '}';
                break;
            case '[':
                bracket = ']';
                break;
            case '(':
                bracket = ')';
                break;
        }
        if (userInput[i] == bracket) stk.pop();
        else stk.push(userInput[i]);
    }
    if (stk.size() == 0) return true;
    else return false;
}

