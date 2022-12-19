## Selecting a free testsuite / unit test framework for stdtests

Requirements for our unit test framework.

  * A reusable license
  * Small
  * Very low Dependencies (includes are also important)
  * Output results in [TAP](https://www.testanything.org) format
  * Portable: Works on many systems with many compiler and runtime libraries
    * Works on Linux
    * Works on BSD and other Unix OS (probably macOS)
    * Works on Windows
    * STDC versions: C23, C17, C11, C99, C95 and C89
    * C++ versions: C++23, C++20, C++17, C++14, C++11, C++03, C++98
  * Catch signals
  * Can execute every test in a separate process
  * Can execute tests in the same process


### Where to looked at

 - Github: [Single file libs: unit-testing](https://github.com/nothings/single_file_libs#unit-testing)
 - Github: [awesome-c: testing](https://github.com/oz123/awesome-c#testing)
 - Github: [awesome-cpp: debug](https://github.com/fffaraz/awesome-cpp#debug)
 - Github: [awesome-tap](https://github.com/sindresorhus/awesome-tap)
 - Github: [awesome-testing](https://github.com/TheJambo/awesome-testing)
 - Github: Search for "unit" or test
 - Wikipedia: [List on unit testing frameworks: C](https://en.wikipedia.org/wiki/List_of_unit_testing_frameworks#C)
 - From the unity makers: [comparsion of unit test frameworks](https://www.throwtheswitch.org/comparison-of-unit-test-frameworks)

 |Name|PD MIT BSD|Other|Main .h| Main .c|More files|OS|Lang|SIG|Exec|Comments |
 |:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
 | - | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[acutest](https://github.com/mity/acutest)| MIT | ? |1839 / 60k | ? | ? | ? | ? | ? | ? | ? |
 |[Atto](https://github.com/TheMatjaz/atto)| BSD-3| - | 562 / 16k6 | 38 / 1k8 | ? | ? | ? | ? | ? | ? |
 |[cfix](https://github.com/jpassing/cfix)|  ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[cgreen](https://github.com/cgreen-devs/cgreen)| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[CHEAT](https://github.com/Tuplanolla/cheat)| BSD-2 | ? | 3296 / 153k | ? | ? | ? | ? | ? | ? | ? |
 |[cheatc](https://github.com/Tuplanolla/cheat)| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[ciut](https://github.com/yhfudev/cpp-ci-unit-test)| MIT | ? | 840 / 36k6 | ? | 219 / 5k5 | ? | ? | ? | ? | ? |
 |[clar](https://github.com/clar-test/clar)| - | ISC | 173 / 6k | 788 / 17k4 | ? | ? | ? | ? | ? | ? |
 |[cmocka](https://github.com/clibs/cmocka)| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[Criterion](https://github.com/Snaipe/Criterion)| MIT | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[ctest](https://github.com/bvdberg/ctest)| - |Apache2| 590 / 20k2 | ? | ? | ? | ? | ? | ? | ? |
 |[CUnit](https://github.com/jacklicn/CUnit)| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[doctest](https://github.com/doctest/doctest)| MIT | - | 7019 / 311k | 3971 / 160k | ? | ? | C++ | - | - | - |
 |[ecunit](https://github.com/utisam/ecunit)| MIT | - | 144 / 4k | 95 / 2k7 | ? | ? | ? | ? | ? | ? |
 |[fctx](https://github.com/imb/fctx) | BSD | - | 3947 / 104k | - | - | - | C / C++ | - | - | - |
 |[greatest](https://github.com/silentbicycle/greatest)| - | ISC | 1266 / 67k3 | ? | ? | ? | ? | ? | ? | ? |
 |[labrat](https://github.com/squarewave/labrat) | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[libtap](https://github.com/zorgnax/libtap)| - |LGPL3 | 115 / 4k7 | 362 / 8k4 | ? | ? | ? | ? | ? | ? |
 |[libzt](https://github.com/zyga/libzt)| - |LGPL| 234 / 6k6 | 1254 / 37k | ? | ? | ? | ? | ? | ? |
 |[ltest](https://github.com/MartinBloedorn/ltest)| - |Apache2| 205 / 7k4 | 134 / 3k4 | ? | ? | ? | ? | ? | ? |
 |[metal_test](https://github.com/PabloMansanet/metal_test)| - |GPL2| ? | ? | ? | ? | ? | ? | ? | ? |
 |[minctest](https://github.com/codeplea/minctest)| ? | Zlib | | 137 / 3k4 | ? | ? | ? | ? | ? | ? | ? |
 |[mintest](https://github.com/marshall/mintest)| - |Apache2| 150 / 3k9 | ? | ? | ? | ? | ? | ? | ? |
 |[MinUnit](https://github.com/siu/minunit)| MIT | ? | 391 / 11k4 | ? | ? | ? | ? | ? | ? | ? |
 |[munit](https://github.com/nemequ/munit)| MIT | ? | 535 / 17k2 | ? | ? | ? | ? | ? | ? | ? |
 |[nala](https://github.com/eerimoq/nala)| MIT | ? | 449 / 16k4 | ? | ? | ? | ? | ? | ? |C11: _Generic, but nice features|
 |[narwhal](https://github.com/vberlier/narwhal) | MIT | ? | Many | ? | ? | ? | ? | ? | ? | ? |
 |[picotest 1k4](https://github.com/chriscowdery/piCotest.git)| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[picotest 5k5](https://github.com/colinbarry/picotest.git)| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[picotest 76k6](https://github.com/fredericbonnet/picotest)| BSD-3| ? | 2029 / 76k6 | ? | ? | ? | ? | ? | ? | ? |
 |[Rexo](https://github.com/christophercrouzet/rexo)| PD | - | 9419 / 493k | ? | ? | ? | ? | ? | ? | ? |
 |[seatest](https://github.com/keithn/seatest)| MIT | - | 97 / 6k | 163 / 4k1 | ? | ? | ? | ? | ? | ? |
 |[sigunit](https://github.com/SigJig/sigunit)| MIT | - | 87 / 4k1 | ? | ? | ? | ? | ? | ? | ? |
 |[slim_test](https://github.com/arkanis/single-header-file-c-libs)| MIT | ? | 198 / 7k1 | ? | ? | ? | ? | ? | ? | ? |
 |[SinplyC](https://github.com/Rebelstack/simplyc)| - | GPL3 | 294 / 11k2 | 854 / 23k4 | ? | ? | ? | ? | ? | ? |
 |[tau](https://github.com/jasmcaus/tau)| ? | ? | ? | ? | ? | ? | ? | ? | ? | C11, but using auto register|
 |[testfw.h](https://github.com/mattiasgustavsson/libs)| PD or MIT | - | 581 / 22k3 | - | - | |
 |[Testie](https://github.com/embeardded/Testie.git) | ? | ? | 47 / 3k | 468 / 15k5 | 192 / 7k2 | ? | ? | ? | ? | ? |
 |[tst](https://github.com/mattwidmann/tst)| ? | ? | 213 / 6k6 | ? | ? | ? | ? | ? | ? | ? |
 |[tinytest](https://github.com/ccosmin/tinytest) | ? | ? | 14k8 | ? | ? | ? | ? | ? | ? | ? |
 |[unit](https://github.com/eliasku/unit)| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[unity](https://github.com/ThrowTheSwitch/Unity)| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[unityc](https://github.com/bradfa/unityc) | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[utest](https://github.com/evolutional/utest)| PD| - | 564 / 16k2 | No | No | ? | ? | ? | ? |C99: var.args|
 |[utest](https://github.com/davilamr/utest)|  - |GPL3| 98 / 6k7 | 107 / 3k2 | ? | ? | ? | ? | ? | ? |
 |[UTEST](https://github.com/jhdenton/UTEST)| ? | ? | 288 / 11k2 | 327 / 10k1 | 28 / 1k | ? | ? | ? | ? | ? |
 |[utest.h](https://github.com/sheredom/utest.h)| PD | - | 1431 / 64k7 | - | - |LMW|C/C++ |? | | |
 | - | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |Name|PD|MIT|BSD|Other|Main .h| Main .c|More files|OS|Lang|SIG|Exec|Comments |

---

