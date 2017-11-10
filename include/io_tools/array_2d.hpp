//-----------------------------------------------------------------------------
// Copyright (c) 2017 Benjamin Buch
//
// https://github.com/bebuch/io_tools
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
//-----------------------------------------------------------------------------
#ifndef _io_tools__array_2d__hpp_INCLUDED_
#define _io_tools__array_2d__hpp_INCLUDED_

#include <ostream>


namespace io_tools{ namespace array_2d{


	template <
		typename CharT, typename Traits,
		typename T, std::size_t Y, std::size_t X >
	std::basic_ostream< CharT, Traits >& operator<<(
		std::basic_ostream< CharT, Traits >& os,
		T(&m)[Y][X]
	){
		os << '{';
		for(std::size_t y = 0; y < Y; ++y){
			if(y != 0) os << ", ";
			os << '{';
			for(std::size_t x = 0; x < X; ++x){
				if(x != 0) os << ", ";
				os << m[y][x];
			}
			os << '}';
		}
		return os << '}';
	}

	template <
		typename CharT, typename Traits,
		typename T, std::size_t Y, std::size_t X >
	std::basic_ostream< CharT, Traits >& operator<<(
		std::basic_ostream< CharT, Traits >& os,
		T(*m)[Y][X]
	){
		return os << *m;
	}

} }


#endif
