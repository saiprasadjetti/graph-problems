//
// Created by sai prasad jetti on 26/05/21.
//

#include <iostream>
#include <vector>
#include<queue>

using namespace std;
typedef pair<int,int> pp;
#ifndef UNTITLED15_PRIMSALGRITHM_H
#define UNTITLED15_PRIMSALGRITHM_H

#endif //UNTITLED15_PRIMSALGRITHM_H

class primsAlgorithm
{public:
    int V;
    int E;
    vector<vector<pair<int,int>>> edges;
    vector<bool> visited;
public:
    primsAlgorithm(int v,int e)
    {
        V=v;
        E=e;
        edges.resize(V+1);
        visited.resize(V+1);
        for(int i=0;i<v+1;i++)
        {
            visited[i]=false;
        }
    }
    void addedge(int u,int v,int w);
    int prims(int x);

};

void primsAlgorithm::addedge(int u,int v,int w)
{
    edges[u].push_back({w,v});
    edges[v].push_back({w,u});
}
int primsAlgorithm::prims(int x) {
    priority_queue <pp, vector<pp>, greater<pp>> q;
    q.push({0, x});
    int mincost = 0;

    while (!q.empty()) {
        pp temp = q.top();
        q.pop();
        int t = temp.second;
        if (visited[t] == true) {
            continue;
        }
        mincost += temp.first;

        visited[t] = true;
        for (int i = 0; i < edges[t].size(); i++) {
            if (!visited[edges[t][i].second]) {

                q.push(edges[t][i]);

            }
        }
    }

    return mincost;
}