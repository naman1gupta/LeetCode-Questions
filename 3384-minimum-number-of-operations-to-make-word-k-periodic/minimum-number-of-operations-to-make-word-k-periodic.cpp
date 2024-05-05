class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int maxOfAllFrequencies = 0;
        unordered_map<string, int> m;
        for(int i = 0; i < word.length(); i += k){
            string sub = word.substr(i, k);
            m[sub]++;
        }
        for(auto p : m)maxOfAllFrequencies = max(maxOfAllFrequencies, p.second);
        return word.length() / k - maxOfAllFrequencies;
    }
};