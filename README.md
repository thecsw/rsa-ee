# RSA-EE

This is a project used as demonstration of RSA and factorization for my diploma work. Everything is written in C.
**DISCLAIMER: ALL CODE IS FOR DEMONSTRATION PURPOSES ONLY. DO NOT USE IT IN THE REAL WORLD TO ENCRYPT, DECRYPT, BRUTE-FORCE, SPY, GET UNAUTHORIZED ACCESS OR USE IT IN ANY OTHER PURPOSES, EXCEPT DEMONSTRATION.**

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

What things you need to install the software and how to install them

You should have GMP from [here](https://gmplib.org/) to be able to compile it. I include short instruction how to do it

```bash
wget https://gmplib.org/download/gmp/gmp-6.1.2.tar.xz
tar xz gmp-6.1.2.tar.xz
cd gmp-6.1.2
./configure
make
sudo make install
```

[GMP](https://gmplib.org/) is a free library for arbitrary precision arithmetic, operating on signed integers, rational numbers, and floating-point numbers. There is no practical limit to the precision except the ones implied by the available memory in the machine GMP runs on. GMP has a rich set of functions, and the functions have a regular interface. 

### Installing

Now after the GMP library has been installed, it's time to compile.

Compilation can be done with gcc and clang C compilers. To do that go to the folder and follow these steps
```bash
cd rsa-ee/src
gcc -O3 rsa.c -lgmp -o rsa
gcc -O3 find_multiples.c -o find_multiples
gcc -O3 factor_with_primes.c -lm -o factor_with_primes
gcc -O3 factor_with_integers.c -o factor_with_integers
```

Please note that we are using full code optimization by compiler so it will go to the moon. Slightly slower compilation speed.

We are linking GMP and math libraries during the compilation. Now all code is compiled and is ready to be used.


## Deployment

There are 4 separate scripts that demonstrate a separate thing.

### rsa.c

This first script shows the work of RSA ancrypting algorithm. [Wikipedia](https://en.wikipedia.org/wiki/RSA_(cryptosystem)) explains how RSA works.

GMP library is needed to work with values that are bigger than 2^32-1 or 2^64-1. It actually doesn't have limit, only depends on the memory size of the computer.

The program requires n, e, and d values to be entered and the message, to simulate the encryption and decryption processess. It works with small primes and bigger ones. For example, imagine we have values

```
p = 11
q = 13
n = p * q = 143
f(n) = (p - 1) * (q - 1) = 120
e = 7
d = 103
```

To use this values the input should look like this

```bash
./rsa 143 7 103 Z
```

Where "Z" letter will be encrypted. After the execution this output will appear

```
Initial settings:
	The n value: 143
	The e value: 7
	The d value: 103

All following data will be shown as hexadecimal values.
It is easier to present in this way than decimal.

RSA keys:
	Public key  :   (0x7, 
			 0x8f)
	Private key :   (0x67, 
			 0x8f)

The results:
	Input text            : Z
	Converted text        : 5a
	Attempt of decrypting : 33
	Encrypted text        : 3
	Decrypted text        : 5a
	Output text           : Z

Thank you for using rsa-ee!
Exiting...

```

Where "Z" is being encrypted into "3" and then back to "Z"

The program can work with bigger values. An example is included in the example folder.

```bash
cat examples/example_input.rsa.c
```

And the output will be

```
./a.out 9516311845790656153499716760847001433441357 65537 5617843187844953170308463622230283376298685 "The cake is a lie."
```

Where a.out is default out file after compilation. Now, run the program with these values:

```
./rsa 9516311845790656153499716760847001433441357 65537 5617843187844953170308463622230283376298685 "The cake is a lie."
```

The output:

```
Initial settings:
	The n value: 9516311845790656153499716760847001433441357
	The e value: 65537
	The d value: 5617843187844953170308463622230283376298685

All following data will be shown as hexadecimal values.
It is easier to present in this way than decimal.

RSA keys:
	Public key  :   (0x10001, 
			 0x6d3ded5264bdacea5cc076e62ae5676c844d)
	Private key :   (0x407d5b79d59107e07e4086752d72897e8abd, 
			 0x6d3ded5264bdacea5cc076e62ae5676c844d)

The results:
	Input text            : The cake is a lie.
	Converted text        : 5468652063616b652069732061206c69652e
	Attempt of decrypting : 639e13dc8bb6d382af7c1480c37476f7e4e2
	Encrypted text        : c�܋�ӂ�|��tv��
	Decrypted text        : 5468652063616b652069732061206c69652e
	Output text           : The cake is a lie.

Thank you for using rsa-ee!
Exiting...
```

Where message "The cake is a lie" is being encrypted and decrypted. These values are bigger than the previous example, but still not secure enough for real world. Real world example is included in examples/example_big_input.rsa.c

Cat it and try it yourself!

### find_multiples.c

Nothing interesting here, a program that takes some integer value and finds multiples. If there are only 2 multiples, so it is a prime!

Example input:

```
$ ./find_multiples 40

Program to find multiples of n

1 is an 1 th multiple of 40
2 is an 2 th multiple of 40
4 is an 3 th multiple of 40
5 is an 4 th multiple of 40
8 is an 5 th multiple of 40
10 is an 6 th multiple of 40
20 is an 7 th multiple of 40
40 is an 8 th multiple of 40

There are 8 multiples of 40

Execution time in seconds : 0.000329
```

### factor_with_integers.c

Factorization problem is a problem where the task is to find p and q of n, where n = p * q.

This script is a full brute-force, meaning that it will just take integers and guess one by one.

An example from rsa.c. Let's take 143 to find 11 and 13.

```
$ ./factor_with_integers 143
Primes for 143 are : 11 and 13

Execution time in seconds : 0.000495
```

Quite fast, however the performance is O(n^2). If we use value 3737 that is 37*101

```
$ ./factor_with_integers 3737
Primes for 3737 are : 37 and 101

Execution time in seconds : 0.175458
```

It starts taking time.

### factor_with_primes.c

Because full brute-force of integers is slow, this script uses brute-force too, but it brute-forces only through prime numbers, so it is significantly faster. Because the script can work with large values, it will ask you to make a performance test to make a time estimation, of how long would it take to factorize the input.

Same example with 3737

```
$ ./factor_with_primes 3737

This is a program to factorize input n.
If you receive Segmentation error when executing, it means that you don't have enough RAM capacity to hold prime numbers

Before starting the factorization, the system performance test shoukd be performed.
It is necessary for accurate approximations of runtime.
However if you don't want to run the performance test, it's up to you. Run it? (Y/n) Y
Starting the performance test...
Finished successfully.
Operations per second for your computer : 315582053.

Expectations: 
	Approximation : 
		In worst-case scenario, it will take 0.000654 seconds or 0 day(s)
	In reality : 
		In worst-case scenario, it will take 0.000863 seconds or 0 day(s)

Primes are : 37 and 101

The results and additional data :
	Number of primes generated to factorize 3737 : 522
	Prime index of p (37) : 12
	Prime index of q (101) : 26

Execution time in seconds : 0.000426
```

It is significantly faster. You can use it.

## Source code

Code is not difficult. I have optimized it the best I could. Code is heavily commented, so shouldn't be a problem understanding it.

## Built With

* [GMP](https://gmp.org) - C and C++ library to work with numbers with arbitrary precision.

## Authors

* **Sagindyk Urazayev** - *Initial work* - [thecsw](https://github.com/thecsw)

## License

This project is licensed under the The GNU General Public License - see the [LICENSE.md](https://github.com/thecsw/rjokes/blob/master/LICENSE) file for details