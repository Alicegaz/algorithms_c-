#include <iostream>
#include <queue>
#include <assert.h>
#include <stdio.h>

using namespace std;

class Graph{
private:
    int n;
    int **arr;
public:
    Graph(int s)
    {
        assert(s>0);
        n = s;
        arr = new int *[n];
        for (int i = 0; i < n; ++i)
            arr[i] = new int[n];
        for (int i = 0; i < n; ++i)
        {
            for(int j = 0; j<n; ++j){
                arr[i][j] = 0;
            }
        }

    }
    ~Graph(){
        for(int i = 0; i < n; ++i)
            delete [] arr[i];
        delete [] arr;
    }

    bool isEdge(int x, int y)
    {
        assert(x>0 && y>0);
        return (arr[x-1][y-1]==1);
    }
    void add(int x, int y){
        assert(x>0 && y>0);
    arr[x-1][y-1] = 1;
    arr[y-1][x-1] = 1;
    }
    void remove1(int x, int y){
        assert(x>0 && y>0);
    arr[x-1][y-1] = 0;
    arr[y-1][x-1] = 0;
    }
    void bfs(int source, int dest)
    {
        assert(source>0 && dest > 0)
        std::queue<int> q;
        bool *visited = new bool[n+1];
        for (int i = 1; i<=n; i++)
        {
            visited[i] = false;
        }
        q.push(source);
        visited[source] = true;
        cout << "dfs traversal from vertex " << source << endl;
        if(source == dest)
        {
            return;
        }

        while(q.size()!=0)
        {
            int current = q.front();
            q.pop();
            if (current == dest)
            {
                break;
            }
            cout << current << " ";
            for (int i = 1; i <= n; ++i)
            {
                if(isEdge(current, i) && !(visited[i]))
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
            cout<<endl;
            delete [] visited;
        }

          };
int main()
{

    Graph g1(12);
    g1.add(1, 2);
    g1.add(2, 4);
    g1.add(1, 3);
    g1.add(3, 4);
    g1.add(3, 6);
    g1.add(4, 7);
    g1.add(5, 6);
    g1.add(5, 7);
    g1.bfs(1, 5);
    return 0;
}

