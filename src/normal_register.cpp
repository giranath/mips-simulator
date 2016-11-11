#include <mips/normal_register.hpp>

namespace mips {
normal_register::normal_register(uint32_t value) 
: m_value(value) {
}

void normal_register::write(uint32_t value) {
	m_value = value;
}

uint32_t normal_register::read() const {
	return m_value;
}
}
