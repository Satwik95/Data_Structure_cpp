/*
 * C++ Program to Implement Adjacency List
 */
#include <iostream>
#include <cstdlib>
using namespace std;

/*
 * Adjacency List Node
 */
struct AdjListNode
{
    int dest;
    AdjListNode* next;
};

/*
 * Adjacency List
 */
struct AdjList
{
    AdjListNode *head;
};

/*
 * Class Graph
 */
class Graph
{
    private:
        int V;
        AdjList* array;
        bool visited;
    public:
        Graph(int V)
        {	visited = new bool[V];
            this->V = V;
            array = new AdjList [V];
            for (int i = 0; i < V; ++i)
               {
               	array[i].head = NULL;
               } 

            for(int i = 0;i<V;i++)
            {
            	visited[i] = FALSE;
            }   


        }
        /*
         * Creating New Adjacency List Node
         */
        AdjListNode* newAdjListNode(int dest)
        {
            AdjListNode* newNode = new AdjListNode;
            newNode->dest = dest;
            newNode->next = NULL;
            return newNode;
        }
        /*
         * Adding Edge to Graph
         */
        void addEdge(int src, int dest)
        {
            AdjListNode* newNode = newAdjListNode(dest);
            newNode->next = array[src].head;
            array[src].head = newNode;
            newNode = newAdjListNode(src);
            newNode->next = array[dest].head;
            array[dest].head = newNode;
        }
        /*
         * Print the graph
         */
        void printGraph()
        {
            int v;
            for (v = 0; v < V; ++v)
            {
                AdjListNode* ptr = array[v].head;
                cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
                while (ptr)
                {
                    cout<<"-> "<<ptr->dest;
                    ptr = ptr->next;
                }
                cout<<endl;
            }
        }

        void dfs(int start)
         {
        	visited[start] = true;
        	cout<<"visiting:"+ start;


        	AdjListNode* temp = array[start].head;

            while(temp!=null)
        	{
        		if(!visited[temp->dest])
        			dfs(temp->dest);

                else
                    temp=temp->next;
                    dfs(temp->dest);

        	}
        	
        	for(int i = 0;i<V;i++)
        	{
        		if(!visited[i])
        		{
        			dfs(i);
        		}
        	}



        }
};

/*
 * Main
 */
int main()
{
    Graph gh(5);
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);

    // print the adjacency list representation of the above graph
    gh.printGraph();

    return 0;
}
