//============================================================================
// Name        : Bimap.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 29 juin 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : This library provide a STL-compliant bidirectional map
//============================================================================

#ifndef BIMAP_HPP_
#define BIMAP_HPP_

#include "Detail.hpp"
#include <utility>
#include <map>

namespace mul { namespace bimap
{

template
<
	class Left,
	class Right,
	class A = std::allocator<std::map<Left,Right*>>,
	typename enable = void
>
class Bimap
{
public:

	using self_type			= Bimap<Left,Right,A>;

	using left_type 		= Left;
	using right_type 		= Right;

	using pair_type			= std::pair<left_type,right_type>;
	using left_map_type		= std::map<left_type,right_type*>;
	using right_map_type	= std::map<right_type,left_type*>;

    using allocator_type 	= A;
    using value_type 		= typename allocator_type::value_type;
    using reference 		= typename allocator_type::reference;
    using const_reference 	= typename allocator_type::const_reference;
    using pointer			= typename allocator_type::pointer;
    using const_pointer		= typename allocator_type::const_pointer;
    using difference_type 	= typename allocator_type::difference_type;
    using size_type 		= typename allocator_type::size_type;

    using iterator			= typename left_map_type::iterator;
    using const_iterator	= typename left_map_type::const_iterator;

    Bimap() {}
    Bimap(std::initializer_list<pair_type> l) { for(auto& p : l) insert(p); }
    Bimap(const Bimap& bimap) { /* TODO */ }
    ~Bimap() {}

    Bimap& operator=(const Bimap& bimap) {  /* TODO */ return *this; }
	bool operator==(const Bimap& bimap) const { return m_left == bimap.m_left; }
	bool operator!=(const Bimap& bimap) const { return m_left != bimap.m_left; }

	iterator begin() { return m_left.begin(); }
	const_iterator begin() const { return m_left.begin(); }
	const_iterator cbegin() const { return m_left.cbegin(); }
	iterator end() { return m_left.end(); }
	const_iterator end() const { return m_left.end(); }
	const_iterator cend() const { return m_left.cend(); }

	void swap(Bimap& bimap) { /* TODO */ }
	size_type size() { return m_left.size(); }
	size_type max_size() { return m_left.max_size(); }
	bool empty() { return m_left.empty(); }

    void insert(const pair_type& pair)
    {
    	auto itLeft = m_left.insert({pair.first,nullptr});
    	left_type* lptr = const_cast<left_type*>(&(itLeft.first->first));
    	auto itRight = m_right.insert({pair.second,lptr});
    	itLeft.first->second = const_cast<right_type*>(&itRight.first->first);
    }

    void insert(const left_type& left, const right_type& right)
	{
    	auto itLeft = m_left.insert({left,nullptr});
		left_type* lptr = const_cast<left_type*>(&(itLeft.first->first));
		auto itRight = m_right.insert({right,lptr});
		itLeft.first->second = const_cast<right_type*>(&itRight.first->first);
	}

    void remove(const pair_type& pair)
    {
    	m_left.erase(pair.first);
    	m_right.erase(pair.second);
    }

    void remove(const left_type& left, const right_type& right)
	{
    	m_left.erase(left);
    	m_right.erase(right);
	}

    right_type fromLeft(const left_type& left) { return *m_left.at(left); }
    left_type fromRight(const right_type& right) { return *m_right.at(right); }

protected:

    left_map_type m_left;
    right_map_type m_right;
};

//****************************************************************************
//*
//*  Bimap specialization for tagged type
//*
//****************************************************************************
template<class Left,class Right,class A>
class Bimap
<
	Left,
	Right,
	A,
	typename std::enable_if<detail::isTag<Left>::value and detail::isTag<Right>::value>::type
>
{
public:

	using self_type			= Bimap<Left,Right,A>;

	using left_tag			= Left;
	using right_tag			= Right;

	using left_type 		= typename Left::tagged_type;
	using right_type 		= typename Right::tagged_type;

	using pair_type			= std::pair<left_type,right_type>;
	using left_map_type		= std::map<left_type,right_type*>;
	using right_map_type	= std::map<right_type,left_type*>;

    using allocator_type 	= A;
    using value_type 		= typename allocator_type::value_type;
    using reference 		= typename allocator_type::reference;
    using const_reference 	= typename allocator_type::const_reference;
    using pointer			= typename allocator_type::pointer;
    using const_pointer		= typename allocator_type::const_pointer;
    using difference_type 	= typename allocator_type::difference_type;
    using size_type 		= typename allocator_type::size_type;

    using iterator			= typename left_map_type::iterator;
    using const_iterator	= typename left_map_type::const_iterator;

    Bimap() {}
    Bimap(std::initializer_list<pair_type> l) { for(auto& p : l) insert(p); }
    Bimap(const Bimap& bimap) { /* TODO */ }
    ~Bimap() {}

    Bimap& operator=(const Bimap& bimap) {  /* TODO */ return *this; }
    bool operator==(const Bimap& bimap) const { return m_left == bimap.m_left; }
    bool operator!=(const Bimap& bimap) const { return m_left != bimap.m_left; }

    iterator begin() { return m_left.begin(); }
    const_iterator begin() const { return m_left.begin(); }
    const_iterator cbegin() const { return m_left.cbegin(); }
    iterator end() { return m_left.end(); }
    const_iterator end() const { return m_left.end(); }
    const_iterator cend() const { return m_left.cend(); }

    void swap(Bimap& bimap) { /* TODO */ }
    size_type size() { return m_left.size(); }
    size_type max_size() { return m_left.max_size(); }
    bool empty() { return m_left.empty(); }

    void insert(const pair_type& pair)
    {
    	auto itLeft = m_left.insert({pair.first,nullptr});
    	left_type* lptr = const_cast<left_type*>(&(itLeft.first->first));
    	auto itRight = m_right.insert({pair.second,lptr});
    	itLeft.first->second = const_cast<right_type*>(&itRight.first->first);
    }

    void insert(const left_type& left, const right_type& right)
	{
    	auto itLeft = m_left.insert({left,nullptr});
		left_type* lptr = const_cast<left_type*>(&(itLeft.first->first));
		auto itRight = m_right.insert({right,lptr});
		itLeft.first->second = const_cast<right_type*>(&itRight.first->first);
	}

    void remove(const pair_type& pair)
    {
    	m_left.erase(pair.first);
    	m_right.erase(pair.second);
    }

    void remove(const left_type& left, const right_type& right)
	{
    	m_left.erase(left);
    	m_right.erase(right);
	}

    template<typename ValueTag, typename KeyType>
    typename ValueTag::tagged_type get(const KeyType& k)
	{
		return detail::bimap_get_helper<Bimap, ValueTag, KeyType>::get(*this, k);
	}

    right_type fromLeft(const left_type& left) { return *m_left.at(left); }
    left_type fromRight(const right_type& right) { return *m_right.at(right); }

protected:

    left_map_type m_left;
    right_map_type m_right;

    template<class,class,class>
    friend struct detail::bimap_get_helper;
};

} // namespace bimap
} // namespace mul

