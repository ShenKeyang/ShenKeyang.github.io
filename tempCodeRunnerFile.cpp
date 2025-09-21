#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin >> m >> n;
    vector<vector<int>> map(m,vector<int>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> map[i][j];
        }
    }
    bool hasXiaoqu = false,hasLajizhan=false;
    vector<pair<int,int>> xiaoqu;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(map[i][j]==0) hasLajizhan=true;
            if(map[i][j]==1)
            {
                hasXiaoqu=true;
                xiaoqu.push_back({i,j});
            }
        }
    }

    vector<int> dx={-1,1,0,0};
    vector<int> dy={0,0,-1,1};

    if(!hasLajizhan||!hasXiaoqu)
    {
        cout << 0;
        return 0;
    }

    int res=0;

    for(auto xq : xiaoqu)
    {
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        int step=0;
        queue<pair<pair<int,int>,int>> q;
        q.push({{xq.first,xq.second},step});

        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            visited[cur.first.first][cur.first.second]=1;
            if(map[cur.first.first][cur.first.second]==0)
            {
                res+=step;
                break;
            }
            for(int i=0;i<4;i++)
            {
                int newX = cur.first.first+dx[i];
                int newY = cur.first.second+dy[i];
                if(map[newX][newY]!=-1 && visited[newX][newY]!=1)
                {
                    q.push({{newX,newY},step+1});
                }
            }
            
        }
    }

    cout << res;

    return 0;
}