//-----------------------------------------------------------------------------
// Copyright (c) 2018 Benjamin Buch
//
// https://github.com/bebuch/io_tools
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
//-----------------------------------------------------------------------------
#include <io_tools/mask_non_print.hpp>

#include "gtest/gtest.h"

#include "time_zone_offset.hpp"

#include <iomanip>


namespace{


	std::string to_hex(char const v){
		std::ostringstream os;
		os << std::hex << std::uppercase << std::setw(2) << std::setfill('0')
			<< static_cast< int >(v);
		return os.str();
	}

	void append_ascii_printables(std::string& in, std::string& out){
		for(char c = 32; c < 127; ++c){
			if(c != '\\'){
				in += c;
				out += c;
			}else{
				in += c;
				out += "\\\\";
			}
		}
	}

	void append_ascii_control(std::string& in, std::string& out){
		for(char c = 0; c < 32; ++c){
			in += c;
			switch(c){
				case  0: out += "\\0"; break;
				case  7: out += "\\a"; break;
				case  8: out += "\\b"; break;
				case  9: out += "\\t"; break;
				case 10: out += "\\n"; break;
				case 11: out += "\\v"; break;
				case 12: out += "\\f"; break;
				case 13: out += "\\r"; break;
				default: out += "\\x" + to_hex(c);
			}
		}
	}


}


TEST(mask_non_print, ascii_printable){
	std::string in;
	std::string out;
	in.reserve(95);
	out.reserve(95);

	append_ascii_printables(in, out);

	EXPECT_EQ(io_tools::mask_non_print(in), out);
}

TEST(mask_non_print, ascii_nonprintable){
	std::string in;
	std::string out;
	in.reserve(32);
	out.reserve(32);

	append_ascii_control(in, out);

	in += 127;
	out += "\\x7F";

	EXPECT_EQ(io_tools::mask_non_print(in), out);
}

TEST(mask_non_print, utf8){
	std::string in = "»«";
	std::string out = "\\xC2\\xBB\\xC2\\xAB";

	EXPECT_EQ(io_tools::mask_non_print(in), out);
}

TEST(mask_non_print, full_8bit){
	std::string in;
	std::string out;
	in.reserve(256);
	out.reserve(256);

	append_ascii_control(in, out);
	append_ascii_control(in, out);

	in += 127;
	out += "\\x7F";

	EXPECT_EQ(io_tools::mask_non_print(in), out);
}
