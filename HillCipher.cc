#include <iostream>
#include <vector>
using namespace std;
int key[2][2]={{3,3},{2,5}};
string plain="HI";

vector<int> encryptHill(vector<int> block) {
    vector<int> enc(2, 0);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            enc[i]+=key[i][j]*block[j];
        } 
        enc[i] %= 26;
    }
    return enc;
}
int main(){
    vector<int> block(2);
    block[0] = plain[0] - 'A'; // H=7
    block[1] = plain[1] - 'A'; // I=8

    // Encrypt
    vector<int> cipherNums = encryptHill(block);
    cout << "Plaintext: " << plain << endl;
    cout << "Ciphertext: ";
    for(int val : cipherNums) {
        cout << char(val + 'A');
    }
    cout << endl;
    return 0;
}


/*
Solving for 3x3 matrix:

#include <iostream>
#include <vector>
using namespace std;

// 3x3 key matrix (must be invertible mod 26)
int key[3][3] = {
    {6, 24, 1},
    {13, 16, 10},
    {20, 17, 15}
};

string plain = "CAT"; // Must be 3 letters

vector<int> encryptHill3(vector<int> block) {
    vector<int> enc(3, 0);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            enc[i] += key[i][j] * block[j];
        }
        enc[i] %= 26;
    }
    return enc;
}

int main() {
    // Convert plaintext to numbers
    vector<int> block(3);
    for(int i = 0; i < 3; i++) {
        block[i] = plain[i] - 'A';
    }

    // Encrypt
    vector<int> cipherNums = encryptHill3(block);
    cout << "Plaintext: " << plain << endl;
    cout << "Ciphertext: ";
    for(int val : cipherNums) {
        cout << char(val + 'A');
    }
    cout << endl;
    return 0;
}

*/
