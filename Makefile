CC=clang
CFLAGS=-ggdb3 -Wall -Wno-deprecated-declarations
LDFLAGS=-framework CoreFoundation -framework Security -framework Carbon -lcrypto
OBJECTS=./debug.o \
	./keychain_pkcs11.o \
	./preferences.o \
	./support_funcs.o

all: keychain_pkcs11.dylib dump_info pkcs11_test

dump_info: 	./dump_info.o ./debug.o
	$(CC) $(CFLAGS) -o $@ ./dump_info.o ./debug.o


pkcs11_test: ./pkcs11_test.o ./debug.o
	$(CC) $(CFLAGS) -o $@ $< ./debug.o

keychain_pkcs11.dylib: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -dynamiclib -o $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
