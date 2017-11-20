## NodeJs-Addon-Example

> Nodejs Addon with Native C/C++ example.

In both cases we use [node-gyp](https://github.com/nodejs/node-gyp) to build from C/C++ code.

In this example, We build a C++ code that determines a very simple prime as an add-on to node.js.

### Confirm the C code

```sh
clang main.cpp prime_number.cpp -o prime_number

./prime_number
Enters number: 4
Is not prime number%

./prime_number
Enters number: 5
Is prime number%
```

### C/C++ Addon with V8

Buildding nodejs native addon C/C++ code.
Compile C/C++ code with [node-gyp](https://github.com/nodejs/node-gyp).

```sh
npm i
#  node-gyp configure
npm run configure
# node-gyp build
npm run build
# test build addon
npt test
# if prime number stdot `true` eles `false`
```

### C/C++ Addon with N-API

[N-API](https://nodejs.org/api/n-api.html)is an ABI stable intermediate layer of the NodeJS API.
Using N-API eliminates the need to build native add on dependent on V8 for each platform or architecture.

```sh
npm i
#  node-gyp configure
npm run configure
# node-gyp build
npm run build
# test build addon
npt test
# if prime number stdot `true` eles `false`
```
