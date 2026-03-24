# minimal-cpp-library-template
minimal cpp library template



# how to run

# ① Clean
rm -rf build

# ② Configure
cmake -S . -B build \
    -DCMAKE_BUILD_TYPE=Release \
    --install-prefix ~/.local

# ③ Build
cmake --build build --parallel

# ④ Install to prefix (for verification)
cmake --install build

# ⑤ Package into .tar.gz distribution
# Generated file: build/libminimal-0.0.2-Linux-x86_64.tar.gz
cmake --build build --target package