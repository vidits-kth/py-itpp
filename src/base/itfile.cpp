//! -------------------------------------------------------------------------
//!
//! Copyright (C) 2016 CC0 1.0 Universal (CC0 1.0)
//!
//! The person who associated a work with this deed has dedicated the work to
//! the public domain by waiving all of his or her rights to the work
//! worldwide under copyright law, including all related and neighboring
//! rights, to the extent allowed by law.
//!
//! You can copy, modify, distribute and perform the work, even for commercial
//! purposes, all without asking permission.
//!
//! See the complete legal text at
//! <https://creativecommons.org/publicdomain/zero/1.0/legalcode>
//!
//! -------------------------------------------------------------------------

#include <boost/python.hpp>
#include <itpp/base/itfile.h>

BOOST_PYTHON_MODULE(itfile) {
  boost::python::docstring_options local_docstring_options(true, true, false);

  boost::python::class_<itpp::it_file_base, boost::noncopyable>("it_file_base",
                                                                "The IT++ file format is a file format that can be used to save (load) variables to (from) files. "
                                                                "These files can also be read an written by Matlab or Octave using the m-files itload.m and itsave.m. "
                                                                "The class it_ifile is used for reading only, whereas the class it_file can be used for both reading and writing. "
                                                                ""
                                                                "Saving of a variable is done in two steps. The first step is to supply the name and optionally description "
                                                                "of the variable to be saved. This can be done either by calling the function it_file::set_next_name() or "
                                                                "by using the helper class Name."
                                                                ""
                                                                "IT++ file format uses the IEEE little endian byte ordering (\"ieee-le\" in Matlab/Octave). "
                                                                "Warning: Do not use the names that begin with an existing type.",
				                                boost::python::no_init)

    ;

    boost::python::class_<itpp::it_ifile, boost::python::bases<itpp::it_file_base>
                                        , boost::noncopyable >("it_ifile",
							       "The IT++ file format reading class.",
							       boost::python::init<>("Default constructor", boost::python::args("self")))

    .def(boost::python::init<const std::string&>("Constructor that calls open(filename)", boost::python::args("self", "filename")))

    .def("open", &itpp::it_ifile::open
               , "Open an existing file in read-only mode"
	       , boost::python::args("self", "filename"))
    .def("close", &itpp::it_ifile::close
                , "Close the file"
	        , boost::python::args("self"))
    .def("low_level", &itpp::it_ifile::low_level
		    , "Returns pointer to the underlying bfstream used"
		    , boost::python::args("self")
                    , boost::python::return_internal_reference<>())

    .def("read_check_file_header", &itpp::it_ifile::read_check_file_header
		                 , "Read and check the file header. Return true if the header is valid and false otherwise."
		                 , boost::python::args("self")
		                 , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("read_data_header", &itpp::it_ifile::read_data_header
		           , "Read data header and return the result in the variable h"
		           , boost::python::args("self", "h"))

    .def("low_level_read", static_cast<void (itpp::it_ifile::*)(char &)>(&itpp::it_ifile::low_level_read)
			 , "Read a char value at the current file pointer position"
			 , boost::python::args("self", "x"))
    .def("low_level_read", static_cast<void (itpp::it_ifile::*)(uint64_t &)>(&itpp::it_ifile::low_level_read)
			 , "Read a 64-bit unsigned integer value at the current file pointer position"
			 , boost::python::args("self", "x"))
    .def("low_level_read", static_cast<void (itpp::it_ifile::*)(bool &)>(&itpp::it_ifile::low_level_read)
			 , "Read a bool value at the current file pointer position"
			 , boost::python::args("self", "x"))

    .def("low_level_read", static_cast<void (itpp::it_ifile::*)(itpp::bin &)>(&itpp::it_ifile::low_level_read)
			 , "Read a binary value at the current file pointer position"
			 , boost::python::args("self", "x"))
    .def("low_level_read", static_cast<void (itpp::it_ifile::*)(short &)>(&itpp::it_ifile::low_level_read)
			 , "Read a short value at the current file pointer position"
			 , boost::python::args("self", "x"))
    .def("low_level_read", static_cast<void (itpp::it_ifile::*)(int &)>(&itpp::it_ifile::low_level_read)
			 , "Read an integer value at the current file pointer position"
			 , boost::python::args("self", "x"))
    .def("low_level_read", static_cast<void (itpp::it_ifile::*)(float &)>(&itpp::it_ifile::low_level_read)
			 , "Read a float value at the current file pointer position"
			 , boost::python::args("self", "x"))
    .def("low_level_read", static_cast<void (itpp::it_ifile::*)(double &)>(&itpp::it_ifile::low_level_read)
			 , "Read a double value at the current file pointer position"
			 , boost::python::args("self", "x"))
    .def("low_level_read", static_cast<void (itpp::it_ifile::*)(std::complex<float> &)>(&itpp::it_ifile::low_level_read)
			 , "Read a float complex value at the current file pointer position"
			 , boost::python::args("self", "x"))
    .def("low_level_read", static_cast<void (itpp::it_ifile::*)(std::complex<double> &)>(&itpp::it_ifile::low_level_read)
			 , "Read a double complex value at the current file pointer position"
			 , boost::python::args("self", "x"))

    .def("low_level_read", static_cast<void (itpp::it_ifile::*)(itpp::bvec &)>(&itpp::it_ifile::low_level_read)
			 , "Read a vector of binary values at the current file pointer position"
			 , boost::python::args("self", "v"))
    .def("low_level_read", static_cast<void (itpp::it_ifile::*)(itpp::svec &)>(&itpp::it_ifile::low_level_read)
			 , "Read a vector of short values at the current file pointer position"
			 , boost::python::args("self", "v"))
    .def("low_level_read", static_cast<void (itpp::it_ifile::*)(itpp::ivec &)>(&itpp::it_ifile::low_level_read)
			 , "Read a vector of  integer values at the current file pointer position"
			 , boost::python::args("self", "v"))
    .def("low_level_read_lo", static_cast<void (itpp::it_ifile::*)(itpp::vec &)>(&itpp::it_ifile::low_level_read_lo)
			    , "Read a vector of float values at the current file pointer position"
			    , boost::python::args("self", "v"))
    .def("low_level_read_hi", static_cast<void (itpp::it_ifile::*)(itpp::vec &)>(&itpp::it_ifile::low_level_read_hi)
			    , "Read a vector of double values at the current file pointer position"
			    , boost::python::args("self", "v"))
    .def("low_level_read_lo", static_cast<void (itpp::it_ifile::*)(itpp::cvec &)>(&itpp::it_ifile::low_level_read_lo)
			    , "Read a vector of float complex values at the current file pointer position"
			    , boost::python::args("self", "v"))
    .def("low_level_read_hi", static_cast<void (itpp::it_ifile::*)(itpp::cvec &)>(&itpp::it_ifile::low_level_read_hi)
			    , "Read a vector of double complex values at the current file pointer position"
			    , boost::python::args("self", "v"))

    .def("low_level_read", static_cast<void (itpp::it_ifile::*)(std::string &)>(&itpp::it_ifile::low_level_read)
			 , "Read a string at the current file pointer position"
			 , boost::python::args("self", "str"))

    .def("low_level_read", static_cast<void (itpp::it_ifile::*)(itpp::bmat &)>(&itpp::it_ifile::low_level_read)
			 , "Read a matrix of binary values at the current file pointer position"
			 , boost::python::args("self", "m"))
    .def("low_level_read", static_cast<void (itpp::it_ifile::*)(itpp::smat &)>(&itpp::it_ifile::low_level_read)
			 , "Read a matrix of short values at the current file pointer position"
			 , boost::python::args("self", "m"))
    .def("low_level_read", static_cast<void (itpp::it_ifile::*)(itpp::imat &)>(&itpp::it_ifile::low_level_read)
			 , "Read a matrix of  integer values at the current file pointer position"
			 , boost::python::args("self", "m"))
    .def("low_level_read_lo", static_cast<void (itpp::it_ifile::*)(itpp::mat &)>(&itpp::it_ifile::low_level_read_lo)
			    , "Read a matrix of float values at the current file pointer position"
			    , boost::python::args("self", "m"))
    .def("low_level_read_hi", static_cast<void (itpp::it_ifile::*)(itpp::mat &)>(&itpp::it_ifile::low_level_read_hi)
			    , "Read a matrix of double values at the current file pointer position"
			    , boost::python::args("self", "m"))
    .def("low_level_read_lo", static_cast<void (itpp::it_ifile::*)(itpp::cmat &)>(&itpp::it_ifile::low_level_read_lo)
			    , "Read a matrix of float complex values at the current file pointer position"
			    , boost::python::args("self", "m"))
    .def("low_level_read_hi", static_cast<void (itpp::it_ifile::*)(itpp::cmat &)>(&itpp::it_ifile::low_level_read_hi)
			    , "Read a matrix of double complex values at the current file pointer position"
			    , boost::python::args("self", "m"))

    .def("seek", static_cast<bool (itpp::it_ifile::*)(const std::string &)>(&itpp::it_ifile::seek)
	       , "Find the variable by name"
	       , boost::python::args("self", "name")
               , boost::python::return_value_policy<boost::python::return_by_value>())
    .def("seek", static_cast<bool (itpp::it_ifile::*)(int)>(&itpp::it_ifile::seek)
	       , "Find the variable by number"
	       , boost::python::args("self", "n")
	       , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("info", &itpp::it_ifile::info
	       , "Get information about the current variable"
	       , boost::python::args("self", "name", "type", "desc", "bytes"))

    ;

    boost::python::class_<itpp::it_file, boost::python::bases<itpp::it_ifile>
                                       , boost::noncopyable >("it_file",
							      "The IT++ file format reading and writing class",
							      boost::python::init<>("Default constructor", boost::python::args("self")))

    .def(boost::python::init<const std::string&, bool>("Constructor that calls open(filename), "
	                                               "If the file does not exist it will be created. If trunc is true,"
	                                               "the file will be truncated.",
						       boost::python::args("self", "filename", "trunc")))

    .def("open", &itpp::it_file::open
               , "Open a file for reading and writing. If the file does not exist it will be created. "
        	 "If trunc is true, the file will be truncated."
	       , boost::python::args("self", "filename", "trunc"))

    .def("close", &itpp::it_file::close
                , "Close the file"
	        , boost::python::args("self"))

    .def("flush", &itpp::it_file::flush
		, "Flush the data to disk"
		, boost::python::args("self"))

    .def("low_level", &itpp::it_file::low_level
		    , "Returns pointer to the underlying bfstream used"
		    , boost::python::args("self")
                    , boost::python::return_internal_reference<>())

    .def("set_low_precision", &itpp::it_file::set_low_precision
		            , "Set the precision. Low precision means floats, high means doubles."
		            , boost::python::args("self", "p"))
    .def("get_low_precision", &itpp::it_file::get_low_precision
		            , "Get the precision"
		            , boost::python::args("self")
                            , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("set_next_name", &itpp::it_file::set_next_name
			, "Set the name and optionally description of the next variable to be saved."
			, boost::python::args("self", "name", "description"))

    .def("write_file_header", &itpp::it_file::write_file_header
		            , "Write the header for the it_file"
		            , boost::python::args("self"))
    .def("write_data_header", static_cast<void (itpp::it_file::*)(const std::string &, uint64_t)>(&itpp::it_file::write_data_header)
			    , "Write the data header for a variable, specifying the type and size of the data to follow."
			    , boost::python::args("self", "type", "size"))
    .def("write_data_header", static_cast<void (itpp::it_file::*)(const std::string &, const std::string &, uint64_t, const std::string &)>(&itpp::it_file::write_data_header)
			    , "Write the data header for a variable, specifying the type, name, size and optionally description of the data to follow."
			    , boost::python::args("self", "type", "name", "size", "description"))

    .def("low_level_write", static_cast<void (itpp::it_file::*)(char)>(&itpp::it_file::low_level_write)
			  , "Write a char value at the current file pointer position"
			  , boost::python::args("self", "x"))
    .def("low_level_write", static_cast<void (itpp::it_file::*)(uint64_t)>(&itpp::it_file::low_level_write)
			  , "Write a 64-bit unsigned integer value at the current file pointer position"
			  , boost::python::args("self", "x"))
    .def("low_level_write", static_cast<void (itpp::it_file::*)(bool)>(&itpp::it_file::low_level_write)
			  , "Write a bool value at the current file pointer position"
			  , boost::python::args("self", "x"))

    .def("low_level_write", static_cast<void (itpp::it_file::*)(itpp::bin)>(&itpp::it_file::low_level_write)
			  , "Write a binary value at the current file pointer position"
			  , boost::python::args("self", "x"))
    .def("low_level_write", static_cast<void (itpp::it_file::*)(short)>(&itpp::it_file::low_level_write)
			  , "Write a short value at the current file pointer position"
			  , boost::python::args("self", "x"))
    .def("low_level_write", static_cast<void (itpp::it_file::*)(int)>(&itpp::it_file::low_level_write)
			  , "Write an integer value at the current file pointer position"
			  , boost::python::args("self", "x"))
    .def("low_level_write", static_cast<void (itpp::it_file::*)(float)>(&itpp::it_file::low_level_write)
			  , "Write a float value at the current file pointer position"
			  , boost::python::args("self", "x"))
    .def("low_level_write", static_cast<void (itpp::it_file::*)(double)>(&itpp::it_file::low_level_write)
			  , "Write a double value at the current file pointer position"
			  , boost::python::args("self", "x"))
    .def("low_level_write", static_cast<void (itpp::it_file::*)(const std::complex<float> &)>(&itpp::it_file::low_level_write)
			  , "Write a float complex value at the current file pointer position"
			  , boost::python::args("self", "x"))
    .def("low_level_write", static_cast<void (itpp::it_file::*)(const std::complex<double> &)>(&itpp::it_file::low_level_write)
			  , "Write a double complex value at the current file pointer position"
			  , boost::python::args("self", "x"))

    .def("low_level_write", static_cast<void (itpp::it_file::*)(const itpp::bvec &)>(&itpp::it_file::low_level_write)
			  , "Write a vector of binary values at the current file pointer position"
			  , boost::python::args("self", "v"))
    .def("low_level_write", static_cast<void (itpp::it_file::*)(const itpp::svec &)>(&itpp::it_file::low_level_write)
			  , "Write a vector of short values at the current file pointer position"
			  , boost::python::args("self", "v"))
    .def("low_level_write", static_cast<void (itpp::it_file::*)(const itpp::ivec &)>(&itpp::it_file::low_level_write)
			  , "Write a vector of  integer values at the current file pointer position"
			  , boost::python::args("self", "v"))
    .def("low_level_write", static_cast<void (itpp::it_file::*)(const itpp::vec &)>(&itpp::it_file::low_level_write)
			  , "Write a vector of float values at the current file pointer position"
			  , boost::python::args("self", "v"))
    .def("low_level_write", static_cast<void (itpp::it_file::*)(const itpp::cvec &)>(&itpp::it_file::low_level_write)
			  , "Write a vector of float complex values at the current file pointer position"
			  , boost::python::args("self", "v"))

    .def("low_level_write", static_cast<void (itpp::it_file::*)(const std::string &)>(&itpp::it_file::low_level_write)
			  , "Write a string at the current file pointer position"
			  , boost::python::args("self", "str"))

    .def("low_level_write", static_cast<void (itpp::it_file::*)(const itpp::bmat &)>(&itpp::it_file::low_level_write)
			  , "Write a matrix of binary values at the current file pointer position"
			  , boost::python::args("self", "m"))
    .def("low_level_write", static_cast<void (itpp::it_file::*)(const itpp::smat &)>(&itpp::it_file::low_level_write)
			  , "Write a matrix of short values at the current file pointer position"
			  , boost::python::args("self", "m"))
    .def("low_level_write", static_cast<void (itpp::it_file::*)(const itpp::imat &)>(&itpp::it_file::low_level_write)
			  , "Write a matrix of  integer values at the current file pointer position"
			  , boost::python::args("self", "m"))
    .def("low_level_write", static_cast<void (itpp::it_file::*)(const itpp::mat &)>(&itpp::it_file::low_level_write)
			  , "Write a matrix of float values at the current file pointer position"
			  , boost::python::args("self", "m"))
    .def("low_level_write", static_cast<void (itpp::it_file::*)(const itpp::cmat &)>(&itpp::it_file::low_level_write)
			  , "Write a matrix of float complex values at the current file pointer position"
			  , boost::python::args("self", "m"))

//    .def("remove", &itpp::it_file::remove
//  	         , "Removes the variable by name from the file"
//	         , boost::python::args("self", "name"))

    .def("exists", &itpp::it_file::exists
  	         , "Returns true if the variable by name exists in the file"
	         , boost::python::args("self", "name")
	         , boost::python::return_value_policy<boost::python::return_by_value>())

    .def("pack", &itpp::it_file::pack
	       , "Remove slack space from the file"
	       , boost::python::args("self"))

  ;

}
