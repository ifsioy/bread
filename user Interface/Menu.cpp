//
// Created by u on 27.02.24.
//

#include "Menu.h"

std::mt19937 rn;
const int sz = 40, kolOfLetters = 40;
const int ERROR_TIMER = 100000;

void toLower(std::string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
        if (s.substr(i, 1) == "�") s.replace(i, 1, "�");
    }
}

void poschitatVocabular()
{
    std::unordered_map<std::string, int> mp;
    std::ifstream fin(TRAIN);

    std::string word = "";

    int cur = 0;
    while (!fin.eof())
    {
        cur++;
        std::string s;
        fin >> s;

        toLower(s);

        for (int i = 0; i < s.size(); i++)
        {
            if ((s.substr(i, 1) < "�" || s.substr(i, 1) > "�") && s.substr(i, 1) != "�")
            {
                if ((word.substr(0, 1) >= "�" && word.substr(0, 1) <= "�") || word.substr(0, 1) == "�" || word.substr(0, 1) == ".")
                    mp[word]++;
//                if (!word.empty() && word[0] != ' ' && !(word[0] >= 'a' && word[0] <= 'z') && !(word[0] >= 'A' && word[0] <= 'Z'))
//                    mp[word]++;
                word = "";
            }
            word += s.substr(i, 1);
            if ((s.substr(i, 1) < "�" || s.substr(i, 1) > "�") && s.substr(i, 1) != "�")
            {
                if ((word.substr(0, 1) >= "�" && word.substr(0, 1) <= "�") || word.substr(0, 1) == "�" || word.substr(0, 1) == ".")
                    mp[word]++;
//                if (!word.empty() && word[0] != ' ' && !(word[0] >= 'a' && word[0] <= 'z') && !(word[0] >= 'A' && word[0] <= 'Z'))
//                    mp[word]++;
                word = "";
            }
        }
        if ((word.substr(0, 1) >= "�" && word.substr(0, 1) <= "�") || word.substr(0, 1) == "�" || word.substr(0, 1) == ".")
            mp[word]++;
        word = "";
    }

    if (!word.empty() && word[0] != ' ')
        mp[word]++;

    std::ofstream fout(VOCABULARY);
    int q = 0;
    std::cout << mp.size() << "\n";
    for (auto u : mp)
    {
        if (u.second > 0)
            fout << u.first << "\n", q++;
    }
}

void read(std::string s, std::unordered_map<std::string, int> &a)
{
    std::ifstream fin(s);
    a.clear();

    for (int i = 0; !fin.eof(); i++)
    {
        std::string word;
        fin >> word;
        a[word] = i;
    }

    fin.close();
}

void read(std::string s, std::string &a)
{
    std::ifstream fin(s);
    a.clear();

    std::getline(fin, a);

    fin.close();
}

void refactor()
{
    std::ifstream fin(DATA + "/1.txt");
    std::ofstream fout(TRAIN);

    std::string word;

    int cur = 0;
    while (!fin.eof())
    {
        cur++;
        std::string s;
        fin >> s;
        toLower(s);

        for (int i = 0; i < s.size(); i++)
        {
            if ((s.substr(i, 1) < "�" || s.substr(i, 1) > "�") && s.substr(i, 1) != "�")
            {
                if ((word.substr(0, 1) >= "�" && word.substr(0, 1) <= "�") || word.substr(0, 1) == "�" || word.substr(0, 1) == ".")
                    fout << word << "\n";
//                if (!word.empty() && word[0] != ' ' && !(word[0] >= 'a' && word[0] <= 'z') && !(word[0] >= 'A' && word[0] <= 'Z'))
//                    fout << word << "\bread";
                word = "";
            }
            word += s.substr(i, 1);
            if ((s.substr(i, 1) < "�" || s.substr(i, 1) > "�") && s.substr(i, 1) != "�")
            {
                if ((word.substr(0, 1) >= "�" && word.substr(0, 1) <= "�") || word.substr(0, 1) == "�" || word.substr(0, 1) == ".")
                    fout << word << "\n";
//                if (!word.empty() && word[0] != ' ' && !(word[0] >= 'a' && word[0] <= 'z') && !(word[0] >= 'A' && word[0] <= 'Z'))
//                    fout << word << "\bread";
                word = "";
            }
        }

        if ((word.substr(0, 1) >= "�" && word.substr(0, 1) <= "�") || word.substr(0, 1) == "�" || word.substr(0, 1) == ".")
            fout << word << "\n";
        word = "";
    }
}

void refactorStringToDeque(std::string s, std::deque<std::string> &a)
{
    std::unordered_map<std::string, int> vocabulary;
    read(VOCABULARY, vocabulary);

    std::string word = "";
    for (int i = 0; i < s.size(); i++)
    {
        if ((s.substr(i, 1) < "�" || s.substr(i, 1) > "�") && s.substr(i, 1) != "�")
        {
            if (!word.empty() && word[0] != ' '  && !(word[0] >= 'a' && word[0] <= 'z') && !(word[0] >= 'A' && word[0] <= 'Z'))
                a.push_back(word);
            word = "";
        }
        word += s.substr(i, 1);
        if ((s.substr(i, 1) < "�" || s.substr(i, 1) > "�") && s.substr(i, 1) != "�")
        {
            if (!word.empty() && word[0] != ' '  && !(word[0] >= 'a' && word[0] <= 'z') && !(word[0] >= 'A' && word[0] <= 'Z'))
                a.push_back(word);
            word = "";
        }
    }

    if (!word.empty() && word[0] != ' ')
        a.push_back(word);

    while (a.size() > sz)
        a.pop_front();
}

