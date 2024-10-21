/* ############# */
/* ToDo: License */
/*
 * detection of some common compiler
 * with the advertised C / C++ standard
 * and some OS/Architecture
 * with the used memory / datamodel
 *
 * Use it only for debug/system information
 */
/* output looks better when using the same length for all output */

#define FMT_DEFAULT_ID    "%-23s"
#define FMT_DEFAULT_VALUE "%-8lu"
#define FMT_INT_VALUE     "%-8d"
#define FMT_HEX4_VALUE    "0x%04lx  "
#define FMT_STRING_VALUE  "%-8s"

#ifndef str2raw
#define str2raw(x) #x
#define str2txt(x) str2raw(x)
#endif


/* ##################################################### */
/* compiler detection:
 * compiler id, compiler name and short compiler version
 * When available, also a verbose compiler version */

/* ############### */
/* Tiny C Compiler */
#ifdef __TINYC__
const char compiler_id_tinyc[] = "__TINYC__";
const unsigned long compiler_value_tinyc = __TINYC__;

const char compiler_name_tinyc[] = "Tiny C";
const int  compiler_ver_tinyc = __TINYC__ / 10000;
const int  compiler_rev_tinyc = (__TINYC__ % 10000) / 100;
const int  compiler_pl_tinyc = __TINYC__ % 100;
#define compiler_ver_fmt_tinyc  "%d.%d.%d"
#define USE_COMPILER_ID      compiler_id_tinyc
#define USE_COMPILER_VALUE   compiler_value_tinyc
#define USE_COMPILER_NAME    compiler_name_tinyc
#define USE_COMPILER_VER     compiler_ver_tinyc
#define USE_COMPILER_REV     compiler_rev_tinyc
#define USE_COMPILER_PL      compiler_pl_tinyc
#define USE_COMPILER_VER_FMT compiler_ver_fmt_tinyc
#endif  /* end of __TINYC__ */



/* ############################ */
/* cosmopolitan compiler driver */

#ifdef __COSMOCC__
const char compiler_id_cosmocc[] = "__COSMOCC__";
const unsigned long compiler_value_cosmocc = __COSMOCC__;
const char compiler_name_cosmocc[] = "cosmopolitan compiler driver";
#define USE_COMPILER_ID       compiler_id_cosmocc
#define USE_COMPILER_VALUE    compiler_value_cosmocc
#define USE_COMPILER_NAME     compiler_name_cosmocc
#endif  /* end of __COSMOCC__ */



/* ################## */
/* Bruce's C compiler */
#ifdef __BCC__
const char compiler_id_bcc[] = "__BCC__";
const unsigned long compiler_value_bcc = __BCC__;

const char compiler_name_bcc[] = "Bruce's C compiler";
#define USE_COMPILER_ID      compiler_id_bcc
#define USE_COMPILER_VALUE   compiler_value_bcc
#define USE_COMPILER_NAME    compiler_name_bcc

#ifdef __BCC_VERSION__
const int  compiler_ver_bcc = __BCC_VERSION__ / 0x10000L;
const int  compiler_rev_bcc = (__BCC_VERSION__ % 0x10000L ) / 256;
const int  compiler_pl_bcc =   __BCC_VERSION__ % 256L;
#define compiler_ver_fmt_bcc  "%d.%d.%d"
#define USE_COMPILER_VER     compiler_ver_bcc
#define USE_COMPILER_REV     compiler_rev_bcc
#define USE_COMPILER_PL      compiler_pl_bcc
#define USE_COMPILER_VER_FMT compiler_ver_fmt_bcc

const char version_id_bcc[] = "__BCC_VERSION__";
const unsigned long version_value_bcc = __BCC_VERSION__;
#define version_fmt_bcc    "0x%lx"
#define USE_VERSION_ID     version_id_bcc
#define USE_VERSION_VALUE  version_value_bcc
#define USE_VERSION_FMT    version_fmt_bcc
#endif  /* end of __BCC_VERSION__ */
#endif  /* end of __BCC__ */



/* ########################### */
/* Borland C/C++ / Turbo C/C++ */

#ifdef __BORLANDC__
const char compiler_id_BORLANDC[] = "__BORLANDC__";
const unsigned long compiler_value_BORLANDC = __BORLANDC__;
const char compiler_name_BORLANDC[] = "Borland C/C++ Compiler";
#define USE_COMPILER_ID      compiler_id_BORLANDC
#define USE_COMPILER_VALUE   compiler_value_BORLANDC
#define USE_COMPILER_NAME    compiler_name_BORLANDC

const int  compiler_ver_BORLANDC = (__BORLANDC__ / 256);
const int  compiler_rev_BORLANDC = (__BORLANDC__ & 0xff );
#define compiler_ver_fmt_BORLANDC  "%d.%x"
#define USE_COMPILER_VER     compiler_ver_BORLANDC
#define USE_COMPILER_REV     compiler_rev_BORLANDC
#define USE_COMPILER_VER_FMT compiler_ver_fmt_BORLANDC
#endif  /* end of __BORLANDC__ */

#ifdef BORLAND386
const char compiler_id_BORLAND386[] = "BORLAND386";
const unsigned long compiler_value_BORLAND386 = BORLAND386;
const char compiler_name_BORLAND386[] = "Borland C/C++ Compiler (386)";
#ifndef USE_COMPILER_ID
#define USE_COMPILER_ID      compiler_id_BORLAND386
#define USE_COMPILER_VALUE   compiler_value_BORLAND386
#define USE_COMPILER_NAME    compiler_name_BORLAND386
#else
#define USE_COMPILER_ID2     compiler_id_BORLAND386
#define USE_COMPILER_VALUE2  compiler_value_BORLAND386
#define USE_COMPILER_NAME2   compiler_name_BORLAND386
#endif

const int  compiler_ver_BORLAND386 = (BORLAND386 / 256);
const int  compiler_rev_BORLAND386 = (BORLAND386 & 0xff );
#define compiler_ver_fmt_BORLAND386  "%d.%x"
#ifndef USE_COMPILER_VER
#define USE_COMPILER_VER      compiler_ver_BORLAND386
#define USE_COMPILER_REV      compiler_rev_BORLAND386
#define USE_COMPILER_VER_FMT  compiler_ver_fmt_BORLAND386
#else
#define USE_COMPILER_VER2     compiler_ver_BORLAND386
#define USE_COMPILER_REV2     compiler_rev_BORLAND386
#define USE_COMPILER_VER_FMT2 compiler_ver_fmt_BORLAND386
#endif
#endif  /* end of BORLAND386 */


#ifdef __TCPLUSPLUS__
const char compiler_id_TCPLUSPLUS[] = "__TCPLUSPLUS__";
const unsigned long compiler_value_TCPLUSPLUS = __TCPLUSPLUS__;
const char compiler_name_TCPLUSPLUS[] = "Turbo C++ Compiler";
#ifndef USE_COMPILER_ID
#define USE_COMPILER_ID       compiler_id_TCPLUSPLUS
#define USE_COMPILER_VALUE    compiler_value_TCPLUSPLUS
#define USE_COMPILER_NAME     compiler_name_TCPLUSPLUS
#define USE_COMPILER_VAL_FMT  FMT_HEX4_VALUE
#else
#ifndef USE_COMPILER_ID2
#define USE_COMPILER_ID2      compiler_id_TCPLUSPLUS
#define USE_COMPILER_VALUE2   compiler_value_TCPLUSPLUS
#define USE_COMPILER_NAME2    compiler_name_TCPLUSPLUS
#define USE_COMPILER_VAL_FMT2 FMT_HEX4_VALUE
#else
#define USE_COMPILER_ID3      compiler_id_TCPLUSPLUS
#define USE_COMPILER_VALUE3   compiler_value_TCPLUSPLUS
#define USE_COMPILER_NAME3    compiler_name_TCPLUSPLUS
#define USE_COMPILER_VAL_FMT3 FMT_HEX4_VALUE
#endif /* USE_COMPILER_ID2 */
#endif /* USE_COMPILER_ID */

const int  compiler_ver_TCPLUSPLUS = (__TCPLUSPLUS__ /  256);
const int  compiler_rev_TCPLUSPLUS = (__TCPLUSPLUS__ & 0xff );
#define compiler_ver_fmt_TCPLUSPLUS  "%d.%x"
#ifndef USE_COMPILER_VER
#define USE_COMPILER_VER      compiler_ver_TCPLUSPLUS
#define USE_COMPILER_REV      compiler_rev_TCPLUSPLUS
#define USE_COMPILER_VER_FMT  compiler_ver_fmt_TCPLUSPLUS
#else
#ifndef USE_COMPILER_VER2
#define USE_COMPILER_VER2     compiler_ver_TCPLUSPLUS
#define USE_COMPILER_REV2     compiler_rev_TCPLUSPLUS
#define USE_COMPILER_VER_FMT2 compiler_ver_fmt_TCPLUSPLUS
#else
#define USE_COMPILER_VER3     compiler_ver_TCPLUSPLUS
#define USE_COMPILER_REV3     compiler_rev_TCPLUSPLUS
#define USE_COMPILER_VER_FMT3 compiler_ver_fmt_TCPLUSPLUS
#endif /* USE_COMPILER_VER2 */
#endif /* USE_COMPILER_VER */

/* end of __TCPLUSPLUS__ */

#elif defined __TURBOC__
const char compiler_id_TURBOC[] = "__TURBOC__";
const unsigned long compiler_value_TURBOC = __TURBOC__;
const char compiler_name_TURBOC[] = "Turbo C/C++ Compiler";
#ifndef USE_COMPILER_ID
#define USE_COMPILER_ID       compiler_id_TURBOC
#define USE_COMPILER_VALUE    compiler_value_TURBOC
#define USE_COMPILER_NAME     compiler_name_TURBOC
#define USE_COMPILER_VAL_FMT  FMT_HEX4_VALUE
#else
#ifndef USE_COMPILER_ID2
#define USE_COMPILER_ID2      compiler_id_TURBOC
#define USE_COMPILER_VALUE2   compiler_value_TURBOC
#define USE_COMPILER_NAME2    compiler_name_TURBOC
#define USE_COMPILER_VAL_FMT2 FMT_HEX4_VALUE
#else
#define USE_COMPILER_ID3      compiler_id_TURBOC
#define USE_COMPILER_VALUE3   compiler_value_TURBOC
#define USE_COMPILER_NAME3    compiler_name_TURBOC
#define USE_COMPILER_VAL_FMT3 FMT_HEX4_VALUE
#endif /* USE_COMPILER_ID2 */
#endif /* USE_COMPILER_ID */

const int  compiler_ver_TURBOC = (__TURBOC__ /  256);
const int  compiler_rev_TURBOC = (__TURBOC__ & 0xff );
#define compiler_ver_fmt_TURBOC  "%d.%x"
#ifndef USE_COMPILER_VER
#define USE_COMPILER_VER      compiler_ver_TURBOC
#define USE_COMPILER_REV      compiler_rev_TURBOC
#define USE_COMPILER_VER_FMT  compiler_ver_fmt_TURBOC
#else
#ifndef USE_COMPILER_VER2
#define USE_COMPILER_VER2     compiler_ver_TURBOC
#define USE_COMPILER_REV2     compiler_rev_TURBOC
#define USE_COMPILER_VER_FMT2 compiler_ver_fmt_TURBOC
#else
#define USE_COMPILER_VER3     compiler_ver_TURBOC
#define USE_COMPILER_REV3     compiler_rev_TURBOC
#define USE_COMPILER_VER_FMT3 compiler_ver_fmt_TURBOC
#endif /* USE_COMPILER_VER2 */
#endif /* USE_COMPILER_VER */

#endif  /* end of __TURBOC__ */


/* ##################################### */
/* EDG: Edison Design Group C++ Frontend */
/* might claim to be GCC or MSVC         */

#ifdef __EDG__
const char compiler_id_EDG[] = "__EDG__";
const unsigned long compiler_value_EDG = __EDG__;
const char compiler_name_EDG[] = "EDG C++ Frontend";
#define USE_COMPILER_ID      compiler_id_EDG
#define USE_COMPILER_VALUE   compiler_value_EDG
#define USE_COMPILER_NAME    compiler_name_EDG

#ifdef __EDG_VERSION__
const int  compiler_ver_EDG = (__EDG_VERSION__ / 256);
const int  compiler_rev_EDG = (__EDG_VERSION__ & 0xff);
#define compiler_ver_fmt_EDG  "%d.%x"
#define USE_COMPILER_VER     compiler_ver_EDG
#define USE_COMPILER_REV     compiler_rev_EDG
#define USE_COMPILER_VER_FMT compiler_ver_fmt_EDG
#endif  /* end of __EDG_VERSION__ */

#endif  /* end of __EDG__ */


/* ################### */
/* Portable C Compiler */
#ifdef __PCC__
const char compiler_id_PCC[] = "__PCC__";
const unsigned long compiler_value_PCC = __PCC__;
const char compiler_name_PCC[] = "Portable C Compiler";
#define USE_COMPILER_ID      compiler_id_PCC
#define USE_COMPILER_VALUE   compiler_value_PCC
#define USE_COMPILER_NAME    compiler_name_PCC

