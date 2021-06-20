#include <QApplication>
#include <QPushButton>
#include "QWidget"
#include "QStackedWidget"
#include "QVBoxLayout"
#include "QComboBox"
#include "QLabel"


#include "widgets/welcome.h"
#include "widgets/nn/perceptron.h"

QPalette ombraPalette() {
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, qRgb(102,102,153));

    pal.setColor(QPalette::WindowText, Qt::GlobalColor::white);
    return pal;
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto ombra = ombraPalette();
    a.setPalette(ombra);

    auto *welcome_page_widget = new Welcome;
    auto *perceptron_page_widget = new Perceptron;

    auto *stacked_widget = new QStackedWidget;
    stacked_widget->addWidget(welcome_page_widget);
    stacked_widget->addWidget(perceptron_page_widget);

    auto *info_label_ = new QLabel("choose:");

    auto *page_combo_box = new QComboBox;
    page_combo_box->addItem("welcome");
    page_combo_box->addItem("perceptron");
    QObject::connect(page_combo_box, QOverload<int>::of(&QComboBox::activated),
                     stacked_widget, &QStackedWidget::setCurrentIndex);

    auto *exit_button = new QPushButton("exit");
    QObject::connect(exit_button, &QPushButton::clicked, qApp, &QApplication::quit);

    auto *layout_h = new QHBoxLayout;
    layout_h->addWidget(info_label_);
    layout_h->addWidget(page_combo_box);
    layout_h->addWidget(exit_button);

    auto *layout_v = new QVBoxLayout;
    layout_v->addLayout(layout_h);
    layout_v->addWidget(stacked_widget);

    auto *main_window = new QWidget;
    main_window->setLayout(layout_v);
    main_window->show();

    return QApplication::exec();
}
