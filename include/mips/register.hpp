#ifndef DEF_MIPS_REGISTER
#define DEF_MIPS_REGISTER

#include <cstdint>

namespace mips {

/**
 * Base interface for a CPU register
 */
class cpu_register {
public:
	virtual ~cpu_register() = default;

	/**
	 * Writes a value in the register
	 *
	 * @param value The value to store in the register
	 */
	virtual void write(uint32_t value) = 0;

	/**
	 * Reads a value from the register
	 *
	 * @return The value read from the register
	 */
	virtual uint32_t read() const = 0;
};
}

#endif /* end of include guard: DEF_MIPS_REGISTER */