#ifdef __PCC_MINOR__
const int  compiler_ver_PCC = __PCC__;
const int  compiler_rev_PCC = __PCC_MINOR__;
const int  compiler_pl_PCC  = __PCC_MINORMINOR__;
#define compiler_ver_fmt_PCC  "%d.%d.%d"
#define USE_COMPILER_VER     compiler_ver_PCC
#define USE_COMPILER_REV     compiler_rev_PCC
#define USE_COMPILER_PL      compiler_pl_PCC
#define USE_COMPILER_VER_FMT compiler_ver_fmt_PCC
#endif  /* end of __PCC_MINOR__ */
#endif  /* end of __PCC__ */



/* ####################### */
/* Small Device C Compiler */
#ifdef __SDCC
const char compiler_id_sdcc[] = "__SDCC";
const char compiler_value_sdcc[] = str2txt(__SDCC);
const char compiler_name_sdcc[] = "Small Device C Compiler";
#define USE_COMPILER_VAL_FMT FMT_STRING_VALUE
#define USE_COMPILER_ID      compiler_id_sdcc
#define USE_COMPILER_VALUE   compiler_value_sdcc
#define USE_COMPILER_NAME    compiler_name_sdcc

#ifdef __SDCC_VERSION_MAJOR
const int  compiler_ver_sdcc = __SDCC_VERSION_MAJOR;
const int  compiler_rev_sdcc = __SDCC_VERSION_MINOR;
const int  compiler_pl_sdcc =  __SDCC_VERSION_PATCH;
#define compiler_ver_fmt_sdcc  "%d.%d.%d"
#define USE_COMPILER_VER     compiler_ver_sdcc
#define USE_COMPILER_REV     compiler_rev_sdcc
#define USE_COMPILER_PL      compiler_pl_sdcc
#define USE_COMPILER_VER_FMT compiler_ver_fmt_sdcc
#endif
#endif  /* end of __SDCC */


/* ################## */
/* Smaller C Compiler */

#ifdef __SMALLER_C__
const char compiler_id_smaller_c[] = "__SMALLER_C__";
const char compiler_value_smaller_c[] = str2txt(__SMALLER_C__);
const char compiler_name_smaller_c[] = "Smaller C Compiler";
#define USE_COMPILER_VAL_FMT  FMT_STRING_VALUE
#define USE_COMPILER_ID       compiler_id_smaller_c
#define USE_COMPILER_VALUE    compiler_value_smaller_c
#define USE_COMPILER_NAME     compiler_name_smaller_c
#endif  /* end of __SMALLER_C__ */


/* ################################## */
/* OpenWatcom C / C++ or Watcom C/C++ */
#ifdef __WATCOMC__
const char compiler_id_watcomc[] = "__WATCOMC__";
const unsigned long compiler_value_watcomc = __WATCOMC__;

#if  __WATCOMC__ > 1100
const char compiler_name_watcomc[] = "OpenWatcom";
const int  compiler_ver_watcomc = (__WATCOMC__ - 1100) / 100;
const int  compiler_rev_watcomc = (__WATCOMC__ - 1100) % 100;
#else
const char compiler_name[] = "Watcom";
const int  compiler_ver_watcomc = __WATCOMC__ / 100;
const int  compiler_rev_watcomc = __WATCOMC__ % 100;
#endif
#define compiler_ver_fmt_watcomc "%d.%d"
#define USE_COMPILER_ID      compiler_id_watcomc
#define USE_COMPILER_VALUE   compiler_value_watcomc
#define USE_COMPILER_NAME    compiler_name_watcomc
#define USE_COMPILER_VER     compiler_ver_watcomc
#define USE_COMPILER_REV     compiler_rev_watcomc
#define USE_COMPILER_VER_FMT compiler_ver_fmt_watcomc
#endif  /* end of __WATCOMC__ */


/* OpenWatcom posix frontend */
#ifdef __OWCC__
const char compiler_id_owcc[] = "__OWCC__";
const unsigned long compiler_value_owcc = __OWCC__;
const char compiler_name_owcc[] = "OpenWatcom (POSIX frontend)";

#ifndef USE_COMPILER_ID
#define USE_COMPILER_ID      compiler_id_owcc
#define USE_COMPILER_VALUE   compiler_value_owcc
#define USE_COMPILER_NAME    compiler_name_owcc
#else
#define USE_COMPILER_ID2     compiler_id_owcc
#define USE_COMPILER_VALUE2  compiler_value_owcc
#define USE_COMPILER_NAME2   compiler_name_owcc
#endif
#endif


/* ######################### */
/* Insert more compiler here */
/* when a linux package is downloadable,
 * automatic testing might need qemu, Wine, dosemu/dosbox or similar */


/* ########################################### */
/* There are also other compiler from other OS, */
/* but without linux downloads:
 * automatic testing is not possible for most compiler
 * for MSVC >=2017, https://www.godbolt.ms helps (compile only) */

#ifdef _MSC_VER
const char compiler_id_msc_ver[] = "_MSC_VER";
const unsigned long compiler_value_msc_ver = _MSC_VER;
#define compiler_ver_fmt_msc_ver "%d.%d"
#ifndef USE_COMPILER_ID
#define USE_COMPILER_VER_FMT  compiler_ver_fmt_msc_ver
#else
#define USE_COMPILER_VER_FMT2 compiler_ver_fmt_msc_ver
#endif

/* 1900: Visual Studio 2015 or newer */
#if  _MSC_VER >= 1900

#if  _MSC_VER > 1936
/* Name and version is a wild guess for newest compilers */
/* value seen from using msvc laterst at https://www.godbolt.ms */
const char compiler_name_msc_ver[] = "Visual Studio 202x";
#ifndef USE_COMPILER_ID
#undef USE_COMPILER_VER_FMT
#else
#undef USE_COMPILER_VER_FMT2
#endif

#else
#if  _MSC_VER >= 1930
const char compiler_name_msc_ver[] = "Visual Studio 2022";
const int  compiler_ver_msc_ver = 17;
const int  compiler_rev_msc_ver = (_MSC_VER - 1930);
#else
#if  _MSC_VER >= 1920
const char compiler_name_msc_ver[] = "Visual Studio 2019";
const int  compiler_ver_msc_ver = 16;
const int  compiler_rev_msc_ver = (_MSC_VER == 1929) ? 10: (_MSC_VER - 1920) ;
#else
#if  _MSC_VER >= 1910
const char compiler_name_msc_ver[] = "Visual Studio 2017";
const int  compiler_ver_msc_ver = 15;
const int  compiler_rev_msc_ver = (_MSC_VER >= 1916) ? 9:
                                  (_MSC_VER >= 1912) ? (_MSC_VER - 1910) + 3 :
                                  (_MSC_VER - 1910) * 3;
#else
/* last else item of: _MSC_VER >= 1900 */
const char compiler_name_msc_ver[] = "Visual Studio 2015";
const int  compiler_ver_msc_ver = 14;
const int  compiler_rev_msc_ver = 0;
#endif
#endif
#endif
#endif

#else   /* else part of:  _MSC_VER >= 1900 */

#if  _MSC_VER >= 1800
const char compiler_name_msc_ver[] = "Visual Studio 2013";
const int  compiler_ver_msc_ver = 12;
const int  compiler_rev_msc_ver = 0;
#else
#if  _MSC_VER >= 1700
const char compiler_name_msc_ver[] = "Visual Studio 2012";
const int  compiler_ver_msc_ver = 11;
const int  compiler_rev_msc_ver = 0;
#else
#if  _MSC_VER >= 1600
const char compiler_name_msc_ver[] = "Visual Studio 2010";
const int  compiler_ver_msc_ver = 10;
const int  compiler_rev_msc_ver = 0;
#else
#if  _MSC_VER >= 1500
const char compiler_name_msc_ver[] = "Visual Studio 2008";
const int  compiler_ver_msc_ver = 9;
const int  compiler_rev_msc_ver = 0;
#else
#if  _MSC_VER >= 1400
const char compiler_name_msc_ver[] = "Visual Studio 2005";
const int  compiler_ver_msc_ver = 8;
const int  compiler_rev_msc_ver = 0;
#else
#if  _MSC_VER >= 1310
const char compiler_name_msc_ver[] = "Visual Studio .NET 2003";
const int  compiler_ver_msc_ver = 7;
const int  compiler_rev_msc_ver = 1;
#else
#if  _MSC_VER >= 1300
const char compiler_name_msc_ver[] = "Visual Studio .NET 2002";
const int  compiler_ver_msc_ver = 7;
const int  compiler_rev_msc_ver = 0;
#else
#if  _MSC_VER >= 1200
const char compiler_name_msc_ver[] = "Visual Studio 6.0";
const int  compiler_ver_msc_ver = 6;
const int  compiler_rev_msc_ver = 0;
#else
const char compiler_name_msc_ver[] = "Visual Studio";
#ifndef USE_COMPILER_ID
#undef USE_COMPILER_VER_FMT
#else
#undef USE_COMPILER_VER_FMT2
#endif

#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif

#endif  /* end of:  _MSC_VER >= 1900 */

#ifndef USE_COMPILER_ID
#define USE_COMPILER_ID      compiler_id_msc_ver
#define USE_COMPILER_VALUE   compiler_value_msc_ver
#define USE_COMPILER_NAME    compiler_name_msc_ver
#ifdef  USE_COMPILER_VER_FMT
#define USE_COMPILER_VER     compiler_ver_msc_ver
#define USE_COMPILER_REV     compiler_rev_msc_ver
#endif
#else  /* part of USE_COMPILER_ID */
#define USE_COMPILER_ID2     compiler_id_msc_ver
#define USE_COMPILER_VALUE2  compiler_value_msc_ver
#define USE_COMPILER_NAME2   compiler_name_msc_ver
#ifdef  USE_COMPILER_VER_FMT2
#define USE_COMPILER_VER2    compiler_ver_msc_ver
#define USE_COMPILER_REV2    compiler_rev_msc_ver
#endif
#endif  /* end of USE_COMPILER_ID */

#endif  /* end of _MSC_VER */


/* ########################### */
/* Digital Mars C/C++ Compiler */

#ifdef __DMC__
const char compiler_id_DMC[] = "__DMC__";
const unsigned long compiler_value_DMC = __DMC__;
const char compiler_name_DMC[] = "Digital Mars C/C++ Compiler";
#define USE_COMPILER_VAL_FMT FMT_HEX4_VALUE

#define USE_COMPILER_ID      compiler_id_DMC
#define USE_COMPILER_VALUE   compiler_value_DMC
#define USE_COMPILER_NAME    compiler_name_DMC

const int  compiler_ver_DMC = __DMC__ >> 8;
const int  compiler_rev_DMC = __DMC__ & 0xff;
#define compiler_ver_fmt_DMC  "%d.%x"
#define USE_COMPILER_VER     compiler_ver_DMC
#define USE_COMPILER_REV     compiler_rev_DMC
#define USE_COMPILER_VER_FMT compiler_ver_fmt_DMC

#ifdef __DMC_VERSION_STRING__
const char version_id_dmc[] = "__DMC_VERSION_STRING__";
const char *version_value_dmc = __DMC_VERSION_STRING__;
#define version_fmt_dmc  "\"%s\""

#define USE_VERSION_ID     version_id_dmc
#define USE_VERSION_VALUE  version_value_dmc
#define USE_VERSION_FMT    version_fmt_dmc
#endif

#endif  /* end of __DMC__ */



/* old name of DMC was SC */
#ifdef __SC__
const char compiler_id_SC[] = "__SC__";
const unsigned long compiler_value_SC = __SC__;
const char compiler_name_SC[] = "Symantec C/C++ Compiler";

#ifndef USE_COMPILER_ID
#define USE_COMPILER_ID       compiler_id_SC
#define USE_COMPILER_VALUE    compiler_value_SC
#define USE_COMPILER_NAME     compiler_name_SC
#define USE_COMPILER_VAL_FMT  FMT_HEX4_VALUE
#else
#define USE_COMPILER_ID2      compiler_id_SC
#define USE_COMPILER_VALUE2   compiler_value_SC
#define USE_COMPILER_NAME2    compiler_name_SC
#define USE_COMPILER_VAL_FMT2 FMT_HEX4_VALUE
#endif

const int  compiler_ver_SC = __SC__ >> 8;
const int  compiler_rev_SC = __SC__ & 0xff;
#define compiler_ver_fmt_SC  "%d.%x"
#define USE_COMPILER_VER     compiler_ver_SC
#define USE_COMPILER_REV     compiler_rev_SC
#define USE_COMPILER_VER_FMT compiler_ver_fmt_SC

#endif  /* end of __SC__ */


/* older name of DMC was ZTC */
#ifdef __ZTC__
const char compiler_id_ZTC[] = "__ZTC__";
const unsigned long compiler_value_ZTC = __ZTC__;
const char compiler_name_ZTC[] = "Zortech C/C++ Compiler";

#ifndef USE_COMPILER_ID
#define USE_COMPILER_ID      compiler_id_ZTC
#define USE_COMPILER_VALUE   compiler_value_ZTC
#define USE_COMPILER_NAME    compiler_name_ZTC
#define USE_COMPILER_VAL_FMT FMT_HEX4_VALUE

