#include<bits/stdc++.h>
using namespace std;
string key = "PLAYFIREXMBCDGHKNOQSTUVZ";
vector<string> table = {"PLAYF", "IREXM", "BCDGH", "KNOQS", "TUVZ"}; // 5x5

string playfairEncrypt(string text) {
    string cipher="";
    // For simplicity, assume text is already uppercase, no spaces, and even length.
    // Prepare plaintext pairs (add X if needed)
    for (int i = 0; i < text.size(); i += 2) {
        char a = text[i], b = text[i+1];
        //picking of characters: [block of 2]: [HE]
        int r1, c1, r2, c2;
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                //have to run in the grid/table:
                if (table[r][c] == a) { r1 = r; c1 = c; }
                if (table[r][c] == b) { r2 = r; c2 = c; }
            }
        }
        if (r1 == r2) {
            cipher+=table[r1][(c1+1)%5];
            cipher+=table[r2][(c2+1)%5];
        }else if(c1==c2){
            cipher+=table[(r1+1)%5][c1];
            cipher+=table[(r2+1)%5][c2];
        }else{
            cipher+=table[r1][c2];
            cipher+=table[r2][c1];
        }
    }
    return cipher;
}
int main(){
    string plaintext = "HELXLOWORLDX"; // example (X used as filler, assume processed)
    cout << "Plaintext pairs: HE LX LO WO RL DX" << endl;
    string enc = playfairEncrypt(plaintext);
    cout << "Encrypted: " << enc << endl;
    return 0;
}