#include <iostream>

#include "headers/PlotBuilder.h"
#include <iostream>

int main() {

    PlotBuilder builder;

    builder
        .addPlot({2.5, 6.5, 4.5}, {2.5, 6.5, 4.5}, "function1")
        .addHorizontalLine(3.8)
        .addVerticalLine(8.9);

    bool showAnnotations = true;
    if (showAnnotations)
        builder
            .addAnnotation(3.4, 5.6, "Annotation1")
            .addAnnotation(5.6, 9.0, "Annotation2");

    std::string result = builder.Build();

    std::cout << result << std::endl;


    return 0;
}
