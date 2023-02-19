#pragma once
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
#define pi 3.141592653589793238463

class tacka
{
public:
    float x, y, z;

    tacka(float x, float y, float z = 0) : x(x), y(y), z(z) {}
    tacka() : x(0), y(0), z(0) {}

    float razmak(const tacka& t2)
    {
        return sqrt(pow(x - t2.x, 2) + pow(y - t2.y, 2) + pow(z - t2.z, 2));
    }
};

tacka prva;
class mnogougao
{
private:
    static int sgn(float x)
    {
        return (((x) < 0) ? -1 : ((x) > 0));
    }
    static float ugao(tacka tacka0, tacka tacka1)
    {
        float x, y;
        x = tacka1.x - tacka0.x;
        y = tacka1.y - tacka0.y;
        if (y == 0)
        {
            if (x >= 0) return 0;
            return pi;
        }
        float tmp = acos((double)x / sqrt(pow(x, 2) + pow(y, 2)) * sgn(y));
        return y < 0 ? tmp + pi : tmp;
    }
public:
    vector<tacka> Tacke;
    mnogougao(vector<tacka> tacke)
    {
        if (tacke.size() <= 3) this->Tacke = tacke;
        vector<tacka> omotac;

        prva = *min_element(tacke.begin(), tacke.end(),
            [](const tacka& tacka1, const tacka& tacka2)
            {
                if (tacka1.y == tacka2.y)
                {
                    return tacka1.x < tacka2.x;
                }
                return tacka1.y < tacka2.y;
            });

        sort(tacke.begin(), tacke.end(),
            [](const tacka& t1, const tacka& t2)
            {
                float ugaov1 = ugao(prva, t1);
                float ugaov2 = ugao(prva, t2);
                return ugaov1 < ugaov2;
            });

        stack<tacka> stek;
        stek.push(tacke[0]);
        stek.push(tacke[1]);

        for (int i = 2; i < tacke.size(); i++)
        {
            tacka tacka0, tacka1;
            tacka1 = stek.top();
            stek.pop();
            tacka0 = stek.top();
            stek.push(tacka1);

            while ((tacka1.x - tacka0.x) * (tacke[i].y - stek.top().y) - (tacka1.y - tacka0.y) * (tacke[i].x - stek.top().x) < 0)
            {
                stek.pop();
                tacka1 = stek.top();
                stek.pop();
                tacka0 = stek.top();
                stek.push(tacka1);
            }
            stek.push(tacke[i]);
        }
        while (!stek.empty())
        {
            omotac.push_back(stek.top());
            stek.pop();
        }
        this->Tacke = omotac;
    }
};