# Experiment 5: Implementation of Calculator Using LEX and YACC

## Aim

To implement an arithmetic calculator using **LEX** and **YACC** that accepts arithmetic expressions, checks whether they are syntactically valid, and evaluates the result.

---

# Algorithm

## LEX (Lexical Analyzer)

1. Include the required header files.
2. Read the input expression character by character.
3. Identify numeric values using the regular expression `[0-9]+`.
4. Convert the identified numbers into integer values using `atoi()`.
5. Return the token `NUMBER` to the YACC parser.
6. Ignore spaces and tab characters.
7. Return arithmetic operators (`+`, `-`, `*`, `/`, `%`) and parentheses (`(`, `)`) as individual tokens.
8. Stop scanning when the end of the input is reached.

---

## YACC (Parser)

1. Receive tokens from the lexical analyzer.
2. Parse the input according to the grammar of arithmetic expressions.
3. Apply operator precedence and associativity.
4. Perform arithmetic operations such as addition, subtraction, multiplication, division, and modulus.
5. Evaluate expressions enclosed within parentheses.
6. Display the calculated result if the expression is syntactically valid.
7. Display an error message if the expression contains invalid syntax.

---

# Program Description

The calculator is implemented using **LEX** and **YACC**.

- **LEX** performs lexical analysis by identifying numbers, operators, and parentheses from the input expression and generating tokens.
- **YACC** performs syntax analysis by checking whether the tokens follow the grammar of a valid arithmetic expression.
- If the expression is valid, YACC evaluates it and prints the result.
- If the expression is invalid (for example, missing operands, unmatched parentheses, or incorrect operator usage), an error message is displayed.

---

# Valid Expressions

The following expressions are considered valid:

```
2 + 3
5 * (4 + 2)
10 % 3
7 - 2 * 5
(8 + 4) / 2
```

---

# Invalid Expressions

The following expressions are considered invalid:

```
2+
2++3
*5+2
(2+3
()
2+3)
```

These expressions violate the grammar defined in the YACC parser and therefore produce an error message.

---

# Result

The arithmetic calculator was successfully implemented using **LEX** and **YACC**. The lexical analyzer correctly identifies tokens, while the parser validates the syntax of arithmetic expressions, evaluates valid expressions, and reports errors for invalid expressions.
