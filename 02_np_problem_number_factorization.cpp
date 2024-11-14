// Prime factorization
// Traveler Salesman
// Boolean Satisfability
#include<iostream>
#include<vector>
#include<chrono>

using std::cout;
using std::vector;
class Factorization{
public:
    Factorization(long long int input){
      factor(input);
    };
    void factor(int);
    void setPrime_vec(int);
    void display_vec();
    bool shold_print_star(int);
private:
    vector<int> prime_vec;
    vector<int> factor_vec;
    int input;
};

bool Factorization::shold_print_star(int begin){
    bool result = false;
    for(int i= begin+1;i<factor_vec.size();i++){
        if(factor_vec[i]!=0){
            result = true;
        }
    }
    return result;
}

void Factorization::display_vec(){
    cout<<"Number: "<<input<<" Factor: ";
    for(int i=0;i<prime_vec.size();i++){
        if(factor_vec[i]!=0){
        cout<<prime_vec[i]<<'^'<<factor_vec[i];
        //to display the * when next factor is not zero
        // cout<<"debug:"<<" i:"<<i<<" power:"<<factor_vec[i+1];
        // 1 2 3 [0 0 0 1]
        if(this->shold_print_star(i)){
            cout<<" "<<"*"<<" ";
        }
      }
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
    this->prime_vec.push_back(2);
    for(int i=3;i<=input;i++){
        // if (input%i==1){
        //     prime_vec.push_back(i);
        // }
        
        if(i%this->prime_vec[j]!=0){
            this->prime_vec.push_back(i);
            j=0;
        } else{
            j++;
        }
        //cout<<"i= "<<i<<" j="<<j<<'\n';
    }
}


// find prime number
// try prime number
void Factorization::factor(int input){
    this->input = input;
    this->setPrime_vec(input);
    for(int i=0;i<prime_vec.size();i++){
        this->factor_vec.push_back(0);
    }
    //2,3,5
    
    for(int i=0;i<prime_vec.size();i++){
        while(input%prime_vec[i]==0){
            input = input/prime_vec[i];
            this->factor_vec[i]+=1;
            
        }
    }
    //cout<<'\n';
}


int main(){
    // Factorization F;
    // F.setPrime_vec(12);
    // cout<<"Display Vector:"<<'\n';
    // F.display_vec();
    // Factorization f1(31);
    // Factorization f2(51);
    // Factorization f3(64);
    // Factorization f4(23);

    // f1.display_vec();
    // f2.display_vec();
    // f3.display_vec();
    // f4.display_vec();

    auto start = std::chrono::high_resolution_clock::now();
    Factorization f6(32);
    f6.display_vec();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Duration: " << duration1.count() << " microseconds\n";

    start = std::chrono::high_resolution_clock::now();
    Factorization f5(4666661);
    f5.display_vec();
    stop = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Duration: " << duration2.count() << " microseconds\n";
    return 0;
}