#ifndef _CPU_TYPES_H_
#define _CPU_TYPES_H_

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
typedef char s8;
typedef unsigned char u8;

#define low_16(address) (u16)address;
#define high_16(address) (u16)(address >> 16);

#endif
