### Title

**Implementation of Shift-Reduce Parser**

### Aim

**To write a program that implements a Shift-Reduce Parser for a given input string based on specified grammar production rules.** 

### Algorithm

1. Start the program.
2. Define the required header files and initialize the variables for the stack and input string.
3. Read the input string from the user and initialize the stack with a bottom marker.
4. Scan the input string character by character.
5. If the substring **`id`** is encountered, push it onto the stack and perform a **SHIFT** operation.
6. After every SHIFT operation, check the stack for possible reductions.
7. Compare the contents of the stack with the grammar production rules:

   * `E → E + E`
   * `E → E - E`
   * `E → E * E`
   * `E → (E)`
   * `E → id`
8. If a right-hand side of a production matches the stack, replace it with the corresponding non-terminal **E** and perform a **REDUCE** operation.
9. After every SHIFT or REDUCE operation, display the stack, remaining input, and action performed.
10. Continue shifting and reducing until the entire input is processed.
11. If the stack contains only **E** and no input symbols remain, display **Accept**; otherwise, reject the input.
12. Stop the program. 