#else
#ifndef USE_COMPILER_ID2
#define USE_COMPILER_ID2      compiler_id_ZTC
#define USE_COMPILER_VALUE2   compiler_value_ZTC
#define USE_COMPILER_NAME2    compiler_name_ZTC
#define USE_COMPILER_VAL_FMT2 FMT_HEX4_VALUE

#else
#define USE_COMPILER_ID3      compiler_id_ZTC
#define USE_COMPILER_VALUE3   compiler_value_ZTC
#define USE_COMPILER_NAME3    compiler_name_ZTC
#define USE_COMPILER_VAL_FMT3 FMT_HEX4_VALUE
#endif
#endif

const int  compiler_ver_ZTC = __ZTC__ >> 8;
const int  compiler_rev_ZTC = __ZTC__ & 0xff;
#define compiler_ver_fmt_ZTC  "%d.%x"
#define USE_COMPILER_VER     compiler_ver_ZTC
#define USE_COMPILER_REV     compiler_rev_ZTC
#define USE_COMPILER_VER_FMT compiler_ver_fmt_ZTC

#endif  /* end of __ZTC__ */

/* ################# */
/* The 6502 compiler */
#ifdef __CC65__
const char compiler_id_cc65[] = "__CC65__";
const unsigned long compiler_value_cc65 = __CC65__;

const char compiler_name_cc65[] = "The 6502 compiler";
const int  compiler_ver_cc65 =  (__CC65__ & 0xf00) >> 8;
const int  compiler_rev_cc65 = (__CC65__ & 0xf0) >> 4;
const int  compiler_pl_cc65 =  (__CC65__ & 0xf);
#define compiler_ver_fmt_cc65  "%d.%d.%d"

#define USE_COMPILER_ID      compiler_id_cc65
#define USE_COMPILER_VALUE   compiler_value_cc65
#define USE_COMPILER_NAME    compiler_name_cc65
#define USE_COMPILER_VER     compiler_ver_cc65
#define USE_COMPILER_REV     compiler_rev_cc65
#define USE_COMPILER_PL      compiler_pl_cc65
#define USE_COMPILER_VER_FMT compiler_ver_fmt_cc65
#endif

/* ################################################### */
/* Check for __clang__ at the end, but before __GNUC__ */
/* some compiler are based on clang/llvm */
/* recent examples: */
/* zig, some versions of Embarcadero C++ Builder, Intel Compiler or MSVC */
#ifdef __clang__
const char compiler_id_clang[] = "__clang__";
const unsigned long compiler_value_clang = __clang__;

const char compiler_name_clang[] = "clang";
const int  compiler_ver_clang = __clang_major__;
const int  compiler_rev_clang = __clang_minor__;
const int  compiler_pl_clang = __clang_patchlevel__;
#define compiler_ver_fmt_clang  "%d.%d.%d"

#ifndef USE_COMPILER_ID
#define USE_COMPILER_ID      compiler_id_clang
#define USE_COMPILER_VALUE   compiler_value_clang
#define USE_COMPILER_NAME    compiler_name_clang
#define USE_COMPILER_VER     compiler_ver_clang
#define USE_COMPILER_REV     compiler_rev_clang
#define USE_COMPILER_PL      compiler_pl_clang
#define USE_COMPILER_VER_FMT compiler_ver_fmt_clang
#else
#define USE_COMPILER_ID2     compiler_id_clang
#define USE_COMPILER_VALUE2  compiler_value_clang
#define USE_COMPILER_NAME2   compiler_name_clang
#define USE_COMPILER_VER2    compiler_ver_clang
#define USE_COMPILER_REV2    compiler_rev_clang
#define USE_COMPILER_PL2     compiler_pl_clang
#define USE_SHORTVER_FMT2    compiler_ver_fmt_clang
#endif

#ifdef __clang_version__
const char version_id_clang_ver[] = "__clang_version__";
const char *version_value_clang_ver = __clang_version__;
#define version_fmt_clang_ver  "\"%s\""
#ifndef USE_VERSION_ID
#define USE_VERSION_ID     version_id_clang_ver
#define USE_VERSION_VALUE  version_value_clang_ver
#define USE_VERSION_FMT    version_fmt_clang_ver
#else
#define USE_VERSION_ID2    version_id_clang_ver
#define USE_VERSION_VALUE2 version_value_clang_ver
#define USE_VERSION_FMT2   version_fmt_clang_ver
#endif
#endif  /* end of __clang_version__ */

#ifdef __VERSION__
const char version_id_clang[] = "__VERSION__";
const char *version_value_clang = __VERSION__;
#define version_fmt_clang  "\"%s\""
#ifndef USE_VERSION_ID
#define USE_VERSION_ID     version_id_clang
#define USE_VERSION_VALUE  version_value_clang
#define USE_VERSION_FMT    version_fmt_clang
#else
#ifndef USE_VERSION_ID2
#define USE_VERSION_ID2    version_id_clang
#define USE_VERSION_VALUE2 version_value_clang
#define USE_VERSION_FMT2   version_fmt_clang
#else
#define USE_VERSION_ID3    version_id_clang
#define USE_VERSION_VALUE3 version_value_clang
#define USE_VERSION_FMT3   version_fmt_clang
#endif
#endif
#endif  /* end of __VERSION__ */
#endif  /* end of __clang__ */


/* ############################# */
/* Check for __GNUC__ at the end */
/* some compiler are based on gcc */
/* or claim to be compatible with gcc */
/* examples: clang / llvm */
#ifdef __GNUC__
const char compiler_id_gnuc[] = "__GNUC__";
const unsigned long compiler_value_gnuc = __GNUC__;

#ifdef __GNUG__
const char compiler_name_gnuc[] = "g++";
#else
const char compiler_name_gnuc[] = "gcc";
#endif   /* end of __GNUG__ */
const int  compiler_ver_gnuc = __GNUC__;
const int  compiler_rev_gnuc = __GNUC_MINOR__;
#ifdef __GNUC_PATCHLEVEL__
const int  compiler_pl_gnuc = __GNUC_PATCHLEVEL__;
#define compiler_ver_fmt_gnuc  "%d.%d.%d"
#else
#define compiler_ver_fmt_gnuc  "%d.%d"
#endif   /* end of __GNUC_PATCHLEVE__ */

#ifndef USE_COMPILER_ID
#define USE_COMPILER_ID      compiler_id_gnuc
#define USE_COMPILER_VALUE   compiler_value_gnuc
#define USE_COMPILER_NAME    compiler_name_gnuc
#define USE_COMPILER_VER     compiler_ver_gnuc
#define USE_COMPILER_REV     compiler_rev_gnuc
#ifdef __GNUC_PATCHLEVEL__
#define USE_COMPILER_PL      compiler_pl_gnuc
#endif
#define USE_COMPILER_VER_FMT compiler_ver_fmt_gnuc
#else

#define USE_COMPILER_ID2     compiler_id_gnuc
#define USE_COMPILER_VALUE2  compiler_value_gnuc
#define USE_COMPILER_NAME2   compiler_name_gnuc
#define USE_COMPILER_VER2    compiler_ver_gnuc
#define USE_COMPILER_REV2    compiler_rev_gnuc
#ifdef __GNUC_PATCHLEVEL__
#define USE_COMPILER_PL2     compiler_pl_gnuc
#endif
#define USE_SHORTVER_FMT2    compiler_ver_fmt_gnuc
#endif


#ifdef __VERSION__
const char version_id_gcc[] = "__VERSION__";
const char *version_value_gcc = __VERSION__;
#define version_fmt_gcc    "\"%s\""
#ifndef USE_VERSION_ID
#define USE_VERSION_ID     version_id_gcc
#define USE_VERSION_VALUE  version_value_gcc
#define USE_VERSION_FMT    version_fmt_gcc
#else
#ifndef __clang__
#ifndef USE_VERSION_ID2
#define USE_VERSION_ID2    version_id_gcc
#define USE_VERSION_VALUE2 version_value_gcc
#define USE_VERSION_FMT2   version_fmt_gcc
#else
#define USE_VERSION_ID3    version_id_gcc
#define USE_VERSION_VALUE3 version_value_gcc
#define USE_VERSION_FMT3   version_fmt_gcc
#endif
#endif
#endif
#endif  /* end of __VERSION__ */

/* ia16-elf-gcc: gcc for DOS (16 bit) */
#ifdef __ia16__
const char version_id_ia16[] = "__ia16__";
const unsigned long version_value_ia16 = __ia16__;
#define version_fmt_ia16    "%lu"
#ifndef USE_VERSION_ID
#define USE_VERSION_ID     version_id_ia16
#define USE_VERSION_VALUE  version_value_ia16
#define USE_VERSION_FMT    version_fmt_ia16
#else
#ifndef USE_VERSION_ID2
#define USE_VERSION_ID2    version_id_ia16
#define USE_VERSION_VALUE2 version_value_ia16
#define USE_VERSION_FMT2   version_fmt_ia16
#else
#define USE_VERSION_ID3    version_id_ia16
#define USE_VERSION_VALUE3 version_value_ia16
#define USE_VERSION_FMT3   version_fmt_ia16
#endif
#endif
#endif  /* end of __ia16__ */

#endif   /* end of __GNUC__ */



/* ############################## */
/*
 * C / C++ standard detection:
 * C++: __cplusplus
 * C:   __STDC_VERSION__
 * all: __STDC__
 */

/* C++: __cplusplus */
#ifdef __cplusplus
const char std_id_cplusplus[] = "__cplusplus";
const unsigned long std_value_cplusplus = __cplusplus;
const char *std_name_cplusplus = \
        (__cplusplus >= 202303) ? "C++2z - C++26" :
        (__cplusplus >= 202302) ? "C++23" :
        (__cplusplus >= 202003) ? "C++2y - C++23" :
        (__cplusplus >= 202002) ? "C++20" :
        (__cplusplus >= 201703) ? "C++17" :
        (__cplusplus >= 201402) ? "C++14" :
        (__cplusplus >= 201103) ? "C++11" :
        (__cplusplus >= 200300) ? "C++03" :
        (__cplusplus >= 199711) ? "C++98" :
        "C++";

#define USE_STD_ID     std_id_cplusplus
#define USE_STD_VALUE  std_value_cplusplus
#define USE_STD_NAME   std_name_cplusplus
#endif  /* end of __cplusplus */


/* C: __STDC_VERSION__ */
#ifdef __STDC_VERSION__
const char std_id_STDC_VERSION[] = "__STDC_VERSION__";
const unsigned long std_value_STDC_VERSION = __STDC_VERSION__;
const char *std_name_STDC_VERSION = \
        (__STDC_VERSION__ >= 202312) ? "C2y" :
        (__STDC_VERSION__ >= 202311) ? "C23" :
        (__STDC_VERSION__ >= 201711) ? "C2x - C23" :
        (__STDC_VERSION__ >= 201710) ? "C17 / C18" :
        (__STDC_VERSION__ >= 201112) ? "C11" :
        (__STDC_VERSION__ >= 199901) ? "C99" :
        (__STDC_VERSION__ >= 199409) ? "C95" :
        "C89 / C90 / ANSI C";

#ifndef USE_STD_ID
#define USE_STD_ID     std_id_STDC_VERSION
#define USE_STD_VALUE  std_value_STDC_VERSION
#define USE_STD_NAME   std_name_STDC_VERSION
#else
#define USE_STD_ID2    std_id_STDC_VERSION
#define USE_STD_VALUE2 std_value_STDC_VERSION
#define USE_STD_NAME2  std_name_STDC_VERSION
#endif
#endif  /* end of __STDC_VERSION__ */


/* Lowest C standard (Also present in most C++ compiler): __STDC__ */
#ifdef __STDC__
/* Only __STDC__ without __STDC_VERSION__: that's C89:ANSI-C or C90:ISO-C */
const char std_id_STDC[] = "__STDC__";
const unsigned long std_value_STDC = (unsigned long) __STDC__ +0;
/* when we already have a name from __STDC_VERSION__, then hide the name from __STDC__ */
#ifndef __STDC_VERSION__
const char std_name_STDC[] = "C89 / C90 / ANSI C";
#endif
#ifndef USE_STD_ID
#define USE_STD_ID    std_id_STDC
#define USE_STD_VALUE std_value_STDC
#define USE_STD_NAME  std_name_STDC
#else
#ifndef USE_STD_ID2
#define USE_STD_ID2    std_id_STDC
#define USE_STD_VALUE2 std_value_STDC
/* when we already have a name from __STDC_VERSION__, then hide the name from __STDC__ */
#ifndef __STDC_VERSION__
#define USE_STD_NAME2  std_name_STDC
#endif
#else
#define USE_STD_ID3    std_id_STDC
#define USE_STD_VALUE3 std_value_STDC
/* when we already have a name from __STDC_VERSION__, then hide the name from __STDC__ */
#ifndef __STDC_VERSION__
#define USE_STD_NAME3  std_name_STDC
#endif
#endif
#endif
#endif  /* end of __STDC__ */


