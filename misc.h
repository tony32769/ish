#ifndef MISC_H
#define MISC_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

// debug output utilities
#if DEBUG_LOG
#define TRACE(msg, ...) printf(msg, ##__VA_ARGS__)
#else
#define TRACE(msg, ...) (void)NULL
#endif
#define TRACEI(msg, ...) TRACE(msg "\t", ##__VA_ARGS__)

#define TODO(msg, ...) { printf("TODO: " msg "\n", ##__VA_ARGS__); abort(); }
#define FIXME(msg, ...) printf("FIXME " msg "\n", ##__VA_ARGS__)

#if defined(__i386__) || defined(__x86_64__)
#define debugger __asm__("int3")
#elif defined(__arm__)
#define debugger __asm__("trap")
#endif

// utility macros
#define CONCAT(a, b) _CONCAT(a, b)
#define _CONCAT(a, b) a##b
#define CONCAT3(a,b,c) CONCAT(a, CONCAT(b, c))

#define STR(x) _STR(x)
#define _STR(x) #x

// keywords
#define bits unsigned int
#define forceinline inline __attribute__((always_inline))
#define flatten __attribute__((flatten))
#ifdef NDEBUG
#define postulate __builtin_assume
#else
#define postulate assert
#endif
#define unlikely(x) __builtin_expect((x), 0)
#define noreturn __attribute__((noreturn))

// types
// word_t will be 64-bit to read 64-bit elves
typedef uint64_t qword_t;
typedef uint32_t dword_t;
typedef int32_t sdword_t;
typedef uint16_t word_t;
typedef uint8_t byte_t;

typedef dword_t addr_t;
typedef dword_t uint_t;
typedef sdword_t int_t;

#define uint(size) CONCAT3(uint,size,_t)
#define sint(size) CONCAT3(int,size,_t)

#endif
