#pragma once

#include <exception>

class bad_opened_file : public std::exception		// �����-����������. ��������� ��� ������������ ����� �����. ����������� �� std::exception
{
public:
	const char* what() const override
	{
		return "File was not opened: it does not existe!";
	}
};