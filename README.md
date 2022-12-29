# Calculator
I built a Calculator using an MVC architecture and followed a Test Driven Developement methodology for the Model.
The idea for this project came to me because I received an interview question asking me to build a
calculator for a string math expression and I messed up quite badly, so I decided to learn how to build one properly.

This program will take your input and try to run it against my Calculator implementation (default) and
if that doesn't work because you have some unsupported operations (ie unary operators,
scientific operations, assumed implicit conversions), this program will send this expression 
to Wolfram Alpha's API. The reply will be delivered to you as the answer.

To run this program follow these steps.

    1. Clone this repo
    2. Open Calculator.sln in Microsoft Visual Studio
    3. Build and Run!

The algorithm for my default Calculator is shown below.
  1. Convert Infix Expression to Postfix Expression.
      I used the Shunting Yard algorithm (developed by Djikstra) for this process whose pseudocode is show below
           
           While there are tokens to be read:
                Read next token
                If it's a number add it to queue
                If it's an operator
                  While there's an operator on the top of the stack with greater precedence:
                     Pop operators from the stack onto the output queue
                  Push the current operator onto the stack
                If it's a left bracket push it onto the stack
                If it's a right bracket 
                  While there's not a left bracket at the top of the stack:
                         Pop operators from the stack onto the output queue.
                   Pop the left bracket from the stack and discard it
            While there are operators on the stack, pop them to the queue
            
  2. Evaluate the Postfix Expression.
      I used the algorithm whose pseudocode is shown below to evaluate the Postfix Expression.
         
          Create a stack to store operands (or values). 
          Scan the given expression from left to right and do the following for every scanned element. 
              If the element is a number, push it into the stack 
              If the element is an operator, pop operands for the operator from the stack. Evaluate the operator and push the result back to the stack 
          When the expression is ended, the number in the stack is the final answer
      
![](https://github.com/cchandel-dev/Calculator/blob/main/demo.gif)
