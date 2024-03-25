class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        if(nums.empty())return {};
        for(int i=0;i<nums.size();i++)
        {
		    // first make the elements negative accordingly as mentioned below 
			//suppose when we iterate through array we find an element 4 so make(4-1) =3rd element make it negative 
			//and move forward in arr and 
			//we again find 4 so we try to make (4-1)=3rd element negatve but it's already negative which means
			// it has occured before so return 4 
            int idx=abs(nums[i])-1;
            if (nums[idx]>0)
            nums[idx] =(-nums[idx]);
            else 
                v.push_back(abs(nums[i]));
            
        }
    
        return v;
    }
};