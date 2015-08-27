/*
 * QUnit
 *   the stupidly simple (yet stunningly gorgeous) unit testing framework
 *
 * https://github.com/AERO-ff/qunit
 * Released to the Public Domain by JD Ballard
 *
 * Usage:
 *
 *   #include "qunit.h"
 *
 *   const char *some_test(void) {
 *     if (true)
 *       return 0; // success
 *     else
 *       return "there was some sort of error"; // error
 *   }
 *
 *   q_start();
 *   q_test(some_test);
 *   q_end();
 *
 *
 * Yes, really. That simple.
 * Built for the AERO File Format for the Kleos Foundation.
 */
#ifndef QTEST_
#define QTEST_

#include <stdio.h>

#define q_test(_name)                                                           \
  do {                                                                          \
    const char *res = _name();                                                  \
    if (res) {                                                                  \
      printf("  \x1b[31m! " #_name ":\x1b[0m %s\n", res);                       \
      failed = 1;                                                               \
    } else {                                                                    \
      printf("  \x1b[32m✓\x1b[0m " #_name "\n");                                \
      ++*passed;                                                                \
    }                                                                           \
    ++*count;                                                                   \
  } while(0)

#define q_start()                                                               \
  static char unused;                                                           \
  int q_do_test(int *count, int *passed) {                                      \
    int failed = 0

#define q_end()                                                                 \
    return failed;                                                              \
  }                                                                             \
                                                                                \
  int main(void) {                                                              \
    (void) unused;                                                              \
    printf("\n");                                                               \
    int total = 0;                                                              \
    int passed = 0;                                                             \
    int result = q_do_test(&total, &passed);                                    \
    printf("\n\x1b[1m%s\x1b[0m with \x1b[1m%d/%d\x1b[0m passing "               \
        "(\x1b[1m%d%%\x1b[0m)\n\n",                                             \
        (result ? "FAILED" : "OK"),                                             \
        passed, total,                                                          \
        total ? (int)(((float)passed / (float)total) * 100.0f) : 100);          \
  }                                                                             \
                                                                                \
  static char unused = 0                                                        \

#endif
