#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdlib.h"
#include <stdio.h>
#include <QMessageBox>
#include <QDesktopWidget>
#include <fstream>
#include <cstring>
#include "string.h"
#include <time.h>
#include <stdafx.h>
using namespace std;
using namespace SortingMethods;

clock_t start, end1;
int type=1, kol=100, seconds;

void MainWindow::on_spinBox_valueChanged(int arg1){
    kol=arg1;}

void MainWindow::on_radioButton_clicked(){ //merge sort - сортир слиянием
    type=1;}

void MainWindow::on_radioButton_2_clicked(){ //natural merge sort - естественная сортир слиянием
    type=2;}

void MainWindow::on_radioButton_3_clicked(){ //balanced multiway merge sort - сбалансированная многопоточная сортир слиянием
    type=3;}

void clone(int n){
    ifstream input;
    input.open("D:\\MyDock\\Desktop\\build-lab2-Desktop_Qt_5_10_1_MinGW_32bit-Debug\\debug\\original.txt");
    fstream output("input.txt", ios::in);
    output.close();
    output.open("D:\\MyDock\\Desktop\\build-lab2-Desktop_Qt_5_10_1_MinGW_32bit-Debug\\debug\\Input.txt", ios::out | ios::in); //открытие с флагом на перезапись
    string name;
    int value;
    for(int j=0;j<n;j++){
        input >> name >> value;
        output << name << " " << value << "\n";
    }
    input.close();
    output.close();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    ui->label_3->setText(tr("не сортированно"));
    ui->label_5->setText(tr("не замеренно"));
    clone(kol);
    switch (type) {
    case 1:
        start = clock();
        Simple_merge_sort();
        end1 = clock();
        break;
    case 2:
        start = clock();
        Natural_merge_sort();
        end1 = clock();
        break;
    case 3:
        start = clock();
        Balanced_Multiway_Merge();
        end1 = clock();
        break;
    }
    seconds = (end1 - start);
    ui->label_3->setText(tr("сортированно"));
    ui->label_5->setText(QString::number(seconds));;
}
