This is a simple `LD_PRELOAD` shim that replaces the `getuid`, `geteuid`, and `setuid` system calls. `getuid` and `geteuid` return a fake UID set from the environment. `setuid` returns unconditional success without doing anything.

Set the `FAKEUID` environment variable to an integer greater than or equal to 10000, and this will be the uid returned by `getuid`/`geteuid`. Otherwise, they will return 9999. This shim will never return a uid less than 9999.

This is meant specifically for use with NetHack, allowing multiple logical UIDs to be used by the same real user. This would be useful for frontends that provide a user system that is separate from the UNIX user space. Since the shim will never give a UID less than 9999, it could coexist with unshimmed NetHack on a system with fewer than ≈9000 real users.

# License

This code is public domain. This README is nearly three times longer than the code, so it would be silly to do otherwise.
