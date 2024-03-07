#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
enum typeChampion
{
    VARUS = 1,
    KAYN,
    AATROX
};
class Point {
public:
    int x;
    int y;
    float distance(Point temp) {
        return sqrt((this->x - temp.x) * (this->x - temp.x) + (this->y - temp.y) * (this->y - temp.y));
    }
    static bool check(Point first, Point second, Point third) {
        float a = first.distance(third);
        float b = second.distance(third);
        float c = first.distance(second);
        return c - (a + b) < 0.00001;
    }
};
class Champion {
public:
    typeChampion type;
    float range;
    float maxhp;
    float hp;
    float atk;
    float def;
    Point  position;
    float dameged;
    virtual void input() {
        cin >> position.x >> position.y >> hp >> atk >> def;
        dameged = 0;
        maxhp = hp;
    }
    void attack(Champion*& temp) {
        if (this->atk > temp->def) {
            temp->hp -= this->atk - temp->def;
            dameged += this->atk - temp->def;
        }
        else {
            this->hp -= temp->def - this->atk;
        }
    }
    static float distance(Champion* first, Champion* second) {
        return first->position.distance(second->position);
    }
    Champion* target(vector<Champion*> vt) {
        Champion* result = vt[0] != this ? vt[0] : vt[1];
        float distance = this->position.distance(result->position);
        for (Champion*& x : vt) {
            if (x != this) {
                if (distance > this->position.distance(x->position)) {
                    result = x;
                    distance = this->position.distance(x->position);
                }
                else if (distance == this->position.distance(x->position))
                    if (result->hp > x->hp) {
                        {
                            result = x;
                            distance = this->position.distance(x->position);
                        }
                }
            }
        }
        return result;
    }
    void move(Champion* champion) {
        if (this->position.x == champion->position.x) {
            this->position.y -= this->position.x < champion->position.x ? -1 : 1;
        }
        else if (this->position.y == champion->position.y) {
            this->position.x -= this->position.y < champion->position.y ? -1 : 1;
        }
        else {
            this->position.y += this->position.x < champion->position.x ? -1 : 1;
            this->position.x += this->position.y < champion->position.y ? -1 : 1;
        }
    }
    virtual void skill(vector<Champion*>& vt) = 0;
};
class Varus : public Champion {
public:
    Varus() {
        range = 2.9;
        type = VARUS;
    }
    void input() {
        cin >> position.x >> position.y >> hp >> atk;
        def = 0;
        dameged = 0;
        maxhp = hp;
    }
    void skill(vector<Champion*>& vt) {
        Champion* temp = target(vt);
        if (distance(temp, this) > 4) {
            move(temp);
        }
        if (distance(temp, this) <= 4) {
            for (Champion*& x : vt) {
                if (x != this) {
                    if (Point::check(this->position, temp->position, x->position)) {
                        x->hp -= this->atk + 0.2 * x->maxhp;
                    }
                }
            }
        }
        dameged = 0;
    }
};
class Kayn : public Champion {
public:
    Kayn() {
        range = 1.5;
        type = KAYN;
    }
    void skill(vector<Champion*>& vt) {
        for (Champion*& x : vt) {
            if (x != this) {
                if (Champion::distance(x, this) <= sqrt(2)) {
                    x->hp -= this->atk * 2;
                }
            }
        }
        dameged = 0;
    }
};
class Aatrox : public Champion {
public:
    Aatrox() {
        range = 1.5;
        type = AATROX;
    }
    float healing;
    void input() {
        Champion::input();
        cin >> healing;
    }
    void skill(vector<Champion*>& vt) {
        Champion* temp = target(vt);
        if (distance(temp, this) > 3) {
            move(temp);
        }
        if (distance(temp, this) < 3) {
            float dame = this->atk + this->def;
            if (dame > temp->def) {
                temp->hp -= dame - temp->def;
                this->hp += healing * (dame - temp->def);
            }
            else {
                this->hp -= temp->def - dame;
            }
        }
        dameged = 0;
    }
};
bool Compare(Champion* a, Champion* b) {
    if (a->hp < b->hp)
        return 1;
    else if (a->hp == b->hp) {
        return a->type < b->type;
    }
    return 0;
}
class Arena {
public:
    vector<Champion*> vt;
    void input() {
        int n, type;
        cin >> n;
        vt.resize(n);

        for (Champion*& x : vt) {
            cin >> type;
            switch (type)
            {
            case VARUS:
                x = new Varus;
                break;
            case KAYN:
                x = new Kayn;
                break;
            case AATROX:
                x = new Aatrox;
                break;
            default:
                x = NULL;
                break;
            }
            if (x != NULL)
                x->input();
        }
    }
    void fight() {
        if (vt.empty())
            return;
        int i = 1;
        while (vt.size() != 1) {
            sort(vt.begin(), vt.end(), Compare);
            vector<Champion*>::iterator it;
            if (i == 1)
                cout << " " << endl;
            for (it = vt.begin(); it != vt.end(); it++) {
                Champion* target = (*it)->target(vt);
                if ((*it)->dameged >= 20) {
                    (*it)->skill(vt);
                }
                else {
                    if (Champion::distance(*it, target) > (*it)->range)
                        (*it)->move(target);
                    if (Champion::distance(*it, target) < (*it)->range)
                        (*it)->attack(target);
                }
                if (target->hp <= 0) {
                    Champion* cur = (*it);
                    vt.erase(find(vt.begin(), vt.end(), target));
                    it = find(vt.begin(), vt.end(), cur);
                }
            }
        }
    }
    void printResult() {
        if (vt.empty())
            return;
        typeChampion type = vt.front()->type;
        switch (type)
        {
        case VARUS:
            cout << "Varus";
            break;
        case KAYN:
            cout << "Kayn";
            break;
        case AATROX:
            cout << "Aatrox";
            break;
        default:
            break;
        }
        cout << " " << vt.front()->hp;
    }
};
int main() {
    Arena a;
    a.input();
    a.fight();
    a.printResult();
    return 0;
}
