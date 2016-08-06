//============================================================================
// Name        : Vector2.inl
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Aug 6, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef VECTOR2_INL_
#define VECTOR2_INL_

namespace mul
{

template<class T, class A>
Vector2<T,A>::Vector2() :
	m_row(0), m_column(0), m_size(0), m_data(nullptr)
{

}

template<class T, class A>
Vector2<T,A>::Vector2(size_type row, size_type column) :
	m_row(row), m_column(column), m_size(row*column), m_data(new T[m_size])
{

}

template<class T, class A>
Vector2<T,A>::Vector2(size_type row, size_type column, const value_type& val) : m_row(row), m_column(column), m_size(row*column), m_data(new T[m_size])
{
	for(auto& element : m_data)
		element = val;
}

template<class T, class A>
Vector2<T,A>::~Vector2()
{
	delete[] m_data;
}


template<class T, class A>
void Vector2<T,A>::resize(typename Vector2<T,A>::size_type row, typename Vector2<T,A>::size_type column)
{
	m_row = row;
	m_column = column;
	m_size = row*column;
	m_data = new T[m_size];
}

template<class T, class A>
void Vector2<T,A>::resize(typename Vector2<T,A>::size_type row, typename Vector2<T,A>::size_type column, const value_type& val)
{
	m_row = row;
	m_column = column;
	m_size = row*column;
	m_data = new T[m_size];
	for(auto& element : m_data)
		element = val;
}

template<class T, class A>
void Vector2<T,A>::clear() noexcept
{
	delete[] m_data;
	m_data = nullptr;
	m_row = 0;
	m_column = 0;
}

template<class T, class A>
typename Vector2<T,A>::reference Vector2<T,A>::operator()(typename Vector2<T,A>::size_type row, typename Vector2<T,A>::size_type column)
{
	return m_data[row*m_column+column];
}

template<class T, class A>
typename Vector2<T,A>::const_reference Vector2<T,A>::operator()(typename Vector2<T,A>::size_type row, typename Vector2<T,A>::size_type column) const
{
	return m_data[row*m_column+column];
}

template<class T, class A>
typename Vector2<T,A>::reference Vector2<T,A>::at(typename Vector2<T,A>::size_type row, typename Vector2<T,A>::size_type column)
{
	if(row*column >= m_size)
		throw(std::out_of_range(""));
	return (*this)(row,column);
}
template<class T, class A>
typename Vector2<T,A>::const_reference Vector2<T,A>::at(size_type row, size_type column) const
{
	if(row*column >= m_size)
		throw(std::out_of_range(""));
	return (*this)(row,column);
}

template<class T, class A>
typename Vector2<T,A>::reference Vector2<T,A>::front()
{
	return m_data[0];
}

template<class T, class A>
typename Vector2<T,A>::const_reference Vector2<T,A>::front() const
{
	return m_data[0];
}

template<class T, class A>
typename Vector2<T,A>::reference Vector2<T,A>::back()
{
	return m_data[m_size-1];
}

template<class T, class A>
typename Vector2<T,A>::const_reference Vector2<T,A>::back() const
{
	return m_data[m_size-1];
}

template<class T, class A>
typename Vector2<T,A>::iterator Vector2<T,A>::begin() noexcept
{
	return &m_data[0];
}

template<class T, class A>
typename Vector2<T,A>::const_iterator Vector2<T,A>::begin() const noexcept
{
	return &m_data[0];
}

template<class T, class A>
typename Vector2<T,A>::const_iterator Vector2<T,A>::cbegin() const noexcept
{
	return &m_data[0];
}

template<class T, class A>
typename Vector2<T,A>::reverse_iterator Vector2<T,A>::rbegin() noexcept
{
	return reverse_iterator(end());
}

template<class T, class A>
typename Vector2<T,A>::const_reverse_iterator Vector2<T,A>::rbegin() const noexcept
{
	return reverse_iterator(end());
}

template<class T, class A>
typename Vector2<T,A>::const_reverse_iterator Vector2<T,A>::crbegin() const noexcept
{
	return reverse_iterator(end());
}

template<class T, class A>
typename Vector2<T,A>::iterator Vector2<T,A>::end() noexcept
{
	return &m_data[m_size];
}

template<class T, class A>
typename Vector2<T,A>::const_iterator Vector2<T,A>::end() const noexcept
{
	return &m_data[m_size];
}

template<class T, class A>
typename Vector2<T,A>::const_iterator Vector2<T,A>::cend() const noexcept
{
	return &m_data[m_size];
}

template<class T, class A>
typename Vector2<T,A>::reverse_iterator Vector2<T,A>::rend() noexcept
{
	return reverse_iterator(begin());
}

template<class T, class A>
typename Vector2<T,A>::const_reverse_iterator Vector2<T,A>::rend() const noexcept
{
	return reverse_iterator(begin());
}

template<class T, class A>
typename Vector2<T,A>::const_reverse_iterator Vector2<T,A>::crend() const noexcept
{
	return reverse_iterator(begin());
}

template<class T, class A>
typename Vector2<T,A>::value_type* Vector2<T,A>::data() noexcept
{
	return m_data;
}

template<class T, class A>
const typename Vector2<T,A>::value_type* Vector2<T,A>::data() const noexcept
{
	return m_data;
}

template<class T, class A>
bool Vector2<T,A>::empty() const noexcept
{
	return m_size == 0;
}

template<class T, class A>
typename Vector2<T,A>::size_type Vector2<T,A>::size() const noexcept
{
	return m_size;
}

template<class T, class A>
typename Vector2<T,A>::size_type Vector2<T,A>::row_count() const noexcept
{
	return m_row;
}

template<class T, class A>
typename Vector2<T,A>::size_type Vector2<T,A>::column_count() const noexcept
{
	return m_column;
}

} // namespace mul

#endif // VECTOR2_INL_
