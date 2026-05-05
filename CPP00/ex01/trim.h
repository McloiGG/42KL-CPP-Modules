#pragma once
#ifndef TRIM_H
# define TRIM_H

# include <string>

std::string&	trim(std::string& s);
std::string		trim_copy(std::string s);
std::string&	trim_inner(std::string& s);
std::string		trim_inner_copy(std::string s);

#endif
