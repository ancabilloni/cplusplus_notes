#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <algorithm> // this is for 'reverse'

/* STRING & MATH*/
int main() {
    
    std::vector<std::string> strVec(10);
    
    std::string str("I'm a string");
    
    strVec[0] = str;
    
    std::cout << str.at(0) << "\n";
    std::cout << str.front() << " " << str.back() << "\n";
    std::cout << "Length " << str.length() << "\n";
    std::string str2(str);
    strVec[1] = str2;
    std::string str3(str, 4);
    strVec[2] = str3;
    std::string str4(5, 'x');
    strVec[3] = str4;
    strVec[4] = str.append(" and your not");
    str += " and your not";
    str.append(str, 34, 37);
    strVec[5] = str;
    str.erase(13, str.length() - 1);
    strVec[6] = str;
    
    // Find first index of certain string
    if(str.find("string") != std::string::npos) 
        std::cout << "1st index " << str.find("string") << "\n";
    
    // Access sub string
    std::cout << "Substr " << str.substr(6, 6) << "\n";
    
    // Reverse, need algorithm library
    reverse(str.begin(), str.end());
    std::cout << "Reverse " << str << "\n";
    
    // Convert to upper case
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    std::cout << "Upper: " << str2 << "\n";
    
    // Convert to lower case
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    std::cout << "Lower: " << str2 << "\n";
    
    /*ASCII Code: a - z: 97 - 122, A - Z: 65 - 90*/
    
    char aChar = 'A';
    int aInt = aChar;
    std::cout << "A Code " << (int)'a' << "\n";
    
    // Convert to string
    std::string strNum = std::to_string(1+2);
    std::cout << "String " << strNum << "\n";
    
    /*for(auto y: strVec){
        std::cout << y << "\n";
    }
     * */
    
    char cString[] = {'A', ' ', 'S', 't', 'r',
    'i', 'n', 'g', '\0'};
    
    std::cout << "Array Size " << sizeof(cString) << "\n";

    return 0;
}

int main(){
   
   /* Assignment: receive an upper case letter,
    turn each letter into ASCII code
    a - z: 97 - 122
    A - Z: 65 - 90 */

   std::string input, secretStr = "";
   std::cout << "Enter string: ";
   std::cin >> input;
   
   // Convert to secret message
   for(char a: input){
       secretStr += std::to_string((int)a - 23);
   }
   std::cout << "Secret: " << secretStr <<  "\n";
   
   // Convert back to string
   input = "";
   int secretSize = secretStr.size(); // or secretStr.length()
   
   std::cout << "String size: " << secretSize << "\n";
   for(int i=0; i<secretSize; i=i+2){
       std::string substr = secretStr.substr(i,2);
       std::cout << "Substr: " << substr << "\n";
       int subInt = std::stoi(substr);
//        // Add condition or substract secretStr to 23
//        if(subInt < 65){
//            substr = secretStr.substr(i,3);
//            subInt = std::stoi(substr);
//            i += 1;
//        }
       char subChar = subInt + 23;
       input += subChar;
   }
   std::cout << "Convert Secret: " << input <<  "\n";
   
   return 0;
}

int main(){
   std::cout << "abs(-10) = " << std::abs(-10) << "\n";
   
   std::cout << "max(5,4) = " << std::max(5,4) << "\n";
   
   std::cout << "min(5,4) = " << std::min(5,4) << "\n";
   
   std::cout << "fmax(5.3,4.3) = " << std::fmax(5.3,4.3) << "\n";
   
   std::cout << "fmin(5.3,4.3) = " << std::fmin(5.3,4.3) << "\n";
   
   // e ^ x
   std::cout << "exp(1) = " << std::exp(1) << "\n";
   
   // 2 ^ x
   std::cout << "exp2(1) = " << std::exp2(1) << "\n";
   
   // e * e * e ~= 20 so log(20.079) ~= 3
   std::cout << "log(20.079) = " << std::log(20.079) << "\n";
   
   // 10 * 10 * 10 = 1000, so log10(1000) = 3
   std::cout << "log10(1000) = " << std::log10(1000) 
           << "\n";
   
   // 2 * 2 * 2 = 8
   std::cout << "log2(8) = " << std::log2(8) 
           << "\n";
   
   // 2 ^ 3
   std::cout << "pow(2,3) = " << std::pow(2,3) 
           << "\n";
   
   // Returns what times itself equals the provided value
   std::cout << "sqrt(100) = " << std::sqrt(100) 
           << "\n";
   
   // What cubed equals the provided
   std::cout << "cbrt(1000) = " << std::cbrt(1000) 
           << "\n";
   
   // Hypotenuse : SQRT(A^2 + B^2)
   std::cout << "hypot(2,3) = " << std::hypot(2,3) 
           << "\n";
   
   std::cout << "ceil(10.45) = " << std::ceil(10.45) 
           << "\n";
   
   std::cout << "floor(10.45) = " << std::floor(10.45) 
           << "\n";
   
   std::cout << "round(10.45) = " << std::round(10.45) 
           << "\n";
   
   // Also sin, cos, tan, asin, acos, atan, atan2,
   // sinh, cosh, tanh, asinh, acosh, atanh
   
}
