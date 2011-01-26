#ifndef __COMMON_H__
#define __COMMON_H__

#define bitset(var, bitno) ((var) |= 1UL << (bitno))
#define bitclr(var, bitno) ((var) &= ~(1UL << (bitno)))

#endif /* __COMMON_H__ */

