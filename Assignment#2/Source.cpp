#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct STUDENT_DATA {
    std::string fn;
    std::string ln;
};

int main() {
    std::ifstream file("StudentData.txt");
    std::vector<STUDENT_DATA> students;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string fn, ln;

            std::getline(ss, fn, ',');
            std::getline(ss, ln);

            students.push_back({ fn, ln });
        }
        file.close();
    }
    #ifdef _DEBUG
        for (const auto& student : students)   
        {
        std::cout << student.fn << " " << student.ln << std::endl;
        }
    #endif

    return 0;
}