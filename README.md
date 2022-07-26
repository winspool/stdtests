
# Testsuite to check a C / C++ Compiler and the standard runtime

Most Compilers and the related standard libraries provide some tests, 
but they are not usable for other implementations and can not check for conformance.

## Goals for std_tests
* A reusable license
* Needs only a Compiler, a shell and a make tool
* Support modern C: 
  * C2x / C23
  * C17
  * C11
* Support classic C:
  * C99
  * C89/C90 / ANSI C

* Support modern C++: 
  * C++20 / C++23
  * C++17
  * C++14
  * C++11
* Support classic C++: 
  * C++03
  * C++98

* Create a nice Table from multiple Results

* Use available Conformance tables as template
  * Examples
    * cppreference.com [C99 Implementation status](https://en.cppreference.com/w/c/99)
    * cppreference.com [C++ Implementation status](https://en.cppreference.com/w/cpp/compiler_support)
    * clang [C++ Support in Clang](https://clang.llvm.org/cxx_status.html)

## Reference Documentation
* C 
  * [ISO SC22/WG14 document list](https://www.open-std.org/jtc1/sc22/wg14/www/documents)
  * [ISO SC22/WG14 document log](https://www.open-std.org/jtc1/sc22/wg14/www/wg14_document_log.htm)
 
 |std|__STDC_VERSION__|Latest Draft|Release|
 |---|---|---|---|
 | C2x | N/A yet| [N2912](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2912.pdf) | N/A |
 | C17 | 201710 | [N2176](https://web.archive.org/web/20181230041359if_/http://www.open-std.org/jtc1/sc22/wg14/www/abq/c17_updated_proposed_fdis.pdf) | [ISO/IEC 9899:2018](https://www.iso.org/standard/74528.html) |
 | C11 | 201112 | [N1570](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf) | [ISO/IEC 9899:2011](https://www.iso.org/standard/57853.html) |
 | C99 | 199901 | [N1256](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf) | [ISO/IEC 9899:1999](https://www.iso.org/standard/29237.html) |
 | C95 | 199409 | Missing | ISO/IEC 9899:1990/AMD1:1995 |
 | C90 | not defined | Missing | [ISO/IEC 9899:1999](https://www.iso.org/standard/17782.html) |
 | C89 | not defined | Missing | ANSI X3.159-1989 |

* C++
  * [ISOCPP SC22/WG21 C++ standards commitee](https://www.open-std.org/jtc1/sc22/wg21/)

 |std|__cplusplus|Latest Draft|Release|
 |---|---|---|---|
 |C++23|not yet| missing | N/A|
 |C++20|202002 |[N4849](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/n4849.pdf)|[ISO/IEC 14882:2020](https://www.iso.org/standard/79358.html)|
 |C++17|201703 |[N4659](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/n4659.pdf)|[ISO/IEC 14882:2017](https://www.iso.org/standard/68564.html)|
 |C++14|201402 |[N3797](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3797.pdf)|[ISO/IEC 14882:2014](https://www.iso.org/standard/64029.html)|
 |C++11|201103 |[N3242](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2011/n3242.pdf)|[ISO/IEC 14882:2011](https://www.iso.org/standard/50372.html)|
 |C++03|200300 | N1316 |[ISO/IEC 14882:2003](https://www.iso.org/standard/38110.html)|
 |C++98|199711 |Missing|[ISO/IEC 14882:1998](https://www.iso.org/standard/25845.html)|


 ## Releases
 * Not yet
