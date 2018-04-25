//============================================================================
// Name        : Memory.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date        : 22 jun. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : Provide some tools to efficiently manipulate memory
//============================================================================

#ifndef MUL_MEMORY_HPP_
#define MUL_MEMORY_HPP_

#if __cplusplus < 201103L
#error This library needs at least a C++11 compliant compiler
#endif

#include <memory>

namespace mul
{

inline std::uint32_t to_u32(const std::uint8_t bytes[4])
{
    return std::uint32_t(bytes[0]) << 24 | std::uint32_t(bytes[1]) << 16
         | std::uint32_t(bytes[2]) <<  8 | std::uint32_t(bytes[3]);
}

inline std::uint64_t to_u64(const std::uint8_t bytes[8])
{
    uint32_t lbytes = to_u32(&bytes[0]);
    uint32_t hbytes = to_u32(&bytes[4]);
    return std::uint64_t(lbytes) << 32 | std::uint64_t(hbytes);
}

inline void to_bytes(std::uint32_t u32, std::uint8_t bytes[4])
{
    uint8_t* u8v = (uint8_t*)&u32;
    uint32_t& bytes_as_u32 = *(uint32_t*)bytes;
    bytes_as_u32 = to_u32(u8v);
}

inline void to_bytes(std::uint64_t u64, std::uint8_t bytes[8])
{
    uint8_t* u8v = (uint8_t*)&u64;
    uint64_t& bytes_as_u64 = *(uint64_t*)bytes;
    bytes_as_u64 = to_u64(u8v);
}

} // namespace mul

#endif // MUL_MEMORY_HPP_
