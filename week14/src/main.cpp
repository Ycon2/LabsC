#include <iostream>
#include <string>
#include <vector>

class Stack {
private:
    std::vector<char> elements;
public:
    void push(char ch) {
        elements.push_back(ch);
    }

    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        }
    }

    char back() {
        if (!elements.empty()) {
            return elements.back();
        }
        return ' ';
    }

    bool empty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

bool isBalanced(const std::string& str) {
    Stack stack;
    for (char ch : str) {
        switch (ch) {
            case '(':
            case '{':
            case '[':
                stack.push(ch);
                break;
            case ')':
                if (stack.back() != '(' || stack.empty()) {
                    return false;
                }
                stack.pop();
                break;
            case '}':
                if (stack.back() != '{' || stack.empty()) {
                    return false;
                }
                stack.pop();
                break;
            case ']':
                if (stack.back() != '[' || stack.empty()) {
                    return false;
                }
                stack.pop();
                break;
            default:
                continue;
        }
    }
    return stack.empty();
}

int main() {
    std::string input;
    std::cout << "Enter a sequence of brackets: ";
    std::getline(std::cin, input);
    std::cout << (isBalanced(input) ? "Balanced" : "Not Balanced") << std::endl;
    return 0;
}
