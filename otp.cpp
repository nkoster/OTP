#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdio>

using namespace std;

int main(int argc, char** argv) {
    const int modulus = 92;
    const int start = 33;
    int c, k, m;
    char k_char;
    string key="", key_buf="", kfile="", cipher="", cipher_buf="", plain="", text="";
    string cipher_file_name="/tmp/cipher.otp", key_file_name="/tmp/key.otp";
    if ((argc == 1) || (argc == 2 && string(argv[1]) == "-w")) {
        srand(time(0));
        while (getline(cin, plain)) {
            for (int i = 0; i < int(plain.length()); i++) {
                text += plain[i];
                k_char = char(start + (rand() % modulus));
                key += k_char;
                cipher += char((((int(k_char) - start) + (int(plain[i]) - start)) % modulus) + start);
            }
        }
        if (argc == 2 && string(argv[1]) == "-w") {
            cout
                << "\nWriting cipher to " << cipher_file_name << "\n"
                << "   Writing key to " << key_file_name << "\n\n";
            ofstream cipher_file;
            cipher_file.open(cipher_file_name);
            cipher_file << cipher;
            cipher_file.close();
            ofstream key_file;
            key_file.open(key_file_name);
            key_file << key;
            key_file.close();
            return 0;
        } else {
            cout << "\nText:\n" << text << "\n\n";
            cout << "Key:\n" << key << "\n\n";
            cout << "Cipher:\n" << cipher << "\n\n";
            return 0;
        }
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
        cout << "\n\n" << plain << "\n\n";
        return 0;
    } else {
        cout 
            << "\nSimple one-time pad, for the paranoids! (niels@w3b.net)\n\n"
            << "   encrypt:   echo 'My secret' | ./otp\n"
            << "   decrypt:   ./otp -d\n\n"
            << "Convert complex text or binary data to base64, first:\n\n"
            << "   encrypt:   ls -l | base64 | ./otp\n\n"
            << "Please be aware of the limitations when decrypting by copy/paste!\n"
            << "https://gitlab.com/nkoster/otp/blob/master/README.md\n\n"
            << "Decrypt from stdin and a key file:\n\n"
            << "   decrypt:   cat cipher.txt | ./otp -d -kfile key.txt\n"
            << "              (Don't forget to shred the key file!)\n\n";
        return 0;
    }
}