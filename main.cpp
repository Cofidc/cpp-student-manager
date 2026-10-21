#include <iostream>
#include <limits>
#include "student.h"

using namespace std;

//输入检查
bool checkInput() {
    if(cin){
        return true;
    }
    else if(cin.eof()){
        return false;
    }
    else{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "输入格式错误，返回菜单\n";
        return false;
    }
}

int main(){
    int choice=0;
    vector<Student> students;
    students.push_back({1001,"小明",90});
    students.push_back({1002,"小红",95});

    while(true){
        cout << "“1”查看学生信息，“2”添加新学生，“3”修改成绩，“4”删除学生，“5”查找学生，“0”退出系统：";
        cin >> choice;

        if (!checkInput()) {
            if (cin.eof()) {
                break;
            }
            continue;
        }
        if(choice==1){
            printAllStudents(students);
        }
        else if(choice==2){
            Student newStudent;
            cout << "请输入学号，姓名，成绩：";
            cin >> newStudent.id >> newStudent.name >> newStudent.score;
            if (!checkInput()) {
                if (cin.eof()) {
                    break;
                }
                continue;
            }
            if(addStudent(students, newStudent)){
                cout << "添加成功\n";
            }
            else{
                cout << "添加失败：学号已存在或成绩不合法\n";
            }
        }
        else if(choice==3){
            int id,score;
            cout << "请输入学号、新成绩：";
            cin >> id >> score;
            if (!checkInput()) {
                if (cin.eof()) {
                    break;
                }
                continue;
            }
            if(updateScore(students,id,score)){
                    cout << "修改成功\n";
            }
            else{
                cout << "修改失败：学号不存在或成绩不合法\n";
            }
        }
        else if(choice==4){
            int id;
            cout << "请输入学号：";
            cin >> id;
            if (!checkInput()) {
                if (cin.eof()) {
                    break;
                }
                continue;
            }
            if(removeStudent(students,id)){
                    cout << "删除成功\n";
            }
            else{
                cout << "删除失败\n";
            }
        }
        else if(choice==5){
            int id;
            cout << "请输入学号：";
            cin >> id;
            if (!checkInput()) {
                if (cin.eof()) {
                    break;
                }
                continue;
            }
            if(!(printStudentById(students,id))){
                    cout << "查找失败\n";
            }
        }
        else if(choice==0){
            break;
        }
        else{
            cout << "无效输入\n";
        }
    }
    return 0;
}