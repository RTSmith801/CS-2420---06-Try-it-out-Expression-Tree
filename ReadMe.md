ExpressionTree class

    Must support the following public methods:
        ExpressionTree() - default constructor creates an empty expression tree
        ExpressionTree(std::string expr) - Creates an expression tree from the given string expression
        setExpression(std::string expr) - Clears the expression tree and stores the given expression in a new tree
        getResult() - return the results of evaluating the expression tree
        printParseTreeInOrder(std::ostream&) - outputs the tree to the ostream& using an in-order traversal
        printParseTreePostOrder(std::ostream&) - outputs the tree to the ostream& using post-order traversal


Parsing Building and Evaluating ExpressionTrees

The core of this assignment revolves around taking a statement like: ((((3+12)-7)*120)/(2+3)) and converting it into a tree like this: ExpressionTree.png

Building the expression tree can be done recursively like follows:

    If the current position is less than 0 or greater than the size of the string then return
    If the character is a '(' create a node and place it on the left of your currentNode, move to the next character in the expression and recursively go left from the currentNode.
    if the character is a digit, continue reading from the string until you encounter a non-digit character. Each time concatenate the new digit character into a temporary string. Store that temp string in your currentNode data and then return.
    If the character is an operator store the operator in the currentNode data, create a new node and place it on the right of your currentNode, move to the next character in the expression and recursively go right from the currentNode.
    if the character is a ')', just return.

Evaluating the expression tree can also be done recursively like follows:

    If the node is null the result is 0.0
    If the node is a number the result is that number
    If the node is an operator the result is the recursive result of the left subtree and right subtree combined using the given operator

Submission

Submit your code/project files and a screenshot of the running program.