//-----------------------------------------------------------------------------
// Copyright (c) 2018 Benjamin Buch
//
// https://github.com/bebuch/io_tools
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
//-----------------------------------------------------------------------------
#include <io_tools/extract_if_is.hpp>

#include <sstream>

#include "gtest/gtest.h"


TEST(extract_if_is, test_with_data){
	std::istringstream is("y");

	EXPECT_TRUE(!io_tools::extract_if_is(is, 'n'));
	ASSERT_TRUE(is);

	EXPECT_TRUE(io_tools::extract_if_is(is, 'y'));
	ASSERT_TRUE(is);

	EXPECT_TRUE(!io_tools::extract_if_is(is, 'y'));
	ASSERT_TRUE(is);
}

TEST(extract_if_is, test_without_data){
	std::istringstream is("");

	EXPECT_TRUE(!io_tools::extract_if_is(is, 'n'));
	ASSERT_TRUE(is);
}
