[U# QuadSwap C++

![C++11](https://img.shields.io/badge/C%2B%2B-11%2B-blue)
![Dependencies](https://img.shields.io/badge/dependencies-none-brightgreen)

A lightweight C++ command-line program that rearranges characters in **four-character blocks**. The transformation runs **in place**, uses **constant auxiliary space**, and can be reversed by running it a second time.

## How it works

The program reads one line of text and processes it from left to right in groups of up to four characters.

For each complete four-character block, it swaps:

- The **first** character with the **third**.
- The **second** character with the **fourth**.

```text
Before:  A B C D  |  E F G H
After:   C D A B  |  G H E F
```

**Incomplete final blocks** follow the same index rules:

| Characters left | Result | Behavior |
| --- | --- | --- |
| 4 | `ABCD` → `CDAB` | Both pairs are swapped. |
| 3 | `ABC` → `CBA` | First and third are swapped. |
| 2 | `AB` → `AB` | No swap is possible. |
| 1 | `A` → `A` | The character is unchanged. |

Spaces and punctuation count as characters and are processed in exactly the same way.

## Example

```text
Enter the text: ABCDEFGHIJK
CDABGHEFKJI
```

The transformation is **self-inverse**: applying it twice returns the original string.

```text
ABCDEFGHIJK → CDABGHEFKJI → ABCDEFGHIJK
```

## Requirements

- A C++11-compatible compiler (GCC, Clang, or MSVC).
- No third-party dependencies.

## Build and run

### Linux / macOS (GCC or Clang)

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o quad-swap
./quad-swap
```

### Windows (MinGW-w64)

```powershell
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o quad-swap.exe
.\quad-swap.exe
```

### Windows (MSVC Developer Command Prompt)

```bat
cl /EHsc /W4 main.cpp /Fe:quad-swap.exe
quad-swap.exe
```

## Complexity

| Metric | Complexity | Explanation |
| --- | --- | --- |
| Time | **O(n)** | Each block is visited once. |
| Auxiliary space | **O(1)** | Characters are swapped directly inside the input string. |
| Input storage | **O(n)** | The input line itself is stored in a `std::string`. |

Here, `n` is the number of bytes in the input string.

## Limitations

- **UTF-8:** The implementation swaps bytes, not Unicode characters. It is suitable for ASCII text but may break multi-byte characters, including Persian letters and emoji.
- **One line at a time:** `std::getline` reads a single line of input.
- **Not encryption:** This is a deterministic, reversible rearrangement algorithm, **not** a secure cipher.

## Project structure

```text
quad-swap-cpp/
├── main.cpp       # Character-swapping implementation
├── README.md      # Documentation
└── .gitignore     # Generated build-file exclusions
```

## Possible improvements

- Add Unicode-aware character handling.
- Support multiple lines or file input.
- Introduce automated tests for all remainder cases.
ploading README (2).md…]()
