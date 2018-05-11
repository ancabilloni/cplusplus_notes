#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>

// Prototype functions
std::vector<std::string> StringToVector(std::string theString, char separator);
std::string VectorToString(std::vector<std::string> theVector, char separator);
std::string TrimWhiteSpace(std::string theString); //Erase white space first or end
std::vector<int> FindSubstringMatches(std::string phrase, std::string target);
std::string ReplaceSubstring(std::string phrase, std::string target,
        std::string replace);

int main() {
    // Convert string to vector
    std::vector<std::string> vec = StringToVector("This is a random string.", ' ');
    
    for(int i=0; i<vec.size(); ++i){
        std::cout << vec[i] << "\n";
    }
    
    // Convert vector to string
    std::vector<std::string> vCusts(3);
    vCusts[0] = "Bob";
    vCusts[1] = "Sue";
    vCusts[2] = "Tom";
    
    std::string sCusts = VectorToString(vCusts, ' ');
    std::cout << sCusts << "\n";
    
    // Trim whitespace
    std::string aStr = "     Just some random words   ";
    aStr = TrimWhiteSpace(aStr);
    std::cout << "*" << aStr << "\n";
    
    // Find index of all substr
    std::string phrase = "To be or not to be";
    std::vector<int> matches = FindSubstringMatches(phrase, "be");
    for(int i=0; i < matches.size(); ++i){
        std::cout << matches[i] << "\n";
    }
    
    // Replace all substring
    std::string replacePhrase = ReplaceSubstring(phrase,"be", "do");
    std::cout << replacePhrase << "\n";
    return 0;
    
    // ----- 6. CHARACTER FUNCTIONS -----
    char letterZ = 'z';
    char num3 = '3';
    char aSpace = ' ';
    
    std::cout << "Is z a letter or number " << 
            isalnum(letterZ) << "\n";
    std::cout << "Is z a letter " << 
            isalpha(letterZ) << "\n";
    std::cout << "Is z uppercase " << 
            isupper(letterZ) << "\n";
    std::cout << "Is z lowercase " << 
            islower(letterZ) << "\n";
    std::cout << "Is 3 a number " << 
            isdigit(num3) << "\n";
    std::cout << "Is space a space " << 
            isspace(aSpace) << "\n";
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

std::string VectorToString(std::vector<std::string> theVector, char separator){
    std::string words = "";
    for(auto a: theVector){
        words += a + separator;
    }
    return words;
}

std::string TrimWhiteSpace(std::string theString){
    std::string whitespaces(" \t\f\n\r");
    theString.erase(theString.find_last_not_of(whitespaces) + 1);
    theString.erase(0, theString.find_first_not_of(whitespaces));
    return theString;
}

std::vector<int> FindSubstringMatches(std::string phrase, std::string target){
    std::vector<int> matches;
    int len = phrase.length();
    int index = phrase.find(target);
    
    while(index != std::string::npos){
        matches.push_back(index);
        index = phrase.find(target, index + 1);
    }

    return matches;
}

std::string ReplaceSubstring(std::string phrase, std::string target,
        std::string replace){
    std::string newString = "";
    std::vector<int> indexTarget = FindSubstringMatches(phrase, target);
    
    if(indexTarget.size() != 0){
        int selectIndex = 0;
        for(int i: indexTarget){
            newString += phrase.substr(selectIndex, (i - selectIndex)) + replace;
            selectIndex = i + target.length();
        }
    }
    return newString;
}
// or
std::string ReplaceSubstring(std::string phrase, std::string target,
        std::string replace){
    std::vector<int> matches = FindSubstringMatches(phrase, target);
    
    if(matches.size() != 0){
        int lengthDifference = replace.size() - target.size();
        int timesLooped = 0;
        for(auto index: matches){
            phrase.replace(index + (timesLooped * lengthDifference),
                    target.size(),
                    replace);
            timesLooped++;
        }
    }
}
