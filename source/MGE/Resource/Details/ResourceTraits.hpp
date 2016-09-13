//============================================================================
// Name        : ResourceTraits.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Sep 6, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef RESOURCETRAITS_HPP_
#define RESOURCETRAITS_HPP_

#include <MUL/TypeTraitsHelper.hpp>


namespace mge { namespace traits
{

MUL_DECLARE_HAS_TYPEDEF_TRAITS(hasResourceType, ResourceType);

MUL_DECLARE_HAS_METHOD_TRAITS(hasLoadMethod, load);
MUL_DECLARE_HAS_METHOD_TRAITS(hasLoadFromFileMethod, loadFromFile);

} // namespace traits
} // namespace mge

#endif // RESOURCETRAITS_HPP_
