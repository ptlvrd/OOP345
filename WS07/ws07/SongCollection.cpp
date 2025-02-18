/*
Name- Vrundaben vijaykumar patel
id-158605220
email-vvpatel20@myseneca.ca
workshop7-part2
OPP344 section:NCC
date 16/03/2024
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <string>
#include "SongCollection.h"

using namespace std;
namespace seneca {
	void SongCollection::trim(string& src)
	{
		if (src.length() > 0) {
			int begin = src.find_first_not_of(' ');
			int end = src.find_last_not_of(' ');
			if (begin == -1) src = "";
			else src = src.substr(begin, end - begin + 1);
		}
	}
	SongCollection::SongCollection(string filename) {
		ifstream file(filename);

		if (!file) {
			throw string("Unable to open the file!");
		}

		Song tempSong;
		string temp;
		do
		{
			getline(file, temp);
			if (file) {
				tempSong.m_title = temp.substr(0, 25);
				trim(tempSong.m_title);
				tempSong.m_artist = temp.substr(25, 25);
				trim(tempSong.m_artist);
				tempSong.m_album = temp.substr(50, 25);
				trim(tempSong.m_album);
				try {
					tempSong.m_year = stoi(temp.substr(75, 5));
				}
				catch (invalid_argument&) {
					tempSong.m_year = 0;
				}
				tempSong.m_length = stoi(temp.substr(80, 5));
				tempSong.m_price = stod(temp.substr(85, 5));
				m_song.push_back(tempSong);
			}

		} while (file);
		file.close();
	}

	void SongCollection::display(ostream& out) const{
		size_t totalPlaytime = 0;
		for_each(m_song.begin(), m_song.end(), [&out, &totalPlaytime](const Song& song) {out << song << endl; totalPlaytime += song.m_length; });
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "| " << std::right << std::setw(77) << "Total Listening Time: " << totalPlaytime / 3600 << ':' << (totalPlaytime % 3600) / 60 << ':' << totalPlaytime % 60 << " |\n";
	}

	ostream& operator<<(ostream& out, const Song& theSong) {
		out << "| " << left << setw(20) << theSong.m_title << " | " << left << setw(15) << theSong.m_artist;
		out << " | " << left << setw(20) << theSong.m_album << " | ";
		if (theSong.m_year == 0) {
			out << right << setw(6) << " ";
		}
		else {
			out << right << setw(6) << theSong.m_year;
		}
		out << " | " << theSong.m_length / 60 << ":" << setw(2) << setfill('0') << theSong.m_length % 60 << setfill(' ') << " | " << theSong.m_price << " |";
		return out;
	}

	void SongCollection::sort(const std::string& field)
	{
		std::sort(m_song.begin(), m_song.end(), [&field](const Song& song1, const Song& song2)
			{
				if (field == "album") return song1.m_album < song2.m_album;
				else if (field == "length") return song1.m_length < song2.m_length;
				else return song1.m_title < song2.m_title;
			}
		);
	}

	void SongCollection::cleanAlbum()
	{
		Song temp;
		replace_if(m_song.begin(), m_song.end(), [&temp](const Song& song) {temp = song; temp.m_album = ""; return song.m_album == "[None]"; }, temp);
	}

	bool SongCollection::inCollection(const std::string& artist) const
	{
		return any_of(m_song.begin(), m_song.end(), [&artist](const Song& song) {return song.m_artist == artist; });
	}

	std::list<Song> SongCollection::getSongsForArtist(const std::string& artist) const
	{
		std::list<Song> songlist(m_song.size());
		auto it = copy_if(m_song.begin(), m_song.end(), songlist.begin(), [&artist](const Song& song) {return song.m_artist == artist; });
		songlist.resize(std::distance(songlist.begin(), it));
		return songlist;
	}
}