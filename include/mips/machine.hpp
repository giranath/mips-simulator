#ifndef MIPS_MACHINE_HPP
#define MIPS_MACHINE_HPP

#include "register.hpp"

#include <array>
#include <memory>
#include <map>
#include <string>

namespace mips {

/**
 * Represents a machine
 */
class machine {
private:
    static const std::size_t REGISTER_COUNT = 32;
    static const std::size_t SPECIAL_REGISTER_COUNT = 3;
    static const std::size_t TOTAL_REGISTER_COUNT = REGISTER_COUNT + SPECIAL_REGISTER_COUNT;

    static const std::size_t PC_REGISTER_INDEX = 32;
    static const std::size_t HI_REGISTER_INDEX = 33;
    static const std::size_t LO_REGISTER_INDEX = 34;

public:
    machine();
    ~machine();

    const cpu_register_32& get_register_at(std::size_t index) const;
    cpu_register_32& get_register_at(std::size_t index);

    std::size_t get_register_index_by_name(const std::string& name) const;

    cpu_register_32& get_pc();
    const cpu_register_32& get_pc() const;

private:
    cpu_register_32* m_registers[TOTAL_REGISTER_COUNT];
    std::map<std::string, std::size_t> m_register_names;

};
}

#endif //MIPS_MACHINE_HPP
