#include <iostream>
#include <cstdint>
#include <string>

using std::cout, std::cin, std::endl, std::string;

void PrintTable(uint32_t* table, uint32_t row, uint32_t col) {
    for (uint32_t i = 0; i <= row; i++) {
        for (uint32_t j = 0; j <= col; j++) {
            printf("%02u ", table[j+i*(col+1)]);
        }
        printf("\n");
    }
}

uint32_t* GenLcsTable(string str1, string str2) {
    uint32_t row = str1.length();
    uint32_t col = str2.length();

    uint32_t* table = new uint32_t[(row+1)*(col+1)];
    for (uint32_t i = 0; i <= col; i++)
        table[i] = 0;

    for (uint32_t i = 0; i <= row; i++) 
        table[i*(col+1)] = 0;
    
    for (uint32_t i = 1 ; i <= row; i++) {
        for (uint32_t j = 1; j <= col; j++) {
            if (str1[i-1] == str2[j-1])
                table[j+i*(col+1)] = table[(j-1)+(i-1)*(col+1)] + 1;
            else if (str1[i-1] != str2[j-1])
                if (table[j+(i-1)*(col+1)] > table[(j-1)+i*(col+1)])
                    table[j+i*(col+1)] = table[j+(i-1)*(col+1)];
                else
                    table[j+i*(col+1)] = table[(j-1)+i*(col+1)];
        }
    }
    return table;
}

string BackTrackingLCS(uint32_t* table, string str1, string str2) {
    uint32_t table_row = str1.length() + 1;
    uint32_t table_col = str2.length() + 1;
    uint32_t val = table[(table_row)*(table_col)-1];
    string lcs = string("0", val);
    uint32_t tmp_row = table_row, tmp_col = table_col;
    uint32_t i = val-1;
    while (val != 0) {
        if (table[(tmp_row-1)*table_col+tmp_col-1] == val) {
            tmp_row--;
        }
        else if (table[(tmp_row-1)*table_col+(tmp_col-1)-1] == val) {
            tmp_col--;
        }
        else {
            val = table[(tmp_row-1)*table_col+(tmp_col-1)-1];
            lcs[i--] = str1[tmp_row-1];
            tmp_row--;
            tmp_col--;
        }
    }
    return lcs;
}

int main() {
    string str1, str2;
    cout << "Input First String : ";
    getline(cin, str1);
    cout << "Input Second String : ";
    getline(cin, str2);
    uint32_t row = str1.length();
    uint32_t col = str2.length();
    uint32_t* table = GenLcsTable(str1, str2);

    PrintTable(table, str1.length(), str2.length());
    cout << "LCS Length : " <<  table[(row+1)*(col+1)-1] << endl;
    string lcs = BackTrackingLCS(table, str1, str2);
    cout << "LCS String : " << lcs << endl;
}