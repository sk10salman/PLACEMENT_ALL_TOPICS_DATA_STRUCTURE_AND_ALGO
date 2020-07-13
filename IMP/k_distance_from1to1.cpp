 bool kLengthApart(vector<int>& nums, int k) {
        int j=-1;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            { j=i;
            break;}
        }
        if(j==-1||j==n-1)
            return true;
        int l=j;
        for(int i=j+1;i<n;i++)
        {
            if(nums[i]==1 && l-j<k)
            {
                return false;
            }
            if(nums[i]==0)
            {
                l++;
            }
            if(nums[i]==1 && l-j>=k)
            {
                j=l;
            }
        }
        return true;
    }

/*
Input: nums = [1,0,0,1,0,1], k = 2
Output: false
Explanation: The second 1 and third 1 are only one apart from each other.
Example 3:

Input: nums = [1,1,1,1,1], k = 0
Output: true
Example 4:

Input: nums = [0,1,0,1], k = 1
Output: true
*/
