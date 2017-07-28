//-----------------------------------------------------------------------------
// Copyright (c) 2009-2017 Benjamin Buch
//
// https://github.com/bebuch/io_tools
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
//-----------------------------------------------------------------------------
#ifndef _io_tools__std_array_io__hpp_INCLUDED_
#define _io_tools__std_array_io__hpp_INCLUDED_

#include "expect.hpp"

#include <iostream>
#include <array>


namespace io_tools{


	template < typename charT, typename traits, typename T, std::size_t N >
	std::basic_ostream< charT, traits >& operator<<(
		std::basic_ostream< charT, traits >& os,
		std::array< T, N > const& data
	){
		os << '{';

		if(N >= 1){
			os << data[0];
			for(std::size_t i = 1; i < N; ++i){
				os << ',' << data[i];
			}
		}

		return os << '}';
	}


	template < typename charT, typename traits, typename T, std::size_t N >
	std::basic_istream< charT, traits >& operator>>(
		std::basic_istream< charT, traits >& is,
		std::array< T, N >& data
	){
		if(!expect(is, '{')) return is;

		std::array< T, N > tmp;
		if(N >= 1){
			is >> tmp[0];
			for(std::size_t i = 1; i < N; ++i){
				if(!expect(is, ',')) return is;
				is >> tmp[i];
			}
		}

		if(!expect(is, '}')) return is;

		data = std::move(tmp);

		return is;
	}


}


#endif
