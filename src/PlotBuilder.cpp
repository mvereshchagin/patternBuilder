//
// Created by misha on 11/23/23.
//

#include "../headers/PlotBuilder.h"
#include <optional>
#include <string>
#include <vector>
#include <sstream>

PlotBuilder&  PlotBuilder::addPlot(double *x, double *y, std::optional<std::string> label, std::optional<LineParam> lineParam) {
    PlotData plotData;
    plotData.X = x;
    plotData.Y = y;
    plotData.Label = std::move(label);
    plotData.LineParam = lineParam;
    mPlotDatas.push_back(*plotData);
    return *this;
}

PlotBuilder&  PlotBuilder::addHorizontalLine(double y, std::optional<double> xMin, std::optional<double> xMax,
                                    std::optional<LineParam> lineParam) {
    HorizonalLine line{};
    return *this;
}

PlotBuilder&  PlotBuilder::addVerticalLine(double x, std::optional<double> yMin, std::optional<double> yMax,
                                  std::optional<LineParam> lineParam) {
    return *this;
}

PlotBuilder&  PlotBuilder::addAnnotation(double x, double y, const std::string &text) {
    return *this;
}

std::string PlotBuilder::Build() {
    std::stringstream ss{};
    for(auto line : mHorizontalLines) {
        ss << "Line" << std::endl;
    }

    return ss.str();
}
