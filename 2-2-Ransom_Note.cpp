// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

 

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true

class Solution {
public:
    int characters1[124],characters2[124];
    bool canConstruct(string ransomNote, string magazine) {
        int i;
        for(i=0;i<size(ransomNote) || i<size(magazine);i++){
            if(i<size(ransomNote))
            characters1[ransomNote[i]]++;
            if(i<size(magazine))
            characters2[magazine[i]]++;
        }
        for(i=0;i<124;i++){
            if(characters1[i]>characters2[i]){
                return false;
            }
        }
        return true;
    }
};

// I used character count array for both words, it helps to compare with one loop. Time complexity O(n);