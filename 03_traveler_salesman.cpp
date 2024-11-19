#include <iostream>
#include <vector>
using std::cout;
using std::vector;

class Graph{
    private:
        int size = 0;
        int adj_matrix;
        vector<int> visited;
    public:
        Graph(int&&);
        Graph(int&, int);
        //gets and sets for atributs + display
};
Graph::Graph(int input_matrix[4][4]){
    adj_matrix = input_matrix;
}
Graph::Graph(int& size, int visited){
    this->size = size;
}

class TSP{
    private:
        Graph g;
    public:
        TSP();
        void print_shortest_path();
};

TSP::TSP(Graph g){
    this->g = g;
}

int main(){
    int size = 4;
    int matrix[4][4] = {{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}};
    Graph g(matrix); //how to send the memory address of a matrix?
    Graph g2(size, 0);
    return 0;
}

































// https://www.geeksforgeeks.org/travelling-salesman-problem-using-dynamic-programming/
// bitcoin algorithm


