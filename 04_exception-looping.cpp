#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <ctime> // give number of seconds 

std::vector<int> Range(int start, int end, int step);

int main() {
   int i = 1;
   
   while (i <= 20){
       if((i%2)==0){
           i += 1;
           continue; //skip everything after this line and keep on next loop
       }
       
       if (i == 15) break; // break out of loop and stop loop
       std::cout << i << "\n";
       i += 1;
   }
   return 0;
}

/* First problem: create a program to draw pine tree on the screen
   #
  ###
 #####
#######
#########
   #
* 1. Decrement space by one each time through the loop
* 2. Increment the hashes by 2 each time
* 3. Save spaces to the stump by calculating tree height - 1
* 4. Decrement from tree height until equals zero
* 5. Print spaces and then hashes for each row
* 6. Print stump spaces then 1 hash
*/
  
int main() {
   
   std::cout << "How tall is the tree? ";
   int treeH, space, hash, stumpSpace;
   std::cin >> treeH;
   space = treeH - 1;
   hash = 1;
   stumpSpace = treeH - 1;
   
//    int i = 0;
   
   while(treeH != 0){
//        for(int j=0; j<space; j++){
//            std::cout<<" ";
//        }
//        for(int j=0; j<hash; j++){
//            std::cout<<"#";
//        }
       for(auto x: Range(1, space, 1)) 
           std::cout<< " ";
       for(auto x: Range(1, hash, 1)) 
           std::cout<< "#";
       std::cout<<"\n";
       treeH -= 1;
       hash += 2;
       space -= 1;
   }
   
   for(auto x: Range(1,stumpSpace,1)) std::cout<<" ";
   std::cout<<"#"<<"\n";

   return 0;
}

/* Exception Handling */
int main() {
   
   double num1 = 0, num2 = 0;
   std::cout << "Enter number 1: ";
   std::cin >> num1;
   std::cout << "Enter number 2: ";
   std::cin >> num2;
   
   try {
       if (num2==0){
           throw "Division by zero is not possible.";
       } else {
           printf("%.1f / %.1f = %.2f", num1, num2, (num1/num2));
       }
   }
   
   catch(const char* exp){
       std::cout << "Error: " << exp << "\n";
   }
   return 0;
}

int main(){
   
   try {
       std::cout << "Throwing exception\n";
       throw std::runtime_error("Error Occurred");
       std::cout << "Can you print me?\n";
   }
   
   catch(std::exception &exp){
       std::cout <<"Handled Exception: " <<
               exp.what() << "\n";
   }
   
   catch(...){
       std::cout << "Default Exception\n";
   }
   return 0;
}

/* Do while loop*/

int main() {
    
    srand(time(NULL));
    int secretNum = std::rand() % 11;
    int guess = 0;
    
    while(true){
        std::cout << "Guess the number: ";
        std::cin >> guess;
        if(guess > secretNum) std::cout << "Too big\n";
        if(guess < secretNum) std::cout << "Too small\n";
        if(guess == secretNum) break;
    }
    
   do{
       std::cout << "Guess the number: ";
       std::cin >> guess;
       if(guess > secretNum) std::cout << "Too big\n";
       if(guess < secretNum) std::cout << "Too small\n";
   }while(secretNum != guess);
    
    std::cout << "You guessed it \n";
    return 0;
}


// Function
std::vector<int> Range(int start, int end, int step){
    std::vector<int> range;
    for(int i=start; i<=end; i=i+step){
        range.push_back(i);
    }
    return range;
}

 // End Function
