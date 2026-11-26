#pragma once

#include <cstdint>

[[gnu::always_inline]] static inline void HeWFI() {
	asm volatile("wfi" ::: "memory");
}

inline void HeTickDelay(uint32_t n) {
	for (volatile uint32_t i{0U}; i < n;) {
		uint32_t tmp{i + 1};
		i = tmp;
	}
}
