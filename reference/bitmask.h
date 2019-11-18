template<class Int>
bool getBit(Int num, int ind) { return ((num >> ind) & 1); }

template<class Int>
Int setBit(Int num, int ind, bool val) {
	return val ? (num | ((Int)(1) << ind)) : (num & ~((Int)(1) << ind));
}

template<class Int>
Int flipBit(Int num, int ind) { return (num ^ ((Int)(1) << ind)); }

template<class Int>
Int leastBit(Int num) { return (num & -num); }

//num%mod, mod is a power of 2
template<class Int>
Int Mod(Int num, Int mod) { return (num & mod - 1); }

template<class Int>
bool isPowerOfTwo(Int num) { return (num & num - 1) == 0; }

void genAllSubmask(int mask) {
	for (int subMask = mask;; subMask = (subMask - 1) & mask) {
		//code
		if (subMask == 0)break;
	}
}

// for run __builtin_popcount in visual
#ifdef _MSC_VER
#include <intrin.h>
#define __builtin_popcount __popcnt
#ifdef _WIN64
#define __builtin_popcountll __popcnt64
#else
inline int __builtin_popcountll(__int64 a) {
	return __builtin_popcount((unsigned int)a) + __builtin_popcount(a >> 32);
}
#endif
#endif
