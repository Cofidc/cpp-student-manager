#pragma once
#include <string>
#include <vector>

struct Student{
    int id;
    std::string name;
    int score;
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