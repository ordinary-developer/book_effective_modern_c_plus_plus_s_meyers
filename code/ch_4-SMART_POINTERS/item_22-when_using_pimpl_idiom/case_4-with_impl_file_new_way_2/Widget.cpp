#include "Widget.hpp"
#include "Gadget.hpp"

#include <string>
#include <vector>

struct Widget::Impl {
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;
};

Widget::Widget() : pImpl(std::make_unique<Impl>()) { }

Widget::~Widget() = default;

Widget::Widget(Widget&& rhs) = default;

Widget& Widget::operator=(Widget&& rhs) = default;
