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
