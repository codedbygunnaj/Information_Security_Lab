#include<bits/stdc++.h>
using namespace std;
string key="QWERTYUIOPASDFGHJKLZXCVBNM";

string monoEncrypt(string plaintext) {
    string cipher="";
    for(char ch:plaintext){
        if(isalpha(ch)){
            char base = isupper(ch) ? 'A' : 'a';
            int id=ch-base;
            char enc=key[id];

            if(islower(ch)) enc = tolower(enc);
            cipher+=(enc);
        }else{
            cipher+=ch;
        }
    }
    return cipher;
}
string monoDecrypt(string cipher) {
    string plaintext = "";
    for(char ch:cipher){
        if (isalpha(ch)) {
            bool toLower=islower(ch);
            char c=toupper(ch);
            int id=key.find(c);
            char dec=key[id];
            if(toLower) dec=tolower(dec);
            plaintext+=dec;
        }else{
            plaintext+=ch;
        }
    }
    return plaintext;

}
string plain="helloworld";
int main(){
    cout << "Plaintext: " << plain << endl;
    string enc = monoEncrypt(plain);
    cout << "Encrypted: " << enc << endl;
    string dec = monoDecrypt(enc);
    cout << "Decrypted: " << dec << endl;
    return 0;

}