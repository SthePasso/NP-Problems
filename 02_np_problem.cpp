// Prime factorization
// Traveler Salesman
// Boolean Satisfability
#include<iostream>
#include<vector>

using std::cout;
using std::vector;
class Factorization{
public:
    Factorization(){};
    int Factor(int);
    void setPrime_vec(int);
    void display_vec();
private:
    vector<int> prime_vec;
    int prime;
};
void Factorization::display_vec(){
    for(int i=0;i<prime_vec.size();i++){
        cout<<prime_vec[i]<<" ";
    }
    cout<<'\n';
}
// loop i - n
//   loop prime_ve
//      i divisible by prime_vec - > if true, so the number is not prime
//      otherwise the number is prime    

void Factorization::setPrime_vec(int input){
    int j=0;
    // calculate prime num from 0 to input = 20 -> prime_vec = 2,3,5,7,11,13,17,19 
    for(int i=2;i<=input;i++){
        // if (input%i==1){
        //     prime_vec.push_back(i);
        // }
        prime_vec.push_back(2);
        if(i%prime_vec[j]!=0){
            prime_vec.push_back(i);
            j=0;
        } else{
            j++;
        }
        cout<<"i= "<<i<<" j="<<j<<'\n';
    }
}


// find prime number
// try prime number
int Factorization::Factor(int input){
return 0;
}


int main(){
    Factorization F;;
    F.setPrime_vec(12);
    cout<<"Display Vector:"<<'\n';
    F.display_vec();
    return 0;
}