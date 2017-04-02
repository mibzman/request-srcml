/*
  @file request_srcml.cpp

  Implementation of request_srcml()
*/

#include "request_srcml.hpp"
#include "get_language_from_filename.hpp"
#include <iostream>

// extracts the filename to use from the request
std::string request_filename(const srcml_request& request) {

    std::string filename = request.entry_filename;

    if (request.option_filename != "") {
        return request.option_filename;
    }
    
    if (request.entry_filename == "data") {
        filename = request.local_filename;
    }

    if (request.local_filename == "-") {
        filename = "";
    }

    return filename;
}

// extracts the language to use from the request, and the filename
std::string request_language(const srcml_request& request, const std::string& filename) {

    std::string language;

    if (request.option_language != "") {
        return request.option_language;
    }

    language = get_language_from_filename(filename);

    return language;
}

// generates srcML based on the request
bool generate_srcml(const srcml_request& request) {

	std::string filename = request_filename(request);

	std::string language = request_language(request, filename);

        if (filename == "" && language == "") {
            std::cerr << "Using stdin requires a declared language" << std::endl;
            return false;
        }

        if (language == "") {
            std::cerr << "Extension not supported" << std::endl;
            return false;
        }


	// srcML generation code that is not available yet
	return true;
}
