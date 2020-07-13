void verticalSum(Node *root) {
    // add code here.
    queue<pair<int,Node*>>q;
    map<int,vector<int>>m;
    int hd=0;
    q.push({hd,root});
    while(!q.empty())
    {
        hd=q.front().first;
        Node *temp=q.front().second;
        q.pop();
        m[hd].push_back(temp->data);
        if(temp->left)
          q.push({hd-1,temp->left});
         if(temp->right)
          q.push({hd+1,temp->right});
    }
    for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<accumulate(i->second.begin(),i->second.end(),0)<<" ";
    }
}
