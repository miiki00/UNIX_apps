# _look

## Description
A program that looks if a file(s) exists in the current working directory.

## Installation
You can use complier of your choic `gcc`/`clang` both works fine.

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _look.c -o _look

```
### Usage:
Navigate to the path (directory) you want to look files in.
```
mv _look /to/the/path/you/need/to/look/files/for/
./_look <file(s)>
```
### Sample outputs.
```
someone@user$ ls
_look  _look.c  README.md  t  te  tes  test
someone@user$ ./_look test tes te t e es est
test : FOUND
tes : FOUND
te : FOUND
t : FOUND
e : NOT FOUND
es : NOT FOUND
est : NOT FOUND
```
NOTE: This is not for production purpose just for training and developing skills
you can adjust the tools in this repository per your own preference.

Thankyou for visiting.
