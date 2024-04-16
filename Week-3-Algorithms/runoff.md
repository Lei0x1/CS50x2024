# *Runoff*

## *Description*
This program simulates an election runoff using ranked-choice voting.

## *Functions*

- `bool vote(int voter, int rank, string name);`
  Records a voter's preference for a candidate at a given rank.
- `void tabulate(void);`
  Updates the vote counts for each candidate based on current preferences.
- `bool print_winner(void);`
  Determines if there is a winner based on the current vote counts.
- `int find_min(void);`
  Finds the minimum number of votes any remaining candidate has.
- `bool is_tie(int min);`
  Checks if the election is tied between all candidates.
- `void eliminate(int min);`
  Eliminates the candidate (or candidates) in last place.

---

### *bool vote(int voter, int rank, string name);*
```c
// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    // Iterate through the candidate names to find a match
    for (int i = 0; i < candidate_count; i++) {
        // Compare the candidate's name with the given name
        if (strcmp(candidates[i].name, name) == 0) {
            // Update preferences array to indicate the rank preference
            // Return true if preference is successfully recorded, false otherwise
            preferences[voter][rank] = i;
            return true;
        }
    }
    // No candidate found
    return false;
}
```

---

### *void tabulate(void);*

```c
// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    // Update the number of votes each candidate has at this stage in the runoff

    // Iterate through each voter
    for (int i = 0; i < voter_count; i++) {
        // Get the voter's top-preferred candidate
        int top_choice = preferences[i][0];

        // Check if the top choice candidate is eliminated
        if (!candidates[top_choice].eliminated) {
            // Update the votes for the top choice candidate if not eliminated
            candidates[top_choice].votes++;
        }
        else {
            // If the top choice candidate is eliminated, find the next non-eliminated candidate in the voter's preferences
            for (int j = 0; j < candidate_count; j++) {
                int next_choice = preferences[i][j];
                if (!candidates[next_choice].eliminated) {
                    // Update the votes for the next non-eliminated candidate and break the loop
                    candidates[next_choice].votes++;
                    break; // Stop after updating the vote for the next choice
                }
            }
        }
    }
    return;
}
```

---

### *bool print_winner(void);*
```c
// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Calculate the number of votes needed to win: half of the voters + 1
    int votes_needed = voter_count / 2;

    // Iterate through each candidate
    for (int i = 0; i < candidate_count; i++) {
        // Check if the candidate has more than half of the votes
        if (candidates[i].votes > votes_needed) {
            // Print the winner's name
            printf("Winner of the election is %s\n", candidates[i].name);
            // Return true indicating a winner is found
            return true;
        }
    }
    // Return false indicating no winner found
    return false;
}
```

---

### *int find_min(void);*
```c
// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    // Find the minimum vote total for any candidate still in the election

    int min_votes = INT_MAX; // Initialize a variable to store the minimum vote total, starting with a large value

    // Iterate through each candidate
    for (int i = 0; i < candidate_count; i++) {
        // Check if the candidate is still in the election and has fewer votes than the current minimum
        if (!candidates[i].eliminated && candidates[i].votes < min_votes) {
            // Update the minimum vote total if a candidate meets the criteria
            min_votes = candidates[i].votes;
        }
    }
    // Return the minimum vote total
    return min_votes;
}
```

---

### *bool is_tie(int min);*
```c
// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    // Iterate through each candidate
    for (int i = 0; i < candidate_count; i++) {
        // Check if the candidate is still in the election and has votes different from the minimum
        if (!candidates[i].eliminated && candidates[i].votes != min) {
            // If any candidate has votes different from the minimum, return false (no tie)
            return false;
        }
    }
    // If all candidates have the same votes as the minimum, return true (tie)
    return true;
}
```

---

### *void eliminate(int min);*
```c
// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    // Iterate through each candidate
    for (int i = 0; i < candidate_count; i++) {
        // Check if the candidate is still in the election and has votes equal to the minimum
        if (!candidates[i].eliminated && candidates[i].votes == min) {
            // Eliminate the candidate by setting their eliminated flag to true
            candidates[i].eliminated = true;
        }
    }
    return;
}
```

### *Example*
```
$ ./runoff Alpha Bravo Charlie
Number of voters: 2
Rank 1: Alpha
Rank 2: Bravo
Rank 3: Charlie

Rank 1: Alpha
Rank 2: Bravo
Rank 3: Charlie

Alpha
```

*In this example, the program is run with three candidates: Alpha, Bravo, and Charlie. Two voters participate in the election. The first voter ranks Alpha as their top choice, Bravo as their second choice, and Charlie as their third choice. The second voter also ranks Alpha first, Bravo second, and Charlie third. After tabulating the votes, Alpha is declared the winner of the election.*

*Complete code [runoff.c](https://github.com/Lei0x1/cs50-2024/blob/main/Week-3-Algorithms/src/runoff.c)*