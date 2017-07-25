#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    string kfile="", cipher="";
    if (argc > 1) {
        if (argc > 2 && string(argv[1]) == "-kfile") {
            getline(cin, cipher);
            kfile = string(argv[2]);
            cout << kfile << "\n";
            //ifstream kfile_stream(kfile, ios::binary);
            ifstream kfile_stream(kfile);
            while (kfile_stream)
                cout << char(kfile_stream.get());
            cout << "\n";
            cout << "\nCipher: " << cipher << "\n";
        }
    }

}