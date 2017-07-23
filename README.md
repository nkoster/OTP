[One-time pad](https://en.wikipedia.org/wiki/One-time_pad) implementation in C++.

Compile:

````
g++ -O -Wall -std=c++11 otp.cpp -o otp
````

### Usage:

#### encrypt

`echo 'My secret' | ./otp`
#### decrypt

`./otp -d`

Convert complex text or binary data to base64, first:

#### encrypt

`ls -l | base64 | ./otp`
