
#include <iostream>
using namespace std;

class PersonalInfo {
protected:
    string name, fatherName, cnic, address, email, phone;
    string nationality, gender, dob;

public:
    PersonalInfo() {
        name = fatherName = cnic = address = email = phone = "";
        nationality = gender = dob = "";
    }

    void inputPersonalInfo() {
        cout << endl << "--- Enter Personal Information ---" << endl;
        cout << "Name: ";
        getline(cin, name);
        cout << "Father's Name: ";
        getline(cin, fatherName);
        cout << "CNIC: ";
        getline(cin, cnic);
        cout << "Date of Birth (DD-MM-YYYY): ";
        getline(cin, dob);
        cout << "Gender: ";
        getline(cin, gender);
        cout << "Nationality: ";
        getline(cin, nationality);
        cout << "Address: ";
        getline(cin, address);
        cout << "Email: ";
        getline(cin, email);
        cout << "Phone: ";
        getline(cin, phone);
    }

    void displayPersonalInfo() const {
        cout << endl << "===== Personal Information =====" << endl;
        cout << "Name          : " << name << endl;
        cout << "Father's Name : " << fatherName << endl;
        cout << "CNIC          : " << cnic << endl;
        cout << "Date of Birth : " << dob << endl;
        cout << "Gender        : " << gender << endl;
        cout << "Nationality   : " << nationality << endl;
        cout << "Address       : " << address << endl;
        cout << "Email         : " << email << endl;
        cout << "Phone         : " << phone << endl;
    }

    string getName() const {
        return name;
    }
};

class EducationInfo {
protected:
    string matric, inter, bachelors;

public:
    void inputEducationInfo() {
        cout << endl << "--- Enter Education Details ---" << endl;
        cout << "Matric (Board and Year): ";
        getline(cin, matric);
        cout << "Intermediate (Board and Year): ";
        getline(cin, inter);
        cout << "Bachelors (University and Year): ";
        getline(cin, bachelors);
    }

    void displayEducationInfo() const {
        cout << endl << "===== Education Information =====" << endl;
        cout << "Matric        : " << matric << endl;
        cout << "Intermediate  : " << inter << endl;
        cout << "Bachelors     : " << bachelors << endl;
    }
};

class SkillsInfo {
protected:
    string skill1, skill2, skill3, skill4, skill5;

public:
    void inputSkills() {
        cout << endl << "--- Enter Your Skills ---" << endl;
        cout << "Skill 1: ";
        getline(cin, skill1);
        cout << "Skill 2: ";
        getline(cin, skill2);
        cout << "Skill 3: ";
        getline(cin, skill3);
        cout << "Skill 4: ";
        getline(cin, skill4);
        cout << "Skill 5: ";
        getline(cin, skill5);
    }

    void displaySkills() const {
        cout << endl << "===== Skills =====" << endl;
        cout << "- " << skill1 << endl;
        cout << "- " << skill2 << endl;
        cout << "- " << skill3 << endl;
        cout << "- " << skill4 << endl;
        cout << "- " << skill5 << endl;
    }
};

class ExperienceInfo {
protected:
    string jobTitle[5];
    string company[5];
    string duration[5];
    int totalJobs;

public:
    ExperienceInfo() {
        totalJobs = 0;
    }

    void inputExperience() {
        cout << endl << "--- Enter Work Experience ---" << endl;

        while (true) {
            cout << "How many jobs do you want to add (1 to 5)? ";
            cin >> totalJobs;

            if (cin.fail() || totalJobs < 1 || totalJobs > 5) {
                cout << "Invalid input. Please enter a number between 1 and 5." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            } else {
                cin.ignore();
                break;
            }
        }

        for (int i = 0; i < totalJobs; ++i) {
            cout << endl << "Job #" << i + 1 << " Title: ";
            getline(cin, jobTitle[i]);
            cout << "Company Name: ";
            getline(cin, company[i]);
            cout << "Duration (e.g. 2022-2023): ";
            getline(cin, duration[i]);
        }
    }

    void displayExperience() const {
        cout << endl << "===== Work Experience =====" << endl;
        if (totalJobs == 0) {
            cout << "No work experience added." << endl;
        } else {
            for (int i = 0; i < totalJobs; ++i) {
                cout << i + 1 << ". " << jobTitle[i]
                     << " at " << company[i]
                     << " (" << duration[i] << ")" << endl;
            }
        }
    }
};

class Resume : public PersonalInfo, public EducationInfo, public SkillsInfo, public ExperienceInfo {
public:
    void buildFullResume() {
        inputPersonalInfo();
        inputEducationInfo();
        inputSkills();
        inputExperience();
    }

    void displayFullResume() const {
        displayPersonalInfo();
        displayEducationInfo();
        displaySkills();
        displayExperience();
    }
};

int main() {
    Resume resumes[5];
    int resumeCount = 0;
    string choice;

    do {
        cout << endl << "=========== Resume Builder Menu ===========" << endl;
        cout << "1. Build New Resume" << endl;
        cout << "2. Show a Resume" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        getline(cin, choice);

        if (choice == "1") {
            if (resumeCount >= 5) {
                cout << endl << "Only 5 resumes can be created." << endl;
            } else {
                cout << endl << "Creating Resume #" << (resumeCount + 1) << endl;
                resumes[resumeCount].buildFullResume();
                cout << "Resume saved successfully." << endl;
                resumeCount++;
            }
        } else if (choice == "2") {
            if (resumeCount == 0) {
                cout << endl << "No resumes available to display." << endl;
            } else {
                cout << endl << "Available Resumes:" << endl;
                for (int i = 0; i < resumeCount; ++i) {
                    cout << i + 1 << ". " << resumes[i].getName() << endl;
                }
                int showIndex;
                cout << "Enter resume number to display: ";
                cin >> showIndex;
                cin.ignore();

                if (showIndex >= 1 && showIndex <= resumeCount) {
                    resumes[showIndex - 1].displayFullResume();
                } else {
                    cout << "Invalid selection." << endl;
                }
            }
        } else if (choice == "0") {
            cout << endl << "Exiting... Goodbye!" << endl;
        } else {
            cout << endl << "Invalid input. Please try again." << endl;
        }

    } while (choice != "0");

    return 0;
}
