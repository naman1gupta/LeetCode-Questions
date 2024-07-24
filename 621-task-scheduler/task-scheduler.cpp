class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res=0;
        map<char, int> count;
        //Count frequencies of all characters
        for(char x: tasks)
            count[x]++;
        priority_queue<pair<int, char>> pq;
        //Add frequency along with its character to priority queue.
        //This will prioritise the characters according to their frequency.
        //Highest frequency will have highest priority
        for(auto x: count)
            pq.push({x.second, x.first});
        
        while(pq.size())
        {
            //This is the timer for the current cycle.
            int i=0;
            //Vector to temporarily store priority queue elements.
            //We will again add these elements to priority queue at the end of the loop.
            //This will rebuild the priority queue(heap) with the updated frequencies.
            vector<pair<int, char>> temp;
            //Iterate the priority queue and decrease the count(frequency) of the processed character.
            //Note that i<=n because we have to account for the cooldown of the current element. So, n+1.
            for(; i<=n && pq.size(); i++)
            {
                //If count is 1, decrementing it will make it 0. So NO need to add this to vector.
                if(pq.top().first==1)
                    pq.pop();
                //If count is more than 1, decrement it and add it to our vector.
                else
                {
                    temp.push_back({pq.top().first-1, pq.top().second});
                    pq.pop();
                }
                //Increment the total time
                res++;
            }
            //If we face cooldown period, add it to our total time(res).
            //Note that we have to skip this step at the end i.e. when we have processed all the characters.
            while(temp.size() && i<=n)
            {
                res++;
                i++;
            }
            //Rebuild the priority queue with updated frequencies.
            for(auto x: temp)
                pq.push(x);
        }

        return res;
    }
};