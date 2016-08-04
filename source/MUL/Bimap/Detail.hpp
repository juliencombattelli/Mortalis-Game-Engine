//============================================================================
// Name        : Detail.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 30 juin 2016
// Version     : 1.0.0
// Copyright   : This file is part of test-sfml project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef DETAIL_HPP_
#define DETAIL_HPP_

namespace mul { namespace bimap { namespace detail
{

template<class C, typename = void>
struct isTag : std::false_type {};

template<class C>
struct isTag<C, typename std::enable_if<!std::is_same<typename C::tagged_type*, void>::value>::type> : std::true_type {};

template<class B, class ValueTag, class KeyType>
struct bimap_get_helper
{
	static typename ValueTag::tagged_type get(B& b, const KeyType&);
};

template<class B>
struct bimap_get_helper<B, typename B::right_tag, typename B::left_type>
{
	static typename B::right_type get(B& b, const typename B::left_type& l)
	{
		return *b.m_left.at(l);
		/*for(auto& p : b)
			if(p.first == l)
				return p.second;
		throw std::out_of_range("Bimap::get() out of range");*/
	}
};

template<class B>
struct bimap_get_helper<B, typename B::left_tag, typename B::right_type>
{
	static typename B::left_type get(B& b, const typename B::right_type& r)
	{
		return *b.m_right.at(r);
		/*for(auto& p : b)
			if(p.second == r)
				return p.first;*/
		throw std::out_of_range("Bimap::get() out of range");
	}
};

} // namespace detail
} // namespace bimap
} // namespace mul

#endif // DETAIL_HPP_
