#include <mips/machine.hpp>
#include <mips/const_register.hpp>
#include <mips/normal_register.hpp>

#include <sstream>
#include <cassert>

namespace mips {
machine::machine() {
    std::stringstream name_stream;

    // Initializes every register and their name
    for(std::size_t i = 0; i < REGISTER_COUNT; ++i) {
        m_registers[i] = nullptr;

        name_stream.clear();
        name_stream << "$" << i;

        m_register_names[name_stream.str()] = i;
    }

    m_register_names["$kt0"] = 26;
    m_register_names["$kt1"] = 27;
    m_register_names["$gp"] =  28;
    m_register_names["$sp"] =  29;
    m_register_names["$fp"] =  30;

    // Instanciates every registers
    m_registers[0] = new const_register<0>;
    for(std::size_t i = 2; i < TOTAL_REGISTER_COUNT; ++i) {
        m_registers[i] = new normal_register;
    }


}

machine::~machine() {
    for(std::size_t i = 0; i < REGISTER_COUNT; ++i) {
        delete m_registers[i];
    }
}

const cpu_register_32& machine::get_register_at(std::size_t index) const {
    assert(index < REGISTER_COUNT);

    return *m_registers[index];
}

cpu_register_32& machine::get_register_at(std::size_t index) {
    assert(index < REGISTER_COUNT);

    return *m_registers[index];
}

std::size_t machine::get_register_index_by_name(const std::string& name) const {
    return m_register_names.at(name);
}

cpu_register_32& machine::get_pc() {
    return *m_registers[PC_REGISTER_INDEX];
}

const cpu_register_32& machine::get_pc() const {
    return *m_registers[PC_REGISTER_INDEX];
}
}

