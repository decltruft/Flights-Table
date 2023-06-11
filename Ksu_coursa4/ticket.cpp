#include "ticket.h"

ticket::ticket()
{
	finished_point = " ";

	departuring_time.tm_mon  = 0;
	departuring_time.tm_mday = 0;
	departuring_time.tm_hour = 0;
	departuring_time.tm_min  = 0;

	arrival_time.tm_mon = 0;
	arrival_time.tm_mday = 0;
	arrival_time.tm_hour = 0;
	arrival_time.tm_min = 0;
}

ticket::ticket(std::tm dt, std::tm at, std::string fp) : departuring_time(dt), arrival_time(at), finished_point(fp)
{

}

void ticket::set_departuring_time(std::tm& dt)
{
	departuring_time = dt;
}

void ticket::set_arrival_time(std::tm& at)
{
	arrival_time = at;
}

void ticket::set_finished_point(std::string& fp)
{
	finished_point = fp;
}

std::string ticket::get_the_name_of_finished_point() const
{
	return finished_point;
}

std::tm ticket::get_departurning_time() const
{
	return departuring_time;
}

std::tm ticket::get_arrival_time() const
{
	return arrival_time;
}

std::ifstream& operator>>(std::ifstream& ifs, ticket& tic)
{
	std::tm departuring_time;
	std::tm arrival_time;
	std::string finished_point;

	ifs >> departuring_time.tm_mon >> departuring_time.tm_mday >> departuring_time.tm_hour >> departuring_time.tm_min
		>> arrival_time.tm_mon >> arrival_time.tm_mday >> arrival_time.tm_hour >> arrival_time.tm_min
		>> finished_point;

	tic.set_departuring_time(departuring_time);
	tic.set_arrival_time(arrival_time);
	tic.set_finished_point(finished_point);

	return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, const ticket& tic)
{
	ofs << tic.get_departurning_time().tm_mon << ' ' <<  tic.get_departurning_time().tm_mday << ' ' << tic.get_departurning_time().tm_hour
		<< ' ' << tic.get_departurning_time().tm_min
		<< ' ' << tic.get_arrival_time().tm_mon << ' ' << tic.get_arrival_time().tm_mday << ' ' << tic.get_arrival_time().tm_hour
		<< ' ' << tic.get_arrival_time().tm_min
		<< ' ' << tic.get_the_name_of_finished_point();

	return ofs;
}

std::ostream& operator<<(std::ostream& os, const ticket& tic)
{
	os << "Пункт назначения: " << tic.finished_point << "\nВремя отправки\\прибытия: " << tic.get_departurning_time().tm_mon << '.' << tic.get_departurning_time().tm_mday << '.' << tic.get_departurning_time().tm_hour
		<< '.' << tic.get_departurning_time().tm_min << '\\' << tic.get_arrival_time().tm_mon << '.' << tic.get_arrival_time().tm_mday << '.' << tic.get_arrival_time().tm_hour
		<< '.' << tic.get_arrival_time().tm_min << std::endl;

	return os;
}
