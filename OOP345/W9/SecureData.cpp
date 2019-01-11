// Workshop 9 - Multithreading
// SecureData.cpp
// Author: Chaz-Lee Pierre
// Date: 2018-11-16

 #include <iostream>
 #include <fstream>
 #include <string>
 #include <thread>
 #include <functional>
 #include "SecureData.h"

 namespace w10 {

     void converter(char* t, char key, int n, const Cryptor& c) {
         for (int i = 0; i < n; i++)
             t[i] = c(t[i], key);
     }

     SecureData::SecureData(const char* file, char key, std::ofstream* pOfs) {

		 ofs = pOfs;

		 // open text file
         std::fstream input(file, std::ios::in);
         if (!input)
             throw std::string("\n***Failed to open file ") +
              std::string(file) + std::string(" ***\n");

         // copy from file into memory
         nbytes = 0;
         input >> std::noskipws;
         while (input.good()) {
             char c;
             input >> c;
             nbytes++;
         }
         nbytes--;
         input.clear();
         input.seekg(0, std::ios::beg);
         text  = new char[nbytes + 1];

         int i = 0;
         while (input.good())
             input >> text[i++];
         text[--i] = '\0';
         *ofs << "\n" << nbytes << " bytes copied from text "
          << file << " into memory (null byte added)\n";
         encoded = false;

         // encode using key
         code(key);
         *ofs << "Data encrypted in memory\n";
     }

     SecureData::~SecureData() {
         delete [] text;
     }

     void SecureData::display(std::ostream& os) const {
         if (text && !encoded)
             os << text << std::endl;
         else if (encoded)
             throw std::string("\n***Data is encoded***\n");
         else
             throw std::string("\n***No data stored***\n");
     }

     void SecureData::code(char key) {
		 const int number_of_threads = 5;
		 int part = nbytes / number_of_threads;
		 std::thread threads[number_of_threads];
		 Cryptor cryptors[number_of_threads];
		 for (int i = 0; i < number_of_threads; i++)
			 threads[i] = std::thread(std::bind(converter, text + i * part, key, (i + 1 < number_of_threads) ? part : (nbytes - i * part), cryptors[i]));
		 for (int i = 0; i < number_of_threads; i++)
			 threads[i].join();
		 encoded = !encoded;
     }

     void SecureData::backup(const char* file) {
         if (!text)
             throw std::string("\n***No data stored***\n");
         else if (!encoded)
             throw std::string("\n***Data is not encoded***\n");
         else {
			 // open binary file
			 std::ofstream output(file);
			 if (!output)
				 throw std::string("File could not be opened.");
			 else
				 // write binary file here
				 output << text;
         }
     }

     void SecureData::restore(const char* file, char key) {
		// open binary file
		 std::fstream input(file, std::ios::in);
		 if (!input)
			 throw std::string("\n***Failed to open file ") +
			 std::string(file) + std::string(" ***\n");

		 // allocate memory here
		 if (text != nullptr) {
			 delete[] text;
			 text = nullptr;
		 }
		 nbytes = 0;
		 input >> std::noskipws;
		 while (input.good()) {
			 char c;
			 input >> c;
			 nbytes++;
		 }
		 nbytes--;
		 input.clear();
		 input.seekg(0, std::ios::beg);
		 text = new char[nbytes + 1];
		 
		 // read binary file here
		 int i = 0;
		 while (input.good())
			 input >> text[i++];
		 text[--i] = '\0';

         *ofs << "\n" << nbytes + 1 << " bytes copied from binary file "
          << file << " into memory (null byte included)\n";

         // decode using key
         code(key);
		 *ofs << "Data decrypted in memory\n\n";
	 }

	 std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		 sd.display(os);
		 return os;
	 }
 }