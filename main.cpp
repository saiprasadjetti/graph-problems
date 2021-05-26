#include <iostream>
#include <vector>
#include <queue>

#include "primsalgrithm.h"
#include "floydwarshall.h"
#include "bellmanford.h"

#define INF INT_MAX

using namespace std;
typedef  pair<int,int> pp;




class disjoint
{
public:
    int v;
    vector<int> parent;
    vector<int> rank;

public:
    disjoint(int v)
    {
        this->v=v;
        parent.resize(v);
        rank.resize(v);
        for(int i=0;i<v;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<v;i++)
        {
            rank[i]=0;
        }
    }
    int  find(int x);
    bool uni(int x,int y);

};

int  disjoint::find(int x)
{
    while(parent[x]!=x)
    {
        x=parent[x];
    }
    return parent[x];
}
bool disjoint::uni(int x,int y)
{
    int a=find(x);
    int b=find(y);
    if(a==b) {
        return false;
    }
    else{
        if(rank[x]>rank[y])
        {
            parent[y]=x;
        }
        if(rank[x]<rank[y])
        {
            parent[x]=y;
        }
        else{
            parent[y]=x;
            rank[x]++;
        };

    }
}


int main()
{
    int v;
    int e;
    int src;
    cin>>v>>e>>src;

    bellmanford graph(v,e,src);

    for(int i=0;i<e;i++)
    {
        int src;
        int dest;
        int weight;
        cin>>src>>dest>>weight;
        edge temp;
        temp.src=src;
        temp.dest=dest;
        temp.weight=weight;
        graph.addedge(temp);
    }
    graph.singleSourceShortestpath();
    for(int i=0;i<v;i++)
    {
        cout<<graph.dist[i]<<endl;
    }



}

