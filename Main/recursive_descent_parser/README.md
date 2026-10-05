
# Design and implementation of a recursive descent parser

## Aim

To design and implement a top-down Recursive Descent Parser utility for evaluating arithmetic expression strings based on a structured context-free production grammar specification.

## Target context-free grammar rules

The parser uses distinct mutually recursive subroutines to evaluate strings matching the left-recursion-free mathematical production structures listed below:

* **E → T E'**
* **E' → + T E' | ε**
* **T → F T'**
* **T' → * F T' | ε**
* **F → ( E ) | id** (implemented as literal character **'a'**)

## Architecture & functional pseudocode

### Procedure E()

Calls subroutines sequentially to match production rule **E → T E'**.

Structure:

* T();
* Eprime();

### Procedure E'()

Checks the lookahead symbol buffer. If a lookahead token matches **'+'**, it advances the global stream pointer, calls **T()**, and recursively loops back via **Eprime()**. Otherwise, it handles the empty **ε** matching path safely by executing an empty skip route.

### Procedure T()

Maps the target production rule structural path:

**T → F T'**

Structure:

* F();
* Tprime();

### Procedure T'()

Evaluates lookahead stream pointers against multiplicative symbols (**'*'**). If confirmed true, it advances the layout index buffer, invokes terminal token checks via **F()**, and loops back through **Tprime()**.

### Procedure F()

Coordinates basic terminal boundary validation checks:

* If the active token variable equals **id** (or character token literal **'a'**), it advances the lookahead layout configuration.
* Else if an opening parenthesis **'('** is spotted, it advances, recursively shifts execution back to the head entry rule **E()**, and checks for structural matching closure with explicit closing parenthesis **')'**.

## Test case verification & trace log table

| Tested input string | Grammar structural evaluation / error tracking status                                      | Final parser verdict |
| ------------------- | ------------------------------------------------------------------------------------------ | -------------------- |
| `a+a*a`             | Successfully matches all recursive procedure layers. All terminal lookup symbols consumed. | **Accepted**         |
| `(a+a)*a`           | Valid parenthesized expression block tracked securely. Brackets resolve structurally.      | **Accepted**         |
| `(a+a*a`            | Missing matching closing parenthesis structure. Terminates with execution flags raised.    | **Rejected**         |
| `a-a+a`             | Contains illegal literal operator **'-'** not accommodated inside the grammar domain.      | **Rejected**         |
| `a+a)*a`            | Unmatched standalone closing parenthesis encountered at sequence location offset.          | **Rejected**         |
| `(b*a)`             | Contains unknown/unsupported literal identifier token character symbol **'b'**.            | **Rejected**         |

## Result

The Top-Down Recursive Descent Parser utility was structured and compiled cleanly. The subroutines traverse nested token branches precisely as specified by the non-recursive arithmetic expression grammar rules, tracking lookaheads and structural errors correctly.
