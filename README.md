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
Space complexity: `O(m*n)`\

### Outputs
![image](https://user-images.githubusercontent.com/80308332/203860417-67705a6b-086d-483e-9640-f53702577505.png)\
![image](https://user-images.githubusercontent.com/80308332/203860514-4e887725-9605-43f3-8a43-94ee705768af.png)\
![image](https://user-images.githubusercontent.com/80308332/203860600-76704122-c10c-4a13-a1f5-d65f996b1997.png)
