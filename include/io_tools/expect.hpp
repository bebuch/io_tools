//-----------------------------------------------------------------------------
// Copyright (c) 2013-2017 Benjamin Buch
//
// https://github.com/bebuch/io_tools
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
//-----------------------------------------------------------------------------
#ifndef _io_tools__expect__hpp_INCLUDED_
#define _io_tools__expect__hpp_INCLUDED_

#include <istream>


namespace io_tools{


	template < class CharT, class Traits, class ShouldBe >
	inline bool expect(
		std::basic_istream< CharT, Traits >& is,
		ShouldBe const& should_be
	){
		ShouldBe in;
		if(is && is >> in && in == should_be) return true;
		is.setstate(std::ios_base::failbit);
		return false;
	}

	template < class CharT, class Traits >
	inline bool expect(
		std::basic_istream< CharT, Traits >& is,
		CharT const& should_be
	){
		auto result = test(is, should_be);
		if(!result) is.setstate(std::ios_base::failbit);
		return result;
	}


}

#endif
