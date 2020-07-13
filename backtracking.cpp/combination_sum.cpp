class Solution {
public:
    void solve( vector<vector<int>>&result,int index,vector<int>row,vector<int>&arr,int sum)
    {
        if(sum==0)
        {
            result.push_back(row);
            return;
        }
        if(sum<0 || index>=arr.size())
            return;
      
        row.push_back(arr[index]);
         solve(result,index,row,arr,sum-arr[index]); 
         row.pop_back();
          solve(result,index+1,row,arr,sum);
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>result;
        if(arr.size()==0)
             return result;
        vector<int>row;
        solve(result,0,row,arr,target);
        return result;
    }
};

/*
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

