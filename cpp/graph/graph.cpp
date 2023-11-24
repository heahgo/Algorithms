#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdint>

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
        std::vector<Vertex*> graph_;
        uint32_t vertex_num_;
        uint32_t edge_num_;
        
        void Print() {  // Graph print Using Adjacent Links List
            for (uint32_t i = 0; i < vertex_num_; i++) {
                Vertex* tmp = graph_.at(i);
                while(tmp->Next() != NULL) {
                    printf("%u ", tmp->num_);
                    tmp = tmp->vertex_;
                }
                printf("%u \n", tmp->num_);
            }
        }

        Graph(uint32_t vertex_num, uint32_t edge_num) : vertex_num_(vertex_num), edge_num_(edge_num) {
            for (uint32_t i = 0; i < vertex_num; i++) {
                Vertex* tmp = new Vertex();
                graph_.push_back(tmp);
            }
            uint32_t v1, v2;
            for (uint32_t i = 0; i < edge_num; i++) {
                scanf("%u %u", &v1, &v2); // Input two-way edges
                Vertex* tmp1 = new Vertex(v2);
                graph_.at(v1-1)->num_ += 1;
                graph_.at(v1-1)->Add(tmp1);  

                if (v1 == v2) continue;
                Vertex* tmp2 = new Vertex(v1);
                graph_.at(v2-1)->num_ += 1;
                graph_.at(v2-1)->Add(tmp2);
            }
        }
        ~Graph() { 
            for (uint32_t i = 0; i < vertex_num_; i++) {
                graph_.at(i)->~Vertex();
            }
        }
};

int main() {
    uint32_t vertex, edge;
    scanf("%u %u", &vertex, &edge); 
    Graph graph = Graph(vertex, edge);
    printf("----------------\n");
    graph.Print();
}
