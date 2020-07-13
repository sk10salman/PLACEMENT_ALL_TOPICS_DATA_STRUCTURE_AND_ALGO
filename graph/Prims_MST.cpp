typedef pair<int,int> ipair;
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    // code here
    vector<int>key(V,20000);
    vector<bool>mset(V,false);
    priority_queue<ipair,vector<ipair>,greater<ipair>>pq;
    key[0]=0;
    pq.push({key[0],0});
    while(!pq.empty())
    {
        ipair q=pq.top();
        pq.pop();
        mset[q.second]=true;
        for(int i=0;i<V;i++)
        {
            if(graph[q.second][i]!=INT_MAX&&mset[i]==false&&key[i]>graph[q.second][i])
            {
                key[i]=graph[q.second][i];
                pq.push({key[i],i});
            }
        }
    }
    return accumulate(key.begin(),key.end(),0);
}

/*
Given a weighted, undirected and connected graph. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.
