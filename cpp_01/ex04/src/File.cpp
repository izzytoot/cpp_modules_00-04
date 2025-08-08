/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/08 14:49:34 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/File.hpp"

/*******************************************************************/
/*                     Constructor and Destructor                  */
/*******************************************************************/

File::File(){}

File::~File(){}

/*******************************************************************/
/*                        Setter functions                         */
/*******************************************************************/

void File::setFileName(std::string fileName){
	_fileName = fileName;
}

void File::setS1(std::string s1){
	_s1 = s1;
}

void File::setS2(std::string s2){
	_s2 = s2;
}

/*******************************************************************/
/*                     Methods / Member function                   */
/*******************************************************************/

void File::transformFile(){
	std::string content;
	content = openAndRead(_fileName);
	if (content == ""){
		std::cout << RED << "Error: failed to open input file." << RES << std::endl;
		return ;
	}
	std::string newContent;
	newContent = transformContent(content, _s1, _s2);
	writeNewFile(_fileName, newContent);
}

/*******************************************************************/
/*                        Helper functions                         */
/*******************************************************************/

std::string openAndRead(std::string fileName){
	std::ifstream inFile(fileName.c_str());
	if (!inFile)
		return "";
	std::ostringstream buffer;
	buffer << inFile.rdbuf();
	std::string content = buffer.str();

	return content;
}

std::string transformContent(const std::string content, const std::string s1, const std::string s2){
	std::string newContent;
	size_t currPos = 0;
	size_t foundPos;
	
	while((foundPos = content.find(s1, currPos)) != std::string::npos){
		newContent += content.substr(currPos, (foundPos - currPos));
		newContent += s2;
		currPos = foundPos + s1.length();
	}
	newContent += content.substr(currPos);

	return newContent;
}

void writeNewFile(const std::string fileName, const std::string newContent){
	std::string newFileName = fileName + ".replace";
	std::ofstream outFile(newFileName.c_str());
	if (!outFile.is_open()){
		std::cout << RED << "Error: failed to open output file." << RES << std::endl;
		return ;
	}
	outFile << newContent;
	outFile.close();
}