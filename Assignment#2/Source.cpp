#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct STUDENT_DATA {
    std::string fn;
    std::string ln;
    std::string email;
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
    std::cout << "The application is running in debug mode!";
        for (const auto& student : students)   
        {
        std::cout << student.fn << " " << student.ln << std::endl;
        }
    #endif

    #ifdef PRE_RELEASE
        std::cout << "The application is running in pre-release mode!"
        std::ifstream efile("StudentData_Emails.txt");
        if (efile.is_open()) 
        {
            std::string email;
            int index = 0;
            while (std::getline(efile, email) && index < students.size()) 
            {
                students[index].email = email;
                //std::cout << students[index].fn << " " << students[index].ln << " " << email << std::endl;
                index++;
            }
            efile.close();
        }
    #endif

    return 0;
}