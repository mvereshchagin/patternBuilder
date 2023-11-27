//
// Created by misha on 11/23/23.
//

#include "../headers/PlotBuilder.h"
#include <optional>
#include <string>
#include <utility>
#include <vector>
#include <sstream>

LineParams::LineParams(std::optional<std::string> color, std::optional<std::string> style,
                       std::optional<std::string> weight) :
        Color{std::move(color)}, Style{std::move(style)}, Weight{std::move(weight)} {

}


VerticalLine::VerticalLine(double x, std::optional<double> yMin, std::optional<double> yMax,
                           std::optional<LineParams> lineParamsData) :
                           X{x}, YMin{yMin}, YMax{yMax}, LineParamsData{std::move(lineParamsData)} {

}

HorizontalLine::HorizontalLine(double y, std::optional<double> xMin, std::optional<double> xMax,
                               std::optional<LineParams> lineParamsData) :
                               Y{y}, XMin{xMin}, XMax{xMax}, LineParamsData{std::move(lineParamsData)} {

}

PlotData::PlotData(const std::vector<double> &x, const std::vector<double> &y, std::optional<std::string> label,
                   std::optional<LineParams> lineParamsData) :
                   X{x}, Y{y}, Label{std::move(label)}, LineParamsData{std::move(lineParamsData)}{

}



PlotBuilder&  PlotBuilder::addPlot(const std::vector<double>& x, const std::vector<double>& y,
                                   std::optional<std::string> label, std::optional<LineParams> lineParamsData) {
    PlotData plotData{x, y, std::move(label), std::move(lineParamsData)};
    mPlotDataVector.emplace_back(plotData);
    return *this;
}

PlotBuilder&  PlotBuilder::addHorizontalLine(double y, std::optional<double> xMin, std::optional<double> xMax,
                                    std::optional<LineParams> lineParamsData) {
    HorizontalLine line{y, xMin, xMax, std::move(lineParamsData)};
    mHorizontalLines.emplace_back(line);
    return *this;
}

PlotBuilder&  PlotBuilder::addVerticalLine(double x, std::optional<double> yMin, std::optional<double> yMax,
                                  std::optional<LineParams> lineParamsData) {
    VerticalLine line{x, yMin, yMax, std::move(lineParamsData)};
    mVerticalLines.emplace_back(line);
    return *this;
}

PlotBuilder&  PlotBuilder::addAnnotation(double x, double y, const std::string &text) {
    Annotation annotation{x, y, text};
    mAnnotations.emplace_back(annotation);
    return *this;
}

std::string PlotBuilder::Build() {
    std::stringstream ss{};
    for(auto& line : mHorizontalLines) {
        ss << "Horizontal line: " << line.Y << std::endl;
    }

    for(auto& line : mVerticalLines) {
        ss << "Vertical line: " << line.X << std::endl;
    }

    for(auto& plotData : mPlotDataVector) {
        ss << "Plot: " << plotData.Label.value() << std::endl;
    }

    for(auto& annotation : mAnnotations) {
        ss << "Annotation: " << annotation.Text << std::endl;
    }

    return ss.str();
}

Annotation::Annotation(double x, double y, const std::string& text) : X{x}, Y{y}, Text{text}{

}
