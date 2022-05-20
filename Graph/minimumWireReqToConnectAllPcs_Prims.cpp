#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge
{  
public:
  int src = 0; 
  int nbr = 0;
  int wt = 0;

  Edge(int src, int nbr, int wt)
  {
    this->src = src; 
    this->nbr = nbr;
    this->wt = wt;
  }
};

class Pair{
  public:
  int v;
  int av;
  int w;

  Pair(int v,int av,int w){
    this->v=v;
    this->av=av;
    this->w=w;
  }
};

bool operator <(const Pair &p1,const Pair &p2){
  return p1.w > p2.w;
}

void solve(vector<vector<Edge>>&graph,vector<bool>&vis){
  priority_queue<Pair>pq;
  pq.push(Pair(0,-1,0));
  while(!pq.empty()){
    Pair rem = pq.top();
    pq.pop();

    if(vis[rem.v]==true){
      continue;
    }
    vis[rem.v]=true;
    if(rem.av != -1){
      cout<<"["<<rem.v<<"-"<<rem.av<<"@"<<rem.w<<"]"<<endl;
    }

    for(auto x:graph[rem.v]){
      if(vis[x.nbr]==false){
        pq.push(Pair(x.nbr,x.src,x.wt));
      }
    }
  }
  return;
}

int main() {                                                        
    
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());
  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w; 
    cin >> u >> v >> w; 
 
    graph[u].push_back(Edge(u, v, w));
    graph[v].push_back(Edge(v, u, w));

  }   

  //write your code here  
  vector<bool>vis(vtces,false);
  solve(graph,vis);
  
  return 0;
}