void otupit(Network &n)
{
    n.otupit();
}

void test(Network &n)
{
    std::string vocabulary;
    read(VOCABULARY, vocabulary);
    vocabulary += "\n";

    std::ofstream fout(OUTPUT);

    std::cout << "Stroka \n";
    std::string adam;

    std::getline(std::cin, adam);
    std::getline(std::cin, adam);

    fout << adam;

    std::string cur = adam;

    while (cur.size() > kolOfLetters)
        cur.erase(0, 1);

    int t = 500;
    while (t--)
    {
//        std::vector<float> start(vocabulary.size(), 0);
//        for (auto &s : curWords)
//            start[vocabulary[s]] = 1;

        std::vector<float> start;
        for (int i = 0; i < sz; i++)
        {
            std::vector<float> tmp(vocabulary.size(), 0);
            if (sz - cur.size() <= i && vocabulary.contains(cur[i - sz + cur.size()]))
                tmp[vocabulary.find(cur[i - sz + cur.size()])] = 1;

            for (auto &u : tmp)
                start.push_back(u);
        }

        int prediction = n.predict(start);
        std::string ans = vocabulary.substr(prediction, 1);

        fout << ans;

        cur.append(ans);
        if (cur.size() > kolOfLetters)
            cur.erase(0, 1);
    }

    fout.close();
}

void testAuto(Network &n)
{
    float error = 0;

    rn.seed(time(nullptr));
    std::ifstream fin("../src/data/test.txt");

    std::string s;
    fin >> s;

    int numOfTests;
    fin >> numOfTests;
    for (int num = 0; num < numOfTests; num++)
    {
        int ans;
        fin >> ans;

        std::vector<float> start;
        for (int i = 0; i < 28; i++)
        {
            for (int j = 0; j < 28; j++)
            {
                float x;
                fin >> x;
                start.push_back(x);
            }
        }

        float an = n.predict(start);

        if (ans != an)
            error++;
    }

    std::cout << error / (float)numOfTests;
}

void train(Network &n)
{
    srand(time(nullptr));
    std::ifstream trainf;
    trainf.open(TRAIN);
    std::string train;
    while (!trainf.eof())
    {
        std::string tmp;
        std::getline(trainf, tmp);
        train += tmp + "\n";
    }

    std::cout << train.size() << "\n";

    std::string vocabulary;
    read(VOCABULARY, vocabulary);
    vocabulary += "\n";

    std::string cur;

    std::cout << "\nVvodi kolichestvo testov padla: ";



    int t;
    std::cin >> t;
    int errorPeriod = 0;
    float guessPercent = 0;
    auto startClock = clock();
    bool gg = false;

    int kol = 0;
    while (true)
    {
        cur = "";
        long long pos = (1LL * rand() * rand()) % train.size();
        if (train.size() - pos < 100)
            pos -= 1000;

        while (train[pos] != ' ')
            pos++;
        pos++;

        std::string word = train.substr(pos, 100);

//        if (trainf.eof())
//        {
//            trainf.close();
//            trainf.open(TRAIN);
//            kol++;
//            std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ZELEBOBA - " << kol << "\bread";
//        }
//

//        std::string word;
//        std::getline(trainf, word);

        word += "\n";
        for (auto &letter : word)
        {
            if (!vocabulary.contains(letter))
                continue;

    //        std::vector<float> start(vocabulary.size(), 0);
    //        for (auto &s : curWords)
    //            start[vocabulary[s]] = 1;

            std::vector<float> start;
            for (int i = 0; i < sz; i++)
            {
                std::vector<float> tmp(vocabulary.size(), 0);
                if (sz - cur.size() <= i && vocabulary.contains(cur[i - sz + cur.size()]))
                {
                    tmp[vocabulary.find(cur[i - sz + cur.size()])] = 1;
                }

                for (auto &u : tmp)
                    start.push_back(u);
            }

            std::vector<float> y(vocabulary.size(), 0);

            y[vocabulary.find(letter)] = 1;

            float error = n.train(start, y);

            cur.push_back(letter);
            if (cur.size() > kolOfLetters)
                cur.erase(0, 1);

            int m = 0;
            for (int i = 0; i < vocabulary.size(); i++)
                if (n.get(i) > n.get(m))
                    m = i;

            if (vocabulary.find(letter) == m)
                guessPercent++;

            errorPeriod++;
            errorPeriod %= ERROR_TIMER;
            if (errorPeriod == 0)
            {
                std::vector<float> prediction;
                for (int i = 0; i < n.getOutputSize(); i++)
                    prediction.push_back(n.get(i));

                std::cout << "\n\n\nREMAIN - " << t << "\n";
                std::cout << "TRAIN_ERROR - | " << error / ERROR_TIMER << " |\n";
                std::cout << "GUESS_PERCENT - | " << guessPercent / ERROR_TIMER << " |\n";
                std::cout << "TIME - " << (clock() - startClock) / CLOCKS_PER_SEC << "\n\n";
                std::cout << cur << "\n";
                std::cout << letter << "\n";
                n.setError(0);
                for (int i = 0; i < 10; i++) std::cout << "-"; std::cout << "\n";
                for (int i = 0; i < n.getOutputSize(); i++)
                    if (y[i] == 1)
                        std::cout << y[i] << " " << prediction[i] << "\n";

                std::cout << vocabulary[m] << " " << n.get(m) << "\n";

                for (int i = 0; i < 10; i++) std::cout << "-"; std::cout << "\n";

                guessPercent = 0;

                //bread.save("narost");
            }

            if (errorPeriod % 100 == 0)
                gg = true;

            if (gg && letter == '.')
            {
                gg = false;
                cur.clear();
            }

            t--;
            if (t <= 0)
                break;
        }


        if (t % 1000000 == 0)
        {
            n.save("stihi" + std::to_string(t));
        }
        if (t <= 0)
            break;
    }
}

