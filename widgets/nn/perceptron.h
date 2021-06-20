//
// Created by pau on 19.06.21.
//

#ifndef SOFTCOMP_PERCEPTRON_H
#define SOFTCOMP_PERCEPTRON_H

#include "QMainWindow"
#include "QLabel"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QFont"
#include "QSlider"

class Perceptron: public QMainWindow {
    Q_OBJECT
public:
    Perceptron();
    QWidget *perceptron_window;

public slots:
    void input_slider_1_changed(int value);
private:
    QString *ombra_;

    //top layout title
    QLabel *label_title_;
    QHBoxLayout *h_layout_top_;

    //mid layout for explanation
    QHBoxLayout *h_layout_mid_;
    QLabel *label_mid_explain_;

    //bot layout for the Perceptron visualization
    QHBoxLayout *h_layout_bot_;
    QVBoxLayout *v_layout_bot_inputs_;
    QVBoxLayout *v_layout_bot_weights_;
    QVBoxLayout *v_layout_bot_perceptron_;
    QVBoxLayout *v_layout_bot_output;

    //input layout
    QSlider *input_slider_1_;
    QLabel *input_label_1_;

};

#endif //SOFTCOMP_PERCEPTRON_H
