//
// Created by misha on 11/23/23.
//

#ifndef CREATEPATTERNSBUILDER_PLOTBUILDER_H
#define CREATEPATTERNSBUILDER_PLOTBUILDER_H

#include <vector>
#include <optional>
#include <string>


struct Annotation {
public:
    explicit Annotation(double x, double y, const std::string& text);


    double X;
    double Y;
    std::string Text;
};

struct LineParams {
public:
    explicit LineParams(std::optional<std::string> color = std::nullopt,
                        std::optional<std::string> style = std::nullopt,
                        std::optional<std::string> weight = std::nullopt);
    LineParams(const LineParams&) = default;



    std::optional<std::string> Color;
    std::optional<std::string> Style;
    std::optional<std::string> Weight;
};

struct VerticalLine {
public:
    explicit VerticalLine(double x,
                 std::optional<double> yMin = std::nullopt,
                 std::optional<double> yMax = std::nullopt,
                 std::optional<LineParams> lineParamsData = std::nullopt);

    double X;
    std::optional<double> YMin;
    std::optional<double> YMax;
    std::optional<LineParams> LineParamsData;
};

struct HorizontalLine {
public:
    explicit HorizontalLine(double y,
                            std::optional<double> xMin = std::nullopt,
                            std::optional<double> xMax = std::nullopt,
                            std::optional<LineParams> lineParamsData = std::nullopt);

    double Y;
    std::optional<double> XMin;
    std::optional<double> XMax;
    std::optional<LineParams> LineParamsData;
};

struct PlotData {
public:
    explicit PlotData(const std::vector<double>& x, const std::vector<double>& y,
                      std::optional<std::string> label = std::nullopt,
                      std::optional<LineParams> lineParamsData = std:: nullopt);

    std::vector<double> X;
    std::vector<double> Y;
    std::optional<std::string> Label;
    std::optional<LineParams> LineParamsData;
};

class PlotBuilder {
public:
    PlotBuilder& addPlot(const std::vector<double>& x, const std::vector<double>& y,
                         std::optional<std::string> label = std::nullopt,
                         std::optional<LineParams> lineParamsData = std::nullopt);
    PlotBuilder&  addHorizontalLine(double y,
                                    std::optional<double> xMin = std::nullopt,
                                    std::optional<double> xMax = std::nullopt,
                                    std::optional<LineParams> lineParamsData = std::nullopt);
    PlotBuilder& addVerticalLine(double x,
                                 std::optional<double> yMin = std::nullopt,
                                 std::optional<double> yMax = std::nullopt,
                                 std::optional<LineParams> lineParamsData = std::nullopt);
    PlotBuilder& addAnnotation(double x, double y, const std::string& text);
    std::string Build();
private:
    std::vector<PlotData> mPlotDataVector{};
    std::vector<HorizontalLine> mHorizontalLines{};
    std::vector<VerticalLine> mVerticalLines{};
    std::vector<Annotation> mAnnotations{};
};


#endif //CREATEPATTERNSBUILDER_PLOTBUILDER_H
