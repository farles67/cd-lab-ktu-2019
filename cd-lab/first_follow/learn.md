Absolutely. FIRST and FOLLOW are the most important concepts in compiler design (especially for LL(1) parsing). Once you understand the rules, most university problems become straightforward.

### FIRST and FOLLOW in compiler design

Think of them as two questions:

* FIRST(X) → What terminals can appear first when X is derived?

* FOLLOW(X) → What terminals can appear immediately after X in some valid derivation?

We’ll learn them with a simple method that works for KTU-style problems.

### The grammar

Consider this grammar:

S→ABA→a∣εB→bS \rightarrow AB\\A \rightarrow a \mid \varepsilon\\B \rightarrow bS→ABA→a∣εB→b

Here, S, A, B are non-terminals and a, b are terminals.

### FIRST set

### Rule 1: FIRST of a terminal

FIRST(a) = { a }

FIRST(b) = { b }

Easy.

### Rule 2: If A → a

Then FIRST(A) contains a.

For:

A→aA \rightarrow aA→a

FIRST(A) = { a }

### Rule 3: If A → ε

Then include ε.

For:

A→εA \rightarrow \varepsilonA→ε

FIRST(A) = { ε }

### Rule 4: If A → BC

Look at B first.

* Add FIRST(B) except ε.

* If B can produce ε, then also look at FIRST(C).

### Example 1

Find FIRST(A)

A→a∣εA \rightarrow a \mid \varepsilonA→a∣ε

FIRST(A) = { a, ε }

### Example 2

Find FIRST(B)

B→bB \rightarrow bB→b

FIRST(B) = { b }

### Example 3

Find FIRST(S)

S→ABS \rightarrow ABS→AB

Step 1: Look at A.

FIRST(A) = { a, ε }

Add a.

Since A has ε, look at B.

FIRST(B) = { b }

Add b.

So:

FIRST(S) = { a, b }

Notice ε is not included because B cannot produce ε.

### A systematic algorithm for FIRST

For each production:

### Case 1: A → terminal

Add terminal.

### Case 2: A → ε

Add ε.

### Case 3: A → X₁ X₂ X₃

* Add FIRST(X₁) − { ε }

* If ε in FIRST(X₁), add FIRST(X₂) − { ε }

* Continue until a symbol cannot produce ε

* If all symbols can produce ε, add ε

### FOLLOW set

FOLLOW is slightly harder.

FOLLOW is defined only for non-terminals.

### Rule 1: Put $ in FOLLOW(Start symbol)

If S is the start symbol:

FOLLOW(S) = { $ }

$ means end of input.

### Rule 2: If A → αBβ

Then add FIRST(β) − { ε } to FOLLOW(B).

Example:

S→ABS \rightarrow ABS→AB

B is after A.

β = B

FIRST(B) = { b }

So add b to FOLLOW(A).

FOLLOW(A) = { b }

### Rule 3: If A → αB

or

If A → αBβ and β can produce ε

Then add FOLLOW(A) to FOLLOW(B).

### Solving the complete example

Grammar:

S→ABA→a∣εB→bS \rightarrow AB\\A \rightarrow a \mid \varepsilon\\B \rightarrow bS→ABA→a∣εB→b

### Step 1: FIRST sets

Already found:

| Non-terminal | FIRST    |
| ------------ | -------- |
| A            | { a, ε } |
| B            | { b }    |
| S            | { a, b } |

### Step 2: FOLLOW sets

### Start symbol

FOLLOW(S) = { $ }

### Production: S → AB

### For A

After A comes B.

FIRST(B) = { b }

Add b.

FOLLOW(A) = { b }

### For B

B is at the end.

Add FOLLOW(S).

FOLLOW(B) = { $ }

Final answer:

| Non-terminal | FOLLOW |
| ------------ | ------ |
| S            | { $ }  |
| A            | { b }  |
| B            | { $ }  |

### A university-level problem

Find FIRST and FOLLOW.

E→TRR→+TR∣εT→FYY→∗FY∣εF→(E)∣idE \rightarrow TR\\R \rightarrow +TR \mid \varepsilon\\T \rightarrow FY\\Y \rightarrow *FY \mid \varepsilon\\F \rightarrow (E) \mid idE→TRR→+TR∣εT→FYY→∗FY∣εF→(E)∣id

This is the classic expression grammar.

### FIRST(F)

F → (E) | id

FIRST(F) = { (, id }

### FIRST(Y)

Y → *FY | ε

FIRST(Y) = { *, ε }

### FIRST(T)

T → FY

FIRST(F) = { (, id }

So:

FIRST(T) = { (, id }

### FIRST(R)

R → +TR | ε

FIRST(R) = { +, ε }

### FIRST(E)

E → TR

FIRST(T) = { (, id }

So:

FIRST(E) = { (, id }

FIRST table:

| Non-terminal | FIRST     |
| ------------ | --------- |
| E            | { (, id } |
| R            | { +, ε }  |
| T            | { (, id } |
| Y            | { *, ε }  |
| F            | { (, id } |

### FOLLOW calculation (exam method)

Initialize:

FOLLOW(E) = { $ }

Now inspect each production.

### E → TR

For T:

After T is R.

FIRST(R) = { +, ε }

Add +

Since R has ε, also add FOLLOW(E)

FOLLOW(T) = { +, $ }

For R:

R is at the end.

Add FOLLOW(E)

FOLLOW(R) = { $ }

### R → +TR

For T:

After T is R.

Add FIRST(R) − { ε } = { + }

Since R has ε, add FOLLOW(R)

FOLLOW(T) = { +, $ }

For R:

R is at end.

Add FOLLOW(R)

No change.

### T → FY

For F:

After F is Y.

FIRST(Y) = { *, ε }

Add *

Since Y has ε, add FOLLOW(T)

FOLLOW(F) = { *, +, $ }

For Y:

Y is at end.

Add FOLLOW(T)

FOLLOW(Y) = { +, $ }

### F → (E)

After E comes )

Add )

FOLLOW(E) = { $, ) }

Now FOLLOW(E) changed.

Propagate once more:

FOLLOW(T) gets )

FOLLOW(R) gets )

FOLLOW(F) gets )

FOLLOW(Y) gets )

Final FOLLOW table:

| Non-terminal | FOLLOW         |
| ------------ | -------------- |
| E            | { $, ) }       |
| R            | { $, ) }       |
| T            | { +, $, ) }    |
| Y            | { +, $, ) }    |
| F            | { *, +, $, ) } |

### The 5-step exam trick

When you get a problem:

1. Write all FIRST sets first.

2. Initialize FOLLOW(start) = { $ }.

3. For every production A → αBβ, add FIRST(β) − { ε } to FOLLOW(B).

4. If β can derive ε or B is at the end, add FOLLOW(A) to FOLLOW(B).

5. Repeat until no FOLLOW set changes.

This iterative approach is exactly how most compiler design problems are solved in exams.

A very useful next step is to practice 5 KTU-style FIRST and FOLLOW problems with complete solutions, including the tricky cases where multiple ε productions are involved.
