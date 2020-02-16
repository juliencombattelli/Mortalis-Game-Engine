#ifndef MGE_COMPONENT_FAMILY_HPP_
#define MGE_COMPONENT_FAMILY_HPP_

#include <atomic>

namespace mge {

class BaseComponentFamily {
protected:
    BaseComponentFamily() = default;

    static inline std::atomic_size_t m_family { 0 };
};

template <typename Component>
class ComponentFamily : public BaseComponentFamily {
public:
    static std::size_t family() noexcept
    {
        static const std::size_t family = m_family.fetch_add(1);
        return family;
    }
};

} // namespace mge

#endif // MGE_COMPONENT_FAMILY_HPP_