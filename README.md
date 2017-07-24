Very simple [one-time pad](https://en.wikipedia.org/wiki/One-time_pad) implementation in C++.

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

Limited, because of by [copy-paste](https://stackoverflow.com/questions/22886167/read-a-string-of-length-greater-than-4096-bytes-from-stdin-in-c).
Otherwise, cipher and/or key material goes to disk, which is likely unwanted. To do: make writing to files posible, altough it's unsave.