# *Sort*

## *Description*
This file provides performance data for various sorting algorithms including Bubble Sort, Merge Sort, and Selection Sort. Each algorithm's efficiency is evaluated based on sorting times for different types of input lists using files named `random50000.txt`, `reversed50000.txt`, and `sorted50000.txt`.

## *Overview*
Three sorting algorithms are compared based on their sorting times for random lists, reversed lists, and sorted lists.

---

### *Bubble Sort*
Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. It has a time complexity of O(n^2).

***How do you know?***
- 5.68s to sort `random50000.txt`
- 5.33s to sort `reversed50000.txt`
- 0.48s to sort `sorted50000.txt`

Bubble Sort performs poorly on large datasets like `random50000.txt` and `reversed50000.txt` due to its quadratic time complexity. However, it performs relatively well on already sorted data like `sorted50000.txt` because it only requires a single pass to confirm the list is sorted.

---

### *Merge Sort*
Merge Sort is a divide and conquer algorithm that divides the input array into two halves, sorts each half separately, and then merges them. It has a time complexity of O(n log n).

***How do you know?***
- 0.48s to sort `random50000.txt`
- 0.51s to sort `reversed50000.txt`
- 0.91s to sort `sorted50000.txt`

Merge Sort performs consistently well regardless of the initial order of the data. Its time complexity makes it suitable for handling large datasets efficiently.

---

### *Selection Sort*
Selection Sort is a simple sorting algorithm that repeatedly selects the smallest or largest element from the unsorted portion of the list and swaps it with the next element in the sorted portion. It has a time complexity of O(n^2).

***How do you know?***
- 2.50s to sort `random50000.txt`
- 2.74s to sort `reversed50000.txt`
- 2.20s to sort `sorted50000.txt`

Selection Sort's performance is affected by the initial order of the data. It performs relatively better on `sorted50000.txt` compared to `random50000.txt` and `reversed50000.txt` due to its nature of repeatedly selecting the smallest or largest element, which aligns well with already sorted data.

---

*These performance metrics are related to the CS50 problem set 3 sort implementation.*

*Link to the solution [sort.txt](https://github.com/Lei0x1/cs50-2024/blob/main/Week-3-Algorithms/src/sort.txt)*