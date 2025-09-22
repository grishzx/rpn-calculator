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
        if (token == "+") {
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            stack.push(a + b);
        }
        else if (token == "-") {
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            stack.push(a - b);
        }
        else if (token == "*") {
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            stack.push(a * b);
        }
        else if (token == "/") {
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            if (b == 0) throw std::runtime_error("Division by zero");
            stack.push(a / b);
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
