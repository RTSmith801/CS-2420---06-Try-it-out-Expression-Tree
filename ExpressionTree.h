/**
 * @file: ExpressionTree.h
 * @assignment_name: 06: Try it out: Expression Tree
 * @author: Rick Smith (rickysmith@mail.weber.edu)
 * @date: 02/04/2023
 * @brief: Implementing a BinaryTree to store math expressions.
 *
 */

#ifndef INC_06_TRY_IT_OUT_EXPRESSION_TREE_EXPRESSIONTREE_H
#define INC_06_TRY_IT_OUT_EXPRESSION_TREE_EXPRESSIONTREE_H

#include <string>
#include <iostream>

struct Node{
    std::string val;
    Node  *left;
    Node *right;
};

//template <class Type>
class ExpressionTree{

public:

    ExpressionTree(); //default constructor creates an empty expression tree
    ExpressionTree(std::string expr); //Creates an expression tree from the given string expression
    ~ExpressionTree();
    void setExpression(std::string expr); //Clears the expression tree and stores the given expression in a new tree
    int getResult(); //return the results of evaluating the expression tree
    std::string printParseTreeInOrder(std::ostream&); //outputs the tree to the ostream& using an in-order traversal
    std::string printParseTreePostOrder(std::ostream&); //outputs the tree to the ostream& using post-order traversal

    bool isOperand(char ch); // function to check if operand
    bool isOperator(char ch); // function to check if operator

protected:
    Node *root; //pointer to top of tree.
    int index; //current position in expr string
    std::string expr;

private:
    //helper methods for recurrsive calls.
    void destroy(Node *curr);
    void setExpression(Node *curr);
    int getResult(Node *curr);
    std::string printParseTreeInOrder(std::ostream &out, Node *curr);
};

//default constructor creates an empty expression tree
ExpressionTree::ExpressionTree(){
    root = nullptr;
    index = 0;
}

//Creates an expression tree from the given string expression
ExpressionTree::ExpressionTree(std::string expr){
    root = nullptr;
    index = 0;
    this->expr = expr;
    setExpression(expr);
}

ExpressionTree::~ExpressionTree(){
    destroy(root);
}


void ExpressionTree::destroy(Node *curr){
    if(curr != nullptr){
        destroy(curr->left);
        destroy(curr->right);
        delete curr;
    }
}

//Clears the expression tree and stores the given expression in a new tree
void ExpressionTree::setExpression(std::string expr){
    //clears current expression tree, if it exists.
    if(root != nullptr){
        destroy(root);
    }

    root = new Node;
    root->val = "";
    root->left = nullptr;
    root->right = nullptr;
    index = 0;
    this->expr = expr;

    std::cout << "Expression is: " << expr << std::endl;

    setExpression(root);
}

//recursive method to assist with creation of nodes.
void ExpressionTree::setExpression(Node *curr){
    ///If the current position is less than 0 or greater than the size of the string then return
    if(index < 0 || index > expr.size()){
        return;
    }

    ///If the character is a '(' create a node and place it on the left of your currentNode, move to the next character in the expression and recursively go left from the currentNode.
    if(expr[index] == '('){
        //new node
        auto temp = new Node;
        curr->left = temp;
        index++;
        setExpression(curr->left);
    }

        ///if the character is a digit, continue reading from the string until you encounter a non-digit character. Each time concatenate the new digit character into a temporary string. Store that temp string in your currentNode data and then return.
    else if(isOperand(expr[index])){
        std::string temp = "";
        while(isOperand(expr[index])){
            temp += expr[index];
            index++;
        }
        curr->val = temp;
        return;
    }

        ///If the character is an operator store the operator in the currentNode data, create a new node and place it on the right of your currentNode, move to the next character in the expression and recursively go right from the currentNode.
    else if(isOperator(expr[index])){
        //assign operator to node
        curr->val = expr[index];
        //create new node
        auto temp = new Node;
        curr->right = temp;
        index++;
        setExpression(curr->right);
    }

        ///if the character is a ')', just return.
    else if(expr[index] == ')'){
        index++;
        return;
    }
}


//return the results of evaluating the expression tree
int ExpressionTree::getResult()
{
    return getResult(root);
}

int ExpressionTree::getResult(Node* curr)
{
    if(curr == nullptr)
    {
        return 0;
    }
    else
    {
        return 123;
    }
}

//outputs the tree to the ostream& using an in-order traversal
std::string ExpressionTree::printParseTreeInOrder(std::ostream&){
    return printParseTreeInOrder(std::cout, root);
}

std::string ExpressionTree::printParseTreeInOrder(std::ostream &out, Node *curr) {
    return "";
}

//outputs the tree to the ostream& using post-order traversal
std::string ExpressionTree::printParseTreePostOrder(std::ostream&){
    return "";
}

// function to check if operand
bool ExpressionTree::isOperand(char ch)
{
    return ch >= '0' && ch <= '9' || ch>='A' && ch<='Z' || ch>='a' && ch<='z';
}
// function to check if operator
bool ExpressionTree::isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

#endif //INC_06_TRY_IT_OUT_EXPRESSION_TREE_EXPRESSIONTREE_H
