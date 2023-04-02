#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int MAX_N = 100010;

vector<pair<int,int>> adj[MAX_N]; //{target , special}
bool school[MAX_N] = {false};
set<int> reach;


int main()
{
    vector<vector<int>> LAYER(2, vector<int>(MAX_N,0));
    vector<vector<bool>> VC(2, vector<bool>(MAX_N,false));
    vector<int> global_v(4);
    for (int i = 0; i < 4; i++){
        cin >> global_v[i];
    }
    int a,b,c,tmp;
    int i = 0;
    while(i < global_v[2]){
        cin >> tmp;
        school[tmp-1] = true;
        i++;
    }
    i = 0;
    while(i < global_v[1]){
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1,c});
        adj[b-1].push_back({a-1,c});
        i++;
    }

    i = 0;
    while(i < global_v[0]){
        cin >> a >> b;
        adj[a-1].push_back({b-1,0});
        adj[b-1].push_back({a-1,0});
        i++;
    }
    queue<pair<int,int>> Q;
    Q.push({0,school[0]});
    int u,v,sp;
    VC[0][0] = true;
    LAYER[0][0] = 0;
    if (school[0]) 
    {
        LAYER[1][0] = 0;
        VC[1][0] = true;
    }
    while (!Q.empty())
    {
        u = Q.front().first;
        sp = Q.front().second;
        Q.pop();
        if (!sp)
        {
            if (LAYER[0][u] <= global_v[3]) reach.insert(u);
            if (LAYER[0][u] >= global_v[3]) continue;
        }
        else 
        {
            if (LAYER[1][u] <= global_v[3]) reach.insert(u);
            if (LAYER[1][u] >= global_v[3]) continue;
        }
        for (auto x: adj[u])
    {
        v = x.first;
        if (sp >= x.second)
        {
            if (sp==0 && !VC[0][v] && !school[v])
            {
                LAYER[0][v] = LAYER[0][u] +1;
                Q.push({v,0});
                VC[0][v] = true;
            }
            else if (sp==0 && !VC[1][v] && school[v])
            {
                LAYER[1][v] = LAYER[0][u] +1;
                Q.push({v,1});
                VC[1][v] = true;
            }
            else if (sp==1 && !VC[1][v])
            {
                LAYER[1][v] = LAYER[1][u] +1;
                Q.push({v,1});
                VC[1][v] = true;
            }
        }
    }

    }
    cout << reach.size() << endl;
}
