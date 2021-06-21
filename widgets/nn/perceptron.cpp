//
// Created by pau on 19.06.21.
//

#include "perceptron.h"

Perceptron::Perceptron() {
    //init perceptron values
    input_1_ =  new int;   input_2_ =  new int;   input_3_ =  new int;   input_4_ =  new int;
    weight_1_ = new float; weight_2_ = new float; weight_3_ = new float; weight_4_ = new float;

    perceptron_window = new QWidget();
    perceptron_window->setStyleSheet(ombra_);
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

    label_mid_explain_ = new QLabel("lel");
    label_mid_explain_->setFrameStyle(QFrame::Panel | QFrame::Raised);
    label_mid_explain_->setAlignment(Qt::AlignCenter);
    label_mid_explain_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    h_layout_mid_ = new QHBoxLayout;
    h_layout_mid_->addWidget(label_mid_explain_);

    //bottom Perceptron layout

    //inputs
    {
        input_label_title_ = new QLabel("Inputs");
        input_label_title_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        input_label_title_->setAlignment(Qt::AlignCenter);
        title_font->setPointSize(13);
        input_label_title_->setFont(*title_font);

        input_button_1_on_ = new QPushButton("1");
        setAutoFillBackground(input_button_1_on_);
        QObject::connect(input_button_1_on_, &QPushButton::clicked,
                         this, &Perceptron::input_button_1_on_clicked);
        input_button_1_off_ = new QPushButton("0");
        QObject::connect(input_button_1_off_, &QPushButton::clicked,
                         this, &Perceptron::input_button_1_off_clicked);
        input_layout_1_ = new QHBoxLayout();
        input_layout_1_->addWidget(input_button_1_on_);
        input_layout_1_->addWidget(input_button_1_off_);

        input_button_2_on_ = new QPushButton("1");
        setAutoFillBackground(input_button_2_on_);
        QObject::connect(input_button_2_on_, &QPushButton::clicked,
                         this, &Perceptron::input_button_2_on_clicked);
        input_button_2_off_ = new QPushButton("0");
        QObject::connect(input_button_2_off_, &QPushButton::clicked,
                         this, &Perceptron::input_button_2_off_clicked);
        input_layout_2_ = new QHBoxLayout();
        input_layout_2_->addWidget(input_button_2_on_);
        input_layout_2_->addWidget(input_button_2_off_);

        input_button_3_on_ = new QPushButton("1");
        setAutoFillBackground(input_button_3_on_);
        QObject::connect(input_button_3_on_, &QPushButton::clicked,
                         this, &Perceptron::input_button_3_on_clicked);
        input_button_3_off_ = new QPushButton("0");
        QObject::connect(input_button_3_off_, &QPushButton::clicked,
                         this, &Perceptron::input_button_3_off_clicked);
        input_layout_3_ = new QHBoxLayout();
        input_layout_3_->addWidget(input_button_3_on_);
        input_layout_3_->addWidget(input_button_3_off_);

        input_button_4_on_ = new QPushButton("1");
        setAutoFillBackground(input_button_4_on_);
        QObject::connect(input_button_4_on_, &QPushButton::clicked,
                         this, &Perceptron::input_button_4_on_clicked);
        input_button_4_off_ = new QPushButton("0");
        QObject::connect(input_button_4_off_, &QPushButton::clicked,
                         this, &Perceptron::input_button_4_off_clicked);
        input_layout_4_ = new QHBoxLayout();
        input_layout_4_->addWidget(input_button_4_on_);
        input_layout_4_->addWidget(input_button_4_off_);

        v_layout_bot_inputs_ = new QVBoxLayout;
        v_layout_bot_inputs_->addWidget(input_label_title_);
        v_layout_bot_inputs_->addLayout(input_layout_1_);
        v_layout_bot_inputs_->addLayout(input_layout_2_);
        v_layout_bot_inputs_->addLayout(input_layout_3_);
        v_layout_bot_inputs_->addLayout(input_layout_4_);


    }

    //weights
    {
        int maxSlider = 1000000;

        weight_label_title_ = new QLabel("Weights");
        weight_label_title_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        weight_label_title_->setAlignment(Qt::AlignCenter);
        weight_label_title_->setFont(*title_font);
        //inputs are 4 widgets with
        weight_slider_1_ = new QSlider(Qt::Orientation::Horizontal);
        weight_slider_1_->setMaximum(maxSlider);
        weight_slider_1_->setTickInterval(1);
        weight_label_1_ = new QLabel("0");
        QObject::connect(weight_slider_1_, &QAbstractSlider::valueChanged,
                         this, &Perceptron::weight_slider_1_changed);
        weight_layout_1_ = new QHBoxLayout;
        weight_layout_1_->addWidget(weight_slider_1_);
        weight_layout_1_->addWidget(weight_label_1_);

        weight_slider_2_ = new QSlider(Qt::Orientation::Horizontal);
        weight_slider_2_->setMaximum(maxSlider);
        weight_slider_2_->setTickInterval(1);
        weight_label_2_ = new QLabel("0");
        QObject::connect(weight_slider_2_, &QAbstractSlider::valueChanged,
                         this, &Perceptron::weight_slider_2_changed);
        weight_layout_2_ = new QHBoxLayout;
        weight_layout_2_->addWidget(weight_slider_2_);
        weight_layout_2_->addWidget(weight_label_2_);

        weight_slider_3_ = new QSlider(Qt::Orientation::Horizontal);
        weight_slider_3_->setMaximum(maxSlider);
        weight_slider_3_->setTickInterval(1);
        weight_label_3_ = new QLabel("0");
        QObject::connect(weight_slider_3_, &QAbstractSlider::valueChanged,
                         this, &Perceptron::weight_slider_3_changed);
        weight_layout_3_ = new QHBoxLayout;
        weight_layout_3_->addWidget(weight_slider_3_);
        weight_layout_3_->addWidget(weight_label_3_);

        weight_slider_4_ = new QSlider(Qt::Orientation::Horizontal);
        weight_slider_4_->setMaximum(maxSlider);
        weight_slider_4_->setTickInterval(1);
        weight_label_4_ = new QLabel("0");
        QObject::connect(weight_slider_4_, &QAbstractSlider::valueChanged,
                         this, &Perceptron::weight_slider_4_changed);
        weight_layout_4_ = new QHBoxLayout;
        weight_layout_4_->addWidget(weight_slider_4_);
        weight_layout_4_->addWidget(weight_label_4_);

        //layout
        v_layout_bot_weights_ = new QVBoxLayout;
        v_layout_bot_weights_->addWidget(weight_label_title_);
        v_layout_bot_weights_->addLayout(weight_layout_1_);
        v_layout_bot_weights_->addLayout(weight_layout_2_);
        v_layout_bot_weights_->addLayout(weight_layout_3_);
        v_layout_bot_weights_->addLayout(weight_layout_4_);

    }

    //internal
    {
        internal_label_title = new QLabel("Internal");
        internal_label_title->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        internal_label_title->setAlignment(Qt::AlignCenter);
        internal_label_title->setFont(*title_font);

        internal_label_fa_ = new QLabel(QString::fromUtf8("fa() = \u2211 input"));

        v_layout_bot_internal_ = new QVBoxLayout;
        v_layout_bot_internal_->addWidget(internal_label_title);
        v_layout_bot_internal_->addWidget(internal_label_fa_);
    }



    h_layout_bot_ = new QHBoxLayout;
    h_layout_bot_->addLayout(v_layout_bot_inputs_);
    h_layout_bot_->addLayout(v_layout_bot_weights_);
    h_layout_bot_->addLayout(v_layout_bot_internal_);

    auto *layout = new QVBoxLayout();
    layout->setContentsMargins(5,5,5,5);
    layout->addLayout(h_layout_top_);
    layout->addLayout(h_layout_mid_);
    layout->addLayout(h_layout_bot_);

    perceptron_window->setLayout(layout);
}

