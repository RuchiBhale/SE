/*
 * assignment7.cpp
 *
 *  Created on: Apr 28, 2023
 *      Author: exam4
 */

#include <iostream>
#include <string>
using namespace std;
#define inf 99
class Graph{
    int v,e; //vertex and edge count
    int **adjmatrix;
    string name;
    string* citynames;

    public:
    Graph(){
        v=0;
        e=0;
        citynames=NULL;

    }
   void create(){
    cout<<"Enter the number of vertices(cities): ";
    cin>>v;
    citynames=new string[v];
    cout<<"Enter the number of edges: ";
    cin>>e;
    adjmatrix=new int*[v];
    for(int i=0;i<v;i++){
        adjmatrix[i]=new int[v];
        for(int j=0;j<v;j++){
            adjmatrix[i][j]=0;
        }
    }

    for(int j=0;j<e;j++){
        string s,d;
        int id1,id2;
        int dis;
        cout<<"EDGE "<<j<<endl;
        cout<<"Name of  STRATING CITY : ";
        cin>>s;
        cout<<"ID of STARTING CITY: ";
        cin>>id1;
        cout<<endl;
        cout<<"Name of DESTINATION CITY: ";
        cin>>d;
        cout<<"ID of DESTINATION CITY: ";
        cin>>id2;
        cout<<endl;
        cout<<"DISTANCE: ";
        cin>>dis;
        insert(id1,id2,s,d,dis);


    }

   for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (adjmatrix[i][j] == 0)
                adjmatrix[i][j] = inf;    //fill infinity where path is not present
        }
    }

   }
   void insert(int src,int dest,string city1, string city2,int dist){
    citynames[src]=city1;
    citynames[dest]=city2;
    adjmatrix[src][dest]=dist;
    adjmatrix[dest][src]=dist;

   }
   void prims(Graph g){
    int n=g.v;
    int no_edge=0;
    bool selected[n];
    selected[0]=1;
    int cost=0;
    int x; //row no
    int y; //col no
    while(no_edge<n-1){
        int min=inf;

        for(int i=0;i<n;i++){

            // cout<<citynames[i]<<endl;
            // cout<<"---------"<<endl;
            if(selected[i]){
                for(int j=0;j<n;j++){
                    if(i!=j && !selected[j]){
                        if(min>adjmatrix[i][j]){
                            min=adjmatrix[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        cout<<citynames[x]<<"->"<<citynames[y]<<" : "<<adjmatrix[x][y];
        cout<<endl;
        selected[y]=1;
        no_edge++;
        cost+=adjmatrix[x][y];
    }
    cout<<"The minimum cost of spanning tree is: "<<cost<<endl;

   }
};
int main(){
    Graph g;
    g.create();
    g.prims(g);
    return 0;
}


