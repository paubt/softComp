//
// Created by pau on 19.06.21.
//

#ifndef SOFTCOMP_PERCEPTRON_H
#define SOFTCOMP_PERCEPTRON_H

#include "string"

#include "QMainWindow"
#include "QLabel"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QFont"
#include "QSlider"
#include "QPushButton"
#include "QPalette"

class InputSlider;

class Perceptron: public QMainWindow {
    Q_OBJECT
public:
    Perceptron();
    QWidget *perceptron_window;
    void recalculate();

public slots:
    //inputs
    void input_button_1_on_clicked();
    void input_button_1_off_clicked();
    void input_button_2_on_clicked();
    void input_button_2_off_clicked();
    void input_button_3_on_clicked();
    void input_button_3_off_clicked();
    void input_button_4_on_clicked();
    void input_button_4_off_clicked();

    //weights
    void weight_slider_1_changed(int value);
    void weight_slider_2_changed(int value);
    void weight_slider_3_changed(int value);
    void weight_slider_4_changed(int value);

    //internal
    void internal_slider_threshold_changed(int value);

private:
    int   *input_1_,  *input_2_,  *input_3_,  *input_4_;
    float *weight_1_, *weight_2_, *weight_3_, *weight_4_;
    float *threshold;
    //colors
    const QString input_button_active_  = QString("background-color: green");
    const QString input_button_passive_ = QString("background-color: red");
    const QString ombra_= QString("QWidget { background: #f9ebef;"
                                      "          color: black }");;

    //top layout title
    QLabel *label_title_;
    QHBoxLayout *h_layout_top_;

    //mid layout for explanation
    QHBoxLayout *h_layout_mid_;
    QLabel *label_mid_explain_;

    //bot layout for the Perceptron visualization
    //inputs
    QLabel *input_label_title_;

    QPushButton *input_button_1_on_;
    QPushButton *input_button_1_off_;
    QHBoxLayout *input_layout_1_;

    QPushButton *input_button_2_on_;
    QPushButton *input_button_2_off_;
    QHBoxLayout *input_layout_2_;

    QPushButton *input_button_3_on_;
    QPushButton *input_button_3_off_;
    QHBoxLayout *input_layout_3_;

    QPushButton *input_button_4_on_;
    QPushButton *input_button_4_off_;
    QHBoxLayout *input_layout_4_;

    QVBoxLayout *v_layout_bot_inputs_;

    //Weights
    QLabel *weight_label_title_;
    QSlider *weight_slider_1_;
    QLabel *weight_label_1_;
    QHBoxLayout *weight_layout_1_;

    QSlider *weight_slider_2_;
    QLabel *weight_label_2_;
    QHBoxLayout *weight_layout_2_;

    QSlider *weight_slider_3_;
    QLabel *weight_label_3_;
    QHBoxLayout *weight_layout_3_;

    QSlider *weight_slider_4_;
    QLabel *weight_label_4_;
    QHBoxLayout *weight_layout_4_;

    QVBoxLayout *v_layout_bot_weights_;

    //internal
    QLabel *internal_label_title;

    QSlider *internal_slider_threshold_;
    QLabel *internal_label_threshold_;
    QHBoxLayout *internal_layout_threshold_;

    QLabel *internal_label_fa_;
    QLabel *internal_label_fo_;

    QVBoxLayout *v_layout_bot_internal_;

    //output
    QVBoxLayout *v_layout_bot_output;
    //main layout bot
    QHBoxLayout *h_layout_bot_;
};

#endif //SOFTCOMP_PERCEPTRON_H
