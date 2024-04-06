# Mario Right Align Solution by CS50

## Description:
*To solve the Mario right-align problem, we need to print a pyramid of '#' characters with the base width specified by the input num. The pyramid should be right-aligned, meaning each row of the pyramid starts with spaces to align it to the right.*


### Function:
```Copy code
void MarioRightAlign(int num) {
    for (int i = 0; i < num; i++) {
        // Print spaces to right-align the pyramid
        for (int k = 0; k < num - i - 1; k++) {
            printf(" ");
        }
        // Print '#' character for the pyramid
        printf("#");
        for (int j = 0; j < i; j++) {
            printf("#");
        }

        printf("\n");
    }
}
```

### Visualization:
```
                 First            Second                  Third
       #        [i = 0]  [spaces = 8 - 0 - 1 = 7]  [hashes = 0 + 1 = 1]
      ##        [i = 1]  [spaces = 8 - 1 - 1 = 6]  [hashes = 1 + 1 = 2]
     ###        [i = 2]  [spaces = 8 - 2 - 1 = 5]  [hashes = 2 + 1 = 3]
    ####        [i = 3]  [spaces = 8 - 3 - 1 = 4]  [hashes = 3 + 1 = 4]
   #####        [i = 4]  [spaces = 8 - 4 - 1 = 3]  [hashes = 4 + 1 = 5]
  ######        [i = 5]  [spaces = 8 - 5 - 1 = 2]  [hashes = 5 + 1 = 6]
 #######        [i = 6]  [spaces = 8 - 6 - 1 = 1]  [hashes = 6 + 1 = 7]
########        [i = 7]  [spaces = 8 - 7 - 1 = 0]  [hashes = 7 + 1 = 8]
```

*This markdown provides a clear description of how to solve the Mario right-align problem, along with the function implementation and a visualization of the calculations for each row.*

*For a detailed walkthrough and the complete code [mario.c](https://github.com/Lei0x1/cs50-2024/blob/main/Week-1-C/src/mario.c)*