//
// Created by sai prasad jetti on 26/05/21.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#ifndef UNTITLED15_BELLMANFORD_H
#define UNTITLED15_BELLMANFORD_H

#endif //UNTITLED15_BELLMANFORD_H

class edge{
public:
    int src;
    int dest;
    int weight;

};

class bellmanford{
public:

    int v;
    int e;
    vector<edge> edges;
    vector<int> dist;

    void addedge(edge Edge);
    void singleSourceShortestpath();
public:
    bellmanford(int v,int e,int src)
    {
        this->v=v;
        this->e=e;
        dist.resize(v);

        for(int i=0;i<v;i++)
        {
            dist[i]=INT_MAX;
        }
        dist[src]=0;

    }
};

void bellmanford::addedge(edge Edge)
{
    /*edge temp;
    temp.src=Edge.src;
    temp.dest=Edge.dest;
    temp.weight=Edge.weight;*/

    edges.push_back(Edge);
}
void bellmanford::singleSourceShortestpath() {




    for(int i=0;i<v-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            int u=edges[j].src;
            int v=edges[j].dest;
            int w=edges[j].weight;
            if(dist[u]!=INT_MAX&&dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
            }
        }
    }
    for(int j=0;j<e;j++)
    {
        int u=edges[j].src;
        int v=edges[j].dest;
        int w=edges[j].weight;
        if(dist[v]>dist[u]+w)
        {
            cout<<"negative cycle found"<<endl;
            return;
        }
    }
}