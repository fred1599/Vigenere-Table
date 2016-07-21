#include <iostream>
#include <string>
#include <vector>

using namespace std;

string createLine(char);
vector<string> createTable(char);
char get_crypt_key(char, char)

int main(){

    vector<string> table = createTable('A');

    for (auto elem: table) {cout << elem << endl;} //C++11

    return 0;
}

string createLine(char start){

    string res;

    if (start >= 'a' && start <= 'z')
        start -= 32;

    for (int i=0; i<26; i++){
        char c = start + i;
        if (c < 'Z') res += c;
        else res += (c-'A')%26 + 'A';
    }

    return res;
}

vector<string> createTable(char start='A'){

    vector<string> v;
    for (int i=0; i<26; i++)
        v.push_back(createLine(start+i));

    return v;
}

char get_crypt_key(char letter_message, char letter_key){

    string column = createLine('A');
    string line = createLine(letter_key);

    size_t pos = column.find_first_of(letter_message, 0);

    return line.at(pos);

}
