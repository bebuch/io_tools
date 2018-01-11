//-----------------------------------------------------------------------------
// Copyright (c) 2009-2018 Benjamin Buch
//
// https://github.com/bebuch/io_tools
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
//-----------------------------------------------------------------------------
#ifndef _io_tools__substreambuf__hpp_INCLUDED_
#define _io_tools__substreambuf__hpp_INCLUDED_

#include <streambuf>


namespace io_tools{


	class substreambuf: public std::streambuf{
	public:
		substreambuf(
			std::streambuf* buffer,
			std::streampos start,
			std::streamsize size
		):
			buffer_(buffer),
			start_(start),
			size_(size)
		{
			setbuf(nullptr, 0);
		}

		substreambuf(substreambuf const&) = delete;
		substreambuf(substreambuf&&) = default;

	protected:
		virtual void imbue(std::locale const& loc)override{
			 buffer_->pubimbue(loc);
		}

		virtual std::streambuf* setbuf(
			char_type* s,
			std::streamsize n
		)override{
			return buffer_->pubsetbuf(s, n);
		}

		virtual std::streampos seekoff(
			std::streamoff off,
			std::ios_base::seekdir dir,
			std::ios_base::openmode which =
				std::ios_base::in | std::ios_base::out
		)override{
			std::streampos new_pos;

			if(dir == std::ios_base::beg){
				new_pos = buffer_->pubseekpos(start_ + off, which);
			}else if(dir == std::ios_base::cur){
				new_pos = buffer_->pubseekoff(off, dir, which);
			}else{
				new_pos = buffer_->pubseekpos(
					start_ + std::streampos(size_) + off, which
				);
			}

			if(new_pos < start_ || new_pos >= start_ + std::streampos(size_)){
				return -1;
			}

			return new_pos;
		}

		virtual std::streampos seekpos(
			std::streampos pos,
			std::ios_base::openmode which =
				std::ios_base::in | std::ios_base::out
		)override{
			auto new_pos = buffer_->pubseekpos(start_ + pos, which);

			if(new_pos < start_ || new_pos >= start_ + std::streampos(size_)){
				return -1;
			}

			return new_pos;
		}

		virtual int sync()override{
			return buffer_->pubsync();
		}

		virtual int_type underflow()override{
			// TODO: Do something
// 			if(pos_ >= size_ - 1) return traits_type::eof();

			return buffer_->sgetc();
		}

		virtual int_type uflow()override{
			// TODO: Do something
// 			if(pos_ >= size_ - 1) return traits_type::eof();

// 			pos_ += std::streampos(1);

			return buffer_->sbumpc();
		}

		virtual std::streamsize xsgetn(
			char_type* s,
			std::streamsize count
		)override{
			return buffer_->sgetn(s, count);
		}

		virtual std::streamsize xsputn(
			char_type const* s,
			std::streamsize count
		)override{
			return buffer_->sputn(s, count);
		}


	private:
		std::streambuf* buffer_;
		std::streampos start_;
		std::streamsize size_;
	};

}


#endif
