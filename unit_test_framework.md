## Selecting a free testsuite / unit test framework for stdtests

Requirements for our unit test framework.

  * [ ] A reusable license
  * [ ] Small
  * [ ] Very low Dependencies (includes are also important)
  * [ ] Supports [TAP](https://www.testanything.org) output (xUnit/JSON output is too big)
  * [ ] Portable: Works on many systems with many compiler and runtime libraries
    * [ ] Works on Linux
    * [ ] Works on BSD and other Unix OS (probably macOS)
    * [ ] Works on Windows
    * [ ] C Compiler: C23, C17, C11, C99, C95 and C89
    * [ ] C++ Compiler: C++23, C++20, C++17, C++14, C++11, C++03, C++98
  * [ ] Catch signals
  * [ ] Run in a separate process: available, but not required


### Where to looked at

 - Github: [Single file libs](https://github.com/nothings/single_file_libs#unit-testing)
 - Github: [Single file libs](https://github.com/nothings/single_file_libs#unit-testing)
 - Github: [Single file libs](https://github.com/nothings/single_file_libs#unit-testing)
 - Wikipedia: [List on unit testing frameworks](https://en.wikipedia.org/wiki/List_of_unit_testing_frameworks#C)
 - [comparsion of unit test frameworks(from the unity makers)](https://www.throwtheswitch.org/comparison-of-unit-test-frameworks)

 |Name|PD|MIT|BSD|Other|Main .h| Main .c|More files|OS|Lang|SIG|Exec|Comments |
 |:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
 | - | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[Atto] | - | - |BSD-3| - | 562 / 16k6 | 38 / 1k8 | ? | ? | ? | ? | ? | ? |
 |[cfix](https://github.com/jpassing/cfix)| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[cgreen](https://github.com/cgreen-devs/cgreen)| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[cheatc](https://github.com/Tuplanolla/cheat)| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[cmocka](https://github.com/clibs/cmocka)| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[doctest](https://github.com/doctest/doctest)| - | x | - | - | 7019 / 311k | 3971 / 160k | ? | ? | C++ | - | - | - |
 |[ecunit](https://github.com/utisam/ecunit)| - | MIT | - | - | 144 / 4k | 95 / 2k7 | ? | ? | ? | ? | ? | ? |
 |[fctx](https://github.com/imb/fctx) | - | - | x | - | 3947 / 104k | - | - | - | C / C++ | - | - | - |
 |[greatest](https://github.com/silentbicycle/greatest)| ? | ? | ? | ISC | 1266 / 67k3 | ? | ? | ? | ? | ? | ? | ? |
 |[labrat](https://github.com/squarewave/labrat) | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[libzt](https://github.com/zyga/libzt)| ? | ? | ? |LGPL| 234 / 6k6 | 1254 / 37k | ? | ? | ? | ? | ? | ? |
 |[ltest](https://github.com/MartinBloedorn/ltest)| ? | ? | ? |Apache2| 205 / 7k4 | 134 / 3k4 | ? | ? | ? | ? | ? | ? |
 |[metal_test](https://github.com/PabloMansanet/metal_test)| ? | ? | ? |GPL2| ? | ? | ? | ? | ? | ? | ? | ? |
 |[minctest](https://github.com/codeplea/minctest)| ? | ? | ? | ZLIB | 137 / 3k4 | ? | ? | ? | ? | ? | ? | ? |
 |[mintest](https://github.com/marshall/mintest)| - | - | - |Apache2| 150 / 3k9 | ? | ? | ? | ? | ? | ? | ? |
 |[munit](https://github.com/nemequ/munit)| - |MIT | ? | ? | 535 / 17k2 | ? | ? | ? | ? | ? | ? | ? |
 |[picotest 1k4](https://github.com/chriscowdery/piCotest.git)| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[picotest 5k5](https://github.com/colinbarry/picotest.git)| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[picotest 76k6](https://github.com/fredericbonnet/picotest)| ? | ? |BSD-3| ? | 2029 / 76k6 | ? | ? | ? | ? | ? | ? | ? |
 |[Rexo](https://github.com/christophercrouzet/rexo)| U | ? | ? | ? | 9419 / 493k | ? | ? | ? | ? | ? | ? | ? |
 |[seatest](https://github.com/keithn/seatest)| - | MIT | - | - | 97 / 6k | 163 / 4k1 | ? | ? | ? | ? | ? | ? |
 |[sigunit](https://github.com/SigJig/sigunit)| - | MIT | - | - | 87 / 4k1 | ? | ? | ? | ? | ? | ? | ? |
 |[slim_test](https://github.com/arkanis/single-header-file-c-libs)| ? | MIT | ? | ? | 198 / 7k1 | ? | ? | ? | ? | ? | ? | ? |
 |[SinplyC](https://github.com/Rebelstack/simplyc)| ? | ? | ? | GPL3 | 294 / 11k2 | 854 / 23k4 | ? | ? | ? | ? | ? | ? |
 |[tau](https://github.com/jasmcaus/tau)| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | C11, but using auto register|
 |[testfw.h](https://github.com/mattiasgustavsson/libs)| PD | MIT | - | - | 581 / 22k3 | - | - | |
 |[Testie](https://github.com/embeardded/Testie.git) | ? | ? | ? | ? | 47 / 3k | 468 / 15k5 | 192 / 7k2 | ? | ? | ? | ? | ? |
 |[tst](https://github.com/mattwidmann/tst)| ? | ? | ? | ? | 213 / 6k6 | ? | ? | ? | ? | ? | ? | ? |
 |[tinytest](https://github.com/ccosmin/tinytest) | ? | ? | ? | ? | 14k8 | ? | ? | ? | ? | ? | ? | ? |
 |[unit](https://github.com/eliasku/unit)| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[unity](https://github.com/ThrowTheSwitch/Unity)| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[unityc](https://github.com/bradfa/unityc) | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |[utest](https://github.com/evolutional/utest)| U | ? | ? | ? | 564 / 16k2 | No | No | ? | ? | ? | ? |C99: var.args|
 |[utest](https://github.com/davilamr/utest)| - | - | - |GPL3| 98 / 6k7 | 107 / 3k2 | ? | ? | ? | ? | ? | ? |
 |[UTEST](https://github.com/jhdenton/UTEST)| ? | ? | ? | ? | 288 / 11k2 | 327 / 10k1 | 28 / 1k | ? | ? | ? | ? | ? |
 |[utest.h](https://github.com/sheredom/utest.h)| PD | - | - | - | 1431 / 64k7 | - | - |LMW|C/C++ |? | | |
 | - | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
 |Name|PD|MIT|BSD|Other|Main .h| Main .c|More files|OS|Lang|SIG|Exec|Comments |





