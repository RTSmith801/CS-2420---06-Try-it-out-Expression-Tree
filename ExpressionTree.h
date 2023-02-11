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
#include <cmath>

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
    void printParseTreeInOrder(std::ostream& out); //outputs the tree to the ostream& using an in-order traversal
    //std::string printParseTreeInOrder(std::ostream&); //outputs the tree to the ostream& using an in-order traversal
    //std::string printParseTreePostOrder(std::ostream&); //outputs the tree to the ostream& using post-order traversal
    void printParseTreePostOrder(std::ostream& out); //outputs the tree to the ostream& using post-order traversal

//    bool isOperand(char ch); // function to check if operand
    bool isOperand(std::string ch);
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
    std::string printParseTreeInOrder(Node *cur);
    std::string printParseTreePostOrder(Node *curr);
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
        curr = nullptr;
    }
}

//Clears the expression tree and stores the given expression in a new tree
void ExpressionTree::setExpression(std::string expr){
    //clears current expression tree, if it exists.
    if(root != nullptr){
        //std::cout << std::endl << "Deleting: " << std::endl;
        destroy(root);
        //std::cout << std::endl;
    }

    root = new Node;
    root->val = "";
    root->left = nullptr;
    root->right = nullptr;
    index = 0;
    this->expr = expr;
    std::cout << "Expression to set is: " << expr << std::endl;
    setExpression(root);
    std::cout << "Expression has been set to: ";
    printParseTreeInOrder(std::cout);
    std::cout << std::endl;
}

//recursive method to assist with creation of nodes.
void ExpressionTree::setExpression(Node *curr){
    std::cout << "Adding expr[" << index << "]->val = " << expr[index] << std::endl;

    ///If the current position is less than 0 or greater than the size of the string then return
    if(index < 0 || index > expr.size()){
        return;
    }

    ///If the character is a '(' create a node and place it on the left of your currentNode, move to the next character in the expression and recursively go left from the currentNode.
    if(expr[index] == '('){
        //new node
        auto temp = new Node;
        curr->left = temp;
        temp->left = nullptr;
        temp->right = nullptr;
        index++;
        setExpression(curr->left);
    }

        ///if the character is a digit, continue reading from the string until you encounter a non-digit character. Each time concatenate the new digit character into a temporary string. Store that temp string in your currentNode data and then return.
    if(isdigit(expr[index])){
        std::string temp = "";
        while(isdigit(expr[index])){
            temp += expr[index];
            index++;
        }
        curr->val = temp;
        return;
    }

        ///If the character is an operator store the operator in the currentNode data, create a new node and place it on the right of your currentNode, move to the next character in the expression and recursively go right from the currentNode.
    if(isOperator(expr[index])){
        std::cout << "Adding expr[" << index << "]->val = " << expr[index] << std::endl;
        //assign operator to node
        curr->val = expr[index];
        //create new node
        auto temp = new Node;
        curr->right = temp;
        temp->left = nullptr;
        temp->right = nullptr;
        index++;
        setExpression(curr->right);
    }

        ///if the character is a ')', just return.
    if(expr[index] == ')'){
        std::cout << "Adding expr[" << index << "]->val = " << expr[index] << std::endl;
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
    //If the node is null the result is 0.0
    if(curr == nullptr)
    {
        return 0;
    }
    //If the node is a number the result is that number
    if(isOperand(curr->val)){
        //stoi converts string to int
        return stoi(curr->val);

    }
    //If the node is an operator the result is the recursive result of the left subtree and right subtree combined using the given operator
    if(isOperator(curr->val[0])){
        if(curr->val[0] == '+'){
            return getResult(curr->left) + getResult(curr->right);
        }
        else if(curr->val[0] == '-'){
            return getResult(curr->left) - getResult(curr->right);
        }
        else if(curr->val[0] == '*'){
            return getResult(curr->left) * getResult(curr->right);
        }
        else if(curr->val[0] == '/'){
            return getResult(curr->left) / getResult(curr->right);
        }
        else if(curr->val[0] == '^'){
            int left = getResult(curr->left);
            int right = getResult(curr->right);
            return std::pow(left, right);
            //return 0;
        }
    }

    return 0;

}

//outputs the tree to the ostream& using an in-order traversal
void ExpressionTree::printParseTreeInOrder(std::ostream& out){
    //What am I using std::ostream& here for? Why isn't there a name for it such as "std::ostream& exampleText"?
    out << printParseTreeInOrder(root);
}

std::string ExpressionTree::printParseTreeInOrder(Node *curr) {
    //if node exists
    std::string toReturn = "";
    if(curr) {
        //if node->left, recurssive call.
        if(curr->left){
            toReturn += printParseTreeInOrder(curr->left);
        }
        //add value to string.
        toReturn += curr->val;
        //if node->right, recursive call.
        if(curr->right){
            toReturn += printParseTreeInOrder(curr->right);
        }
        return toReturn;
    }
    else{
        //return nothing when finding an empty node.
        return "";
    }

}

//outputs the tree to the ostream& using post-order traversal
void ExpressionTree::printParseTreePostOrder(std::ostream& out){
    out << printParseTreePostOrder(root);
}

std::string ExpressionTree::printParseTreePostOrder(Node *curr){
    //std::cout << "Expression is: " << expr << std::endl;
    std::string toReturn = "";
    if(curr){
        if (curr->left){
            toReturn += printParseTreePostOrder(curr->left);
            toReturn += " " ;
        }
        if (curr->right){
            toReturn += printParseTreePostOrder(curr->right);
            toReturn += " ";
        }
        toReturn += curr->val;
        return toReturn;
    }
    else{
        //return nothing when finding an empty node.
        return "";
    }
}

// function to check if operand
bool ExpressionTree::isOperand(std::string ch)
{
    //std::cout << "Val to compare " << ch << " isOperand?  " ;
    if(ch[0] >= '0' && ch[0] <= '9'){
        //std::cout << "true" << std::endl;
        return true;
    }
    else{
        //std::cout << "false" << std::endl;
        return false;
    }
    //return ch[0] >= '0' && ch[0] <= '9';
}
// function to check if operator
bool ExpressionTree::isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

#endif //INC_06_TRY_IT_OUT_EXPRESSION_TREE_EXPRESSIONTREE_H
