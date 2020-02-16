#include <gtest/gtest.h>

#include <mge/ecs/ComponentPool.hpp>

namespace {
struct TestComponent {
    int i;
    float f;
};
} // namespace

TEST(ComponentPoolTest, construct)
{
    mge::ComponentPool<TestComponent> pool;
    pool.resize(64);

    TestComponent& component = pool.construct(42, 2, 3.3F);
    EXPECT_EQ(component.i, 2);
    EXPECT_FLOAT_EQ(component.f, 3.3F);
}