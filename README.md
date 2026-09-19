# ezprompt
A basic terminal app for building LLM prompts.

## Build

The program uses `std::println`, so a C++23-capable standard library is required.
Use GCC 14 or newer on Linux, or Visual Studio 2022 17.10 or newer on Windows.

### Linux, MinGW, or MSYS2 (GNU Make)

```sh
make
./ezprompt
```

On Windows with GNU Make, the output is `ezprompt.exe`:

```sh
make
./ezprompt.exe
```

You can select a compiler or add flags without editing the makefile:

```sh
make CXX=g++ CXXFLAGS="-std=c++23 -Wall -Wextra -pedantic"
```

Clean the generated files with:

```sh
make clean
```

### Windows with Visual Studio (NMAKE)

Open a **Developer Command Prompt for VS 2022**, then run:

```bat
nmake /f Makefile.msvc
.\ezprompt.exe
```

Clean the Visual Studio build with:

```bat
nmake /f Makefile.msvc clean
```
