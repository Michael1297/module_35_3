#include <iostream>
#include <filesystem>
#include <vector>
#include <memory>


int main() {
    auto recursiveGetFileNamesByExtension = [](std::filesystem::path path, const std::string extension){
        auto file_name = std::make_unique<std::vector<std::string>>();
        for(auto& p: std::filesystem::recursive_directory_iterator(path)){
            if(p.is_regular_file()){
                if(p.path().extension().compare(extension) == 0) file_name->push_back(p.path().filename().string());
            }
        }
        return file_name;
    };

    auto files = recursiveGetFileNamesByExtension(std::filesystem::current_path(), ".txt");
    for(auto& file : *files) std::cout << file << "\n";
}