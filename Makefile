all: fakeuid.so

fakeuid.so: fakeuid.c
	gcc -shared fakeuid.c -o fakeuid.so

clean:
	rm -f fakeuid.so
