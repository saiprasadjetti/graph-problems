#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;

int main()
{

    int V;
    int E;
    cin>>V>>E;
    Graph temp(V,E);
    int u,v,w;
    for(int i=0;i<E;i++)
    {
        cin>>w>>u>>v;
        temp.addedge(w,u,v);
    }
    temp.parent.resize(V);
    temp.rank.resize(V);
    for(int i=0;i<V;i++)
    {
        temp.parent[i]=i;
    }
    for(int i=0;i<V;i++)
    {
        temp.rank[i]=0;
    }
    cout<<temp.kruskalsmst()<<endl;
}