// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
 

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.


class Solution {
public:
    bool isAnagram(string s, string t) {
        int i = 0;
        int alphabet[130] = { 0 };
        cout << alphabet[99];
        for(i=0; i<size(s);i++){
            alphabet[s[i]]++;
        }
        for(i=0; i<size(t);i++){
            alphabet[t[i]]--;
        }
        for(int i=0;i<size(alphabet);i++){
            if(alphabet[i] != 0){
                // cout << alphabet[i] ;
                return 0;
            }
        }
        return 1;
    }
};