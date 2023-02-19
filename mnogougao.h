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
        float temp = acos((double)x / sqrt(pow(x, 2) + pow(y, 2)) * sgn(y));
        return y < 0 ? temp + pi : temp;
    }
public:
    vector<tacka> tacke;
    mnogougao(vector<tacka> tacke)
    {
        if (tacke.size() <= 3) this->tacke = tacke;
        vector<tacka> omotac;

        prva = *min_element(tacke.begin(), tacke.end(),
            [](const tacka& t1, const tacka& t2)
            {
                if (t1.y == t2.y)
                {
                    return t1.x < t2.x;
                }
                return t1.y < t2.y;
            });

        sort(tacke.begin(), tacke.end(),
            [](const tacka& t1, const tacka& t2)
            {
                float ugaov1 = ugao(prva, t1);
                float ugaov2 = ugao(prva, t2);
                return ugaov1 < ugaov2;
            });

        stack<tacka> s;
        s.push(tacke[0]);
        s.push(tacke[1]);

        for (int i = 2; i < tacke.size(); i++)
        {
            tacka t0, t1;
            t1 = s.top();
            s.pop();
            t0 = s.top();
            s.push(t1);

            while ((t1.x - t0.x) * (tacke[i].y - s.top().y) - (t1.y - t0.y) * (tacke[i].x - s.top().x) < 0)
            {
                s.pop();
                t1 = s.top();
                s.pop();
                t0 = s.top();
                s.push(t1);
            }
            s.push(tacke[i]);
        }
        while (!s.empty())
        {
            omotac.push_back(s.top());
            s.pop();
        }
        this->tacke = omotac;
    }
};