#ifdef __STDC_HOSTED__
const char std_id_STDC_HOSTED[] = "__STDC_HOSTED__";
const unsigned long std_value_STDC_HOSTED = __STDC_HOSTED__;
#if __STDC_HOSTED__
const char std_name_STDC_HOSTED[] = "hosted";
#else
const char std_name_STDC_HOSTED[] = "freestanding";
#endif
#ifndef USE_STD_ID
#define USE_STD_ID    std_id_STDC_HOSTED
#define USE_STD_VALUE std_value_STDC_HOSTED
#define USE_STD_NAME  std_name_STDC_HOSTED
#else
#ifndef USE_STD_ID2
#define USE_STD_ID2    std_id_STDC_HOSTED
#define USE_STD_VALUE2 std_value_STDC_HOSTED
#define USE_STD_NAME2  std_name_STDC_HOSTED
#else
#ifndef USE_STD_ID3
#define USE_STD_ID3    std_id_STDC_HOSTED
#define USE_STD_VALUE3 std_value_STDC_HOSTED
#define USE_STD_NAME3  std_name_STDC_HOSTED
#else
#define USE_STD_ID4    std_id_STDC_HOSTED
#define USE_STD_VALUE4 std_value_STDC_HOSTED
#define USE_STD_NAME4  std_name_STDC_HOSTED
#endif
#endif
#endif
#endif  /* end of __STD_HOSTED__ */



#ifdef __STRICT_ANSI__
const char std_id_STRICT_ANSI[] = "__STRICT_ANSI__";
const unsigned long std_value_STRICT_ANSI = __STRICT_ANSI__;
#ifndef USE_STD_ID
#define USE_STD_ID    std_id_STRICT_ANSI
#define USE_STD_VALUE std_value_STRICT_ANSI
#define USE_STD_NAME  std_name_STRICT_ANSI
#else
#ifndef USE_STD_ID2
#define USE_STD_ID2    std_id_STRICT_ANSI
#define USE_STD_VALUE2 std_value_STRICT_ANSI
#else
#ifndef USE_STD_ID3
#define USE_STD_ID3    std_id_STRICT_ANSI
#define USE_STD_VALUE3 std_value_STRICT_ANSI
#else
#ifndef USE_STD_ID4
#define USE_STD_ID4    std_id_STRICT_ANSI
#define USE_STD_VALUE4 std_value_STRICT_ANSI
#else
#define USE_STD_ID5    std_id_STRICT_ANSI
#define USE_STD_VALUE5 std_value_STRICT_ANSI
#endif
#endif
#endif
#endif
#endif  /* end of __STRICT_ANSI__ */


#ifdef __ANSI__
const char std_id_ANSI[] = "__ANSI__";
const unsigned long std_value_ANSI = __ANSI__;
#ifndef USE_STD_ID
#define USE_STD_ID    std_id_ANSI
#define USE_STD_VALUE std_value_ANSI
#define USE_STD_NAME  std_name_ANSI

#else
#ifndef USE_STD_ID2
#define USE_STD_ID2    std_id_ANSI
#define USE_STD_VALUE2 std_value_ANSI
#else
#ifndef USE_STD_ID3
#define USE_STD_ID3    std_id_ANSI
#define USE_STD_VALUE3 std_value_ANSI
#else
#ifndef USE_STD_ID4
#define USE_STD_ID4    std_id_ANSI
#define USE_STD_VALUE4 std_value_ANSI
#else
#ifndef USE_STD_ID5
#define USE_STD_ID5    std_id_ANSI
#define USE_STD_VALUE5 std_value_ANSI
#else
#define USE_STD_ID6    std_id_ANSI
#define USE_STD_VALUE6 std_value_ANSI
#endif
#endif
#endif
#endif
#endif
#endif  /* end of __ANSI__ */


/* ############################## */
/*
 * detect OS:
 */

/* primary os group: unix / bsd OS */
#ifdef __unix__
const char os_id___unix__[] = "__unix__";
const int  os_value___unix__ = __unix__;
#define USE_OSGROUP_ID    os_id___unix__
#define USE_OSGROUP_VALUE os_value___unix__
#endif


#ifdef __unix
const char os_id___unix[] = "__unix";
const int  os_value___unix = __unix;
#ifndef USE_OSGROUP_ID
#define USE_OSGROUP_ID     os_id___unix
#define USE_OSGROUP_VALUE  os_value___unix
#else
#define USE_OSGROUP_ID2    os_id___unix
#define USE_OSGROUP_VALUE2 os_value___unix
#endif /* end of USE_OSGROUP_ID */

/* OpenWatcom use uppcercase names */
#elif defined __UNIX__
const char os_id___UNIX__[] = "__UNIX__";
const int  os_value___UNIX__ = __UNIX__;
#ifndef USE_OSGROUP_ID
#define USE_OSGROUP_ID     os_id___UNIX__
#define USE_OSGROUP_VALUE  os_value___UNIX__
#else
#define USE_OSGROUP_ID2    os_id___UNIX__
#define USE_OSGROUP_VALUE2 os_value___UNIX__
#endif /* end of USE_OSGROUP_ID */
#endif /* end of __unix / __UNIX__ */


#ifdef BSD
const char os_id_BSD[] = "BSD";
const int  os_value_BSD = BSD;
#ifndef USE_OSGROUP_ID
#define USE_OSGROUP_ID     os_id_BSD
#define USE_OSGROUP_VALUE  os_value_BSD
#else
#ifndef USE_OSGROUP_ID2
#define USE_OSGROUP_ID2    os_id_BSD
#define USE_OSGROUP_VALUE2 os_value_BSD
#else
#define USE_OSGROUP_ID3    os_id_BSD
#define USE_OSGROUP_VALUE3 os_value_BSD
#endif /* end of USE_OSGROUP_ID2 */
#endif /* end of USE_OSGROUP_ID */
#endif /* end of BSD */


/* OS compatibility */
#ifdef _POSIX_
const char os_id__POSIX_[] = "_POSIX_";
const int  os_value__POSIX_ = _POSIX_;
#ifndef USE_OSGROUP_ID
#define USE_OSGROUP_ID     os_id__POSIX_
#define USE_OSGROUP_VALUE  os_value__POSIX_
#else
#ifndef USE_OSGROUP_ID2
#define USE_OSGROUP_ID2    os_id__POSIX_
#define USE_OSGROUP_VALUE2 os_value__POSIX_
#else
#ifndef USE_OSGROUP_ID3
#define USE_OSGROUP_ID3    os_id__POSIX_
#define USE_OSGROUP_VALUE3 os_value__POSIX_
#else
#define USE_OSGROUP_ID4    os_id__POSIX_
#define USE_OSGROUP_VALUE4 os_value__POSIX_
#endif /* end of USE_OSGROUP_ID3 */
#endif /* end of USE_OSGROUP_ID2 */
#endif /* end of USE_OSGROUP_ID */
#endif /* end of _POSIX_ */


#ifdef _POSIX_VERSION
const char os_id__POSIX_VERSION[] = "_POSIX_VERSION";
const int  os_value__POSIX_VERSION = _POSIX_VERSION;
#ifndef USE_OSGROUP_ID
#define USE_OSGROUP_ID     os_id__POSIX_VERSION
#define USE_OSGROUP_VALUE  os_value__POSIX_VERSION
#else
#ifndef USE_OSGROUP_ID2
#define USE_OSGROUP_ID2    os_id__POSIX_VERSION
#define USE_OSGROUP_VALUE2 os_value__POSIX_VERSION
#else
#ifndef USE_OSGROUP_ID3
#define USE_OSGROUP_ID3    os_id__POSIX_VERSION
#define USE_OSGROUP_VALUE3 os_value__POSIX_VERSION
#else
#ifndef USE_OSGROUP_ID4
#define USE_OSGROUP_ID4    os_id__POSIX_VERSION
#define USE_OSGROUP_VALUE4 os_value__POSIX_VERSION
#else
#define USE_OSGROUP_ID5    os_id__POSIX_VERSION
#define USE_OSGROUP_VALUE5 os_value__POSIX_VERSION
#endif
#endif
#endif
#endif
#endif /* end of _POSIX_VERSION */


#ifdef _POSIX2_C_VERSION
const char os_id__POSIX2_C_VERSION[] = "_POSIX2_C_VERSION";
const int  os_value__POSIX2_C_VERSION = _POSIX2_C_VERSION;
#ifndef USE_OSGROUP_ID
#define USE_OSGROUP_ID     os_id__POSIX2_C_VERSION
#define USE_OSGROUP_VALUE  os_value__POSIX2_C_VERSION
#else
#ifndef USE_OSGROUP_ID2
#define USE_OSGROUP_ID2    os_id__POSIX2_C_VERSION
#define USE_OSGROUP_VALUE2 os_value__POSIX2_C_VERSION
#else
#ifndef USE_OSGROUP_ID3
#define USE_OSGROUP_ID3    os_id__POSIX2_C_VERSION
#define USE_OSGROUP_VALUE3 os_value__POSIX2_C_VERSION
#else
#ifndef USE_OSGROUP_ID4
#define USE_OSGROUP_ID4    os_id__POSIX2_C_VERSION
#define USE_OSGROUP_VALUE4 os_value__POSIX2_C_VERSION
#else
#ifndef USE_OSGROUP_ID5
#define USE_OSGROUP_ID5    os_id__POSIX2_C_VERSION
#define USE_OSGROUP_VALUE5 os_value__POSIX2_C_VERSION
#else
#define USE_OSGROUP_ID6    os_id__POSIX2_C_VERSION
#define USE_OSGROUP_VALUE6 os_value__POSIX2_C_VERSION
#endif
#endif
#endif
#endif
#endif
#endif /* end of _POSIX2_C_VERSION */


#ifdef _XOPEN_VERSION
const char os_id__XOPEN_VERSION[] = "_XOPEN_VERSION";
const int  os_value__XOPEN_VERSION = _XOPEN_VERSION;
#ifndef USE_OSGROUP_ID
#define USE_OSGROUP_ID     os_id__XOPEN_VERSION
#define USE_OSGROUP_VALUE  os_value__XOPEN_VERSION
#else
#ifndef USE_OSGROUP_ID2
#define USE_OSGROUP_ID2    os_id__XOPEN_VERSION
#define USE_OSGROUP_VALUE2 os_value__XOPEN_VERSION
#else
#ifndef USE_OSGROUP_ID3
#define USE_OSGROUP_ID3    os_id__XOPEN_VERSION
#define USE_OSGROUP_VALUE3 os_value__XOPEN_VERSION
#else
#ifndef USE_OSGROUP_ID4
#define USE_OSGROUP_ID4    os_id__XOPEN_VERSION
#define USE_OSGROUP_VALUE4 os_value__XOPEN_VERSION
#else
#ifndef USE_OSGROUP_ID5
#define USE_OSGROUP_ID5    os_id__XOPEN_VERSION
#define USE_OSGROUP_VALUE5 os_value__XOPEN_VERSION
#else
#ifndef USE_OSGROUP_ID6
#define USE_OSGROUP_ID6    os_id__XOPEN_VERSION
#define USE_OSGROUP_VALUE6 os_value__XOPEN_VERSION
#else
#define USE_OSGROUP_ID7    os_id__XOPEN_VERSION
#define USE_OSGROUP_VALUE7 os_value__XOPEN_VERSION
#endif
#endif
#endif
#endif
#endif
#endif
#endif /* end of _XOPEN_VERSION */


/* ############################################### */
/* cosmopolitan / ape: actual portable executable  */
/* multi-os, multi-arch */
/* Linux, Windows, MacOS, FreeBSD, OpenBSD, NetBSD */

#ifdef __COSMOPOLITAN__
const char os_id_cosmopolitan[] = "__COSMOPOLITAN__";
const int os_value_cosmopolitan = __COSMOPOLITAN__;

#define USE_OS_ID      os_id_cosmopolitan
#define USE_OS_VALUE   os_value_cosmopolitan

const int  os_ver_cosmopolitan = __COSMOPOLITAN_MAJOR__;
const int  os_rev_cosmopolitan = __COSMOPOLITAN_MINOR__;
const int  os_pl_cosmopolitan  = __COSMOPOLITAN_PATCH__;
#define os_ver_fmt_cosmopolitan  "%d.%d.%d"
#define USE_OS_VER     os_ver_cosmopolitan
#define USE_OS_REV     os_rev_cosmopolitan
#define USE_OS_PL      os_pl_cosmopolitan
#define USE_OS_VER_FMT os_ver_fmt_cosmopolitan

#endif  /* end of __COSMOPOLITAN__ */


/* ############# */
/* unix subclass */
#ifdef __ANDROID__
const char os_id_ANDROID[] = "__ANDROID__";
const int  os_value_ANDROID = __ANDROID__;
#define USE_OS_ID     os_id_ANDROID
#define USE_OS_VALUE  os_value_ANDROID
#endif

#ifdef __linux__
const char os_id___linux__[] = "__linux__";
const int  os_value___linux__ = __linux__;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id___linux__
#define USE_OS_VALUE  os_value___linux__
#else
#define USE_OS_ID2    os_id___linux__
#define USE_OS_VALUE2 os_value___linux__
#endif
#endif

#ifdef __linux
const char os_id___linux[] = "__linux";
const int  os_value___linux = __linux;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id___linux
#define USE_OS_VALUE  os_value___linux
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2     os_id___linux
#define USE_OS_VALUE2  os_value___linux
#else
#define USE_OS_ID3     os_id___linux
#define USE_OS_VALUE3  os_value___linux
#endif
#endif
#endif

