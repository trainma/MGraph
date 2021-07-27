#include <iostream>
#include "queue"
using namespace std;
#define maxsize 100
#define INF 99999

typedef struct {
    char vex[maxsize];
    int arc[maxsize][maxsize];
    int vexnum,arcnum;
}MGrph;
int Locate(MGrph G,char v)
{
    for(int i=0;i<G.vexnum;i++)
        if(v==G.vex[i])
            return i;
    return -1;
}
bool Create_Graph_UDN(MGrph &G)
{
    cin>>G.vexnum>>G.arcnum;
    for(int i=0;i<G.vexnum;i++)
    {
        cin>>G.vex[i];
    }
    for(int i=0;i<G.vexnum;i++)
    {
        for(int j=0;j<G.vexnum;j++)
            G.arc[i][j]=INF;
    }
    for(int k=0;k<G.arcnum;k++)
    {
        char v1,v2;
        int w;
        cin>>v1>>v2>>w;
        int i= Locate(G,v1);
        int j= Locate(G,v2);
        G.arc[i][j]=w;
        G.arc[j][i]=G.arc[i][j];

    }
    return true;
}
void PrintGraph(MGrph G)
{
    int i,j;
    for(i=0;i<G.vexnum;i++)
        for(j=0;j<G.vexnum;j++)
            if(j!=G.vexnum-1)
            {
                if(G.arc[i][j]!=INF)
                    cout<<G.arc[i][j]<<"\t";
                else
                    cout<<"0"<<"\t";
            }
            else{
                if(G.arc[i][j]!=INF)
                    cout<<G.arc[i][j]<<endl;
                else
                    cout<<"0"<<endl;
            }
}
bool visited[10];
void BFS(MGrph G,int v)
{
    for(int i=0;i<G.vexnum;i++)
        visited[i]= false;
    cout<<v<<" ";
    visited[v]= true;
    queue<int>Q;
    Q.push(v);
    while (!Q.empty())
    {
        int t=Q.front();
        Q.pop();
        for(int w=0;w<G.vexnum;w++)
        {
            if(G.arc[t][w]!=INF&&visited[w]== false)
            {
                visited[w]= true;
                cout<<w<<" ";
                Q.push(w);
            }
        }

    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    MGrph G;
    Create_Graph_UDN(G);
    PrintGraph(G);
    BFS(G,0);
    return 0;
}