void setAlpha(Network &n)
{
    std::cout << "Alpha day: ";
    float alpha;
    std::cin >> alpha;

    n.setAlpha(alpha);
}

void setPacketSize(Network &n)
{
    std::cout << "packetSize day: ";
    int packetSize;
    std::cin >> packetSize;

    n.setPacketSize(packetSize);
}

void setLayers(Network &n)
{
    std::cout << "Skolko sloev?(-1 na vihod) ";
    int num;
    std::cin >> num;
    if (num == -1)
        return;

    std::vector<int> layers(num);
    std::cout <<"Vvody, ne jdi\n";
    for (int i = 0; i < num; i++)
        std::cin >> layers[i];

    n.setLayers(layers);
}

void setLayer(Network &n)
{
    std::cout << "NomerSloya(-1 vihod) ";
    int num, size;
    std::cin >> num;
    std::cout << "Razmer: ";
    std::cin >> size;
    n.setLayer(num, size);
}

void setActivation(Network &n)
{
    std::cout << "Kakoy sloy? ";
    int num;
    std::cin >> num;
    if (num < 0 || num >= n.getSize())
        return;

    std::cout << "Vvedite activatiu\n";
    std::cout << "0 - Nothing\n"
                 "1 - Leaky ReLU\n"
                 "2 - Sigmoida\n"
                 "5 - Softmax\n";

    int type;
    std::cin >> type;
    n.setActivateType(num, type);
}

void setActivations(Network &n)
{
    std::cout << "Vvedite " << n.getSize() << " activatiy\n";
    std::cout << "0 - Nothing\n"
                 "1 - Leaky ReLU\n"
                 "2 - Sigmoida\n"
                 "5 - Softmax\n";

    std::vector<int> activatios(n.getSize());
    for (int i = 0; i < n.getSize(); i++)
        std::cin >> activatios[i];

    n.setActivateType(activatios);
}

void outputWeights(Network &n)
{
    n.printW();
}

void outputA(Network &n)
{
    n.printA();
}

void setDropoutUsage(Network &n)
{
    std::cout << "Ispolzovat ili net? (1/0): ";
    bool dropoutUsage;
    std::cin >> dropoutUsage;
    n.setDropoutUsage(dropoutUsage);
}

void setDropoutPercentOfZeros(Network &n)
{
    std::cout << "Vvedite " << n.getSize() << " dropoutov(Ne znau kak nazvat)\n";
    std::vector<int> percent(n.getSize());
    for (int i = 0; i < n.getSize(); i++)
        std::cin >> percent[i];

    n.setDropoutPercentOfZeros(percent);
}

void setDropoutPercentOfZerosOnLayer(Network &n)
{
    std::cout << "Kakoy sloy? ";
    int num;
    std::cin >> num;
    if (num < 0 || num >= n.getSize())
        return;

    std::cout << "Vvedite procent\n";

    int percent;
    std::cin >> percent;
    n.setDropoutPercentOfZeros(num, percent);
}

void makeLayerConvolutional(Network &n)
{
    std::cout << "Kakoy sloy? ";
    int num;
    std::cin >> num;
    if (num < 0 || num >= n.getSize())
        return;

    std::cout << "Vvedite skolko i vo skolko: ";

    int kolFrom, kolTo;
    std::cin >> kolFrom >> kolTo;

}

void fastSave(Network &n)
{
    n.save();
}

void save(Network &n)
{
    std::cout << "Vvedi nazvanie fayla urod: ";
    std::string s;
    std::cin >> s;

    n.save(s);
}

void load(Network &n)
{
    std::cout << "Otcuda? (fastSave or else): \n";
    std::string s;
    std::cin >> s;

    n.load(s);
}