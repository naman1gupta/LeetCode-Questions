class Solution {
private:
    // Phone keypad mapping
    unordered_map<char, string> digitToLetters = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    
    void backtrack(const string& digits, int index, string& current, vector<string>& result) {
        // If current combination is complete
        if (index == digits.length()) {
            if (!current.empty()) {
                result.push_back(current);
            }
            return;
        }
        
        // Get letters corresponding to current digit
        string letters = digitToLetters[digits[index]];
        
        // Try each letter for current digit
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, index + 1, current, result);
            current.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> result;
        string current;
        backtrack(digits, 0, current, result);
        return result;
    }
};