#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    const int modulus = 92;
    const int start = 33;
    int c, k, m;
    char k_char;
    string plain="", text="", key="", cipher="";
    if (argc == 1) {
        srand(time(0));
        while (getline(cin, plain)) {
            for (int i = 0; i < int(plain.length()); i++) {
                text += plain[i];
                k_char = char(start + (rand() % modulus));
                key += k_char;
                cipher += char((((int(k_char) - start) + (int(plain[i]) - start)) % modulus) + start);
            }
        }
        cout << "\nText:\n" << text << "\n\n";
        cout << "Key:\n" << key << "\n\n";
        cout << "Cipher:\n" << cipher << "\n\n";
        return 0;
    } else if (string(argv[1]) == "-d") {
        cout << "\nCipher: ";
        getline(cin, cipher);
        cout << "   Key: ";
        getline(cin, key);
        if (key.length() < cipher.length()) {
            cerr << " Error: Key length cannot be shorter than cipher length.\n";
            return 1;
        }
        for (int i = 0; i < int(cipher.length()); i++) {
            c = int(cipher[i]) - start;
            k = int(key[i]) - start;
            m = (c - k);
            if (m < 0) m += modulus;
            plain += char((m % modulus) + start);
        }
        cout << " Plain: " << plain << "\n\n";
        return 0;
    } else {
        cout 
            << "\nSimple one-time pad, for the paranoids! (niels@w3b.net)\n\n"
            << "   encrypt:   echo 'My secret' | ./otp\n"
            << "   decrypt:   ./otp -d\n\n"
            << "Convert complex text or binary data to base64, first:\n\n"
            << "   encrypt:   ls -l | base64 | ./otp\n\n";
        return 0;
    }
}