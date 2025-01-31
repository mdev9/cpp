/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:51:04 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/28 07:36:19 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

std::string	replace(std::string& str, const std::string& from, const std::string& to, int start_pos)
{
	std::string start;
	std::string end;
	
	start = str.substr(0, start_pos);
	end = str.substr(start_pos + from.length(), str.length());
	return (start + to + end);
}

void replaceAll(std::string& str, const std::string& from, const std::string& to)
{
    if (from.empty())
        return;
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		str = replace(str, from, to, start_pos);
        start_pos += to.length();
	}
}

int	main(int ac, char **av)
{
	char *infile_name = av[1];
	char *s1 = av[2];
	char *s2 = av[3];

	if (ac != 4)
	{
		std::cout << "Incorrect number of arguments!\n";
		return (1);
	}
	std::ifstream infile(infile_name);
	std::string outfile_name = infile_name;
	outfile_name.append(".replace");
	std::ofstream outfile(outfile_name.c_str());
	std::string line;
	if (infile.is_open() && outfile.is_open())
	{
		while (infile)
		{
			std::getline(infile, line);
			replaceAll(line, s1, s2);
			outfile << line;
			if (infile)
				outfile << std::endl;
		}
		infile.close();
		outfile.close();
	}
	else
		std::cout << "Couldn't open file " << infile_name << std::endl;
}
