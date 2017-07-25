#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    string key="", kfile="", cipher="", cipher_buf="";
    if (argc > 1) {
        if (argc > 2 && string(argv[1]) == "-kfile") {
            while (getline(cin, cipher_buf))
                cipher += cipher_buf;
            kfile = string(argv[2]);
            cout << "\nReading key from " << kfile << "\n\nKey: ";
            ifstream kfile_stream(kfile);
            while (kfile_stream)
                key += char(kfile_stream.get());
            if (key.length() < cipher.length()) {
                cerr << " Error: Key length cannot be shorter than cipher length.\n";
                return 1;
            }
            cout
                << "\nKey: " << key << "\n"
                << "\nCipher: " << cipher << "\n";
        }
    }

}