#ifndef DEF_MIPS_REGISTER
#define DEF_MIPS_REGISTER

#include <cstdint>

namespace mips {
/**
 * Interface for a register
 */
class cpu_register {
public:
	/**
	 * Writes a value in the register
	 *
	 * @param value The value to write in the register
	 */
	virtual void write(uint32_t value) = 0;

	/**
	 * Read a value from the register
	 *
	 * @return The value stored in the register
	 */
	virtual uint32_t read() const = 0;
};
}

#endif /* end of include guard: DEF_MIPS_REGISTER */
