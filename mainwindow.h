#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cctype>
#include <iterator>
#include "opencv2/objdetect.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/imgproc.hpp"
#include<string>
using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void openCamera();
    void readFrame();
    void closeCamera();
    void takingPictures();
    void showCanny();
    void showErode();
    Mat detectAndDraw( Mat& img, CascadeClassifier& cascade,
                        CascadeClassifier& nestedCascade,
                        double scale, bool tryflip );
    void detectFace();


private:
    Ui::MainWindow *ui;

    QTimer *timer;
    QImage qimage;
    cv::Mat cvimage;
    cv::VideoCapture capture;
    cv::Mat cvframe;

    string cascadeName;
    string nestedCascadeName;
    CascadeClassifier cascade, nestedCascade;
    double scale;

    bool isDetectFace;
};

#endif // MAINWINDOW_H