#endif // BIMAP_HPP_
/*
/// Checker for typedef with given name and convertible type
#define TYPEDEF_CHECKER(checker, name) \
template<class C, typename T, typename = void> struct checker : std::false_type {}; \
template<class C, typename T> struct checker<C, T, typename std::enable_if< \
  std::is_convertible<typename C::name, T>::value>::type> : std::true_type {}
/// Checker for typedef with given name and exact type
#define TYPEDEF_CHECKER_STRICT(checker, name) \
template<class C, typename T, typename = void> struct checker : std::false_type {}; \
template<class C, typename T> struct checker<C, T, typename std::enable_if< \
  std::is_same<typename C::name, T>::value>::type> : std::true_type {}
/// Checker for typedef with given name and any type
#define TYPEDEF_CHECKER_ANY(checker, name) \
template<class C, typename = void> struct checker : std::false_type {}; \
template<class C> struct checker<C, typename std::enable_if< \
  !std::is_same<typename C::name*, void>::value>::type> : std::true_type {}

/// Checker for member with given name and convertible type
#define MTYPE_CHECKER(checker, name) \
template<class C, typename T, typename = void> struct checker : std::false_type {}; \
template<class C, typename T> struct checker<C, T, typename std::enable_if< \
  std::is_convertible<decltype(C::name), T>::value>::type> : std::true_type {}
/// Checker for member with given name and exact type
#define MTYPE_CHECKER_STRICT(checker, name) \
template<class C, typename T, typename = void> struct checker : std::false_type {}; \
template<class C, typename T> struct checker<C, T, typename std::enable_if< \
  std::is_same<decltype(C::name), T>::value>::type> : std::true_type {}
/// Checker for member with given name and any type
#define MTYPE_CHECKER_ANY(checker, name) \
template<class C, typename = void> struct checker : std::false_type {}; \
template<class C> struct checker<C, typename std::enable_if< \
  !std::is_same<decltype(C::name)*, void>::value>::type> : std::true_type {}

/// Checker for static const variable with given name and value
#define MVALUE_CHECKER(checker, name, val) \
template<class C, typename = void> struct checker : std::false_type {}; \
template<class C> struct checker<C, typename std::enable_if< \
  std::is_convertible<decltype(C::name), const decltype(val)>::value && C::name == val>::type> : std::true_type {}
/// Checker for static const variable with given name, value and type
#define MVALUE_CHECKER_STRICT(checker, name, val) \
template<class C, typename = void> struct checker : std::false_type {}; \
template<class C> struct checker<C, typename std::enable_if< \
  std::is_same<decltype(C::name), const decltype(val)>::value && C::name == val>::type> : std::true_type {}

/// Checker for member function with convertible return type and accepting given arguments
#define METHOD_CHECKER(checker, name, ret, args) \
template<class C, typename=void> struct checker : std::false_type {}; \
template<class C> struct checker<C, typename std::enable_if< \
  std::is_convertible<decltype(std::declval<C>().name args), ret>::value>::type> : std::true_type {};
/// Checker for member function with exact retutn type and accepting given arguments
#define METHOD_CHECKER_STRICT_RET(name, fn, ret, args) \
template<class C, typename=void> struct name : std::false_type {}; \
template<class C> struct name<C, typename std::enable_if< \
  std::is_same<decltype(std::declval<C>().fn args), ret>::value>::type> : std::true_type {};
/// Checker for member function accepting given arguments
#define METHOD_CHECKER_ANY(name, fn, args) \
template<class C, typename=void> struct name : std::false_type {}; \
template<class C> struct name<C, typename std::enable_if< \
  !std::is_same<decltype(std::declval<C>().fn args)*, void>::value>::type> : std::true_type {};*/
