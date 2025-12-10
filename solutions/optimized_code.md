Optimization Notes — Challenge 3 (State Sequence Simulation)


The optimized version focuses on *reducing repeated work* and *avoiding unnecessary calculations*, making the program significantly faster and more scalable.


---


## What Was Improved


### *1. Faster Prime Checking Using a Sieve*
In the original version, primality might be checked individually for each number. This is slow.


The optimized version uses the *Sieve of Eratosthenes*, which quickly marks all prime numbers up to the largest value in the input.


*Why this helps:*
- Prime checks become instant (O(1) lookup instead of repeated division checks).
- Very beneficial when the input contains many numbers.


---


### *2. Memoization: "Remembering" Previously Computed Outcomes*
If a number appears more than once in the input, the non-optimized solution would recalculate everything again.


The optimized version stores the final state result for every distinct number.


*Result:*
- Repeated numbers cost zero extra computation.
- Large inputs with repeated values get a big speed boost.


---


### *3. Rule Simplification (Logical Shortcut)*
By analyzing how the transition system behaves:
- *Prime numbers* always jump straight to the final state.
- *Even numbers* always advance enough steps to reach the final state.
- *Odd composite numbers* never move forward.


Because of this, the optimized solution:
- Does *not simulate states step-by-step*.
- Instead directly determines where a number ends.


*This eliminates unnecessary looping entirely.*


---


## The Result
After all optimizations, the solution becomes:


### *Time Complexity:*
- O(maxV log log maxV + n)
- maxV = largest input value
- n = number of values in the file


### *Memory Usage:*
- O(maxV) for prime sieve + memoization


### *Real-World Benefit:*
- Handles much larger datasets
- Runs far faster
- Avoids repeated work
- Still easy to understand and maintain


---


## When This Optimization Helps the Most
- When the input file is very large
- When many numbers repeat
- When values are moderately sized and the sieve is efficient


---


## Running the Optimized Version
1. Compile: cc -O2 -o optimized_code optimized_code.c
2. Run: ./optimized_code states.txt


This version is significantly faster and more efficient than a straightforward implementation.