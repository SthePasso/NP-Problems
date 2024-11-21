#include <iostream>
#include <vector>
using std::cout;
using std::vector;

class Graph{
    private:
        int size;
        int** adj_matrix;
        vector<int> visited;
    public:
        Graph(int**, int);
        Graph(int&, int);
        //gets and sets for atributs + display
        int get_size();
        int get_adj_matrix(int,int);
        vector<int> get_visited();
        void set_size(int size);
        void set_adj_matrix(int,int,int);
        void set_visited(vector<int>);
        void display_adj_matrix();
};
Graph::Graph(int** input_matrix, int size){//[4][4]){
    adj_matrix = input_matrix;
    this->size = size;
}
Graph::Graph(int& size, int visited){
    this->size = size;
}
int Graph::get_size(){
    return this->size;
}
int Graph::get_adj_matrix(int i, int j){
    return adj_matrix[i][j]; 
}

void Graph::display_adj_matrix(){
    //how to get the end of memory allocation;
    cout<<"Display adj_matrix"<<'\n';
    for(int i=0;i<this->size;i++){
        for(int j=0;j<this->size;j++){
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<'\n';
    }
}
vector<int> Graph::get_visited(){
    return this->visited;
}
void Graph::set_size(int size){
    this->size = size;
}
void Graph::set_adj_matrix(int i, int j, int weight){
    adj_matrix[i][j] = weight; 
}
void Graph::set_visited(vector<int> visited){
    this->visited = visited;
}

class TSP{
    private:
        Graph g;
        vector<int[3]>  path;//node: 1->w:10->node: 2
    public:
        TSP(Graph);
        void calculate_path();
        void print_shortest_path();
};

TSP::TSP(Graph g){
    this->g = g;
}
void TSP::calculate_path(){
    // walk to adj_matrix
    // find the minimun weigth with the node that is not visited
    // save the minimum weigth with node: 1->w:10->node: 2 in path
    // go to the next node
    
}

int main(){
    int size = 4;
    int matrix[4][4] = {{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}};
    int* matrix_pointer[4];
    for(int i=0;i<4;i++){
        matrix_pointer[i] = matrix[i];
    }
    Graph g(matrix_pointer, size); //how to send the memory address of a matrix?
    g.display_adj_matrix();
    Graph g2(size, 0);
    return 0;
}

































// https://www.geeksforgeeks.org/travelling-salesman-problem-using-dynamic-programming/
// bitcoin algorithm


