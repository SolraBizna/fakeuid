This is a simple `LD_PRELOAD` shim that replaces the `getuid`, `geteuid`, and `setuid` system calls. `getuid` and `geteuid` return a fake UID set from the environment. `setuid` returns unconditional success without doing anything.

Set the `FAKEUID` environment variable to an integer greater than or equal to 10000, and this will be the uid returned by `getuid`/`geteuid`. Otherwise, they will return 9999. This shim will never return a uid less than 9999.

This is meant specifically for use with NetHack, allowing multiple logical UIDs to be used by the same real user. This would be useful for frontends that provide a user system that is separate from the UNIX user space. Since the shim will never give a UID less than 9999, it could coexist with unshimmed NetHack on a system with fewer than ≈9000 real users.

Assuming NetHack is installed in the sane, usual, setgid manner... if you want this shim to be usable with NetHack only by a specific user:

```sh
# copy the library into place
cp fakeuid.so /usr/lib
# make owned by the user of the frontend, and the group of NetHack
chown nhfrontend:nethack /usr/lib/fakeuid.so
# set permissions: user read+execute, setuid
chmod 04500 /usr/lib/fakeuid.so

# now, when the time comes to run NetHack:
LD_PRELOAD=fakeuid.so FAKEUID=xxxx nethack
```

It has to be installed in `/usr/lib` specifically, not e.g. `/usr/lib/powerpc64-linux-gnu` or `/usr/local/lib`, because of security features of `ld.so`.

# License

This code is public domain. This README is almost five times longer than the code, so it would be silly to do otherwise.
