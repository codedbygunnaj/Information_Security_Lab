#include<bits/stdc++.h>
using namespace std;
string caesarEncrypt(string plaintext,int key){
    string cipher="";
    for(char &ch: plaintext){
        if(isalpha(ch)){
            char base=isupper(ch) ? 'A':'a';
            char encry=char(int(base+(ch-base+key)%26));
            cipher+=encry;
        }else{
            cipher+=ch;
        }
    }
    return cipher;
}

int main(){
    string cypher=caesarEncrypt("%HellK%",3);
    string plainy=caesarEncrypt(cypher,26-(3%26));
    cout<<cypher<<endl<<plainy;
    return 0;
}