# ezprompt

A basic terminal app for building LLM prompts. Answer a few questions about your agent and get back a ready-to-use prompt, structured as XML (for Claude) or Markdown (for everyone else).

Two interchangeable implementations are included:

- **PowerShell** (`src/pwsh/prompt.ps1`) — no build step, run it directly.
- **C++** (`src/cpp/`) — a compiled version for when you don't want a PowerShell dependency.

## PowerShell version

Requires PowerShell 5.1+ (Windows PowerShell) or PowerShell 7+ (cross-platform).

```sh
cd src/pwsh
./prompt.ps1
```

## C++ version

Requires a C++23-capable standard library, since the program uses `std::println`. Use GCC 14 or newer on Linux, or Visual Studio 2022 17.10 or newer on Windows.

### Linux, MinGW, or MSYS2 (GNU Make)

```sh
cd src/cpp
make
./ezprompt
```

On Windows with GNU Make, the output is `ezprompt.exe`:

```sh
cd src/cpp
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
cd src\cpp
nmake /f Makefile.msvc
.\ezprompt.exe
```

Clean the Visual Studio build with:

```bat
nmake /f Makefile.msvc clean
```
</content>
