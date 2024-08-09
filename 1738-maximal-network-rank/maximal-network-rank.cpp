class Solution {
public:
    int maximalNetworkRank(int n, std::vector<std::vector<int>>& roads) {
        std::vector<int> degrees(n, 0);
        for (auto& road : roads) {
            degrees[road[0]]++;
            degrees[road[1]]++;
        }
        
        std::unordered_set<int> unique_degrees(degrees.begin(), degrees.end());
        std::vector<int> sorted_degrees(unique_degrees.begin(), unique_degrees.end());
        std::sort(sorted_degrees.rbegin(), sorted_degrees.rend());
        
        int max_deg = sorted_degrees[0];
        int second_max_deg = sorted_degrees.size() > 1 ? sorted_degrees[1] : 0;
        
        int max_count = std::count(degrees.begin(), degrees.end(), max_deg);
        int second_max_count = std::count(degrees.begin(), degrees.end(), second_max_deg);
        
        if (max_count > 1) {
            int directly_connected = 0;
            for (auto& road : roads) {
                if (degrees[road[0]] == max_deg && degrees[road[1]] == max_deg)
                    directly_connected++;
            }
            int possible_connections = max_count * (max_count - 1) / 2;
            return possible_connections == directly_connected ? 2 * max_deg - 1 : 2 * max_deg;
        }
        
        int direct_connections_to_second = 0;
        for (auto& road : roads) {
            if ((degrees[road[0]] == max_deg && degrees[road[1]] == second_max_deg) ||
                (degrees[road[0]] == second_max_deg && degrees[road[1]] == max_deg))
                direct_connections_to_second++;
        }
        
        return second_max_count == direct_connections_to_second ? max_deg + second_max_deg - 1 : max_deg + second_max_deg;
    }
};