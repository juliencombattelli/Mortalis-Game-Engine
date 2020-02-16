#include <gtest/gtest.h>

#include <mge/ecs/Entity.hpp>

TEST(EntityId, default_construction)
{
    // Two default constructed ids MUST be equal
    mge::Entity::Id id1, id2;
    EXPECT_EQ(id1.id(), id2.id());
}

TEST(EntityId, explicit_construction)
{
    // An id constructed with a specific value MUST hold this value
    mge::Entity::Id id { 42U };
    EXPECT_EQ(id.id(), 42U);
}

TEST(EntityId, equality_comparison)
{
    // Two ids MUST be equally comparable
    // The comparison MUST return true if their values are equal
    mge::Entity::Id id1, id2;
    EXPECT_EQ(id1, id2);
}

TEST(EntityId, inequality_comparison)
{
    // Two ids MUST be inequally comparable
    // The comparison MUST return false if their values are not equal
    mge::Entity::Id id1 { 42U }, id2 { 43U };
    EXPECT_NE(id1, id2);
}

// TODO add index() and version() utests
