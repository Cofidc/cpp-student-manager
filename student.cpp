#include <iostream>
#include "student.h"

using namespace std;

//显示单个学生
void printStudent(const Student& s){
    cout << s.getId() << " " << s.getName() << " " << s.getScore() << endl;
}
//显示所有学生
void printAllStudents(const vector<Student>& ss){
    if(ss.empty()){
        cout << "暂无学生信息\n";
        return;
    }
    for(const Student& s : ss){
        printStudent(s);
    }
}
//判断学号是否存在
bool hasStudent(const vector<Student>& students, int id) {
    for(const Student& s:students){
        if(s.getId()==id){
            return true;
        }
    }
    return false;
}
//增
bool addStudent(vector<Student>& students, const Student& newStudent){
    if(newStudent.getId()<=0 || newStudent.getName().empty() 
    || hasStudent(students, newStudent.getId())){
        return false;
    }
    students.push_back(newStudent);
    return true;
}
//改分
bool updateScore(vector<Student>& students, int id, int newScore) {
    for(Student& s:students){
        if(s.getId()==id){
            return s.setScore(newScore);
        }
    }
    return false;
}
//改名
bool updateName(vector<Student>& students, int id,const string& newName){
    for(Student& student : students){
        if(student.getId()==id){
            return student.setName(newName);
        }
    }
    return false;
}
//删
bool removeStudent(vector<Student>& students, int id) {
    for (size_t i = 0; i < students.size(); i++) {
        if(students[i].getId()==id){
            students.erase(students.begin()+i);
            return true;
        }
    }
    return false;
}
//查
bool printStudentById(const vector<Student>& students, int id) {
    for(const Student& student:students){
        if(student.getId()==id){
            printStudent(student);
            return true;
        }
    }
    return false;
}