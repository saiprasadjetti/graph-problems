//
// Created by sai prasad jetti on 26/05/21.
//
#include <iostream>
#include <vector>
#include <queue>

#define INF INT_MAX

using namespace std;

#ifndef UNTITLED15_FLOYDWARSHALL_H
#define UNTITLED15_FLOYDWARSHALL_H

#endif //UNTITLED15_FLOYDWARSHALL_H
class floydwarshall
{
public:
    int v;
    vector<vector<int>> dist;
public:
    floydwarshall(int v,vector<vector<int>>& graph)
    {
        this->v=v;
        dist.resize(v);
        for(int i=0;i<v;i++) {
            dist[i].resize(v);
            for (int j = 0; j < v; j++) {
                  dist[i][j]=graph[i][j];
            }
        }
    };

    void allPairShortestpath();
    void printdist();


};
void floydwarshall::allPairShortestpath()
{
    for(int k=0;k<v-1;k++)
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(dist[k][j]!=INF&&dist[i][k]!=INF)
                {
                    if(dist[i][j]>dist[i][k]+dist[k][j])
                    {
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
    }
}
void floydwarshall::printdist()
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(dist[i][j]==INF)
            {
                cout<<"INF"<<" ";
            } else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}
