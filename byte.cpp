#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    const int modulus = 92;
    const int start = 33;
    string key="", key_buf="", kfile="", cipher="", cipher_buf="", plain="";
    int c, k, m;
    if (argc > 1) {
        if (argc > 2 && string(argv[1]) == "-kfile") {
            while (getline(cin, cipher_buf))
                cipher += cipher_buf;
            kfile = string(argv[2]);
            cout << "\nReading key from " << kfile << "\n\n";
            ifstream kfile_stream(kfile);
            //while (kfile_stream)
            //    key += char(kfile_stream.get());
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
            cout
                << "\nKey:\n" << key << "\n"
                << "\nCipher:\n" << cipher << "\n"
                << "\nPlain:\n" << plain << "\n";
        }
    }
}