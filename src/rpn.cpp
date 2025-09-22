#include "rpn.h"
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cmath>

double evaluate_rpn(const std::string& expression) {
    std::stack<double> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // ВАЖНО: Проверяем что в стеке достаточно операндов ДО извлечения
            if (stack.size() < 2) {
                throw std::runtime_error("Not enough operands for operator: " + token);
            }
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            
            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else if (token == "/") {
                if (b == 0) throw std::runtime_error("Division by zero");
                stack.push(a / b);
            }
        }
        else if (token == "sqrt") {
            // Проверяем что в стеке достаточно операндов
            if (stack.empty()) {
                throw std::runtime_error("Not enough operands for sqrt");
            }
            double a = stack.top(); stack.pop();
            if (a < 0) throw std::runtime_error("Square root of negative number");
            stack.push(std::sqrt(a));
        }
        else {
            try {
                stack.push(std::stod(token));
            } catch (const std::exception&) {
                throw std::runtime_error("Invalid number: " + token);
            }
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Invalid expression");
    }

    return stack.top();
}
