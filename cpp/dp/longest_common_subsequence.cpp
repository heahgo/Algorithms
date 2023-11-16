#include <iostream>
#include <cstdint>

using std::cout, std::cin, std::endl;
using std::string;

uint32_t LCS(string str1, string str2) {
    uint32_t row = str1.length();
    uint32_t col = str2.length();
    uint32_t* table = new uint32_t[(row+1)*(col+1)];
    for (uint32_t i = 0; i <= row; i++)
        table[0+i*col] = 0;
    for (uint32_t i = 0; i <= col; i++) 
        table[i] = 0;
    for (uint32_t i = 0; i <= row*col; i++) {

    }

}

int main() {

    string str1, str2;
    cout << "Input First String : ";
    cin >> str1;
    cout << "Input Second String : ";
    cin >> str2;


    
}