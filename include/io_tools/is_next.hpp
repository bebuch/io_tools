//-----------------------------------------------------------------------------
// Copyright (c) 2013-2017 Benjamin Buch
//
// https://github.com/bebuch/io_tools
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
//-----------------------------------------------------------------------------
#ifndef _io_tools__is_next__hpp_INCLUDED_
#define _io_tools__is_next__hpp_INCLUDED_

#include <istream>


namespace io_tools{


	template < class CharT, class Traits >
	inline bool is_next(
		std::basic_istream< CharT, Traits >& is,
		CharT const& should_be
	){
		CharT in;
		if(is){
			if(is >> in && in == should_be) return true;
			is.putback(in);
		}
		return false;
	}


}

#endif
