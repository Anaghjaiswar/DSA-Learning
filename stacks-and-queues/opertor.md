`^` - max priority (let's say 3)

`* and /` - medium priority (let's say 2)

`+ and -` - low priority (let's say 1)

anaything else - min priority (let's say -1)

When evaluating an expression, operators with higher priority are applied before operators with lower priority. For example, in the expression `3 + 5 * 2`, the multiplication operator `*` has a higher priority than the addition operator `+`, so the multiplication is performed first, resulting in `3 + (5 * 2) = 3 + 10 = 13`.



what is infix ?
Infix notation is a common way of writing mathematical expressions where the operator is placed between the operands. For example, in the expression `3 + 5`, the `+` operator is between the operands `3` and `5`. This is the standard notation used in arithmetic and algebra.

`(p+q) * (m-n)`

what is prefix ?
Prefix notation, also known as Polish notation, is a way of writing mathematical expressions where the operator precedes its operands. For example, in prefix notation, the expression `+ 3 5` represents the same operation as `3 + 5` in infix notation.
In prefix notation, the operator is placed before the operands, which can eliminate the need for parentheses to indicate the order of operations.

`* + p q - m n`


what is postfix ?
Postfix notation, also known as Reverse Polish Notation (RPN), is a way of writing mathematical expressions where the operator follows its operands. For example, in postfix notation, the expression `3 5 +` represents the same operation as `3 + 5` in infix notation.
In postfix notation, the operator is placed after the operands, which can also eliminate the need for parentheses to indicate the order of operations.

`p q + m n - *`

postfix expressions are used in stack-based calculations and are particularly useful in computer science for evaluating expressions without the need for parentheses.


prefix expressions are used in certain programming languages and calculators, and they can simplify the parsing of expressions by eliminating the need for parentheses.


infix expressions are the most common and familiar way of writing mathematical expressions, but they can require additional rules and parentheses to clarify the order of operations.


`INFIX TO POSTFIX`
1. take a iterator i starting from 0
2. will be taking a stack which is initially empty
3. will be taking an output string which is initially empty

eg = `a + b * (c ^ d -e)`
```
i = 0                stack = []                     output = ""
a                                                        a
+                        +                          output = "a" 
b                        +                              ab
*                    +, *( priority high than +)    output = "ab"
(                      +, *, (                         output = "ab"   
c                      +, *, (                       output = "ab c"
^                    +, *, (, ^                     output = "ab c"
d                    +, *, (, ^                     output = "ab cd"
-                  +, *, (, - (priority less than ^) output = "ab cd ^"
e                       +, *, (                      output = "ab cd ^ e"
)                           +, *                      output = "ab cd ^ e -"
                            +                         output = "ab cd ^ e - *"
            all remaining operators are popped from stack and added to output
final output = "ab c d ^ e - * +"
```

