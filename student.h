#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

class Student {
private:
    int id=0;
    int score = 0;
    std::string name;
public:
     Student(int newId,const std::string& newName,int newScore)
    :id(newId),score(newScore),name(newName)
    {
        if(id<=0){
            throw std::invalid_argument("学号必须为正数");
        }
        if(name.empty()){
            throw std::invalid_argument("姓名不能为空");
        }
        if(score<0 || score>100){
            throw std::invalid_argument("成绩不合法");
        }
    }

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

class StudentManager {
private:
    std::vector<Student> students;

    bool hasStudent(int id) const;

public:
    bool addStudent(const Student& newStudent);
    void printAllStudents() const;
    bool printStudentById(int id) const;
    bool updateScore(int id, int newScore);
    bool updateName(int id, const std::string& newName);
    bool removeStudent(int id);
};

//显示单个学生
void printStudent(const Student& s);