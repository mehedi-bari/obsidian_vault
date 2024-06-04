## Basics:
- Lexical Analysis reads characaters and produces sequences of tokens.
- Therefore it recognises the language's parts of the speech.
- It can check grammer given a set of instructions.
- It checks valid input characters, or else returns an error.

## Definitions
-   Vocabulary: a finite set of symbols.
-   String: a finite sequence of symbols from the vocabulary.
-   Language: a set of strings over a fixed vocabulary.
-   Grammar: a finite way of describing a language.
-   Context-free grammar: A way of expressing a grammar. Some grammar � is given as G =(S,N,T, P) where
    -   S = starting symbol
    -   N = set of non-terminal symbols
    -   T = set of terminal symbols
    -   P = set of production rules
-   A language is the set of all terminal productions of some CFG �. That is, every possible sequence that satisfies the production rules � and ends with some terminal ∈ T.
![[Screenshot 2023-03-01 at 21.47.12.png]]


## Motivation
Why study lexical analysis?
-   To avoid writing lexical analysers by hand
-   To simplify the specification and implementation.
-   To understand the techniques and technologies. We want to know how to specify lexical patterns. Some parts of this are easy (e.g. defining operators, comments, whitespace, etc.) but some are significantly harder such as identifiers (letter followed by alphanumeric characters), numbers (integer vs floating point, multiple base literals, etc.).

## Regular Expressions
Regex patterns form a regular language. A regular language is a formula that describes a possibly infinite set of strings. For example:![[Screenshot 2023-03-01 at 21.55.49.png]]
- r+ means one or more occurances 
- You could write a lexical analyser that checks case by case, like this: This has the potential to be efficient, but it requires a lot of work and will be difficult to modify. Instead, consider how regular expressions are evaluated like using a transition diagram or  transition table: ![[Screenshot 2023-03-11 at 19.13.35.png]]

![[Screenshot 2023-03-11 at 19.14.16.png]]

- These are the actions that take place in a lexical analyser. A string is evaluated against a set of states and transitions, being identified as some sort of token if it reaches a terminal state. Using this concept, lexical analysis can be automated.

## Finite automaton:
The generalised transition digaram is a finite automaton. It can be:
- Deterministic: DFA; as in the example:for every state and symbol there is only one transition to another state(deterministic)
- Non Deterministic: NFA; more than 1 transition out of a state may be possible on the same input symbol: think about (a|b)*

**The process:**
-   Write down a regular expression that expresses the input language.
-   Convert the regular expression to an NFA (using Thompson's construction).
-   Convert the NFA to a DFA (using subset construction).
-   Minimise the DFA (using Hopcroft's algorithm). There exist programs that (pretty much) do this for you, such as `lex` and `flex`; these algorithms are well-known and well understood.

## Regular Expresssion to Non-deterministic FA
## RE to NFA

By following these rules, a regular expression can be translated to an NFA: 
![[Screenshot 2023-03-11 at 20.05.36.png]]

## NFA to DFA:
Simple definitions:

-   move(s$_i$,a): the states that you can reach from state s$_i$ when the input symbol is a.
-   $\epsilon$-closure(s$_i$): the states that you can reach from state s$_i$ without needing another input symbol (i.e. where the transition symbol is $\epsilon$).
![[Screenshot 2023-03-11 at 20.12.46.png]]
<br>
![[Screenshot 2023-03-11 at 20.27.03.png]]
<br>
![[Screenshot 2023-03-11 at 20.27.32.png]]


## DFA Minimisation
-  If we can find a group where for each input symbol, will either go to the group itself, or they will go to a different group but to the same group. Example:
![[Screenshot 2023-03-11 at 20.28.39.png]]


## Building fast scanners

Using a table to encode the transitions is easy to understand and code, but it involves lots of memory operations, and other operations in general. Instead, you can represent the transition logic directly in your code:
![[Screenshot 2023-03-11 at 20.40.00.png]]
<br>![[Screenshot 2023-03-11 at 20.41.53.png]]
-   Has fewer operations
-   Avoids memory interaction (which is especially important for large tables)
-   Has a lot of added complexity, which may make the code ugly and/or difficult to understand. However this is still generated automatically, so it doesn't really matter that much