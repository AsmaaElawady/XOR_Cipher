#include <iostream>
#include<cmath>
#include <iterator>
#include<string>
using std::cout; using std::endl;
using std::string; using std::hex;
using std::stringstream;

using namespace std;
int main();
string hexa;
string hexa_to;
string msg;
int n;
string text;
char letter;
string enctext = "";
void xorencryption() {
    cout << "please enter text you want to encrypt: ";      //the user chooses that he wants to do encryption
    cin.ignore();
    getline(cin, text);
    cout << "please enter the key letter: ";             //the user chooses  letter which he wants to do encryption
    cin >> letter;
    for (int i = 0;i < text.length();++i) {

        text[i] = text[i] ^ letter;         //make an xor between the letter and text
        enctext += text[i];                 //after makes xor between each letter in the word with the letter he will enter ,he brings them together

    }
    cout << enctext << endl;
    cout << "hexval: ";
    for (const auto& item : enctext) {                //loop on each element in the word and convert it to hexa 
        cout << hex << int(item);
    }
    cout << endl;
}

void xordecryption() {
    cout << "please enter text you want to dcrypt: ";  //the user chooses that he wants to do decryption
    cin.ignore();
    getline(cin, hexa);                  //enter hexa 
    cout << "please enter letter: ";    //the user chooses  letter which he wants to do encryption
    cin >> letter;
    string hexa_to = "";
    for (int i = 0; i < hexa.length() - 1; i += 2) {     ////loop on each element in the hexa and convert it to encyrpt 
        string output = hexa.substr(i, 2);
        int decimal = strtol(output.c_str(), NULL, 16);
        hexa_to += (char)decimal;
    }

    for (int i = 0;i < hexa_to.length();++i) {

        enctext += hexa_to[i] ^ letter;    //make an xor between the letter and hexa
    }
    cout << enctext << endl;
}
int main() {
    cout << "please enter the process you want:\n 1.encrypt a message\n 2.decrypt a message\n 3.end \n";      //choose what do you want
    cout << "1,2 or 3:";
    cin >> n;
    switch (n) {
        case 1: xorencryption();
            break;
        case 2: xordecryption();
            break;
        case 3: cout << "thank you for using this program ";
            break;
        default:cout << "this input is invalid please try again";
    }
}