#ifdef _LINUX
const char os_id__LINUX[] = "_LINUX";
const int  os_value__LINUX = _LINUX;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id__LINUX
#define USE_OS_VALUE  os_value__LINUX
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2     os_id__LINUX
#define USE_OS_VALUE2  os_value__LINUX
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3     os_id__LINUX
#define USE_OS_VALUE3  os_value__LINUX
#else
#define USE_OS_ID4     os_id__LINUX
#define USE_OS_VALUE4  os_value__LINUX
#endif
#endif
#endif
#endif

/* OpenWatcom is using uppcercase defines */
#ifdef __LINUX__
const char os_id___LINUX__[] = "__LINUX__";
const int  os_value___LINUX__ = __LINUX__;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id___LINUX__
#define USE_OS_VALUE  os_value___LINUX__
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2     os_id___LINUX__
#define USE_OS_VALUE2  os_value___LINUX__
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3     os_id___LINUX__
#define USE_OS_VALUE3  os_value___LINUX__
#else
#define USE_OS_ID4     os_id___LINUX__
#define USE_OS_VALUE4  os_value___LINUX__
#endif
#endif
#endif
#endif


/* bsd subclass */
#ifdef __FreeBSD__
const char os_id___FreeBSD__[] = "__FreeBSD__";
const int  os_value___FreeBSD__ = __FreeBSD__;
#define USE_OS_ID     os_id___FreeBSD__
#define USE_OS_VALUE  os_value___FreeBSD__
#endif

#ifdef __FreeBSD
const char os_id___FreeBSD[] = "__FreeBSD";
const int  os_value___FreeBSD = __FreeBSD;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id___FreeBSD
#define USE_OS_VALUE  os_value___FreeBSD
#else
#define USE_OS_ID2     os_id___FreeBSD
#define USE_OS_VALUE2  os_value___FreeBSD
#endif
#endif


/* ############################ */
/* Windows is still widely used */
#ifdef _WIN64
const char os_id__WIN64[] = "_WIN64";
const int  os_value__WIN64 = _WIN64;
#define USE_OS_ID     os_id__WIN64
#define USE_OS_VALUE  os_value__WIN64
#endif

#ifdef _WIN32
const char os_id__WIN32[] = "_WIN32";
const int  os_value__WIN32 = _WIN32;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id__WIN32
#define USE_OS_VALUE  os_value__WIN32
#else
#define USE_OS_ID2    os_id__WIN32
#define USE_OS_VALUE2 os_value__WIN32
#endif
#endif

#ifdef __WIN32__
const char os_id___WIN32__[] = "__WIN32__";
const int  os_value___WIN32__ = __WIN32__;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id___WIN32__
#define USE_OS_VALUE  os_value___WIN32__
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id___WIN32__
#define USE_OS_VALUE2 os_value___WIN32__
#else
#define USE_OS_ID3    os_id___WIN32__
#define USE_OS_VALUE3 os_value___WIN32__
#endif
#endif
#endif


#ifdef _WIN16
const char os_id__WIN16[] = "_WIN16";
const int  os_value__WIN16 = _WIN16;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id__WIN16
#define USE_OS_VALUE  os_value__WIN16
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id__WIN16
#define USE_OS_VALUE2 os_value__WIN16
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3    os_id__WIN16
#define USE_OS_VALUE3 os_value__WIN16
#else
#define USE_OS_ID4    os_id__WIN16
#define USE_OS_VALUE4 os_value__WIN16
#endif
#endif
#endif
#endif  /* end of _WIN16 */



#ifdef __WINDOWS__
const char os_id___WINDOWS__[] = "__WINDOWS__";
const int  os_value___WINDOWS__ = __WINDOWS__;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id___WINDOWS__
#define USE_OS_VALUE  os_value___WINDOWS__
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id___WINDOWS__
#define USE_OS_VALUE2 os_value___WINDOWS__
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3    os_id___WINDOWS__
#define USE_OS_VALUE3 os_value___WINDOWS__
#else
#ifndef USE_OS_ID4
#define USE_OS_ID4    os_id___WINDOWS__
#define USE_OS_VALUE4 os_value___WINDOWS__
#else
#define USE_OS_ID5    os_id___WINDOWS__
#define USE_OS_VALUE5 os_value___WINDOWS__
#endif
#endif
#endif
#endif
#endif  /* end of __WINDOWS__ */


#ifdef _WINDOWS
const char os_id__WINDOWS[] = "_WINDOWS";
const int  os_value__WINDOWS = _WINDOWS;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id__WINDOWS
#define USE_OS_VALUE  os_value__WINDOWS
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id__WINDOWS
#define USE_OS_VALUE2 os_value__WINDOWS
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3    os_id__WINDOWS
#define USE_OS_VALUE3 os_value__WINDOWS
#else
#ifndef USE_OS_ID4
#define USE_OS_ID4    os_id__WINDOWS
#define USE_OS_VALUE4 os_value__WINDOWS
#else
#ifndef USE_OS_ID5
#define USE_OS_ID5    os_id__WINDOWS
#define USE_OS_VALUE5 os_value__WINDOWS
#else
#define USE_OS_ID6    os_id__WINDOWS
#define USE_OS_VALUE6 os_value__WINDOWS
#endif
#endif
#endif
#endif
#endif
#endif  /* end of _WINDOWS */



/* ##################################### */
/* DOS: 640k is enough for everybody :-) */
#ifdef __MSDOS__
const char os_id___MSDOS__[] = "__MSDOS__";
const int  os_value___MSDOS__ = __MSDOS__;
#define USE_OS_ID     os_id___MSDOS__
#define USE_OS_VALUE  os_value___MSDOS__
#endif

#ifdef _MSDOS
const char os_id__MSDOS[] = "_MSDOS";
const int  os_value__MSDOS = _MSDOS;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id__MSDOS
#define USE_OS_VALUE  os_value__MSDOS
#else
#define USE_OS_ID2    os_id__MSDOS
#define USE_OS_VALUE2 os_value__MSDOS
#endif
#endif

/* used by __WATCOMC__ */
#ifdef __DOS__
const char os_id___DOS__[] = "__DOS__";
const int  os_value___DOS__ = __DOS__;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id___DOS__
#define USE_OS_VALUE  os_value___DOS__
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id___DOS__
#define USE_OS_VALUE2 os_value___DOS__
#else
#define USE_OS_ID3    os_id___DOS__
#define USE_OS_VALUE3 os_value___DOS__
#endif
#endif
#endif


/* used by __SMALLER_C__ */
#ifdef _DOS
const char os_id__DOS[] = "_DOS";
const int  os_value__DOS = _DOS;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id__DOS
#define USE_OS_VALUE  os_value__DOS
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id__DOS
#define USE_OS_VALUE2 os_value__DOS
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3    os_id__DOS
#define USE_OS_VALUE3 os_value__DOS
#else
#define USE_OS_ID4    os_id__DOS
#define USE_OS_VALUE4 os_value__DOS
#endif
#endif
#endif
#endif

/* DOS Protected Mode Interface.  */
#ifdef _DPMI
const char os_id__DPMI[] = "_DPMI";
const int  os_value__DPMI = _DPMI;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id__DPMI
#define USE_OS_VALUE  os_value__DPMI
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id__DPMI
#define USE_OS_VALUE2 os_value__DPMI
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3    os_id__DPMI
#define USE_OS_VALUE3 os_value__DPMI
#else
#ifndef USE_OS_ID4
#define USE_OS_ID4    os_id__DPMI
#define USE_OS_VALUE4 os_value__DPMI
#else
#define USE_OS_ID5    os_id__DPMI
#define USE_OS_VALUE5 os_value__DPMI
#endif
#endif
#endif
#endif
#endif


#ifdef __DPMI32__
const char os_id___DPMI32__[] = "__DPMI32__";
const int  os_value___DPMI32__ = __DPMI32__;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id___DPMI32__
#define USE_OS_VALUE  os_value___DPMI32__
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id___DPMI32__
#define USE_OS_VALUE2 os_value___DPMI32__
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3    os_id___DPMI32__
#define USE_OS_VALUE3 os_value___DPMI32__
#else
#ifndef USE_OS_ID4
#define USE_OS_ID4    os_id___DPMI32__
#define USE_OS_VALUE4 os_value___DPMI32__
#else
#define USE_OS_ID5    os_id___DPMI32__
#define USE_OS_VALUE5 os_value___DPMI32__
#endif
#endif
#endif
#endif
#endif


/* Various DOS Extender */
#ifdef CAUSEWAY
const char os_id_CAUSEWAY[] = "CAUSEWAY";
const int  os_value_CAUSEWAY = CAUSEWAY;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id_CAUSEWAY
#define USE_OS_VALUE  os_value_CAUSEWAY
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id_CAUSEWAY
#define USE_OS_VALUE2 os_value_CAUSEWAY
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3    os_id_CAUSEWAY
#define USE_OS_VALUE3 os_value_CAUSEWAY
#else
#ifndef USE_OS_ID4
#define USE_OS_ID4    os_id_CAUSEWAY
#define USE_OS_VALUE4 os_value_CAUSEWAY
#else
#define USE_OS_ID5    os_id_CAUSEWAY
#define USE_OS_VALUE5 os_value_CAUSEWAY
#endif
#endif
#endif
#endif
#endif

#ifdef __CAUSEWAY__
const char os_id___CAUSEWAY__[] = "__CAUSEWAY__";
const int  os_value___CAUSEWAY__ = __CAUSEWAY__;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id___CAUSEWAY__
#define USE_OS_VALUE  os_value___CAUSEWAY__
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id___CAUSEWAY__
#define USE_OS_VALUE2 os_value___CAUSEWAY__
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3    os_id___CAUSEWAY__
#define USE_OS_VALUE3 os_value___CAUSEWAY__
#else
#ifndef USE_OS_ID4
#define USE_OS_ID4    os_id___CAUSEWAY__
#define USE_OS_VALUE4 os_value___CAUSEWAY__
#else
#define USE_OS_ID5    os_id___CAUSEWAY__
#define USE_OS_VALUE5 os_value___CAUSEWAY__
#endif
#endif
#endif
#endif
#endif

#ifdef DOS4G
const char os_id_DOS4G[] = "DOS4G";
const int  os_value_DOS4G = DOS4G;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id_DOS4G
#define USE_OS_VALUE  os_value_DOS4G
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id_DOS4G
#define USE_OS_VALUE2 os_value_DOS4G
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3    os_id_DOS4G
#define USE_OS_VALUE3 os_value_DOS4G
#else
#ifndef USE_OS_ID4
#define USE_OS_ID4    os_id_DOS4G
#define USE_OS_VALUE4 os_value_DOS4G
#else
#define USE_OS_ID5    os_id_DOS4G
#define USE_OS_VALUE5 os_value_DOS4G
#endif
#endif
#endif
#endif
#endif

#ifdef __DOS4G__
const char os_id___DOS4G__[] = "__DOS4G__";
const int  os_value___DOS4G__ = __DOS4G__;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id___DOS4G__
#define USE_OS_VALUE  os_value___DOS4G__
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id___DOS4G__
#define USE_OS_VALUE2 os_value___DOS4G__
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3    os_id___DOS4G__
#define USE_OS_VALUE3 os_value___DOS4G__
#else
#ifndef USE_OS_ID4
#define USE_OS_ID4    os_id___DOS4G__
#define USE_OS_VALUE4 os_value___DOS4G__
#else
#define USE_OS_ID5    os_id___DOS4G__
#define USE_OS_VALUE5 os_value___DOS4G__
#endif
#endif
#endif
#endif
#endif


#ifdef DOSX
const char os_id_DOSX[] = "DOSX";
const int  os_value_DOSX = DOSX;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id_DOSX
#define USE_OS_VALUE  os_value_DOSX
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id_DOSX
#define USE_OS_VALUE2 os_value_DOSX
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3    os_id_DOSX
#define USE_OS_VALUE3 os_value_DOSX
#else
#ifndef USE_OS_ID4
#define USE_OS_ID4    os_id_DOSX
#define USE_OS_VALUE4 os_value_DOSX
#else
#define USE_OS_ID5    os_id_DOSX
#define USE_OS_VALUE5 os_value_DOSX
#endif
#endif
#endif
#endif
#endif

#ifdef DOSX286
const char os_id_DOSX286[] = "DOSX286";
const int  os_value_DOSX286 = DOSX286;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id_DOSX286
#define USE_OS_VALUE  os_value_DOSX286
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id_DOSX286
#define USE_OS_VALUE2 os_value_DOSX286
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3    os_id_DOSX286
#define USE_OS_VALUE3 os_value_DOSX286
#else
#ifndef USE_OS_ID4
#define USE_OS_ID4    os_id_DOSX286
#define USE_OS_VALUE4 os_value_DOSX286
#else
#define USE_OS_ID5    os_id_DOSX286
#define USE_OS_VALUE5 os_value_DOSX286
#endif
#endif
#endif
#endif
#endif



