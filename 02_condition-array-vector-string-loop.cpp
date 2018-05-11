#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream> // manipulate string
#include <limits> // used to find min and max values of different data type

int main() {
   // 1 - 18, 21, 50, > 65
   std::string sAge = "0";
   std::cout << "Enter your age: ";
   getline(std::cin, sAge);
   int nAge = std::stoi(sAge);
   
   if ((nAge >= 1) && (nAge <= 18)){
       std::cout << "Important Birthday\n";
   } else if ((nAge == 21) || (nAge == 50)) {
       std::cout << "Important Birthday\n";
   } else if (nAge >= 65){
       std::cout << "Important Birthday\n";
   }else {
       std::cout << "Not Important Birthday\n";
   }

   return 0;
}

/* Exercise 2
 * */
//
int main(){
   // if age 5 "Go to Kindergarden
   // age 6 through 17 -> 1 through 12
   // age > 17, "Go to college"
   // Enter age: 2
   // Too young for school
   // Enter age: 8
   // Go to grade 3
   std::string sAge = "0";
   std::cout << "Enter age: ";
   getline(std::cin, sAge);
   int nAge = std::stoi(sAge);
   
   if (nAge == 5){
       std::cout << "Go to Kindergarden\n";
   } else if((nAge >= 6) && (nAge <= 17)){
       int grade = (nAge-6) + 1;
       std::cout << "Go to grade " << grade << "\n";
   } else if (nAge > 17){
       std::cout << "Go to college\n";
   } else{
       std::cout << "Too young for school\n";
   }
}

/* Array 3*/
int main(){
   int arrnNums[10] ={1};
   int arrnNums2[] = {1,2,3};
   int arrnNums3[5]={8,9};
   
   std::cout << "1st Value: " << arrnNums3[0] << "\n";
   arrnNums3[0]=7;
   std::cout << "1st Value: " << arrnNums3[0] << "\n";
   
   std::cout << "Array size: " <<
           sizeof(arrnNums3) / sizeof(*arrnNums3) << "\n";
   
   // multi dimensional array
   int arrnNums4[2][2][2] = {{{1,2}, {3,4}}, {{5,6},{7,8}}};
   
   std::cout << arrnNums4[1][1][1] <<"\n";
   return 0;
}

/* Vector 
 With array, once the size is set, we cannot change it.
 However, vector is resizable*/

int main(){
   std::vector<int> vecnRandNums(2);
   vecnRandNums[0] = 10;
   vecnRandNums[1] = 10;
   vecnRandNums.push_back(30);
   std::cout << "last index :" <<
           vecnRandNums[vecnRandNums.size() - 1] << "\n";
   
   std::string sSentence = "This is a random string";
   std::vector<std::string> vecsWords;
   std::stringstream ss(sSentence);
   std::string sIndivStr;
   char cSpace = ' ';
   
   while(getline(ss, sIndivStr, cSpace)){
       vecsWords.push_back(sIndivStr);
   }
   
   for (int i=0; i<vecsWords.size(); i++){
       std::cout << vecsWords[i] << "\n";
   }
   
   return 0;
   
}

/* Exercise 3: Simple calculator*/

int main(){
    // enter calculation (ex. 5 + 6) : 10 - 6
    // 10.0 - 6.0 = 4.0
    // + - * / 5 % 6 => Please enter + - / * only
    
    double num1=0; double num2=0;
    std::string op =" ";
    std::vector<std::string>  vecsOperations;
    std::string mathOperation;
    std::cout << "Enter calculation (ex. 5 + 6): \n";
    getline(std::cin, mathOperation);
    std::stringstream ss(mathOperation);
    std::string sIndivStr;
    char cSpace = ' ';
    
    while (getline(ss, sIndivStr, cSpace)){
        vecsOperations.push_back(sIndivStr);
    }
    num1 = std::stod(vecsOperations[0]);
    num2 = std::stod(vecsOperations[2]);
    op = vecsOperations[1];
    double result;
    
    if (op == "+") {
        result = num1 + num2;
        printf("%.1f + %.1f = %.1f", num1, num2, result);
    } else if(op == "-"){
        result = num1 - num2;
        printf("%.1f - %.1f = %.1f", num1, num2, result);
    } else if(op == "*"){
        result = num1 * num2;
        printf("%.1f * %.1f = %.1f", num1, num2, result);
    } else if(op == "/"){
        result = num1 / num2;
        printf("%.1f / %.1f = %.1f", num1, num2, result);
    } else {
        std::cout << "Please enter + - / * only \n";
    }
    
}
