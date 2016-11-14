#ifndef MIPS_MEMORY_HPP
#define MIPS_MEMORY_HPP

#include <cstdint>
#include <cstddef>

namespace mips {
class memory {
public:
    using address = std::size_t;

    /**
     * Initializes the memory with a capacity
     *
     * @param capacity The initial capacity
     */
    memory(std::size_t capacity);

    /**
     * Releases the memory
     */
    ~memory();

    /**
     * Returns the memory capacity in bytes
     *
     * @return The number of bytes that can be accessed in the random access memory
     */
    std::size_t get_capacity() const;

    /**
     * Read data from memory
     *
     * @param destination_buffer The destination buffer where the read data will be copied to
     * @param len The number of bytes to read from the memory
     * @param source_address The memory address to read from
     * @return destination_buffer
     */
    const uint8_t* read(uint8_t* destination_buffer, std::size_t len, address source_address) const;

    /**
     * Write data to memory
     *
     * @param data_buffer The data to write in memory
     * @param len The size of the data to write
     * @param destination_address The address where to write the data
     */
    void write(const uint8_t* data_buffer, std::size_t len, address destination_address);

private:
    std::size_t m_capacity;
    uint8_t*    m_data;
};
}

#endif //MIPS_MEMORY_HPP