#ifdef __DOS_386__
const char os_id___DOS_386__[] = "__DOS_386__";
const int  os_value___DOS_386__ = __DOS_386__;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id___DOS_386__
#define USE_OS_VALUE  os_value___DOS_386__
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id___DOS_386__
#define USE_OS_VALUE2 os_value___DOS_386__
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3    os_id___DOS_386__
#define USE_OS_VALUE3 os_value___DOS_386__
#else
#ifndef USE_OS_ID4
#define USE_OS_ID4    os_id___DOS_386__
#define USE_OS_VALUE4 os_value___DOS_386__
#else
#define USE_OS_ID5    os_id___DOS_386__
#define USE_OS_VALUE5 os_value___DOS_386__
#endif
#endif
#endif
#endif
#endif


#ifdef PHARLAP
const char os_id_PHARLAP[] = "PHARLAP";
const int  os_value_PHARLAP = PHARLAP;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id_PHARLAP
#define USE_OS_VALUE  os_value_PHARLAP
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id_PHARLAP
#define USE_OS_VALUE2 os_value_PHARLAP
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3    os_id_PHARLAP
#define USE_OS_VALUE3 os_value_PHARLAP
#else
#ifndef USE_OS_ID4
#define USE_OS_ID4    os_id_PHARLAP
#define USE_OS_VALUE4 os_value_PHARLAP
#else
#define USE_OS_ID5    os_id_PHARLAP
#define USE_OS_VALUE5 os_value_PHARLAP
#endif
#endif
#endif
#endif
#endif

#ifdef __PHARLAP__
const char os_id___PHARLAP__[] = "__PHARLAP__";
const int  os_value___PHARLAP__ = __PHARLAP__;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id___PHARLAP__
#define USE_OS_VALUE  os_value___PHARLAP__
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id___PHARLAP__
#define USE_OS_VALUE2 os_value___PHARLAP__
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3    os_id___PHARLAP__
#define USE_OS_VALUE3 os_value___PHARLAP__
#else
#ifndef USE_OS_ID4
#define USE_OS_ID4    os_id___PHARLAP__
#define USE_OS_VALUE4 os_value___PHARLAP__
#else
#define USE_OS_ID5    os_id___PHARLAP__
#define USE_OS_VALUE5 os_value___PHARLAP__
#endif
#endif
#endif
#endif
#endif

#ifdef PMODE
const char os_id_PMODE[] = "PMODE";
const int  os_value_PMODE = PMODE;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id_PMODE
#define USE_OS_VALUE  os_value_PMODE
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id_PMODE
#define USE_OS_VALUE2 os_value_PMODE
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3    os_id_PMODE
#define USE_OS_VALUE3 os_value_PMODE
#else
#ifndef USE_OS_ID4
#define USE_OS_ID4    os_id_PMODE
#define USE_OS_VALUE4 os_value_PMODE
#else
#define USE_OS_ID5    os_id_PMODE
#define USE_OS_VALUE5 os_value_PMODE
#endif
#endif
#endif
#endif
#endif


#ifdef PMODEW
const char os_id_PMODEW[] = "PMODEW";
const int  os_value_PMODEW = PMODEW;
#ifndef USE_OS_ID
#define USE_OS_ID     os_id_PMODEW
#define USE_OS_VALUE  os_value_PMODEW
#else
#ifndef USE_OS_ID2
#define USE_OS_ID2    os_id_PMODEW
#define USE_OS_VALUE2 os_value_PMODEW
#else
#ifndef USE_OS_ID3
#define USE_OS_ID3    os_id_PMODEW
#define USE_OS_VALUE3 os_value_PMODEW
#else
#ifndef USE_OS_ID4
#define USE_OS_ID4    os_id_PMODEW
#define USE_OS_VALUE4 os_value_PMODEW
#else
#define USE_OS_ID5    os_id_PMODEW
#define USE_OS_VALUE5 os_value_PMODEW
#endif
#endif
#endif
#endif
#endif


/* ToDo: The 6502 compiler supports many OS */


/* ############################## */
/*
 * detect Processor architecture:
 */

/* 64 bit */
#ifdef __amd64__
const char arch_id___amd64__[] = "__amd64__";
const int  arch_value___amd64__ = __amd64__;
#define USE_ARCH_ID     arch_id___amd64__
#define USE_ARCH_VALUE  arch_value___amd64__
#endif


#ifdef __amd64
const char arch_id___amd64[] = "__amd64";
const int  arch_value___amd64 = __amd64;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___amd64
#define USE_ARCH_VALUE  arch_value___amd64
#else
#define USE_ARCH_ID2     arch_id___amd64
#define USE_ARCH_VALUE2  arch_value___amd64
#endif
#endif


#ifdef __x86_64__
const char arch_id___x86_64__[] = "__x86_64__";
const int  arch_value___x86_64__ = __x86_64__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___x86_64__
#define USE_ARCH_VALUE  arch_value___x86_64__
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2     arch_id___x86_64__
#define USE_ARCH_VALUE2  arch_value___x86_64__
#else
#define USE_ARCH_ID3     arch_id___x86_64__
#define USE_ARCH_VALUE3  arch_value___x86_64__
#endif
#endif
#endif


#ifdef __x86_64
const char arch_id___x86_64[] = "__x86_64";
const int  arch_value___x86_64 = __x86_64;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___x86_64
#define USE_ARCH_VALUE  arch_value___x86_64
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2     arch_id___x86_64
#define USE_ARCH_VALUE2  arch_value___x86_64
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3     arch_id___x86_64
#define USE_ARCH_VALUE3  arch_value___x86_64
#else
#define USE_ARCH_ID4     arch_id___x86_64
#define USE_ARCH_VALUE4  arch_value___x86_64
#endif
#endif
#endif
#endif


/* DOS/Windows Compiler use a different naming */
#ifdef _M_AMD64
const char arch_id__M_AMD64[] = "_M_AMD64";
const int  arch_value__M_AMD64 = _M_AMD64;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id__M_AMD64
#define USE_ARCH_VALUE  arch_value__M_AMD64
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2     arch_id__M_AMD64
#define USE_ARCH_VALUE2  arch_value__M_AMD64
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3     arch_id__M_AMD64
#define USE_ARCH_VALUE3  arch_value__M_AMD64
#else
#ifndef USE_ARCH_ID4
#define USE_ARCH_ID4     arch_id__M_AMD64
#define USE_ARCH_VALUE4  arch_value__M_AMD64
#else
#define USE_ARCH_ID5     arch_id__M_AMD64
#define USE_ARCH_VALUE5  arch_value__M_AMD64
#endif
#endif
#endif
#endif
#endif


#ifdef _M_X64
const char arch_id__M_X64[] = "_M_X64";
const int  arch_value__M_X64 = _M_X64;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id__M_X64
#define USE_ARCH_VALUE  arch_value__M_X64
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2     arch_id__M_X64
#define USE_ARCH_VALUE2  arch_value__M_X64
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3     arch_id__M_X64
#define USE_ARCH_VALUE3  arch_value__M_X64
#else
#ifndef USE_ARCH_ID4
#define USE_ARCH_ID4     arch_id__M_X64
#define USE_ARCH_VALUE4  arch_value__M_X64
#else
#ifndef USE_ARCH_ID5
#define USE_ARCH_ID5     arch_id__M_X64
#define USE_ARCH_VALUE5  arch_value__M_X64
#else
#define USE_ARCH_ID6     arch_id__M_X64
#define USE_ARCH_VALUE6  arch_value__M_X64
#endif
#endif
#endif
#endif
#endif
#endif


/* 32 bit */
/* Used by clang, GCC, MinGw, TCC, ... */
#ifdef __i686__
const char arch_id___i686__[] = "__i686__";
const int  arch_value___i686__ = __i686__;
#define USE_ARCH_ID     arch_id___i686__
#define USE_ARCH_VALUE  arch_value___i686__
#elif defined __i586__
const char arch_id___i586__[] = "__i586__";
const int  arch_value___i586__ = __i586__;
#define USE_ARCH_ID     arch_id___i586__
#define USE_ARCH_VALUE  arch_value___i586__
#elif defined __i486__
const char arch_id___i486__[] = "__i486__";
const int  arch_value___i486__ = __i486__;
#define USE_ARCH_ID     arch_id___i486__
#define USE_ARCH_VALUE  arch_value___i486__
#endif /* ifdef __i686__ */

/* Used by clang, GCC, MinGw, TCC, ... */
#ifdef __i386__
const char arch_id___i386__[] = "__i386__";
const int  arch_value___i386__ = __i386__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___i386__
#define USE_ARCH_VALUE  arch_value___i386__
#else
#define USE_ARCH_ID2     arch_id___i386__
#define USE_ARCH_VALUE2  arch_value___i386__
#endif /* ifndef USE_ARCH_ID */

/* Used by Sun Studio, VOS C, ... */
#elif defined __i386
const char arch_id___i386[] = "__i386";
const int  arch_value___i386 = __i386;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___i386
#define USE_ARCH_VALUE  arch_value___i386
#else
#define USE_ARCH_ID2     arch_id___i386
#define USE_ARCH_VALUE2  arch_value___i386
#endif /* ifndef USE_ARCH_ID */

#elif defined __i286__
const char arch_id___i286__[] = "__i286__";
const int  arch_value___i286__ = __i286__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___i286__
#define USE_ARCH_VALUE  arch_value___i286__
#else
#define USE_ARCH_ID2     arch_id___i286__
#define USE_ARCH_VALUE2  arch_value___i286__
#endif /* ifndef USE_ARCH_ID */

#elif defined __i86__
const char arch_id___i86__[] = "__i86__";
const int  arch_value___i86__ = __i86__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___i86__
#define USE_ARCH_VALUE  arch_value___i86__
#else
#define USE_ARCH_ID2     arch_id___i86__
#define USE_ARCH_VALUE2  arch_value___i86__
#endif /* ifndef USE_ARCH_ID */
#endif /* ifdef __3686__ */


/* Used by Digital Mars */
#ifdef __I86__
const char arch_id___I86__[] = "__I86__";
const int  arch_value___I86__ = __I86__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___I86__
#define USE_ARCH_VALUE  arch_value___I86__
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2     arch_id___I86__
#define USE_ARCH_VALUE2  arch_value___I86__
#else
#define USE_ARCH_ID3     arch_id___I86__
#define USE_ARCH_VALUE3  arch_value___I86__
#endif /* ifndef USE_ARCH_ID2 */
#endif /* ifndef USE_ARCH_ID */
#endif /* ifdef __I86__ */


/* Used by OpenWatcom */
#ifdef __X86__
const char arch_id___X86__[] = "__X86__";
const int  arch_value___X86__ = __X86__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___X86__
#define USE_ARCH_VALUE  arch_value___X86__
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2     arch_id___X86__
#define USE_ARCH_VALUE2  arch_value___X86__
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3     arch_id___X86__
#define USE_ARCH_VALUE3  arch_value___X86__
#else
#define USE_ARCH_ID4     arch_id___X86__
#define USE_ARCH_VALUE4  arch_value___X86__
#endif /* ifndef USE_ARCH_ID3 */
#endif /* ifndef USE_ARCH_ID2 */
#endif /* ifndef USE_ARCH_ID */

/* Used by clang, GCC, MinGW, ... */
#elif defined _X86_
const char arch_id__X86_[] = "_X86_";
const int  arch_value__X86_ = _X86_;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id__X86_
#define USE_ARCH_VALUE  arch_value__X86_
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2     arch_id__X86_
#define USE_ARCH_VALUE2  arch_value__X86_
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3     arch_id__X86_
#define USE_ARCH_VALUE3  arch_value__X86_
#else
#define USE_ARCH_ID4     arch_id__X86_
#define USE_ARCH_VALUE4  arch_value__X86_
#endif /* ifndef USE_ARCH_ID3 */
#endif /* ifndef USE_ARCH_ID2 */
#endif /* ifndef USE_ARCH_ID */
#endif /* ifdef __I86__ */

/* Used for 32bit targets by MSVC, Intel C/C++, Digital Mars, OpenWatcom, ... */
#ifdef _M_IX86
const char arch_id__M_IX86[] = "_M_IX86";
const int  arch_value__M_IX86 = _M_IX86;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id__M_IX86
#define USE_ARCH_VALUE  arch_value__M_IX86
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2     arch_id__M_IX86
#define USE_ARCH_VALUE2  arch_value__M_IX86
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3     arch_id__M_IX86
#define USE_ARCH_VALUE3  arch_value__M_IX86
#else
#ifndef USE_ARCH_ID4
#define USE_ARCH_ID4     arch_id__M_IX86
#define USE_ARCH_VALUE4  arch_value__M_IX86
#else
#define USE_ARCH_ID5     arch_id__M_IX86
#define USE_ARCH_VALUE5  arch_value__M_IX86
#endif /* ifndef USE_ARCH_ID4 */
#endif /* ifndef USE_ARCH_ID3 */
#endif /* ifndef USE_ARCH_ID2 */
#endif /* ifndef USE_ARCH_ID */
#endif /* ifdef _M_IX86 */


