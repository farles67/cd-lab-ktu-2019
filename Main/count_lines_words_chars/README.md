# Experiment: Count Lines, Words and Characters

## Aim

To implement a LEX program to count the number of lines, words and characters in a given input file.

## Algorithm

1. Start the program.
2. Initialize the counters `line`, `word` and `ch` to 0.
3. Open the input file using `fopen()`.
4. Scan the file using `yylex()`.
5. Increment the character count for every alphabet or digit.
6. Increment the word count whenever a space is encountered.
7. Increment both the line count and word count whenever a newline is encountered.
8. Display the number of lines, words and characters.
9. Stop the program.

## Expected Output

```
line=2
word=5
character=24
```

*(Output depends on the contents of the input file.)*

## Result

The LEX program was executed successfully and displayed the number of lines, words and characters in the given input file.
