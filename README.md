# DSA-Practice
Here, we practice Data Structures with java 

Implementation of Data Structures without Collection Framework, 
And with Collection Framework also

Here's what We have DONE :


1. STACK IMPLEMENTAION Using ARRAY

2. VALID PARENTHESIS (Application of stack)

3. Conversion of an INFIX Expression To POSTFIX Expression

    ALGORITHM:

        loop for each index of the i/p string

            if operand

                output it

            else

                if opening bracket

                    push in stack

                if closing bracket

                    pop & output stack untill matching opening bracket is reached

                    pop once again to remove opening bracket from the stack

                else

                    while (stack is not empty && precedence of incoming char in less than or equal to char at top of stack)

                        output & pop top of stack

                    push in stack the incoming char



        while( stack is not empty )
   
            output & pop stack top


5. Conversion of an INFIX Expression To PREFIX Expression

    ALGORITHM:

        (i) reverse the input string (while reversing the string swap opening bracket with matching closing barcket and vice versa)

       (ii) convert this expresion into postfix expression

       (iii) again reverse the expression received in step (ii)

            This obtained expression is prefix expression
            
6. Evaluation of Postfix Expression

   ALGORITHM :

       for( i = 0 ; i < postfix.length() ; i++){
           if operand
               push in stack
           else
               b2 = pop stack
               b1 = pop stack
               res = operate(b1, operator, b2)        //User defined fun (as operator is in the form of character)
               push res in stack
       }

7. Searching in a Stack
