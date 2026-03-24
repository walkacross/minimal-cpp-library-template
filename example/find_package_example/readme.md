# two ways to use the libminimal in your own project

## method 1: compile from the source and then find_package

* step 1: compile the libminimal library from the source

~~~
git clone https://github.com/walkacross/minimal-cpp-library-template.git

cd minimal-cpp-library-template

cmake -B build \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_PREFIX_PATH=~/.local

cmake --build build --parallel

cmake --install build    
~~~

* step 2: build your own project

~~~
cd <find_packge_example>

cmake -B build \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_PREFIX_PATH=~/.local

# compile
cmake --build build --parallel

# validate
./build/consumer_app
~~~

## method 2: use the libminial library package

* step 1: get the package,e.g. libminimal-0.0.2-Linux-x86_64.tar.gz
* step 2:
~~~
tar -xzf libminimal-0.0.2-Linux-x86_64.tar.gz -C ~/sdk/
~~~
* step 3:
~~~
cd <find_packge_example>

cmake -B build -DCMAKE_PREFIX_PATH=~/sdk/libminimal-0.0.2-Linux-x86_64
cmake --build build --parallel

./build/consumer_app
~~~