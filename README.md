# memtest

This is a simply utility which allocates as much megabytes of RAM as requested, pausing 0 or more seconds during allocation. It was designed to verify the progression of memory allocation on Linux environments under cgroups constraints for memory usage.

## Building

The following dependencies are required to build the software: gcc, automake, and [valgrind](http://valgrind.org/) for the small test suite.

* `make all` to build, test, and prepare the program for release.
* `make check` to build and test the program.
* `make memtest` to just build the program.
* `make clean` to clean the entire workspace.


## Usage

The program accepts two arguments:

* -m: memory size in MB, required.
* -s: number of seconds to wait between allocations, optional.

## Sample run

```ShellSession
./memtest -m 12
Memory allocation test up to 12 MB, sleeping 0 seconds between allocations
Total allocation 0 MB...success!
Total allocation 1 MB...success!
Total allocation 2 MB...success!
Total allocation 3 MB...success!
Total allocation 4 MB...success!
Total allocation 5 MB...success!
Total allocation 6 MB...success!
Total allocation 7 MB...success!
Total allocation 8 MB...success!
Total allocation 9 MB...success!
Total allocation 10 MB...success!
Total allocation 11 MB...success!
Successfully allocated 12 MB
```

## License

MIT License