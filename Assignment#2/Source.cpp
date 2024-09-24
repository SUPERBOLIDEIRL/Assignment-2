#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


//student struct
struct STUDENT_DATA {
    std::string fn;
    std::string ln;
    std::string email;
};

int main() {
    std::ifstream file("StudentData.txt");
    std::vector<STUDENT_DATA> students; //create students vector

    if (file.is_open()) { //opening the file
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string fn, ln;

            std::getline(ss, fn, ',');
            std::getline(ss, ln);

            students.push_back({ fn, ln }); //put names into students vector
        }
        file.close(); //close the file
    }

        //debug mode
    #ifdef _DEBUG
    std::cout << "The application is running in debug mode!"; //if run in debug mode print the message to inform the user
        for (const auto& student : students)   //for all the student objects in the students vector
        {
        std::cout << student.fn << " " << student.ln << std::endl; //print all the students out
        }
    #endif

        //pre release mode
    #ifdef PRE_RELEASE
        std::cout << "The application is running in pre-release mode!"; //if run in pre release mode (with directives enabled) print "The application is running in pre-release mode!"
        std::ifstream efile("StudentData_Emails.txt"); //if run in debug mode open the email file, read and put them into the student vector next to first name and last name with the corresponding index number
        if (efile.is_open())  //open the email file
        {
            std::string email;
            int index = 0; //initiate index
            while (std::getline(efile, email) && index < students.size())
            {
                students[index].email = email; //put emails into students vector
                //std::cout << students[index].fn << " " << students[index].ln << " " << email << std::endl; //the assignment only mentioned reading the emails not printing them, i used this line for testing purposes
                index++;
            }
            efile.close(); //close the email file
        }
    #endif

    return 0;
}