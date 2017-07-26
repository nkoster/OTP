#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    const int modulus = 92;
    const int start = 33;
    int c, k, m;
    char k_char;
    string key="", key_buf="", kfile="", cipher="", cipher_buf="", plain="", text="";
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
    } else if (argc == 2 && string(argv[1]) == "-d") {
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
    } else if (argc > 3 && string(argv[1]) == "-d" && string(argv[2]) == "-kfile") {
        while (getline(cin, cipher_buf))
            cipher += cipher_buf;
        kfile = string(argv[3]);
        cout << "\nReading key from " << kfile << "\n\n";
        ifstream kfile_stream(kfile);
        while (getline(kfile_stream, key_buf))
            key += key_buf;
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
            << "   encrypt:   ls -l | base64 | ./otp\n\n"
            << "Please be aware of the limitations when decrypting by copy/paste)\n"
            << "https://gitlab.com/nkoster/otp/blob/master/README.md\n\n"
            << "Decrypt from stdin and a key file:\n\n"
            << "   decrypt:   cat cipher.txt | ./otp -d -kfile key.txt\n"
            << "              (Don't forget to shred the key file!)\n\n";
        return 0;
    }
}