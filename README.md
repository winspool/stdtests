# Portable Testsuite to check a C / C++ Compiler and standard runtime libraries

Many compiler and the related standard libraries provide tests,
but they are not easy usable as portable/standalone conformance check for other compiler or for other runtime library implementations.


## Goals for stdtests
* [ ] A reusable license
* [ ] Only needs a Compiler and a posix shell to run the testsuite
* [ ] Portable: Works on many systems with many compiler and runtime libraries
* [ ] Check C Compiler and the C Runtime library
* [ ] Check the POSIX Runtime library
* [ ] Check C++ Compiler and the C++ Runtime library
* [ ] Create a nice Table from multiple Results


#### Expected usecase
* Extract the testsuite
* configure the testsuite to test a compiler / runtime library for a given standard
* `make`: run the testsuite and generate a result file
* `make table`: generate a table for multiple results


#### Example usage
 * std: newest
 * Compiler: tcc
 * runtime-library: system-default
~~~
mkdir results
cd results
CC=tcc ../configure --disable-c++
make
~~~
* Now there should be an document with the results of the current test


### Portability
* Current tested environments
  |Target OS|tested Compiler|
  |:-:|---|
  |Linux| tcc / gcc / g++ / owcc / clang / zig cc / zig c++|
  |Windows| x86_64-win32-tcc / x86_64-w64-mingw32-gcc / x86_64-w64-mingw32-g++|

