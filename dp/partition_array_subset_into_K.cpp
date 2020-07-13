
/*You are required to complete this method */
bool partition(int ar[],int k,int A[],int index,int target)
{
  if(index<0)
    return true;
   
  int selected=A[index];
  for(int i=0;i<k;i++)
    {
        if(ar[i]+selected<=target)
        {
            ar[i] += selected;
            if(partition(ar,k,A,index-1,target))
              return true;
             ar[i] -= selected;
        }
           
    }
   return false; 
}



bool isKPartitionPossible(int A[], int N, int K)
{
     //Your code here
     int sum=accumulate(A,A+N,0);
     //cout<<sum<<" ";
     
     if(sum%K!=0)
      return false;
      int target=sum/K;
      sort(A,A+N);
     
      int index=N-1;
      if(A[index]>target)
         return false;
      while(index>=0 && A[index]==target)
      {
          index--;
          K--;
      }
      int ar[K]; 
      memset(ar,0,sizeof(ar));
     return partition(ar,K,A,index,target);
}


/*
2
5
2 1 4 5 6
3
5
2 1 5 5 6
3
Output:
1
0

Explanation:
Input : A[] = [2, 1, 4, 5, 6], K = 3
Output : 1, as we can divide above array into 3 parts with equal sum as (2, 4), (1, 5), (6)
Input : A[] = [2, 1, 5, 5, 6], K = 3
Output : 0, as it is not possible to divide above array into 3 parts with equal sum.
