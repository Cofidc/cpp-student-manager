#include <iostream>
#include "student.h"

using namespace std;

//显示单个学生
void printStudent(const Student& s){
    cout << s.id << " " << s.name << " " << s.score << endl;
}
//显示所有学生
void printAllStudents(const vector<Student>& ss){
    for(const Student& s : ss){
        printStudent(s);
    }
}
//判断学号是否存在
bool hasStudent(const vector<Student>& students, int id) {
    for(const Student& s:students){
        if(s.id==id){
            return true;
        }
    }
    return false;
}
//增
bool addStudent(vector<Student>& ss, const Student& ns){
    if(hasStudent(ss,ns.id) || ns.score>100 || ns.score <0){
        return false;
    }
    ss.push_back(ns);
    return true;
}
//改
bool updateScore(vector<Student>& students, int id, int newScore) {
    if(newScore>100 || newScore <0){
        return false;
    }
    for(Student& s:students){
        if(s.id==id){
            s.score=newScore;
            return true;
        }
    }
    return false;
}
//删
bool removeStudent(vector<Student>& students, int id) {
    for (size_t i = 0; i < students.size(); i++) {
        if(students[i].id==id){
            students.erase(students.begin()+i);
            return true;
        }
    }
    return false;
}
//查
bool printStudentById(const vector<Student>& students, int id) {
    for(const Student& student:students){
        if(student.id==id){
            printStudent(student);
            return true;
        }
    }
    return false;
}