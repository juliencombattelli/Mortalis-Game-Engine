#ifndef MGE_ENTITY_HPP_
#define MGE_ENTITY_HPP_

#include <cstdint>
#include <limits>

namespace mge {
namespace detail {

class Id {
public:
    constexpr Id() noexcept = default;
    constexpr explicit Id(std::uint64_t id) noexcept
        : _id { id }
    {
    }
    constexpr Id(std::uint32_t index, std::uint32_t version) noexcept
        : _id { (static_cast<std::uint64_t>(version) << 32U) | static_cast<std::uint64_t>(index) }
    {
    }

    constexpr std::uint64_t id() const noexcept
    {
        return _id;
    }
    constexpr std::uint32_t index() const noexcept
    {
        return _id & 0xFFFFFFFF;
    }
    constexpr std::uint32_t version() const noexcept
    {
        return (_id >> 32U) & 0xFFFFFFFF;
    }

    constexpr bool operator==(const Id& other) const noexcept
    {
        return _id == other._id;
    }
    constexpr bool operator!=(const Id& other) const noexcept
    {
        return _id != other._id;
    }
    constexpr bool operator<(const Id& other) const noexcept
    {
        return _id < other._id;
    }

private:
    std::uint64_t _id { 0 };
};

} // namespace detail

class Entity {
public:
    using Id = detail::Id;

    constexpr static inline Id InvalidId {};

private:
};

} // namespace mge

#endif // MGE_ENTITY_HPP_