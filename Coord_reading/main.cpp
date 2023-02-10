#include <iostream>
#include <fstream>
#include <vector>
#include <string>
std::vector<std::string> split(const std::string &str, const std::string &delim)
{
    size_t start;
    size_t end = 0;
    std::vector <std::string> v2;
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        v2.push_back(str.substr(start, end - start));
    };
    return v2;
};
int main() {
    std::string delim;
   std::ifstream file;
   std::cout<<"Enter the deliminator"<<std::endl;
   std::cin>>delim;
   double y;
    std::string x;
    std::vector <double> v1;
   file.open("C:\\Users\\Nikita\\cpp_project\\Coord_reading\\info.txt");
    if (file.is_open())
        while (!file.eof()) {
            getline(file, x);
            auto vec = split(x, delim);
            for (auto &x: vec) {
                v1.push_back(std::stod(x));
                std::cout << x << std::endl;
            };
        }
    else std::cout << "error";
   file.close();
   for (auto y: v1)
       std::cout<<y<<std::endl;
   //Mission complete!~
    return 0;
}
