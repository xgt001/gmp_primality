GMP implementation of AKS primality testing algorithm using C++

Implemented strictly according to GMP standards. 

Code is under active development, but you can use it just fine.

Needs :

GMP Library greater than v5

If you are using ubuntu based distros, just do

sudo apt-get install libgmp3-dev

Alternatively you can download and setup GMP from the source site.


Running the code

Just run :

./aksgmp
Insert a number of any given length to check its primality

To Customise The Code

You can tweak the source and compile with the following

g++ aks_beta.cpp -o <youroutput> -lgmp -lgmpxx

Bugs to reported : xgt008@gmail.com
