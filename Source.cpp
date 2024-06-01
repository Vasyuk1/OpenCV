#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    // Чтение изображение
    string picDerectory;
    cout << "Введите путь к изображению (например: F:\\manga\\01-02-02bratva001.jpeg):" << endl;
    cin >> picDerectory;
    Mat image = imread(picDerectory);
    resize(image, image, Size(500, 500));

    // Проверка на нахождение изображения
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
        cout << "Введите параметр яркости (от -100 до 100): " << endl;
        cin >> brighness;
        cout << "Введите параметр контрастности (от -10 до 10): " << endl;
        cin >> contrast;
        cout << "Введите параметр цветовой насыщенности (от -10 до 10): " << endl;
        cin >> saturation;

        Mat imageBrighnessHigh50;
        Mat convertedHSV;
        image.convertTo(imageBrighnessHigh50, -1, contrast, brighness); //изменение контрастности и яркости
        cvtColor(imageBrighnessHigh50, convertedHSV, COLOR_BGR2HSV);

        Mat HSVChannels[3];

        split(convertedHSV, HSVChannels);

        HSVChannels[1] *= saturation;
        merge(HSVChannels, 3, imageBrighnessHigh50);

        cvtColor(imageBrighnessHigh50, imageBrighnessHigh50, COLOR_HSV2BGR);

        //Создание оглавлений окон
        String windowNameOriginalImage = "Оригинальное изображение";
        String windowNameBrightnessHigh50 = "Отредактированное изображение";

        //Именование окон
        namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
        namedWindow(windowNameBrightnessHigh50, WINDOW_NORMAL);

        //Показон окон
        imshow(windowNameOriginalImage, image);
        imshow(windowNameBrightnessHigh50, imageBrighnessHigh50);
        waitKey(0); 
        destroyAllWindows();
    return 0;
}