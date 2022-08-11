
# Testsuite to check a C / C++ Compiler and the standard runtime library

Most Compilers and the related standard libraries provide some tests, 
but they are not easy usable as conformance check for other Compiler or Runtime library implementations.


## Goals for stdtests
* [ ] A reusable license
* [ ] Need only a Compiler, a posix shell and a make tool

  |Target OS|tested Compiler|
  |:-:|---|
  |Linux| tcc / gcc / g++ / owcc / clang / zig cc / zig c++|
  |Windows| x86_64-win32-tcc / x86_64-w64-mingw32-gcc / x86_64-w64-mingw32-g++|
  
* [ ] Check C Compiler and the C Runtime library (libc) 
  
  |check| C23 | C17 | C11 | C99 | C95 | C89/C90 / ANSI-C|
  |:-:|:-:|:-:|:-:|:-:|:-:|:-:|
  |compiler limits  | :x: | :x: | :x: | :x: | :x: | :x: |
  |compiler features| :x: | :x: | :x: | :x: | :x: | :x: |
  |library header | :heavy_check_mark: 30 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |
  |library features | :x: | :x: | :x: | :x: | :x: | :x: |

* [ ] Check C++ Compiler and the C++ Runtime library (libstdc++) 
  
  |check| C++23 | C++20 | C++17 | C++14 | C++11 | C++03 | C++98 |
  |:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
  |compiler limits  | :x: | :x: | :x: | :x: | :x: | :x: | :x: |
  |compiler features| :x: | :x: | :x: | :x: | :x: | :x: | :x: |
  |library header | :question: 100 | :heavy_check_mark: 100 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |
  |library features | :x: | :x: | :x: | :x: | :x: | :x: | :x: |

* [ ] Create a nice Table from multiple Results, similar as available tables
  * Some Examples:
    - gcc [Status of C99 features in GCC](https://gcc.gnu.org/c99status.html)
    - gcc [C11 Status in GCC](https://gcc.gnu.org/wiki/C11Status)
    - gcc [C++ Standards support in GCC](https://gcc.gnu.org/projects/cxx-status.html#) 
    - clang [C++ Support in Clang](https://clang.llvm.org/cxx_status.html)
    - cppreference.com [C99 Implementation status](https://en.cppreference.com/w/c/99)
    - cppreference.com [C++ Implementation status](https://en.cppreference.com/w/cpp/compiler_support)

***
## C Reference Documentation
  * [ISO SC22/WG14 document list](https://www.open-std.org/jtc1/sc22/wg14/www/documents)
  * [ISO SC22/WG14 document log](https://www.open-std.org/jtc1/sc22/wg14/www/wg14_document_log.htm)
 
 |std|\_\_STDC_VERSION\_\_|Latest Draft|Release|
 |:-:|:-:|:-:|:-:|
 | C2x | N/A yet| [N2912](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2912.pdf) | N/A |
 | C17 | 201710 | [N2176](https://web.archive.org/web/20181230041359if_/http://www.open-std.org/jtc1/sc22/wg14/www/abq/c17_updated_proposed_fdis.pdf) | [ISO/IEC 9899:2018](https://www.iso.org/standard/74528.html) |
 | C11 | 201112 | [N1570](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf) | [ISO/IEC 9899:2011](https://www.iso.org/standard/57853.html) |
 | C99 | 199901 | [N1256](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf) | [ISO/IEC 9899:1999](https://www.iso.org/standard/29237.html) |
 | C95 | 199409 | [c89_na1: c94](https://port70.net/~nsz/c/c89/c94_na1.html) | ISO/IEC 9899:1990/AMD1:1995 |
 | C90 | not defined | Missing | [ISO/IEC 9899:1999](https://www.iso.org/standard/17782.html) |
 | C89 | not defined | [c89 draft](https://port70.net/~nsz/c/c89/c89-draft.html) | ANSI X3.159-1989 |

---
## C++ Reference Documentation
  * [ISOCPP SC22/WG21 C++ standards commitee](https://www.open-std.org/jtc1/sc22/wg21/)

 |std|\_\_cplusplus|Latest Draft|Release|
 |:-:|:-:|:-:|:-:|
 |C++23|not yet| missing | N/A|
 |C++20|202002 |[N4849](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/n4849.pdf)|[ISO/IEC 14882:2020](https://www.iso.org/standard/79358.html)|
 |C++17|201703 |[N4659](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/n4659.pdf)|[ISO/IEC 14882:2017](https://www.iso.org/standard/68564.html)|
 |C++14|201402 |[N3797](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3797.pdf)|[ISO/IEC 14882:2014](https://www.iso.org/standard/64029.html)|
 |C++11|201103 |[N3242](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2011/n3242.pdf)|[ISO/IEC 14882:2011](https://www.iso.org/standard/50372.html)|
 |C++03|200300 | [c++03 final](https://port70.net/~nsz/c/c%2B%2B/c%2B%2B03_final.pdf)|[ISO/IEC 14882:2003](https://www.iso.org/standard/38110.html)|
 |C++98|199711 |[nr. unknown](https://port70.net/~nsz/c/c%2B%2B/c%2B%2B98.pdf)|[ISO/IEC 14882:1998](https://www.iso.org/standard/25845.html)|


***
## Releases
* Not yet
