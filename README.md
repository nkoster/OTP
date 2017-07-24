Very simple [one-time pad](https://en.wikipedia.org/wiki/One-time_pad) implementation in C++.

Youtube video: https://www.youtube.com/watch?v=FlIG3TvQCBQ

Limited in size when decrypting ("-d"), because of this:
[copy-paste issue](https://stackoverflow.com/questions/22886167/read-a-string-of-length-greater-than-4096-bytes-from-stdin-in-c).
In Linux, this issue will become problametic when the copy-paste contains more than 4092 bytes, in SSH/TTY/bash.

To do: make processing more bytes than the copy-paste limit (thus writing cipher and key to files) possible with the "-d" option, altough that's unsave:
the key goes to disk, which is likely unwanted, or, at least needs extra attention in shredding the key.

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

#### decrypt

````
./otp -d
````

(limited, see above!)
