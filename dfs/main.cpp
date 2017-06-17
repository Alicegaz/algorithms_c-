#include <iostream>
#include <deque>
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
        return (arr[x][y]==1);
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
    void dfs(int source, int dest)
    {
        assert(source >0 && dest >0);
        std::deque<int> q;
        bool *visited = new bool[n+1];
        for (int i = 0; i<=n; i++)
        {
            visited[i] = false;
        }
        q.push_back(source);
        visited[source] = true;
        cout << "dfs traversal from vertex " << source << endl;
        if(source == dest)
            return;

        while(!q.empty())
        {
            int current = q.back();
            q.pop_back();
            if (current == dest)
                break;
            cout << current << " ";
            for (int i = n; i >= 0; --i)
            {
                if(isEdge(current, i) && !(visited[i]))
                {
                    q.push_back(i);
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
    Graph g(10);
    g.add(1, 5);
    g.add(1, 2);
    g.add(3, 4);
    g.add(5, 6);
    g.add(4, 5);
    g.add(5, 8);
    g.add(7, 8);
    g.add(9, 4);
    g.add(5, 4);
    g.add(8, 3);
    g.dfs(3, 8);
    Graph s(5);
    s.add(1, 3);
    s.add(3, 2);
    s.add(2, 1);
    s.add(5, 3);
    s.add(1, 4);
    s.dfs(1, 4);
    return 0;
}
