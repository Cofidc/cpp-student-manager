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
    StudentManager manager;

    Student s1(1001, "小明", 90);
    Student s2(1002, "小红", 95);

    manager.addStudent(s1);
    manager.addStudent(s2);

    while(true){
        cout << "“1”查看信息，“2”添加学生，“3”修改成绩，“4”修改姓名，“5”删除数据，“6”查找学生，“0”退出系统：";
        cin >> choice;

        if (!checkInput()) {
            if (cin.eof()) {
                break;
            }
            continue;
        }
        if(choice==1){
            manager.printAllStudents();
        }
        else if(choice==2){
            int id,score;
            string name;
            cout << "请输入学号，姓名，成绩：";
            cin >> id >> name >> score;
            if (!checkInput()) {
                if (cin.eof()) {
                    break;
                }
                continue;
            }
            try{
                Student newStudent(id,name,score);
                if(manager.addStudent(newStudent)){
                    cout << "添加成功\n";
                }
                else{
                    cout << "添加失败:学号已存在\n";
                }
            }
            catch(const invalid_argument& e){
                cout << "添加失败：" << e.what() << '\n';
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
            if(manager.updateScore(id,score)){
                    cout << "修改成功\n";
            }
            else{
                cout << "修改失败\n";
            }
        }
        else if(choice==4){
            int id;
            string name;
            cout << "请输入学号、姓名：";
            cin >> id >> name;
            if (!checkInput()) {
                if (cin.eof()) {
                    break;
                }
                continue;
            }
            if(manager.updateName(id,name)){
                    cout << "修改成功\n";
            }
            else{
                cout << "修改失败\n";
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
            if(manager.removeStudent(id)){
                    cout << "删除成功\n";
            }
            else{
                cout << "删除失败\n";
            }
        }
        else if(choice==6){
            int id;
            cout << "请输入学号：";
            cin >> id;
            if (!checkInput()) {
                if (cin.eof()) {
                    break;
                }
                continue;
            }
            if(!(manager.printStudentById(id))){
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