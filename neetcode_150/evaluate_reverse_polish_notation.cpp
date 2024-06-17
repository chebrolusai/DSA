/*
 * You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
 * Evaluate the expression. Return an integer that represents the value of the expression.
 * Note that:
 * The valid operators are '+', '-', '*', and '/'.
 * Each operand may be an integer or another expression.
 * The division between two integers always truncates toward zero.
 * There will not be any division by zero.
 * The input represents a valid arithmetic expression in a reverse polish notation.
 *The answer and all the intermediate calculations can be represented in a 32-bit integer.
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        unordered_set<string> operators = {"+","-","*","/"};

        stack<int> operatingStack;

        for( int i=0; i<tokens.size(); i++ ) {

            if ( operators.count(tokens[i]) ) {

                int number2 = operatingStack.top();
                operatingStack.pop();
                int number1 = operatingStack.top();
                operatingStack.pop();

                if ( tokens[i] == "+" ) {
                    operatingStack.push(number1 + number2);
                }
                else if ( tokens[i] == "-" ) {
                    operatingStack.push(number1 - number2);
                }
                else if ( tokens[i] == "*" ) {
                    operatingStack.push(number1 * number2);
                }
                else if ( tokens[i] == "/" ) {
                    operatingStack.push(number1 / number2);
                }

            }
            else {
                operatingStack.push( stoi(tokens[i]) );
            }
            
        }

        return operatingStack.top();

    }
};
