# Challenge Summaries

## Challenge 1 — Grid Transformation
This challenge involved applying rotation-based transformations to each row of a character grid.  
Using grid.txt and directions.txt, every row was modified according to the specified rotation instructions.

After completing all transformations:
- The *central row* (middle row) was extracted.
- The ASCII values of its characters were summed.
- This total became *Clue 1*.

---

## Challenge 2 — Multi-Pass String Processing
In this challenge, a given input string underwent three sequential operations:

1. *Reverse the string*  
2. *Remove every 3rd character*  
3. *Apply a +2 ASCII shift* to all remaining characters  

The final processed output was recorded as *Clue 2*.

---

## Challenge 3 — State Sequence Simulation
This challenge simulated how each value from states.txt moves through a 4-state system using the following rules:

- *Prime numbers* → Jump directly to the final state  
- *Even numbers* → Progress step-by-step until reaching the final state  
- *Odd composite numbers* → Do not move and never reach the final state  

The count of numbers that successfully reached the final state became *Clue 3*.