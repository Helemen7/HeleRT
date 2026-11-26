#include <fsl_device_registers.h>

#include "helert/led.hpp"

void HeOnboardLEDInit(HeBinaryColorRGB color) {
	MRCC0->MRCC_GLB_CC1 |= MRCC_MRCC_GLB_CC1_PORT3_MASK;
	MRCC0->MRCC_GLB_CC1 |= MRCC_MRCC_GLB_CC1_GPIO3_MASK;

	MRCC0->MRCC_GLB_RST1 |= MRCC_MRCC_GLB_RST1_PORT3_MASK;
	MRCC0->MRCC_GLB_RST1 |= MRCC_MRCC_GLB_RST1_GPIO3_MASK;

	if (color.R == HeBinaryState::HeON) {
		PORT3->PCR[12] =
		    (PORT3->PCR[12] & ~PORT_PCR_MUX_MASK) | PORT_PCR_MUX(0);
		GPIO3->PSOR = GPIO_PSOR_PTSO12(1U);
		GPIO3->PDDR |= GPIO_PDDR_PDD12(1U);
	}
	if (color.G == HeBinaryState::HeON) {
		PORT3->PCR[13] =
		    (PORT3->PCR[13] & ~PORT_PCR_MUX_MASK) | PORT_PCR_MUX(0);
		GPIO3->PSOR = GPIO_PSOR_PTSO13(1U);
		GPIO3->PDDR |= GPIO_PDDR_PDD13(1U);
	}
	if (color.B == HeBinaryState::HeON) {
		PORT3->PCR[0] =
		    (PORT3->PCR[0] & ~PORT_PCR_MUX_MASK) | PORT_PCR_MUX(0);
		GPIO3->PSOR = GPIO_PSOR_PTSO0(1U);
		GPIO3->PDDR |= GPIO_PDDR_PDD0(1U);
	}
}

void HeOnboardLEDSet(HeBinaryColorRGB color) {
	if (color.R == HeBinaryState::HeON) {
		GPIO3->PCOR = GPIO_PCOR_PTCO12(1U);
	} else {
		GPIO3->PSOR = GPIO_PSOR_PTSO12(1U);
	}
	if (color.G == HeBinaryState::HeON) {
		GPIO3->PCOR = GPIO_PCOR_PTCO13(1U);
	} else {
		GPIO3->PSOR = GPIO_PSOR_PTSO13(1U);
	}
	if (color.B == HeBinaryState::HeON) {
		GPIO3->PCOR = GPIO_PCOR_PTCO0(1U);
	} else {
		GPIO3->PSOR = GPIO_PSOR_PTSO0(1U);
	}
}
