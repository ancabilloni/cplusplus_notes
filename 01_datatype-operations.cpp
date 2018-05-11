#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream> // manipulate string
#include <limits> // used to find min and max values of different data type

//using namespace std; //output information on the screen

/**** Printing tutorial: ****
Start here at main, argc: argument, argv is array */

int main(int argc, char** argv) {
   
   std::cout << "Hello World" << std::endl; // use \n or endl
   
   // Check if any argument was passed
   
   if (argc != 1){ // if not equal to 1, it means we receive something
       std::cout << "You entered " << argc <<
               " argument\n";
   }
   
   for (int i=0; i<argc; ++i){
       std::cout << argv[i] << "\n";
   }

   return 0; // 0 means the program is ok, if -1 then there is problem
}

/* Data types*/
int g_iRandNum = 0 ; // global variable, outside of main loop and can be used anywhere

const double PI = 3.14159; // constant and cannot change it

int main(){
   
   bool bMarried = true; // true or false
   char chMyGrade = 'A'; //store 256 possible characters
   unsigned short int u16Age = 43 ; // 'unsigned' don't need a negative value
   short int siWeight = 180; // min -32000 and max 32767
   int nDays = 7; //normal integer
   long lBigNum = 1100000; // large value integer
   float fPi = 3.14159; // decimal point
   double dbBigFloat = 1.111111111111111111; // bigger than float
   long double ldPi = 3.14159; // bigger double
   auto whatWillIBe = true; // turn this into boolean automatically
   
   std::cout << "Min Bool " << std::numeric_limits<bool>::min() << "\n";
   std::cout << "Max Bool " << std::numeric_limits<bool>::max() << "\n";
   
   std::cout << "Min unsigned short int " << std::numeric_limits<unsigned short int>::min() << "\n";
   std::cout << "Max unsigned short int " << std::numeric_limits<unsigned short int>::max() << "\n";
   
   std::cout << "Min short int " << std::numeric_limits<short int>::min() << "\n";
   std::cout << "Max short int " << std::numeric_limits<short int>::max() << "\n";
   
   // Size 
   std::cout << "Size of int " << sizeof(int) << "\n";
   
   // How float blew precision
   double fBigFloat = 1.1111111111;
   double fBigFloat2 = 1.1111111111;
   double dbFloatSum = fBigFloat + fBigFloat2;
   
   printf("dbFloatSum Precision : %.20f\n", dbFloatSum);
   
   printf("%c %d %5d %.3f %s \n", 'A', 10, 5, 3.1234, "Hi");
   
   return 0;
}

/* Math operator and input from user*/

int main() {
   std::string sQuestion ("Enter number 1: ");
   std::string sNum1, sNum2;
   std::cout << sQuestion;
   getline(std::cin, sNum1);
   std::cout<< "Enter number 2: ";
   getline(std::cin, sNum2);
   int nNum1 = std::stoi(sNum1); //stoi convert string to number
   int nNum2 = std::stoi(sNum2);
   
   printf("%d + %d = %d\n", nNum1, nNum2, (nNum1 + nNum2));
   printf("%d - %d = %d\n", nNum1, nNum2, (nNum1 - nNum2));
   printf("%d * %d = %d\n", nNum1, nNum2, (nNum1 * nNum2));
   printf("%d %% %d = %d\n", nNum1, nNum2, (nNum1 % nNum2)); // Modulus
}

/* First exercise: Convert miles to kilometer */
int main(){
    /* convert miles to km
     km = miles * 1.60934
     Enter miles: 5
     5 miles equals 8.0467 kilometers*/
    
    const float convert_factor = 1.60934;
    std::string sMiles;
    std::cout << "Enter miles: ";
    getline(std::cin, sMiles);
    double nMiles = std::stod(sMiles); // convert string to double, stod
    
    printf("%.0f miles equals: %.4f kilometers.", nMiles, nMiles*convert_factor);
    
}
