//-----------------------------------------------------------------------------
// Copyright (c) 2009-2017 Benjamin Buch
//
// https://github.com/bebuch/io_tools
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
//-----------------------------------------------------------------------------
#ifndef _io_tools__std_vector_io__hpp_INCLUDED_
#define _io_tools__std_vector_io__hpp_INCLUDED_

#include "expect.hpp"

#include <iostream>
#include <vector>


namespace io_tools{


	template < typename charT, typename traits, typename T >
	std::basic_ostream< charT, traits >& operator<<(
		std::basic_ostream< charT, traits >& os,
		std::vector< T > const& data
	){
		os << '{';

		if(data.size() >= 1){
			os << data[0];
			for(std::size_t i = 1; i < data.size(); ++i){
				os << ',' << data[i];
			}
		}

		return os << '}';
	}


	template < typename charT, typename traits, typename T >
	std::basic_istream< charT, traits >& operator>>(
		std::basic_istream< charT, traits >& is,
		std::vector< T >& data
	){
		if(!expect(is, '{')) return is;

		std::vector< T > tmp;
		{
			T value;
			is >> value;
			tmp.push_back(std::move(value));
		}

		for(;;){
			if(!is_next(is, ',')){
				if(!expect(is, '}')) return is;

				data = std::move(tmp);

				return is;
			}

			T value;
			is >> value;
			tmp.push_back(std::move(value));
		}

		return is;
	}


}


#endif
