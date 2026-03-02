# CS300 Data Structures Advising Program

## Overview

This project implements a command-line course advising assistance program in C++. The system reads course data from a CSV file, stores it using a Binary Search Tree, and provides functionality to:

- Load course data from file
- Print courses in alphanumeric order
- Search for a specific course
- Display prerequisite information
- Handle invalid input safely

This project demonstrates practical application of data structures, algorithm analysis, and structured program design.

---

## Data Structure Selection

Three data structures were evaluated:

- Vector
- Hash Table
- Binary Search Tree

After analyzing runtime and memory trade-offs, the Binary Search Tree was selected because it:

- Maintains sorted order naturally via in-order traversal
- Provides efficient average-case search `O(log n)`
- Eliminates the need for repeated sorting operations

A detailed runtime comparison is included in:

`Runtime_Analysis.md`

---

## Algorithmic Concepts Demonstrated

- Recursive binary search tree insertion
- Recursive in-order traversal for sorted output
- Big O runtime evaluation
- File parsing and validation
- Defensive input handling
- Data structure trade-off analysis

---

## Reflection

This project strengthened my understanding of how data structure selection directly impacts system performance and maintainability.

Instead of choosing a structure based on familiarity, I evaluated each option using Big O analysis and system requirements. Implementing the Binary Search Tree reinforced recursive design, pointer-based structures, and efficient data organization.

This experience has improved my approach to software development by encouraging:

- Efficiency-first design decisions
- Structured modular implementation
- Defensive programming practices
- Clear separation of responsibilities within code

---

## Technologies Used

- C++
- Standard Template Library (STL)
- Command-line interface design

## Reflection

### What problem was being solved?

The goal of this course project was to design and implement an advising assistance program that efficiently stores, sorts, and retrieves course data. The system needed to load structured data from a CSV file, validate prerequisite relationships, print courses in alphanumeric order, and allow advisors to search for individual courses.

### How did you approach the problem?

I approached the problem by first analyzing multiple data structures to determine which best satisfied the system requirements. Understanding time complexity and memory usage was vital here. I evaluated vector, hash table, and binary search tree implementations, comparing their performance characteristics. Because sorted output was a primary requirement, the Binary Search Tree was selected due to its natural ordering through in-order traversal.

### How did you overcome roadblocks?

Key challenges included handling file input validation, ensuring prerequisite integrity, and managing tree recursion correctly. I resolved these issues by breaking the problem into simpler, smaller functions, validating input in multiple passes, and carefully tracing recursive insert and search operations. Debugging and step by step testing ensured correctness.

### How has this project expanded your approach to designing software?

This project reinforced the importance of selecting the appropriate data structure based on system requirements rather than convenience. It emphasized evaluating algorithmic trade offs early in the design process. I now consider runtime complexity and scalability even more foundational elements of system architecture.

### How has this project improved your coding practices?

Working through this project improved my ability to write modular, readable, and maintainable code. I did my best to focus on clear function separation, consistent naming conventions, and defensive input validation. I know that this experience strengthened my understanding of how structured design leads to adaptable and extensible software.
