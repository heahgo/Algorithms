#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdint>


class Vertex {
    private:
        uint32_t num_;
        uint32_t* adj_array_;
    public:
        Vertex();
        ~Vertex();
};

class Graph {
    private:
        Vertex* graph_;
};


uint32_t* GenAdjacencyArrayGraph(uint32_t vertex_num, uint32_t edge_num) {
    vertex
}


int main() {
    uint32_t* graph = GenAdjacencyArrayGraph(5, 3);

}