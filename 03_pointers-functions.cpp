#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric> 

/* Function prototype*/
double AddNumbers(double num1, double num2);
void AssignAge(int age);
int AssignAge2(int age);

int main() {
    
    std::vector<int> myVec(10);
    std::iota(std::begin(myVec), std::end(myVec),0); // set values from 0 to 9
    // if problem with iota, need to set to c++ 11
    for(int i=0; i < myVec.size(); ++i){
        std::cout << myVec[i] << std::endl;
    }
    
    for(auto y: myVec) std::cout << y << "\n"; // same thing as previous for loop
    
    int val = 8;
    if((val%2) == 0){
        std::cout << val << " is even\n";
    }else {
        std::cout << val << " is odd\n";
    }
    
    /**** Generate a vector from 1 to 10, and print out the even ****/
    std::vector<int> myVec(10);
    std::iota(std::begin(myVec), std::end(myVec),1); // generate from 1 to fill vector
    for(int i=0; i<myVec.size(); ++i){
        if((myVec[i]%2) == 0){
            std::cout << myVec[i] << "\n";
//        }
//    }
    /* Practice functions */
    double num1, num2;
    std::cout << "Enter Num 1: ";
    std::cin >> num1; // receiving input and push to num1
    std::cout << "Enter Num2: ";
    std::cin >> num2;
    printf("%.1f + %.1f = %.1f\n", num1, num2, AddNumbers(num1, num2));
    
    int age = 43;
    AssignAge(age);
    std::cout << "New age " << age << "\n"; // still return 43 because no memory
                                            // location being assigned
    
    age = AssignAge2(age);
    std::cout << "Returned age " << age << "\n";
    
    return 0;
}

// FUNCTIONS

double AddNumbers(double num1, double num2){
    return num1 + num2;
}
// void does not return anything
void AssignName(){
    std::string name = "An";
}

void AssignAge(int age){
    age = 24;
}

int AssignAge2(int age){
    age = 24;
    return age;
}

// END FUNCTIONS


/********* POINTERS ************/

// Function Prototype
void AssignAge3(int* pAge);
void DoubleArray(int* arr, int size);


int main(){
    int age = 43;
    int* pAge = NULL;
    
    pAge = &age; //& is reference operator, return address for the variable
    
    std::cout << "Address : " << pAge << "\n"; // return heximal numbers
    
    std::cout << "Value at Address : " << *pAge << "\n"; // return the value the pointer points to
    
    int intArray[] = {1,2,3,4};
    int* pIntArray = intArray; // no need to put & for array
    
    std::cout << "1st " << *pIntArray << " Address " << pIntArray << "\n";
    pIntArray++;
    std::cout << "2nd " << *pIntArray << " Address " << pIntArray << "\n";
    pIntArray--;
    std::cout << "1st " << *pIntArray << " Address " << pIntArray << "\n";
    
    
    int age = 43;
    AssignAge3(&age);
    std::cout << "Pointer Age " << age << "\n";
    
    int arr[] = {1,2,3,4};
    DoubleArray(arr, 4);
    for(int i=0; i<4; ++i){
        std::cout << "Array " << arr[i] << "\n";
    }
    
    return 0;
}
//
// FUNCTIONS
void AssignAge3(int* pAge){
    *pAge = 22;   
}

void DoubleArray(int* arr, int size){
    for(int i=0; i<size; ++i){
        arr[i] = arr[i] * 2;
    }
}
    
/*******Exercise : Make a Range(start, end) function*****/

// Function prototype
std::vector<int> Range(int start, int end, int step);

int main(){
    int start, end;
    std::vector<int> range;
    std::cout << "Enter start of range: \n";
    std::cin >> start;
    std::cout << "Enter end of range: \n";
    std::cin >> end;
    
    range = Range(start, end, 2);
    
    for(auto a: range){
        std::cout << a << "\n";
    }
}

// Function
std::vector<int> Range(int start, int end, int step){
    std::vector<int> range;
    for(int i=start; i<=end; i=i+step){
        range.push_back(i);
    }
    
//    // OR
//    int i = start;
//    while(int i <= end){
//        range.push_back(i);
//        i += step;
//    }
    return range;
}

/***** Exercise: Find compound interest after x years ***/
float totalReturn(float startAmount, float intRate, int numOfYears);

int main() {
    float startAmount;
    float intRate;
    int numOfYears = 10;
    
    std::cout << "How much to invest: ";
    std::cin >> startAmount;
    std::cout << "Interest Rate: ";
    std::cin >> intRate;
    
    float total_return = totalReturn(startAmount, intRate, numOfYears);
    std::cout << "Value after " << numOfYears << " years is : " << total_return;
    
    return 0;
}

// Function
float totalReturn(float startAmount, float intRate, int numOfYears){
    float total_return = startAmount;
    for(int i=0; i<numOfYears; i++){
        total_return += total_return*intRate*.01;
    } 
    return total_return;
}
