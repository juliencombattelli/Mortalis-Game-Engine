#ifndef MGE_COMPONENTPOOL_HPP_
#define MGE_COMPONENTPOOL_HPP_

#include <vector>

namespace mge {

class BaseComponentPool {
};

template <typename Component>
class ComponentPool : BaseComponentPool {
public:
    using container_type = std::vector<Component>;

    using size_type = typename container_type::size_type;
    using reference = typename container_type::reference;
    using const_reference = typename container_type::const_reference;

    size_type size() const;

    void resize(size_type size);

    reference at(size_type pos);
    const_reference at(size_type pos) const;

    reference operator[](size_type pos);
    const_reference operator[](size_type pos) const;

    template <typename... Args>
    reference construct(size_type pos, Args&&... args);

    void destroy(size_type pos);

private:
    container_type m_components;
};

template <typename Component>
auto ComponentPool<Component>::size() const -> size_type
{
    return m_components.size();
}

template <typename Component>
void ComponentPool<Component>::resize(size_type size)
{
    m_components.resize(size);
}

template <typename Component>
auto ComponentPool<Component>::at(size_type pos) -> reference
{
    return m_components.at(pos);
}

template <typename Component>
auto ComponentPool<Component>::at(size_type pos) const -> const_reference
{
    return m_components.at(pos);
};

template <typename Component>
auto ComponentPool<Component>::operator[](size_type pos) -> reference
{
    return m_components[pos];
}

template <typename Component>
auto ComponentPool<Component>::operator[](size_type pos) const -> const_reference
{
    return m_components[pos];
};

template <typename Component>
template <typename... Args>
auto ComponentPool<Component>::construct(size_type pos, Args&&... args) -> reference
{
    reference component = m_components.at(pos);
    ::new (std::addressof(component)) Component { std::forward<Args>(args)... };
    return component;
}

template <typename Component>
void ComponentPool<Component>::destroy(size_type pos)
{
    reference component = m_components.at(pos);
    component.~Component();
}

} // namespace mge

#endif // MGE_COMPONENTPOOL_HPP_