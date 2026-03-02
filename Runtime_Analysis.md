# Runtime and Memory Analysis

## Project Context

The ABCU Advising Assistance Program required:

- Loading course data from a CSV file
- Printing all courses in alphanumeric order
- Searching for individual courses efficiently
- Validating prerequisites

Three data structures were evaluated:

- Vector
- Hash Table
- Binary Search Tree

Each was analyzed for runtime efficiency and memory usage under both average-case and worst-case conditions.

---

## 1. Vector Analysis

### File Processing Cost

Reading and parsing the file:

- Loop through `n` lines
- Split each line
- Create `Course` objects
- Insert into vector

Base processing cost (excluding insertion):

`O(n)`

### Insertion Cost

- Average case: `O(1)` (push_back)
- Worst case: `O(n)` (if resizing occurs)

Worst case scenario:

`n insertions × O(n) = O(n²)`

### Runtime Summary

- Worst Case: `O(n²)`
- Average Case: `O(n)`

### Memory Complexity

- Stores `n` Course objects
- Contiguous memory allocation

`Space Complexity: O(n)`

### Evaluation

**Advantages**
- Simple implementation
- Low memory overhead
- Fast average insertion

**Disadvantages**
- Requires sorting before ordered printing
- Linear search time `O(n)`
- Possible `O(n²)` resizing cost

Vectors do not maintain sorted order automatically, which makes them inefficient for repeated ordered output.

---

## 2. Hash Table Analysis

### File Processing Cost

`O(n)`

### Insertion Cost

- Hash computation → `O(1)`
- Bucket insertion

Average case: `O(1)`

Worst case (all elements collide into one bucket): `O(n)`

Total worst case insertion:

`n × O(n) = O(n²)`

### Runtime Summary

- Worst Case: `O(n²)`
- Average Case: `O(n)`

### Memory Complexity

- Bucket array
- `n` Course objects
- Potential unused bucket space

`Space Complexity: O(n)`

### Evaluation

**Advantages**
- Fast average-case search `O(1)`
- Efficient direct lookup by course number
- Ideal for frequent retrieval

**Disadvantages**
- Does not maintain sorted order
- Requires sorting keys for ordered printing `O(n log n)`
- Performance degrades with collisions

Although lookup is efficient, additional sorting is required to meet ordered printing requirements.

---

## 3. Binary Search Tree Analysis

### File Processing Cost

`O(n)`

### Insertion Cost

Average case (balanced tree):

`O(log n)` per insertion → `O(n log n)`

Worst case (skewed tree):

`O(n)` per insertion → `O(n²)`

### Runtime Summary

- Worst Case: `O(n²)`
- Average Case: `O(n log n)`

### Search Cost

- Average Case: `O(log n)`
- Worst Case: `O(n)`

### In-Order Traversal

Printing sorted output:

`O(n)`

No additional sorting required.

### Memory Complexity

- `n` nodes
- Two pointers per node

`Space Complexity: O(n)`

### Evaluation

**Advantages**
- Maintains sorted order naturally
- Efficient average-case search `O(log n)`
- No additional sorting required

**Disadvantages**
- Can degrade to `O(n)` per operation if unbalanced
- Slightly higher memory overhead due to pointers
- More complex implementation

---

## Runtime Comparison

| Structure              | Worst Case | Average Case  | Space Complexity |
|------------------------|------------|---------------|------------------|
| Vector                 | O(n²)      | O(n)          | O(n)             |
| Hash Table             | O(n²)      | O(n)          | O(n)             |
| Binary Search Tree     | O(n²)      | O(n log n)    | O(n)             |

---

## Final Recommendation

The Binary Search Tree is the most appropriate structure for the advising program.

### Primary Requirement  
Print courses in alphanumeric order.

- BST maintains sorted order by design.
- In-order traversal produces sorted output without additional sorting.

### Secondary Requirement  
Efficient individual course lookup.

- BST provides `O(log n)` average lookup.
- Vector requires `O(n)` search.
- Hash table provides `O(1)` average lookup but does not preserve order.

Although all three structures share `O(n²)` worst-case loading behavior, the BST provides the best balance between:

- Natural ordering
- Efficient lookup
- Elimination of repeated sorting

For these reasons, the Binary Search Tree was selected for implementation in Project Two.
