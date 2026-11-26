#include "helert/led.hpp"
#include "helert/utility.hpp"

int main() {
	HeBinaryColorRGB allon{HeBinaryState::HeON, HeBinaryState::HeON,
			       HeBinaryState::HeON};
	HeOnboardLEDInit(allon);

	volatile uint32_t n{0U};

	while (1) {
		switch (n % 3) {
		case (0): {
			HeOnboardLEDSet(HeBinaryColorRGB{HeBinaryState::HeON,
							 HeBinaryState::HeOFF,
							 HeBinaryState::HeOFF});
			break;
		}
		case (1): {
			HeOnboardLEDSet(HeBinaryColorRGB{HeBinaryState::HeOFF,
							 HeBinaryState::HeON,
							 HeBinaryState::HeOFF});
			break;
		}
		case (2): {
			HeOnboardLEDSet(HeBinaryColorRGB{HeBinaryState::HeOFF,
							 HeBinaryState::HeOFF,
							 HeBinaryState::HeON});
			break;
		}
		}

		uint32_t tmp{n + 1};
		n = tmp;

		HeTickDelay(2'400'000U);
	}
}
