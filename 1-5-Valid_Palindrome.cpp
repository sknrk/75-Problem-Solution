// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, stack_top = 1, stack_bottom = 1;
        int head=0,end=size(s)-1;
        while(head!=end && head<end){
            cout << int(s[head])<< " " << int(s[end]) << " " << endl;
            if((s[head]>90 && s[head]<97) || (s[head]>57 && s[head]<65) || s[head]<48 || s[head]>122){
                head++;
                continue;
            }
            if((s[end]>90 && s[end]<97) || (s[end]>57 && s[end]<65) || s[end]<48 || s[end]>122){
                end--;
                continue;
            }
            if(s[head]>90 && int(s[head])-32==int(s[end])){
                head++;
                end--;
            }
            else if(s[end]>90 && int(s[head])==int(s[end])-32){
                head++;
                end--;
            }
            else if(s[head]==s[end]){
                head++;
                end--;
            }
            else if(s[head]!=s[end]){
                return 0;
            }
        }
        return 1;
    }
};