// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

class Solution {
public:
    int characters[124];
    int count=0;
    bool oddNumber=false;
    int longestPalindrome(string s) {
        for(int i=0;i<size(s);i++){
            characters[s[i]]++;
        }
        for(int i=0;i<size(characters);i++){
            if(characters[i]%2==1){
                oddNumber=true;
            }
            count += characters[i]/2;
        }
        return count*2 + oddNumber;
    }
};


// I am searching for the odd and even numbers. After that multiplying even numbers with 2, adding oddNumber count and returning it.