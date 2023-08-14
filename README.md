# 680. Valid Palindrome-II

## Intuition
Check whether the string is a palindrome or not using two-pointers. 

## Approach
- Initialize pointers from the start and end of the string.
- Use the while loop to iterate the pointers till half of the string.
- If the characters are the same, continue the iteration.
- Else, call a function to check which of the two characters to remove for a valid palindrome.
- The function takes the current position of i and j pointers, returning a BOOL value.
- If the string from i+1th character to jth character forms a valid palindrome, then return true, by checking each character in another while loop.
- Alternatively, check if the ith character to j-1th character forms a valid palindrome and return true.
- The while loop may return true in the primary function by either of the two calls.
- Else, if the loop is exited without any calls to the custom function, the given string is already a palindrome and returns true.

## Complexity
- Time complexity:
$$O(n^2)$$ 

- Space complexity:
$$O(n)$$

## Code
```
class Solution {
public:
    bool removeIJ(int i, int j, string s){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return removeIJ(i+1,j, s) || removeIJ(i,j-1, s);
            }
        }
        return true;
    }
};
```
