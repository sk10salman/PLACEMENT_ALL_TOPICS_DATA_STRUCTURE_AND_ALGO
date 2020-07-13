vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
   
    //code here   
    if(nums.size()<=1)
     {
         return vector<long long int>(1,1);
     }
    vector<long long int>v;
    long long int ans=1,count=0;
    for(auto x:nums)
    {
        if(x==0)
         count++;
        else
          ans *= x;
    }
    for(x:nums)
    {
        if(x!=0)
           {
               if(count>=1)
                 v.push_back(0);
                else
                v.push_back(ans/x);
           }
         else if(x==0)
         {
             if(count>=2)
               v.push_back(0);
              else
                v.push_back(ans);
         }
           
    }
    return v;
}

