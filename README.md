Very simple [one-time pad](https://en.wikipedia.org/wiki/One-time_pad) implementation in C++.

Youtube video: https://www.youtube.com/watch?v=FlIG3TvQCBQ

Very limited, because of this [copy-paste](https://stackoverflow.com/questions/22886167/read-a-string-of-length-greater-than-4096-bytes-from-stdin-in-c) thing.
In Linux, this issue will be problametic when the copy-paste contains more than 4092 bytes, in SSH/TTY/bash.

To do: make processing more bytes than the copy-paste limit (thus writing cipher and key to files) possible, altough that's unsave:
key material goes to disk, which is likely unwanted, or, at least needs extra attention in shredding the key.

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
