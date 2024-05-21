# kv_skeleton
Just a simple and ineffective kv-store based on linked-list, only for API &amp; libs usage example.

For educational purposes.

# build

- build
```
make
```
- build for test in local directory
```
make libdir=$PWD
```
- enable debug messages
```
make DEBUG=1
```
- build for local test with debug messages
```
make libdir=$PWD DEBUG=1
```
- cleanup
```
make clean
```
- install
```
sudo make install
```
- uninstall
```
sudo make distclean
```

# test
## test example for kv-store
```
make libdir=$PWD DEBUG=1 teststore
./teststore
valgrind --track-origins=yes ./teststore
```
## interactive test for libcomm
```
make libdir=$PWD DEBUG=1 server
./server
cat /etc/services | ./server
cat /etc/services | valgrind --track-origins=yes ./server
```
