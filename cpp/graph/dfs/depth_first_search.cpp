#include <vector>
#include <cstdio>
#include <cstdint>

using std::vector;

class Vertex {
    public:
        uint32_t num_;
        Vertex* vertex_;
        Vertex* Next() {
            return this->vertex_;
        }
        void Add(Vertex* vertex) {
            Vertex* v = this;
            while (v->Next() != NULL) {
                v = v->Next();
            }
            v->vertex_ = vertex;
        }

        Vertex() : num_(0), vertex_(NULL) {}
        Vertex(uint32_t num) : num_(num), vertex_(NULL) {};
        ~Vertex() { 
            delete vertex_;
        }
};

class Graph {
    public:
        vector<Vertex*> graph_;
        uint32_t vertex_num_;
        uint32_t edge_num_;
        
        void Print() {  // Graph print Using Adjacent Linked List
        printf("**** Linked List Graph ****\n");
        printf("--------+------------------\n");
            for (uint32_t i = 0; i < vertex_num_; i++) {
                Vertex* tmp = graph_.at(i);
                printf("idx : %u | ", i+1);
                tmp = tmp->Next();
                while(tmp->Next() != NULL) {
                    printf("%u ", tmp->num_);
                    tmp = tmp->vertex_;
                }
                printf("%u \n", tmp->num_);
            }
        printf("--------+------------------\n");
        }

        Graph(uint32_t vertex_num, uint32_t edge_num) : vertex_num_(vertex_num), edge_num_(edge_num) {
            for (uint32_t i = 0; i < vertex_num; i++) {
                Vertex* tmp = new Vertex(i+1);
                graph_.push_back(tmp);
            }
            uint32_t v1, v2;
            for (uint32_t i = 0; i < edge_num; i++) {
                printf("Input two-way edges (ex : 1 2): ");
                scanf("%u %u", &v1, &v2); // Input two-way edges
                Vertex* tmp1 = new Vertex(v2);
                graph_.at(v1-1)->Add(tmp1);  

                if (v1 == v2) continue;
                Vertex* tmp2 = new Vertex(v1);
                graph_.at(v2-1)->Add(tmp2);
            }
        }
        ~Graph() { 
            for (uint32_t i = 0; i < vertex_num_; i++) {
                graph_.at(i)->~Vertex();
            }
        }
};

vector<uint32_t> DFS(Graph* graph, uint32_t start) {
    vector<Vertex*> g = graph->graph_;
    vector<Vertex*> stack;
    vector<uint32_t> result;
    bool* visited = new bool[graph->vertex_num_+1];       // init false
    for (uint32_t i = 0; i < graph->vertex_num_; i++) {
        visited[i] = false;
    }

    uint32_t n = start-1;
    Vertex* v = g.at(n);

    stack.push_back(v);
    visited[n] = true;
    result.push_back(start);
    v = v->Next();

    while(stack.size() != 0) {
        if (v != NULL) {
            if (visited[v->num_-1] == true) {
                v = v->Next();
                continue;
            }
            n = v->num_-1;
            result.push_back(n+1);
            visited[n] = true;
            stack.push_back(v);
            v = g.at(n);
        } else {
            v = stack.back();
            stack.pop_back();
        }
    }
    delete[] visited;
    return result;
}

int main() {
    uint32_t vertex, edge;
    printf("Input vertex number and edge number (ex 1 2): ");
    scanf("%u %u", &vertex, &edge); 
    Graph graph = Graph(vertex, edge);

    graph.Print();
    vector<uint32_t> dfs_result;

    uint32_t start = 1;
    printf("Input start vertex : ");
    scanf("%u", &start);

    printf("\nDFS : ");
    dfs_result = DFS(&graph, start);  
    for (uint32_t i = 0; i < dfs_result.size(); i++) {
        printf("%u ", dfs_result.at(i));
    }
    printf("\n\n");
}
