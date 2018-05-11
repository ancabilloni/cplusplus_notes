#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <cmath>
#include <ctime>

std::vector<int> GenerateRandVec(int numOfNums, int min, int max);
void BubbleSort(std::vector<int>& theVec);
int Factorial(int number);
void PrintHorizontalVector(std::vector<int>& theVec);
int Fib(int number);
double Area(double radius);
double Area(double height, double width);

int main() {
    
    // Bubble Sort
    std::vector<int> testVec = GenerateRandVec(10, 5, 50);
    BubbleSort(testVec);
    for(auto x: testVec)
        std::cout << x << "\n";
    
    // Factorial
    std::cout << "Factorial 6 = " << Factorial(6) << "\n";
    
    // To print an array horizontally on the screen
    /*
     ------------------
     |  0  |  1  |  2  |
     --------------
     | 10  |  8  |  2  |
     --------------
     */
    std::vector<int> theVec = {10,8,2,5,9,11,6,14};
    PrintHorizontalVector(theVec);
    
    // Fibonnaci
    int index;
    std::cout << "Get Fibonacci Index: ";
    std::cin >> index;
    printf("Fib(%d) = %d\n", index, Fib(index));
    
    // Overloaded Functions: same name function but different params
    std::cout << "Area Circle (c) or Rectangle (r) : ";
    char areaType;
    std::cin >> areaType;
    
    switch(areaType){
        case 'c':
            std::cout << "Enter Radius : ";
            double radius;
            std::cin >> radius;
            std::cout << "Area = " << Area(radius) << "\n";
            break;
        case 'r':
            std::cout << "Enter Height : ";
            double height, width;
            std::cin >> height;
            std::cout << "Enter Width : ";
            std::cin >> width;
            std::cout << "Area = " << Area(height, width) << "\n";
            break;
        default : std::cout << "Please Enter c or r \n";
    }
    
    return 0;
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

void BubbleSort(std::vector<int>& theVec){
    int i = theVec.size() - 1;
    while(i >= 1){
        int j = 0;
        while(j < i){
            printf("\nIs %d > %d\n", theVec[j], theVec[j+1]);
            if(theVec[j] > theVec[j+1]){
                std::cout << "Switch\n";
                int temp = theVec[j];
                theVec[j] = theVec[j+1];
                theVec[j+1] = temp;
            } else {
                std::cout << "Don't Switch\n";
            }
            j += 1;
            for(auto k: theVec){
                std::cout << k << ", ";
            }
        }
        std::cout << "\nEnd of Round\n";
        i -= 1;
    }
}

int Factorial(int number){
    if(number==1){
        return 1;
    } else {
        int result = number * Factorial(number - 1);
        return result;
    }
}

void PrintHorizontalVector(std::vector<int>& theVec){
    int dashes = std::ceil(theVec.size() * 5);
    for(int n = 0; n < dashes; n++)
        std::cout << "-";
    std::cout << "\n";
    
    for(int n = 0; n < theVec.size(); n++)
        printf("| %2d ", n);
    std::cout << "|\n";
    
    for(int n = 0; n < dashes; n++)
        std::cout << "-";
    std::cout << "\n";
    
    for(int n = 0; n < theVec.size(); n++)
        printf("| %2d ", theVec[n]);
    std::cout << "|\n";
}

int Fib(int number){
    /*0,1,1,2,3,5*/
    if(number < 2) return number;
    
    return Fib(number-1) + Fib(number-2);
}

double Area(double radius){
    return M_PI*std::pow(radius, 2);
}
double Area(double height, double width){
    return height*width;
}
