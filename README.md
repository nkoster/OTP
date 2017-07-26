Very simple [one-time pad](https://en.wikipedia.org/wiki/One-time_pad) implementation in C++.

Youtube video: https://www.youtube.com/watch?v=FlIG3TvQCBQ

Limited in size when decrypting ("-d"), because of this
[copy/paste issue](https://stackoverflow.com/questions/22886167/read-a-string-of-length-greater-than-4096-bytes-from-stdin-in-c).
For instance, on my Linux laptop, this issue will become problametic when the copy/paste contains more than 4092 bytes, using a combination of Terminator and Bash.

### Compile

````
g++ -O -Wall -std=c++11 otp.cpp -o otp
````

### Usage:

#### encrypt

````
echo 'My secret' | ./otp
````

Convert complex text or binary data to base64, first:

````
ls -l | base64 | ./otp
````

#### Decrypt

````
./otp -d
````

(limited, see above!)

#### Decrypt a file

Use stdin for the cipher and read the key from a file:

````
cat cipher.txt | ./otp -d -kfile key.txt\n"
````

Don NOT forget to [shredd](https://en.wikipedia.org/wiki/Shred_(Unix)) the key file!

#### To do
Automated key shredding when decrypting might be an interesting feature as well.
