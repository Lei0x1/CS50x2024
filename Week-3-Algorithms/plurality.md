# *Plurality*

## *Description*
The Plurality Voting System is implemented in C as part of the CS50 problem set. This system allows users to vote for candidates, and the candidate with the most votes wins the election.

### *Functions*
- `bool vote(string name)`
This function updates vote totals given a new vote by iterating over each candidate, checking if the candidate's name matches the given name, and incrementing the candidate's votes if there is a match.
- `void print_winner(void)`
This function prints the winner (or winners) of the election by finding the candidate(s) with the maximum number of votes.

### *bool vote(string name)*

```c
// Update vote totals given a new vote
bool vote(string name)
{
    // Iterate over each candidate
    for (int i = 0; i < candidate_count; i++) {
        // Check if candidate's name matches given name
        if (strcmp(candidates[i].name, name) == 0) {
            // If yes, increment candidate's votes and return true
            candidates[i].votes++;
            return true;
        }
    }

    // If no match, return false
    return false;
}
```

### *void print_winner(void)*
```c
// Print the winner (or winners) of the election
void print_winner(void)
{
    // Find the maximum number of votes
    int max_votes = 0;

    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
        }
    }

    // Print the candidate (or candidates) with maximum votes
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes == max_votes) {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}
```

### *Example*
```
$ ./plurality Alice Bob Charlie
Number of voters: 3
Vote: Alice
Vote: Alice
Vote: Bob
Alice
```

*In this example, we have three candidates named Alice, Bob, and Charlie. After taking votes from three voters, where two voted for Alice and one voted for Bob, the system correctly determines Alice as the winner.*

*Complete code [plurality.c](https://github.com/Lei0x1/cs50-2024/blob/main/Week-3-Algorithms/src/plurality.c)*