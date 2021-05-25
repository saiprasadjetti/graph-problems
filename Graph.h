//
// Created by sai prasad jetti on 25/05/21.
//
#include <queue>
#include <functional>
#include <utility>
#include<algorithm>
#include <iostream>

#ifndef UNTITLED15_GRAPH_H
#define UNTITLED15_GRAPH_H

using namespace std;


class Graph
{
public:
    int V;
    int E;
    vector< pair< int,pair<int,int> > > edges;
    vector<pair<int,pair<int,int>>> mst;
    vector<int> parent;
    vector<int> rank;
public:
    Graph(int v,int e);
    void addedge(int u,int v,int w);
    int kruskalsmst();
    int find(int x);
    bool uni(int x,int y);

};

Graph::Graph(int V,int E)
{
    this->V=V;
    this->E=E;

}
void Graph::addedge(int w,int u,int v)
{
    edges.push_back({w,{u,v}});
}

int Graph::find(int x)
{
    while(parent[x]!=x)
    {
        x=parent[x];
    }
    return parent[x];
}
bool Graph::uni(int x,int y)
{
    if(find(x)==find(y))
    {
        return false;
    }
    else
    {
        if(rank[x]>rank[y])
        {
            parent[y]=x;
        }
        if(rank[x]<rank[y])
        {
            parent[x]=y;

        }
        else
        {
            parent[y]=x;
            rank[x]++;
        }
    }
    return true;
}

int Graph::kruskalsmst()
{

    sort(edges.begin(),edges.end());
    int cost=0;

    vector<pair<int,pair<int,int> > >::iterator it;
    for(it=edges.begin();it!=edges.end();it++)
    {
        pair<int,int> curr_edge =it->second;

        int w=it->first;
        cout<<w<<" "<<curr_edge.first<<" "<<curr_edge.second;
        cout<<endl;
    }

    for(int i=0;i<E;i++)
    {
        int u=edges[i].second.first;
        int v=edges[i].second.second;
        int w=edges[i].first;
        if(uni(u,v))
        {
            mst.push_back({w,{u,v}});
            cost=cost+w;
        }
    }
    return cost;
}



#endif //UNTITLED15_GRAPH_H
