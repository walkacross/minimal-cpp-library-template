# minimal-cpp-library-template
minimal cpp library template

# how to run

## Configure
~~~
cmake -S . -B build \
    -DCMAKE_BUILD_TYPE=Release \
    --install-prefix ~/.local
~~~
## Build
~~~
cmake --build build --parallel
~~~

## Install to prefix (for verification)
~~~
cmake --install build
~~~

## Package into .tar.gz distribution

Generated file: build/libminimal-0.0.2-Linux-x86_64.tar.gz
~~~
cmake --build build --target package
~~~