#ifndef DEF_MIPS_CONST_REGISTER
#define DEF_MIPS_CONST_REGISTER

#include "register.hpp"

namespace mips {

/**
 * Specifies a readonly register
 */
template<uint32_t VALUE>
class const_register : public cpu_register_32 {
public:
	virtual void write(uint32_t value) override {
	}

	virtual uint32_t read() const override {
		return VALUE;
	}
};
}

#endif
