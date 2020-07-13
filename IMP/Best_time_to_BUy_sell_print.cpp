#include <string>
#include <ios>
#include <iostream>
#include "algorithm"

using namespace std;

vector<int> stocks(int *arr, int n)
{
    vector<int> profits;
  
    int i=0;
    while(i<n-1)
    {
        while(i<(n-1)&&arr[i+1]<=arr[i])
          i++;
        if(i==n-1)
          break;
        int buy=i;
        i++;
        while((i<n)&&arr[i]>arr[i-1])
          i++;
        int sel=i-1;
        profits.push_back(buy);
        profits.push_back(sel);
    }

    return profits;

}



int main()
{
  


    int testcase;
    scanf("%d",&testcase);

    while(testcase--)
    {
        int n,*arr;
        cin >> n;
            
        arr = new int[n+1];
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        vector<int> results = stocks(arr,n);
        
        if(results.empty())
        cout << "No Profit";
        else
        for (int i = 0; i < results.size()-1; i+=2) {
            cout << "(" <<  results[i] << " " << results[i+1] << ")" << " ";
        }
        
        cout << endl;
     
    }
    

    return 0;
}

/*
3
7
100 180 260 310 40 535 695
4
100 50 30 20
10
23 13 25 29 33 19 34 45 65 67

Output:
(0 3) (4 6)
No Profit
(1 4) (5 9)

Explanation:
Testcase 1: We can buy stock on day 0, and sell it on 3rd day, which will give us maximum profit.

Note: Output format is as follows - (buy_day sell_day) (buy_day sell_day)
