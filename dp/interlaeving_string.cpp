/*You are required to complete this method */
bool isInterleave(string A, string B, string C) 
{
    //Your code here
  if(!A.length()&&!B.length()&&!C.length())
return true;
if(!C.length())
return false;
bool x=(A.length()&&C[0]==A[0]
&& isInterleave(A.substr(1),B,C.substr(1)));
bool y=(B.length()&&C[0]==B[0]
&& isInterleave(A,B.substr(1),C.substr(1)));
return x||y;
}

/*
2
YX  X  XXY
XY X XXY

Output
0
1

Explanation:
1. For first test case XXY is not interleaving of YX and X
2. For the sec test case XXY is interleaving of XY and X.
