Simple [one-time pad](https://en.wikipedia.org/wiki/One-time_pad) CLI implementation in C++.

Youtube video: https://www.youtube.com/watch?v=FlIG3TvQCBQ

Limited in size when decrypting from console ("-d" argument), because of this
[copy/paste issue](https://stackoverflow.com/questions/22886167/read-a-string-of-length-greater-than-4096-bytes-from-stdin-in-c).
For instance, on my Linux laptop, this issue will become problametic when the copy/paste contains more than 4092 bytes, using a combination of Terminator and Bash.

You can decide to encrypt/decrypt from files, but you have to understand the risk increment when doing so:
Do NOT forget to [shred](https://en.wikipedia.org/wiki/Shred_(Unix)) the key file!

### Compile

````
g++ -O -Wall -std=c++11 otp.cpp -o otp
````

### Usage:

### Encrypt

````
echo 'My secret' | ./otp
````

Convert complex text or binary data to base64, first:

````
ls -l | base64 | ./otp
````

Write the cipher and the key to /tmp/otp.cipher and /tmp/otp.key:

````
cat file | base64 | ./otp -w
````

#### Decrypt

````
./otp -d
````

(limited, see above!)

#### Decrypt a file

Use stdin for the cipher and read the key from a file:

````
cat /tmp/otp.cipher | ./otp -d -kfile /tmp/otp.key
````

Do NOT forget to [shred](https://en.wikipedia.org/wiki/Shred_(Unix)) the key file!

#### To do

Automated key shredding when decrypting might be an interesting feature as well.
