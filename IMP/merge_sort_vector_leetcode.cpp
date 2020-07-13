class Solution {
public:
    void sort1(vector<int>& nums,int start,int mid,int end)
    {
       vector<int>left,right;
        for(int i=start;i<=mid;i++)
            left.push_back(nums[i]);
        for(int j=mid+1;j<=end;j++)
            right.push_back(nums[j]);
        
        int k=start,i=0,j=0;
        while(i<left.size() && j<right.size())
        {
            if(left[i]<=right[j])
            {
                nums[k]=left[i];
                k++;
                i++;
            }
            else
            {
               nums[k]=right[j];
                j++;
                k++; 
            }
              
        }
        while(i<left.size())
        {
             nums[k]=left[i];
                k++;
                i++;
        }
        while(j<right.size())
        {
            nums[k]=right[j];
                j++;
                k++; 
        }
        return;
    }
    void merge(vector<int>& nums,int start,int end)
    {
        if(start>=end)
            return;
      
            int mid = (start+end)/2;
            merge(nums,start,mid);
            merge(nums,mid+1,end);
            sort1(nums,start,mid,end);
    
    }
    
    vector<int> sortArray(vector<int>& nums) {
        merge(nums,0,nums.size()-1);
        return nums;
    }
};




/*
/*Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
