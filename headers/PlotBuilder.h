//
// Created by misha on 11/23/23.
//

#ifndef CREATEPATTERNSBUILDER_PLOTBUILDER_H
#define CREATEPATTERNSBUILDER_PLOTBUILDER_H

#include <vector>
#include <optional>
#include <string>

struct Annotation;
struct VerticalLine;
struct HorizonalLine;
struct LineParam;
struct PlotData;


class PlotBuilder {
public:
    PlotBuilder& addPlot(double* x, double* y,
                 std::optional<std::string> label = std::nullopt,
                 std::optional<LineParam> lineParam = std::nullopt);
    PlotBuilder&  addHorizontalLine(double y,
                           std::optional<double> xMin = std::nullopt,
                           std::optional<double> xMax = std::nullopt,
                           std::optional<LineParam> lineParam = std::nullopt);
    PlotBuilder& addVerticalLine(double x,
                         std::optional<double> yMin = std::nullopt,
                         std::optional<double> yMax = std::nullopt,
                         std::optional<LineParam> lineParam = std::nullopt);
    PlotBuilder& addAnnotation(double x, double y, const std::string& text);
    std::string Build();
private:
    std::vector<std::reference_wrapper<PlotData>> mPlotDatas;
    std::vector<std::reference_wrapper<HorizonalLine>> mHorizontalLines;
    std::vector<std::reference_wrapper<VerticalLine>> mVerticalLines;
    std::vector<std::reference_wrapper<Annotation>> mAnotations;
};

struct Annotation {
public:
    double X;
    double Y;
    std::string Text;
};

struct LineParam {
public:
    std::string Color;
    std::string Style;
    std::string Weight;
};

struct VerticalLine {
public:
    double X;
    std::optional<double> yMin;
    std::optional<double> yMax;
    std::optional<LineParam> LineParam;
};

struct HorizonalLine {
public:
    double Y;
    std::optional<double> xMin;
    std::optional<double> xMax;
    std::optional<LineParam> LineParam;
};

struct PlotData {
public:
    double* X;
    double* Y;
    std::optional<std::string> Label;
    std::optional<LineParam> LineParam;
};

#endif //CREATEPATTERNSBUILDER_PLOTBUILDER_H