* Hints / Links for later use:
  - With many years delay, a command line switch arrived in [MSVC 2015 Update 3](https://aka.ms/versionswitches) for selecting the c++ version


#### Checking C Compiler and the C Runtime library

  |STD| C2y | C23 | C17 | C11 | C99 | C95 (C90+AMD1) | C89/C90 / ANSI-C|
  |:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|

#### Checking POSIX Runtime library
Currently, POSIX.1-2024 ist referenced. Older versions will follow.


#### Checking C++ Compiler and the C++ Runtime library

  |STD| C++2c | C++23 | C++20 | C++17 | C++14 | C++11 | C++03 | C++98 |
  |:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|


#### Some examples of other tables with Features or Test-Results
 - gcc [Status of C99 features in GCC](https://gcc.gnu.org/c99status.html) / [C11 Status in GCC](https://gcc.gnu.org/wiki/C11Status) / [C++ Standards support in GCC](https://gcc.gnu.org/projects/cxx-status.html#)
 - clang [C Support in clang](https://clang.llvm.org/c_status.html) / [C++ Support in Clang](https://clang.llvm.org/cxx_status.html)
 - msvc [C/C++ Support in MSVC](https://learn.microsoft.com/en-us/cpp/overview/visual-cpp-language-conformance?view=msvc-170)
 - dmc [C++0x language Implementation](https://digitalmars.com/ctg/CPP0x-Language-Implementation.html)
 - owcc [C99 Compliance](https://github.com/open-watcom/open-watcom-v2/wiki/C99-Compliance) / [C++ Language](https://github.com/open-watcom/open-watcom-v2/wiki/C---Language) / [C++ Library](https://github.com/open-watcom/open-watcom-v2/wiki/C---Library) / [C++ Library Status](https://github.com/open-watcom/open-watcom-v2/wiki/C++-Library-Status)
 - cppreference.com [What's new in C99](https://en.cppreference.com/w/c/99) / [C99 Implementation status](https://en.cppreference.com/w/c/compiler_support/99) / [C23 Implementation status](https://en.cppreference.com/w/c/compiler_support/23) / [C++ Implementation status](https://en.cppreference.com/w/cpp/compiler_support)


#### Some links to compiler / library tests

 |Name|URL
 |:-:|:-:|
 |clang|[test top dir](https://github.com/llvm/llvm-project/tree/main/clang/test)|
 |gcc|[test top dir](https://gcc.gnu.org/git/?p=gcc.git;a=tree;f=gcc/testsuite;hb=HEAD)|
 |mcpp|[preprocessor](https://github.com/zeroc-ice/mcpp)|
 |musl|[libc-tests](https://gitlab.com/libc-tests)|
 |glibc|[libc](https://sourceware.org/git/glibc.git)|


***
## C Reference Documentation
  * [ISOC SC22/WG14 C standards commitee](https://www.open-std.org/jtc1/sc22/wg14/)
  * [ISO SC22/WG14 docs](https://www.open-std.org/jtc1/sc22/wg14/www/docs/?C=M;O=D)
  * [ISO SC22/WG14 document log](https://www.open-std.org/jtc1/sc22/wg14/www/wg14_document_log.htm)
  * [C Project status and milestones](https://www.open-std.org/jtc1/sc22/wg14/www/projects.html)
  * C23: Early C2y draft from 02.02.2024 was [N3220](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3220.pdf)
  * C17: Early C23 draft from 11.11.2018 was [N2310](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3220.pdf)

#### Released C Standards

 |std|\_\_STDC_VERSION\_\_|Latest Draft|Release|
 |:-:|:-:|:-:|:-:|
 | C2y | N/A | [N3301](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3301.pdf) | N/A |
 | C23 | 202311 | [N3096](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3096.pdf) | [ISO/IEC 9899:2024](https://www.iso.org/standard/82075.html) |
 | C17 | 201710 | [N2176](https://web.archive.org/web/20181230041359if_/http://www.open-std.org/jtc1/sc22/wg14/www/abq/c17_updated_proposed_fdis.pdf) | [ISO/IEC 9899:2018](https://www.iso.org/standard/74528.html) |
 | C11 | 201112 | [N1570](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf) | [ISO/IEC 9899:2011](https://www.iso.org/standard/57853.html) |
 | C99 | 199901 | [N1256](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf) | [ISO/IEC 9899:1999](https://www.iso.org/standard/29237.html) |
 | C95 | 199409 | [c89_na1: c94](https://port70.net/~nsz/c/c89/c94_na1.html) | [ISO/IEC 9899:1990/AMD1:1995](https://www.iso.org/standard/23909.html) |
 | C90 | not defined | Missing | [ISO/IEC 9899:1990](https://www.iso.org/standard/17782.html) |
 | C89 | not defined | [c89 draft](https://port70.net/~nsz/c/c89/c89-draft.html) | ANSI X3.159-1989 |


---
## POSIX Reference Documentation
POSIX (Portable Operating System Interface) specifies many parts of an Operating System.

 * [Unix standards overview](https://www.opengroup.org/certifications/unix/standards)

Interesting for this project is the API part of the Base Specification.


### Released versions
The Open Group Base Specification is also released as
the Single UNIX Specification and also released as
the ISO/IEC 9945-1 standard.

  |\_POSIX_VERSION|\_XOPEN_VERSION|The Open Group Base Specification|View|Downloads|
  |:-:|:-:|:-:|:-:|:-:|
  |202405|800|POSIX.1-2024, Issue 8, 2024 Edition|[View online](https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/)|[Downloads N/A yet]|
  |200809|700|POSIX.1-2017, Issue 7, 2018 Edition|[View online](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/)|[susv4-2018](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/download/)|
  |200809|700|POSIX.1-2008, Issue 7, 2016 Edition|[View online](https://pubs.opengroup.org/onlinepubs/9699919799.2016edition/)|[susv4tc2](https://pubs.opengroup.org/onlinepubs/9699919799.2016edition/download/)|
  |200809|700|POSIX.1-2008, Issue 7, 2013 Edition|[View online](https://pubs.opengroup.org/onlinepubs/9699919799.2013edition/)|[susv4tc1](https://pubs.opengroup.org/onlinepubs/9699919799.2013edition/download/)|
  |200809|700|POSIX.1-2008, Issue 7, 2008 Edition|[View online](https://pubs.opengroup.org/onlinepubs/9699919799.2008edition/)|[susv4](https://pubs.opengroup.org/onlinepubs/9699919799.2008edition/download/)|
  |200112|600|POSIX.1-2001, Issue 6, 2004 Edition|[View online](https://pubs.opengroup.org/onlinepubs/009695399/)|[susv3](https://pubs.opengroup.org/onlinepubs/009695399/download/)|
  |199506||POSIX.1-1996| | |
  |199009||POSIX.1-1990| | |
  |198808||POSIX.1-1988| | |


* Single UNIX Specification [(SUSv*)](https://publications.opengroup.org/standards/unix/single-unix-specification)
  * [UNIX V7, Version 4](https://publications.opengroup.org/t101)
  * [UNIX 03, Version 3](https://publications.opengroup.org/t041)
  * [UNIX 98, Version 2](https://publications.opengroup.org/c60x)
  * [UNIX 95, Version 1](https://publications.opengroup.org/c43x)


* POSIX 2024 Publication status at iso.org: 40.99 (since 19.Sep.2024)

    |Changed|Status|Status-Text|
    |:-:|:-:|:--|
    |    N/A    |60.60|International Standard published|
    |    N/A    |60.00|International Standard under publication|
    |    N/A    |50.60|Close of voting. Proof returned by secretariat|
    |    N/A    |50.20|Proof sent to secretariat or FDIS ballout initiated: 8 weeks|
    |    N/A    |50.00|Final text received or FDIS registered for formal approval|
    |19.Sep.2024|40.99|Full report circulated: DIS approved for registration as FDIS|

  * [ISO/IEC/IEEE 9945:2024](https://www.iso.org/standard/86539.html)
  * [ISO/IEC/IEEE 9945:2009](https://www.iso.org/standard/50516.html)
  * [ISO/IEC/IEEE 9945-1:2003](https://www.iso.org/standard/38789.html)
  * [ISO/IEC/IEEE 9945-1:2002](https://www.iso.org/standard/37312.html)
  * [ISO/IEC/IEEE 9945-1:1996](https://www.iso.org/standard/24426.html)
  * [ISO/IEC/IEEE 9945-1:1990](https://www.iso.org/standard/17840.html)


---
## C++ Reference Documentation
  * [ISOCPP SC22/WG21 C++ standards commitee](https://www.open-std.org/jtc1/sc22/wg21/)
  * [C++ standard core language issues list](https://www.open-std.org/jtc1/sc22/wg21/docs/cwg_index.html)
  * [C++ standard library issues list](https://www.open-std.org/jtc1/sc22/wg21/docs/lwg-active.html)
  * C++26 First draft was [N4958](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2023/n4958.pdf)
  * C++23 is available at the iso.org Website since 19.Oct.2024


#### Released C++ Standards

 |std|\_\_cplusplus|Latest Draft|Release|
 |:-:|:-:|:-:|:-:|
 |C++26|  N/A |[N4993](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2024/n4993.pdf)|N/A|
 |C++23|202302|[N4950](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2023/n4950.pdf)|[ISO/IEC 14882:2023](https://www.iso.org/standard/83626.html)|
 |C++20|202002|[N4849](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/n4849.pdf)|[ISO/IEC 14882:2020](https://www.iso.org/standard/79358.html)|
 |C++17|201703|[N4659](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/n4659.pdf)|[ISO/IEC 14882:2017](https://www.iso.org/standard/68564.html)|
 |C++14|201402|[N3797](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3797.pdf)|[ISO/IEC 14882:2014](https://www.iso.org/standard/64029.html)|
 |C++11|201103|[N3242](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2011/n3242.pdf)|[ISO/IEC 14882:2011](https://www.iso.org/standard/50372.html)|
 |C++03|200300|[c++03 final](https://port70.net/~nsz/c/c%2B%2B/c%2B%2B03_final.pdf)|[ISO/IEC 14882:2003](https://www.iso.org/standard/38110.html)|
 |C++98|199711|[nr. unknown](https://port70.net/~nsz/c/c%2B%2B/c%2B%2B98.pdf)|[ISO/IEC 14882:1998](https://www.iso.org/standard/25845.html)|


***
## Maintainer Mode hints
  * use 'bootstrap' to regenerate the build system files
  * use 'configure' with "--enable-maintainer-mode" to rebuild all programs
    all tests groups are enabled by default:
    - C
    - C++    (alias names: cxx / cplusplus)
    - posix
    - libc
    - libc++ (alias name: libcxx)

---
