 // Workshop 4 - Templates
 // w4.cpp
//Author:  Dr. Elliott Coleshill
//Date:    2018-08-22

#include <iostream>
 #include <iomanip>
 #include <string>
 #include <fstream>
 #include "Pair.h"
 #include "List.h"

 int main(int argc, char** argv) {
	 int width;
     bool keepreading;

	 std::ofstream ofs("Lab3Output.txt");

     std::cout << std::fixed << std::setprecision(2);

     std::cout << "\nInventory\n=========\n";
	 List <Pair<std::string, double>, 5> inventory;

     std::string str;
     double price;

     keepreading = true;
     do {
          std::cout << "Product : ";
          getline(std::cin, str);
          if (str.compare("quit") == 0) {
              keepreading = false;
          } else {
              std::cout << "Price : ";
              std::cin >> price;
              std::cin.ignore();
              Pair <std::string, double> pair(str, price);
              inventory += pair;
          }
     } while(keepreading);

     ofs << "\nPrice List\n-----------\n";
     for (int i = 0; i < inventory.size(); i++)
         ofs << inventory[i].getKey()
          << " : " << inventory[i].getValue() << std::endl;

     std::cout << "\nGlossary\n========\n";
     List <Pair<std::string, std::string>, 5> glossary;
     std::string key, definition;

     keepreading = true;
     do {
          std::cout << "Key : ";
          getline(std::cin, key);
          if (key.compare("quit") == 0) {
              keepreading = false;
          } else {
              std::cout << "Definition : ";
              getline(std::cin, definition);
              Pair <std::string, std::string> pair(key, definition);
              glossary += pair;
          }
     } while(keepreading);

     ofs << "\nEntries\n-------\n";
     for (int i = 0; i < glossary.size(); i++)
         ofs << glossary[i].getKey()
          << " : " << glossary[i].getValue() << std::endl;

	 ofs.close();
 }

