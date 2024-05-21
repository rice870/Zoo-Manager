#include <fstream> 
#include <iostream> 
#include <string> 
#include <vector>
using namespace std; 

int main(){
    ifstream inputFile("Names.txt");
    vector<string> names;
    string line;
    while (getline(inputFile, line)) {
        names.push_back(line);
    }
    cout << names[249];
}