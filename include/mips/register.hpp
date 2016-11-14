#ifndef DEF_MIPS_REGISTER
#define DEF_MIPS_REGISTER

#include <cstdint>

namespace mips {

/**
 * Base interface for a CPU register
 */
template<typename TYPE>
class cpu_register {
public:
	virtual ~cpu_register() = default;

	/**
	 * Writes a value in the register
	 *
	 * @param value The value to store in the register
	 */
	virtual void write(TYPE value) = 0;

	/**
	 * Reads a value from the register
	 *
	 * @return The value read from the register
	 */
	virtual TYPE read() const = 0;
};

using cpu_register_32 = cpu_register<uint32_t>;
using cpu_register_64 = cpu_register<uint64_t>;

}

#endif /* end of include guard: DEF_MIPS_REGISTER */
