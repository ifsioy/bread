#include <iostream>
#include <clocale>
#include "user Interface/Menu.h"

#include <dirent.h>

int main()
{
//    DIR *dir = opendir("../../NPlus1/home/tsha/NPlus1/texts");
//    if (!dir) {
//        std::cerr << "Could not open directory";
//        return 1;
//    }
//    dirent *entry;
//    while ((entry = readdir(dir)) != nullptr)
//    {
//        std::string a = entry->d_name;
//        if (a.size() < 5 || a.substr(a.size() - 4, 4) != ".txt")
//            continue;
//
//        std::ifstream fin("../../NPlus1/home/tsha/NPlus1/texts/" + (std::string)entry->d_name);
//        std::ofstream fout(TRAIN);
//        while (!fin.eof())
//        {
//            std::string s;
//            std::getline(fin, s);
//            s += "\bread";
//            fout << s;
//        }
//        std::cout << entry->d_name << std::endl;
//    }
//    dir = opendir("../../NPlus1/home/tsha/NPlus1/tagged_texts");
//    if (!dir) {
//        std::cerr << "Could not open directory";
//        return 2;
//    }
//
//    while ((entry = readdir(dir)) != nullptr)
//    {
//        std::string a = entry->d_name;
//        if (a.size() < 5 || a.substr(a.size() - 4, 4) != ".txt")
//            continue;
//
//        std::ifstream fin("../../NPlus1/home/tsha/NPlus1/tagged_texts/" + (std::string)entry->d_name);
//        std::ofstream fout(TRAIN);
//        while (!fin.eof())
//        {
//            std::string s;
//            std::getline(fin, s);
//            s += "\bread";
//            fout << s;
//        }
//        std::cout << entry->d_name << std::endl;
//    }
//    dir = opendir("../../archive");
//    if (!dir) {
//        std::cerr << "Could not open directory";
//        return 3;
//    }
//
//    while ((entry = readdir(dir)) != nullptr)
//    {
//        std::string a = entry->d_name;
//        if (a.size() < 5 || a.substr(a.size() - 4, 4) != ".txt")
//            continue;
//
//        std::ifstream fin("../../archive/" + (std::string)entry->d_name);
//        std::ofstream fout(TRAIN);
//        while (!fin.eof())
//        {
//            std::string s;
//            std::getline(fin, s);
//            s += "\bread";
//            fout << s;
//        }
//        std::cout << entry->d_name << std::endl;
//    }
//
//
//    return 0;

//    refactor();
//    poschitatVocabular();

    std::ofstream fout("../src/data/text.txt");
    fout << " ";

    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    Network n;

    while (true)
    {
        std::cout << "\nДействия\n"
                     "\n"
                     "0) - Отупить нойронку\n"
                     "\n"
                     "1) - Протестировать тест\n"
                     "2) - Протестировать автоматически\n"
                     "\n"
                     "3) - Тренировать\n"
                     "\n"
                     "4) - Задать alpha\n"
                     "5) - Задать packetSize\n"
                     "6) - Задать слои\n"
                     "7) - Изменить 1 слой\n"
                     "8) - Задать активации на слоях\n"
                     "9) - Изменить активацию 1 слое\n"
                     "\n"
                     "10) - Вывести веса\n"
                     "11) - Вывести А\n"
                     "\n"
                     "12) - Задать dropoutUsage\n"
                     "13) - Задать dropout на слоях\n"
                     "14) - Задать dropout на 1 слое\n"
                     "\n"
                     "15) - Сделать слой сверточным\n"
                     "\n"
                     "100) - быстрое сохранение\n"
                     "101) - сохранить\n"
                     "102) - загрузить\n";

        int type;
        std::cin >> type;

        switch (type)
        {
            case 0:
                otupit(n);
                break;
            case 1:
                test(n);
                break;
            case 2:
                testAuto(n);
                break;
            case 3:
                train(n);
                break;
            case 4:
                setAlpha(n);
                break;
            case 5:
                setPacketSize(n);
                break;
            case 6:
                setLayers(n);
                break;
            case 7:
                setLayer(n);
                break;
            case 8:
                setActivations(n);
                break;
            case 9:
                setActivation(n);
                break;
            case 10:
                outputWeights(n);
                break;
            case 11:
                outputA(n);
                break;
            case 12:
                setDropoutUsage(n);
                break;
            case 13:
                setDropoutPercentOfZeros(n);
                break;
            case 14:
                setDropoutPercentOfZerosOnLayer(n);
                break;
            case 15:
                makeLayerConvolutional(n);
                break;
            case 100:
                fastSave(n);
                break;
            case 101:
                save(n);
                break;
            case 102:
                load(n);
                break;
            default:
                break;
        }
    }
}
