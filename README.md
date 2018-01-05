# RSA-EE

This is a project used as demonstration of RSA and factorization for my diploma work. Everything is written in C.

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
gcc rsa.c -lgmp -o rsa
gcc find_multiples.c -o find_multiples
gcc factor_with_primes.c -lm -o factor_with_primes
gcc factor_with_integers.c -o factor_with_integers
```

We are linking GMP and math libraries during the compilation. Now all code is compiled and is ready to be used.


## Deployment

There are 4 separate scripts that demonstrate a separate thing.

### rsa

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

## Source code

I know that the script is little bit messy, I tried. Simple and small, but it works!

Now, I want to give little insight on the code. If you want to take posts from any other subreddit, in the main source file rjokes.py, change this variable's value to any subrreddit you like

```python
sub = 'Jokes' # Means it will extract posts from reddit.com/r/Jokes
```

Also, this script takes only the best jokes of the last 24 hours and updates them every hour. If you want to change the source of jokes, change this line

```python
hot_python = subreddit.top('day', limit=LIMIT)
```

LIMIT is the amount of posts to extract

Well and also the time interval is in seconds

```python
time.sleep(3600)
```

## Built With

* [telepot](https://github.com/nickoala/telepot) - python framework for Telegram Bot API.
* [praw](https://github.com/praw-dev/praw) - Python Reddit API Wrapper.

## Authors

* **Sagindyk Urazayev** - *Initial work* - [thecsw](https://github.com/thecsw)

## License

This project is licensed under the The GNU General Public License - see the [LICENSE.md](https://github.com/thecsw/rjokes/blob/master/LICENSE) file for details