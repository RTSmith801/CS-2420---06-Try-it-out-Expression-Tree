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
    char val;
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

private:
    //helper methods for recurrsive calls.
    void destroy(Node *curr);
    int getResult(Node *curr);
    std::string printParseTreeInOrder(std::ostream &out, Node *curr);
};

//default constructor creates an empty expression tree
ExpressionTree::ExpressionTree(){
    root = nullptr;
}

//Creates an expression tree from the given string expression
ExpressionTree::ExpressionTree(std::string expr){

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
        return 12345;
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
