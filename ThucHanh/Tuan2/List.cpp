#include <iostream>
#include <list>
int main()
{
    int n, x, y;
    std::list<int> l;
    while (true)
    {
        std::cin >> n;
        switch (n)
        {
        case -1:
            if (l.empty())
                std::cout << "[]";
            else
            {

                std::cout << "[";
                for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
                {
                    if (it != --l.end())
                        std::cout << *it << ",";
                    else
                        std::cout << *it << "]";
                }
            }
            break;
        case 0:
            std::cin >> x;
            l.push_back(x);
            break;
        case 1:
            std::cin >> x;
            for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
            {
                if (*it == x)
                {
                    l.erase(it);
                    break;
                }
            }
            break;
        case 2:
            std::cin >> x;
            l.remove(x);
            break;
        case 3:
        {
            std::cin >> x;
            std::cin >> y;
            if (x > l.size() - 1)
                break;
            int i = 0;
            std::list<int>::iterator it = l.begin();
            while (i < x)
            {
                it++;
                i++;
            }
            *it = y;

            break;
        }
        default:
            break;
        }
        if (n == -1)
            break;
    }
    return 0;
}