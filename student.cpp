#include <iostream>
#include "student.h"

using namespace std;

//显示单个学生
void printStudent(const Student& s){
    cout << s.getId() << " " << s.getName() << " " << s.getScore() << endl;
}
//显示所有学生
void StudentManager::printAllStudents() const{
    if(students.empty()){
        cout << "暂无学生信息\n";
        return;
    }
    for(const Student& s : students){
        printStudent(s);
    }
}
//判断学号是否存在
bool StudentManager::hasStudent(int id) const {
    for(const Student& s:students){
        if(s.getId()==id){
            return true;
        }
    }
    return false;
}
//增
bool StudentManager::addStudent(const Student& newStudent){
    if(newStudent.getId()<=0 || newStudent.getName().empty() 
    || hasStudent(newStudent.getId())){
        return false;
    }
    students.push_back(newStudent);
    return true;
}
//改分
bool StudentManager::updateScore(int id, int newScore) {
    for (Student& s : students) {
        if (s.getId() == id) {
            return s.setScore(newScore);
        }
    }
    return false;
}
//改名
bool StudentManager::updateName(int id, const string& newName){
    for(Student& student : students){
        if(student.getId()==id){
            return student.setName(newName);
        }
    }
    return false;
}
//删
bool StudentManager::removeStudent(int id){
    for (size_t i = 0; i < students.size(); i++) {
        if(students[i].getId()==id){
            students.erase(students.begin()+i);
            return true;
        }
    }
    return false;
}
//查
bool StudentManager::printStudentById(int id) const{
    for(const Student& student:students){
        if(student.getId()==id){
            printStudent(student);
            return true;
        }
    }
    return false;
}