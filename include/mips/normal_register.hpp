#ifndef DEF_MIPS_NORMAL_REGISTER
#define DEF_MIPS_NORMAL_REGISTER

#include "register.hpp"

namespace mips {
/**
 * A read-write register
 */
class normal_register : public cpu_register {
public:
	/**
	 * Initializes a register
	 *
	 * @param intial_value The register's initial value
	 */
	normal_register(uint32_t initial_value = 0);

	virtual void write(uint32_t value) override;
	virtual uint32_t read() const override;
private:
	uint32_t m_value;
};
}

#endif /* end of include guard: DEF_MIPS_NORMAL_REGISTER */
