//-----------------------------------------------------------------------------
// Copyright (c) 2018 Benjamin Buch
//
// https://github.com/bebuch/io_tools
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
//-----------------------------------------------------------------------------
#include <io_tools/make_string.hpp>

#include "gtest/gtest.h"


using io_tools::make_string;
using io_tools::make_string_separated_by;


TEST(make_string, nothing){
	EXPECT_EQ(make_string(), "");
}

TEST(make_string, one_int){
	EXPECT_EQ(make_string(5), "5");
}

TEST(make_string, one_float){
	EXPECT_EQ(make_string(0.4), "0.4");
}

TEST(make_string, int_float){
	EXPECT_EQ(make_string(5, 0.4), "50.4");
}

TEST(make_string, int_char_string){
	EXPECT_EQ(make_string(5, 'x', 0.4), "5x0.4");
}

TEST(make_string, int_cstring_string){
	EXPECT_EQ(make_string(5, "x", 0.4), "5x0.4");
}

TEST(make_string, true_noboolalpha_true){
	EXPECT_EQ(make_string(true, std::noboolalpha, true), "true1");
}

TEST(make_string, false_noboolalpha_false){
	EXPECT_EQ(make_string(false, std::noboolalpha, false), "false0");
}


TEST(make_string_separated_by, nothing){
	EXPECT_EQ(make_string_separated_by(
		'-'), "");
}

TEST(make_string_separated_by, one_int){
	EXPECT_EQ(make_string_separated_by(
		'-', 5), "5");
}

TEST(make_string_separated_by, one_float){
	EXPECT_EQ(make_string_separated_by(
		'-', 0.4), "0.4");
}

TEST(make_string_separated_by, int_float){
	EXPECT_EQ(make_string_separated_by(
		'-', 5, 0.4), "5-0.4");
}

TEST(make_string_separated_by, int_char_string){
	EXPECT_EQ(make_string_separated_by(
		'-', 5, 'x', 0.4), "5-x-0.4");
}

TEST(make_string_separated_by, int_cstring_string){
	EXPECT_EQ(make_string_separated_by(
		'-', 5, "x", 0.4), "5-x-0.4");
}

TEST(make_string_separated_by, true_noboolalpha_true){
	EXPECT_EQ(make_string_separated_by(
		'-', true, std::noboolalpha, true), "true--1");
}

TEST(make_string_separated_by, false_noboolalpha_false){
	EXPECT_EQ(make_string_separated_by(
		'-', false, std::noboolalpha, false), "false--0");
}
