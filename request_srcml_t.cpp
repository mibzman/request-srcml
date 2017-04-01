/*
  @file request_srcml_t.cpp

  Test program for request_srcml()
*/

#include "request_srcml.hpp"
#include <cassert>

int main() {

	// all filenames and languages empty
    {
    	srcml_request request = { "", "", "", ""};
    	assert(request_filename(request) == "");
    	assert(request_language(request, "") == "");
    }

	// not a source code archive, just a regular old file
    {
        srcml_request request = { "", "main.cpp", "data", ""};
        std::string result_filename = request_filename(request);
        assert(result_filename == "main.cpp");
        assert(request_language(request, result_filename) == "C++");
    }

	// a source code archive
    {
        srcml_request request = { "", "", "main.cpp", ""};
        std::string result_filename = request_filename(request);
        assert(result_filename == "main.cpp");
        assert(request_language(request, result_filename) == "C++");
    }

	//filename based on option
    {
        srcml_request request = { "main.cpp", "ignoreMe.cpp", "data", ""};
        std::string result_filename = request_filename(request);
        assert(result_filename == "main.cpp");
        assert(request_language(request, result_filename) == "C++");
    }

	//language based on option
    {
        srcml_request request = { "", "main.dpp", "data", "C++"};
        std::string result_filename = request_filename(request);
        assert(request_language(request, result_filename) == "C++");
    }

	//stdin with option filename
    {
        srcml_request request = { "main.cpp", "-", "data", ""};
        std::string result_filename = request_filename(request);
        assert(result_filename == "main.cpp");
        assert(request_language(request, result_filename) == "C++");
    }

        //stdin with option language
    {
        srcml_request request = { "", "-", "data", "C++"};
        std::string result_filename = request_filename(request);
        assert(request_language(request, result_filename) == "C++");
    }


    return 0;
}
