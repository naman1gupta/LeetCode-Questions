#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;class Solution {

public:

    vector<int> resultArray(vector<int>& nums) {
        vector<int>v1,v2,v;
        ordered_multiset<int>s1,s2;
        s1.insert(nums[0]);
        v1.push_back(nums[0]);
        s2.insert(nums[1]);
        v2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(s1.size()-s1.order_of_key(nums[i]+1) > s2.size()-s2.order_of_key(nums[i]+1)){
                s1.insert(nums[i]);
                v1.push_back(nums[i]);
            }
            else if(s1.size()-s1.order_of_key(nums[i]+1) < s2.size()-s2.order_of_key(nums[i]+1)){
                s2.insert(nums[i]);
                v2.push_back(nums[i]);
            }
            else{
                if(s1.size()<=s2.size()){
                    s1.insert(nums[i]);
                    v1.push_back(nums[i]);
                }
                else {
                    s2.insert(nums[i]);
                    v2.push_back(nums[i]);
                }
            }
        }
        for(auto i:v1) v.push_back(i);
        for(auto i:v2) v.push_back(i);
        return v;
    }
};