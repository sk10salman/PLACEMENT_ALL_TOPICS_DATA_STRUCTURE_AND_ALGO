class Solution {
public:
    void backtrack(vector<vector<int>>&result,int index, vector<int>&arr, vector<int>&row)
    {
        if(index==arr.size())
        {
            result.push_back(row);
            return;
        }
        if(index>arr.size())
            return;
        row.push_back(arr[index]);
         backtrack(result,index+1,arr,row);
        row.pop_back();
         backtrack(result,index+1,arr,row);
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>result;
        if(nums.size()==0)
             return result;
       vector<int>row;
        backtrack(result,0,nums,row);
        return result;
        
    }
};

/*
Input: [1,1,2]

Output
[[1,1,2],[1,1],[1,2],[1],[1,2],[1],[2],[]]

