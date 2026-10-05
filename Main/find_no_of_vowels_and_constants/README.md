# Experiment: Find Number of Vowels and Consonants

## Aim

To implement a LEX program to find the total number of vowels and consonants from a given input string.

## Algorithm

1. Start the program.
2. Initialize `vow_count` and `const_count` to 0.
3. Read the input string using `yylex()`.
4. Scan each character of the input.
5. If the character is a vowel (`a, e, i, o, u` or `A, E, I, O, U`), increment `vow_count`.
6. If the character is an alphabet other than a vowel, increment `const_count`.
7. Continue scanning until the end of the input.
8. Display the total number of vowels and consonants.
9. Stop the program.

## Expected Output

```
Enter the string of vowels and consonants: CompilerLab
Number of vowels are: 3
Number of consonants are: 8
```

## Result

The LEX program was executed successfully and displayed the total number of vowels and consonants in the given input string.
