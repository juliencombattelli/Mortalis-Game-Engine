#ifndef MGE_COMPONENTREGISTRY_HPP_
#define MGE_COMPONENTREGISTRY_HPP_

#include <mge/ecs/ComponentFamily.hpp>
#include <mge/ecs/ComponentPool.hpp>

#include <memory>
#include <vector>

namespace mge {

class ComponentRegistry {
public:
private:
    std::vector<std::unique_ptr<BaseComponentPool>> _componentPools;
};

} // namespace mge

#endif // MGE_COMPONENTREGISTRY_HPP_