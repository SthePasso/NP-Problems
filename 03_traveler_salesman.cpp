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
        int get_visited_sum();
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
int Graph::get_visited_sum(){
    int sum=0;
    for(auto num : this->visited){
        sum+=num;
    }
    return sum;
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
        vector<vector<int>>  path;//node: 1->w:10->node: 2
    public:
        TSP(Graph);
        void calculate_path();
        void print_shortest_path();
};

TSP::TSP(Graph new_g): g(0,0){
    this->g = new_g;
}
void TSP::calculate_path(){
    // walk to adj_matrix
    int min_weight = 9999;
    int current_weight;
    int row =0;
    int next_row=-1;
    cout<<"calculate_path"<<'\n';
    //g.display_adj_matrix();
    while(g.get_visited_sum()!=g.get_size()&& next_row!=0){
        if(g.get_visited()[row]){
            cout<<"calculate_path 3"<<'\n';
            continue;
        }
        else{
            cout<<"calculate_path 1"<<'\n';
            for(int i=0;i<g.get_size();i++){
                current_weight = g.get_adj_matrix(row,i);
                if(current_weight<min_weight && g.get_visited()[row]==0){
                    cout<<"calculate_path 2"<<'\n';
                    min_weight = current_weight;
                    next_row = i;
                    cout<<"node: "<<row<<" weight: "<<min_weight<<" node: "<<next_row<<'\n';
                }
            }
            row = next_row;
        }
    }
        
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
    //Graph g2(size, 0);
    cout<<"before t1 created"<<'\n';
    TSP t1(g);
    cout<<"after t1 created"<<'\n';
    t1.calculate_path();
    return 0;
}

//g++ -std=c++11 01_complexity.cpp
































// https://www.geeksforgeeks.org/travelling-salesman-problem-using-dynamic-programming/
// bitcoin algorithm


