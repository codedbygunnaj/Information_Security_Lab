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
