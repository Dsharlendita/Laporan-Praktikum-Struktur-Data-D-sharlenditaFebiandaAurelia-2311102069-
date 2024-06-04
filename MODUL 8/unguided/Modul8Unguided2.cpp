// D'sharlendita Febianda Aurelia
// 2311102069

#include <iostream>
#include <string>

using namespace std;

bool is_vowel(char c) {
    c = tolower(c); 
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int count_vowels(const string& kalimat) {
    int count = 0;
    for (char c : kalimat) {
        if (is_vowel(c)) {
            count++;
        }
    }
    return count;
}

int main() {
    string kalimat;

    cout << "\tMENGHITUNG HURUF VOKAL DALAM KALIMAT" << endl;

    cout << "\nMasukkan sebuah kalimat: ";
    getline(cin, kalimat);

    int vowel_count = count_vowels(kalimat);

    cout << "\nJumlah huruf vokal dalam kalimat: " << vowel_count << endl;

    return EXIT_SUCCESS;
}
