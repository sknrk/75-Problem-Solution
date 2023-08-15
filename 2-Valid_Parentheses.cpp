// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false
 

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.


class Solution {
public:
    bool isValid(string s) {
        int i=0, stack_counter = 1;
        char paranthese_stack[size(s)+1];
        for(i=0;i<size(s);i++){
            if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                paranthese_stack[stack_counter] = s[i];
                stack_counter++;
            }
            else if(s[i]=='}' && paranthese_stack[stack_counter-1]=='{'){
                paranthese_stack[stack_counter-1] = 0; 
                stack_counter--;
            }
            else if (s[i]==')' && paranthese_stack[stack_counter-1]=='('){
                paranthese_stack[stack_counter-1] = 0; 
                stack_counter--;
            }
            else if (s[i]==']' && paranthese_stack[stack_counter-1]=='['){
                paranthese_stack[stack_counter-1] = 0; 
                stack_counter--;
            }else{
                return 0;
            }
        }
        if(stack_counter==1 && size(s)!=1){
            return 1;
        }else{
            return 0;
        }
    }

};

// SOLUTION: A stack is used for all 3 types of parantheses. Last in first out (LIFO).