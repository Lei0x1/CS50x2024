# Mario More

## Description:
To solve the Mario more problem, we need to print two pyramids of '#' characters, with the base width specified by the input num. One pyramid should be right-aligned, and the other left-aligned.

### Function:
```c
void printPyramid(int num) {
    for (int row = 0; row < num; row++) {
        // Print spaces to right-align the pyramid
        for (int right_spaces = 0; right_spaces < num - row - 1; right_spaces++) {
            printf(" ");
        }
        // Print '#' character for the right pyramid
        printf("#");

        // Print additional '#'s for the right pyramid
        for (int right_hashes = 0; right_hashes < row; right_hashes++) {
            printf("#");
        }

        // Print space between the right and left alignments
        for (int double_spaces = 0; double_spaces < 2; double_spaces++) {
            printf(" ");
        }

        // Print '#' for the left pyramid
        for (int left_hashes = 0; left_hashes < row + 1; left_hashes++) {
            printf("#");
        }

        printf("\n");
    }
}
```

### Visualization:
```
                            First                    Second                            Third                         Fourth
       #  #               [row = 0]   [right_spaces = num - 0 - 1 = num - 1]   [right_hashes = 0 + 1 = 1]   [left_hashes = 0 + 1 = 1]
      ##  ##              [row = 1]   [right_spaces = num - 1 - 1 = num - 2]   [right_hashes = 1 + 1 = 2]   [left_hashes = 1 + 1 = 2]
     ###  ###             [row = 2]   [right_spaces = num - 2 - 1 = num - 3]   [right_hashes = 2 + 1 = 3]   [left_hashes = 2 + 1 = 3]
    ####  ####            [row = 3]   [right_spaces = num - 3 - 1 = num - 4]   [right_hashes = 3 + 1 = 4]   [left_hashes = 3 + 1 = 4]
   #####  #####           [row = 4]   [right_spaces = num - 4 - 1 = num - 5]   [right_hashes = 4 + 1 = 5]   [left_hashes = 4 + 1 = 5]
  ######  ######          [row = 5]   [right_spaces = num - 5 - 1 = num - 6]   [right_hashes = 5 + 1 = 6]   [left_hashes = 5 + 1 = 6]
 #######  #######         [row = 6]   [right_spaces = num - 6 - 1 = num - 7]   [right_hashes = 6 + 1 = 7]   [left_hashes = 6 + 1 = 7]
########  ########        [row = 7]   [right_spaces = num - 7 - 1 = num - 8]   [right_hashes = 7 + 1 = 8]   [left_hashes = 7 + 1 = 8]
```

*This markdown provides a clear description of how to solve the Mario more problem, along with the function implementation and a visualization of the calculations for each row.*

*For a detailed walkthrough and the complete code [mario-more.c](https://github.com/Lei0x1/cs50-2024/blob/main/Week-1-C/src/mario-more.c)*