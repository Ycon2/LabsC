#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(const std::string& input) {
  std::stack<char> stack;
  std::unordered_map<char, char> parenthesesMap {
    {')', '('},
    {'}', '{'},
    {']', '['}
  };

  for (char c : input) {
    if (c == '(' || c == '{' || c == '[') {
      // Если это открывающая скобка, помещаем ее в стек
      stack.push(c);
    } else if (c == ')' || c == '}' || c == ']') {
      // Если это закрывающая скобка
      if (stack.empty() || stack.top() != parenthesesMap[c]) {
        // Проверяем, соответствует ли закрывающая скобка открывающей
        return false;
      } else {
        stack.pop(); // Скобка соответствует — удаляем открывающую из стека
      }
    }
  }

  // Если в стеке остались открывающие скобки, значит входная строка невалидна
  return stack.empty();
}

int main() {
  std::string input;
  std::cout << "Введите строку: ";
  std::cin >> input;

  if (isValid(input)) {
    std::cout << "Строка валидна." << std::endl;
  } else {
    std::cout << "Строка невалидна." << std::endl;
  }

  return 0;
}
