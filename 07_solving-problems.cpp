#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <cmath>
#include <ctime>

std::string CaesarCipher(std::string theString, int move, bool encrypt);
std::vector<std::string> StringToVector(std::string theString, char separator);
std::vector<int> GetPrimes(int maxPrime);
std::vector<int> Range(int start, int max, int step);
std::vector<int> GenerateRandVec(int numOfNums, int min, int max);
void SolveForX(std::string equation);
bool IsPrime(int num);

int main(){
    // Cipher
    std::string theString = "Make me secret";
    std::string encryptedStr = CaesarCipher(theString, 5, true);
    std::string decryptedStr = CaesarCipher(encryptedStr, 5, false);
    std::cout << "Encrypted " << encryptedStr << "\n";
    std::cout << "Decrypted " << decryptedStr << "\n";
    
   // Solve for x
    std::cout << "enter an equation to solve ";
    std::string equation = "";
    getline(std::cin, equation);
    SolveForX(equation);
    
    // Check if the number is prime value
    int num = 0;
    std::cout << "Number to Check : ";
    std::cin >> num;
    
    std::cout.setf(std::ios::boolalpha);
    std::cout << "Is " << num << " Prime " << IsPrime(num) << "\n";
    std::cout << "Generate Primes up to ";
    int maxPrime;
    std::cin >> maxPrime;
    std::vector<int> primeList = GetPrimes(maxPrime);
    for(auto x: primeList) 
        std::cout << x << "\n";
    
    // Generate random vector
    std::vector<int> vecVals = GenerateRandVec(10,5,50);
    for(auto x: vecVals)
        std::cout << x << "\n";
    
    return 0;
    
}

// Functions
std::string CaesarCipher(std::string theString, int move, bool encrypt){
    std::string outputString = "";
    // Check if encrypting or decrypting
    if(!encrypt) move = move * -1;
    // Loop through the string characters
    for(auto c: theString){
        char newChar;
        if(isalpha(c)){
            int charCode = c;
            charCode += move;
            
            // Check upper and lower limit
            if(isupper(c)){
                if(charCode > (int)'Z') charCode -= 26;
                else if (charCode < (int)'A') charCode += 26;
            }else{
                if(charCode > (int)'z') charCode -= 26;
                else if (charCode < (int)'a') charCode += 26;
            }
            // Convert to character
            newChar = charCode;
        } else {
            newChar = c;
        }
        outputString += newChar;
    }
    return outputString;
}

void SolveForX(std::string equation){
    std::vector<std::string> vecsEquation = StringToVector(equation, ' ');
    // Equation x + num1 = num2
    int x = 0;
    int num1 = std::stoi(vecsEquation[2]);
    int num2 = std::stoi(vecsEquation[4]);
    
    x = num2 - num1;
    std::cout << "x = " << x << "\n"; 
}

std::vector<std::string> StringToVector(std::string theString, char separator){
    std::vector<std::string> vecsWords;
    
    std::stringstream ss(theString);
    std::string sIndivStr;
    while(getline(ss, sIndivStr, separator)){
        vecsWords.push_back(sIndivStr);
    }
    
    return vecsWords;
}
std::vector<int> Range(int start, int max, int step){
    std::vector<int> vecRange;
    for(int i=start; i<=max; i += step){
        vecRange.push_back(i);
    }
    return vecRange;
}

bool IsPrime(int num){
    float numSquare = std::sqrt(num);
    int checkPrime = std::floor(numSquare);
    std::vector<int> testRange = Range(2, checkPrime, 1);
    
    for(int a: testRange){
        if((num%a) == 0){
            return false;
        }
    }
    return true;
}

std::vector<int> GetPrimes(int maxPrime){
    std::vector<int> primeList;
    if(maxPrime > 1){
        std::vector<int> testRange = Range(2, maxPrime, 1);
        for(int n: testRange){
            if(IsPrime(n)) primeList.push_back(n);
        }
    }
    return primeList;
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

