//-----------------------------------------------------------------------------
// Copyright (c) 2017 Benjamin Buch
//
// https://github.com/bebuch/io_tools
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
//-----------------------------------------------------------------------------
#ifndef _io_tools__c_array__hpp_INCLUDED_
#define _io_tools__c_array__hpp_INCLUDED_

#include <ostream>
#include <string_view>


namespace io_tools{ namespace c_array{


	// Use it by:
	//
	// using ::io_tools::c_array::operator<<;

	template <
		typename CharT, typename Traits,
		typename T, std::size_t N >
	std::basic_ostream< CharT, Traits >& operator<<(
		std::basic_ostream< CharT, Traits >& os,
		T(&m)[N]
	){
		os << '{';
		for(std::size_t i = 0; i < N; ++i){
			using namespace std::literals::string_view_literals;
			if(i != 0) os << ", "sv;
			os << m[i];
		}
		return os << '}';
	}


} }


#endif
