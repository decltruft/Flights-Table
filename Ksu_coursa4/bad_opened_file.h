#pragma once

#include <exception>

class bad_opened_file : public std::exception		// класс-исключение. бросается при некорректном имени файла. унаследован от std::exception
{
public:
	const char* what() const override
	{
		return "File was not opened: it does not existe!";
	}
};