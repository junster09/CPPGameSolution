#pragma once
#ifndef STATS_H
#define STATS_H

#include <string>

class Stats {
public:
	Stats(const std::string&, const std::string&, const unsigned int&,
		const unsigned int&, const unsigned int&, const unsigned int&);

	//BEGIN GETTERS AND SETTERS
	void setName(const std::string&);
	std::string getName() const;

	void setTextBlurb(const std::string&);
	std::string getTextBlurb() const;

	void setHP(const unsigned int&);
	unsigned int getHP() const;

	void setS(const unsigned int&);
	unsigned int getS() const;

	void setW(const unsigned int&);
	unsigned int getW() const;

	void setB(const unsigned int&);
	unsigned int getB() const;
	//END GETTERS AND SETTERS

private:
	std::string name;
	std::string textBlurb;
	unsigned int hp;//hit points
	unsigned int s;//speed
	unsigned int w;//wit
	unsigned int b;//brawn
};



#endif