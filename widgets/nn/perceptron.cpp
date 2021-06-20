//
// Created by pau on 19.06.21.
//

#include "perceptron.h"

Perceptron::Perceptron() {
    //Colors
    ombra_ = new QString("QWidget { background: #f9ebef;"
                         "              color: black }"
                             );


    perceptron_window = new QWidget();
    perceptron_window->setStyleSheet(*ombra_);
    setCentralWidget(perceptron_window);

    //top layout  mainly for title
    label_title_ = new QLabel("Perceptron");
    auto *title_font = new QFont;
    title_font->setBold(true);
    title_font->setPointSize(16);
    label_title_->setFont(*title_font);

    auto *filler_title_left = new QWidget;
    filler_title_left->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    auto *filler_title_right = new QWidget;
    filler_title_right->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    h_layout_top_ = new QHBoxLayout;
    h_layout_top_->addWidget(filler_title_left);
    h_layout_top_->addWidget(label_title_);
    h_layout_top_->addWidget(filler_title_right);

    //mid layout for explanation and formulas

    label_mid_explain_ = new QLabel("kek");
    label_mid_explain_->setFrameStyle(QFrame::Panel | QFrame::Raised);
    label_mid_explain_->setAlignment(Qt::AlignCenter);
    label_mid_explain_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    h_layout_mid_ = new QHBoxLayout;
    h_layout_mid_->addWidget(label_mid_explain_);

    //bottom Perceptron layout

    //inputs are 4 widgets with
    input_slider_1_ = new QSlider;
    input_slider_1_->setTickInterval(1);
    input_slider_1_->setSingleStep(1);

    input_label_1_ = new QLabel("test");

    QObject::connect(input_slider_1_, &QAbstractSlider::valueChanged,
                     this, &Perceptron::input_slider_1_changed);

    v_layout_bot_inputs_ = new QVBoxLayout;
    v_layout_bot_inputs_->addWidget(input_slider_1_);
    v_layout_bot_inputs_->addWidget(input_label_1_);


    h_layout_bot_ = new QHBoxLayout;
    h_layout_bot_->addLayout(v_layout_bot_inputs_);

    auto *layout = new QVBoxLayout();
    layout->setContentsMargins(5,5,5,5);
    layout->addLayout(h_layout_top_);
    layout->addLayout(h_layout_mid_);
    layout->addLayout(h_layout_bot_);

    perceptron_window->setLayout(layout);
}

void Perceptron::input_slider_1_changed(int value) {
    input_label_1_->setNum(value);
}
