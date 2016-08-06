//============================================================================
// Name        : Vector2.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Aug 6, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef VECTOR2_HPP_
#define VECTOR2_HPP_

namespace mul
{

template<typename T, class Alloc = std::allocator<T>>
class Vector2
{
public:

	using allocator_type 			= Alloc;
	using value_type 				= typename allocator_type::value_type;
	using reference 				= typename allocator_type::reference;
	using const_reference 			= typename allocator_type::const_reference;
	using pointer					= typename allocator_type::pointer;
	using const_pointer				= typename allocator_type::const_pointer;
	using difference_type 			= typename allocator_type::difference_type;
	using size_type 				= typename allocator_type::size_type;

	using iterator					= pointer;
	using const_iterator			= const_pointer;
	using const_reverse_iterator 	= std::reverse_iterator<const_iterator>;
	using reverse_iterator 			= std::reverse_iterator<iterator>;

	Vector2();
	Vector2(size_type row, size_type column);
	Vector2(size_type row, size_type column, const value_type& val);
	Vector2(const Vector2& x);
	Vector2(Vector2&& x);

	~Vector2();

	Vector2& operator= (const Vector2& x);
	Vector2& operator= (Vector2&& x);

	void resize(size_type row, size_type column);
	void resize(size_type row, size_type column, const value_type& val);
	void clear() noexcept;

	reference operator()(size_type row, size_type column);
	const_reference operator()(size_type row, size_type column) const;

	reference at(size_type row, size_type column);
	const_reference at(size_type row, size_type column) const;

	reference front();
	const_reference front() const;

	reference back();
	const_reference back() const;

	iterator begin() noexcept;
	const_iterator begin() const noexcept;
	const_iterator cbegin() const noexcept;

	reverse_iterator rbegin() noexcept;
	const_reverse_iterator rbegin() const noexcept;
	const_reverse_iterator crbegin() const noexcept;

	iterator end() noexcept;
	const_iterator end() const noexcept;
	const_iterator cend() const noexcept;

	reverse_iterator rend() noexcept;
	const_reverse_iterator rend() const noexcept;
	const_reverse_iterator crend() const noexcept;

	value_type* data() noexcept;
	const value_type* data() const noexcept;

	bool empty() const noexcept;

	// <section>
	// TODO return an iterator to the newly inserted row/column
	void insert_row(size_type position);
	void insert_row(size_type position, size_type number);

	void insert_column(size_type position);
	void insert_column(size_type position, size_type number);
	// </section>

	// <section>
	// TODO return an iterator to the new location of the row/column that followed the last row/column erased
	void erase_row(size_type position);
	void erase_row(size_type first, size_type last);

	void erase_column(size_type position);
	void erase_column(size_type first, size_type last);
	// </section>

	size_type size() const noexcept;
	size_type row_count() const noexcept;
	size_type column_count() const noexcept;

	void swap (Vector2& x);

protected:

	size_type m_row;
	size_type m_column;
	size_type m_size;
	T* m_data;
};

} // namespace mul

#include "Vector2.inl"

#endif // VECTOR2_HPP_
