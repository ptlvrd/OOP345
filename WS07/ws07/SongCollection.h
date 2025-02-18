/*
Name- Vrundaben vijaykumar patel
id-158605220
email-vvpatel20@myseneca.ca
workshop7-part2
OPP344 section:NCC
date 16/03/2024
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_SONGCOLLECTION_H
#define SENECA_SONGCOLLECTION_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

namespace seneca {
	struct Song {
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price = 0;
		size_t m_year = 0;
		size_t m_length = 0;
	};
	class SongCollection {
		std::vector<Song> m_song;
	public:
		SongCollection() {};
		SongCollection(std::string filename);
		void display(std::ostream& out) const;
		void trim(std::string& src);
		void sort(const std::string& field);
		void cleanAlbum();
		bool inCollection(const std::string& artist) const;
		std::list<Song> getSongsForArtist(const std::string& artist) const;
	}; 
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}



#endif // !SENECA_SONGCOLLECTION_H
