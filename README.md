# Selection Sort in C

An interactive command-line implementation of **selection sort**. You enter a list of
integers and the program prints it before and after sorting.

## How it works

On each pass, the algorithm scans the unsorted part of the array, finds the smallest
element, and swaps it into the next position of the sorted part:

```
[5, -2, 9, 0, 3]  → find min (-2), swap to index 0 → [-2 | 5, 9, 0, 3]
[-2 | 5, 9, 0, 3] → find min (0),  swap to index 1 → [-2, 0 | 9, 5, 3]
... and so on until the unsorted part is empty
```

| Property | Value |
|---|---|
| Time | O(n²) comparisons in every case |
| Swaps | At most n − 1, which helps when writes are expensive |
| Space | O(1) extra; sorts in place |
| Stable | No |

## Build and run

```bash
gcc -Wall -Wextra -ansi -pedantic -o selection_sort SelectionAlgorithm.c
./selection_sort
```

```
Enter the number of elements: 6
Enter 6 number(s):
  ...
Unsorted array: 5 -2 9 0 9 3
Sorted array:   -2 0 3 5 9 9
```

## Notes

- The array is allocated on the heap with `malloc`. Up to 10 million elements are accepted
  without overflowing the stack.
- Input is validated: the element count must be between 1 and 10,000,000, and each entry
  must be an integer.
- The code is strict ANSI C (C89), so it builds on older compilers too.
