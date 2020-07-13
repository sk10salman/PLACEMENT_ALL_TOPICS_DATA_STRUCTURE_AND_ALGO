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
Given three strings A, B and C your task is to complete the function isInterleave which returns true if C is an interleaving of A and B else returns false. C is said to be interleaving A and B, if it contains all characters of A and B and order of all characters in individual strings is preserved.


matlab C-- A and B ka variation hai at konsa index (a,b ) mai pehle aayega jisse yeh addition ho C ka

2
YX  X  XXY
XY X XXY

Output
0
1





case 1 : A-XY and B-X
Y ka X liya jo C ke X ke brabar hai next option mai sirf A KA Y hai jo C ke X se match nhi return false

