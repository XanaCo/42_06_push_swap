
<div align=center>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/push_swapm.png alt=Xanaco's 42Project Badge/>
<h2>Final score</h2>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/125Grade.png alt=Xanaco's 42Project Score/>
<h4>Completed + Bonus</h4>
</div>

## Overview

The `push_swap` project focuses on sorting algorithms and data manipulation. In this task, students are given two stacks named `a` and `b` and a set of operations to manipulate these stacks. The main goal is to sort the stack `a` using the fewest operations possible while employing the stack `b` as a temporary workspace.

The challenge is twofold: 
- To sort the numbers using only the given operations.
- To do it efficiently, minimizing the number of operations used.

The exercise essentially teaches the students the importance of algorithmic efficiency and how to approach complex problems with a strategic mindset.

## Key Components

1. **Two Stacks**: At the start, all numbers are in stack `a` and must be sorted only using the provided operations, utilizing stack `b` as needed.

2. **Operations**: These include:
    - `pa` and `pb`: push a number from one stack to the other.
    - `sa` and `sb`: swap the first 2 numbers at the top of stack `a` or `b`.
    - `ss`: swap the first 2 numbers at the top of both stacks.
    - `ra` and `rb`: rotate stack `a` or `b` (the first element becomes the last).
    - `rr`: rotate both stacks.
    - `rra` and `rrb`: reverse rotate stack `a` or `b` (the last element becomes the first).
    - `rrr`: reverse rotate both stacks.

3. **Checker Program (bonus)**: Alongside the main `push_swap` program, students can create a bonus `checker` program. This tool reads the numbers and operations from the standard input and verifies if the given operations successfully sort the numbers.

4. **Efficiency Requirement**: It's not just about sorting the numbers, but doing so efficiently. For larger sets of numbers, there is typically a maximum number of operations allowed to achieve a passing grade.

## Key Skills Developed

1. **Algorithmic Efficiency**: The heart of this project lies in optimizing sorting operations, teaching students the importance of algorithmic design and efficiency.

2. **Data Manipulation**: Through managing two stacks simultaneously and adhering to a strict set of operations, students hone their data manipulation abilities.

3. **Problem-solving**: Finding the optimal strategy to sort the stacks challenges students' problem-solving and strategic thinking.

4. **Code Organization and Structure**: To handle complex operations and checks, students must maintain a well-organized and structured codebase.

5. **Testing and Validation**: The checker program emphasizes the importance of validating algorithmic solutions and ensuring their correctness.

6. **Complexity Analysis**: The project indirectly introduces students to the world of Big O notation and the complexity analysis of algorithms, vital for future computer science endeavors.
