#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    // ������ �����������
    string picDerectory;
    cout << "������� ���� � ����������� (��������: F:\\manga\\01-02-02bratva001.jpeg):" << endl;
    cin >> picDerectory;
    Mat image = imread(picDerectory);
    resize(image, image, Size(500, 500));

    // �������� �� ���������� �����������
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get();
        return -1;
    }

    int brighness = 0;
    int contrast = 0;
    int saturation = 0;
    int count;
        cout << "������� �������� ������� (�� -100 �� 100): " << endl;
        cin >> brighness;
        cout << "������� �������� ������������� (�� -10 �� 10): " << endl;
        cin >> contrast;
        cout << "������� �������� �������� ������������ (�� -10 �� 10): " << endl;
        cin >> saturation;

        Mat imageBrighnessHigh50;
        Mat convertedHSV;
        image.convertTo(imageBrighnessHigh50, -1, contrast, brighness); //��������� ������������� � �������
        cvtColor(imageBrighnessHigh50, convertedHSV, COLOR_BGR2HSV);

        Mat HSVChannels[3];

        split(convertedHSV, HSVChannels);

        HSVChannels[1] *= saturation;
        merge(HSVChannels, 3, imageBrighnessHigh50);

        cvtColor(imageBrighnessHigh50, imageBrighnessHigh50, COLOR_HSV2BGR);

        //�������� ���������� ����
        String windowNameOriginalImage = "������������ �����������";
        String windowNameBrightnessHigh50 = "����������������� �����������";

        //���������� ����
        namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
        namedWindow(windowNameBrightnessHigh50, WINDOW_NORMAL);

        //������� ����
        imshow(windowNameOriginalImage, image);
        imshow(windowNameBrightnessHigh50, imageBrighnessHigh50);
        waitKey(0); 
        destroyAllWindows();
    return 0;
}