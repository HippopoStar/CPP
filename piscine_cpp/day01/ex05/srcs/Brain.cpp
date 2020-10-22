#include "Brain.hpp"

Brain::Brain(void) : _cortex_content("*empty*"), _lymbic_system_content("Monkey playing Jazz music")
{
}

Brain::~Brain(void)
{
}

std::string	Brain::identify(void) const
{
	std::ostringstream	oss;

	oss << "0x";
	oss << std::hex;
	oss << std::setiosflags(std::ios::uppercase);
	oss << (unsigned long int)this;
	return (oss.str());
}
