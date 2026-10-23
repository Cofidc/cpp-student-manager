#pragma once
#include <string>
#include <vector>

class Student {
private:
    int id=0;
    int score = 0;
    std::string name;
public:

    bool setScore(int newScore) {
        if(newScore>=0 && newScore<=100){
			score=newScore;
			return true;
		}
		return false;
    }

    int getScore() const{
        return score;
    }

    bool setId(int newId){
        if(newId>0){
            id=newId;
            return true;
        }
        return false;
    }

    int getId() const{
        return id;
    }
    bool setName(const std::string& newName){
        if(newName.empty()){
            return false;
        }
        name=newName;
        return true;
    }
    std::string getName() const{
        return name;
    }
};

//显示单个学生
void printStudent(const Student& s);
//显示所有学生
void printAllStudents(const std::vector<Student>& ss);
//判断学号是否存在
bool hasStudent(const std::vector<Student>& students, int id);
//增
bool addStudent(std::vector<Student>& ss, const Student& ns);
//改分
bool updateScore(std::vector<Student>& students, int id, int newScore);
//改名
bool updateName(std::vector<Student>& students, int id,const std::string& newName);
//删
bool removeStudent(std::vector<Student>& students, int id);
//查
bool printStudentById(const std::vector<Student>& students, int id);