/* Used for 16bit targets by MSVC, Digital Mars, OpenWatcom, ... */
#ifdef _M_I86
const char arch_id__M_I86[] = "_M_I86";
const int  arch_value__M_I86 = _M_I86;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id__M_I86
#define USE_ARCH_VALUE  arch_value__M_I86
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2     arch_id__M_I86
#define USE_ARCH_VALUE2  arch_value__M_I86
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3     arch_id__M_I86
#define USE_ARCH_VALUE3  arch_value__M_I86
#else
#ifndef USE_ARCH_ID4
#define USE_ARCH_ID4     arch_id__M_I86
#define USE_ARCH_VALUE4  arch_value__M_I86
#else
#ifndef USE_ARCH_ID5
#define USE_ARCH_ID5     arch_id__M_I86
#define USE_ARCH_VALUE5  arch_value__M_I86
#else
#define USE_ARCH_ID6     arch_id__M_I86
#define USE_ARCH_VALUE6  arch_value__M_I86
#endif /* ifndef USE_ARCH_ID5 */
#endif /* ifndef USE_ARCH_ID4 */
#endif /* ifndef USE_ARCH_ID3 */
#endif /* ifndef USE_ARCH_ID2 */
#endif /* ifndef USE_ARCH_ID */
#endif /* ifdef _M_I86 */


/* Is this in use? */
#ifdef _M_X86
const char arch_id__M_X86[] = "_M_X86";
const int  arch_value__M_X86 = _M_X86;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id__M_X86
#define USE_ARCH_VALUE  arch_value__M_X86
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2     arch_id__M_X86
#define USE_ARCH_VALUE2  arch_value__M_X86
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3     arch_id__M_X86
#define USE_ARCH_VALUE3  arch_value__M_X86
#else
#ifndef USE_ARCH_ID4
#define USE_ARCH_ID4     arch_id__M_X86
#define USE_ARCH_VALUE4  arch_value__M_X86
#else
#ifndef USE_ARCH_ID5
#define USE_ARCH_ID5     arch_id__M_X86
#define USE_ARCH_VALUE5  arch_value__M_X86
#else
#ifndef USE_ARCH_ID6
#define USE_ARCH_ID6     arch_id__M_X86
#define USE_ARCH_VALUE6  arch_value__M_X86
#else
#define USE_ARCH_ID7     arch_id__M_IX86
#define USE_ARCH_VALUE7  arch_value__M_IX86
#endif /* ifndef USE_ARCH_ID6 */
#endif /* ifndef USE_ARCH_ID5 */
#endif /* ifndef USE_ARCH_ID4 */
#endif /* ifndef USE_ARCH_ID3 */
#endif /* ifndef USE_ARCH_ID2 */
#endif /* ifndef USE_ARCH_ID */
#endif /* ifdef _M_X86 */


/* ########## */
/* 64 bit ARM */
#ifdef __aarch64__
const char arch_id___aarch64__[] = "__aarch64__";
const int  arch_value___aarch64__ = __aarch64__;
#define USE_ARCH_ID     arch_id___aarch64__
#define USE_ARCH_VALUE  arch_value___aarch64__
#endif

#ifdef _M_ARM64
const char arch_id__M_ARM64[] = "_M_ARM64";
const int  arch_value__M_ARM64 = _M_ARM64;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id__M_ARM64
#define USE_ARCH_VALUE  arch_value__M_ARM64
#else
#define USE_ARCH_ID2    arch_id__M_ARM64
#define USE_ARCH_VALUE2 arch_value__M_ARM64
#endif /* ifndef USE_ARCH_ID */

/* Used my MSVC for ARM64 with x86_64 emulation */
#elif defined _M_ARM64EC
const char arch_id__M_ARM64EC[] = "_M_ARM64EC";
const int  arch_value__M_ARM64EC = _M_ARM64EC;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id__M_ARM64EC
#define USE_ARCH_VALUE  arch_value__M_ARM64EC
#else
#define USE_ARCH_ID2    arch_id__M_ARM64EC
#define USE_ARCH_VALUE2 arch_value__M_ARM64EC
#endif /* ifndef USE_ARCH_ID */
#endif /* ifdef _M_ARM64 */


/* 32 bit ARM */
#ifdef __arm__
const char arch_id___arm__[] = "__arm__";
const int  arch_value___arm__ = __arm__;
#define USE_ARCH_ID     arch_id___arm__
#define USE_ARCH_VALUE  arch_value___arm__
#endif

#ifdef _M_ARM
const char arch_id__M_ARM[] = "_M_ARM";
const int  arch_value__M_ARM = _M_ARM;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id__M_ARM
#define USE_ARCH_VALUE  arch_value__M_ARM
#else
#define USE_ARCH_ID2    arch_id__M_ARM
#define USE_ARCH_VALUE2 arch_value__M_ARM
#endif /* ifndef USE_ARCH_ID */
#endif /* ifdef _M_ARM */


#ifdef __thumb2__
const char arch_id___thumb2__[] = "__thumb2__";
const int  arch_value___thumb2__ = __thumb2__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___thumb2__
#define USE_ARCH_VALUE  arch_value___thumb2__
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2    arch_id___thumb2__
#define USE_ARCH_VALUE2 arch_value___thumb2__
#else
#define USE_ARCH_ID3    arch_id___thumb2__
#define USE_ARCH_VALUE3 arch_value___thumb2__
#endif /* ifndef USE_ARCH_ID2 */
#endif /* ifndef USE_ARCH_ID */
#endif /* ifdef __thumb2__ */


#ifdef __thumb__
const char arch_id___thumb__[] = "__thumb__";
const int  arch_value___thumb__ = __thumb__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___thumb__
#define USE_ARCH_VALUE  arch_value___thumb__
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2    arch_id___thumb__
#define USE_ARCH_VALUE2 arch_value___thumb__
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3    arch_id___thumb__
#define USE_ARCH_VALUE3 arch_value___thumb__
#else
#define USE_ARCH_ID4    arch_id___thumb__
#define USE_ARCH_VALUE4 arch_value___thumb__
#endif /* ifndef USE_ARCH_ID3 */
#endif /* ifndef USE_ARCH_ID2 */
#endif /* ifndef USE_ARCH_ID */
#endif /* ifdef __thumb2__ */


#ifdef __ARM_EABI__
const char arch_id___ARM_EABI__[] = "__ARM_EABI__";
const int  arch_value___ARM_EABI__ = __ARM_EABI__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___ARM_EABI__
#define USE_ARCH_VALUE  arch_value___ARM_EABI__
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2    arch_id___ARM_EABI__
#define USE_ARCH_VALUE2 arch_value___ARM_EABI__
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3    arch_id___ARM_EABI__
#define USE_ARCH_VALUE3 arch_value___ARM_EABI__
#else
#ifndef USE_ARCH_ID4
#define USE_ARCH_ID4    arch_id___ARM_EABI__
#define USE_ARCH_VALUE4 arch_value___ARM_EABI__
#else
#define USE_ARCH_ID5    arch_id___ARM_EABI__
#define USE_ARCH_VALUE5 arch_value___ARM_EABI__
#endif /* ifndef USE_ARCH_ID4 */
#endif /* ifndef USE_ARCH_ID3 */
#endif /* ifndef USE_ARCH_ID2 */
#endif /* ifndef USE_ARCH_ID */
#endif /* ifdef __ARM_EABI__ */


/* for 32 bit and 64 bit ARM */
#ifdef __ARM_ARCH
const char arch_id___ARM_ARCH[] = "__ARM_ARCH";
const int  arch_value___ARM_ARCH = __ARM_ARCH;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___ARM_ARCH
#define USE_ARCH_VALUE  arch_value___ARM_ARCH
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2    arch_id___ARM_ARCH
#define USE_ARCH_VALUE2 arch_value___ARM_ARCH
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3    arch_id___ARM_ARCH
#define USE_ARCH_VALUE3 arch_value___ARM_ARCH
#else
#ifndef USE_ARCH_ID4
#define USE_ARCH_ID4    arch_id___ARM_ARCH
#define USE_ARCH_VALUE4 arch_value___ARM_ARCH
#else
#ifndef USE_ARCH_ID5
#define USE_ARCH_ID5    arch_id___ARM_ARCH
#define USE_ARCH_VALUE5 arch_value___ARM_ARCH
#else
#define USE_ARCH_ID6    arch_id___ARM_ARCH
#define USE_ARCH_VALUE6 arch_value___ARM_ARCH
#endif /* ifndef USE_ARCH_ID5 */
#endif /* ifndef USE_ARCH_ID4 */
#endif /* ifndef USE_ARCH_ID3 */
#endif /* ifndef USE_ARCH_ID2 */
#endif /* ifndef USE_ARCH_ID */
#endif /* ifdef __ARM_EABI__ */



/* #### */
/* mips */
#ifdef __mips__
const char arch_id___mips__[] = "__mips__";
const int  arch_value___mips__ = __mips__;
#define USE_ARCH_ID     arch_id___mips__
#define USE_ARCH_VALUE  arch_value___mips__
#endif

#ifdef __MIPSEB__
const char arch_id___MIPSEB__[] = "__MIPSEB__";
const int  arch_value___MIPSEB__ = __MIPSEB__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___MIPSEB__
#define USE_ARCH_VALUE  arch_value___MIPSEB__
#else
#define USE_ARCH_ID2    arch_id___MIPSEB__
#define USE_ARCH_VALUE2 arch_value___MIPSEB__
#endif
#endif

#ifdef __MIPSEL__
const char arch_id___MIPSEL__[] = "__MIPSEL__";
const int  arch_value___MIPSEL__ = __MIPSEL__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___MIPSEL__
#define USE_ARCH_VALUE  arch_value___MIPSEL__
#else
#define USE_ARCH_ID2    arch_id___MIPSEL__
#define USE_ARCH_VALUE2 arch_value___MIPSEL__
#endif
#endif


#ifdef __mips
const char arch_id___mips[] = "__mips";
const int  arch_value___mips = __mips;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___mips
#define USE_ARCH_VALUE  arch_value___mips
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2    arch_id___mips
#define USE_ARCH_VALUE2 arch_value___mips
#else
#define USE_ARCH_ID3    arch_id___mips
#define USE_ARCH_VALUE3 arch_value___mips
#endif
#endif
#endif


/* OpenWatcom */
#ifdef __MIPS__
const char arch_id___MIPS__[] = "__MIPS__";
const int  arch_value___MIPS__ = __MIPS__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___MIPS__
#define USE_ARCH_VALUE  arch_value___MIPS__
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2    arch_id___MIPS__
#define USE_ARCH_VALUE2 arch_value___MIPS__
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3    arch_id___MIPS__
#define USE_ARCH_VALUE3 arch_value___MIPS__
#else
#define USE_ARCH_ID4    arch_id___MIPS__
#define USE_ARCH_VALUE4 arch_value___MIPS__
#endif
#endif
#endif
#endif


/* ############## */
/* 64 bit powerpc */
#ifdef __powerpc64__
const char arch_id___powerpc64__[] = "__powerpc64__";
const int  arch_value___powerpc64__ = __powerpc64__;
#define USE_ARCH_ID     arch_id___powerpc64__
#define USE_ARCH_VALUE  arch_value___powerpc64__
#endif

#ifdef __PPC64__
const char arch_id___PPC64__[] = "__PPC64__";
const int  arch_value___PPC64__ = __PPC64__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___PPC64__
#define USE_ARCH_VALUE  arch_value___PPC64__
#else
#define USE_ARCH_ID2    arch_id___PPC64__
#define USE_ARCH_VALUE2 arch_value___PPC64__
#endif
#endif

#ifdef _M_PPC64
const char arch_id__M_PPC64[] = "_M_PPC64";
const int  arch_value__M_PPC64 = _M_PPC64;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id__M_PPC64
#define USE_ARCH_VALUE  arch_value__M_PPC64
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2    arch_id__M_PPC64
#define USE_ARCH_VALUE2 arch_value__M_PPC64
#else
#define USE_ARCH_ID3    arch_id__M_PPC64
#define USE_ARCH_VALUE3 arch_value__M_PPC64
#endif
#endif
#endif


/* 32 bit powerpc */
#ifdef __powerpc__
const char arch_id___powerpc__[] = "__powerpc__";
const int  arch_value___powerpc__ = __powerpc__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___powerpc__
#define USE_ARCH_VALUE  arch_value___powerpc__
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2    arch_id___powerpc__
#define USE_ARCH_VALUE2 arch_value___powerpc__
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3    arch_id___powerpc__
#define USE_ARCH_VALUE3 arch_value___powerpc__
#else
#define USE_ARCH_ID4    arch_id___powerpc__
#define USE_ARCH_VALUE4 arch_value___powerpc__
#endif
#endif
#endif
#endif

#ifdef __ppc__
const char arch_id___ppc__[] = "__ppc__";
const int  arch_value___ppc__ = __ppc__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___ppc__
#define USE_ARCH_VALUE  arch_value___ppc__
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2    arch_id___ppc__
#define USE_ARCH_VALUE2 arch_value___ppc__
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3    arch_id___ppc__
#define USE_ARCH_VALUE3 arch_value___ppc__
#else
#ifndef USE_ARCH_ID4
#define USE_ARCH_ID4    arch_id___ppc__
#define USE_ARCH_VALUE4 arch_value___ppc__
#else
#define USE_ARCH_ID5    arch_id___ppc__
#define USE_ARCH_VALUE5 arch_value___ppc__
#endif
#endif
#endif
#endif
#endif

