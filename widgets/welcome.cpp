//
// Created by pau on 19.06.21.
//

#include "welcome.h"

Welcome::Welcome() {
    ombra_ = new QString("QWidget { background: grey; }");

    welcome_window = new QWidget();
    welcome_window->setStyleSheet(*ombra_);
    setCentralWidget(welcome_window);

    auto *top_filler = new QWidget();
    top_filler->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    test_label_ = new QLabel("welcome hel wf sdf asd");
    test_label_->setFrameStyle(QFrame::Panel | QFrame::Raised);
    test_label_->setAlignment(Qt::AlignCenter);

    auto *bottomFiller = new QWidget();
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    auto *layout = new QVBoxLayout();
    layout->setContentsMargins(5,5,5,5);
    layout->addWidget(top_filler);
    layout->addWidget(test_label_);
    layout->addWidget(bottomFiller);

    welcome_window->setLayout(layout);
}
