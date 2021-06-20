//
// Created by pau on 19.06.21.
//

#ifndef SOFTCOMP_WELCOME_H
#define SOFTCOMP_WELCOME_H

#include "QMainWindow"
#include "QLabel"
#include "QVBoxLayout"

class Welcome: public QMainWindow {
    Q_OBJECT
public:
    Welcome();
    QWidget *welcome_window;

private:
    QString *ombra_;
    QLabel *test_label_;
};

#endif //SOFTCOMP_WELCOME_H