#ifdef __PPC__
const char arch_id___PPC__[] = "__PPC__";
const int  arch_value___PPC__ = __PPC__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___PPC__
#define USE_ARCH_VALUE  arch_value___PPC__
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2    arch_id___PPC__
#define USE_ARCH_VALUE2 arch_value___PPC__
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3    arch_id___PPC__
#define USE_ARCH_VALUE3 arch_value___PPC__
#else
#ifndef USE_ARCH_ID4
#define USE_ARCH_ID4    arch_id___PPC__
#define USE_ARCH_VALUE4 arch_value___PPC__
#else
#ifndef USE_ARCH_ID5
#define USE_ARCH_ID5    arch_id___PPC__
#define USE_ARCH_VALUE5 arch_value___PPC__
#else
#define USE_ARCH_ID6    arch_id___PPC__
#define USE_ARCH_VALUE6 arch_value___PPC__
#endif
#endif
#endif
#endif
#endif
#endif




#ifdef _M_PPC
const char arch_id__M_PPC[] = "_M_PPC";
const int  arch_value__M_PPC = _M_PPC;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id__M_PPC
#define USE_ARCH_VALUE  arch_value__M_PPC
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2    arch_id__M_PPC
#define USE_ARCH_VALUE2 arch_value__M_PPC
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3    arch_id__M_PPC
#define USE_ARCH_VALUE3 arch_value__M_PPC
#else
#ifndef USE_ARCH_ID4
#define USE_ARCH_ID4    arch_id__M_PPC
#define USE_ARCH_VALUE4 arch_value__M_PPC
#else
#ifndef USE_ARCH_ID5
#define USE_ARCH_ID5    arch_id__M_PPC
#define USE_ARCH_VALUE5 arch_value__M_PPC
#else
#ifndef USE_ARCH_ID6
#define USE_ARCH_ID6    arch_id__M_PPC
#define USE_ARCH_VALUE6 arch_value__M_PPC
#else
#define USE_ARCH_ID7    arch_id__M_PPC
#define USE_ARCH_VALUE7 arch_value__M_PPC
#endif
#endif
#endif
#endif
#endif
#endif
#endif


/* riscv */
#ifdef __riscv
const char arch_id___riscv[] = "__riscv";
const int  arch_value___riscv = __riscv;
#define USE_ARCH_ID     arch_id___riscv
#define USE_ARCH_VALUE  arch_value___riscv
#endif

#ifdef __riscv_xlen
const char arch_id___riscv_xlen[] = "__riscv_xlen";
const int  arch_value___riscv_xlen = __riscv_xlen;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___riscv_xlen
#define USE_ARCH_VALUE  arch_value___riscv_xlen
#else
#define USE_ARCH_ID2    arch_id___riscv_xlen
#define USE_ARCH_VALUE2 arch_value___riscv_xlen
#endif
#endif


/* s390 / zsystem family */
#ifdef __s390__
const char arch_id___s390__[] = "__s390__";
const int  arch_value___s390__ = __s390__;
#define USE_ARCH_ID     arch_id___s390__
#define USE_ARCH_VALUE  arch_value___s390__
#endif

#ifdef __s390x__
const char arch_id___s390x__[] = "__s390x__";
const int  arch_value___s390x__ = __s390x__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___s390x__
#define USE_ARCH_VALUE  arch_value___s390x__
#else
#define USE_ARCH_ID2    arch_id___s390x__
#define USE_ARCH_VALUE2 arch_value___s390x__
#endif
#endif

#ifdef __zarch__
const char arch_id___zarch__[] = "__zarch__";
const int  arch_value___zarch__ = __zarch__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___zarch__
#define USE_ARCH_VALUE  arch_value___zarch__
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2    arch_id___zarch__
#define USE_ARCH_VALUE2 arch_value___zarch__
#else
#define USE_ARCH_ID3    arch_id___zarch__
#define USE_ARCH_VALUE3 arch_value___zarch__
#endif
#endif
#endif

/* __ARCH__ is used in the __s390__ family */
#ifdef __ARCH__
const char arch_id___ARCH__[] = "__ARCH__";
const int  arch_value___ARCH__ = __ARCH__;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id___ARCH__
#define USE_ARCH_VALUE  arch_value___ARCH__
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2    arch_id___ARCH__
#define USE_ARCH_VALUE2 arch_value___ARCH__
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3    arch_id___ARCH__
#define USE_ARCH_VALUE3 arch_value___ARCH__
#else
#define USE_ARCH_ID4    arch_id___ARCH__
#define USE_ARCH_VALUE4 arch_value___ARCH__
#endif
#endif
#endif
#endif



/* MSVC can downgrade C and C++ to crl (common runtime library) */
/* CEE: common execution environment */
#ifdef _M_CEE
const char arch_id__M_CEE[] = "_M_CEE";
const int  arch_value__M_CEE = _M_CEE;
#ifndef USE_ARCH_ID
#define USE_ARCH_ID     arch_id__M_CEE
#define USE_ARCH_VALUE  arch_value__M_CEE
#else
#ifndef USE_ARCH_ID2
#define USE_ARCH_ID2    arch_id__M_CEE
#define USE_ARCH_VALUE2 arch_value__M_CEE
#else
#ifndef USE_ARCH_ID3
#define USE_ARCH_ID3    arch_id__M_CEE
#define USE_ARCH_VALUE3 arch_value__M_CEE
#else
#ifndef USE_ARCH_ID4
#define USE_ARCH_ID4    arch_id__M_CEE
#define USE_ARCH_VALUE4 arch_value__M_CEE
#else
#ifndef USE_ARCH_ID5
#define USE_ARCH_ID5    arch_id__M_CEE
#define USE_ARCH_VALUE5 arch_value__M_CEE
#else
#ifndef USE_ARCH_ID6
#define USE_ARCH_ID6    arch_id__M_CEE
#define USE_ARCH_VALUE6 arch_value__M_CEE
#else
#define USE_ARCH_ID7    arch_id__M_CEE
#define USE_ARCH_VALUE7 arch_value__M_CEE
#endif
#endif
#endif
#endif
#endif
#endif
#endif


/* SDCC supports many architectures */
/* and each architecture has a different define */
/* todo: arch supported by SDCC */

/* ############################## */
/* Data Models */
#ifdef __LP32__
const char datamodel_id___LP32__[] = "__LP32__";
const int  datamodel_value___LP32__ = __LP32__;
#define USE_DATAMODEL_ID     datamodel_id___LP32__
#define USE_DATAMODEL_VALUE  datamodel_value___LP32__
#endif

#ifdef _LP32
const char datamodel_id__LP32[] = "_LP32";
const int  datamodel_value__LP32 = _LP32;
#ifndef USE_DATAMODEL_ID
#define USE_DATAMODEL_ID     datamodel_id__LP32
#define USE_DATAMODEL_VALUE  datamodel_value__LP32
#else
#define USE_DATAMODEL_ID2    datamodel_id__LP32
#define USE_DATAMODEL_VALUE2 datamodel_value__LP32
#endif
#endif


#ifdef __ILP32__
const char datamodel_id___ILP32__[] = "__ILP32__";
const int  datamodel_value___ILP32__ = __ILP32__;
#define USE_DATAMODEL_ID     datamodel_id___ILP32__
#define USE_DATAMODEL_VALUE  datamodel_value___ILP32__
#endif

#ifdef _ILP32
const char datamodel_id__ILP32[] = "_ILP32";
const int  datamodel_value__ILP32 = _ILP32;
#ifndef USE_DATAMODEL_ID
#define USE_DATAMODEL_ID     datamodel_id__ILP32
#define USE_DATAMODEL_VALUE  datamodel_value__ILP32
#else
#define USE_DATAMODEL_ID2    datamodel_id__ILP32
#define USE_DATAMODEL_VALUE2 datamodel_value__ILP32
#endif
#endif


#ifdef __LP64__
const char datamodel_id___LP64__[] = "__LP64__";
const int  datamodel_value___LP64__ = __LP64__;
#define USE_DATAMODEL_ID     datamodel_id___LP64__
#define USE_DATAMODEL_VALUE  datamodel_value___LP64__
#endif

#ifdef _LP64
const char datamodel_id__LP64[] = "_LP64";
const int  datamodel_value__LP64 = _LP64;
#ifndef USE_DATAMODEL_ID
#define USE_DATAMODEL_ID     datamodel_id__LP64
#define USE_DATAMODEL_VALUE  datamodel_value__LP64
#else
#define USE_DATAMODEL_ID2    datamodel_id__LP64
#define USE_DATAMODEL_VALUE2 datamodel_value__LP64
#endif
#endif


#ifdef __LLP64__
const char datamodel_id___LLP64__[] = "__LLP64__";
const int  datamodel_value___LLP64__ = __LLP64__;
#define USE_DATAMODEL_ID     datamodel_id___LLP64__
#define USE_DATAMODEL_VALUE  datamodel_value___LLP64__
#endif

#ifdef _LLP64
const char datamodel_id__LLP64[] = "_LLP64";
const int  datamodel_value__LLP64 = _LLP64;
#ifndef USE_DATAMODEL_ID
#define USE_DATAMODEL_ID     datamodel_id__LLP64
#define USE_DATAMODEL_VALUE  datamodel_value__LLP64
#else
#define USE_DATAMODEL_ID2    datamodel_id__LLP64
#define USE_DATAMODEL_VALUE2 datamodel_value__LLP64
#endif
#endif


#ifdef __ILP64__
const char datamodel_id___ILP64__[] = "__ILP64__";
const int  datamodel_value___ILP64__ = __ILP64__;
#define USE_DATAMODEL_ID     datamodel_id___ILP64__
#define USE_DATAMODEL_VALUE  datamodel_value___ILP64__
#endif

#ifdef _ILP64
const char datamodel_id__ILP64[] = "_ILP64";
const int  datamodel_value__ILP64 = _ILP64;
#ifndef USE_DATAMODEL_ID
#define USE_DATAMODEL_ID     datamodel_id__ILP64
#define USE_DATAMODEL_VALUE  datamodel_value__ILP64
#else
#define USE_DATAMODEL_ID2    datamodel_id__ILP64
#define USE_DATAMODEL_VALUE2 datamodel_value__ILP64
#endif
#endif

/* is __SILP64__ used anywhere? */


/* ############################ */
/* detect the used Memory model */
/* 16bit DOS: near limit is 64k */
/* 16bit DOS:  far limit is 1MB */
/* 32bit systems: limit is 4GB  */

/* __TINY__: code+data: near (64k) */
#ifdef __TINY__
const char mcmodel_id_tiny[] = "__TINY__";
const int  mcmodel_value_tiny = __TINY__;
#define USE_MCMODEL_ID     mcmodel_id_tiny
#define USE_MCMODEL_VALUE  mcmodel_value_tiny
#endif

/* __SMALL__: code: near (64k), data: near (64k) */
#ifdef __SMALL__
const char mcmodel_id_small[] = "__SMALL__";
const int  mcmodel_value_small = __SMALL__;
#define USE_MCMODEL_ID     mcmodel_id_small
#define USE_MCMODEL_VALUE  mcmodel_value_small
#endif

/* __MEDIUM__: code: far (1MB), data: near (64k) */
#ifdef __MEDIUM__
const char mcmodel_id_medium[] = "__MEDIUM__";
const int  mcmodel_value_medium = __MEDIUM__;
#define USE_MCMODEL_ID     mcmodel_id_medium
#define USE_MCMODEL_VALUE  mcmodel_value_medium
#endif

/* __COMPACT__: code: near (64k), data: far (1MB), data per object: 64kb */
#ifdef __COMPACT__
const char mcmodel_id_compact[] = "__COMPACT__";
const int  mcmodel_value_compact = __COMPACT__;
#define USE_MCMODEL_ID     mcmodel_id_compact
#define USE_MCMODEL_VALUE  mcmodel_value_compact
#endif

/* __LARGE__: code: far (1MB), data: far (1MB), data per object: 64kb */
#ifdef __LARGE__
const char mcmodel_id_large[] = "__LARGE__";
const int  mcmodel_value_large = __LARGE__;
#define USE_MCMODEL_ID     mcmodel_id_large
#define USE_MCMODEL_VALUE  mcmodel_value_large
#endif

/* __HUGE__: code: far (1MB), data: far (1MB), data per object: 1MB */
#ifdef __HUGE__
const char mcmodel_id_huge[] = "__HUGE__";
const int  mcmodel_value_huge = __HUGE__;
#define USE_MCMODEL_ID     mcmodel_id_huge
#define USE_MCMODEL_VALUE  mcmodel_value_huge
#endif

/* __FLAT__: code: far (1GB/4GB), data: far (4GB), data per object: 4GB */
#ifdef __FLAT__
const char mcmodel_id_flat[] = "__FLAT__";
const int  mcmodel_value_flat = __FLAT__;
#define USE_MCMODEL_ID     mcmodel_id_flat
#define USE_MCMODEL_VALUE  mcmodel_value_flat
#endif

/* __UNREAL__ (DOS realmode with 32bit limits): code: 4GB, data: 4GB */
#ifdef __UNREAL__
const char mcmodel_id_unreal[] = "__UNREAL__";
const int  mcmodel_value_unreal = __UNREAL__;
#define USE_MCMODEL_ID     mcmodel_id_unreal
#define USE_MCMODEL_VALUE  mcmodel_value_unreal
#endif

/* ############################## */