void Perceptron::weight_slider_1_changed(int value) {
    *weight_1_ = value/1000000.0;
    std::string temp = std::to_string(*weight_1_);
    weight_label_1_->setText(QString::fromStdString(temp));
}
void Perceptron::weight_slider_2_changed(int value) {
    *weight_2_ = value/1000000.0;
    std::string temp = std::to_string(*weight_2_);
    weight_label_2_->setText(QString::fromStdString(temp));
}
void Perceptron::weight_slider_3_changed(int value) {
    *weight_3_ = value/1000000.0;
    std::string temp = std::to_string(*weight_3_);
    weight_label_3_->setText(QString::fromStdString(temp));
}
void Perceptron::weight_slider_4_changed(int value) {
    *weight_4_ = value/1000000.0;
    std::string temp = std::to_string(*weight_4_);
    weight_label_4_->setText(QString::fromStdString(temp));
}

void Perceptron::input_button_1_on_clicked() {
    //set internal var
    *input_1_ = 1;
    //set button color for visual feedback
    input_button_1_on_->setStyleSheet(input_button_active_);
    input_button_1_off_->setStyleSheet(input_button_passive_);

}
void Perceptron::input_button_1_off_clicked() {
    //set internal var
    *input_1_ = 0;
    //set button color for visual feedback
    input_button_1_on_->setStyleSheet(input_button_passive_);
    input_button_1_off_->setStyleSheet(input_button_active_);
}
void Perceptron::input_button_2_on_clicked() {
    //set internal var
    *input_2_ = 1;
    //set button color for visual feedback
    input_button_2_on_->setStyleSheet(input_button_active_);
    input_button_2_off_->setStyleSheet(input_button_passive_);
}
void Perceptron::input_button_2_off_clicked() {
    //set internal var
    *input_2_ = 0;
    //set button color for visual feedback
    input_button_2_on_->setStyleSheet(input_button_passive_);
    input_button_2_off_->setStyleSheet(input_button_active_);
}
void Perceptron::input_button_3_on_clicked() {
    //set internal var
    *input_3_ = 1;
    //set button color for visual feedback
    input_button_3_on_->setStyleSheet(input_button_active_);
    input_button_3_off_->setStyleSheet(input_button_passive_);
}
void Perceptron::input_button_3_off_clicked() {
    //set internal var
    *input_3_ = 0;
    //set button color for visual feedback
    input_button_3_on_->setStyleSheet(input_button_passive_);
    input_button_3_off_->setStyleSheet(input_button_active_);
}
void Perceptron::input_button_4_on_clicked() {
    //set internal var
    *input_4_ = 1;
    //set button color for visual feedback
    input_button_4_on_->setStyleSheet(input_button_active_);
    input_button_4_off_->setStyleSheet(input_button_passive_);
}
void Perceptron::input_button_4_off_clicked() {
    //set internal var
    *input_4_ = 0;
    //set button color for visual feedback
    input_button_4_on_->setStyleSheet(input_button_passive_);
    input_button_4_off_->setStyleSheet(input_button_active_);
}




