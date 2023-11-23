#include <iostream>

#include "headers/PlotBuilder.h"

int main() {

    PlotBuilder builder;

    double x[] = {2.5, 6.5, 4.5};
    double y[] = {3.4, 6.7, 2.1};

    builder
        .addPlot(x, y, "function1")
        .addHorizontalLine(3.8)
        .addVerticalLine(8.9);

    bool showAnnotations = false;
    if (showAnnotations)
        builder
            .addAnnotation(3.4, 5.6, "Annotation1")
            .addAnnotation(5.6, 9.0, "Annotation2");

    std::string plot = builder.Build();

    return 0;
}
