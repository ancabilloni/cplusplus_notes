#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <functional> // for function

std::vector<int> GenerateRandVec(int numOfNums, int min, int max);
std::vector<int> GenerateFibList(int numberOfFibs);

int main(){
    std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
    
    // Sorting with Lambda
    std::cout << "Before sorting: \n";
    for(auto val: vecVals)
        std::cout << val << " ";
    
    std::sort(vecVals.begin(), vecVals.end(), [](int x, int y){return x < y;});
    std::cout << "\nSorted: \n";
    for(auto val: vecVals)
        std::cout << val << " ";
    
    // Copy If
    std::vector<int> evenVecVals;
    std::copy_if(vecVals.begin(), vecVals.end(),
            std::back_inserter(evenVecVals),
            [](int x){return (x % 2) == 0;});
    std::cout << "\nEven Values: \n";
    for(auto val: evenVecVals)
        std::cout << val << " ";
    
    // Sum
    int sum = 0;
    std::for_each(vecVals.begin(), vecVals.end(),
            [&](int x){sum += x; });
    std::cout << "\nSum " << sum << "\n";
    
    // Problem: create a dynamic list that is divisable by a value
    int divisor;
    std::vector<int> vecVals2;
    std::cout << "List of values Divisable by : ";
    std::cin >> divisor;
    std::copy_if(vecVals.begin(), vecVals.end(),
            std::back_inserter(vecVals2),
            [divisor](int x){return (x % divisor) == 0;});
    
    for(auto val: vecVals2)
        std::cout << val << " ";
    
    // How to multiply all values in one vector
    std::vector<int> doubleVec;
    std::for_each(vecVals.begin(), vecVals.end(),
            [&](int x){doubleVec.push_back(x*2);});
    std::cout << "\nDouble Vector: ";
    for(auto val: doubleVec)
        std::cout << val << " ";
    
    // Sum of two vectors
    
    std::vector<int> vec1 = {1,2,3,4,5};
    std::vector<int> vec2 = {1,2,4,5,6};
    std::vector<int> vec3(5);
    
    transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(), [](int x, int y){return x + y;});
    
    for(auto val: vec3)
        std::cout << val << " ";
            
    // Ternary operator
    int age = 43;
    bool canIVote = (age >= 18) ? true : false;
    std::cout.setf(std::ios::boolalpha);
    std::cout << "Can Derek Vote : " << canIVote << "\n";
    
    // Recursive lambda
    std::function<int(int)> Fib = [&Fib](int n)
    {return n < 2 ? n : Fib(n-1) + Fib(n - 2);};
    
    std::cout << "Fib 4 : " << Fib(4) << "\n";
    
    // Create a list of fibonacci numbers
    std::vector<int> listOfFibs = GenerateFibList(10);
    for(auto val: listOfFibs)
        std::cout << val << "\n";
    
}

std::vector<int> GenerateRandVec(int numOfNums, int min, int max){
    std::vector<int> vecValues;
    srand(time(NULL));
    int i = 0, randVal = 0;
    while(i < numOfNums){
        randVal = min + std::rand() % ((max + 1) - min); // the modulus can never be greater than the divider
        vecValues.push_back((randVal));
        i++;
    }
    
    return vecValues;
}

std::vector<int> GenerateFibList(int numberOfFibs){
    std::vector<int> listOfFibs;
    
    std::function<int(int)> Fib = [&Fib](int n)
    {return n < 2 ? n : Fib(n-1) + Fib(n - 2);};
    
    for(int i=0; i <= numberOfFibs; i++){
        listOfFibs.push_back(Fib(i));
    }
    return listOfFibs;
}
