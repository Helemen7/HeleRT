#include <cstdint>

#include "helert/utility.hpp"

typedef void (*fn_ptr)(void);

extern "C" void *__StackTop;

extern "C" [[noreturn]] void Reset_Handler();

int main();

// Use a function pointer array as the ISR vector is just a vector of functions
extern "C" [[gnu::section(".isr_vector")]] const fn_ptr isr_vector[6]{
    reinterpret_cast<fn_ptr>(&__StackTop), Reset_Handler};

[[noreturn]] void Reset_Handler() {

	uintptr_t word{0x20000000};

	while (word < 0x20002000) {
		*reinterpret_cast<volatile uint32_t *>(word) =
		    0xDEADC0DE; // little easter egg here
		word += sizeof(word);
	}

	main();

	while (1) {
		HeWFI();
	}
}
