# Solution Code for String Editing

###### This repo contains a solution code for string editing problem using dynamic programming.

### Implementation
I created a vector of vectors `dp` with the outer vector equal to one more than the size of source string and each internal vector one more than the size of input string. 
`dp[i][j]` stores the minimum cost of converting input string of length `j` into source string of length `i`. Hence `dp[m][n]` contains the required min. cost where `m` and
`n` are sizes of source and input strings respectively.\
\
The algorithm works on following principles:
1. If source string is empty, delete all characters in input string.
2. If input string is empty, insert all characters from source string.
3. Else, if `source[i]!=input[j]`, perform the operation with min. cost out of insertion, deletion, replacement.

### Complexity
Time complexity: `O(m*n)`\
Space complexity: `O(m*n)`
