#include <stdio.h>
#include <queue>
#include <iostream>
/// http://www.cplusplus.com/reference/queue/queue/

using namespace std;
template<typename TnodeInfo, typename TedgeInfo>
class Graph {
    public:
        int N;
        char **A;
        TnodeInfo *nodeInfo;
        TedgeInfo **edgeInfo;

        Graph(int numNodes) {
            int i, j;

            N = numNodes;

            /// allocate the adjacency matrix
            A = new char*[N]; ///allocated rows
            for (i = 0; i < N; i++)
                A[i] = new char[N]; ///allocated columns

			for (i = 0; i < N; i++)
                for (j = 0; j < N; j++)
                    A[i][j] = 0;

            // allocate the array with node information
            nodeInfo = new TnodeInfo[N];

            // allocate the matrix of edge information
            edgeInfo = new TedgeInfo*[N];
            for (i = 0; i < N; i++)
                edgeInfo[i] = new TedgeInfo[N];
        }

        void setNodeInfo(int i, TnodeInfo info) {
            nodeInfo[i] = info;
        }

        TnodeInfo getNodeInfo(int i) {
            return nodeInfo[i];
        }

        void addEdge(int i, int j) {
            A[i][j] = 1;
        }
        void removeEdge(int i, int j) {
            A[i][j] = 0;
            }

        void setEdgeInfo(int i, int j, TedgeInfo info) {
            edgeInfo[i][j] = info;
            }

        TedgeInfo getEdgeInfo(int i, int j) {
            return edgeInfo[i][j];
            }

        ~Graph() {
            int i;
            for (i = 0; i < N; i++) {
                delete A[i];
                delete edgeInfo[i];
            }
            delete A;
            delete edgeInfo;
            delete [] nodeInfo;
        }
};
Graph<int, int> g(12);
char* visited;

void dfs(int x) {
    int y;
    printf("%d\n", x);
    visited[x] = 1;

    for (y = 0; y < g.N; y++)
        if (g.A[x][y] && !visited[y])
            dfs(y);
}
void bfs(int S) {
    std::queue<int> Q;
    int x, y;

    Q.push(S);
    visited[S] = 1;

    while (!Q.empty()) {
        x = Q.front();
		Q.pop(); ///dequeue
        printf("%d\n", x);
        for (y = 0; y < g.N; y++)
            if (g.A[x][y] && !visited[y]) {
                visited[y] = 1;
               Q.push(y);
            }
    }
}


int main() {
    int i;

    visited = new char[g.N];
    for (i = 0; i < g.N; i++)
        visited[i] = 0;

   return 0;
}

