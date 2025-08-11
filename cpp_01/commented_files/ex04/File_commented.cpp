/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File_commented.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:17 by icunha-t          #+#    #+#             */
/*   Updated: 2025/08/11 15:17:42 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/File.hpp"

/*******************************************************************/
/*                     Constructor and Destructor                  */
/*******************************************************************/

File::File(){}

File::~File(){}

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
/*                        Helper functions                         */
/*******************************************************************/

std::string 
openAndRead(std::string fileName){
	std::ifstream inFile(fileName.c_str()); //standard input file stream - used to open and read from files
	if (!inFile)
		return "";
	std::ostringstream buffer; // creates buffer to be written into
	buffer << inFile.rdbuf(); //reads from infile into buffer
	std::string content = buffer.str(); //converts full file into a string

	return content;
}

std::string transformContent(const std::string content, const std::string s1, const std::string s2){
	std::string newContent;
	size_t currPos = 0;
	size_t foundPos;
	
	//find finds the first occurance of s1  starting in currPos and returns the index of the match position (foundPos)
	//while foundPos is different from npos (no positions / no more matches)
	while((foundPos = content.find(s1, currPos)) != std::string::npos){
		newContent += content.substr(currPos, (foundPos - currPos)); //adds chunck from currPos to foundPos
		newContent += s2; //adds s2 (substitution)
		currPos = foundPos + s1.length(); //transforms currPos to after s1
	}
	newContent += content.substr(currPos); //remaining part of string after last match

	return newContent;
}

void writeNewFile(const std::string fileName, const std::string newContent){
	std::string newFileName = fileName + ".replace";
	std::ofstream outFile(newFileName.c_str()); //standard output file stream - used to open/create and write into a file
	if (!outFile.is_open()){ //check if the file opened
		std::cout << RED << "Error: failed to open output file." << RES << std::endl;
		return ;
	}
	outFile << newContent; //copy content into new file
	outFile.close();
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
