
/*You are required to complete below method */
int DP[101][101];
int Get_Max(int Array[], int I, int N)
{
    if(I>N) return 0;
    
    if(DP[I][N]!=-1) return DP[I][N];
    int Res=0;
    Res=std::max(Res, Array[I]+std::min(Get_Max(Array, I+1, N-1), Get_Max(Array, I+2, N)));
    Res=std::max(Res, Array[N]+std::min(Get_Max(Array, I+1, N-1), Get_Max(Array, I, N-2)));
    return DP[I][N]=Res;
}

int maxCoins(int Array[], int N)
{
    memset(DP, -1, sizeof(DP));
    return Get_Max(Array, 0, N-1);
}


/*
Two player X and Y are playing a game in which there are pots of gold arranged in a  line, each containing some gold coins. They get alternating turns in which the player can pick a pot from one of the ends of the line. The winner is the player who has a higher number of coins at the end. The objective is to maximize the number of coins collected by X, assuming Y also plays optimally. You are required to complete the method maxCoins which returns an integer denoting the max coins X could get while playing the game. You may assume that X starts the game. 

Input:
2
4
8 15 3 7
4
2 2 2 2

Output:
22
4
