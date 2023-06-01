#include <iostream>
#include <fstream>
#include <string>
using namespace std;
template<typename T>
struct File
{
	fstream file;
	string path;
	bool isBinary;
	File() {
		this->path = "file.txt";
	}
	File(bool isBinary) {
		this->isBinary = isBinary;
		this->path = "file.dat";
	}
	File(string path, bool isBinary) {
		this->path = path;
		this->isBinary = isBinary;
	}
	void save_to_file_txt(const T& data) {
		this->file.open(this->path, ios::out | ios::app);
		if (!this->file.is_open())
			cout << "File not open!" << endl;
		else
		{
			this->file << data << endl;
			this->file.close();
		}
	}
	void read_from_file_txt(T& data) {
		this->file.open(this->path, ios::in);
		if (!this->file.is_open())
			cout << "File not open!" << endl;
		else
		{
			this->file >> data;
			this->file.close();
		}
	}
	void save_to_file_binary(const T& data) {
		this->file.open(this->path, ios::out | ios::binary | ios::app | ios::binary);
		if (!this->file.is_open())
			cout << "File not open!" << endl;
		else
		{
			this->file.write(reinterpret_cast<const char*>(&data), sizeof(T));
			this->file.close();
		}
	}
	void read_from_file_binary(T& data) {
		this->file.open(this->path, ios::in | ios::binary);
		if (!this->file.is_open())
			cout << "File not open!" << endl;
		else
		{
			this->file.read(reinterpret_cast<char*>(&data), sizeof(T));
			this->file.close();
		}
	}
};
struct Application {
	string name;
	string version;
	int size;
};
int main() {
	File<Application> file("data.txt", false);
}